#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "gol.h"



// This is basically fgets but it ignores null chatacters, doesnt read the final \n
// and doesnt append a null terminator
// returns number of characters read or -1 if an invalid character is read
int getLine(char* buffer, int maxCount, FILE* file){
    int count = 0;
    int in = '\0';
    char pChar = '\0';
    while((in = getc(file)) != EOF) {
        pChar = in;
        if(count >= maxCount) break;
        if(in == '\r') continue;
        if(in == '\n') break;
        if(in != '*' && in != '.') {
            count = -1;
            break;
        }
        buffer[count] = in;
        ++count;
    }
    if(count == 0 && pChar == '\n'){
        count = -1;
    }
    if(count > 0 && pChar != '\n') {
        count = -1;
    }
    return count;
}

// probably uncessary to ever use this as it would only be used when calling exit anyway
void freeBoard(char ***board, int rows) {
    for(int i = 0;i<rows;++i) {
        free((*board)[i]);
        (*board)[i] = NULL;
    }
    free(*board);
    *board = NULL;
}

long getAliveCount(struct universe *u) {
    long count = 0;
    for(long i = 0;i<u->height;++i) {
        for(long j = 0;j<u->width;++j){
            if(u->board[i][j] == '*'){
                ++count;
            }
        }
    }
    return count;
}


void read_in_file(FILE *infile, struct universe *u){
    int rows = 0;
    int columns = 0;
    int columnCount = 0;
    char buff[513]; // temporarily stores up to 513 characters from a line
    // read in first row to see how long each row is
    columnCount = getLine(buff, 513, infile);
    if(columnCount <= 0 || columnCount > 512) {
        fprintf(stderr, "Input file is invalid\n");
        exit(EXIT_FAILURE);
    } else {
        ++rows;
        columns = columnCount;
        u->board = malloc(rows*sizeof(char*));
        if(u->board == NULL) {
            fprintf(stderr, "Could not allocate memory for input file\n");
            exit(EXIT_FAILURE);
        }
        u->board[rows-1] = malloc(columns*sizeof(char));
        if(u->board[rows-1] == NULL){
            fprintf(stderr, "Could not allocate memory for input file\n");
            freeBoard(&u->board, 0);
            exit(EXIT_FAILURE);
        }
        memcpy(u->board[rows-1], buff, columns); // copy from buffer to main board
        // while there are still characters to read
        while((columnCount = getLine(buff, 513, infile)) != 0) {
            if(columnCount < 0 || columnCount != columns) {
                freeBoard(&u->board, rows);
                fprintf(stderr, "Input file is invalid\n");
                exit(EXIT_FAILURE);
            }
            ++rows;
            char **tmp = realloc(u->board, rows*sizeof(char*));
            if(tmp == NULL) {
                freeBoard(&u->board, rows);
                fprintf(stderr, "Could not allocate memory for input file\n");
                exit(EXIT_FAILURE);
            }
            u->board = tmp;
            tmp = NULL;
            u->board[rows-1] = malloc(columns*sizeof(char));
            if(u->board[rows-1] == NULL){
                freeBoard(&u->board, rows);
                fprintf(stderr, "Could not allocate memory for input file\n");
                exit(EXIT_FAILURE);
            }
            memcpy(u->board[rows-1], buff, columns); // copy from buffer to main board
        }
        u->height = rows;
        u->width = columns;
        u->currentAlive = getAliveCount(u);
        u->aliveTotal = u->currentAlive;
        u->generation = 1;
    }
    
}


void write_out_file(FILE *outfile, struct universe *u){
    for(int i = 0;i<u->height;++i) {
        for(int j = 0;j<u->width;++j){
            putc(u->board[i][j], outfile);
        }
        putc('\n', outfile);
    }
}


int is_alive(struct universe *u, int column, int row){
    if(row < 0 || row > (u->height - 1)) {
        fprintf(stderr, "is_alive: trying to access a non exisitent cell");
        // free the board we have, it will be freed on exit anyway but may as well do it now
        freeBoard(&u->board, u->height);
        exit(EXIT_FAILURE);
    }
    return (u->board[row][column] == '*');
}


int will_be_alive(struct universe *u, int column, int row){
    long aliveCount = 0;
    for (long i = row - 1 ; i < row + 2; ++i) {
        for (long j = column - 1;j < column +2;++j) {
            if(i < 0 || j < 0 || i > (u->height-1) || j > (u->width - 1)) {
                continue;
            }else if(is_alive(u, j, i)) {
                ++aliveCount;
            }
        }
    }
    if(is_alive(u, column, row)) {
        if(aliveCount == 3 || aliveCount == 4) {
            return 1;
        }
    }else {
        if(aliveCount == 3) {
            return 1;
        }
    }
    return 0;
}


int will_be_alive_torus(struct universe *u,  int column, int row){
    int aliveCount = 0;
    for (long i = row - 1 ; i < row + 2; ++i) {
        for (long j = column - 1;j < column +2;++j) {
            long r = i;
            long c = j;
            if(i <= -1) {
                r = (u->height + i%u->height)%u->height;
            }else if(i >= u->height) {
                r = i%u->height;
            }
            if(j <= -1) {
                c = (u->width + j%u->width)%u->width;
            }else if(j >= u->width) {
                c = j%u->width;
            }
            if(is_alive(u, c, r)) {
                ++aliveCount;
            }
        }
    }
    if(is_alive(u, column, row)) {
        if(aliveCount == 3 || aliveCount == 4) {
            return 1;
        }
    }else {
        if(aliveCount == 3) {
            return 1;
        }
    }
    return 0;
}


void evolve(struct universe *u, int (*rule)(struct universe *u, int column, int row)){
    //create tmp buffer to store new state
    char **tmp = malloc(u->height*sizeof(char*));
    if(tmp == NULL) {
        fprintf(stderr, "Memory error while evolving game state");
        exit(EXIT_FAILURE);
    }
    for(int i = 0;i<u->height;++i) {
        tmp[i] = malloc(u->width * sizeof(char));
        if(tmp[i] == NULL) {
            fprintf(stderr, "Memory error while evolving game state");
            freeBoard(&tmp, i);
            exit(EXIT_FAILURE);
        }
    }
    for(int i = 0; i<u->height;++i) {
        for(int j = 0;j<u->width;++j) {
            if(rule(u, j,i)) {
                tmp[i][j] = '*';
            }else {
                tmp[i][j] = '.';
            }
        }
    }
    //free old board
    freeBoard(&u->board, u->height);
    //assign universe board to tmp buffer
    u->board = tmp;
    tmp = NULL;
    u->currentAlive = getAliveCount(u);
    u->aliveTotal += u->currentAlive;
    ++u->generation;
}


void print_statistics(struct universe *u){
    float currentPerc = ((float)u->currentAlive / (u->height * u->width))*100;
    float avgPerc = ((float)u->aliveTotal / (u->height * u->width * u->generation))*100;
    printf("%.3f%% of cells currently alive\n", currentPerc);
    printf("%.3f%% of cells alive on average\n", avgPerc);
}


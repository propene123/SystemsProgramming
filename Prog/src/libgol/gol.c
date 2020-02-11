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
    while((in = getc(file)) != EOF) {
        if(count >= maxCount) break;
        if(in == '\n') break;
        if(in != '*' && in != '.') {
            count = -1;
            break;
        }
        buffer[count] = in;
        ++count;
    }
    return count;
}

void freeBoard(char **board, int rows) {
    for(int i = 0;i<rows;++i) {
        free(board[i]);
    }
    free(board);
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
            exit(EXIT_FAILURE);
        }
        memcpy(u->board[rows-1], buff, columns); // copy from buffer to main board
        // while there are still characters to read
        while((columnCount = getLine(buff, 513, infile)) != 0) {
            if(columnCount < 0 || columnCount != columns) {
                freeBoard(u->board, rows);
                u->board = NULL;
                fprintf(stderr, "Input file is invalid\n");
                exit(EXIT_FAILURE);
            }
            ++rows;
            char **tmp = realloc(u->board, rows*sizeof(char*));
            if(tmp == NULL) {
                freeBoard(u->board, rows);
                u->board = NULL;
                fprintf(stderr, "Could not allocate memory for input file\n");
                exit(EXIT_FAILURE);
            }
            u->board = tmp;
            tmp = NULL;
            u->board[rows-1] = malloc(columns*sizeof(char));
            if(u->board[rows-1] == NULL){
                freeBoard(u->board, rows);
                u->board = NULL;
                fprintf(stderr, "Could not allocate memory for input file\n");
                exit(EXIT_FAILURE);
            }
            memcpy(u->board[rows-1], buff, columns); // copy from buffer to main board
        }
        u->height = rows;
        u->width = columns;
    }
    
}


void write_out_file(FILE *outfile, struct universe *u){

}


int is_alive(struct universe *u, int column, int row){

}


int will_be_alive(struct universe *u, int column, int row){

}


int will_be_alive_torus(struct universe *u,  int column, int row){

}


void evolve(struct universe *u, int (*rule)(struct universe *u, int column, int row)){

}


void print_statistics(struct universe *u){

}


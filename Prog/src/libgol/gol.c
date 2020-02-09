#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "gol.h"

void read_in_file(FILE *infile, struct universe *u){
    // count rows and columns in file
    int rows = 0;
    int columns = 0;
    int columnCount = 0;
    bool initRead = true;
    bool error = false;
    for(;;) {
        char currentChar = '\0';
        fscanf(infile, "%c", &currentChar);
        if(currentChar == EOF) {
            break;
        } else if (currentChar == '\n') {
            rows++;
            if(!initRead && columnCount != columns) {
                error = true;
                break;
            }
            columns = columnCount;
            columnCount = 0;
        } else if (currentChar == '*' || currentChar == '.'){
            columnCount++;
        } else {
            error = true;
            break;
        }
    }
    if(error) {
        fprintf(stderr, "Input file was invalid");
        exit(EXIT_FAILURE);
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


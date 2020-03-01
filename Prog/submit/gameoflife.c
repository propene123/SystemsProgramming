#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include "gol.h"


bool isNum(const char* str) {
    for(size_t i = 0;i<strlen(str);++i) {
        if(!(isdigit(str[i]))) {
            return false;
        }
    }
    return true;
}



int main(int argc, char** argv) {
    // set default arg values
    bool stats = false;
    bool torus = false;
    int generations = 5;
    int gCount = 0;
    char* infile = NULL;
    char* outfile = NULL;
    FILE* infilePtr = NULL;
    FILE* outfilePtr = NULL;
    struct universe u;

    for (int i = 1;i<argc;++i) {
        if(strlen(argv[i]) != 2) {
            fprintf(stderr, "invalid option detected\n");
            exit(EXIT_FAILURE);
        }
        if(argv[i][0] != '-') {
            fprintf(stderr, "invalid option detected\n");
            exit(EXIT_FAILURE);
        }
        switch (argv[i][1]){
        case 'i':
            if(i < argc - 1) {
                ++i;
                if (infile != NULL && strcmp(infile, argv[i])) {
                    fprintf(stderr, "-i flag repeated with different arguments\n");
                    exit(EXIT_FAILURE);
                }
                infile = argv[i];
            } else {
                fprintf(stderr, "-i flag with no filename\n");
                exit(EXIT_FAILURE);
            }
            break;
        case 'o':
            if(i < argc - 1) {
                ++i;
                if(outfile != NULL && strcmp(outfile, argv[i])) {
                    fprintf(stderr, "-o flag repeated with different arguments\n");
                    exit(EXIT_FAILURE);
                }
                outfile = argv[i];
            } else {
                fprintf(stderr, "-o flag with no filename\n");
                exit(EXIT_FAILURE);
            }
            break;
        case 'g':
            if(i < argc - 1) {
                ++i;
                if(!isNum(argv[i])){
                    fprintf(stderr, "-g flag passed with invalid argument\n");
                    exit(EXIT_FAILURE);
                }
                errno = 0;
                long tmp = strtol(argv[i], NULL, 10);
                if(errno == ERANGE || tmp < 0 || tmp > INT_MAX) {
                    fprintf(stderr, "-g flag passed with invalid argument\n");
                    exit(EXIT_FAILURE);
                }
                ++gCount;
                if (gCount == 2 && (int) tmp != generations) {
                    fprintf(stderr, "-g flag repeated with different arguments\n");
                    exit(EXIT_FAILURE);
                }
                generations = (int) tmp;
            } else {
                fprintf(stderr, "-g flag with no number\n");
                exit(EXIT_FAILURE);
            }
            break;
        case 's':
            stats = true;
            break;
        case 't':
            torus = true;
            break;
        default:
            fprintf(stderr, "unrecognised flag passed\n");
            exit(EXIT_FAILURE);
            break;
        }
    }

    if(infile!=NULL) {
        infilePtr = fopen(infile, "r");
        if(infilePtr == NULL){
            fprintf(stderr, "could not open input file\n");
            exit(EXIT_FAILURE);
        }
        read_in_file(infilePtr, &u);
        fclose(infilePtr);
        infilePtr = NULL;
    }else {
        read_in_file(stdin, &u);
    }

    for(int i = 0;i<generations;++i) {
        if(torus) {
            evolve(&u, will_be_alive_torus);
        }else {
            evolve(&u, will_be_alive);
        }
    }

    if(stats) {
        print_statistics(&u);
    }

    if(outfile != NULL) {
        outfilePtr = fopen(outfile, "w");
        if(outfilePtr == NULL) {
            fprintf(stderr, "could not open output file\n");
            exit(EXIT_FAILURE);
        }
        write_out_file(outfilePtr, &u);
        fclose(outfilePtr);
        outfilePtr = NULL;
    }else {
        write_out_file(stdout, &u);
    }

    return 0;
}


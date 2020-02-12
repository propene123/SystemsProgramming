#include <stdio.h>
#include "gol.h"

int main(int argc, char** argv) {
    struct universe u;
    FILE* in = fopen("glider.txt", "r");
    read_in_file(in, &u);
    for(int i = 0;i<5;++i) {
        evolve(&u, will_be_alive);
    }
    
    for(int i = 0;i<u.height;++i){
        for(int j = 0;j<u.width;++j){
            printf("%c", u.board[i][j]);
        }
        printf("\n");
    }
    getchar();
    return 0;
}
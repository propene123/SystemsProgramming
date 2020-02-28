#include <stdio.h>

int main() {
    
    FILE* f = fopen("heh.txt", "wb");
    char buff[] = {'.','.','.', '\r','\n','.','.','.', '\r','\n'};
    fwrite(buff, sizeof(char), sizeof(buff)/sizeof(char), f);
    fclose(f);
    return  0;
}

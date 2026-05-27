#include <stdio.h>
#include <stdlib.h>

#define MAX_N 30
#define MAX_M 30

int main(int argc, char *argv[]) {
    if (argc != 3) {
        return 1;
    }

    FILE *in = fopen(argv[1], "r");
    if (!in) {
        return 1;
    }

    int N, M;
    if (fscanf(in, "%d %d", &N, &M) != 2) {
        fclose(in);
        return 1;
    }

    if (N < 1 || N > MAX_N || M < 1 || M > MAX_M) {
        fclose(in);
        return 1;
    }

    char map[MAX_N][MAX_M];
    int walls = 0, treasures = 0, traps = 0;

    
    fgetc(in); 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int ch = fgetc(in);
            if (ch == EOF) {
                fclose(in);
                return 1;
            }
            map[i][j] = (char)ch;
           
            if (map[i][j] == '#') walls++;
            else if (map[i][j] == '$') treasures++;
            else if (map[i][j] == 'X') traps++;
        }
       
        fgetc(in); 
    }

    fclose(in);


    FILE *out = fopen(argv[2], "w");
    if (!out) {
        return 1;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            fputc(map[i][j], out);
        }
        fputc('\n', out);
    }

    fprintf(out, "Walls: %d\n", walls);
    fprintf(out, "Treasures: %d\n", treasures);
    fprintf(out, "Traps: %d\n", traps);

    fclose(out);

    return 0;
}
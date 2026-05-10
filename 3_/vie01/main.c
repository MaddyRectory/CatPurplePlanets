#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void print(char* grid, int size_x, int size_y) {
    int x =0;
    int y=0;

    while(y < size_y) {
        x =0;
        while(x < size_x) {
            if (grid[y*size_x + x] == 1)
                putchar('0');
            else
                putchar('.'); //warning a changer par des espaces a la fin
            x++;
        }

        putchar('\n');
        y++;
    }
}

int main(int ac, char** av) {
    (void)ac;
    (void)av; // commit

    if (ac != 4)
        return 1;
    int size_x = atoi(av[1]);
    int size_y = atoi(av[2]);
    int it = atoi(av[3]);
    (void)it;

    //printf("x:%i y:%i it%i \n", size_x, size_y, it); // commit

    char* now = calloc(size_x*size_y, sizeof(char));
    if (now == NULL)
        return 1;
    //print(now, size_x, size_y); // commit

    char buf;
    int  pen = -1;
    int  x =0;
    int  y =0;
    while(read(0, &buf, 1) == 1) {
        if (buf == 'x')
            pen = pen * (-1);
        else if (buf == 'w') y--;//
        else if (buf == 's') y++;
        else if (buf == 'a') x--;
        else if (buf == 'd') x++;

        if ((pen > 0) && (y >=0 && y < size_y) && (x>=0 && x< size_x))
            now[y*size_x + x] = 1;
    }
    print(now, size_x, size_y); // commit

    char* next = calloc(size_x*size_y, sizeof(char));
//    for (int i = 0; i < size_x*size_y; i++)
//        next[i] = now[i];
    print(next, size_x, size_y); // commit

    x=0;
    y=0;
    int neigbours = 0
    while(it > 0) {
        y = 0;
        while(y < size_y) {

            x = 0;
            while(x < size_x) {
                neigbours = count_neibours(now, size_x, size_y, x, y)
                next[y*size_x + x] = evolution(neigbours)
                x++;
            }
            y++;
        }
        for (int j = 0; j < size_x*size_y; j++)
            now[j] = next[j];
        it--;
    }

    free(next);
    print(???, size_x, size_y);
    free(now);
    return 0;
}

/*
pipeline
arguments
stock arg
init now
print now
read buffer
print now_start
init next
-------------
algo
    isinside
    check neigbours
print now
free
*/
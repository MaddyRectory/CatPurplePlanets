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
                putchar(' '); //warning test avec '.'a changer par des espaces a la fin
            x++;
        }

        putchar('\n');
        y++;
    }
}

int is_inside(int x, int y, int size_x, int size_y)
{
    if (x < 0 || x >= size_x)
        return 0;
    if (y < 0 || y >= size_y)
        return 0;
    return 1;
}

int count_nei(char *grid, int size_x, int size_y, int x, int y)
{
    int dx;
    int dy;
    int count = 0;

    dy = -1;
    while (dy <= 1)
    {
        dx = -1;
        while (dx <= 1)
        {
            if (!(dx == 0 && dy == 0))
                if (is_inside(x + dx, y + dy, size_x, size_y))
                    if (grid[(y + dy) * size_x + (x + dx)] == 1)
                        count++;
            dx++;
        }
        dy++;
    }
    return count;
}

char evolution(int nb_nei, char now)
{
    if (nb_nei == 3)
        return 1;
    else if (now == 1 && nb_nei == 2)
        return 1;
    else
        return 0;
}

int main(int ac, char** av) {
//    (void)ac;
//    (void)av; // commit

    if (ac != 4)
        return 1;
    int size_x = atoi(av[1]);
    int size_y = atoi(av[2]);
    int it = atoi(av[3]);
//    (void)it;

    //printf("x:%i y:%i it%i \n", size_x, size_y, it); // check commit

    char* now = calloc(size_x*size_y, sizeof(char));
    if (now == NULL)
        return 1;
    //print(now, size_x, size_y); // dev ft, check, commit

    char buf;
    int  pen = -1;
    int  x = 0;
    int  y = 0;
    while(read(0, &buf, 1) == 1) {
        if (buf == 'x')
            pen = pen * (-1);
        else if (buf == 'w') y--;// warning sens de déplacement double check !!
        else if (buf == 's') y++;
        else if (buf == 'a') x--;
        else if (buf == 'd') x++;

        if ((pen > 0) && (is_inside(x, y, size_x, size_y) == 1))
            now[y*size_x + x] = 1;
    }
//    print(now, size_x, size_y); // check puis commit

    char* next = calloc(size_x*size_y, sizeof(char));
//    for (int i = 0; i < size_x*size_y; i++)
//        next[i] = now[i];
//    print(next, size_x, size_y); // check - commit

    x=0;
    y=0;
    int neigbours = 0;
    while(it > 0) {
        y = 0;
        while(y < size_y) {

            x = 0;
            while(x < size_x) {
                neigbours = count_nei(now, size_x, size_y, x, y);
                next[y*size_x + x] = evolution(neigbours, now[y*size_x + x]);
                x++;
            }
            y++;
        }
        for (int j = 0; j < size_x*size_y; j++)
            now[j] = next[j];
        it--;
    }

    free(next);
    print(now, size_x, size_y);
    free(now);
    return 0;
}

/*
includes

arguments
stock arg
init now
print now + code print
read buffer + code is_inside
print now_start
init next
algo * it
    check neigbours + code count
    evolution + code evolution
print now
free


hope
*/
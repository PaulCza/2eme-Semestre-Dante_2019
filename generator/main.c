/*
** EPITECH PROJECT, 2020
** za
** File description:
** z
*/

#include "my.h"

void print_real_tab(t_tab *yolo)
{
    int l = 0;
    int c = 0;

    while (l < yolo->y){
        while (c < yolo->x){
            if (yolo->tab[l][c] == 1)
                printf("*");
            else if (yolo->tab[l][c] == 0)
                printf("X");
            c = c + 1;
        }
        printf("\n");
        l = l + 1;
        c = 0;
    }
    l = 0;
    c = 0;
}

void shuffle(int *array, size_t n)
{
    if (n > 1) {
        size_t i;
        for (i = 0; i < n - 1; i++) 
        {
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
            int t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}

void dfs(int r, int c, t_tab *yolo)
{
    int arr[4] = {1, 2, 3, 4};

    shuffle(arr, 4);
    for (int i = 0; i < 4; i++){
        switch(arr[i]){
        case UP:
            if (r - 2 < 0)
                continue;
            if (yolo->tab[r - 2][c] != 1) {
                yolo->tab[r-2][c] = 1;
                yolo->tab[r-1][c] = 1;
                dfs(r - 2, c, yolo);
            }
            break;
        case RIGHT:
            if (c + 2 > yolo->x - 1)
                continue;
            if (yolo->tab[r][c + 2] != 1) {
                yolo->tab[r][c + 2] = 1;
                yolo->tab[r][c + 1] = 1;
                dfs(r, c + 2, yolo);
            }
            break;
        case DOWN:
            if (r + 2 > yolo->y - 1)
                continue;
            if (yolo->tab[r + 2][c] != 1) {
                yolo->tab[r+2][c] = 1;
                yolo->tab[r+1][c] = 1;
                dfs(r + 2, c, yolo);
            }
            break;
        case LEFT:
            if (c - 2 < 0)
                continue;
            if (yolo->tab[r][c - 2] != 1) {
                yolo->tab[r][c - 2] = 1;
                yolo->tab[r][c - 1] = 1;
                dfs(r, c - 2, yolo);
            }
            break;
        }
    }
}

void start_dfs(t_tab *yolo)
{
    yolo->tab[0][0] = 1;
    dfs(0, 0, yolo);
    yolo->tab[yolo->y - 1][yolo->x - 1] = 1;
    yolo->tab[yolo->y - 1][yolo->x - 2] = 1;
    print_real_tab(yolo);
    free_tab(yolo);
}

int start_maze(char *str1, char *str2)
{
    t_tab yolo;

    yolo.x = atoi(str1);
    yolo.y = atoi(str2);
    yolo.n = ((yolo.x * yolo.y) / 4);
    create_tab(&yolo);
    start_dfs(&yolo);
}

int main(int argc, char *argv[])
{
    if (argc == 3){
    int a = 0;
    srand(time(NULL));

    a = start_maze(argv[1], argv[2]);
    return a;
    }else{
        return 0;
    }
}

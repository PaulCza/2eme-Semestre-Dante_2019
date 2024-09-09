/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** da
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

typedef struct	s_tab{
  int		i;
  int		n;
  int		x;
  int		y;
  int		**tab;
} t_tab;

typedef struct next{
  int x;
  int y;
} next_cell;

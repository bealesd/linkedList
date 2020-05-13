// cl main.c generic.c
// gcc -g main.c generic.c -o main

#include <stdio.h>
#include <stdlib.h>

#include "generic.h"

typedef struct Game
{
    char *name;
    int year;
} Game;

int main(void)
{
    system("cls");

    Game *gta = (Game *)calloc(1, sizeof(Game));
    gta->name = "gta";
    gta->year = 1997;

    Game *toca = (Game *)calloc(1, sizeof(Game));
    toca->name = "toca";
    toca->year = 1997;

    node *games = newListOfObject(gta);
    appendObject(&games, toca);

    printf("\n%s - %d,",
           ((Game *)getObject(games, 1))->name,
           ((Game *)getObject(games, 1))->year);

    printf("\nGame count: %d.", countObject(games));
    removeObject(&games, gta);
    removeObjectAtIndex(&games, 1);
    removeObjectAtIndex(&games, 0);
    appendObject(&games, toca);
    removeObjectLast(&games);
    printf("\nGame count: %d.", countObject(games));

    return 0;
}
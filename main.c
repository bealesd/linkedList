// cl main.c generic.c person.c
// gcc -g main.c person.c generic.c -o main

#include <stdio.h>
#include <stdlib.h>

#include "generic.h"
#include "person.h"


int main(void)
{
    system("cls");
    if (1 == 2)
    {
        PERSON *davey = newPerson("davey", "jones", 45);
        node_t *people = newList(davey);

        PERSON *joe = newPerson("joe", "cole", 38);
        append(people, joe);

        PERSON *michael = newPerson("michael", "jackson", 50);
        append(people, michael);

        PERSON *elvis = newPerson("elvis", "presley", 44);
        insertStart(&people, elvis);

        remove_first(&people);
        remove_last(people);

        print_list(people);

        removePerson(&people, joe);

        removePerson(&people, elvis);

        print_list(people);

        PERSON *found = getPerson(people, 0);
        printf("\n\n-------------------");
        printPerson(found);
        printf("\n-------------------");
    }

    Game *gta = (Game *)calloc(1, sizeof(Game));
    gta->name = "gta";
    gta->year = 1997;

    Game *toca = (Game *)calloc(1, sizeof(Game));
    toca->name = "toca";
    toca->year = 1997;

    t_node *games = newListOfObject(gta);
    appendObject(games, toca);

    Game *g = (Game *)((t_node *)games->next->previous->object);
    printf("\n%s - %d,", g->name, g->year);

    printf("\n%s - %d,",
           ((Game *)getObject(games, 1))->name,
           ((Game *)getObject(games, 1))->year);

    removeObject(&games, gta);
    printf("\nGame count: %d.",countObject(games));
    removeObject(&games, toca);
    printf("\nGame count: %d.",countObject(games));

    return 0;
}
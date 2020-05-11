// cl main.c mathHelper.c person.c

#include <stdio.h>

#include "mathHelper.h"
#include "person.h"

int main(void)
{
    system("cls");

    PERSON *davey = newPerson("davey", "jones", 45);
    node_t *people = newList(davey);

    PERSON *joe = newPerson("joe", "cole", 38);
    append(people, joe);

    PERSON *michael = newPerson("michael", "jackson", 50);
    append(people, michael);

    PERSON *elvis = newPerson("elvis", "presley", 44);
    insertStart(&people, elvis);

    if (1 == 1)
    {
        remove_first(&people);
        remove_last(people);

        print_list(people);

        removePerson(&people, joe);

        removePerson(&people, elvis);

        print_list(people);
    }

    PERSON *found = getPerson(people, 0);
    printf("\n\n-------------------");
    printPerson(found);
    printf("\n-------------------");

    // int y = addFive(3);
    // printf("%d\n", y);

    return 0;
}
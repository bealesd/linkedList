// cl main.c mathHelper.c person.c

#include <stdio.h>

#include "mathHelper.h"
#include "person.h"

int main(void)
{
    PERSON *davey = newPerson("davey", "jones", 45);
    node_t *people = newList(davey);

    PERSON *joe = newPerson("joe", "cole", 38);
    append(people, joe);

    PERSON *michael = newPerson("michael", "jackson", 50);
    append(people, michael);

    // remove_first(&people);
    // remove_last(people);

    PERSON *elvis = newPerson("elvis", "presley", 44);
    insertStart(&people, elvis);
    printf("\nFirst name: %s\n", people->person->fisrtName);

    // print_list(people);
    removePerson(&people, joe);
    removePerson(&people, michael);

    print_list(people);

    // PERSON *found = getPerson(people, 1);
    // printPerson(found);
    // PERSON *found2 = getPerson(people, 0);
    // printPerson(found2);

    // int y = addFive(3);
    // printf("%d\n", y);

    return 0;
}
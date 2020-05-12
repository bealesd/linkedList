#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "person.h"

PERSON *newPerson(char *fisrtName, char *lastName, int age)
{
    PERSON *person = (PERSON *)calloc(1, sizeof(PERSON));
    person->fisrtName = (char *)strdup(fisrtName);
    person->lastName = (char *)strdup(lastName);
    person->age = age;
    return person;
}

node_t *newList(PERSON *person)
{
    node_t *head = NULL;
    head = (node_t *)calloc(1, sizeof(node_t));
    head->person = person;
    head->next = NULL;
    return head;
}

void append(node_t *head, PERSON *person)
{
    node_t *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = (node_t *)calloc(1, sizeof(node_t));
    current->next->person = person;
    current->next->next = NULL;
}

void insertStart(node_t **head, PERSON *person)
{
    node_t *new_node;
    new_node = (node_t *)calloc(1, sizeof(node_t));

    new_node->person = person;
    new_node->next = *head;
    *head = new_node;
}

int remove_first(node_t **head)
{
    int retval = -1;
    node_t *next_node = NULL;

    if (*head == NULL)
    {
        return -1;
    }

    next_node = (*head)->next;
    free(*head);
    *head = next_node;
    retval = 0;

    return retval;
}

void removePerson(node_t **head, PERSON *person)
{
    //guard
    if (person == NULL)
    {
        return;
    }

    node_t *current = *head;

    //check if first record matches person
    if (current->person == person)
    {
        node_t *next_node = NULL;
        next_node = (*head)->next;
        free(*head);
        *head = next_node;
        return;
    }

    // guard, if one person left, no match.
    int length = countPeople(current);
    int count = 1;
    if (length == 1)
    {
        return;
    }

    // does next node match
    // if not role next node forward
    while (count < length && current->next->person != person)
    {
        printf("\nCount: %d.", count);
        current = current->next;
        count++;
    }

    // theres a match on the next node
    if (current->next->person == person)
    {
        node_t *temp_node;
        temp_node = current->next;
        current->next = temp_node->next;
        free(temp_node);
    }
    // there was no macth
    return;
}

int countPeople(node_t *head)
{
    int length;
    node_t *current = head;
    if (current == NULL || current->person == NULL)
    {
        length = 0;
    }
    else
    {
        length = 1;
    }
    while (current->next != NULL)
    {
        current = current->next;
        length++;
    }
    return length;
}

PERSON *getPerson(node_t *head, int index)
{
    //guards
    if (index < 0)
    {
        return NULL;
    }
    //check list length
    int length = countPeople(head);
    if (index + 1 > length)
    {
        return NULL;
    }

    node_t *current = head;

    if (index == 0)
    {
        return current->person;
    }

    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }
    return current->person;
}

void remove_last(node_t *head)
{
    /* if there is only one item in the list, remove it */
    if (head->next == NULL)
    {
        free(head);
    }

    /* get the second to last node in the list */
    node_t *current = head;
    while (current->next->next != NULL)
    {
        current = current->next;
    }

    /* now current points to the second to last item of the list, so let's remove current->next */
    free(current->next);
    current->next = NULL;
}

void print_list(node_t *head)
{
    printf("\n\n-------------------");
    printf("\n\nPrint Persons:");

    node_t *current = head;

    while (current != NULL)
    {
        printf("\n");
        printPerson(current->person);
        current = current->next;
    }
    printf("\n-------------------");
}

void printPerson(PERSON *person)
{
    if (person != NULL)
    {
        printf("\nFirst name: %s.", person->fisrtName);
        printf("\nLast name: %s.", person->lastName);
        printf("\nAge: %d.", person->age);

        printf("\nAddress in memory: %p.", person);
    }
    else
    {
        printf("\nPerson is null.");
    }
}

//   user person codde
//   printf("Enter First Name: ");
//   scanf("%s", std.firstname);

//   printf("Enter Last Name: ");
//   scanf("%s", std.lastname);

//   printf("Enter ID: ");
//   scanf("%s", std.id);

#include "person.h"
#include <stdio.h>

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
    printf("\n\nRemoving Person:");
    printf("\n");
    printPerson(person);

    node_t *current = *head;

    //check if first record matches person
    if (current->person == person)
    {
        node_t *next_node = NULL;
        next_node = (*head)->next;
        free(*head);
        printf("\n\nPerson at address: %p, removed!", person);
        *head = next_node;
        return;
    }
    //does next node match
    // if not role next node forward
    while (current->next->person != person)
    {
        current = current->next;
    }

    //theres a match on the next node
    if (current->next->person == person)
    {
        node_t *temp_node;
        temp_node = current->next;
        current->next = temp_node->next;
        printf("\n\nPerson at address: %p, removed!", person);
        free(temp_node);
    }
}

void remove_last(node_t *head)
{
    /* if there is only one item in the list, remove it */
    if (head->next == NULL)
    {
        free(head);
    }

    /* get to the second to last node in the list */
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
    printf("\n\nPrint Persons:");

    node_t *current = head;

    while (current != NULL)
    {
        printf("\n");
        printPerson(current->person);
        current = current->next;
    }
}

PERSON *getPerson(node_t *head, int index)
{
    int count = 0;
    node_t *current = head;

    if (index == 0)
    {
        return current->person;
    }

    while (current->next != NULL)
    {
        current = current->next;
        if (index == ++count)
        {
            return current->person;
        }
    }

    return NULL;
}

// list *getPersonByAge(int age)
// {
//     //create new list for results
//     list *personsByAge = malloc(sizeof(list));
//     personsByAge->next = NULL;
//     personsByAge->person = NULL;

//     list *nextElement = PERSONS;
//     while (nextElement != NULL)
//     {
//         printf("\nIn age: age: %d\n", nextElement->person->age);
//         if (nextElement->person->age == age)
//         {
//             printf("\nIn age: First name: %s\n", nextElement->person->fisrtName);
//             //append to results
//             if (personsByAge->next == NULL)
//             {
//                 personsByAge->person = nextElement->person;
//             }
//             else
//             {
//                 personsByAge->next = nextElement->person;
//                 personsByAge = personsByAge->next;
//             }
//         }
//         nextElement = nextElement->next;
//     }
//     //return NULL if list is empty
//     if (personsByAge->person == NULL)
//     {
//         return NULL;
//     }
//     else
//     {
//         return personsByAge;
//     }
// }

void printPerson(PERSON *person)
{
    printf("\nFirst name: %s.", person->fisrtName);
    printf("\nLast name: %s.", person->lastName);
    printf("\nAge: %d.", person->age);

    printf("\nAddress in memory: %p.", person);
}

//   user person codde
//   printf("Enter First Name: ");
//   scanf("%s", std.firstname);

//   printf("Enter Last Name: ");
//   scanf("%s", std.lastname);

//   printf("Enter ID: ");
//   scanf("%s", std.id);

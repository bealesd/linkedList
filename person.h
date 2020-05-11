// #ifndef OBJECT   /* Guard for it already being defined. */
// #define OBJECT

// typedef struct Object Object;
// #endif

typedef struct
{
    char *fisrtName;
    char *lastName;
    int age;

} PERSON;

typedef struct node
{
    PERSON *person;
    struct node *next;
} node_t;

node_t *newList(PERSON *value);

void append(node_t *head, PERSON *person);

void insertStart(node_t ** head, PERSON *person);

int remove_first(node_t ** head);

void remove_last(node_t * head);

void print_list(node_t *head);

void removePerson(node_t **head, PERSON *person);

PERSON *getPerson(node_t *head, int index);

PERSON *newPerson(char *fisrtName, char *lastName, int age);

int countPeople(node_t *head);

void printPerson(PERSON *person);
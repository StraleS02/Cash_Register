#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 20
#define MAX_SNAME 30

typedef struct user {                                           //structure of a user
	char name;
	char surename;
	int code;
    struct user *sl;
}USER;

FILE* safe_open(char*, char*);                             //prototypes of used functions
void load(FILE*, USER**);
USER* make_user(char*, char*, int);

void list_init(USER**);
void delete_list(USER**);
void add_to_list(USER** head, USER* nuevo);

FILE* safe_open(char* name, char* mode) {     //file opening function
    FILE* f = fopen(name, mode);

    if (f == NULL) {
        printf("Error loading file %s\n", name);
        exit(EXIT_FAILURE);
    }
    return f;
}

void list_init(USER** head) {                                   //list initialisation function
    *head = NULL;
    return;
}

void delete_list(USER** head) {                                 //list deletion function
    USER* t;

    while (*head != NULL) {
        t = *head;
        *head =  (*head)->sl;
        free(t);
    }
    return;
}

void add_to_list(USER** head, USER* nuevo) {                    //adding user to list function
    if (*head == NULL) {
        *head = nuevo;
    }
    else {
        USER* t = *head;
        while (t->sl != NULL) {
            t = t->sl;
        }
        t->sl = nuevo;
    }
    return;
}

void load(FILE* f, USER** head) {                               //loading users from text file to list function
    int code;
    int index;
    char name[MAX_NAME],
        surename[MAX_SNAME];

    while (fscanf(f, "%s %s %d",
        name,
        surename,
        &code) != EOF) {
        add_to_list(head, make_user(name, surename, code));
    }
    return;
}

USER* make_user(char* name, char* surename, int code) {         //loading structure from text file function  
    USER* nuevo = (USER*)malloc(sizeof(USER));

    if (nuevo == NULL) {
        printf("Could not allocate memory.");
        exit(EXIT_FAILURE);
    }

    strcpy(&nuevo->name, name);
    strcpy(&nuevo->surename, surename);
    nuevo->code = code;
    return nuevo;
}

int searchElement(USER* head, int code)                         //list search function
{
    USER* current = head;
    char name[MAX_NAME],
        surename[MAX_SNAME];

    while (current != NULL)
    {
        if (current->code == code) {
            printf("%s %s", name, surename);
            return 0;
        }
        current = current->sl;
    }
    printf("non existing user");
}

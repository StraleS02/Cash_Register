#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct user {                                           //structure of a user
	char name;
	char surename;
	int code;
	struct user* sl;
}USER;

FILE* safe_open(const char*, const char*);                             //prototypes of used functions
void load(FILE*, USER**);
USER* make_user(char*, char*, int);

void list_init(USER**);
void delete_list(USER**);
void add_to_list(USER**, USER*);
USER* searchElement(USER*, int);
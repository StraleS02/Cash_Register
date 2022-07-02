#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.cpp"

int main() {
	USER* head;
	//int x=123;
	FILE* users = safe_open("user.txt", "r");
	list_init(&head);
	load(users, &head);
	fclose(users);
	//printf("enter your code: ");
	//scanf_s("%d", &x);
	//int n=searchElement(head, x);
	delete_list(&head);
	return EXIT_SUCCESS;
}
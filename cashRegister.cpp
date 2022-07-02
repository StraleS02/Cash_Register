#include "user.h"
#pragma warning(push)
#pragma warning(disable: 6001)
#pragma warning(push)
#pragma warning(disable: 4101)
#pragma warning(push)
#pragma warning(disable: 4477)
#pragma warning(push)
#pragma warning(disable: 4313)
int main() {
	
	USER* head;
	int code;
	USER* person;
	printf("enter your code: ");
	scanf("%d", &code);
	FILE* users = safe_open("user.txt", "r");
	list_init(&head);
	load(users, &head);
	fclose(users);
	person=searchElement(head, code);
	if (person == NULL) {
		printf("user not found");
	}
	else {
		printf("%s %s", &person->name, &person->surename);
	}
	delete_list(&head);
	return EXIT_SUCCESS;
}
#pragma warning(pop)
#pragma warning(pop)
#pragma warning(pop)
#pragma warning(pop)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node() {
	char *data;
	struct Node *next;
};

Node *head_ptr = NULL;

int insert(char *data) {
	if (head_ptr == NULL) {
		head_ptr = (struct Node*)malloc(sizeof(struct Node));
		head_ptr->data = data;
		head_ptr->next = NULL;
	}
	else if (strcmp((const char*)data, (const char*)head_ptr->data) < 0) {


}

int main(int argc, char *argv[]) {
	struct Node *head = NULL;
	struct Node *node2 = NULL;
	struct Node *node3 = NULL;

	head = (struct Node*)malloc(sizeof(struct Node));
	node2 = (struct Node*)malloc(sizeof(struct Node));
	node3 = (struct Node*)malloc(sizeof(struct Node));	
}

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/*
Template of node with a head pointer being initialized as global.
*/
struct node {
	int data;
	struct node* link;
}*head;

void append();
void insert();
void delete();
void reverse();
void sort();
void display();
void delete_list();

int main() {
	char opt;
	head = NULL;

	do {
		system("cls");
		printf("Linked list program\n");
		printf("-------------------\n");
		printf("1. Append new node\n");
		printf("2. Insert new node\n");
		printf("3. Delete node\n");
		printf("4. Reverse list\n");
		printf("5. Sort list\n");
		printf("6. Display list\n");
		printf("7. Delete list\n");
		printf("[X to exit]\n");
		printf("\nSelection: ");
		opt = getchar(); while (getchar() != '\n');
		switch (opt) {
			case '1':
				append();
				printf("\nAfter appending:-\n");
				display();
				break;
			case '2':
				insert();
				printf("\nAfter inserting:-\n");
				display();
				break;
			case '3':
				delete();
				printf("\nAfter deleting:-\n");
				display();
				break;
			case '4':
				reverse();
				printf("\nAfter reversing:-\n");
				display();
				break;
			case '5':
				sort();
				printf("\nAfter sorting:-\n");
				display();
				break;
			case '6':
				display();
				break;
			case '7':
				delete_list();
				break;
			case 'X':
			case 'x':
				printf("---PROGRAM ENDED---");
				break;
			default:
				printf("Invalid option.\n");
				_getch();
		}
	} while (opt != 'X' && opt != 'x');
	return 0;
}

/*
Append works by creating a node and check if the head is pointing at a node or not, if not, the head can point to this new node, otherwise, a pointer will traverse until end of list and append new node.
*/
void append() {
	int num;
	printf("New data: ");
	scanf_s("%d", &num); while (getchar() != '\n');

	struct node* ptr, * temp;
	temp = malloc(sizeof(struct node));
	temp->data = num;
	temp->link = NULL;

	ptr = head;
	if (head == NULL) {
		head = temp;
	}
	else {
		while (ptr->link) {
			ptr = ptr->link;
		}
		ptr->link = temp;
	}
}

/*
Insert works by creating a new node and getting the position. During traversal of each node, a counter variable takes note of how many jump it'd made and insert the new node once it reaches the node before position.
*/
void insert() {
	int num, pos, ctr = 1;
	printf("New data: ");
	scanf_s("%d", &num); while (getchar() != '\n');
	printf("Position of node to insert: ");
	scanf_s("%d", &pos); while (getchar() != '\n');

	struct node* ptr,* temp;
	temp = malloc(sizeof(struct node));
	temp->data = num;
	temp->link = NULL;

	ptr = head;
	if (ptr == NULL) {
		printf("\nList is empty. New node will be assign at first node");
		head = temp;
	}
	else {
		while (ptr) {
			ctr++;
			if (ctr == pos) {
				temp->link = ptr->link;
				ptr->link = temp;
				break;
			}
			ptr = ptr->link;
		}
		if (ptr == NULL) {	// If loop through list but havn't reach node, just append
			printf("Position exceeded length of linked list. New node will be appended instead.\n");
			ptr = head;
			while (ptr->link) {
				ptr = ptr->link;
			}
			ptr->link = temp;
		}
	}
}

/*
Delete works by getting the position and traverse the list. Once it reach a node before the position, it will maodify the links and remove the node of said position.
*** Can be modify to get value of node to be deleted ***
*/
void delete() {
	int pos, ctr = 1;

	printf("Position of node to delete: ");
	scanf_s("%d", &pos); while (getchar() != '\n');

	struct node* ptr, *temp;
	ptr = head;
	temp = ptr->link;
	if (ptr == NULL) {
		printf("\nList is empty.");
	}
	else {
		while (ptr) {
			ctr++;
			if (ctr == pos) {
				ptr->link = temp->link;
				temp->link = NULL;
				free(temp);
				break;
			}
			ptr = ptr->link;
			if (ptr != NULL) {
				temp = ptr->link;
			}
			else {
				printf("Position exceeded lenght of linked list. No node will be deleted.\n");
			}
		}
	}
}

/*
Reverse works by using two pointers with head pointer and while traversing the list, it changes the link.
*/
void reverse() {
	struct node* prev = NULL, * next = NULL;
	while (head != NULL) {
		next = head->link;
		head->link = prev;;
		prev = head;
		head = next;
	}
	head = prev;
}

/*
Sort works by bubble sorting. It checks with the next node's value and swap if needed. This sort algorithm has time complexity of o(n^2) for worst scenario.
*/
void sort() {
	struct node* i, * j;
	int temp;

	i = head;
	for (i = head; i->link != NULL; i = i->link) {
		for (j = i->link; j != NULL; j = j->link) {
			if (i->data > j->data) {
				temp = i->data;
				i->data = j->data;
				j->data = temp;
			}
		}
	}
}

/*
Display will traverse all nodes while printing the data
*/
void display() {
	int ctr = 1;
	struct node* ptr;
	ptr = head;
	printf("Linked list:\n");
	if (ptr == NULL) {
		printf("There is no linked list.\n");
		_getch();
	}
	else {
		while (ptr) {
			printf("Node #%d: %d\n", ctr++, ptr->data);
			ptr = ptr->link;
		}
		_getch();
	}
}

/*
Delete_list free each nodes by traversing the list
*/
void delete_list() {
	struct node* ptr = head;
	while (ptr != NULL) {
		ptr = ptr->link;
		free(head);
		head = ptr;
	}
	printf("linked list deleted.\n");
	_getch();
}

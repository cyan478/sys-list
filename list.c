#include <stdio.h>
#include <stdlib.h>

struct node { int i; struct node *next };
//===================================================================== print_list
void print_list( struct node *list ){
	printf("[");
	if (list == 0) //if list is empty then print []
		printf("] \n");
	else {
		while (list -> next) { //fixes end comma problem
			printf( "%d,", list -> i);
			list = list -> next;
		}
		printf("%d] \n", list -> i);
	}
}
//===================================================================== insert_front
struct node *insert_front(void *list, int *data){
	struct node *hd = (struct node *)malloc(sizeof(struct node)); //new head
	hd -> i = data;
	hd -> next = list;
	return hd;
}
//====================================================================== free_list
struct node *free_list(struct node *list){
    struct node *tmp; //helps w iteration
	while (list){
		tmp = list -> next; 
		free(list);
		list = tmp;
	}
	return list;
}
//====================================================================== main
int main(){
	struct node *head;
	struct node *n1 = (struct node *)malloc(sizeof(struct node));
	struct node *n2 = (struct node *)malloc(sizeof(struct node));
	struct node *n3 = (struct node *)malloc(sizeof(struct node));
	head = n1;

	n1 -> i = 3;
	n2 -> i = 5;
	n3 -> i = 7;

	n1 -> next = n2;
	n2 -> next = n3;
	n3 -> next = NULL;

	printf("----------------------------* \n");
	printf("print_list: \n");
	print_list(head); //[3,5,7] works!!

	printf("--------------------* \n");
	printf("insert_front: \n");
	head = insert_front(head,1);
	print_list(head); //[1,3,5,7] works!!

	printf("--------------------* \n");
	printf("free_list: \n");
	head = free_list(head);
	printf("head: %d \n", head); //0 works!!
	print_list(head); //[] works!!
	printf("----------------------------* \n");

	return 0;
}
//====================================================================== testing code output
/* PRINT OUTPUT:
----------------------------* 
print_list: 
[3,5,7] 
--------------------* 
insert_front: 
[1,3,5,7] 
--------------------* 
free_list: 
head: 0 
[] 
----------------------------* 
*/
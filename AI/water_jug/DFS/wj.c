#include <stdio.h>
#include <stdlib.h>

struct node{
	int x, y;
	struct node *next;
	struct node *parent;
};

struct node *head = NULL;

struct node* assign(int a, int b){
	struct node *t = (struct node *)malloc(sizeof(struct node));
	t->next = NULL;
	t->x = a;
	t->y = b;
	return t;
}

struct node *production_rules(struct node *E){
	// Returns NULL only when there is no rules applied
	int a = E->x;
	int b = E->y;
	struct node *t = NULL;

	if(a<4){
		t = assign(4, b);
	}
	else if(b<3){
		t = assign(a, 3);
	}
	else if(a>0){
		t = assign(0, b);
	}
	else if(b>0){
		t = assign(a, 0);
	}
	else if(a+b>=4 && b>0){
		t = assign(4, b-(4-a));
	}
	else if(a+b>=3 && a>0){
		t = assign(a-(3-b), 3);
	}
	else if(a+b<=4 && b>0){
		t = assign(a+b, 0);
	}
	else if(a+b<=3 && a>0){
		t = assign(0, a+b);
	}
	else if(a==0 && b==2){
		t = assign(2, 0);
	}

	return t;

}

void display_ll(struct node *E){
	printf("\nTrace:\n");
	struct node *ptr = head;
	while(ptr!=NULL){
		printf("(%d, %d) --> ", ptr->x, ptr->y);
		ptr = ptr->next;
	}
	printf("(%d, %d)\n", E->x, E->y);
}

void DFS(){
	//head is the initial state
	head = (struct node *) malloc(sizeof(struct node));
	head->x = 0;
	head->y = 0; 
	head->next = NULL;

	struct node *E = head;
	E = production_rules(E);

	while(E!=NULL){
		if(E->x == 2){
			// Goal state reached
			printf("\n Goal state reached");
			struct node *ptr = head;
			display_ll(E);
			return;
		}
		else{
			//Check whether the state is already in the list
			struct node *ptr = head;
			int flag =0;
			while(ptr!=NULL){
				if(ptr->x == E->x && ptr->y == E->y){
					printf("Failure because of repetition of same state!");
					display_ll(E);
					return;
				}
				ptr = ptr->next;
			}
			// Add the state to the end of the list
			ptr = head;
			while(ptr->next != NULL){
				ptr = ptr->next;
			}
			ptr->next = E;
		}
		E = production_rules(E);
	}

	printf("Failure because no rules can be applied!");
	display_ll(E);
}

void main(){
	DFS();
}
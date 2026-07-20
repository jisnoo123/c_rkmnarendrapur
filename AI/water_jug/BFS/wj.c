#include <stdio.h>
#include <stdlib.h>

struct node{
	int x, y;
	struct node *next;
	struct node *parent;
};

struct node *head = NULL;
struct node *goal;

struct node* assign(int a, int b){
	// Assign a node to the end of the linked list
	struct node *last = head;
	while(last->next != NULL){
		last = last->next;
	}
	struct node *t = (struct node *)malloc(sizeof(struct node));
	t->next = NULL;
	t->x = a;
	t->y = b;
	t->parent = head;
	last->next = t;
	return t;
}

int production_rules(){
	// Production rules for the water jug problem
	int a = head->x;
	int b = head->y;

	if(a<4){
		assign(4, b);
		//printf("4 %d\n", b);
	}

	if(b<3){
		goal = assign(a, 3);
		//printf("%d 3\n", a);
		if(a==2){ return 1;}
	}

	if(a>0){
		assign(0, b);
		//printf("0 %d\n", b);
	}

	if(b>0){
		goal = assign(a, 0);
		//printf("%d 0\n", a);
		if(a==2){return 1;}
	}
	
	if(a+b>=4 && b>0){
		assign(4, b-(4-a));
		//printf("4 %d\n", b-(4-a));
	}

	if(a+b>=3 && a>0){
		goal = assign(a-(3-b), 3);
		//printf("%d 3\n", a-(3-b));
		if(a-(3-b)==2){return 1;}
	}

	if(a+b<=4 && b>0){
		goal = assign(a+b, 0);
		//printf("%d 0\n", a+b);
		if(a+b==2){return 1;}
	}

	if(a+b<=3 && a>0){
		assign(0, a+b);
		//printf("0 %d\n", a+b);
	}

	if(a==0 && b==2){
		goal = assign(2, 0);
		//printf("2 0\n");
		return 1;
	}

	head = head->next;
	return 0;
}

void BFS(){
	struct node* NODE_LIST = (struct node *)malloc(sizeof(struct node));
	NODE_LIST->x = 0;
	NODE_LIST->y = 0;
	NODE_LIST->next = NULL;
	NODE_LIST->parent = NULL;
	head = NODE_LIST;
	struct node *head1 = head;
	
	while(head!=NULL){
		int res = production_rules();
		if(res == 1){
			printf("Successful!\n");
			struct node *p = goal;
			while(p!=NULL){
				printf("(%d, %d) <- ", p->x, p->y);
				p = p->parent;
			}
			break;
		}
	}
}

int main(){
	BFS();
}
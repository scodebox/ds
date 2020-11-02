#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* link;
}*FRONT=NULL, *REAR=NULL;


int is_empty(){
	if(FRONT==NULL && REAR==NULL)
		return 1;
	else
		return 0;
}


int enqueue(int item){
	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	if(new_node == NULL){
		printf("\n\tOVERFLOW!");
		return -1;
	}else{
		new_node->data = item;
		new_node->link = NULL;
		if(is_empty())
			FRONT=REAR=new_node;
		else{
			REAR->link=new_node;
			REAR = new_node;
		}
		return 1;
	}
}


int dequeue(){
	if(is_empty()){
		printf("\n\tUNDERFLOW!");
		return -1;
	}else{
		int item = FRONT->data;
		struct node *del = FRONT;
		
		if(FRONT==REAR)
			FRONT=REAR=NULL;
		else
			FRONT=FRONT->link;
		del->link = NULL;

		free(del);
		return item;
	}
}


void queue_content(){
	if(is_empty()){
		printf("\n\tEMPTY!");
		return;
	}else{
		struct node *i;
		i = FRONT;

		printf("\nQUEUE CONTENT : ");
		while(i){
			printf(" %d",i->data);
			i=i->link;
		}
	}
}


int items_inside(){
	if(is_empty())
		return 0;
	else{
		struct node *i = FRONT;
		int counter=0;

		printf("\nQUEUE CONTENT : ");
		while(i){
			++counter;
			i=i->link;
		}
	}
}


int main(int argc, char const *argv[])
{
	int choice,input;
	while(1){
		
		printf("\n<<<<<<<<<<<<<<< OPTIONS >>>>>>>>>>>>>>>>");
		printf("\n1 ENQUEUE");
		printf("\n2 DEQUEUE");
		printf("\n3 CHECK EMPTY");
		printf("\n4 NUMBER OF ITEMS INSIDE");
		printf("\n5 STACK CONTENT");
		
		printf("\n\n0 EXIT\n");
		
		printf("---------------------------------------");
		
		printf("\nENTER CHOICE : ");
		scanf("%d",&choice);
		
		switch(choice){
			case 0:
				exit(1);
			case 1:
				printf("\nENTER ITEM : ");
				scanf("%d",&input);
				enqueue(input);
				break;
			case 2:
				printf("\nITEM POPED : %d",dequeue());
				break;
			case 3:
				if(is_empty())
					printf("\n\tQUEUE IS EMPTY!");
				else
					printf("\n\tQUEUE IS NOT EMPTY!");
				break;
			case 4:
				printf("\nNUMBER OF ITEM INSIDE : %d",items_inside());
				break;
			case 5:
				queue_content();
				break;
			default:
				printf("\nINVALID INPUT!");
		}
	}
	return 0;
}
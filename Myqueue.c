#include<stdio.h>
#include<stdlib.h>
void enqueue();
void dequeue();
void display();
struct node
{
	int data;
	struct node *next;
}*front,*rear,*temp;
main()
{
	int ch;
	ch = 1;
	front = rear = 0;
	while(ch)
	{
		printf("1 ---> Enqueue\n2 ---> Dequeue\n3 --->Display\n0 ---> Exit\n\n");
		printf("Enter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			default:
				printf("Invalid Choice\n");
		}
	}
}


void enqueue()
{
	struct node *newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("Enter data : ");
	scanf("%d",&newnode->data);
	newnode->next = 0;
	if(front==0&&rear==0)
	front = rear = newnode;
	else
	{
		rear->next = newnode;
		rear = newnode;
	}
}

void display()
{
	temp = front;
	if(front == 0 && rear == 0)
	printf("\nQueue is Underflow\n\n");
	else
	{
		printf("\nElements in the queue are : \n\n");
		while(temp!=0)
		{
			printf("%d\n",temp->data);
			temp = temp->next;
		}
		printf("\n\n");
	}
}


void dequeue()
{
	if(front==0 && rear == 0)
		printf("\nQueue is underFlow\n\n");
	else if(front->next == 0)
	{
		temp = front;
		printf("\nDequeued element is  %d\n",front->data);
		front = rear = 0;
		free(temp);
	}
	else
	{
		temp = front ;
		printf("\nDequeued element is  %d\n",front->data);
		front = front->next;
		free(temp);
	}
}

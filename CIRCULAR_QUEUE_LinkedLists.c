//author : Hamora Hadi

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct SData Data;

struct SData{
	char *name[5][6][7];
	int RollNo;
	Data *next;
};

Data *front=NULL;
Data *rear=NULL;

int len;

void Enqueue(){
	Data *temp;
	temp=(Data *)malloc(sizeof(Data));
	
	printf("Insert name : ");
	scanf(" %[^\n]",&temp->name);
	printf("Insert Roll Number : ");
	scanf(" %d",&temp->RollNo);
	
	temp->next=NULL;
	
	if(front==NULL && rear==NULL){
		front=rear=temp;
		return;
	}
	rear->next=temp;
	rear=front;
	rear=temp;
}

void Dequeue(){
	Data *temp=front;
	
	if(front==NULL){
		return;
	}
	
	if(front==rear){
		front=rear=NULL;
	}
	else{
		front=front->next;
	}
	free(temp);
}

void Show(){
	Data *temp;
	temp=front;
	
	if(temp==NULL){
		printf("No lists of queue\n\n");
	}
	else{
		while(temp!=NULL){
			printf("Name : %s\n",temp->name);
			printf("Roll Number : %d\n\n",temp->RollNo);
			temp=temp->next;
		}
	}
}

int Length(){
	int count=0;
	Data *temp;
	temp=front;
	
	while(temp!=NULL){
		count++;
		temp=temp->next;
	}
	return count;
}

int main(){
	char choose;
	start:
	
	puts("Choose!");
	puts("1. Enqueue");
	puts("2. Dequeue");
	puts("3. Show");
	puts("4. Length");
	printf("->");
	scanf(" %s",&choose);
	switch(choose)
	{
		case'1':
			Enqueue();
			break;
		case'2':
			Dequeue();
			break;
		case'3':
			Show();
			break;
		case'4':
			len = Length();
			printf("Length of list is : %d\n\n",len);
			break;
		default:
			printf("Invalid choosen\n\n");
			break;
	}
	
	
	
	goto start;
	return 0;
}

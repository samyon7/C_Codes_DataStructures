//author : Hamora Hadi

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

int len;

typedef struct SData Data;

struct SData{
	char name[5][6][7];
	int RollNo;
	Data *next;
};

Data *top=NULL;

void Push(){
	Data *temp;
	
	temp=(Data *)malloc(sizeof(Data));
	
	printf("Insert name : ");
	scanf(" %[^\n]",&temp->name);
	printf("Insert Roll Number : ");
	scanf(" %d",&temp->RollNo);
	
	temp->next=top;
	top=temp;
}

void Traverse(){
	Data *temp;
	
	if(top==NULL){
		printf("Stack is empty.\n");
	}
	else{
		temp=top;
		while(temp!=NULL){
			printf("--------------------------------------\n");
			printf("Name : %s\n",temp->name);
			printf("Roll Number : %d\n",temp->RollNo);
			temp=temp->next;
		}
		printf("--------------------------------------\n");
	}
}

void Pop(){
	Data *temp;
	
	temp=top;
	
	if(temp==NULL){
		printf("No element\n");
	}
	else{
		temp=top;
		printf("Name : %s\n",temp->name);
		printf("Roll Number %d\n\n",temp->RollNo);
		top=top->next;
		temp->next=NULL;
		free(temp);
	}
}

int Length(){
	int count=0;
	Data *temp;
	temp=top;
	
	while(temp!=NULL){
		count++;
		temp=temp->next;
	}
	return count;
}

void Delete(){
	Data *temp;
	int location;
	
	printf("Insert the location to delete (based top position) : ");
	scanf(" %d",&location);
	
	if(location>Length()){
		printf("Invalid location!\n");
	}
	else if(location==1){
		temp=top;
		top=temp->next;
		temp->next=NULL;
		free(temp);
	}
	else{
		Data *p=top,*q;
		int i=1;
		while(i<location-1){
			p=p->next;
			i++;
		}
		q=p->next;
		p->next=q->next;
		q->next=NULL;
		free(q);
	}
}

int main(){
	char choose;
	start:
	
	puts("Choose!");
	puts("1. Insert");
	puts("2. Show");
	puts("3. Delete(Pop)");
	puts("4. Want to know how many products");
	puts("5. Delete from position that user given");
	printf("->");
	scanf(" %s",&choose);
	switch(choose)
	{
		case'1':
			Push();
			break;
		case'2':
			Traverse();
			break;
		case'3':
			Pop();
			break;
		case'4':
			len = Length();
			if(len<2){
				printf("The product are : %d product\n",len);
			}
			else{
				printf("The products are : %d products\n",len);
			}
			break;
		case'5':
			Delete();
			break;
		default:
			printf("You insert the wrong!\n\n");
			break;
	}
	
	
	
	goto start;
	end:
	
	return 0;
}

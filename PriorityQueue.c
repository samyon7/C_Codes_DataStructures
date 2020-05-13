#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef struct Data Data;

struct Data{
	char NameID[50];
	int RollNo;
	Data *next;
};

Data *front=NULL, *rear=NULL;

void Insert(){
	char name[50];
	int roll;
	
	Data *temp=(Data *)malloc(sizeof(Data));
	printf("Insert Name ID : ");
	scanf(" %[^\n]",&name);
	printf("Insert Roll Number : ");
	scanf(" %d",&roll);
	
	strcpy(temp->NameID,name);
	temp->RollNo=roll;
	temp->next=NULL;
	
	if(front==NULL){
		front=rear=temp;
	}
	else{
		if(roll < temp->RollNo){
			temp->next=front;
			front=temp;
		}
		else{
			Data *curr=front;
			while(curr->next!=NULL && curr->next->RollNo <= roll){
				curr=curr->next;
			}
			temp->next=curr->next;
			curr->next=temp;
		}
	}
}

void Show(){
	Data *temp=front;
	
	while(temp!=NULL){
		printf("Name : %s\n",temp->NameID);
		printf("Roll No : %d\n\n",temp->RollNo);
		temp=temp->next;
	}
}

int main(){
	int i;
	for(i=0;i<3;i++){
		Insert();
	}
	
	Show();
	
	return 0;
}

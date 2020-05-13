//author : Hamora Hadi

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct SData Data;

struct SData{
	int data;
	Data *right;
	Data *left;
};

Data *root=NULL;
int len;

void Append(){
	Data *temp;
	
	temp=(Data *)malloc(sizeof(Data));
	
	printf("Insert data : ");
	scanf(" %d",&temp->data);
	
	temp->left=NULL;
	temp->right=NULL;
	
	if(root==NULL){
		root=temp;
	}
	else{
		Data *p;
		p=root;
		while(p->right!=NULL){
			p=p->right;
		}
		p->right=temp;
		temp->left=p;
	}
}

void AddBegin(){
	Data *temp;
	
	temp=(Data *)malloc(sizeof(Data));
	
	printf("Insert data : ");
	scanf(" %d",&temp->data);
	
	temp->left=NULL;
	temp->right=NULL;
	
	if(root==NULL){
		root=temp;
	}
	else{
		temp->right=root;
		root->left=temp;
		root=temp;
	}
}

int Length(){
	int count=0;
	Data *temp;
	temp=root;
	
	while(temp!=NULL){
		count++;
		temp=temp->right;
	}
	return count;
}

void Display(){
	Data *temp;
	temp=root;
	
	if(temp==NULL){
		printf("No lists\n\n");
	}
	else{
		while(temp!=NULL){
			printf("Data : %d\n",temp->data);
			temp=temp->right;
		}
	}
}

void AddAfter(){
	Data *temp,*p;
	int location,len,i=1;
	
	printf("Insert position : ");
	scanf(" %d",&location);
	
	len=Length();
	
	if(location>len){
		puts("Invalid position\n");
	}
	else{
		temp=(Data *)malloc(sizeof(Data));
		
		printf("Insert data : ");
		scanf(" %d",&temp->data);
		
		temp->left=NULL;
		temp->right=NULL;
		p=root;
		
		while(i<location){
			p=p->right;
			i++;
		}
		temp->right=p->right;
		p->right->left=temp;
		temp->left=p;
		p->right=temp;
	}
	
}

int main(){
	char choose;
	start:
		;
	puts("Choose one : ");
	puts("1. Append");
	puts("2. Add After");
	puts("3. Length");
	puts("4. Show Lists");
	puts("5. Delete");
	puts("6. Quit");
	printf("->");
	scanf(" %s",&choose);
	switch(choose)
	{
		case'1':
			Append();
			break;
		case'2':
			AddAfter();
			break;
		case'3':
			len = Length();
			printf("Length : %d\n",len);
			break;
		case'4':
			Display();
			break;
		case'5':
			break;
	}
	
	goto start;
	return 0;
}


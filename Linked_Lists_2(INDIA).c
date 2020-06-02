#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct SData Data;

struct SData{
	char *name[5][6][7];
	int RollNo;
	Data *link;
};

Data *root=NULL;
int len;

void Append(){
	Data *temp;
	temp=(Data *)malloc(sizeof(Data));
	
	printf("Insert Name product : ");
	scanf(" %[^\n]",&temp->name);
	printf("Insert Roll Number of Product : ");
	scanf(" %d",&temp->RollNo);
	
	temp->link=NULL;
	
	if(root==NULL){
		root=temp;
	}
	else{
		Data *p;
		p=root;
		while(p->link!=NULL){
			p=p->link;
		}
		p->link=temp;
	}
}

void Reverse(){
	Data *temp,*prev,*reverse;
	temp=root;
	
	prev=NULL;
	
	while(temp!=NULL){
		reverse=temp->link;
		temp->link=prev;
		prev=temp;
		temp=reverse;
	}
	root=prev;
}

int Length(){
	int count=0;
	Data *temp;
	temp=root;
	
	while(temp!=NULL){
		count++;
		temp=temp->link;
	}
	return count;
}

void Show(){
	Data *temp;
	temp=root;
	
	if(temp==NULL){
		printf("List is empty.\n\n");
	}
	else{
		while(temp!=NULL){
			printf("Name Product : %s\n",temp->name);
			printf("Roll Number : %d\n\n",temp->RollNo);
			temp=temp->link;
		}
		printf("\n\n");
	}
}

void Delete(){
	Data *temp;
	int location;
	
	printf("Insert the location to delete : ");
	scanf(" %d",&location);
	
	if(location>Length()){
		printf("Invalid location!\n");
	}
	else if(location==1){
		temp=root;
		root=temp->link;
		temp->link=NULL;
		free(temp);
	}
	else{
		Data *p=root,*q;
		int i=1;
		while(i<location-1){
			p=p->link;
			i++;
		}
		q=p->link;
		p->link=q->link;
		q->link=NULL;
		free(q);
	}
}

void AddAfter(){
	Data *temp,*p;
	int location,len,i=1;
	
	printf("Insert the position : ");
	scanf(" %d",&location);
	len=Length();
	
	if(location>len){
		puts("Invalid location!");
		printf("Currently, the nodes is only %d\n\n",len);
	}
	else{
		p=root;
		while(i<location){
			p=p->link;
			i++;
		}
		temp=(Data *)malloc(sizeof(Data));
		
		printf("Insert Name product : ");
		scanf(" %[^\n]",&temp->name);
		printf("Insert Roll Number of Product : ");
		scanf(" %d",&temp->RollNo);
		
		temp->link=p->link;
		p->link=temp;
	}
}

void Sort(){
	Data *a = NULL;
	Data *b = NULL; 
	Data *c = NULL;
	Data *e = NULL;
	Data *tmp = NULL; 

 /* 
 // the `c' node precedes the `a' and `e' node 
 // pointing up the node to which the comparisons
 // are being made. 
 */
	while(e!=root->link){
		c=a=root;
		b=a->link;
		while(a!=e){
			if(a->RollNo < b->RollNo){
    			if(a==root){
     				tmp=b->link;
     				b->link=a;
    				a->link=tmp;
    				root=b;
    				c=b;
    			}
				else{
     				tmp=b->link;
     				b->link=a;
     				a->link=tmp;
    				c->link=b;
    				c=b;
    			}
   			}
			else{
    			c=a;
    			a=a->link;
			}
   			b=a->link;
   			if(b == e)
				e = a;
  		}
 	}
}

int main(){
	char choose;
	start:
	
	puts("Choose one : ");
	puts("1. Append");
	puts("2. Reverse");
	puts("3. Add After");
	puts("4. Length");
	puts("5. Show Lists");
	puts("6. Delete");
	puts("7. Sort");
	puts("8. Quit");
	printf("->");
	scanf(" %s",&choose);
	switch(choose)
	{
		case'1':
			Append();
			break;
		case'2':
			Reverse();
			break;
		case'3':
			AddAfter();
			break;
		case'4':
			len = Length();
			printf("Length is %d\n",len);
			break;
		case'5':
			Show();
			break;
		case'6':
			Delete();
			break;
		case'7':
			Sort();
			break;
		case'8':
			goto end;
			break;
		default:
			printf("Insert correctly!\n\n");
			break;
	}
	goto start;
	end:
	
	return 0;
}

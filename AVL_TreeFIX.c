#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node Node;

struct Node{
	int data;
	Node *Left,*Right;
	int Height;
};

Node *RR(Node *T);
Node *LL(Node *T);
Node *LR(Node *T);
Node *RL(Node *T);
int BF(Node *T);
Node *Insert(Node *T,int x);
Node *Delete(Node *T,int x);
int height(Node *T);
void PreOrder(Node *T);
void InOrder(Node *T);
Node *RotateRight(Node *x);
Node *RotateLeft(Node *x);

Node *Insert(Node *T,int x){
	if(T==NULL){
		T=(Node *)malloc(sizeof(Node));
		T->data=x;
		T->Left=T->Right=NULL;
	}
	else{
		if(x > T->data){
			T->Right=Insert(T->Right,x);
			if(BF(T)== -2){
				if(x > T->Right->data){
					T=RR(T);
				}
				else{
					T=RL(T);
				}
			}
		}
		else{
			if(x < T->data){
				T->Left=Insert(T->Left,x);
				if(BF(T)==2){
					if(x < T->Left->data){
						T=LL(T);
					}
					else{
						T=LR(T);
					}
				}
			}
		}
		return(T);
	}
}

Node *Delete(Node *T,int x){
	Node *p;
	
	if(T==NULL){
		return NULL;
	}
	else{
		if(x > T->data){
			T->Right=Delete(T->Right,x);
			if(BF(T)==2){
				if(BF(T->Left) >= 0){
					T==LL(T);
				}
				else{
					T=LR(T);
				}
			}
		}
		else{
			if(x < T->data){
				T->Left=Delete(T->Left,x);
				if(BF(T)== -2){
					if(BF(T->Right) <= 0){
						T==RR(T);
					}
					else{
						T=RL(T);
					}
				}
			}
			else{
				if(T->Right!=NULL){
					p=T->Right;
					while(p->Left!=NULL){
						p=p->Left;
					}
					
					T->data=p->data;
					T->Right=Delete(T->Right,p->data);
					if(BF(T)==2){
						if(BF(T->Left) >= 0){
							T=LL(T);
						}
						else{
							T=LR(T);
						}
					}
				}
				else{
					return (T->Left);
				}
			}
		}
	}
	
	T->Height=height(T);
	return (T);
}

int height(Node *T){
	int Left_H,Right_H;
	
	if(T==NULL){
		return 0;
	}
	
	if(T->Left==NULL){
		Left_H=0;
	}
	else{
		Left_H=1+T->Left->Height;
	}
	
	if(T->Right==NULL){
		Right_H=0;
	}
	else{
		Right_H=1+T->Right->Height;
	}
	
	
	if(Left_H > Right_H){
		return(Left_H);
	}
	
	return(Right_H);
}

Node *RR(Node *T){
	T=RotateLeft(T);
	return (T);
}

Node *LL(Node *T){
	T=RotateRight(T);
	return (T);
}

Node *LR(Node *T){
	T->Left=RotateLeft(T->Left);
	T=RotateRight(T);
	
	return (T);
}

Node *RL(Node *T){
	T->Right=RotateRight(T->Right);
	T=RotateLeft(T);
	
	return (T);
}

int BF(Node *T){
	int LH,RH;
	if(T==NULL){
		return 0;
	}
	
	if(T->Left==NULL){
		LH=0;
	}
	else{
		LH=1+T->Left->Height;
	}
	
	if(T->Right==NULL){
		LH=0;
	}
	else{
		LH=1+T->Right->Height;
	}
	
	return(LH-RH);
}

void PreOrder(Node *T){
	if(T!=NULL){
		printf("=> %d ",T->data);
		PreOrder(T->Left);
		PreOrder(T->Right);
	}
}

void InOrder(Node *T){
	if(T!=NULL){
		InOrder(T->Left);
		printf("=> %d ",T->data);
		InOrder(T->Right);
	}
}

Node *RotateRight(Node *x){
	Node *y;
	
	y=x->Left;
	x->Left=y->Right;
	y->Right=x;
	x->Height=height(x);
	y->Height=height(y);
	
	return (y);
}

Node *RotateLeft(Node *x){
	Node *y;
	
	y=x->Right;
	x->Right=y->Left;
	y->Left=x;
	x->Height=height(x);
	y->Height=height(y);
	
	return (y);
}

int main(){
	Node *Root=NULL;
	char Choose;
	
	int ManyElements;
	int data_a;
	int i;
	
	start:
	puts("Choose any operation for AVL tree!");
	puts("1. Create");
	puts("2. Insert");
	puts("3. Delete");
	puts("4. Print");
	puts("5. Quit");
	printf("->");
	scanf(" %s",&Choose);
	switch(Choose)
	{
		case'1':
			printf("Insert how many nodes : ");
			scanf(" %d",&ManyElements);
			Root=NULL;
			for(i=0;i<ManyElements;i++){
				printf("Insert data %d : ",i+1);
				scanf(" %d",&data_a);
				Root=Insert(Root,data_a);
			}
			break;
		case'2':
			printf("Enter data : ");
			scanf(" %d",&data_a);
			Root=Insert(Root,data_a);
			break;
		case'3':
			printf("Enter data : ");
			scanf(" %d",&data_a);
			Root=Delete(Root,data_a);
			break;
		case'4':
			puts("Preorder :");
			PreOrder(Root);
			puts("\nInorder :");
			InOrder(Root);
			break;
		case'5':
			puts("Program terminated!\n");
			goto end;
	}
	puts("");
	goto start;
	end:
	return 0;
}













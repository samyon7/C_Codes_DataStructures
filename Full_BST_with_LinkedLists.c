//author : Hamora Hadi

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<conio.h>

typedef struct bin_tree node;

struct bin_tree {
	int data;
	struct bin_tree * right, * left;	
};

void insert(node ** tree, int val){
    node *temp = NULL;
    if(!(*tree)){
        temp = (node *)malloc(sizeof(node));
        temp->left = temp->right = NULL;
        temp->data = val;
        *tree = temp;
        return;
    }

    if(val < (*tree)->data){
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data){
        insert(&(*tree)->right, val);
    }

}

void print_preorder(node * tree){
    if (tree){
        printf("%d=>",tree->data);
        print_preorder(tree->left);
        print_preorder(tree->right);
    }

}

void print_inorder(node * tree){
    if (tree){
        print_inorder(tree->left);
        printf("%d=>",tree->data);
        print_inorder(tree->right);
    }
}

void print_postorder(node * tree){
    if (tree){
        print_postorder(tree->left);
        print_postorder(tree->right);
        printf("%d=>",tree->data);
    }
}

void deltree(node * tree){
    if (tree){
        deltree(tree->left);
        deltree(tree->right);
        free(tree);
    }
}

node* search(node ** tree, int val){
    if(!(*tree)){
        return NULL;
    }

    if(val < (*tree)->data){
        search(&((*tree)->left), val);
    }
    else if(val > (*tree)->data){
        search(&((*tree)->right), val);
    }
    else if(val == (*tree)->data){
        return *tree;
    }
}

int main(void){
    node *root;
    node *tmp;
    int i,val,many_nodes,search_val;
    char choose;
    root = NULL;
    
    printf("Insert how many nodes : ");
    scanf(" %d",&many_nodes);
    
    for(i=0;i<many_nodes;i++){
	    printf("Insert data : ");
	    scanf(" %d",&val);
	    insert(&root, val);
	}
	
	ask_show:
	puts("Choose show option : ");
	printf("1. Pre Order Display\n");
	printf("2. In Order Display\n");
	printf("3. Post Order Display\n");
	printf("->");
	scanf(" %s",&choose);
    switch(choose)
    {
    	case'1':
		    printf("Pre Order Display\n");
		    print_preorder(root);
			printf("NULL\n");
			break;
		case'2':
			printf("In Order Display\n");
		    print_inorder(root);
			printf("NULL\n");
			break;
		case'3':
			printf("Post Order Display\n");
		    print_postorder(root);
			printf("NULL\n");
			break;
		default:
			printf("You insert the wrong!\nChoose again correctly!\n");
			goto ask_show;
			break;
	}
	
	printf("Insesrt the node that you want to search : ");
	scanf(" %d",&search_val);
    tmp = search(&root, search_val);
    
	if(tmp){
		puts("Data is present.");
        printf("Searched node=%d\n", tmp->data);
    }
    else{
        printf("Data Not found in tree.\n");
    }

    deltree(root);
}

//author : Hamora Hadi

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Node Node;
typedef struct List List;
typedef struct Graph Graph;

struct Node{
	int Dest;
	Node *next;
};

struct List{
	Node *head;
};

struct Graph{
	int V;
	List *Array;
};

Node *NewNode(int Dest){
	Node *New=(Node *)malloc(sizeof(Node));
	New->Dest=Dest;
	New->next=NULL;
	return New;
}

Graph *CreateGraph(int V){
	Graph *graph=(Graph *)malloc(sizeof(Graph));
	graph->V=V;
	graph->Array=(List *)malloc(sizeof(List)*V);
	
	int i;
	for(i=0;i<V;i++){
		graph->Array[i].head=NULL;
	}
	
	return graph;
}

void AddEdge(Graph *graph,int Src,int Dest){
	Node *New=NewNode(Dest);
	New->next=graph->Array[Src].head;
	graph->Array[Src].head=New;
	
	New=NewNode(Src);
	New->next=graph->Array[Dest].head;
	graph->Array[Dest].head=New;
}

void PrintGraph(Graph *graph){
	int vein;
	for(vein=0;vein<graph->V;++vein){
		Node *pCrawl=graph->Array[vein].head;
		printf("\nAdjacency list of vertex %d\n head ",vein);
		while(pCrawl){
			printf("-> %d ",pCrawl->Dest);
			pCrawl=pCrawl->next;
		}
		puts(" ");
	}
}

int main(void){

	
	
	int V;
	int ManyEdges[100];
	int DataEdge[100][100];
	
	int i,j;
	
	printf("Insert how many nodes : ");
	scanf(" %d", &V);
	Graph *graph=CreateGraph(V);
	
	for(i=0;i<V-1;i++){
		printf("How many edges of node %d : ",i);
		scanf(" %d",&ManyEdges[i]);
		for(j=0;j<ManyEdges[i];j++){
			printf("Insert edge %d of node %d : ",j+1,i);
			scanf(" %d",&DataEdge[i][j]);
			AddEdge(graph,i,DataEdge[i][j]);
		}
	}
	
	PrintGraph(graph);
	
	return 0;
}


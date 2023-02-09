#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
} node;

int** initadjmat(int);
node** initadjlist(int);
node* getnode(int);
void insertedge(int**, node**, int, int);

int main() {
	int vert, edges, u, v;

	printf("Enter the number of vertices: ");
	scanf("%d", &vert);

	int** mat = initadjmat(vert);
	node** list = initadjlist(vert);

	printf("Enter the number of edges in the graph: ");
	scanf("%d", &edges);

	printf("Enter the edges as the ordered pairs (u, v):\n");
	for(int i=0; i<edges; i++) {
		scanf("%d %d", &u, &v);
		insertedge(mat, list, u-1, v-1);
	}

	printf("\nAdjacency Matrix for the Given Graph:\n");
	for(int i=0; i<vert; i++) {
		for(int j=0; j<vert; j++) {
			printf("\t%d", mat[i][j]);
		}
		printf("\n");
	}

	printf("\nAdjacency List for the Given Graph:\n");
	for(int i=0; i<vert; i++) {
		printf("%d -> ", i+1);

		node* temp = list[i];

		while(temp) {
			printf("%d ", temp->data+1);
			temp = temp->next;
		}

		printf("\n");
	}

	return 0;
}

int** initadjmat(int v) {
	int** mat = (int**) calloc(v, sizeof(int*));

	for(int i=0; i<v; i++) {
		mat[i] = (int*) calloc(v, sizeof(int));
	}

	return mat;
}

node** initadjlist(int v) {
	return (node**) calloc(v, sizeof(node*));
}

void insertedge(int** mat, node** list, int u, int v) {
	mat[u][v] = 1;

	node* temp = list[u];

	if(temp == NULL) {
		list[u] = getnode(v);
	}
	else {
		while(temp->next) {
			temp = temp->next;
		}
		temp->next = getnode(v);
	}
}

node* getnode(int data) {
	node* temp = (node*) malloc(sizeof(node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}
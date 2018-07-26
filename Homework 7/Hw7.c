#include<stdio.h>
#include<stdlib.h>
#define T int


typedef struct GraphNode {
	T data;
	int value;
	int index;
	int used;
	struct GraphNode* next;
	struct GraphNode* prev;
	struct Stack*children;
} GraphNode;

struct Stack {
	int size;
	struct GraphNode* head;
}Stack;

typedef struct Queue {
	GraphNode* head;
	GraphNode* tail;
	int size;
} Queue;

Queue q;


void initList (Queue* q)
{
	q->head = NULL;
	q->tail = NULL;
	q->size = 0;
}

//Task  1. Написать функции, которые считывают матрицу смежности из файла и выводят ее на экран
void readFromFile()
{
    FILE *file;
  int N=3;
  int arr[N][N];
  int i;
  int j;
    file=fopen("in.txt","r");

  for(i=0;i<N;i++)
   for(j=0;j<N;j++)
    fscanf(file,"%3i",&arr[i][j]);
    for(i=0;i<N;i++)
    {
    for(j=0;j<N;j++)

      printf("%3i ",arr[i][j]);
      printf("\n");
    }
      fclose(file);
}

//Task 2. Написать рекурсивную функцию обхода графа в глубину.
int depthSearch (GraphNode* start,GraphNode* goal)
{
    //int check [64]={0};

        start->used =1;
        GraphNode* current = popQ(q);
		if (current->index == goal->index)
			return 1;
        GraphNode* child = popS(current->children);
    //int i;
   // for (i=0; i<GraphNode*size; i++)
        if (child->used==0 && child->next!=NULL)
        {
            pushQ(child);
            child->used=1;
          //  check [i] = 1;
            depthSearch(start,goal);
        }
        return 0;
}

//Task 3 Написать функцию обхода графа в ширину.
void push(GraphNode* value)
{
    GraphNode *tmp = (GraphNode*) malloc(sizeof(GraphNode));
    tmp->data = value;
    tmp->next = Stack.head;
    Stack.head = tmp;
    Stack.size++;
}
T popS()
{
    if (Stack.size == 0)
    {
        printf("Stack is empty");
    }
    GraphNode* next = NULL;
    GraphNode* value=next;
    value = Stack.head->value;
    next = Stack.head;
    Stack.head = Stack.head->next;
    free(next);
    Stack.size-- ;
}

int pushQ(GraphNode *value)
{
   GraphNode* temp = (GraphNode*) malloc(sizeof(GraphNode));
	if (temp == NULL)
    {
		printf("Out of memory");
		return 1;
	}
	temp->data = value;
	temp->value = q.size++;
	temp->next = q.head;
	temp->prev = NULL;
	if (q.head == NULL)
		q.tail = temp;
	else
		q.head->prev = temp;
	q.head = temp;
}

T popQ (Queue*q)
{
    if (q->size <= 0)
    {
		printf("Stack is empty");
		return -1;
	}
	GraphNode* temp = q->tail;
	GraphNode* value=temp;
	value = q->tail;
	q->tail = q->tail->prev;
	if (q->size > 1)
		q->head->prev = NULL;
	else
		q->tail = NULL;
	free(temp);
	q->size--;
}

int widthTravers(GraphNode* start, GraphNode* goal)
{
	pushQ(start);
	start->used = 1;
	while (q.size != 0) {
		GraphNode* current = popQ(start);
		if (current->index == goal->index)
			return 1;
		while (current->children != NULL)
        {
			GraphNode* child = popS(current->children);
			if (child->used == 0)
			{
				pushQ(child);
				child->used = 1;
			}
		}
	}
	return 0;
}

int main()
{
    int size =6;
    int matrix[size][size];
    int i;
    int j;
    FILE*file;
    file=fopen("in.txt","r");
       for(i=0;i<size;i++)
            for(j=0;j<size;j++)
                fscanf(file,"%3i",&matrix[i][j]);


    Queue q;
	initList(&q);
    Stack.size = 100;
    Stack.head = NULL;

    readFromFile();//task 1
    depthSearch(0,9);//task 2
    widthTravers(0,5);//task 3

        return 0;
}




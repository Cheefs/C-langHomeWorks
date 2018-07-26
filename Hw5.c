#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#define T char
#define MaxN 100

struct TNode
{
    int value;
    struct TNode *next;
};
typedef struct TNode Node;

typedef struct NodeQueue {
	T data;
	int value;
	int index;
	struct NodeQueue* next;
	struct NodeQueue* prev;
} NodeQueue;

typedef struct  {
	NodeQueue *head;
	NodeQueue *tail;
	int size;
	int maxSize;
} List;

struct Stack
{
    Node *head;
    int size;
    int maxSize;
};
struct Stack Stack;
struct Stack Copy;

void push(T value)
{
    if (Stack.size >= Stack.maxSize)
    {
        printf("Error stack size");
            return;
    }
    Node *tmp = (Node*) malloc(sizeof(Node));
    tmp->value = value;
    tmp->next = Stack.head;
    Stack.head = tmp;
    Stack.size++;
}

T pop()
{
    if (Stack.size == 0)
    {
        printf("Stack is empty");
    }

    Node* next = NULL;

    T value;
    value = Stack.head->value;
    next = Stack.head;
    Stack.head = Stack.head->next;
    free(next);
    Stack.size-- ;
return value;
}

void PrintStack(struct Stack Stack)
{
    Node *current = Stack.head;
    while(current != NULL)
    {
        printf("%c ", current->value);
        current = current->next;
    }
}

// Binary Task 1
void toBin(int num)
{
	int temp = num;
	while (num > 0)
    {
		(num % 2) ? push('1'): push('0');
		num /= 2;
	}
}
//bracket sequence Task 2
void bracketSequence()
{
    char open[]={'(','{','['};
    char close[]={')','}',']'};
    char BrtSqnc[]={'(',')','{','}','[',']'};
    int count=0;
    int i;


 for (i=0;i<5;i++)
 {
     if(BrtSqnc[i]=='(' || BrtSqnc[i]=='['|| BrtSqnc[i]=='{')
     {
            push(i); // count++;
     }

     else
     {
         pop(); // count--;
     }
 }
if(Stack.head!=NULL)printf("bracket sequence correct");
 //if (count>=0) printf(" correct");
 else printf("bracket sequence Wrong");

}

// Copy List Task 3
void copyList (struct Stack Copy)
{
    Node *current = Stack.head;
    while(current != NULL)
    {
        Copy.head->value=current->value;
        Copy.head->next=current->next;
        current=current->next;
        printf("%c ", Copy.head->value);
    }
}
//Queue Task 4
void initList (List* list) {
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
}

void enqueue(List* l, T value)
{
   NodeQueue* temp = (NodeQueue *) malloc(sizeof(NodeQueue));
	if (temp == NULL) {
		printf("Out of memory");
		return;
	}
	temp->data = value;
	temp->index = l->size++;
	temp->next = l->head;
	temp->prev = NULL;
	if (l->head == NULL)
		l->tail = temp;
	else
		l->head->prev = temp;
	l->head = temp;
}

T dequeue (List *l) {
if (l->size <= 0) {
		printf("Stack is empty");
		return -1;
	}
	NodeQueue* temp = l->tail;
	T value = l->tail->data;
	l->tail = l->tail->prev;
	if (l->size > 1)
		l->head->prev = NULL;
	else
		l->tail = NULL;
	free(temp);
	l->size--;
	return value;
}

int main ()
{
      List list;
	initList(&list);
    char *copy[MaxN];
    Stack.maxSize = 100;
    Stack.head = NULL;
     list.maxSize = 100;
   list.head = NULL;

    push('a');
    push('b');
    push('c');
    PrintStack(Stack);

    while (Stack.size> 0) pop();
    printf("\n");

    toBin(33);
	PrintStack(Stack);
	printf("\nThis is A Copy of Stack List: ");
    copyList(Stack);
     printf("\n");

     enqueue(&list,'a');
     enqueue(&list,'b');
     enqueue(&list,'c');
     enqueue(&list,'d');
     enqueue(&list,'f');

     printf("\nQueue: ");
	while (list.size > 0)
		printf("%c ", dequeue(&list));
		printf("\n");

		bracketSequence();
		printf("\n");

    return 0;
}

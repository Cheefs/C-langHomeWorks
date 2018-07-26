#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

//Task 1  Реализовать простейшую хеш-функцию. На вход функции подаётся строка, на выходе сумма кодов символов.
void HashTask1()
{
    int total = 0;
    int single=0;
    char* str="Task #1 Hash";
        printf(" %s ", str);
         printf("\n Single Elemets code: ");
    while (*str != NULL)
    {
        single=*str;// просто проверка кодов отдельных элементов
        total+= *str;
        str++;
        printf("\t%d",single);
    }
    printf("\n Total: ");
    printf("%d\n",total);
}


//          Task 2 Переписать программу, реализующее двоичное дерево поиска.
//     а) Добавить в него обход дерева различными способами;
//     б) Реализовать поиск в двоичном дереве поиска;
//     в) *Добавить в программу указания из какого файла считывать данные, каким образом обходить дерево.

typedef int T;
typedef struct Node {
T data;
struct Node *left;
struct Node *right;
struct Node *parent;
} Node;

void printTree(Node *root)
{
    if (root)
    {
          printf("%d",root->data);
        if (root->left || root->right)
        {
                printf("(");
            if (root->left)
                printTree(root->left);
            else printf("NULL");
                printf(",");
            if (root->right)
                printTree(root->right);
            else
                printf("NULL");
                printf(")");
        }
    }
}

Node *getFreeNode(T value, Node*parent)
{
    Node*tmp=(Node*)malloc(sizeof(Node));
    tmp->left = tmp->right = NULL;
    tmp->data = value;
    tmp->parent = parent;
    return tmp;
}
void insert(Node **head, int value)
{
    Node *tmp = NULL;
    if (*head == NULL)
    {
        *head = getFreeNode(value, NULL);
        return;
    }
    tmp = *head;
    while (tmp)
    {
        if (value> tmp->data)
        {
            if (tmp->right)
            {
                tmp = tmp->right;
                continue;
            }
            else
            {
                tmp->right = getFreeNode(value, tmp);
                return;
            }
        }
        else if(value<tmp->data)
        {
            if(tmp->left)
            {
                tmp=tmp->left;
                continue;
            }
            else
            {
                tmp->left = getFreeNode(value, tmp);
                return;
            }
        }
        else exit(2);
    }
}
void preOrderTravers(Node* root) //обход в прямом порядке
{
    if (root)
    {
        printf("%d ", root->data);
        preOrderTravers(root->left);
        preOrderTravers(root->right);
    }
}

void symmetricTravers(Node*root)
{
    if (root)
    {
      symmetricTravers(root->left);
      printf("%d ", root->data);
      symmetricTravers(root->right);
    }
}

void reverseTravers(Node*root)
{
    if(root)
    {
      reverseTravers(root->left);
      reverseTravers(root->right);
      printf("%d ", root->data);
    }
}
int search (Node* root, T value)
{
    while (root)
    {
        if (root->data<=value) result = root->left;
        else if (root->data>=value) result = root->right;
        else return root;
    }
    return result;
}

int main()
{
    //Task 1
   HashTask1();

    //Task 2
    Node *Tree = NULL;
    FILE* file = fopen("data.txt", "r");
    FILE* fileMethod = fopen("method.txt", "r");
    if (file == NULL)
    {
        puts("Can't open file!");
        exit(1);
    }
    int count;
    int method;

    fscanf(file, "%d", &count);
    fscanf(fileMethod, "%d", &method);
        fclose(fileMethod);

    int i;

    for(i = 0; i < count; i++)
    {
        if (i<=count)
        {
            int value;
            fscanf(file, "%d", &value);
            insert(&Tree, value);
        }
    }

    fclose(file);
    printTree(Tree);
    if (method==1)
    {
        printf("\nPreOrderTravers:\t");
        preOrderTravers(Tree);
    }
    else if (method==2)
    {
      printf("\nReverseTravers:\t\t");
      reverseTravers(Tree);
    }
    else if (method==3)
    {
      printf("\nSymmetricTravers:\t");
      symmetricTravers(Tree);
    }
    else
    {
        printf("\nPreOrderTravers:\t");
            preOrderTravers(Tree);
        printf("\nReverseTravers:\t\t");
            reverseTravers(Tree);
        printf("\nSymmetricTravers:\t");
            symmetricTravers(Tree);
    }
   search(Tree, 8);
    return 0;
}

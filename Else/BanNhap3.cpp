#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

#define Maxlength 100
typedef int ElementType; 

typedef struct{
    ElementType Data[Maxlength];
    int Top;
}Stack;

typedef struct Node{
    ElementType Data;
    struct Node* Next;
}Node;

typedef Node* Positiion;

typedef struct{
    Positiion Front, Rear;
}Queue;

void makenullQueue(Queue *pQ){
    Positiion T = (struct Node*)malloc(sizeof(Node));
    T->Next = NULL;
    pQ->Front = T;
    pQ->Rear = T;
}

int emptyQueue(Queue Q){
    return Q.Front == Q.Rear;
}

ElementType front(Queue Q){
    return Q.Front->Next->Data;
}

void enQueue(ElementType x, Queue *pQ){
    pQ->Rear->Next = (struct Node*)malloc(sizeof(Node));
    pQ->Rear = pQ->Rear->Next;
    pQ->Rear->Data = x;
    pQ->Rear->Next = NULL;
}

void deQueue(Queue *pQ){
    if (!emptyQueue(*pQ)){
        Positiion T = pQ->Front;
        pQ->Front = pQ->Front->Next;
        free(T);
    }
}

//----------------------------------------- 
void makenullStack(Stack *pS){
    pS->Top = Maxlength;
}

int emptyStack(Stack S){
    return S.Top == 0;
}

ElementType top(Stack S){
    return S.Data[S.Top];
}

void pop(Stack *pS){
    if(!emptyStack(*pS))
        pS->Top ++;
}

void push(ElementType x, Stack *pS){
    if (pS->Top != 0){
        pS->Top --;
        pS->Top[pS->Data] = x;
    }
}

void Palindrome(char s[], int *flag){
    Stack S;
    makenullStack(&S);
    Queue Q;
    makenullQueue(&Q);
    int i;
    for (i = 0; i < strlen(s); i++){
        push(s[i], &S);
        enQueue(s[i], &Q);
    }
    while (!emptyQueue(Q)){
        if (top(S) != front(Q)){
            *flag = 0;
            return;
        } else {
            pop(&S);
            deQueue(&Q);
        }
    }
    // printf("\"%s\" ",s);
}

char* normalizeString(char *str,char *result) {
    int pos = 0;
 
     /*Tìm độ dài chuỗi ban đầu*/
    for (int i = 0; i < strlen(str); i++) {
        char c = str[i];

      
        if (c == '\r' || c == '\n' || c == ' ') 
            continue;
        else if (c >= 'A' && c <= 'Z')
            c += 32;

      
        if (c >= 'a' && c <= 'z')
            result[pos++] = c;
    }
    return result;
}

//=================================
int main (){
    char s[500];
    int flag = 1,i;
    fgets(s, sizeof(s), stdin);
    if (s[strlen(s)-1] == '\n')
        s[strlen(s)-1] = '\0';
    
    char re[strlen(s)];
    normalizeString(s,re);
    
    // free(s);
    Palindrome(re, &flag);

    printf("\"");
    for (i =0; i < strlen(s); i++)
        printf("%c", s[i]);
    printf("\" ");
    (flag) ? printf("doc xuoi va doc nguoc nhu nhau")
           : printf("doc xuoi khac doc nguoc");
    return 0; 
}
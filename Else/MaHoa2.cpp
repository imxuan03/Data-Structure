#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxLength 100
typedef char ElementType;
typedef struct{
	ElementType Elements[MaxLength];
	int Front, Rear;
}Queue;
//=========================================
void makenullQueue(Queue *pQ){ //O(1)
	pQ->Front = -1;
	pQ->Rear = -1;
}
int emptyQueue(Queue Q){ //O(1)
	return Q.Front == -1;
}
int fullQueue(Queue Q){
	return (Q.Front == 0 && Q.Rear == MaxLength-1);
}

void deQueue(Queue *pQ){
	if(!emptyQueue(*pQ))
    {
		pQ->Front ++;
		if(pQ->Front > pQ->Rear)
			makenullQueue(pQ);		
	}
}
void enQueue(ElementType x, Queue *pQ){ //O(n)
	if(!fullQueue(*pQ))
	{
		if(emptyQueue(*pQ)) //Queue rong
			pQ->Front = 0;
		else if(pQ->Rear == MaxLength -1){
			//tinh huong, Queue bi tran
			for(int i = pQ->Front; i<= pQ->Rear; i++){
				//di chuyen phan tu tai chi so i ve chi so i- front
				pQ->Elements[i-pQ->Front]=pQ->Elements[i];
			}
			pQ->Rear = pQ->Rear - pQ->Front;
			pQ->Front = 0;
		}
		pQ->Rear ++;
		pQ->Elements[pQ->Rear] = x ;		
	}
}

//============================================================================

#define Max_length 100
typedef char ElementType;

typedef struct {
	ElementType elements[Max_length];
	int Top_inx; //giu vi tri dinh ngan xep
}Stack;

void makenullStack(Stack* pS) {
	pS->Top_inx = Max_length;
}
int emptyStack(Stack S) {
	return S.Top_inx == Max_length;
}
int full(Stack S) {
	return S.Top_inx == 0;
}
void push(ElementType x, Stack* pS) {
	if (!full(*pS)) {
		pS->elements[pS->Top_inx - 1] = x;
		pS->Top_inx--;
	}
	else
		printf("Stack day, khong the them\n");

}
void pop(Stack* pS) {
	if (!emptyStack(*pS)) {
		pS->Top_inx++;
	}
	else {
		printf("Danh sach rong , khong co gia tri\n");
	}
}


//=====================================================================
int main(){

    char s[500];
    fgets(s, sizeof(s), stdin);
    //xoa enter
    if(s[strlen(s)-1]=='\n')
        s[strlen(s)-1]='\0';

    
    Stack S;
    makenullStack(&S);
    Queue Q;
    makenullQueue(&Q);

    for(int i = 0;i<strlen(s);i++){
        push(s[i],&S);
        enQueue(s[i],&Q);
    }
    int flag =1;

    while(!emptyQueue(Q)){
        char m = S.elements[S.Top_inx];
        if( (m<'a'|| m>'z') && (m<'A' || m>'Z')){
            pop(&S);
            m = S.elements[S.Top_inx];
             continue;
        }
        char n = Q.Elements[Q.Front];
        if( (n<'a'|| n>'z') && (n<'A'|| n>'Z')){
            deQueue(&Q);
            n = Q.Elements[Q.Front];
             continue;
        }
        //chuyen tat ca cac chu thanh chu viet thuong het
        if(m>='A'&&m<='Z')
            m+=32;

        if(n>='A'&&n<='Z')
            n+=32;
        //=======================
        if(m==n){
            deQueue(&Q);
            pop(&S);
            flag=1;
        }else{
            printf("\"%s\" doc xuoi khac doc nguoc",s);
            flag =0;
            break;
        }

    }
    if(flag==1)
        printf("\"%s\" doc xuoi va doc nguoc nhu nhau", s);

    return 0;
}
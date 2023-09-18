#include <stdio.h>
#include <stdlib.h>

#define MaxLength 100
typedef int ElementType;
typedef struct{
	ElementType Elements[MaxLength];
	int Front, Rear;
}Queue;

//=========================================
void makenullQueue(Queue *pQ){ //O(1)
	pQ->Front = -1;
	pQ->Rear = -1;
}
Queue makenullQueue(){ //O(1)
	Queue Q;
	Q.Front = -1;
	Q.Rear = -1;
	return Q;
}
int emptyQueue(Queue Q){ //O(1)
	return Q.Front == -1;
}
int fullQueue(Queue Q){
	/*
		vd:
		16 - 0 + 1 = 17
		1 - 2 + 1 = 0
	*/
	return (Q.Rear - Q.Front +1) % MaxLength == 0;
}

ElementType front(Queue Q){
	if(!emptyQueue(Q))
		return Q.Elements[Q.Front];
	else
		printf("Queue is emptied\n");
}
void deQueue(Queue *pQ){
	if(emptyQueue(*pQ))
		printf("Queue is emptied, can't delete it\n");
	else{
		if(pQ->Front==pQ->Rear)
			makenullQueue(pQ);
		else
			pQ->Front = (pQ->Front+1)%MaxLength;	
	}
}

void enQueue(ElementType x, Queue *pQ){ //O(n)
	if(fullQueue(*pQ))
		printf("Queue is fulled\n");
	else{
		if(emptyQueue(*pQ))
			pQ->Front = 0;
		
		pQ->Rear = (pQ->Rear+1)%MaxLength;
		pQ->Elements[pQ->Rear] = x ;		
	}
}
int main()
{
	
	return 0;
}



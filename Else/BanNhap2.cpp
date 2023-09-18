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

int emptyQueue(Queue Q){ //O(1)
	return Q.Front == -1;
}
int fullQueue(Queue Q){
	return (Q.Front == 0 && Q.Rear == MaxLength-1);
}
void deQueue(Queue *pQ){
	if(emptyQueue(*pQ))
		printf("Queue is emptied, can't delete it\n");
	else{
		pQ->Front ++;
		if(pQ->Front > pQ->Rear)
			makenullQueue(pQ);		
	}
}
void deQueue2(Queue *pQ){
	if(pQ->Front == -1)
		printf("Queue is emptied, can't delete it\n");
	else{
		pQ->Front ++;
		if(pQ->Front > pQ->Rear){
			pQ->Front = -1;
			pQ->Rear = -1;
		}	
	}
}
void enQueue(ElementType x, Queue *pQ){ //O(n)
	if(fullQueue(*pQ))
		printf("Queue is fulled\n");
	else{
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
void read(int n,Queue *pQ){
	ElementType x;
	for(int i =0;i<n;i++){
		scanf("%d", &x);
		enQueue(x, pQ);
	}
}
int main()
{
	int n;
    scanf("%d", &n);
    Queue P;
    makenullQueue(&P);
    Queue Q;
    makenullQueue(&Q);

    //nhap thong tin vao cho 2 hang doi
    read(n, &P);
    read(n, &Q);

    int soBuoc = 0;
    while(!emptyQueue(P)){
        soBuoc ++;
        if(P.Elements[P.Front]!=Q.Elements[Q.Front]){
            //them vao cuoi
            enQueue(P.Elements[P.Front],&P);
            //xoa phan tu luc dau
            deQueue(&P);

        }else{
            deQueue(&P);
            deQueue(&Q);
        }

    }
    printf("%d", soBuoc);

	return 0;
}



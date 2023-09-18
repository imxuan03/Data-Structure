#include <stdio.h>
#include <stdlib.h>

#define MaxLength 100
typedef int ElementType;
typedef struct{
	ElementType Elements[MaxLength];
	int Front, Rear;
}Queue;

void makenullQueue(Queue *pQ);
int emptyQueue(Queue Q);
void enQueue(ElementType x, Queue *pQ);
void deQueue(Queue *pQ);
int fullQueue(Queue Q);
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
int main()
{   
    Queue Q;
    makenullQueue(&Q);

	int n;
    scanf("%d",&n);
    getchar();
    char x;
    for(int i =0;i<n;i++){
        
        scanf("%c", &x);
        getchar();
        if(x=='E'){
            //them phan tu, hien ra so luong phan tu
            int m;
            scanf("%d", &m);
            getchar();
            enQueue(m, &Q);
            printf("%d\n", Q.Rear-Q.Front+1);
        }else{
            if(!emptyQueue(Q)){
                printf("%d ",Q.Elements[Q.Front]);
                deQueue(&Q);
                if(emptyQueue(Q))
                    printf("0\n");
                else
                    printf("%d\n", Q.Rear-Q.Front+1);
            }else{
                printf("-1 0\n");
            }
            
        }

    }

	return 0;
}



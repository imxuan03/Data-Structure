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

int main(){

    char s[500];
    char maHoa[20];

    fgets(s,sizeof(s), stdin);
    if(s[strlen(s)-1]=='\n'){
        s[strlen(s)-1]='\0';
    }
    fgets(maHoa, sizeof(maHoa), stdin);
    if(maHoa[strlen(maHoa)-1]=='\n'){
        maHoa[strlen(maHoa)-1]='\0';
    }

    //cho tung ki tu cua maHoa vao ben trong Hang Doi
    Queue Q;
    makenullQueue(&Q);
    size_t doDaiMaHoa = strlen(maHoa);
    for(int i =0;i<doDaiMaHoa;i++){
        enQueue(maHoa[i],&Q);
    }
    

    size_t len = strlen(s);
    for(int i =0;i<len;i++){
        s[i]+= Q.Elements[Q.Front] -48 ;
        enQueue(Q.Elements[Q.Front],&Q);
        deQueue(&Q);
    }
    for(int i =0;i<len;i++){
        printf("%c",s[i]);
    }
    


    return 0;
}
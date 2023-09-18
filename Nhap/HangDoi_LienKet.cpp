#include <stdio.h>
#include <stdlib.h>
 
typedef int ElementType;
struct Node{
	ElementType Element;
	struct Node *Next;
};
typedef struct Node* Position;
typedef struct {
	Position Front, Rear;
}Queue;
void makenullQueue(Queue *pQ){
	Position Header = (struct Node*)malloc(sizeof(struct Node));
	Header->Next = NULL;
	pQ->Front = Header;
	pQ->Rear = Header;	
}
int emptyQueue(Queue Q){ //O(1)
	return Q.Front == Q.Rear; 
	
}
ElementType front(Queue Q){
	if(!emptyQueue(Q))
		return Q.Front->Next->Element;
	else
		printf("Queue is emptied");
}
void enQueue(ElementType x, Queue *pQ){
	pQ->Rear->Next = (struct Node*)malloc(sizeof(struct Node));//Position = struct Node*
	pQ->Rear = pQ->Rear->Next;
	pQ->Rear->Next->Element = x;
	pQ->Rear->Next = NULL;
}
void deQueue(Queue *pQ){
	//xoa o header ==> o 1 se tro thanh header
	if(!emptyQueue(*pQ)){
		Position temp = pQ->Front;
		pQ->Front = pQ->Front->Next;
		free(temp);
		
	}else
		printf("Queue is emptied, can't delete");
	
}
int main()
{
	

	return 0;
}



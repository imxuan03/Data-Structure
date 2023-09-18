#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
struct Node {
	ElementType Element;
	struct Node* Next;
};
typedef struct Node* Position;// dia chi cua position ,kieu du lieu Node
typedef Position List;//dia chi cua phan tu dau tien cua Node==>Node* List

void append(ElementType x, List *pL){
	Position P = endList(*pL);
	Position T;
	T = (struct Node*)malloc(sizeof(struct Node));
	 
	//them sau phan tu cuoi cung
	T->Element = x;
	P->Next = T;
	T->Next =NULL;
	
}

void makenullList(List* pL) {
	//List *pL = Node* *pL
	(*pL) = (struct Node*)malloc(sizeof(struct Node));
	(*pL)->Next = NULL;
}
int emptyList(List L) {
	//List L = Node* L
	return L->Next == NULL;
	//khong co ham fullList (khong co Max_lenght), vi la con tro
}
ElementType retrieve(Position P, List L) {
	//Position P = Node *P,List L = Node *L
	//    P voi P->Next
	//P se luu dia chi cua P->Next, P se luu gia tri cua Node truoc P
	return P->Next->Element;
}
void insertList(ElementType x, Position P, List* pL) {
	//chen vao thoi, va noi cac Node lai voi nhau, dia chi khong thay doi
	Position T;//Node *T;
	T = (struct Node*)malloc(sizeof(struct Node));

	T->Element = x;
	T->Next = P->Next;
	P->Next = T;
}
void deleteList(Position P, List* pL) {
	Position Temp;

	if (P->Next != NULL) {
		Temp = P->Next;
		P->Next = Temp->Next;

		free(Temp);
	}
}
Position first(List L) {
	return L;
}
Position endList(List L) { //O(n)
	//tra ve vi tri sau phan tu cuoi cung
	List P = L;
	while (P->Next != NULL) {
		P = P->Next;
	}
	return P;
}
Position Next(Position P, List L) {
	return P->Next;
}
Position previous(Position P, List L) {
	Position Q = L;

	while (Q->Next != P) {
		Q = Q->Next;
	}
	return Q;
}
Position locate(ElementType x, List L) {
	Position P = L;
	Position E = endList(L);
	while (P != E) {
		if (retrieve(P, L) == x) {
			return P;
		}
		else
		{
			P = Next(P, L);
		}
	}
	return P;
}

//Position locate(ElementType x, List L) {
//	Position P = L;
//	while (P->Next != NULL) {
//		if (P->Next->Element  == x) {
//			break;
//		}
//		else
//		{
//			P = P->Next;
//		}
//	}
//	return P;
//}

void printList(List L) {
	Position P = first(L);
	Position E = endList(L);
	while (P != E) {
		printf("%d ",retrieve(P, L));
		P = Next(P, L);
	}
	printf("\n");
}

//void printList(List L) {
//	Position P = L;
//	while (P->Next != NULL) {
//		printf("%d ",P->Next->Element);
//		P = P->Next;
//	}
//	printf("\n");
//}

void readList(List* pL) {

	ElementType x;
	makenullList(pL);
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		insertList(x, endList(*pL), pL);

	}
}
int member(ElementType x, List L){
	Position P = L;
	
	while(P->Next!=NULL){
		if(P->Next->Element==x)
			return 1;
		
		P=P->Next;
	}
	return 0;
}

//them vao dau danh sach
void addFirst(ElementType x,List *pL){
	Position P = *pL;//vi tri dau tien
	
	Position T = (struct Node*)malloc(sizeof(struct Node));
	T->Element = x;
	T->Next=P->Next;
	P->Next=T;
}

//cho phep nhap tat ca cac phan tu khong trung nhau
void readSet(List *pL){
	makenullList(pL);
	
	int n;
	scanf("%d", &n);
	ElementType x;
	for(int i =0;i<n;i++){
		scanf("%d", &x);
		if(!member(x,*pL))
			addFirst(x,pL);
	}
}
//hop 2 List lai
List  unionSet(List L1, List L2){
	List L;
	makenullList(&L);
	
	Position P = L1;
	while(P->Next !=NULL){
		append(P->Next->Element,&L);
		
		P=P->Next;
	}
	
	Position Q = L2;
	while(Q->Next!=NULL){
		if(!member(Q->Next->Element,L1))
			append(Q->Next->Element,&L);
			
		Q=Q->Next;
	}
	
	return L;
}
//==================================================
int main() {
	List L;
	makenullList(&L);
	printf("%d ", L->Next);

	
	return 0;
}
//==================================================

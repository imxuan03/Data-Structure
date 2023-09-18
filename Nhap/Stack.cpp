#include <stdio.h>
#include <stdlib.h>


#define Max_length 100
typedef int ElementType;

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
ElementType top(Stack S) {
	if (emptyStack(S)) {
		printf("Stack rong, khong the hien thi gia tri phan tu o dinh\n");
	}
	else
		return S.elements[S.Top_inx];
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
void printBinary(int n) {
	Stack S;
	makenullStack(&S);
	while (n != 0) {
		push(n % 2, &S);
		n /= 2;
	}
	while (!emptyStack(S)) {
		printf("%d",top(S));
		pop(&S);
	}

}
void read(Stack *pS){
	makenullStack(pS);
	int n;
	printf("nhap so phan tu : ");
	scanf("%d", &n);
	ElementType x;
	for(int i =0;i<n;i++){
		scanf("%d", &x);
		push(x, pS);
	}
	
}
void print(Stack S){
	while(!emptyStack(S)){
		printf("%d ", top(S));
		pop(&S);
	}
}

int main() {

//	int n;
//	scanf("%d", &n);
//	printBinary(n);

	Stack S;
	read(&S);
	print(S);
	return 0;
}

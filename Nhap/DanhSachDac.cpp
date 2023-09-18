#include <stdio.h>
#include <stdlib.h>
#define Max_length 100
typedef int ElementType;
typedef int Position;


struct List{
	ElementType Elements[Max_length];
	Position Last;
};


void makenullList(List* pL) {
	pL->Last = 0;
}
bool emptyList(List L) {
	return L.Last == 0;
}
bool fullList(List L) {
	return L.Last == Max_length;
}
Position first(List L) {
	return 1;
}
Position endList(List L) {
	return L.Last + 1;
}
void insertList(ElementType x, Position P, List* pL) {
	if (fullList(*pL))
		printf("Danh sach day\n");
	else if (P<first(*pL) || P>endList(*pL))
		//xet theo vi tri
		//co the dung tu vi tri 1 -> sau cuoi
		printf("Vi tri khong hop le\n");
	else {
		//hop le
		Position Q;
		for (Q = pL->Last; Q >= P; Q--) {
			//pL->Last = chi so + 1 
			pL->Elements[Q] = pL->Elements[Q - 1];
		}
		pL->Elements[P - 1] = x;
		pL->Last++;
	}
}
void deleteList(Position P, List* pL) {
	if (emptyList(*pL))
		printf("Danh sach rong khong xoa duoc\n");
	else if (P<first(*pL) || P>pL->Last) {
		printf("Vi tri khong hop le\n");
	}
	else {
		//doi phan tu
		for (Position Q = P - 1; Q < pL->Last - 1; Q++) {
			pL->Elements[Q] = pL->Elements[Q + 1];
		}
		pL->Last--;
	}

}
Position next(Position P, List L) {
	return P + 1;
}
Position previous(Position P, List L) {
	return P - 1;
}
ElementType retrieve(Position P, List L) {
	//xac dinh noi dung cua phan tu tai vi tri P
	return L.Elements[P - 1];

}
Position locate(ElementType x, List L) {
	//tra ve vi tri cua phan tu co noi dung x
	Position P = first(L);
	while (P != endList(L)) {
		if (retrieve(P, L) == x)
			break;

		P = next(P, L);
	}
	return P; //neu tim khong thay thi return ve vi tri EndList (P+1)
}

int member(ElementType x, List L) {
	//kiem tra gia tri x co trong List hay khong
	Position P = first(L);
	while (P != endList(L)) {
		if (retrieve(P, L) == x)
			return 1;

		P = next(P, L);
	}
	return 0;
}

void readList(List* pL) {
	int n;//so phan tu cua mang
	ElementType x;
	makenullList(pL);
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		insertList(x, endList(*pL), pL);
	}
}

//void readList(List* pL) {
//	int n;//so phan tu cua mang
//	cin >> n;
//	int x;
//
//	pL->Last = 0;
//	for (int i = 0; i < n; i++) {
//		cin >> x;
//		pL->Elements[i] = x;
//		pL->Last++;
//	}
//}

void printList(List L) {
	Position P = first(L);
	while (P != endList(L)) {
		printf("%d ",retrieve(P, L));
		P = next(P, L);
	}
	printf("\n");
}

void  delete_duplicate(List* pL) {
	//xoa nhung vi tri trung lap nhau

	Position p, q;
	p = first(*pL);

	while (p != endList(*pL)) {
		q = next(p, *pL);
		while (q != endList(*pL)) {
			if (retrieve(p, *pL) == retrieve(q, *pL)) {
				deleteList(q, pL);
			}
			else {
				q = next(q, *pL);
			}

		}
		p = next(p, *pL);
	}

}
int main() {
	struct List L;
	readList(&L);
	printList(L);

	//them phan tu co noi dung x vao danh sach tai vi tri P
	printf("them phan tu co noi dung x vao danh sach tai vi tri P\n");
	printf("Nhap x va P\n");
	ElementType x; scanf("%d", &x);
	Position P; scanf("%d", &P);
	insertList(x, P, &L);
	printList(L);

	//xoa phan tu dau tien co noi dung x ra khoi danh sach
	printf("nhap gia tri phan tu can xoa\n");
	ElementType k;
	scanf("%d", &k);
	deleteList(locate(k, L), &L);
	printList(L);

	//xoa phan tu trung
	delete_duplicate(&L);
	printList(L);

}




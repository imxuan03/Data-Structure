#include <bits/stdc++.h>

using namespace std;

struct Node{
    char ID[20];
    char HoTen[50];
    float GDA;
    Node *Next;
};
typedef struct Node* Position;
typedef Position List;

void makenullList(List *pL){
   (*pL) = (struct Node*)malloc(sizeof(struct Node));
    (*pL)->Next = NULL; 
}
int isEmpty(List L){
    return L->Next==NULL;
}
Position Last(List L){
    Position P = L;
    while(P->Next!=NULL){
        P=P->Next;
    }
    return P;
}
//them 1 sinh vien vao cuoi danh sach
void last_insert(List *pL){
    List T = (struct Node*)malloc(sizeof(struct Node));
    getline(cin, T->ID);
    getline(cin, T->HoTen);
    cin>>T->GDA;
    
    Position P = Last(*pL);
    P->Next = T;
    T->Next = NULL;

}
void nhap(List *pL){
    makenullList(pL);
}
int main(){
    

    return 0;
}
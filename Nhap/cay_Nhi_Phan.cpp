#include <stdio.h>
#include <stdlib.h>
typedef int DataType;
struct Node
{
    DataType Data;
    struct Node *Left, *Right;
};
typedef struct Node *Tree; // con tro , tro den nut goc

//========================
void makenullTree(Tree *pT)
{
    // struct Node* *pT
    (*pT) = NULL;
}
Tree makenullTree()
{
    Tree T;
    T = NULL;
    return T;
}
int emptyTree(Tree T)
{
    return T == NULL;
}
struct Node *leftChild(struct Node *n)
{
    if (n == NULL) // emptyTree(n)
        return NULL;
    else
        return n->Left;
}
struct Node *rightChild(struct Node *n)
{
    if (n == NULL) // emptyTree(n)
        return NULL;
    else
        return n->Right;
}
int isLeaf1(struct Node *n)
{
    return n->Left == NULL && n->Right == NULL;
}
int isLeaf(struct Node *n)
{
    return (leftChild(n)) == NULL && (rightChild(n) == NULL);
}
void preOrder(Tree T)
{
    if (T != NULL)
    {
        // NLR
        printf("%d", T->Data);
        preOrder(T->Left);
        preOrder(T->Right);
    }
}
void inOrder(Tree T)
{
    if (!emptyTree(T))
    {
        // LNR
        inOrder(T->Left);
        printf("%d", T->Data);
        inOrder(T->Right);
    }
}
void postOrder(Tree T)
{
    if (!emptyTree(T))
    {
        // LRN
        postOrder(T->Left);
        postOrder(T->Right);
        printf("%d", T->Data);
    }
}
int nb_nodes(Tree T)
{
    if (emptyTree(T))
        return 0;
    else
        return nb_nodes(leftChild(T)) + nb_nodes(rightChild(T)) + 1;
}
//dem so nut la
int nb_leaves(Tree T)
{
    if (emptyTree(T))
        return 0;
    else if (isLeaf(T))
        return 1;
    else
        return isLeaf(T->Left) + isLeaf(T->Right);
}

//dem so nut trung gian (loai tru nut la)
int inNode(Tree T)
{
    if (emptyTree(T))
        return 0;
    else if (isLeaf(T))
        return 0;
    else
        return 1 + inNode(leftChild(T)) + inNode(rightChild(T));
}

Tree create2(DataType v, Tree l, Tree r)
{
    Tree N = (struct Node *)malloc(sizeof(struct Node));
    N->Data = v;
    N->Left = l;
    N->Right = r;

    return N;
}

//viet ham tim phan tu x trong cay T, kq tra ve con tro tro den Node co
//gia tri x hoac tro den NULL
Tree findElement(DataType x, Tree T){
    if(T==NULL)
        return NULL;
    
    if(T->Data ==x)
        return T;
    
    return findElement(x, T->Left) || findElement(x, T->Right);

}
Tree findElement(DataType x, Tree T){
	if(T==NULL) return NULL;
	
	if(T->Data == x)
		return T;
	Tree L =findElement(x, T->Left);
	if(L == NULL){
		return findElement( x,  T->Right);
	}else
		return L;
		
}
int isMirrors(Tree T1,Tree T2){
	if(T1==NULL && T2==NULL)
		return 1;
	if((T1==NULL&&T2!=NULL)||(T1!=NULL&&T2==NULL)||(T1->Data!=T2->Data))
		return 0;
	
	return (T1->Data==T2->Data) && isMirrors(T1->Left,T2->Right) && isMirrors(T1->Right,T2->Left);
	
}
DataType findMax(Tree T){
	if(T == NULL) return 0;
	
	int L = findMax(T->Left);
	int R =findMax(T->Right);
	
	if(T->Data > L && T->Data > R){
		return T->Data;
	}else if(L > T->Data && L > R){
		return L;
	}else
		return R;
}
int findIndex(DataType x, char in[], int star, int end){
    int i=star;
    while (i<=end){
         if (x==in[i])
             return i;
         else
             i++;
   }
   return i;
}
int preIndex =0;
Tree createTree(char pre[], char in[], int Start, int End){
	Tree N ; N= NULL;
	if(Start <= End){
		N = (struct Node*)malloc(sizeof(struct Node));
		N->Data = pre[preIndex];
		preIndex ++;
		
		if(End == Start){
			//dat N la nut la
			N->Right =NULL;
			N->Left = NULL;
		}else{
			int  inIndex = findIndex(N->Data, in,Start,End);
			N->Left=createTree(pre, in, Start, inIndex-1);
			N->Right=createTree(pre, in, inIndex+1, End);
		}
	}
		
	return N;
	
}
// Xac dinh chieu cao
int h(Tree T){
	if (T == NULL) return 0;
	return max(h(T->Left),h(T->Right)) + 1;
}

//Tim ban kinh lon nhat cay nhi phan kieu con tro
void getDiameter(Tree T,int* diameter){
	if(T == NULL) return;
	
	int L = h(T->Left);
	int R = h(T->Right);
	getDiameter(T->Left,diameter);
	int DL = *diameter;
	getDiameter(T->Right,diameter);
	int DR = *diameter;
	*diameter = max(L+R+1, max(DL,DR));
	
}
//dem so nut co du 2 con
int getFullNodes(Tree T){
	if(T==NULL)
		return 0;
	if(T->Left!=NULL&&T->Right!=NULL)
		return 1 +  getFullNodes(T->Left)+getFullNodes(T->Right);
	else
		return getFullNodes(T->Left)+getFullNodes(T->Right);
}
// Cay phan chieu
Tree convertTree(Tree T){
	if(T == NULL) return NULL;
	else{
		Tree temp;
		
		/* do the subtrees */
		convertTree(T->Left);
		convertTree(T->Right);
		
		/* swap the pointers in this node */
		temp = T->Left;
		T->Left = T->Right;
		T->Right = temp;
	}
	return T;
}
// In noi dung cua mot mang path
void printArray(int path[], int len){
 int i;
 for(i=0;i<len;i++)
    printf("%d ",path[i]);
    printf("\n");
}

//Hien thi tat ca cac duong di
void printAllPaths(Tree T,int path[],int len,int pathlen){
	if(T == NULL) return;
	path[len] = T->Data;
	len++;
	if(T->Left == NULL && T->Right == NULL && len == pathlen + 1){
		printArray(path,len);
	}
	else{
		printAllPaths(T->Left,path,len,pathlen);
		printAllPaths(T->Right,path,len,pathlen);
	}
}
//========================
int main()
{
    //create ra mot cai cay
    Tree T1 = create2('D', NULL, NULL);
    Tree T2 = create2('C', T1 , NULL);

    Tree T3 = create2('B', NULL, NULL);
    Tree T4 = create2('E', NULL, T3);

	Tree T = create2('A', T2,T4);

    return 0;
}

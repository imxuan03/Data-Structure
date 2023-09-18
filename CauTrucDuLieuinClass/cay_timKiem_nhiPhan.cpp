#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;
struct Node
{
    KeyType Key;
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
        printf("%d", T->Key);
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
        printf("%d ", T->Key);
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
        printf("%d", T->Key);
    }
}
int nb_nodes(Tree T)
{
    if (emptyTree(T))
        return 0;
    else
        return nb_nodes(leftChild(T)) + nb_nodes(rightChild(T)) + 1;
}
int nb_leaves(Tree T)
{
    if (emptyTree(T))
        return 0;
    else if (isLeaf(T))
        return 1;
    else
        return isLeaf(T->Left) + isLeaf(T->Right);
}

int inNode(Tree T)
{
    if (emptyTree(T))
        return 0;
    else if (isLeaf(T))
        return 0;
    else
        return 1 + inNode(leftChild(T)) + inNode(rightChild(T));
}

Tree create2(KeyType v, Tree l, Tree r)
{
    Tree N = (struct Node *)malloc(sizeof(struct Node));
    N->Key = v;
    N->Left = l;
    N->Right = r;

    return N;
}

// viet ham tim phan tu x trong cay T, kq tra ve con tro tro den Node co
// gia tri x hoac tro den NULL
Tree findElement(KeyType x, Tree T)
{ // O(h)
    if (T == NULL)
        return NULL;

    if (T->Key == x)
        return T;
    else if (x < T->Key)
        return findElement(x, T->Left);
    else
        return findElement(x, T->Right);
}

// them 1 nut vao trong cay
void insertNode(KeyType x, Tree *pT)
{
    if ((*pT) == NULL)
    {
        (*pT) = (struct Node *)malloc(sizeof(struct Node));
        (*pT)->Key = x;
        (*pT)->Left = NULL;
        (*pT)->Right = NULL;
    }
    else if (x < (*pT)->Key)
        insertNode(x, &(*pT)->Left);
    else if (x > (*pT)->Key)
        insertNode(x, &(*pT)->Right);
}
Tree createTree()
{
    // tao ra 1 cay, co N khoa duoc nhap tu ban phim
    Tree T;
    makenullTree(&T);
    int n;
    scanf("%d", &n);
    KeyType x;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        insertNode(x, &T);
    }
    return T;
}
KeyType deleteMin(Tree *pT)
{
    KeyType k;
    Tree temp;
    if ((*pT)->Left == NULL)
    {
        k = (*pT)->Key;
        temp = (*pT);
        (*pT) = (*pT)->Right;
        free(temp);
        return k;
    }
    else
    {
        return deleteMin(&(*pT)->Left);
    }
}

// xoa mot KeyType x
void deleteNode(KeyType x, Tree *pT)
{
    Tree temp;
    if ((*pT) != NULL)
    {
        // kiem tra cay khac rong
        if (x < (*pT)->Key)
            deleteNode(x, &(*pT)->Left);
        else if (x > (*pT)->Key)
            deleteNode(x, &(*pT)->Right);
        else
        {
            // x==(*pT)->Key //tim thay khoa x==> co 3 truong hop
            if ((*pT)->Left == NULL && (*pT)->Right == NULL)
            {
                //*pT la nut la
                temp = (*pT);
                (*pT) = NULL;
                free(temp);
            }
            else if ((*pT)->Left == NULL)
            {
                // *pT chi co con phai
                temp = (*pT);
                (*pT) = (*pT)->Right;
                free(temp);
            }
            else if ((*pT)->Right == NULL)
            {
                //*pT chi co con trai
                temp = (*pT);
                (*pT) = (*pT)->Left;
                free(temp);
            }
            else
            {
                // nut co ca 2 con
                (*pT)->Key = deleteMin(&(*pT)->Right);
            }
        }
    }
}
Tree getParent(int x, Tree T){
	Tree P = T;
	Tree Parent = NULL;
    
    while(P!=NULL){
        if(P->Key == x)
            return Parent;
        else if(x<P->Key){
            Parent = P;
            P=P->Left;
        }else{
            Parent = P;
            P=P->Right;
        }
    }	
    return NULL;

}
Tree rightSibling(int x, Tree T){
	Tree P = T, Brother = NULL;
	while(P!=NULL){
		if(P->Key==x){
			if(P!=Brother)
				return Brother;
			else
				return NULL;
		}
		Brother = P->Right;
		if(x<P->Key){
			P=P->Left;
		}else{
			P=P->Right;
		}
		
	}
	return NULL;
}
Tree getMin(Tree T){
	if(T==NULL)
		return NULL;
	if(T->Left==NULL)
		return T;
	else
		return getMin(T->Left);
}
Tree getNext(int x, Tree T){
	Tree P = T, Ancestor = NULL;
	
	if(P==NULL)
		return NULL;
	while(P!=NULL){
	  if(P->Key == x){
		//xem cocay con ben phai khong
		if(P->Right!=NULL)
    			return getMin(P->Right);
    		else
    			return Ancestor;
    
    	}
    	if(x<P->Key){
    		Ancestor = P;
    		P=P->Left;
    	}else{
    		P= P->Right;
    	}  
	}
	
	return NULL;
}

//Chieu cao
int max(int a,int b){
    return (a > b) ? a : b;
}

int getHeight(Tree T){
    if(T == NULL) return -1;
    return max(getHeight(T->Left),getHeight(T->Right)) + 1;
}

int hNode(int x,Tree T){
    if(T == NULL) return -1;
    else if(T->Key == x) 
        return getHeight(T);
    else if(T->Key > x) 
        return hNode(x,T->Left);
    else 
        return hNode(x,T->Right);
}
Tree getMax(Tree T){
    if(T->Right==NULL)
		return T;
    else
        return getMax(T->Right);
}

Tree getPrevious(int x, Tree T){
	Tree Save = NULL;
	while(T!=NULL){
		if(x>T->Key){
			Save = T;
			T = T->Right;
		}
		else if(x<T->Key)
			T = T->Left;
		else{
			if(T->Left==NULL)
				return Save;
			else return getMax(T->Left);
		}
	}
	return NULL;
}
//========================
int main()
{
    Tree T = createTree();
    inOrder(T);
    deleteNode(3, &T);
    printf("\n");
    inOrder(T);

    return 0;
}

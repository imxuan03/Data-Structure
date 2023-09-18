#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Max_length 100
typedef char ElementType;
typedef struct
{
    ElementType elements[Max_length];
    int Top_inx; // giu vi tri dinh ngan xep
} Stack;

//=================
typedef float ElementType2;
typedef struct
{
    ElementType2 elements[Max_length];
    int Top_inx; // giu vi tri dinh ngan xep
} Stack2;
void makenullStack(Stack *pS)
{
    pS->Top_inx = Max_length;
}
int emptyStack(Stack S)
{
    return S.Top_inx == Max_length;
}
int full(Stack S)
{
    return S.Top_inx == 0;
}
ElementType top(Stack S)
{
    return S.elements[S.Top_inx];
}
void push(ElementType x, Stack *pS)
{
    if (!full(*pS))
    {
        pS->elements[pS->Top_inx - 1] = x;
        pS->Top_inx--;
    }
}
void pop(Stack *pS)
{
    if (!emptyStack(*pS))
    {
        pS->Top_inx++;
    }
}
//=======
void makenullStack2(Stack2 *pS)
{
    pS->Top_inx = Max_length;
}
int emptyStack2(Stack2 S)
{
    return S.Top_inx == Max_length;
}
int full2(Stack2 S)
{
    return S.Top_inx == 0;
}
ElementType2 top2(Stack2 S)
{
    return S.elements[S.Top_inx];
}
void push2(ElementType2 x, Stack2 *pS)
{
    if (!full2(*pS))
    {
        pS->elements[pS->Top_inx - 1] = x;
        pS->Top_inx--;
    }
}
void pop2(Stack2 *pS)
{
    if (!emptyStack2(*pS))
    {
        pS->Top_inx++;
    }
}
//============
int comp(char a, char b)
{
    if ((a == '+' || a == '-') && (b == '*' || b == '/' || b == '%'))
        return 0;
    else
        return 1;
}
int main()
{
    char s[500];

    // nhap chuoi can tinh
    fgets(s, sizeof(s), stdin);
    // xoa enter
    if (s[strlen(s) - 1] == '\n')
        s[strlen(s) - 1] = '\0';

    Stack S;
    makenullStack(&S);
    
    char BT[500];
    int k = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        // neu la toan hang
        if ((s[i] - 48) >= 0 && (s[i] - 48) <= 9)
        {
            // them vao BT
            BT[k] = s[i];
            k++;
        }
        else if (s[i] == '(')
        {
            push('(', &S);
        }
        else if (s[i] == ')')
        {
            // lap cho den khi tim duoc dau ngoac (
            while (S.elements[S.Top_inx] != '(' )
            {
                // lay toan tu ra, them vao BT, roi xoa
                BT[k] = S.elements[S.Top_inx];
                k++;
                pop(&S);
            }
            pop(&S);
            //=======================

            //=======================
        }
        else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '%')
        {
            while ((S.elements[S.Top_inx] == '+' || S.elements[S.Top_inx] == '-' || S.elements[S.Top_inx] == '*' || S.elements[S.Top_inx] == '/' || S.elements[S.Top_inx] == '%') && comp(S.elements[S.Top_inx], s[i]))
            {
                BT[k] = S.elements[S.Top_inx];
                k++;
                pop(&S);
            }

            push(s[i], &S);
        }
    }
    while (!emptyStack(S))
    {
        BT[k] = S.elements[S.Top_inx];
        k++;
        pop(&S);
    }

    for (int i = 0; i < k; i++)
    {
        printf("%c ", BT[i]);
    }

    printf("\n");

    //=====================================================
    Stack2 Q;
    makenullStack2(&Q);
    
    for(int i=0;i<k;i++){
        if( (BT[i]-48)>=1 && (BT[i]-48)<=9 ){
            float m =(float) (BT[i]-48);
            push2(m,&Q);
        }  
        else if( BT[i]=='+'|| BT[i]=='-'||BT[i]=='*'||BT[i]=='/'||BT[i]=='%'){
           float x =0;

            //do Stack nen thu tu lay ra se thay doi
            float b = (Q.elements[Q.Top_inx]);
            pop2(&Q);
           float a = (Q.elements[Q.Top_inx]);
            pop2(&Q);

            if(BT[i]=='+')
                x = (a+b);    
            else if(BT[i]=='-')  
                x = (a-b); 
            else if(BT[i]=='*')  
                x = (a*b); 
            else if(BT[i]=='/')  
                x = (a/b);
            else if(BT[i]=='%')  
                x = ((int)a) % ((int)b);

            push2(x, &Q);
        }

    }
    // float m =(float) (BT[0]-48);
   
    // push2(m,&Q);
    // printf("%f",Q.elements[Q.Top_inx] );
    printf("%.2f", Q.elements[Q.Top_inx]);


    return 0;
}
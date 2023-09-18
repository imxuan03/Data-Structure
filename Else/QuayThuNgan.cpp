#include <stdio.h>
#include <stdlib.h>

#define MaxLength 100
typedef int ElementType;
typedef struct
{
    ElementType Elements[MaxLength];
    int Front, Rear;
} Queue;

void makenullQueue(Queue *pQ);
int emptyQueue(Queue Q);
int fullQueue(Queue Q);
void enQueue(ElementType x, Queue *pQ);
void deQueue(Queue *pQ);
ElementType front(Queue Q);
//=========================================
void makenullQueue(Queue *pQ)
{ // O(1)
    pQ->Front = -1;
    pQ->Rear = -1;
}
Queue makenullQueue()
{ // O(1)
    Queue Q;
    Q.Front = -1;
    Q.Rear = -1;
    return Q;
}
int emptyQueue(Queue Q)
{ // O(1)
    return Q.Front == -1;
}
int fullQueue(Queue Q)
{
    return (Q.Front == 0 && Q.Rear == MaxLength - 1);
}
int fullQueue2(Queue Q)
{
    return (Q.Rear - Q.Front + 1) == MaxLength;
}
ElementType front(Queue Q)
{
    if (!emptyQueue(Q))
        return Q.Elements[Q.Front];
    else
        printf("Queue is emptied\n");
}
void deQueue(Queue *pQ)
{
    if (emptyQueue(*pQ))
        printf("Queue is emptied, can't delete it\n");
    else
    {
        pQ->Front++;
        if (pQ->Front > pQ->Rear)
            makenullQueue(pQ);
    }
}
void deQueue2(Queue *pQ)
{
    if (pQ->Front == -1)
        printf("Queue is emptied, can't delete it\n");
    else
    {
        pQ->Front++;
        if (pQ->Front > pQ->Rear)
        {
            pQ->Front = -1;
            pQ->Rear = -1;
        }
    }
}
void enQueue(ElementType x, Queue *pQ)
{ // O(n)
    if (fullQueue(*pQ))
        printf("Queue is fulled\n");
    else
    {
        if (emptyQueue(*pQ)) // Queue rong
            pQ->Front = 0;
        else if (pQ->Rear == MaxLength - 1)
        {
            // tinh huong, Queue bi tran
            for (int i = pQ->Front; i <= pQ->Rear; i++)
            {
                // di chuyen phan tu tai chi so i ve chi so i- front
                pQ->Elements[i - pQ->Front] = pQ->Elements[i];
            }
            pQ->Rear = pQ->Rear - pQ->Front;
            pQ->Front = 0;
        }
        pQ->Rear++;
        pQ->Elements[pQ->Rear] = x;
    }
}
void read(Queue *pQ)
{
    makenullQueue(pQ);
    printf("Nhap so phan tu : ");
    int n;
    scanf("%d", &n);
    ElementType x;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        enQueue(x, pQ);
    }
}
void print(Queue Q)
{
    while (!emptyQueue(Q))
    {
        printf("%d ", front(Q));
        deQueue(&Q);
    }
}
int main()
{
    int slKhachHang, slQuayThuNgan;
    int tgXuLyTrungBinh, tgDenTrungBinh, tgMucTieu;
    scanf("%d%d%d%d%d", &slKhachHang,&slQuayThuNgan,&tgXuLyTrungBinh
    ,&tgDenTrungBinh, &tgMucTieu);

    Queue Q;
    makenullQueue(&Q);

    //Mo tu quay 1
    for(int i =1;i<=slQuayThuNgan;i++){
        //thoi diem khach truoc di ra khoi quay
        int thoiDiemKhachDiRaKhoiQuay =0;
        
        //thoi diem den cua tung Khach Hang
        for(int j =1;j<=slKhachHang;j++){
            enQueue(i*tgDenTrungBinh,&Q);
        }

        int tongThoiGian =0;
        int timeDen = Q.Elements[Q.Front];
        deQueue(&Q);

        if(timeDen >= thoiDiemKhachDiRaKhoiQuay){
            thoiDiemKhachDiRaKhoiQuay = timeDen + tgXuLyTrungBinh;
        else
            thoiDiemKhachDiRaKhoiQuay = 

        }

    }






    return 0;
}
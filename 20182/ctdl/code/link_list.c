#include<stdio.h>

typedef struct Node{
    int data;
    struct Node *next;
    
}NODE;
NODE* first;

NODE* end(NODE* head)
{
    if (head == NULL)
        printf("Danh sach rong!");
    else
    {
        while (head ->next == NULL)
        {
            head = head ->next;
        }   
    return head;
    }
}

NODE* insert(int value, NODE* Pred )
{
    NODE* newnode;
    if (Pred == NULL)
        printf("Pred khong ton tai");
    else
    {
        newnode = (NODE*)malloc(sizeof(NODE));
        newnode ->data = value;
        newnode ->next = Pred ->next;
        Pred ->next = newnode;
        return newnode;
    }
    
}

void chenvaodau(int value, NODE* first ){
    if (first ==NULL){
        printf("Danh sach rong");
    }
    else
    {
        NODE* newnode;
        newnode = (NODE*)malloc(sizeof(NODE));
        newnode ->next = first->next;
        newnode ->data = value;
        first = newnode;
    }
}

NODE* chenvaocuoi(int value, NODE* first){
    NODE* curr = first;
    while (curr ->next != NULL)
        curr = curr ->next;
    NODE* newnode;
    newnode = (NODE*)malloc(sizeof(NODE));
    newnode ->data = value;
    newnode ->next = NULL;
    curr ->next = newnode;
    return newnode;

}

NODE* xoadau(NODE first){
    
}
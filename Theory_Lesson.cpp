#include <iostream>

struct node
{
    int data;
    node* next;
};

node* makeNode(int x){
    node* newNode = new node;
    newNode -> data = x;
    newNode -> next = NULL;
    return newNode;
}

node* findX(node* head, int x){
    node* tmp = head;
    if (head == NULL) return NULL;
    while (tmp != NULL && tmp -> data <= x)
    {
        if (tmp -> data == x) return tmp;
        tmp = tmp -> next;
    }
    return NULL;
}

int main(){
    node* head = NULL;
    return 0;
}
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
    //if (head == NULL) return NULL; // we dont need this line because this was already checked
    while (tmp != NULL && tmp -> data <= x)
    {
        if (tmp -> data == x) return tmp;
        tmp = tmp -> next;  
    }
    return NULL;
}

node* findXFixed(node* head, int x){
    node* tmp = head;
    //if (head == NULL) return NULL; // we dont need this line because this was already checked
    while (tmp != NULL && tmp -> data < x)
    {
        tmp = tmp -> next;  
    }
    if (tmp && tmp -> data == x) return tmp;    // check if tmp is a null to avoid accessing to null data
    return NULL;
}

void pushFront2(node* &head, int x){
    node* newNode = makeNode(x);
    newNode -> next = head;
    head = newNode;
}

void duyet(node* head){
    node* tmp = head;
    while (tmp != NULL)
    {
        std:: cout << tmp -> data << " ";
        tmp = tmp -> next;
    }
}

void mergeOrderedLists(node* &head1, node* &head2){
    node* tmp1 = head1;
    node* tmp2 = head2;
    node* pre = NULL;
    if (head1 == NULL)
    {
        head2 = head1;
        return;
    }
    if (head2 == NULL || (head1 == NULL && head2 == NULL)) return;
    if (head2 -> data < head1 -> data)
    {
        pushFront2(head1, head2 -> data);
        pre = tmp1;
        tmp1 = tmp1 -> next;
        tmp2 = tmp2 -> next;
    }
    while (tmp1 != NULL)
    {
        if (tmp2 -> data < tmp1 -> data)
        {
            pre -> next = tmp2;
            node* tmp = tmp2 -> next;
            tmp2 -> next = tmp1;
            tmp2 = tmp;
        }
        pre = tmp1;
        tmp1 = tmp1 -> next;
    }
    if (tmp2)
    {
        pre -> next = tmp2;
    }
}

void pushBack(node* &head, int x){
    node *tmp = head;
    node *newNode = makeNode(x);
    if (head == NULL) 
    {
        head = newNode;
        return;
    }
    while (tmp -> next != NULL)
    {
        tmp = tmp -> next;
    }
    tmp -> next = newNode;
}

int main(){
    node* head1 = NULL;
    pushBack(head1, 30);
    pushBack(head1, 50);
    pushBack(head1, 60);
    
    node* head2 = NULL;
    pushBack(head2, 10);
    pushBack(head2, 70);
    pushBack(head2, 150);

    mergeOrderedLists(head1, head2);
    duyet(head1);
    return 0;
}
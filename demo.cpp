#include <iostream>
using namespace std;

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

void duyet(node* head){
    while (head != NULL)
    {
        cout << head -> data << " ";
        head = head -> next;
    }
}

int count(node* head){
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head -> next;
    }
    return count;
}

void pushFront(node** head, int x){     // để thay đổi vị trí của head
    node* newNode = makeNode(x);
    newNode -> next = (*head);  // dấu sao là giá trị của head, nghĩa là địa chỉ của node đầu tiên trong DSLK
    (*head) = newNode;
}

void pushFront2(node* &head, int x){
    node* newNode = makeNode(x);
    newNode -> next = head;
    head = newNode;
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

void insert(node* &head, int x, int index){
    int n = count(head);
    if (index < 0 || index > n) return;
    if (index == 0)
    {
        pushFront2(head, x);
    }
    else
    {
        node* newNode = makeNode(x);
        node* tmp = head;
        while (index > 0)
        {
            tmp = tmp -> next;
            index--;
        }
        node* tmp1 = tmp -> next;
        tmp -> next = newNode;
        newNode -> next = tmp1;
    }
}

void deleteOneX(node* &head, int x){
    if (head == NULL) return;
    if (head -> data == x)
    {
        node* tmp = head;
        head = head -> next;
        delete tmp;
        return;
    }
    node* tmp = head;
    node* pre = NULL;
    while (tmp != NULL && tmp -> data != x)
    {   
        pre = tmp;
        tmp = tmp -> next;
    }
    pre -> next = tmp -> next;
    delete tmp;
}

void deleteManyX(node* &head, int x){
    if (head == NULL) return;
    if (head -> data == x)
    {
        node* tmp = head;
        head = head -> next;
        delete tmp;
    }
    node* tmp = head;
    node* pre = NULL;
    while (tmp != NULL)
    {
        if (tmp -> data == x)
        {
            while (tmp -> data == x)
            {
                pre -> next = tmp -> next;
                node* tmp1 = tmp;
                tmp = tmp -> next;
                delete tmp1;
            }
            
        }
        pre = tmp;
        tmp = tmp -> next;
    }
}

void sort(node* head){
    for (node* i = head; i != NULL; i = i -> next)
    {
        node* minNode = i;
        for (node* j = i -> next; j != NULL; j = j -> next)
        {
            if (minNode -> data > j -> data)
            {
                minNode = j;
            }
        }
        std:: swap(minNode -> data, i -> data);
    }
}

int main(){
    node* head = NULL;
    int a[10] = {10, 4, 3, 2, 6, 7, 5, 1, 9, 8};
    for (int i = 0; i < 10; i++)
    {
        pushBack(head, a[i]);
    }
    duyet(head);
    std:: cout << "\n";
    sort(head);
    duyet(head);
    return 0;
}
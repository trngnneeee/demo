#include <iostream>
#include "header.h"
using namespace std;

int main(){
    yearLink* yearHead = NULL;
    int ctr;
    do
    {
        cout << "1. Create a new year.\n";
        cout << "0. Exit.\n";
        cout << "Your choice: ";
        cin >> ctr;
        cin.ignore();
        switch (ctr)
        {
            case 1:
                {
                    yearLink* newYear = new yearLink;
                    newYear -> next = NULL;
                    inputYear(newYear);
                    // kiểm tra xem coi data đã có từ trước chưa lưu vô link trước
                    if (yearHead == NULL) 
                    {
                        yearHead = newYear;
                        break;
                    }
                    yearLink* tmp = yearHead;
                    while (tmp -> next != NULL)
                    {
                        tmp = tmp -> next;
                    }
                    tmp -> next = newYear;
                    break;
                }
            case 2:
                {
                    cout << "Exit!\n";
                    break;
                }
        }
    } while (ctr != 0);
    
    return 0;
}
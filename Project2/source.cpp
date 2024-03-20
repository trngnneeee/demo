#include <iostream>
#include <string>
#include "header.h"
using namespace std;

void inputYear(yearLink* &newYear){
    cout << "Enter start date of year: ";
    cin >> newYear -> start;
    cout << "Enter end date of year: ";
    cin >> newYear -> end;
    int ctr;
    do
    {
        cout << "1. Continue input for semester.\n";
        cout << "0. Exit";
        cout << "Your choice: ";
        cin >> ctr;
        cin.ignore();
        switch (ctr)    
        {
            case 1:
                {
                    cout << "Enter the number of semeseter: ";
                    cin >> newYear -> semesterHead -> semesterNum;
                    newYear -> semesterHead = new SemesterArray[newYear -> semesterHead -> semesterNum];
                    inputSemester(newYear -> semesterHead, newYear -> semesterHead -> semesterNum);
                    break;
                }
            case 0:
                {
                    cout << "Exit!\n";
                    return;
                }
        }
    } while (ctr != 0);
}

void inputSemester(SemesterArray* &semesterHead, int n){
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the start date of semester " << i + 1;
        cin >> semesterHead -> start;
        cout << "Enter the end date of semester " << i + 1;
        cin >> semesterHead -> end;
        int ctr;
        do
        {
            cout << "1. Continue input for the course.\n";
            cout << "0. Exit.\n";
            cout << "Your choice: ";
            cin >> ctr;
            cin.ignore();
            switch (ctr)
            {
                case 1:
                    {
                        semesterHead -> courseHead = NULL;
                        int ctr;
                        do
                        {
                            cout << "1. Create a new course.\n";
                            cout << "0. Exit.\n";
                            cout << "Your choice: ";
                            cin >> ctr;
                            cin.ignore();
                            switch(ctr)
                            {
                                case 1:
                                    {
                                        CourseLink* newCourse = new CourseLink;
                                        newCourse -> next = NULL;
                                        inputCourse(newCourse);
                                        if (semesterHead -> courseHead == NULL)
                                        {
                                            semesterHead -> courseHead = newCourse;
                                            break;
                                        }
                                        CourseLink* tmp = semesterHead -> courseHead;
                                        while (tmp -> next != NULL)
                                        {
                                            tmp = tmp -> next;
                                        }
                                        tmp -> next = newCourse;
                                        break;
                                    }
                                case 0:
                                    {
                                        cout << "Exit!\n";
                                        break;
                                    }
                            }
                        } while (ctr != 0);
                        break;
                    }
                case 0:
                    {
                        cout << "Exit!\n";
                        return;
                    }
            }
        } while (ctr != 0);
    }
}
void inputCourse(CourseLink* &newCourse){
    cout << "Enter course's ID: ";
    getline(cin, newCourse -> courseID);
    cout << "Enter course's name: ";
    getline(cin, newCourse -> courseName);
    cout << "Enter teacher's name: ";
    getline(cin, newCourse -> teacherName);
    cout << "Enter the number of course's credit: ";
    cin >> newCourse -> numberOfCredits;
    cout << "Enter the day in week: ";
    getline(cin, newCourse -> day);
    cout << "Enter session of course: ";
    getline(cin, newCourse -> sessionAndTime);
    newCourse -> classHead = NULL;
    int ctr;
    do
    {
        cout << "1. Add new class to this course.\n";
        cout << "0. Exit.\n";
        cout << "Your choice: ";
        cin >> ctr;
        cin.ignore();
        switch(ctr)
        {
            case 1:
                {
                    classLink* newClass = new classLink;
                    newClass -> next = NULL;
                    inputClass(newClass);
                    if (newCourse -> classHead == NULL)
                    {
                        newCourse -> classHead = newClass;
                        break;
                    }
                    classLink* tmp = newCourse -> classHead;
                    while (tmp -> next != NULL)
                    {
                        tmp = tmp -> next;
                    }
                    tmp -> next = newClass;
                    break;
                }
            case 0:
                {
                    cout << "Exit!.\n";
                    return;
                }
        }
    } while (ctr != 0);
}

void inputClass(classLink* &newClass){
    cout << "Enter the name of class: ";
    getline(cin, newClass -> className);
    cout << "Enter the number of student: ";
    // read from file
}
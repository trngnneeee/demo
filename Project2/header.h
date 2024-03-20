#include <string>
using namespace std;

struct student
{
    int No;
    string studentID, firstName, lastName, gender, dateOfBirth, socialID;
    Mark studentMark;
};

struct Mark
{
    double totalMark, finalMark, midtermMark, otherMark;
};

struct yearLink
{
    int start, end;
    SemesterArray* semesterHead;
    yearLink* next;
};

struct SemesterArray
{
    int semesterNum;
    int start, end;
    CourseLink* courseHead;
};

struct classLink
{
    string className;
    student* StudentArr;
    int maxStudent;
    classLink* next;
};

struct CourseLink
{
    string courseID, courseName, teacherName;
    int numberOfCredits;
    string day, sessionAndTime;
    classLink* classHead;
    CourseLink* next;
};

// Under is for prototype of function
void inputYear(yearLink*&);
void inputSemester(SemesterArray*&, int);
void inputCourse(CourseLink* &);
void inputClass(classLink*&);



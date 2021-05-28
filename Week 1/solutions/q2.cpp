#include <iostream>

using namespace std;

struct Date
{
    int day;
    int month;
    int year;
};

// (a)
struct Student
{
    int id;
    int level;
    Date dateOfBirth;
};

// (b)
Date makeDate(int day, int month, int year);
Student makeStudent(int id, int level, Date dateOfBirth);

// (c)
void printDate(Date date);
void printStudent(Student student);

// (d)
int getDiffInYears(Date d1, Date d2);
int getAge(Student student);

int main()
{
    // (b)
    Date dateOfBirth = makeDate(9, 6, 2000);
    Student s1 = makeStudent(123456789, 2, dateOfBirth);

    // (c)
    cout << "Student s1:" << endl;
    printStudent(s1);

    // (d)
    cout << "Student s1's age: " << getAge(s1) << endl;

    return 0;
}

// (b)
Date makeDate(int day, int month, int year)
{
    Date date;

    date.day = day;
    date.month = month;
    date.year = year;

    return date;
}

Student makeStudent(int id, int level, Date dateOfBirth)
{
    Student student;

    student.id = id;
    student.level = level;
    student.dateOfBirth = dateOfBirth;

    // Alternative Way
    // Student s2 = {id, level, dateOfBirth};

    return student;
}

// (c)
void printDate(Date date)
{
    cout << date.day << "/" << date.month << "/" << date.year;
}

void printStudent(Student student)
{
    cout << "ID: " << student.id << endl;
    cout << "Level: " << student.level << endl;
    cout << "Date of birth: ";
    printDate(student.dateOfBirth);
    // Alternative Way
    // cout << student.dateOfBirth.day << "/" << student.dateOfBirth.month << "/" << student.dateOfBirth.year;
    cout << endl;
}

// (d)
int getDiffInYears(Date d1, Date d2)
{
    int years = d2.year - d1.year;

    if ((d1.month == d2.month && d2.day < d1.day) || d2.month < d1.month)
    {
        years--;
    }
    if (years < 0)
    {
        return -years;
    }
    return years;
}

int getAge(Student student)
{
    Date today = makeDate(28, 5, 2021);
    int age = getDiffInYears(student.dateOfBirth, today);
    return age;
}
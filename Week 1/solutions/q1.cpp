#include <iostream>

using namespace std;

struct Date
{
    int day;
    int month;
    int year;
};

// (c)
void printDate(Date date);

// (d)
Date makeDate(int day, int month, int year);

// (e)
int getDiffInYears(Date d1, Date d2);

int main()
{
    // (a)
    Date d1;
    d1.day = 25;
    d1.month = 1;
    d1.year = 2017;

    Date d2 = {16, 2, 2017};

    // (b)
    Date d3, d4, d5;
    cout << "Please enter a date (d3) in format (d m y): ";
    cin >> d3.day >> d3.month >> d3.year;

    cout << "Please enter a date (d4): ";
    cin >> d4.day >> d4.month >> d4.year;

    cout << "Please enter a date (d5): ";
    cin >> d5.day >> d5.month >> d5.year;

    // (c)
    cout << "Date d1: ";
    printDate(d1);
    cout << endl;

    cout << "Date d5: "; // we also output d5
    printDate(d5);
    cout << endl;

    // (d)
    Date d6 = makeDate(5, 10, 1990);

    // (e)
    int diff = getDiffInYears(d1, d6);
    cout << "d1 and d6 are " << diff << " years apart" << endl;

    return 0;
}

// (c)
void printDate(Date date)
{
    cout << date.day << "/" << date.month << "/" << date.year;
}

// (d)
Date makeDate(int day, int month, int year)
{
    Date date;

    date.day = day;
    date.month = month;
    date.year = year;

    return date;
}

int getDiffInYears(Date d1, Date d2)
{
    int years = d2.year - d1.year;

    if (
        (d1.month == d2.month && d2.day < d1.day) || // if the months are the same and the end day is less than the start day e.g. 20 jan 2020 and 15 jan 2021
        d2.month < d1.month                          // if the end month is less than the start month e.g. dec 2020 and jan 2021
    )
    {
        years--;
    }
    if (years < 0)
    {
        return -years;
    }
    return years;
}

int compareDate(Date d1, Date d2)
{
    /* 
    Logic
    -----
    - if d1's year occurs before d2's -> return -1
    - if d1's and d2's years are the same BUT d1's month comes before d2's -> return -1
    - if d1's and d2's years and months are the same BUT d1's day comes before d2's -> return -1
    - if d1's and d2's years, months and days are the same -> return 0 - Same date
    - All other cases, d1 occurs after d2
    */

    if (d1.year < d2.year) // d1's year comes before d2's e.g. 2019 vs 2020
    {
        return -1;
    }
    else
    {
        if (d1.year == d2.year) // same year
        {
            if (d1.month < d2.month) // d1's month comes before d2's e.g. mar 2020 vs oct 2020
            {
                return -1;
            }
            else
            {
                if (d1.month == d2.month) // same month
                {
                    if (d1.day < d2.day) // d1's day comes before d2's e.g. 15 mar 2020 and 20 mar 2020
                    {
                        return -1;
                    }
                    else
                    {
                        if (d1.day == d2.day) // same day
                        {
                            return 0;
                        }
                    }
                }
            }
        }
    }

    return 1;
}

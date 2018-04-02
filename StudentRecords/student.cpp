#include <iostream>
#include "student.h"

using namespace std;

Student::Student(string name, string st_year, string st_gender)
{
    full_name = name;
    year = st_year;
    gender = st_gender;
}

Student::~Student()
{

}

string Student::getFullName()
{
    return full_name;
}

string Student::getId()
{
    return id;
}

string Student::getYear()
{
    return year;
}

string Student::getGender()
{
    return gender;
}

void Student::editFullName(string new_name)
{
    full_name = new_name;
}

void Student::editId(string st_id)
{
    if (st_id.length() != 9) {
        cout << "The student id must be 9 digits long. Provide a proper id"
                " for it to change." << endl;
        return;
    }
    id = st_id;
}

void Student::editYear(string new_year)
{
    year = new_year;
}

void Student::editGender(string new_gender)
{
    gender = new_gender;
}

void Student::printStudent()
{
    cout << id
         << setw(20) << full_name
         << setw(10) << gender
         << setw(10) << year << endl;
}










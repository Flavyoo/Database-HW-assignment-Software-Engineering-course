#include <fstream>
#include "database.h"
#include "verify.h"
#include <iostream>

using namespace std;
Database::Database()
{
    vector<Student*> students;
    //students = temp;
}

Database::~Database()
{
    students.clear();
}

void Database::createStudent() {
    string first_name;
    string last_name;
    string year;
    string gender;
    cout << "Enter the student's first name: " << flush;
    cin >> first_name;
    cout << "Enter the student's last name: " << flush;
    cin >> last_name;
    string full_name = first_name + " " + last_name;

    do {
        cout << "Enter the student's year: " << flush;
        cin >> year;
    } while(checkYear(year) != 1);

    do {
        cout << "Enter the student's gender: " << flush;
        cin >> gender;
    } while(checkGender(gender) != 1);

    year[0] = toupper(year[0]);

    Student* student = new Student(full_name, year, gender);
    // check if this id, exists
    string id;
    do {
        // generate the id for the student, create new ones if found
        id = generateId();
    }while(lookForId(getAllStudents(), id) != 1);

    student->editId(id);
    cout << endl;
    cout << "Your new student has been created." << endl << endl;
    cout << "ID"
         << setw(23) << "Full Name"
         << setw(15) << "Gender"
         << setw(8) << "Year" << endl << endl;
    student->printStudent();
    addStudent(student);
    return;
}

void Database::addStudent(Student* student)
{

   students.push_back(student);
}

// call this to remove a student
void Database::inputId()
{
    string id;
    do {
        cout << "Enter an ID: " << flush;
        cin >> id;
    } while(checkId(id) != 1);

    removeStudent(id);

}

void Database::removeStudent(string id)
{

    int location = getStudent(id, 0);
    if (location != -1)
        students.erase(students.begin() + location);
    else{
        cout << "Student not found." << endl;
    }
    return;
}


int Database::getStudent(string id, int print)
{
   int location = -1;
   for (unsigned i = 0; i < students.size(); i++) {
       // student found
       if (students[i]->getId().compare(id))
           continue;
       else {
            location = i;
            if (print == 1) {
                cout << "ID"
                     << setw(23) << "Full Name"
                     << setw(15) << "Gender"
                     << setw(8) << "Year" << endl << endl;
                students[i]->printStudent();
            }
            break;
       }

   }
   if (print == 1)
       cout << "A Student with this id does not exist." << endl;
   return location;

}

void Database::editStudent(int id) {
    string first_name, last_name, year, gender;
    string invalid;
    int choice;
    bool edit_menu = true;
    while(edit_menu) {
        cout <<" EDIT STUDENT "<< endl<< endl <<endl;
        cout << "1. EDIT NAME" << endl;
        cout << "2. EDIT GENDER" << endl;
        cout << "3. EDIT YEAR" << endl;
        cout << "4. EXIT" << endl;

        cout << "Enter a choice: " << flush;
        cin >> choice;
        if (!cin.fail()) {
            switch(choice) {
            case 1:
                cout << "Enter the student's first name: " << flush;
                cin >> first_name;
                cout << "Enter the student's last name: " << flush;
                cin >> last_name;
                students[id]->editFullName(first_name + " " + last_name);
                break;
            case 2:
                do {
                    cout << "Enter the student's gender: " << flush;
                    cin >> gender;
                } while(checkGender(gender) != 1);
                students[id]->editGender(gender);
                break;
            case 3:
                do {
                    cout << "Enter the student's year: " << flush;
                    cin >> year;
                } while(checkYear(year) != 1);
                year[0] = toupper(year[0]);
                students[id]->editYear(year);
                break;
             case 4:
                edit_menu = false;
                break;
            default:
                break;
           }
        }

        else {
            cin.clear();
            cin >> invalid;
            cout << "Please Enter A Valid Input." << endl;
        }

    }
    cout << "Your new student." << endl;
    students[id]->printStudent();
    return;
}

int Database::getStudents()
{
    string year;

    do {
        cout << "Enter the year of the students you want. " << flush;
        cin >> year;
    } while(checkYear(year) != 1);
    // loop and print the students that match the year

    cout << "ID"
         << setw(23) << "Full Name"
         << setw(15) << "Gender"
         << setw(8) << "Year" << endl << endl;

    for (unsigned i = 0; i < students.size(); i++) {
        // if years are equal
        if (!students[i]->getYear().compare(year))
            students[i]->printStudent();
    }
    return 1;

}


std::vector<Student *> Database::getAllStudents()
{
    return students;
}



void Database::saveData()
{
    string file_name;
    cout << "Enter a complete path to the file you want to save to." << endl;
    cout << "Make sure the file is already created." << flush;
    cin >> file_name;
    // write with space as delimiter, read  by splitting spaces
    ofstream students_database;
    // get rid of this as different systems have different paths.
    //string base_directory = "/home/flavio/Desktop/cs410/hw2/StudentRecords/";

    students_database.open(file_name);
    if (!students_database.is_open())
        cout << "Try creating the file first and giving the full path." << endl;
    else {
        for (unsigned i = 0; i < students.size(); i++) {
               students_database << students[i]->getId()
                                 << setw(20) << students[i]->getFullName()
                                 << setw(10) << students[i]->getYear()
                                 << setw(10) << students[i]->getGender()
                                 << endl;
        }
        cout << "Data Saved!" << endl;
    }
    students_database.close();
}

void Database::loadDataFromFile()
{
    string file_name;
    cout << "Enter the file or path to file to read from. " << flush;
    cin >> file_name;

    ifstream load_data;
    load_data.open(file_name);
    string id;
    string prev_id;
    string first_name;
    string last_name;
    string year;
    string gender;
    if (load_data.is_open()) {
        while(!load_data.eof()) {
            load_data >> id;
            load_data >> first_name;
            load_data >> last_name;
            load_data >> year;
            load_data >> gender;
            Student* student = new Student(first_name + " " + last_name, year, gender);
            //student->editId(id);
            // check if the ID exists first
            int i = lookForId(getAllStudents(), id);
            if (i == 0)
                cout << "This student is already in the database" << endl;
            else {
                // add the student to the database
                student->editId(id);
                students.push_back(student);
            }
        }
        cout << "Data Loaded!" << endl;
    }
    load_data.close();
}

string Database::getId() {
    string id;
    //bool run = true;
    do {
        cout << "Enter an ID: " << flush;
        cin >> id;
        /*if (lookForId(getAllStudents(), id) == 1) {
            cout << "This id was not found in the databse." << endl;
            run = false;
            break;
        }*/
    } while(checkId(id) != 1);
    return id;
}







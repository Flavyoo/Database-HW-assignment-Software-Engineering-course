#include <iostream>
#include <database.h>
#include <verify.h>
#include <ctime>
#include <random>

using namespace std;
//int argc, char *argv[]
int checkId(string st_id){
    if (st_id.length() < 9 || st_id.length() > 9) {
        cout << "This id does not have a valid length." << endl;
        return 0;
    }
    else {
    unsigned i;
    unsigned v;
    for (i = 0; i < st_id.length(); i++) {
        v = int((char) st_id[i]);
        if (v < 48 || v > 57) {
            cout << "An id must contain only numeric characters." << endl;
            return 0;
        }
      }
    }
    return 1;
}

int checkGender(string gender) {
    string prev = gender;
    gender[0] = toupper(gender[0]);
    if (!gender.compare("Male") || !gender.compare("Female"))
        return 1;
    else {
        cout << "'" + prev + "'" + " is invalid for a gender." << endl;
        return 0;
    }
}


int checkYear(string year) {
    // add lowercase of years in YEARS
    year[0] = toupper(year[0]);
    unsigned i;
    int exists = 0;
    for (i = 0; i < 8; i++) {
        // the year equals an element in YEARS array
        if (!year.compare(YEARS[i])) {
            exists = 1;
            return exists;
        }
    }
    cout << "Provide a valid year." << endl;
    return exists;
}


string generateId() {
    string id;
    unsigned i;
    for (i = 0; i < 9; i++) {
        id += DIGITS[rand() % 10];
    }
    return id;
}

// if id exists return 0, if not return 1
int lookForId(std::vector<Student*>students, string id) {
    if (checkId(id) == 0) {
        return -1;
    }
    for (unsigned i = 0; i < students.size(); i++)
       if (students[i] != NULL)
           // if == 0 id exists, cause they are the same
           if(!students[i]->getId().compare(id))
                return 0;
    return 1;
}

void printAllStudents(std::vector<Student*> students) {
    cout << "ID"
         << setw(23) << "Full Name"
         << setw(15) << "Gender"
         << setw(8) << "Year" << endl << endl;

    for (unsigned i = 0; i < students.size(); i++) {
        // if years are equal
        students[i]->printStudent();
    }
}

void mainMenu() {
    cout <<"UMB STUDENT MANAGEMENT SYSTEM"<< endl<<endl<<endl;
    cout << "1. ADD    A STUDENT" << endl;
    cout << "2. REMOVE A STUDENT" << endl;
    cout << "3. GET    A STUDENT" << endl;
    cout << "4. EDIT   A STUDENT" << endl;
    cout << "5. GET    STUDENTS BY YEAR" << endl;
    cout << "6. GET    ALL STUDENTS" << endl;
    cout << "7. SAVE   DATABASE" << endl;
    cout << "8. LOAD   DATABASE" << endl;
    cout << "9. MAIN   MENU" << endl;
    cout << "10. EXIT" << endl << endl;
}

int main()
{
    srand(time(0));
    Database students;
    string not_valid, student_id;
    mainMenu();
    int input, student;
    bool run = true;
    while (run) {
        cout << "Choose An Option: 9 For main menu. " << flush;
        cin >> input;
        if (!cin.fail()) {
            switch(input) {
            case 1:
                // add a student
                students.createStudent();
                break;
            case 2:
                // remove a student
                students.inputId();
                break;
            case 3:
                student_id = students.getId();
                student = students.getStudent(student_id, 1);
                break;
            case 4:
                student_id = students.getId();
                student = students.getStudent(student_id, 1);
                if (student != -1)
                    students.editStudent(student);
                break;
            case 5:
                // get students by year
                students.getStudents();
                break;
            case 6:
                // print all students
                printAllStudents(students.getAllStudents());
                break;
            case 7:
                // save Data:
                students.saveData();
                break;
            case 8:
                // load from file
                students.loadDataFromFile();
                break;
            case 9:
                // main memu
                mainMenu();
                break;
            case 10:
                // exit
                run = false;
            default:
                break;
            }
        }
        else {
            cin.clear();
            cin >> not_valid;
            cout << "Please Enter A Valid Input." << endl;
        }
    }
    cout << "GOOD  BYE!" << endl;
    return 0;
}

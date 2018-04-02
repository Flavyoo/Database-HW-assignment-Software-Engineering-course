#include "student.h"
#include <vector>
#ifndef DATABASE_H
#define DATABASE_H

class Database;
class Database {
private:
    //int size;
    // arrays of pointers to store students
    std::vector<Student*> students;
public:
    // database constructor
    Database();
    // database destructor
    ~Database();
    /* add student to database, and return index
     use index as student id. When the program is
     restarted previous students woul have the same id
     as some of the ones being added.
    */

    // create a new student from user inputs and return it.
    void createStudent();
    // get id from user input, call this to remove a student
    void inputId();
    void addStudent(Student* student);
    // remove the student with the given id.
    void removeStudent(std::string id);
    // get student from the database by id
    int getStudent(std::string id, int print);
    // edit the student information
    void editStudent(int id);
    // print names, and ID's of students in each year asked for
    int getStudents();
    // get all students
    std::vector<Student*> getAllStudents();
    // save all the data in the database to the file_name
    void saveData();
    // get the id in the database
    std::string getId();
    // load data from the file_name
    void loadDataFromFile();
};

#endif // DATABASE_H

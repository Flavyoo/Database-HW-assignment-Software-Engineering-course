#include <string>

#ifndef STUDENT_H
#include <iomanip>
#define STUDENT_H
class Student;
class Student {
private:
    std::string full_name;
    // string of 9 digits
    // first char is index location
    std::string id;
    std::string year;
    std::string gender;
public:
    // constructor to build a student
    Student(std::string full_name, std::string year, std::string gender);
    // destructor
    ~Student();
    // methods to return data related to this student
    std::string getFullName();
    std::string getId();
    std::string getYear();
    std::string getGender();
    // methods to edit this student
    void editFullName(std::string new_name);
    void editId(std::string id);
    void editYear(std::string new_year);
    void editGender(std::string new_gender);
    // print all data on a student, call getStudent() first
    void printStudent();

};

#endif // STUDENT_H

#include <string>
#include "student.h"
#ifndef VERIFY_H
#define VERIFY_H
const std::string YEARS[8] = {"Freshmen", "Sophmore", "Junior", "Senior", "freshmen", "sophmore", "junior", "senior"};
const char DIGITS[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
// checks if the id is valid, returns 1 if valid
int checkId(std::string st_id);
// checks if the gender is valid, return 1 if valid.
int checkGender(std::string gender);
// checks if the year provided is valid, return 1 if valid.
int checkYear(std::string year);
// generate a new id
std::string generateId();
// check if the id already exists
int lookForId(std::vector<Student*> students, std::string id);
// print all students in the database
void printAllStudents(std::vector<Student*> students);
#endif // VERIFY_H

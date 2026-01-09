#pragma once
#include "../database.hpp"
#include "../student.h"
#include <vector>

class StudentService {
public:
    StudentService(Database& db) : database(db) {}

    void addStudent();
    void listStudents();
    void updateStudent();
    void deleteStudent();

private:
    Database& database;
};


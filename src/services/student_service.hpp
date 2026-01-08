#ifndef STUDENT_SERVICE_HPP
#define STUDENT_SERVICE_HPP

#include "database/database.hpp"
#include "../models/student.hpp"
#include <vector>

class StudentService {
public:
    StudentService(Database& db);

    void addStudent(const std::string& name,
                    const std::string& number,
                    const std::string& department);

    std::vector<Student> listStudents();

private:
    Database& database;
};

#endif

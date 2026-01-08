#include "student_service.hpp"
#include <pqxx/pqxx>

StudentService::StudentService(Database& db) : database(db) {}

void StudentService::addStudent(const std::string& name,
                                const std::string& number,
                                const std::string& department) {

    pqxx::work txn(database.getConnection());
    txn.exec(
        "INSERT INTO students (name, student_number, department) VALUES (" +
        txn.quote(name) + ", " +
        txn.quote(number) + ", " +
        txn.quote(department) + ")"
    );
    txn.commit();
}

std::vector<Student> StudentService::listStudents() {
    pqxx::work txn(database.getConnection());
    pqxx::result res = txn.exec("SELECT * FROM students");

    std::vector<Student> students;
    for (const auto& row : res) {
        Student s;
        s.id = row["id"].as<int>();
        s.name = row["name"].as<std::string>();
        s.student_number = row["student_number"].as<std::string>();
        s.department = row["department"].as<std::string>();
        students.push_back(s);
    }
    return students;
}

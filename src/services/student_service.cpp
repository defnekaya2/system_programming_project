#include "services/student_service.hpp"
#include <iostream>

void StudentService::addStudent() {
    Student s;
    std::cout << "ID: "; std::cin >> s.id;
    std::cin.ignore();
    std::cout << "Name: "; std::getline(std::cin, s.name);
    std::cout << "Surname: "; std::getline(std::cin, s.surname);
    std::cout << "Department: "; std::getline(std::cin, s.department);
    std::cout << "Email: "; std::getline(std::cin, s.email);

    database.insertStudent(s);
}

void StudentService::listStudents() {
    auto students = database.getStudents();
    for (auto& s : students) {
        std::cout << s.id << " | " << s.name << " | " << s.surname
                  << " | " << s.department << " | " << s.email << "\n";
    }
}

void StudentService::updateStudent() {
    int id;
    std::string email;
    std::cout << "Student ID to update: "; std::cin >> id;
    std::cin.ignore();
    std::cout << "New email: "; std::getline(std::cin, email);
    database.updateStudent(id, email);
}

void StudentService::deleteStudent() {
    int id;
    std::cout << "Student ID to delete: "; std::cin >> id;
    database.deleteStudent(id);
}


#include "database/database.hpp"
#include "services/student_service.hpp"
#include <iostream>

int main() {
    Database db;
    db.connect();

    StudentService service(db);

    service.addStudent("Defne Kaya", "2023123", "CSE");

    auto students = service.listStudents();
    for (const auto& s : students) {
        std::cout << s.id << " "
                  << s.name << " "
                  << s.student_number << " "
                  << s.department << "\n";
    }

    return 0;
}




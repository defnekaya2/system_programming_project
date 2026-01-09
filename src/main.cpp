#include <iostream>
#include "database.hpp"
#include "services/student_service.hpp"

int main() {
    Database db;
    if (!db.connect("db", "student_information", "zuleyha", "zuleyha1")) {
        std::cerr << "Database connection failed\n";
        return 1;
    }

    StudentService service(db);
    int choice;

    do {
        std::cout << "\n--- Student Information System ---\n";
        std::cout << "1. Add student\n";
        std::cout << "2. List students\n";
        std::cout << "3. Update student\n";
        std::cout << "4. Delete student\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: service.addStudent(); break;
            case 2: service.listStudents(); break;
            case 3: service.updateStudent(); break;
            case 4: service.deleteStudent(); break;
            case 5: std::cout << "Exiting...\n"; break;
            default: std::cout << "Invalid option.\n"; break;
        }
    } while (choice != 5);

    return 0;
}


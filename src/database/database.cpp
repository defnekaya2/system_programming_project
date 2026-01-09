#include "database.hpp"
#include <iostream>

Database::Database() {
    conn = nullptr;
}

void Database::connect() {
    try {
        conn = new pqxx::connection(
            "host=db "
            "dbname=student_information "
            "user=zuleyha "
            "password=zuleyha1"
        );

        if (conn->is_open()) {
            std::cout << "Database connected successfully\n";
        }
    } catch (const std::exception& e) {
        std::cerr << "Database connection failed: " << e.what() << std::endl;
    }
}

void Database::addStudent(int id, const std::string& name,
                          const std::string& surname,
                          const std::string& department,
                          const std::string& email) {
    pqxx::work txn(*conn);
    txn.exec(
        "INSERT INTO students VALUES (" +
        txn.quote(id) + "," +
        txn.quote(name) + "," +
        txn.quote(surname) + "," +
        txn.quote(department) + "," +
        txn.quote(email) + ")"
    );
    txn.commit();
}

void Database::listStudents() {
    pqxx::nontransaction txn(*conn);
    pqxx::result r = txn.exec("SELECT * FROM students");

    for (auto row : r) {
        std::cout
            << row[0].c_str() << " | "
            << row[1].c_str() << " | "
            << row[2].c_str() << " | "
            << row[3].c_str() << " | "
            << row[4].c_str() << std::endl;
    }
}

void Database::updateStudent(int id, const std::string& email) {
    pqxx::work txn(*conn);
    txn.exec(
        "UPDATE students SET email=" +
        txn.quote(email) +
        " WHERE id=" + txn.quote(id)
    );
    txn.commit();
}

void Database::deleteStudent(int id) {
    pqxx::work txn(*conn);
    txn.exec(
        "DELETE FROM students WHERE id=" + txn.quote(id)
    );
    txn.commit();
}


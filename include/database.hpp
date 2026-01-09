#pragma once
#include <string>
#include <vector>
#include <memory>
#include <pqxx/pqxx>
#include <iostream>
#include "student.h"

class Database {
public:
    Database() = default;
    ~Database() = default;

    bool connect(const std::string& host,
                 const std::string& dbname,
                 const std::string& user,
                 const std::string& password)
    {
        try {
            conn = std::make_unique<pqxx::connection>(
                "host=" + host + " dbname=" + dbname + " user=" + user + " password=" + password
            );

            if (conn->is_open()) {
                std::cout << "Connected to database.\n";

                // tablo yoksa oluştur
                pqxx::work W(*conn);
                W.exec(
                    "CREATE TABLE IF NOT EXISTS students ("
                    "id INT PRIMARY KEY, "
                    "name TEXT NOT NULL, "
                    "surname TEXT NOT NULL, "
                    "department TEXT NOT NULL, "
                    "email TEXT NOT NULL);"
                );
                W.commit();
                return true;
            }
        } catch (const std::exception& e) {
            std::cerr << "Database connection failed: " << e.what() << "\n";
            return false;
        }
        return false;
    }

    void insertStudent(const Student& student) {
        try {
            pqxx::work W(*conn);
            W.exec_params(
                "INSERT INTO students (id, name, surname, department, email) VALUES ($1,$2,$3,$4,$5)",
                student.id, student.name, student.surname, student.department, student.email
            );
            W.commit();
            std::cout << "Student added.\n";
        } catch (const std::exception& e) {
            std::cerr << "Insert failed: " << e.what() << "\n";
        }
    }

    std::vector<Student> getStudents() {
        std::vector<Student> students;
        try {
            pqxx::nontransaction N(*conn);
            pqxx::result R(N.exec("SELECT id, name, surname, department, email FROM students"));
            for (auto row : R) {
                students.push_back({
                    row["id"].as<int>(),
                    row["name"].as<std::string>(),
                    row["surname"].as<std::string>(),
                    row["department"].as<std::string>(),
                    row["email"].as<std::string>()
                });
            }
        } catch (const std::exception& e) {
            std::cerr << "Select failed: " << e.what() << "\n";
        }
        return students;
    }

    void updateStudent(int id, const std::string& email) {
        try {
            pqxx::work W(*conn);
            W.exec_params("UPDATE students SET email=$1 WHERE id=$2", email, id);
            W.commit();
            std::cout << "Student updated.\n";
        } catch (const std::exception& e) {
            std::cerr << "Update failed: " << e.what() << "\n";
        }
    }

    void deleteStudent(int id) {
        try {
            pqxx::work W(*conn);
            W.exec_params("DELETE FROM students WHERE id=$1", id);
            W.commit();
            std::cout << "Student deleted.\n";
        } catch (const std::exception& e) {
            std::cerr << "Delete failed: " << e.what() << "\n";
        }
    }

private:
    std::unique_ptr<pqxx::connection> conn;
};


#include "database.hpp"
#include "config.hpp"
#include <iostream>

Database::Database() {
    std::string host = Config::getEnv("DB_HOST");
    std::string db   = Config::getEnv("DB_NAME");
    std::string user = Config::getEnv("DB_USER");
    std::string pass = Config::getEnv("DB_PASSWORD");

    connection_string =
        "host=" + host +
        " dbname=" + db +
        " user=" + user +
        " password=" + pass;
}

void Database::connect() {
    try {
        pqxx::connection c(connection_string);
        if (c.is_open()) {
            std::cout << "Database connected successfully" << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Database connection failed: " << e.what() << std::endl;
    }
}

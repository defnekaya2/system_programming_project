#include "database/database.hpp"
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
    conn = std::make_unique<pqxx::connection>(connection_string);
    if (conn->is_open()) {
        std::cout << "Database connected successfully\n";
    }
}

pqxx::connection& Database::getConnection() {
    return *conn;
}

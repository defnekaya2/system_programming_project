#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <pqxx/pqxx>
#include <memory>
#include <string>

class Database {
public:
    Database();
    void connect();
    pqxx::connection& getConnection();

private:
    std::string connection_string;
    std::unique_ptr<pqxx::connection> conn;
};

#endif

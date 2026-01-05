#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <pqxx/pqxx>
#include <string>

class Database {
public:
    Database();
    void connect();

private:
    std::string connection_string;
};

#endif

#include <iostream>
#include <unistd.h>
#include "database.hpp"

int main() {
    std::cout << "Student Information System started" << std::endl;

    Database db;
    db.connect();

    while (true) {
        sleep(5);
    }

    return 0;
}



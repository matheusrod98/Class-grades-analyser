/*
 * Author: Matheus Rodrigues de Souza.
 * DRE: 117084066
 * Programming languages (EEL660) first assignment.
 */

#include <iostream>
#include <map>
#include <string>

#include "sqlite3.h"

#include "DAO.h"

int main() {

    sqlite3 *db;
    int exit;
    exit = sqlite3_open_v2("./classes.db", &db, SQLITE_OPEN_READWRITE, NULL);
    std::cout << "Hello, world!" << std::endl;
    if (exit) {
        std::cerr << "Couldn't open the database." << std::endl;
    }

    std::string className = "Calculus IV";
    std::map<std::string, float> studentsAndGrades = {
        {"João Ribeiro", 8.5},
        {"Maria Carolina", 4.5},
        {"Larissa Santana", 9.0}
    };
    int semester = 1;

    DAO dao;
    dao.createClass(db, className, studentsAndGrades, semester);

    return 0;
}

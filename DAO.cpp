#include "sqlite3.h"

#include "DAO.h"
#include <iostream>
#include <string>

// int sqlite3_exec(sqlite3 *, const char *sql,
//                  int (*callback)(void *, int, char **, char **), void *,
//                  char **errmsg)

void DAO::createClass(sqlite3 *db,
                      std::string className,
                      std::map<std::string, float> studentsAndGrades,
                      int semester) {


    std::string studentsAndGradesString;
    for (auto const& studentAndGrade : studentsAndGrades) {
        studentsAndGradesString +=
        "(" +
        studentAndGrade.first +
        ", " +
        std::to_string(studentAndGrade.second) +
        ") ";
    }

    std::string Sql = "INSERT INTO " +
                      className +
                      " (studentName, grade)" +
                      " VALUES " +
                      studentsAndGradesString;
}

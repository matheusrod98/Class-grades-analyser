#include <map>
#include <string>

#include "sqlite3.h"

class DAO {
 public:
    void createClass(sqlite3 *db,
                     std::string className,
                     std::map<std::string, float> studentsAndGrades,
                     int semester);
};

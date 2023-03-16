#include <ctime>
#include <string>
using namespace std;

struct Product {
    string name;
    time_t productionDate;
    time_t expirationDate;
};
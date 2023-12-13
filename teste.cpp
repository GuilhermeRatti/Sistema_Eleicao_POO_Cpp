#include <iostream> // cout
#include <fstream>  // ifstream
#include <sstream>  // istringstream
#include <map>
#include "CsvReader.hpp"
#include <memory>
#include <any>
#include <exception>
#include <ctime>
#include <stdexcept>
#include <typeinfo>
#include <locale>
#include <list>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
    list<string> tokens = setHeaders();
    CsvReader csvReader(";", tokens);


}

#include <iostream> // cout
#include <fstream>  // ifstream
#include <sstream>  // istringstream
#include <map>
#include <memory>
#include <any>
#include <exception>
#include <ctime>
#include <stdexcept>
#include <typeinfo>
#include <locale>
#include <iomanip>
#include<string.h>
#include <string>

using namespace std;



int main()
{
    string separador = " ";
    string header = "the moon is blue";
    istringstream iss(header);
    string coluna;
    int index = 0;
    while (getline(iss, coluna, *separador.c_str()))
    {
        cout << coluna << endl;
    }
}

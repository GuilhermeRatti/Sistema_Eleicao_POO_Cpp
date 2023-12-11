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
    char colada[] = "the moon is blue";
    char *holder;
    holder = strtok(colada," ");
    while(holder != NULL){
        string str(holder);
        cout << str << endl;
        holder = strtok(NULL," ");
    }
    return 0;
}

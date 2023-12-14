#include <iostream> // cout
#include <sstream>  // istringstream
#include <map>
#include <memory>
#include <list>
#include <string>
#include "Eleicao.hpp"
#include "CsvReader.hpp"

using namespace std;

int main(int argc, char **argv)
{
    checaArgs(argc, argv);
    list<string> tokens = setHeaders();
    CsvReader csvReader(";", tokens);

    Eleicao eleicao = criaEleicao(argc, argv, eleicao);

    
}

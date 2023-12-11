#include <iostream> // cout
#include <fstream>  // ifstream
#include <sstream>  // istringstream
#include <map>

#include "CsvReader.hpp"

using namespace std;

CsvReader::CsvReader(const string &separador, const list<string> &colunasDeInteresse) : separador(separador)
{
    for (auto coluna : colunasDeInteresse)
    {
        this->colunas.push_back(coluna);
    }
}

void CsvReader::readHeader(const string &header)
{
    istringstream iss(header);
    string coluna;
    int index = 0;
    while (getline(iss, coluna, *separador.c_str()))
    {
        this->colunasIndexes.insert(pair<string, int>(coluna, index));
    }
}
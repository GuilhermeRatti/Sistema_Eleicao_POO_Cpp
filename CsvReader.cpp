#include <iostream> // cout
#include <fstream>  // ifstream
#include <sstream>  // istringstream
#include <string>   // getline, string
#include <string_view>
#include <map>
#include <locale>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <vector>

#include "CsvReader.hpp"

using namespace std;

string removeDoubleQuotes(const string &str)
{
    string strOut = str;
    strOut.erase(remove(strOut.begin(), strOut.end(), '\"'), strOut.end());
    return strOut;
}

const int stringToInt(const string &str)
{
    int i;
    istringstream iss(str);
    iss >> i;
    return i;
}

void checaArgs(int argc, char **argv)
{
    // if (argc < 3)
    // {
    //     cout << "Número de arugumentos inválido" << endl;
    //     exit(1);
    // }
    // else if (argv[0] != "--estadual" || argv[0] != "--federal")
    // {
    //     cout << "Tipo de cargo inválido" << endl;
    // }
}

string iso_8859_1_to_utf8(string &str)
{
    // adaptado de: https://stackoverflow.com/a/39884120 :-)
    string strOut;
    for (string::iterator it = str.begin(); it != str.end(); ++it)
    {
        uint8_t ch = *it;
        if (ch < 0x80)
        {
            // já está na faixa ASCII (bit mais significativo 0), só copiar para a saída
            strOut.push_back(ch);
        }
        else
        {
            // está na faixa ASCII-estendido, escrever 2 bytes de acordo com UTF-8
            // o primeiro byte codifica os 2 bits mais significativos do byte original (ISO-8859-1)
            strOut.push_back(0b11000000 | (ch >> 6));
            // o segundo byte codifica os 6 bits menos significativos do byte original (ISO-8859-1)
            strOut.push_back(0b10000000 | (ch & 0b00111111));
        }
    }
    return strOut;
}

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
        this->colunasIndexes.insert(pair<string, int>(removeDoubleQuotes(coluna), index));
        index++;
    }
}

const vector<string> CsvReader::split(const string &s) const
{
    vector<string> tokens = vector<string>();
    string token;
    istringstream iss(s);
    while (getline(iss, token, *separador.c_str()))
    {
        tokens.push_back(token);
    }
    return tokens;
}
void setLocaleInt()
{
    // Configura locale para imprimir números inteiros com separador de milhar e virgula decimal
    locale brLocale("pt_BR.UTF-8");
    cout.imbue(brLocale);
}

map<string, any>CsvReader::readLine(const string &line) const
{
    const vector<string> tokens = split(line);
    map<string, any>linha = map<string, any>();
    for (string coluna : colunas)
    {
        string str_quoteless = removeDoubleQuotes(tokens[colunasIndexes.at(coluna)]);

        if (coluna.rfind("CD", 0) == 0 || coluna.rfind("NR", 0) == 0 || coluna.rfind("QT", 0) == 0)
        {
            linha.insert(pair<string, any>(coluna, stringToInt(str_quoteless)));
            continue;
        }
        else
        {
            str_quoteless = iso_8859_1_to_utf8(str_quoteless);
            linha.insert(pair<string, any>(coluna, str_quoteless));
            continue;
        }
    }

    return linha;
}
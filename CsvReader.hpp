#if !defined(CSVREADER_H)
#define CSVREADER_H

#include <list>
#include <string>
#include <map>
#include <any>

using namespace std;

class CsvReader
{
    list<string> colunas;
    map<string, int> colunasIndexes;
    string separador;

    public:
        CsvReader(const string &separador, const list<string> &colunasDeInteresse);
        void readHeader(const string &header);
        const map<string, any> &readLine(const string &line) const;
        const vector<string> &split (const string &s) const;
};

#endif
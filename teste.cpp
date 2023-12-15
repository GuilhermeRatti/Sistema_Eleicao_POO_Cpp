#include <iostream> // cout
#include <fstream>  // ifstream
#include <sstream>  // istringstream
#include <map>      // map :-)
#include "Eleicao.hpp"
#include "CsvReader.hpp"
#include <any>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
    checaArgs(argc, argv);
    list<string> tokens = setHeaders();
    CsvReader csvReader(";", tokens);

    Eleicao e(ESTADUAL, "oi");

    string codigoDepStr;
    ifstream inputStream;

    int linhaAtual = 0;

    try
    {
        inputStream.open("candidatos.csv");
        string linha;
        getline(inputStream, linha); // cabeçalho
        csvReader.readHeader(linha);

        while (getline(inputStream, linha))
        {
            map<string, any> *res = csvReader.readLine(linha);
            e.registraCandidato(any_cast<int>(res->find("CD_CARGO")->second),
                                any_cast<int>(res->find("CD_SITUACAO_CANDIDATO_TOT")->second), 
                                any_cast<int>(res->find("NR_CANDIDATO")->second), 
                                any_cast<string>(res->find("NM_URNA_CANDIDATO")->second), 
                                any_cast<int>(res->find("NR_PARTIDO")->second), 
                                any_cast<string>(res->find("SG_PARTIDO")->second), 
                                any_cast<int>(res->find("NR_FEDERACAO")->second), 
                                any_cast<string>(res->find("DT_NASCIMENTO")->second), 
                                any_cast<int>(res->find("CD_SIT_TOT_TURNO")->second), 
                                any_cast<int>(res->find("CD_GENERO")->second), 
                                any_cast<string>(res->find("NM_TIPO_DESTINACAO_VOTOS")->second));
            // getline(linhaStream,nomeDepartamento,';');
            // e.createDepartamento(codigoDep,nomeDepartamento);
            linhaAtual++;
            delete res;
        }
        inputStream.close();
    }
    catch (const invalid_argument &e)
    {
        cerr << "Formato de arquivo.csv inválido. ";
        cerr << "Não foi possível ler código [" << codigoDepStr << "] do departamento na linha " << (linhaAtual + 1) << "." << endl;
        exit(1);
    }
    catch (const ifstream::failure &e)
    {
        if (!inputStream.eof())
        {
            cerr << "Não foi possível ler o arquivo departamentos.csv!" << endl;
            cerr << e.what() << endl; // só para exemplificar
            exit(1);
        }
        else
        {
            inputStream.close();
        }
    }

    e.printaRelatorio2();
}

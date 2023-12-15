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
    list<string> headers;
    headers.push_back("CD_CARGO");
    headers.push_back("CD_SITUACAO_CANDIDATO_TOT");
    headers.push_back("NR_CANDIDATO");
    headers.push_back("NM_URNA_CANDIDATO");
    headers.push_back("NR_PARTIDO");
    headers.push_back("SG_PARTIDO");
    headers.push_back("NR_FEDERACAO");
    headers.push_back("DT_NASCIMENTO");
    headers.push_back("CD_SIT_TOT_TURNO");
    headers.push_back("CD_GENERO");
    headers.push_back("NM_TIPO_DESTINACAO_VOTOS");

    CsvReader csvReaderCand(";", headers);

    Eleicao e(ESTADUAL, "oi");

    string codigoDepStr;
    ifstream inputStream;

    int linhaAtual = 0;

    try
    {
        inputStream.open("candidatos.csv");
        string linha;
        getline(inputStream, linha); // cabeçalho
        csvReaderCand.readHeader(linha);

        while (getline(inputStream, linha))
        {
            map<string, any> res = csvReaderCand.readLine(linha);
            e.registraCandidato(any_cast<int>(res.find("CD_CARGO")->second),
                                any_cast<int>(res.find("CD_SITUACAO_CANDIDATO_TOT")->second),
                                any_cast<int>(res.find("NR_CANDIDATO")->second),
                                any_cast<string>(res.find("NM_URNA_CANDIDATO")->second),
                                any_cast<int>(res.find("NR_PARTIDO")->second),
                                any_cast<string>(res.find("SG_PARTIDO")->second),
                                any_cast<int>(res.find("NR_FEDERACAO")->second),
                                any_cast<string>(res.find("DT_NASCIMENTO")->second),
                                any_cast<int>(res.find("CD_SIT_TOT_TURNO")->second),
                                any_cast<int>(res.find("CD_GENERO")->second),
                                any_cast<string>(res.find("NM_TIPO_DESTINACAO_VOTOS")->second));
            linhaAtual++;
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

    list<string> headersvot;
    headersvot.push_back("CD_CARGO");
    headersvot.push_back("NR_VOTAVEL");
    headersvot.push_back("QT_VOTOS");

    CsvReader csvReaderVot(";", headersvot);

    try
    {
        inputStream.open("votacao.csv");
        string linha;
        getline(inputStream, linha); // cabeçalho
        csvReaderVot.readHeader(linha);

        while (getline(inputStream, linha))
        {
            map<string, any> res = csvReaderVot.readLine(linha);
            e.registraVoto(any_cast<int>(res.find("CD_CARGO")->second),
                           any_cast<int>(res.find("NR_VOTAVEL")->second),
                           any_cast<int>(res.find("QT_VOTOS")->second));
            linhaAtual++;
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

}

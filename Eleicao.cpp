#include <iostream> // cout
#include <fstream>
#include <string>  // ifstream
#include <sstream> // istringstream
#include <map>

#include "Eleicao.hpp"
#include "Candidato.hpp"

using namespace std;

Eleicao criaEleicao(int argc, char **argv, Eleicao eleicao)
{
    // tipoDeCargo tipo;
    // if (argv[0] == "--estadual")
    // {
    //     tipo = ESTADUAL;
    // }
    // else
    // {
    //     tipo = FEDERAL;
    // }

    // string caminhoCand = argv[1];
    // string caminhoVotos = argv[2];
    // string dataEleicao = argv[3];
    tipoDeCargo tipo = ESTADUAL;
    string dataEleicao = "2020-11-15";

    return Eleicao(tipo, dataEleicao);
}

void Eleicao::registraCandidato(int cd_cargo, int cd_situacao_candidato_tot, int nr_candidato, string nm_urna_candidato, int nr_partido, string sg_partido, int nr_federacao, string dt_nascimento, int cd_sit_tot_turno, int cd_genero, string nm_tipo_destinacao_votos)
{
    cout << partidos.size() << endl;
    auto pt = partidos.find(nr_partido);
    Partido *p = NULL;

    if (pt == partidos.end())
    {
        Partido par = Partido(sg_partido, nr_partido);
        partidos.insert(pair<int, Partido>(nr_partido, par));
        p = &par;
    }
    else
        p = &(pt->second);

    if (!((this->tipo == ESTADUAL && cd_cargo == 7) || (this->tipo == FEDERAL && cd_cargo == 6)))
        return;

    if (!(cd_situacao_candidato_tot == 2 || cd_situacao_candidato_tot == 16) && !(nm_tipo_destinacao_votos.compare("Válido (legenda)")))
        return;

    if (cd_sit_tot_turno == 2 || cd_sit_tot_turno == 3)
        this->numeroDeVagas++;

    bool legenda;
    if (nm_tipo_destinacao_votos.compare("Válido (legenda)"))
        legenda = true;
    else
        legenda = false;

    Candidato c = Candidato(nm_urna_candidato, nr_candidato, nr_federacao, cd_genero, cd_sit_tot_turno, p, legenda);

    totalCandidatos.insert(pair<int, Candidato>(nr_candidato, c));
}

void Eleicao::registraVoto()
{
    // registraVoto implemen
}

void Eleicao::ordenaCandidatos()
{
    // ordenaCandidatos implementation
}

void ordenaPartidos()
{
    // ordenaPartidos implementation
}

void Eleicao::printaRelatorio1()
{
    cout << "Número de vagas: " << this->numeroDeVagas << endl;
}

void Eleicao::printaRelatorio2()
{
    if (this->candidatosOrdenados.empty())
    {
        this->ordenaCandidatos();
    }

    string tipoDeDeputados = "";
    if (this->tipo == ESTADUAL)
    {
        tipoDeDeputados = "estaduais";
    }
    else
    {
        tipoDeDeputados = "federais";
    }

    cout << "Deputados " << tipoDeDeputados << " eleitos:" << endl;

    // TODO: printar os deputados eleitos

    try{
        for(auto it = totalCandidatos.begin(); it != totalCandidatos.end(); it++)
        {
            cout << it->second.getNomeUrna() << " (" << it->second.getPartido()->getSigla() << ", " << it->second.getQtdVotos() << " voto)" << endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(...)
    {
        std::cerr << "Erro desconhecido" << '\n';
    }

    // cout << endl;
}

void Eleicao::printaRelatorio3()
{
    // printaRelatorio3 implementation
}

void Eleicao::printaRelatorio4()
{
    // printaRelatorio4 implementation
}

void Eleicao::printaRelatorio5()
{
    // printaRelatorio5 implementation
}

void Eleicao::printaRelatorio6()
{
    // printaRelatorio6 implementation
}

void Eleicao::printaRelatorio7()
{
    // printaRelatorio7 implementation
}

void Eleicao::printaRelatorio8()
{
    // printaRelatorio8 implementation
}

void Eleicao::printaRelatorio9()
{
    // printaRelatorio9 implementation
}

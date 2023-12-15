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
    auto pt = partidos.find(nr_partido);
    if (pt == partidos.end())
    {
        Partido par = Partido(sg_partido, nr_partido);
        partidos.insert(pair<int, Partido>(nr_partido, par));
    }

    if (!((this->tipo == ESTADUAL && cd_cargo == 7) || (this->tipo == FEDERAL && cd_cargo == 6)))
        return;

    if (!(cd_situacao_candidato_tot == 2 || cd_situacao_candidato_tot == 16) && !(nm_tipo_destinacao_votos.compare("Válido (legenda)")))
        return;

    if (cd_sit_tot_turno == 2 || cd_sit_tot_turno == 3)
        this->numeroDeVagas++;

    bool legenda = false;
    if (nm_tipo_destinacao_votos.compare("Válido (legenda)") == 0)
        legenda = true;
    else
        legenda = false;

    Candidato c = Candidato(nm_urna_candidato, nr_candidato, nr_federacao, cd_genero, cd_sit_tot_turno, nr_partido, legenda);

    totalCandidatos.insert(pair<int, Candidato>(nr_candidato, c));
}

void Eleicao::registraVoto(int cdCargo, int nrVotavel, int qtdVotos)
{
    if (!((this->tipo == ESTADUAL && cdCargo == 7) || (this->tipo == FEDERAL && cdCargo == 6)))
    {
        return;
    }  
    
    auto it = totalCandidatos.find(nrVotavel);
    if (it != totalCandidatos.end())
    {
        int nrPartido = it->second.registraVoto(qtdVotos);

        auto it2 = partidos.find(nrPartido);
        if (it2 != partidos.end())
        {
            if (it->second.verificaLegenda())
            {
                it2->second.registraVotosLegenda(qtdVotos);
                totalVotosLegenda += qtdVotos;
            }
            else
            {
                it2->second.registraVotosNominais(qtdVotos, nrVotavel);
                totalVotosNominais += qtdVotos;
            }
        }
    }
    else
    {
        auto it = partidos.find(nrVotavel);
        if (it != partidos.end())
        {
            it->second.registraVotosLegenda(qtdVotos);
            totalVotosLegenda += qtdVotos;
        }
    }
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

    for (auto it = totalCandidatos.begin(); it != totalCandidatos.end(); it++)
    {
        Partido p = partidos.find(it->second.getNrPartido())->second;
        string flexaoVotos = "";
        if (it->second.getQtdVotos() > 1)
        {
            flexaoVotos = " votos)";
        }
        else
        {
            flexaoVotos = " voto)";
        }
        cout << it->second.getNomeUrna() << " (" << p.getSigla() << ", " << it->second.getQtdVotos() << flexaoVotos << endl;
    }

    cout << endl;
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

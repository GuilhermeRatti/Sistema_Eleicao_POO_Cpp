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
    return eleicao;
}

void Eleicao::registraCandidato(int cd_cargo, int cd_situacao_candidato_tot, int nr_candidato, string nm_urna_candidato, int nr_partido, string sg_partido, int nr_federacao, string dt_nascimento, int cd_sit_tot_turno, int cd_genero, string nm_tipo_destinacao_votos)
{
    auto pt = partidos.find(nr_partido);

    Partido par;
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
    {
        this->numeroDeVagas++;
        if(pt!=partidos.end())
            pt->second.addQtdCandidatosEleitos();
        else
            par.addQtdCandidatosEleitos();
    }

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

bool ComparaCandidatos(const Candidato &c1, const Candidato &c2)
{
    return c1.getQtdVotos() > c2.getQtdVotos();
}

void Eleicao::ordenaCandidatos()
{
    for(auto it = totalCandidatos.begin(); it != totalCandidatos.end(); it++)
    {
        candidatosOrdenados.push_back(it->second);
    }

    candidatosOrdenados.sort(ComparaCandidatos);
}

bool ComparaPartidos(const Partido &p1, const Partido &p2)
{
    return p1.getQtdVotosTotais() > p2.getQtdVotosTotais();
}

void Eleicao::ordenaPartidos()
{
    for(auto it = partidos.begin(); it != partidos.end(); it++)
    {
        partidosOrdenados.push_back(it->second);
    }

    partidosOrdenados.sort(ComparaPartidos);
}
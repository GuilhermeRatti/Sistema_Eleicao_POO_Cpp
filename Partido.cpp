#include <iostream> // cout
#include <fstream>  // ifstream
#include <sstream>  // istringstream
#include <map>
#include <list>
#include <ctime>

#include "Partido.hpp"
#include "Candidato.hpp"

void Partido::registraVotosNominais(const int &votos, const int &nrCandidato)
{
    auto it = candidatos.find(nrCandidato);
    if (it != candidatos.end())
    {
        it->second.registraVoto(votos);
    }

    qtdVotosNominais += votos;
}

bool ComparadorDeDatas(const tm &dt1, const tm &dt2) {
    if (dt1.tm_year > dt2.tm_year)
    {
        return true;
    }
    else if (dt1.tm_year == dt2.tm_year)
    {
        if (dt1.tm_mon > dt2.tm_mon)
        {
            return true;
        }
        else if (dt1.tm_mon == dt2.tm_mon)
        {
            if (dt1.tm_mday > dt2.tm_mday)
            {
                return true;
            }
        }
    }
    return false;
}

bool ComparadorDeCandidatos(const Candidato &c1, const Candidato &c2)
{
    if (c1.getQtdVotos() > c2.getQtdVotos())
    {
        return true;
    }
    else if (c1.getQtdVotos() == c2.getQtdVotos())
    {
        tm dt1 = (c1.getDtNascimento());
        if (c1.getNrCandidato() < c2.getNrCandidato())
        {
            return true;
        }
    }
    return false;
}

void Partido::ordenaCandidatos() {
    for (auto it = candidatos.begin(); it != candidatos.end(); it++)
    {
        candidatosOrdenados.push_back(it->second);
    }

    candidatosOrdenados.sort(ComparadorDeCandidatos);
}
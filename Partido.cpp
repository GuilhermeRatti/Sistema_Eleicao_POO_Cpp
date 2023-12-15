#include <iostream> // cout
#include <fstream>  // ifstream
#include <sstream>  // istringstream
#include <map>

#include "Partido.hpp"

void Partido::registraVotosNominais(const int &votos, const int &nrCandidato)
{
    auto it = candidatos.find(nrCandidato);
    if (it != candidatos.end())
    {
        it->second.registraVoto(votos);
    }

    qtdVotosNominais += votos;
}

#include "Candidato.hpp"
#include "Partido.hpp"
#include <string>
#include <iostream>

const int &Candidato::registraVoto(const int &votos)
{
    if (legenda==false)
    {
        qtdVotos += votos;
    }

    return nrPartido;
}


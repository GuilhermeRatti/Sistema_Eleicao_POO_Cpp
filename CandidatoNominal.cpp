#include <string>
#include <iostream> // cout

#include "CandidatoNominal.hpp"

using namespace std;

void CandidatoNominal::registraVoto(const int &votos)
{
    this->adicionaVotos(votos);
    this->getPartido().registraVotosLegenda(votos);
}

ostream &operator<<(ostream &strm, const CandidatoNominal &c)
{
    string asterisco = "";
    if(c.getNumFederacao()!=-1)  asterisco = "*";

    string flexaoDeVoto = "";
    if(c.getQtdVotos() > 1) {
        flexaoDeVoto = " votos)";
    } else {
        flexaoDeVoto = " voto)";
    }

    return strm << asterisco << c.getNomeUrna() << " (" << c.getPartido().getSigla() << ", " << c.getQtdVotos() << flexaoDeVoto;
}
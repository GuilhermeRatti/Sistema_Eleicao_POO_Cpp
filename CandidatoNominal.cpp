#include <string>
#include <iostream> // cout

#include "CandidatoNominal.hpp"

using namespace std;

void CandidatoNominal::registraVoto(const int &votos)
{
    try
    {
        int votosPreAtualizacao = this->getQtdVotos();
        this->adicionaVotos(votos);

        if (this->getQtdVotos() != votosPreAtualizacao + votos)
            throw invalid_argument("Erro ao registrar votos nominais para o candidato nominal " + this->getNomeUrna() + " do partido " + this->getPartido().getSigla() + ".\n");
    }
    catch (const invalid_argument &e)
    {
        cout << e.what() << endl;
        exit(1);
    }
    
    try
    {
        int votosPreAtualizacao = this->getPartido().getQtdVotosLegenda();
        this->getPartido().registraVotosLegenda(votos);

        if (this->getPartido().getQtdVotosLegenda() != votosPreAtualizacao + votos)
            throw invalid_argument("Erro ao registrar votos de legenda para o candidato nominal " + this->getNomeUrna() + " do partido " + this->getPartido().getSigla() + ".\n");
    }
    catch (const invalid_argument &e)
    {
        exit(1);
    }
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
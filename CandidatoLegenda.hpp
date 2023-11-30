#if !defined(CANDIDATO_LEG_H)
#define CANDIDATO_LEG_H

#include "Candidato.hpp"

using namespace std;

class CandidatoLegenda : public Candidato
{
public:
    CandidatoLegenda(const string &nomeUrna,
                     const int &numCandidato,
                     const int &numFederacao,
                     const int &genero,
                     const int &cdEleito,
                     const Partido &partido) : Candidato(nomeUrna, numCandidato, numFederacao, genero, cdEleito, partido){};

    void registraVoto(const int &votos) override;

    friend ostream &operator<<(ostream &strm, const CandidatoLegenda &c);
};

#endif
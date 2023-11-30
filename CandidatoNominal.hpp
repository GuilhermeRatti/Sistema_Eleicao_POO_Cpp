#if !defined(CANDIDATO_NOM_H)
#define CANDIDATO_NOM_H

#include "Candidato.hpp"

using namespace std;

class CandidatoNominal : public Candidato
{
public:
    CandidatoNominal(const string &nomeUrna,
                     const int &numCandidato,
                     const int &numFederacao,
                     const int &genero,
                     const int &cdEleito,
                     const Partido &partido) : Candidato(nomeUrna, numCandidato, numFederacao, genero, cdEleito, partido){};

    void registraVoto(const int &votos) override;

    friend ostream &operator<<(ostream &strm, const CandidatoNominal &c);
};

#endif
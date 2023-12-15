#if !defined(CANDIDATO_H)
#define CANDIDATO_H

#include <string>
#include <ctime>
using namespace std;

class Candidato
{
    string nomeUrna;
    int qtdVotos;
    int numCandidato;
    int numFederacao;
    string dataNascimento;
    int genero;
    int cdEleito;
    int nrPartido;
    bool legenda;

public:
    Candidato() { ; }
    Candidato(const string &nomeUrna,
              const int &numCandidato,
              const int &numFederacao,
              const int &genero,
              const int &cdEleito,
              int nrPartido,
              bool legenda,
              const string &dataNascimento) : nomeUrna(nomeUrna),
                                              numCandidato(numCandidato),
                                              numFederacao(numFederacao),
                                              dataNascimento(dataNascimento),
                                              genero(genero),
                                              cdEleito(cdEleito),
                                              nrPartido(nrPartido),
                                              legenda(legenda) { qtdVotos = 0; }

    const int &getQtdVotos() const { return qtdVotos; }
    const int &getNumCandidato() const { return numCandidato; }
    const string &getNomeUrna() const { return nomeUrna; }
    const int &getNrPartido() const { return nrPartido; }
    const string &getDataNascimento() const { return dataNascimento; }
    const int &getGenero() const { return genero; }
    const int &getNumFederacao() const { return numFederacao; }
    const bool verificaEleito() const { return (cdEleito == 2 || cdEleito == 3); }
    const bool &verificaLegenda() const { return legenda; }

    const int &registraVoto(const int &votos);

    const string &printCandidato() const;
    friend ostream &operator<<(ostream &os, const Candidato &c);
};

#endif
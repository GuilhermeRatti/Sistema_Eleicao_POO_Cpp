#if !defined(CANDIDATO_H)
#define CANDIDATO_H

#include <string>
#include <ctime>
using namespace std;

class Partido;

class Candidato
{
    string nomeUrna;
    int qtdVotos;
    int numCandidato;
    int numFederacao;
    tm dataNascimento;
    int genero;
    int cdEleito;
    Partido* partido;

public:
    Candidato() {;}
    Candidato(const string &nomeUrna,
              const int &numCandidato,
              const int &numFederacao,
              const int &genero,
              const int &cdEleito,
              Partido* partido) : nomeUrna(nomeUrna),
                                        numCandidato(numCandidato),
                                        numFederacao(numFederacao),
                                        genero(genero),
                                        cdEleito(cdEleito),
                                        partido(partido) { qtdVotos = 0; }

    const int &getQtdVotos() const { return qtdVotos; }
    const int &getNumCandidato() const { return numCandidato; }
    const string &getNomeUrna() const { return nomeUrna; }
    const Partido* getPartido() const { return partido; }
    Partido* getPartido() { return partido; }
    // const string &getDataNascimento() const { return dataNascimento; }
    const int &getGenero() const { return genero; }
    const int &getNumFederacao() const { return numFederacao; }
    void adicionaVotos(const int &votos) { qtdVotos += votos; }
    bool verificaEleito() const { return (cdEleito == 2 || cdEleito == 3); }

    virtual void registraVoto(const int &votos);

    friend bool operator<(const Candidato &c1, const Candidato &c2) { return c1.qtdVotos < c2.qtdVotos; }
};

#endif
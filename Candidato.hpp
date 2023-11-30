#if !defined(CANDIDATO_H)
#define CANDIDATO_H

#include <string>

using namespace std;

class Partido
{
    string sigla;
    int numPartido;
    int qtdVotosNominais;
    int qtdVotosLegenda;
    bool estaOrdenado;

    public:
        const string &getSigla() const { return sigla; }
        const int &getNumPartido() const { return numPartido; }
        const int &getQtdVotosNominais() const { return qtdVotosNominais; }
        const int &getQtdVotosLegenda() const { return qtdVotosLegenda; }
        const int &getQtdVotosTotais() const { return qtdVotosNominais + qtdVotosLegenda; }
        const bool &getEstaOrdenado() const { return estaOrdenado; }
        void registraVotosNominais(const int &votos) { qtdVotosNominais += votos; }
        void registraVotosLegenda(const int &votos) { qtdVotosLegenda += votos; }
};

class Candidato
{
    string nomeUrna;
    int qtdVotos;
    int numCandidato;
    int numFederacao;
    // string dataNascimento;
    int genero;
    int cdEleito;
    Partido partido;

public:
    Candidato(const string &nomeUrna,
              const int &numCandidato,
              const int &numFederacao,
              const int &genero,
              const int &cdEleito,
              const Partido &partido) : nomeUrna(nomeUrna),
                                        numCandidato(numCandidato),
                                        numFederacao(numFederacao),
                                        genero(genero),
                                        cdEleito(cdEleito),
                                        partido(partido) { qtdVotos = 0; }

    const int &getQtdVotos() const { return qtdVotos; }
    const int &getNumCandidato() const { return numCandidato; }
    const string &getNomeUrna() const { return nomeUrna; }
    const Partido &getPartido() const { return partido; }
    Partido &getPartido() { return partido; }
    // const string &getDataNascimento() const { return dataNascimento; }
    const int &getGenero() const { return genero; }
    const int &getNumFederacao() const { return numFederacao; }
    void adicionaVotos(const int &votos) { qtdVotos += votos; }
    const bool &verificaEleito() const { return cdEleito == 2 || cdEleito == 3; }

    virtual void registraVoto(const int &votos);

    friend bool operator<(const Candidato &c1, const Candidato &c2) { return c1.qtdVotos < c2.qtdVotos; }
};

#endif
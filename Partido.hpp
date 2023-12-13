#if !defined(PARTIDO_H)
#define PARTIDO_H

#include <map>

class Candidato;
using namespace std;

class Partido
{
    map<int, Candidato*> candidatos;
    string sigla;
    int numPartido;
    int qtdVotosNominais;
    int qtdVotosLegenda;
    bool estaOrdenado;

public:
    Partido(const string &sigla, const int &numPartido) : sigla(sigla), numPartido(numPartido)
    {
        qtdVotosNominais = 0;
        qtdVotosLegenda = 0;
        estaOrdenado = false;
    }
    const string &getSigla() const { return sigla; }
    const int &getNumPartido() const { return numPartido; }
    const int &getQtdVotosNominais() const { return qtdVotosNominais; }
    const int &getQtdVotosLegenda() const { return qtdVotosLegenda; }
    const int &getQtdVotosTotais() const;
    const bool &getEstaOrdenado() const { return estaOrdenado; }
    void registraVotosNominais(const int &votos) { qtdVotosNominais += votos; }
    void registraVotosLegenda(const int &votos) { qtdVotosLegenda += votos; }
    void adicionaCandidato(const Candidato &candidato);
    const map<int, Candidato*> &getCandidatos() const { return candidatos; }
    void ordenaCandidatos();

    friend ostream &operator<<(ostream &strm, const Partido &p);
    friend bool operator<(const Partido &p1, const Partido &p2) { return p1.getQtdVotosTotais() < p2.getQtdVotosTotais(); }
};

#endif
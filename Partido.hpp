#if !defined(PARTIDO_H)
#define PARTIDO_H

#include <map>
#include <list>
#include "Candidato.hpp"

using namespace std;

class Partido
{
    map<int, Candidato> candidatos;
    list<Candidato> candidatosOrdenados;
    string sigla;
    int numPartido;
    int qtdVotosNominais;
    int qtdVotosLegenda;
    bool estaOrdenado;
    int qtdCandidatosEleitos;

public:
    Partido()
    {
        qtdVotosNominais = 0;
        qtdVotosLegenda = 0;
        qtdCandidatosEleitos = 0;
        estaOrdenado = false;
    }
    Partido(const string sigla, const int numPartido) : sigla(sigla), numPartido(numPartido)
    {
        qtdVotosNominais = 0;
        qtdVotosLegenda = 0;
        qtdCandidatosEleitos = 0;
        estaOrdenado = false;
    }
    const string &getSigla() const { return sigla; }
    const int &getNumPartido() const { return numPartido; }
    const int &getQtdVotosNominais() const { return qtdVotosNominais; }
    const int &getQtdVotosLegenda() const { return qtdVotosLegenda; }
    const int getQtdVotosTotais() const { return qtdVotosLegenda + qtdVotosNominais; }
    const bool &getEstaOrdenado() const { return estaOrdenado; }
    const int &getQtdCandidatosEleitos() const { return qtdCandidatosEleitos; }
    const Candidato &getCandMaisVotado() const {return candidatosOrdenados.front();}
    const Candidato &getCandMenosVotado() const;
    const int getQtdDeCandidatos() const { return candidatos.size(); }
    void addQtdCandidatosEleitos() { qtdCandidatosEleitos++; }
    void adicionaCandidato(const Candidato &candidato);
    const map<int, Candidato> &getCandidatos() const { return candidatos; }
    void registraVotosNominais(const int &votos, const int &nrCandidato);
    void registraVotosLegenda(const int &votos) { qtdVotosLegenda += votos; };
    void ordenaCandidatos();

    friend ostream &operator<<(ostream &strm, const Partido &p);
    friend bool operator<(const Partido &p1, const Partido &p2) { return p1.getQtdVotosTotais() < p2.getQtdVotosTotais(); }
};

#endif
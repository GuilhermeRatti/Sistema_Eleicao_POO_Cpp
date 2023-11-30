#if !defined(ELEICAO_H)
#define ELEICAO_H

#include <map>
#include <list>
#include <string>

#include "Candidato.hpp"
#include "Partido.hpp"  

using namespace std;

enum tipoDeCargo
{
    ESTADUAL,
    FEDERAL
};

class Eleicao
{
    private:
        map<int, Partido> partidos;
        map<int, Candidato> totalCandidatos;
        list<Candidato> candidatosOrdenados;
        list<Partido> partidosOrdenados;
        //string dataDaEleicao;
        tipoDeCargo tipo;
        int numeroDeVagas;
        int totalVotosNominais;
        int totalVotosLegenda;
    
    public:
        Eleicao(tipoDeCargo tipo/*, string dataEleicao*/);
        void registraCandidato();
        void registraVoto();
};

#endif
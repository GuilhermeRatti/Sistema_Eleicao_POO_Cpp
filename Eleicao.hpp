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
    string dataDaEleicao;
    tipoDeCargo tipo;
    int numeroDeVagas;
    int totalVotosNominais;
    int totalVotosLegenda;

    void ordenaCandidatos();
    void ordenaPartidos();

public:
    Eleicao(tipoDeCargo tipo, string dataEleicao) : dataDaEleicao(dataEleicao), tipo(tipo)
    {
        this->numeroDeVagas = 0;
        this->totalVotosLegenda = 0;
        this->totalVotosNominais = 0;
    };
    void registraCandidato(int cd_cargo, int cd_situacao_candidato_tot, int nr_candidato, string nm_urna_candidato, int nr_partido, string sg_partido, int nr_federacao, string dt_nascimento, int cd_sit_tot_turno, int cd_genero, string nm_tipo_destinacao_votos);
    void registraVoto();
    void printaRelatorio1();
    void printaRelatorio2();
    void printaRelatorio3();
    void printaRelatorio4();
    void printaRelatorio5();
    void printaRelatorio6();
    void printaRelatorio7();
    void printaRelatorio8();
    void printaRelatorio9();
};

Eleicao criaEleicao(int argc, char **argv, Eleicao eleicao);

#endif
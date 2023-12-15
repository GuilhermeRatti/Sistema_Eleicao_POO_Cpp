#if !defined(RELATORIO_H)
#define RELATORIO_H

#include "Eleicao.hpp"
#include "Candidato.hpp"
#include "Partido.hpp"

class GeradorDeRelatorio
{
    Eleicao eleicao;

    public:
        GeradorDeRelatorio(const Eleicao &eleicao) : eleicao(eleicao) {ordenaListas();}
        void ordenaListas();
        void printaRelatorio1() const;
        void printaRelatorio2() const;
        void printaRelatorio3() const;
        void printaRelatorio4() const;
        void printaRelatorio5() const;
        void printaRelatorio6() const;
        void printaRelatorio7() const;
        void printaRelatorio8() const;
        void printaRelatorio9() const;
        void printaRelatorio10() const;
};

#endif
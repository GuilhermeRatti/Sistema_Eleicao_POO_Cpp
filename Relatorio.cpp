#include <iostream> // cout
#include <fstream>
#include <string>  // ifstream
#include <sstream> // istringstream
#include <map>
#include <locale>
#include <iomanip>

#include "Eleicao.hpp"
#include "Candidato.hpp"
#include "Partido.hpp"
#include "Relatorio.hpp"

void GeradorDeRelatorio::printaRelatorio1() const
{
    cout << "Número de vagas: " << eleicao.numeroDeVagas << endl;
}

void GeradorDeRelatorio::ordenaListas() {
    locale brLocale("pt_BR.UTF-8");
    cout.imbue(brLocale);
    if (eleicao.candidatosOrdenados.empty())
    {
        eleicao.ordenaCandidatos();
    }
    if (eleicao.partidosOrdenados.empty())
    {
        eleicao.ordenaPartidos();
    }
}

void GeradorDeRelatorio::printaRelatorio2() const
{
    string tipoDeDeputados = "";
    if (eleicao.tipo == ESTADUAL)
    {
        tipoDeDeputados = "estaduais";
    }
    else
    {
        tipoDeDeputados = "federais";
    }

    cout << "Deputados " << tipoDeDeputados << " eleitos:" << endl;

    for (auto it = eleicao.totalCandidatos.begin(); it != eleicao.totalCandidatos.end(); it++)
    {
        Partido p = eleicao.partidos.find(it->second.getNrPartido())->second;
        string flexaoVotos = "";
        if (it->second.getQtdVotos() > 1)
        {
            flexaoVotos = " votos)";
        }
        else
        {
            flexaoVotos = " voto)";
        }
        cout << it->second.getNomeUrna() << " (" << p.getSigla() << ", " << it->second.getQtdVotos() << flexaoVotos << endl;
    }

    cout << endl;
}

void GeradorDeRelatorio::printaRelatorio3() const
{
    // printaRelatorio3 implementation
}

void GeradorDeRelatorio::printaRelatorio4() const
{
    cout << "Eleitos, que se beneficiaram do sistema proporcional:\n(com sua posição no ranking de mais votados)" << endl;
    int i=0,j=0;
    for(auto it = eleicao.candidatosOrdenados.begin(); it != eleicao.candidatosOrdenados.end(); it++)
    {
        if(i==eleicao.numeroDeVagas)
            break;
        if(it->verificaEleito()==true)
        {
            i++;
            if(j>=eleicao.numeroDeVagas)
            {
                Partido p = eleicao.partidos.find(it->getNrPartido())->second;
                string flexaoVotos = "";
                if (it->getQtdVotos() > 1)
                {
                    flexaoVotos = " votos)";
                }
                else
                {
                    flexaoVotos = " voto)";
                }
                cout << j+1 << " - " << it->getNomeUrna() << " (" << p.getSigla() << ", " << it->getQtdVotos() << " votos)" << endl;
            }
        }
    }
}

void GeradorDeRelatorio::printaRelatorio5() const
{
    // printaRelatorio5 implementation
}

void GeradorDeRelatorio::printaRelatorio6() const
{
    // printaRelatorio6 implementation
}

void GeradorDeRelatorio::printaRelatorio7() const
{
    // printaRelatorio7 implementation
}

void GeradorDeRelatorio::printaRelatorio8() const
{
    // printaRelatorio8 implementation
}

void GeradorDeRelatorio::printaRelatorio9() const
{
    // printaRelatorio9 implementation
}

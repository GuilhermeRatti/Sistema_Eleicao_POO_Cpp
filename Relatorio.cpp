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
    cout << endl;
}

void GeradorDeRelatorio::ordenaListas()
{
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
    int i = 0;
    for (auto it = eleicao.candidatosOrdenados.begin(); it != eleicao.candidatosOrdenados.end(); it++)
    {
        if (i == eleicao.numeroDeVagas)
            break;
        if (it->verificaEleito())
        {
            Partido p = eleicao.partidos.find(it->getNrPartido())->second;
            string flexaoVotos = "";
            string asterisco = "";
            if (it->getNumFederacao() != -1)
                asterisco = "*";
            if (it->getQtdVotos() > 1)
            {
                flexaoVotos = " votos)";
            }
            else
            {
                flexaoVotos = " voto)";
            }
            cout << (++i) << " - " << asterisco << it->getNomeUrna() << " (" << p.getSigla() << ", " << it->getQtdVotos() << flexaoVotos << endl;
        }
    }

    cout << endl;
}

void GeradorDeRelatorio::printaRelatorio3() const
{
    cout << "Candidatos mais votados (em ordem decrescente de votação e respeitando número de vagas):" << endl;
    int i = 0;
    for (auto it = eleicao.candidatosOrdenados.begin(); it != eleicao.candidatosOrdenados.end(); it++)
    {
        if (i == eleicao.numeroDeVagas)
            break;
        Partido p = eleicao.partidos.find(it->getNrPartido())->second;
        string asterisco = "";
        if (it->getNumFederacao() != -1)
            asterisco = "*";
        string flexaoVotos = "";
        if (it->getQtdVotos() > 1)
        {
            flexaoVotos = " votos)";
        }
        else
        {
            flexaoVotos = " voto)";
        }
        cout << (++i) << " - " << asterisco << it->getNomeUrna() << " (" << p.getSigla() << ", " << it->getQtdVotos() << flexaoVotos << endl;
    }
    cout << endl;
}

void GeradorDeRelatorio::printaRelatorio4() const
{
    cout << "Teriam sido eleitos se a votação fosse majoritária, e não foram eleitos:\n(com sua posição no ranking de mais votados)" << endl;
    int i = 0;
    for (auto it = eleicao.candidatosOrdenados.begin(); it != eleicao.candidatosOrdenados.end(); it++)
    {
        if (i == eleicao.numeroDeVagas)
            break;
        if (it->verificaEleito() == false)
        {
            Partido p = eleicao.partidos.find(it->getNrPartido())->second;
            string asterisco = "";
            if (it->getNumFederacao() != -1)
                asterisco = "*";
            string flexaoVotos = "";
            if (it->getQtdVotos() > 1)
            {
                flexaoVotos = " votos)";
            }
            else
            {
                flexaoVotos = " voto)";
            }
            cout << (i+1) << " - " << asterisco << it->getNomeUrna() << " (" << p.getSigla() << ", " << it->getQtdVotos() << flexaoVotos << endl;
        }
        i++;
    }
    cout << endl;
}

void GeradorDeRelatorio::printaRelatorio5() const
{
    cout << "Eleitos, que se beneficiaram do sistema proporcional:\n(com sua posição no ranking de mais votados)" << endl;
    int i = 0, j = 0;
    for (auto it = eleicao.candidatosOrdenados.begin(); it != eleicao.candidatosOrdenados.end(); it++)
    {
        if (i == eleicao.numeroDeVagas)
            break;
        if (it->verificaEleito() == true)
        {
            i++;
            if (j >= eleicao.numeroDeVagas)
            {
                Partido p = eleicao.partidos.find(it->getNrPartido())->second;
                string flexaoVotos = "";
                string asterisco = "";
                if (it->getNumFederacao() != -1)
                    asterisco = "*";
                if (it->getQtdVotos() > 1)
                {
                    flexaoVotos = " votos)";
                }
                else
                {
                    flexaoVotos = " voto)";
                }
                cout << j + 1 << " - " << asterisco << it->getNomeUrna() << " (" << p.getSigla() << ", " << it->getQtdVotos() << flexaoVotos << endl;
            }
        }
        j++;
    }
    cout << endl;
}

void GeradorDeRelatorio::printaRelatorio6() const
{
    cout << "Votação dos partidos e número de candidatos eleitos:" << endl;
    int i = 0;
    for(auto it = eleicao.partidosOrdenados.begin(); it != eleicao.partidosOrdenados.end(); it++)
    {
        Partido p = *it;
        if(p.getQtdVotosNominais() > 0)
        {
            string flexaovoto = " voto (";
            if(p.getQtdVotosTotais() > 1)
            {
                flexaovoto = " votos (";
            }

            string flexaonominal = " nominai e ";
            if(p.getQtdVotosNominais() > 1)
            {
                flexaonominal = " nominais e ";
            }

            cout << (++i) << " - " << p.getSigla() << " - " << p.getNumPartido() << ", " << p.getQtdVotosTotais() << flexaovoto;
            cout << p.getQtdVotosNominais() << flexaonominal << p.getQtdVotosLegenda() << " de legenda), ";
            if(p.getQtdCandidatosEleitos() > 1)
            {
                cout << p.getQtdCandidatosEleitos() << " candidatos eleitos" << endl;
            }
            else
            {
                cout << p.getQtdCandidatosEleitos() << " candidato eleito" << endl;
            }
        }
    }
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

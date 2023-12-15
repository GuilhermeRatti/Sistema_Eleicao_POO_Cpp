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
    for (auto it = eleicao.partidos.begin(); it != eleicao.partidos.end(); it++)
    {
        it->second.ordenaCandidatos();
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
            cout << (i + 1) << " - " << asterisco << it->getNomeUrna() << " (" << p.getSigla() << ", " << it->getQtdVotos() << flexaoVotos << endl;
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
    for (auto it = eleicao.partidosOrdenados.begin(); it != eleicao.partidosOrdenados.end(); it++)
    {
        Partido p = *it;
        if (p.getQtdVotosNominais() > 0)
        {
            string flexaovoto = " voto (";
            if (p.getQtdVotosTotais() > 1)
            {
                flexaovoto = " votos (";
            }

            string flexaonominal = " nominai e ";
            if (p.getQtdVotosNominais() > 1)
            {
                flexaonominal = " nominais e ";
            }

            cout << (++i) << " - " << p.getSigla() << " - " << p.getNumPartido() << ", " << p.getQtdVotosTotais() << flexaovoto;
            cout << p.getQtdVotosNominais() << flexaonominal << p.getQtdVotosLegenda() << " de legenda), ";
            if (p.getQtdCandidatosEleitos() > 1)
            {
                cout << p.getQtdCandidatosEleitos() << " candidatos eleitos" << endl;
            }
            else
            {
                cout << p.getQtdCandidatosEleitos() << " candidato eleito" << endl;
            }
        }
    }
    cout << endl;
}

void GeradorDeRelatorio::printaRelatorio7() const
{
    // printaRelatorio7 implementation
}

void GeradorDeRelatorio::printaRelatorio8() const
{
    int sub_30 = 0, _30a40 = 0, _40a50 = 0, _50a60 = 0, acima60 = 0, i = 0;

    for (auto it = eleicao.candidatosOrdenados.begin(); it != eleicao.candidatosOrdenados.end(); it++)
    {
        if (i == eleicao.numeroDeVagas)
            break;
        if (it->verificaEleito() == true)
        {
            tm dataNascimento = {};
            istringstream ss(it->getDataNascimento());
            ss >> get_time(&dataNascimento, "%d/%m/%Y");

            tm dataEleicao = {};
            istringstream ss2(eleicao.dataDaEleicao);
            ss2 >> get_time(&dataEleicao, "%d/%m/%Y");

            double idade = difftime(mktime(&dataEleicao), mktime(&dataNascimento)) / (60 * 60 * 24 * 365.25);
            i++;
            if (idade < 30)
                sub_30++;
            else if (idade >= 30 && idade < 40)
                _30a40++;
            else if (idade >= 40 && idade < 50)
                _40a50++;
            else if (idade >= 50 && idade < 60)
                _50a60++;
            else
                acima60++;
        }
    }
    cout << setprecision(2) << fixed;
    cout << "Eleitos, por faixa etária (na data da eleição):" << endl;
    cout << "      Idade < 30: " << sub_30 << " (" << float(sub_30) / float(eleicao.numeroDeVagas) * 100 << "%)" << endl;
    cout << "30 <= Idade < 40: " << _30a40 << " (" << float(_30a40) / float(eleicao.numeroDeVagas) * 100 << "%)" << endl;
    cout << "40 <= Idade < 50: " << _40a50 << " (" << float(_40a50) / float(eleicao.numeroDeVagas) * 100 << "%)" << endl;
    cout << "50 <= Idade < 60: " << _50a60 << " (" << float(_50a60) / float(eleicao.numeroDeVagas) * 100 << "%)" << endl;
    cout << "60 <= Idade     : " << acima60 << " (" << float(acima60) / float(eleicao.numeroDeVagas) * 100 << "%)" << endl;
    cout << endl;
}

void GeradorDeRelatorio::printaRelatorio9() const
{
    cout << "Eleitos, por gênero:" << endl;
    int fem = 0, masc = 0;
    for (auto it = eleicao.candidatosOrdenados.begin(); it != eleicao.candidatosOrdenados.end(); it++)
    {
        if (it->verificaEleito() == true)
        {
            if (it->getGenero() == 2)
            {
                masc++;
            }
            else
            {
                fem++;
            }
        }
    }
    cout << setprecision(2) << fixed;

    cout << "Feminino: " << fem << " (" << float(fem) / float(eleicao.numeroDeVagas) * 100 << "%)" << endl;
    cout << "Masculino: " << masc << " (" << float(masc) / float(eleicao.numeroDeVagas) * 100 << "%)" << endl;
    cout << endl;
}

#include "Candidato.hpp"
#include "Partido.hpp"

void Candidato::registraVoto(const int &votos) {
    return;
}

/*ostream &operator<<(ostream &os, const Candidato &c)
{
    string asterisco = "";
    if(c.getNumFederacao()!=-1)  asterisco = "*";

    string flexaoDeVoto = "";
    if(c.getQtdVotos() > 1) {
        flexaoDeVoto = " votos)";
    } else {
        flexaoDeVoto = " voto)";
    }

    return os << asterisco << c.getNomeUrna() << " (" << c.getPartido()->getSigla() << ", " << c.getQtdVotos() << flexaoDeVoto;
}*/
#ifndef GRAPHE_H_INCLUDED
#define GRAPHE_H_INCLUDED
#include "Sommet.h"
#include "Plateau.h"
class Graphe
{
private:
    Sommet m_S1;

public:

    Graphe();
    Graphe( Plateau _S1);
    void Afficher_graphe();
    void MIN();
    void Max();
    void AlgoMin_Max();


};


#endif // GRAPHE_H_INCLUDED

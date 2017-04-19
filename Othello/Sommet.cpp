#include "Sommet.h"
#include "Plateau.h"
#include <vector>
using namespace std;

Sommet::Sommet()
{

}
Sommet::Sommet(int _Profondeur)
:m_Profondeur(_Profondeur)
{

}
Sommet::Sommet(Plateau _Jeu,int _Profondeur)
       :m_Jeu(_Jeu),m_Profondeur(_Profondeur)
    {

    }

int Sommet::get_Pronfondeur()
{
    return m_Profondeur;
}
void Sommet::set_Profondeur(int _Profondeur)
{
    m_Profondeur=_Profondeur;
}
void Sommet::create_fils()
{
    vector <Plateau> a;
     a[0].initialiserCases();
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
               a[0].cases[i][j].set_couleur(m_Jeu.cases[i][j].get_couleur());


    //Simulation des coups possibles
    //Enregistremenent des coups possible
    //Creer

}
//void Sommet::dupliquer_plateau();

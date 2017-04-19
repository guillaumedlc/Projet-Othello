#ifndef SOMMET_H_INCLUDED
#define SOMMET_H_INCLUDED
#include "Plateau.h"

class Sommet
{
private:
    Plateau m_Jeu;
    int m_Profondeur;
    Sommet*m_Smere;
public:
    vector <Sommet> m_Sfils;
    Sommet();
    Sommet(int _Profondeur);
    Sommet(Plateau _Jeu,int _Profondeur);
    int get_Pronfondeur();
    void set_Profondeur(int _Profondeur);
    void create_fils();
};

#endif // SOMMET_H_INCLUDED

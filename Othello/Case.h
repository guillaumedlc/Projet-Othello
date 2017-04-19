#ifndef CASE_H_INCLUDED
#define CASE_H_INCLUDED
#include "enums.h"

class Case
{
    protected:

        CaseDispo m_couleur; //couleur du pion (0:blanc, 1:noir, 3:vide)
        int m_x,m_y; //coordonnées de la case


    public:

        Case();
        Case(int _x, int _y, CaseDispo _couleur);
        ~Case();

        int get_x(){return (m_x);}
        int get_y(){return (m_y);}
        int get_couleur(){return (m_couleur);}
        void set_couleur(CaseDispo _couleur){m_couleur =_couleur;}


};

#endif // CASE_H

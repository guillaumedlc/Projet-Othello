#ifndef PLATEAU_H_INCLUDED
#define PLATEAU_H_INCLUDED
#include <vector>
#include "Case.h"
#include "Move.hpp"


using namespace std;

class Plateau
{
    protected:

    int m_nombreDeCases = 0;
    vector < vector < Case > > cases;
    Tour tour = Blanc;
    int nombreNoir = 0;
    int nombreBlanche = 0;
    
    public:

    Plateau();
    ~Plateau();

    int get_nombreDeCases(){return (m_nombreDeCases);}
    int get_nombreNoir(){return (nombreNoir);}
    int get_nombreBlanche(){return (nombreBlanche);}
    void set_nombreDeCases(int _nombreDeCases){m_nombreDeCases = _nombreDeCases;}
    void set_nombreNoirs(int _nombreNoir){nombreNoir = _nombreNoir;}
    void blanchesAndOne(){m_nombreDeCases++;}
    void noirsAndOne(){nombreNoir++;}
    void set_nombreDeBlanches(int _nombreBlanche){nombreBlanche = _nombreBlanche;}
    void initialiserCases();
    void initialiserCasesPourNouvellePartie();
    vector< Move > findOpenSpot(CaseDispo);
    void afficher();
    void afficherAvecCasesLibres(vector<Move> casesVides);
    void changementDeTour(){if (tour == Blanc){tour = Noir;}else{tour = Blanc;}}
    Tour getTour(){return tour;}
    void placerPion(int x, int y);
    void verifManger(int x, int y, CaseDispo caseRecu,vector<Move> mv);
    bool moveIsGood(int x, int y, vector <Move> mv);
    void enregistrerPartie(vector<Case> v);
    void afficherScore();
    void casesCounter();

    
    
};

#endif // CASE_H

#include "Joueur.h"

using namespace std;

Joueur::Joueur()
{

}

Joueur::~Joueur()
{

}

Joueur::Joueur(string _nom,int _nbpion) //constructeur
       :m_nbpion(_nbpion),m_nom(_nom),m_win(false)
{

}


//getters et setters

string Joueur::get_nom() {return m_nom;}
string Joueur::set_nom()
{
    string nom;
    cout<<"Entrez votre nom de joueur : ";
    cin>>nom;
    m_nom=nom;
    return m_nom;
}

bool Joueur::get_win() {return m_win;}
void Joueur::set_win(bool _win) {m_win = _win;}

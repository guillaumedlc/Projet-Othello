#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED

#include <string>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "Move.hpp"
#include <vector>
using namespace std;

class Joueur
{
private:
    //attributs
	string m_nom;
	int m_nbpion = 2; //nombre de pions sur l'othellier au départ (2 noir et 2 blanc)
	bool m_win;

public:
	//constructeur et destructeur
	Joueur();
	Joueur(string _nom,int _nbpion);
	~Joueur();

    //getters et setters
	int get_nbpion(){return m_nbpion;}
	void set_nbpion(int _nbpion){m_nbpion = _nbpion;}

	bool get_win();
	void set_win(bool _win);
	
    Move selectionAI(vector< Move > mv){return mv[rand() % mv.size()];}
    
	string get_nom();
	string set_nom();
};

#endif // JOUEUR_H

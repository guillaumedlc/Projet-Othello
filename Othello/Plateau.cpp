#include "Plateau.h"
#include "Case.h"
#include <iostream>
using namespace std;

Plateau::Plateau(){

}

void Plateau::initialiserCases(){

    for (int i=0; i<8; i++){
        vector<Case> v;
        cases.push_back(v);
        for(int j=0; j<8; j++){
            cases[i].push_back(Case());
        }
    }
}


void Plateau::initialiserCasesPourNouvellePartie(){

	for (int i=0; i<8; i++)
        for(int j=0; j<8; j++)
            cases[i][j] = Case(i,j,nil);

    cases[3][3] = Case(3,3,blanc);
    cases[4][4] = Case(4,4,blanc);
    cases[3][4] = Case(3,4,noir);
    cases[4][3] = Case(4,3,noir);
}


std::vector< Move > Plateau::findOpenSpot(CaseDispo caseRecu){
	std::vector< Case > vct;
    vector<Move> mov;
	for (int i=0; i<8; i++){
        for(int j=0; j<8; j++){
        	if (cases[i][j].get_couleur() == caseRecu)
			{
				// Check Right
				if (cases[i][j].get_x() < 6)
				{
					if (cases[i+1][j].get_couleur() != caseRecu && cases[i+1][j].get_couleur() != nil)
					{
						int x = 1;
						while(x < 7 - cases[i][j].get_x())
						{
							if (cases[i + 1 + x][j].get_couleur() == nil)
							{
								// GOOD ADD To list
                                Move m = Move(cases[i][j], cases[i + 1 + x][j],droite, 1 + x);
                                mov.push_back(m);
								break;
							} 
						x++;
						}
					}
				}

				// Check Left
				if (cases[i][j].get_x() > 1)
				{
					if (cases[i-1][j].get_couleur() != caseRecu && cases[i-1][j].get_couleur() != nil)
					{
						int x = 1;
						while(x < cases[i][j].get_x())
						{
							if (cases[i - 1 - x][j].get_couleur() == nil)
							{
								// GOOD ADD To list
                                Move m = Move(cases[i][j], cases[i - 1 - x][j],gauche, 1 + x);
                                mov.push_back(m);
								break;
							} 
						x++;
						}
					}
				}

				// Check down
				if (cases[i][j].get_y() < 6)
				{
					if (cases[i][j+1].get_couleur() != caseRecu && cases[i][j+1].get_couleur() != nil)
					{
						int x = 1;
						while(x < 7 - cases[i][j].get_y())
						{
							if (cases[i][j + 1 + x].get_couleur() == nil)
							{
								// GOOD ADD To list
                                Move m = Move(cases[i][j], cases[i][j + 1 + x],bas, 1 + x);
                                mov.push_back(m);
								break;
							}
						x++;
						}
					}
				}

				// Check up
				if (cases[i][j].get_y() > 1)
				{
					if (cases[i][j-1].get_couleur() != caseRecu && cases[i][j-1].get_couleur() != nil)
					{
						int x = 1;
						while(x < cases[i][j].get_y())
						{
							if (cases[i][j - 1 - x].get_couleur() == nil)
							{
								// GOOD ADD To list
                                Move m = Move(cases[i][j], cases[i][j - 1 - x],haut, 1 + x);
                                mov.push_back(m);
								break;
							} 
						x++;
						}
					}
				}

				// Check north west
				if (cases[i][j].get_y() > 1 && cases[i][j].get_x() > 1)
				{
					if (cases[i-1][j-1].get_couleur() != caseRecu && cases[i-1][j-1].get_couleur() != nil)
					{
						int x = 1;
						while(x < cases[i][j].get_x() && x < cases[i][j].get_y())
						{
							if (cases[i - 1 - x][j - 1 - x].get_couleur() == nil)
							{
								// GOOD ADD To list
                                vct.push_back(cases[i - 1 - x][j - 1 - x]);
                                Move m = Move(cases[i][j], cases[i - 1 - x][j - 1 - x],nordwest, 1 + x);
                                mov.push_back(m);
								break;
							} 
						x++;
						}
					}
				}

				// Check north east
				if (cases[i][j].get_y() > 1 && cases[i][j].get_x() < 6)
				{
					if (cases[i+1][j-1].get_couleur() != caseRecu && cases[i+1][j-1].get_couleur() != nil)
					{
						int x = 1;
						while(x < 7 - cases[i][j].get_x() && x < cases[i][j].get_y())
						{
							if (cases[i + 1 + x][j - 1 - x].get_couleur() == nil)
							{
								// GOOD ADD To list
                                Move m = Move(cases[i][j], cases[i + 1 + x][j - 1 - x],norest, 1 + x);
                                mov.push_back(m);
								break;
							} 
						x++;
						}
					}
				}

				// Check south west
				if (cases[i][j].get_y() < 6 && cases[i][j].get_x() > 1)
				{
					if (cases[i-1][j+1].get_couleur() != caseRecu && cases[i-1][j+1].get_couleur() != nil)
					{
						int x = 1;
						while(x < 7 - cases[i][j].get_x() && x < cases[i][j].get_y())
						{
							if (cases[i - 1 - x][j + 1 + x].get_couleur() == nil)
							{
								// GOOD ADD To list
                                Move m = Move(cases[i][j], cases[i - 1 - x][j + 1 + x],sudouest, 1 + x);
                                mov.push_back(m);
								break;
							} 
						x++;
						}
					}
				}

				// Check south east
				if (cases[i][j].get_y() < 6 && cases[i][j].get_x() < 6)
				{
					if (cases[i+1][j+1].get_couleur() != caseRecu && cases[i+1][j+1].get_couleur() != nil)
					{
						int x = 1;
						while(x < cases[i][j].get_x() && x < cases[i][j].get_y())
						{
							if (cases[i + 1 + x][j + 1 + x].get_couleur() == nil)
							{
								// GOOD ADD To list
                                vct.push_back(cases[i + 1 + x][j + 1 + x]);
                                Move m = Move(cases[i][j], cases[i + 1 + x][j + 1 + x],sudest, 1 + x);
                                mov.push_back(m);
								break;
							} 
						x++;
						}
					}
				}
			}	
		}
	}
return mov;
}

void Plateau::afficher(){

	for (int i=0; i<8; i++){
        cout<<"\n";
        for(int j=0; j<8; j++){
        	if (cases[i][j].get_couleur() == blanc)
        	{
                std::cout <<"B ";
        	}
        	else if (cases[i][j].get_couleur() == noir)
        	{
        		cout <<"N ";
        	}else{
        		cout <<" - ";
        	}
        }
    }
    cout << endl;
}


void Plateau::afficherAvecCasesLibres(vector <Move> casesLibres){
    cout << "  ";
    for (int x = 0; x < 8; x++) {
        char c = 65;
        cout << char(c+x) << " ";
    }
    for (int j=0; j<8; j++){
        cout<<"\n";
        cout << j << " ";
        for(int i=0; i<8; i++){
            bool works = false;
            for (int b = 0; b < casesLibres.size(); b++) {
                if (casesLibres[b].getCaseFin().get_x() == i && casesLibres[b].getCaseFin().get_y() == j) {
                    cout << "* ";
                    b++;
                    works = true;
                    break;
                    }
            }
            if (works == false) {
                if (cases[i][j].get_couleur() == blanc){
                    std::cout <<"B ";
                }else if (cases[i][j].get_couleur() == noir){
                    cout <<"N ";
                }else{
                    cout <<"- ";
                }
            }
        }
    }
cout <<endl;
}


void Plateau::afficherScore(){
    cout << "Cases Blanches : " << get_nombreBlanche() << " Cases Noires : " << get_nombreNoir() << endl;
}



void Plateau::casesCounter(){
    int b = 0;
    int n = 0;
    for(int i = 0; i < cases.size(); i++ ){
        for(int j = 0; j < cases.size(); j++ ){
            if(cases[i][j].get_couleur() == blanc){
                b++;
            }else if(cases[i][j].get_couleur() == noir){
                n++;
            }
        }
    }
    set_nombreNoirs(n);
    set_nombreDeBlanches(b);
}




void Plateau::verifManger(int x, int y, CaseDispo caseRecu, vector<Move> mv){
//    cout << "HELLO1\n";
    for (int i = 0; i < mv.size(); i++) {
        if (x == mv[i].getCaseFin().get_x() && y == mv[i].getCaseFin().get_y()) {
//          Place all tiles between beginning and end
//            cout << mv[i].getCaseFin().get_x() << "\n" << mv[i].getCaseFin().get_y()<<endl;
            
//            int distance = mv[i].getDistance();
            for (int distance = 0; distance <= mv[i].getDistance(); distance++) {
                if (mv[i].getDirection() == droite) {
                    cout << "RIGHT";
                    placerPion(mv[i].getCaseDepart().get_x() + distance, mv[i].getCaseDepart().get_y());
                }
                if (mv[i].getDirection() == gauche) {
                    cout << "LEFT";
                    placerPion(mv[i].getCaseDepart().get_x() - distance, mv[i].getCaseDepart().get_y());
                }
                if (mv[i].getDirection() == haut) {
                    cout << "UP";
                    placerPion(mv[i].getCaseDepart().get_x(), mv[i].getCaseDepart().get_y() - distance);
                }
                if (mv[i].getDirection() == bas) {
                    cout << "DOWN";
                    placerPion(mv[i].getCaseDepart().get_x(), mv[i].getCaseDepart().get_y() + distance);
                }
                if (mv[i].getDirection() == norest) {
                    cout << "NORTH EAST";
                    placerPion(mv[i].getCaseDepart().get_x() + distance, mv[i].getCaseDepart().get_y() - distance);
                }
                if (mv[i].getDirection() == nordwest) {
                    cout << "NORTH WEST";
                    placerPion(mv[i].getCaseDepart().get_x() - distance, mv[i].getCaseDepart().get_y() - distance);
                }
                if (mv[i].getDirection() == sudest) {
                    cout << "SOUTH EAST";
                    placerPion(mv[i].getCaseDepart().get_x() + distance, mv[i].getCaseDepart().get_y() + distance);
                }
                if (mv[i].getDirection() == sudouest) {
                    cout << "SOUTH WEST";
                    placerPion(mv[i].getCaseDepart().get_x() - distance, mv[i].getCaseDepart().get_y() + distance);
                }
            }
        }
    }
}

void Plateau::enregistrerPartie(vector<Case> v){

}



bool Plateau::moveIsGood(int x, int y, vector <Move> mv){
    bool b = false;
    
    for (int i = 0; i < mv.size(); i++) {
        if (x == mv[i].getCaseFin().get_x() && y == mv[i].getCaseFin().get_y()) {
            b = true;
        }
    }
    if (!b) {
        cout<< "Pas Possible" <<endl;
    }
    return b;
}

void Plateau::placerPion(int x, int y){
    if (tour == Blanc){
        cases[x][y] = Case(x,y,blanc);
    }else{
        cases[x][y] = Case(x,y,noir);
    }
}

Plateau::~Plateau(){

}


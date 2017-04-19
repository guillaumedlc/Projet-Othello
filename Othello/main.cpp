#include <iostream>
#include <map>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <time.h>
#include <string>
#include "Joueur.h"
#include "Case.h"
#include "Plateau.h"
#include "Curseur.h"
#include "console.h"

using namespace std;


void Nouvelle_Partie() {


    Joueur joueur1; //objet de la classe Joueur
    Joueur joueur2; //joueur virtuel

    //joueur1.set_nom(); //demande le nom du joueur
    //joueur2.set_nom(); //demande le nom du joueur

    Plateau plateau = Plateau();
    plateau.initialiserCases();
    plateau.initialiserCasesPourNouvellePartie();


    Curseur curseur(2,2); // Initialisation du curseur a 2 , 2

    char touche;



    ///Boucle de jeu
    while(1){

        plateau.changementDeTour();
        cin.clear();
        cin.ignore(10000,'\n');

        // pt->gotoLigCol(curseur.get_y(),curseur.get_x() ); //position curseur

        // if (pt->isKeyboardPressed()){ //si une touche du clavier est enfoncée

        vector <Move> emptyCases;
        // touche=pt->getInputKey(); //prend en compte la touche enfoncée
        if (plateau.getTour() == Blanc) {
            emptyCases =  plateau.findOpenSpot(blanc);
            cout<<"Joueur Blanc a vous de jouer"<<endl;
        }else{
            emptyCases =  plateau.findOpenSpot(noir);
            cout<<"Joueur Noir a vous de jouer"<<endl;
        }

//        AI ALEATOIR
        if (false) {
            plateau.placerPion(joueur2.selectionAI(emptyCases).getCaseFin().get_x(), joueur2.selectionAI(emptyCases).getCaseFin().get_y()) ;
        }


        plateau.afficherAvecCasesLibres(emptyCases);
        cout << "\n";

        plateau.casesCounter();
        plateau.afficherScore();




        cin >> touche;
        cout << touche;


        if (touche =='z'){ //deplacement vers le haut
            if(curseur.get_y() != 0){ //blindage des bords
                curseur.yMinusOne();
            }
        }
        if (touche =='s'){ //deplacement vers le haut
            if(curseur.get_y() != 7){
                curseur.yAddOne();
            }
        }
        if (touche =='q'){ //deplacement vers le haut
            if(curseur.get_x() != 0){
                curseur.xMinusOne();
            }
        }
        if (touche =='d'){ //deplacement vers le haut
            if(curseur.get_x() != 7){ //blindage des bords
                curseur.xAddOne();
            }
        }
        if (touche =='n'){ // ON AJOUTE UNE NOUVELLE PIECE
            while (1) {

                char coordx, coordy;
                cin.clear();
                cin.ignore(10000, '\n');
                cin >> coordx >> coordy;
                cout << coordx << coordy <<endl;

                if (plateau.moveIsGood(coordx - 48, coordy - 48, emptyCases)) {
                    if (plateau.getTour() == Blanc) {
                        plateau.verifManger(coordx - 48, coordy - 48, blanc, emptyCases);
                    }else{
                        plateau.verifManger(coordx - 48, coordy - 48, noir, emptyCases);
                    }
                    break;
                }
            }
        }
    }
}



int main()
{
     Console* c = NULL; //pointeur console
     c = Console::getInstance();
     c->setColor(COLOR_GREEN); //écriture noir sur fond vert

    char choix;



    while(1){


        //Affichage menu
        cout << endl << "\t*************\n\t** OTHELLO **\n\t*************" << endl<< endl;
        cout << "\t1. Nouvelle partie" << endl;
        cout << "\t2. Continuer" << endl;
        cout << "\t3. Quitter" << endl << endl;

        cin.clear();
        cin >> choix; //recupere le choix utilisateur

        if(choix == '1'){
//            system("cls");
            Nouvelle_Partie();//Appel du sous programme
        }
        else if(choix == '2')
        {
//            system("cls");
//            Continuer();//Appel du sous programme
        }
        else if(choix == '3')
        {
            exit(0); //fin du programme
        }
        else{
            cout << "Vous avez mal saisi la commande";
        }

    }

    return 0;
}

//
//  Move.cpp
//  ProjetDEM
//
//  Created by Remy Broun on 16/04/2017.
//  Copyright © 2017 Remy Broun. All rights reserved.
//

#include "Move.hpp"

void Move::setDirection(Direction dir){
    m_direction = dir;
}

void Move::setCaseDebut(Case debut){
    m_caseDepart = debut;
}

void Move::setCaseFin(Case fin){
    m_caseFin = fin;
}

void Move::setDistance(int dist){
    m_distance = dist;
}

Move::Move(){
    
}

Move::~Move(){
    
}

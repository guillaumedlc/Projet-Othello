//
//  Move.hpp
//  ProjetDEM
//
//  Created by Remy Broun on 16/04/2017.
//  Copyright © 2017 Remy Broun. All rights reserved.
//

#ifndef Move_hpp
#define Move_hpp

#include <stdio.h>
#include "Case.h"


class Move {
    
private:
    Case m_caseDepart;
    Case m_caseFin;
    Direction m_direction;
    int m_distance;
    
public:
    Case getCaseDepart(){return m_caseDepart;}
    Case getCaseFin(){return m_caseFin;}
    Direction getDirection(){return m_direction;}
    int getDistance(){return m_distance;}
    void setDirection(Direction dir);
    void setCaseDebut(Case debut);
    void setCaseFin(Case fin);
    void setDistance(int dist);
    Move();
    Move(Case caseDepart, Case caseFin, Direction direction, int distance):m_caseDepart(caseDepart),m_caseFin(caseFin),m_direction(direction),m_distance(distance){}
    ~Move();
};

#endif /* Move_hpp */

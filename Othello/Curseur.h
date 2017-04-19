#ifndef CURSEUR_H_INCLUDED
#define CURSEUR_H_INCLUDED

class Curseur
{
    protected:

        int m_x,m_y; //coordonnées de la case


    public:

        Curseur();
        Curseur(int _x, int _y);
        ~Curseur();

        int get_x(){return (m_x);}
        int get_y(){return (m_y);}
        void set_x(int _x){m_x =_x;}
        void set_y(int _y){m_y =_y;}
        void xAddOne(){m_x += 1;}
        void yAddOne(){m_y += 1;}
        void xMinusOne(){m_x -= 1;}
        void yMinusOne(){m_y -= 1;}
        void set_xy(int _y,int _x){m_x =_x; m_y =_y;}
        

};

#endif // CASE_H

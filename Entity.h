#ifndef __ENTITY__
#define __ENTITY__

//-----INCLUSIONS DES HEADERS-----------//
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <vector>
#include <stack>
#include <map>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
//--------------------------------------//


class Entity
{
private:


protected:
    sf::RectangleShape shape;
    float moveSpeed = 500.f;


public:
    // Constructeurs & Destructeurs
    Entity();
    virtual ~Entity();

    // Fonctions pour les entités
    virtual void move(const float& dt,const float dir_x, const float dir_y);
    virtual void update(const float& dt);
    virtual void render(sf::RenderTarget& target);

};




#endif //__ENTITY__

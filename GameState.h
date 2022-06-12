#ifndef __GAMESTATE__
#define __GAMESTATE__

#include "State.h"


class GameState:
    public State
{
private:
    //Etat du jeu
    Entity player;

    void initKeyBinds();

public:
    // Constructeur & Destructeur
    GameState(sf::RenderWindow* window, std::map<std::string,int>* supportedKeys);
    virtual ~GameState();

    // Fin du jeu
    void endState();

    //Fonction qui changent l'état du jeu
    void updateInput(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target = NULL);

};

#endif // __GAMESTATE__

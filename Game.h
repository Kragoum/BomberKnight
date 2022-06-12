#ifndef __GAME__
#define __GAME__

#include "GameState.h"

/* Class that act as the game engine */

class Game
{

private:
    // Variables

    // Gestion du temps
    float dt;
    sf::Clock dtClock;

    // Coeur
    sf::RenderWindow* window;
    sf::Event event;
    std::stack<State*> states;
    std::map<std::string,int> supportedKeys;


    // Game objects


    // Fonction d'initialisations
    void initVariables();
    void initWindow();
    void initKeys();
    void initStates();

public:
    // Constructeurs & Destructeurs
    Game();
    virtual ~Game();

    // Accesseurs
    //const bool running();

    // Mise à jour des évenements

    void endApplication();
    void update();
    void updateSFMLEvents();
    void updateDt();

    // Render
    void render();
    void run();

};


#endif // __GAME__

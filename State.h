#ifndef __STATE__
#define __STATE__

#include "Entity.h"

class State
{
private:

protected:
    // Etat de la fenêtre
    sf::RenderWindow* window;

    // Keys for the game
    std::map<std::string,int>* supportedKeys;
    std::map<std::string,int>  keyBinds;

    bool quit;

    // Ressources
    std::vector<sf::Texture> textures;

    // Fonctions
    virtual void initKeyBinds()=0;

public:
    // Constructeurs & Destructeurs
    State(sf::RenderWindow* window, std::map<std::string,int>* supportedKeys);
    virtual ~State();

    //
    const bool& getQuit() const;
    virtual void checkForQuit();
    virtual void endState() =0;

    //
    virtual void updateInput(const float& dt) = 0;
    virtual void update(const float& dt) = 0;
    virtual void render(sf::RenderTarget* target = NULL) = 0;
};


#endif // __STATE__

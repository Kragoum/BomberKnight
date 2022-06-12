#include "Game.h"
#include <iostream>


// Initialisation des fonctions du jeu

void Game::initVariables()
{
    this->window = NULL; // Pas de variables pour l'instant
}

void Game::initWindow()
{
    // Lecture de la résolution d'écran dans le fichier "Window.ini"
    std::ifstream ifs("window.ini");

    std::string title ="None";
    sf::VideoMode window_bounds(800,600);
    unsigned framerate_limit =120;
    bool vertical_sync_enabled = false;

    if(ifs.is_open())
    {
        std::getline(ifs,title);
        ifs >> window_bounds.width >> window_bounds.height;
        ifs >> framerate_limit;
        ifs >> vertical_sync_enabled;

    }

    ifs.close();

    // Création de la fenêtre
    this->window = new sf::RenderWindow(window_bounds, "BomberKnight", sf::Style::Titlebar | sf::Style::Close);

    this->window->setVerticalSyncEnabled(vertical_sync_enabled);
    this->window->setFramerateLimit(framerate_limit);
}

void Game::initKeys()
{
    // Génere
    this->supportedKeys.emplace("Q" , sf::Keyboard::Key::Q);
    this->supportedKeys.emplace("D" , sf::Keyboard::Key::D);
    this->supportedKeys.emplace("Z" , sf::Keyboard::Key::Z);
    this->supportedKeys.emplace("S" , sf::Keyboard::Key::S);

    std::cout << this->supportedKeys.at("A") << "\n";
}

void Game::initStates()
{
    this->states.push(new GameState(this->window, &this->supportedKeys));
}


// Constructeurs et destructeurs

Game::Game()
{
    this->initVariables();
    this->initWindow();
    this->initKeys();
    this->initStates();
}


Game::~Game()
{
    delete this->window;

    while(!this->states.empty())
        delete this->states.top();
        this->states.pop();
}

// Acesseurs

/*
const bool Game::running()
{
    return this->window->isOpen();
}
*/


// Fonctions

/*
void Game::pollEvents()
{
    // Event polling
}*/

void Game::endApplication()
{
 std::cout << "Ending Application !" << "\n";
}

void Game::update()
{
    this->updateSFMLEvents();

    if (!this->states.empty())
    {
        this->states.top()->update(this->dt);

        if(this->states.top()->getQuit())
        {
            this->states.top()->endState();
            delete this->states.top();
            this->states.pop();
        }
    }
    // Application end
    else
    {
        this->endApplication();
        this->window->close();
    }
}



void Game::updateSFMLEvents()
{
     while(this->window->pollEvent(this->event))
    {
        switch(this->event.type)
        {
        case sf::Event::Closed:
            this->window->close();
            break;
        case sf::Event::KeyPressed:
            if(this->event.key.code == sf::Keyboard::Escape)
                this->window->close();
            break;
        }
    }
}

void Game::updateDt()
{
    // Updates the time variable with the time it takes to update and render one frame.
    this->dt = this->dtClock.restart().asSeconds();
}

void Game::render()
{
    //Clear previous objects
    this->window->clear(sf::Color(245,255,255,255));

    //Draw game objects
    // this->window->draw(this->rectangle);

    if(!this->states.empty())
        this->states.top()->render(this->window);
    this->window->display();

}

void Game::run()
{
    while(this->window->isOpen())
    {
        this->updateDt();
        this->update();
        this->render();
    }
}

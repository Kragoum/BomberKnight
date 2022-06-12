#include "GameState.h"

void GameState::initKeyBinds()
{
    &this->keyBinds.emplace("MOVE_UP",   this->supportedKeys->at("Z"));
    &this->keyBinds.emplace("MOVE_LEFT", this->supportedKeys->at("Q"));
    this->keyBinds.emplace("MOVE_DOWN", this->supportedKeys->at("S"));
    this->keyBinds.emplace("MOVE_RIGHT",this->supportedKeys->at("D"));
}

GameState::GameState(sf::RenderWindow* window, std::map<std::string,int>* supportedKeys)
    : State(window, supportedKeys)
{
    this->initKeyBinds();
}

GameState::~GameState()
{

}

void GameState::endState()
{
    std::cout<<"Ending GameState" << "\n";
}

void GameState::updateInput(const float& dt)
{
    this->checkForQuit();

    //Update player inputs ...
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_UP"))))
    this->player.move(dt,  0.f, -2.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_LEFT"))))
    this->player.move(dt, -2.f, 0.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_DOWN"))))
    this->player.move(dt,  0.f, 2.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_RIGHT"))))
    this->player.move(dt,  2.f, 0.f);
}


void GameState::update(const float& dt)
{
    this->updateInput(dt);
    this->player.update(dt);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        std::cout << "A" << "\n";
}

void GameState::render(sf::RenderTarget* target)
{
    this->player.render(target);
}

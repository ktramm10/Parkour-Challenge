//
// Created by battl on 5/24/2024.
//

#ifndef PLATFORMER_ATTEMPT_3_PLAYER_H
#define PLATFORMER_ATTEMPT_3_PLAYER_H
#include "SFML/Graphics.hpp"
#include "Character.h"

class Player : public Character {
public:
    Player(sf::Vector2f pos, sf::Texture& texture, float speed, float jumpHeight);
    ~Player();
    void processInput(float deltaTime);
    void update(float deltaTime) override;
    void draw(sf::RenderWindow &window) override;
    Collider getCollider() override { return Collider(*getSprite()); }
    void onCollision(sf::Vector2f direction);
private:
    sf::Texture playerTexture;
    bool canJump;
    float jumpHeight;
    float gravity;


};


#endif //PLATFORMER_ATTEMPT_3_PLAYER_H

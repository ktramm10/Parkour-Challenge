//
// Created by battl on 5/24/2024.
//

#ifndef PLATFORMER_ATTEMPT_3_COLLIDER_H
#define PLATFORMER_ATTEMPT_3_COLLIDER_H
#include "SFML/Graphics.hpp"
#include <iostream>

class Collider {
public:
    Collider(sf::Sprite& theSprite);
    ~Collider();

    void move(float dx, float dy) { sprite.move(dx, dy);  }
    bool checkCollision(Collider other, sf::Vector2f& direction, float push);
    sf::Vector2f getPosition() { return sprite.getPosition(); }
    sf::Vector2f getHalfSize() { return sprite.getGlobalBounds().getSize() / 2.0f; }
private:
    sf::Sprite& sprite;
};


#endif //PLATFORMER_ATTEMPT_3_COLLIDER_H

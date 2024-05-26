//
// Created by battl on 5/24/2024.
//

#ifndef PLATFORMER_ATTEMPT_3_CHARACTER_H
#define PLATFORMER_ATTEMPT_3_CHARACTER_H
#include "Object.h"
#include "SFML/Graphics.hpp"
#include "Collider.h"

class Character : public Object {
public:
    sf::Vector2f getPosition() { return position; }
    sf::Vector2f getVelocity() { return velocity; }
    sf::Vector2f getSize() { return size; }
    sf::Vector2f getHalfSize() { return size / 2.0f; }
    void setSize(sf::Vector2f theSize) { size = theSize; }
    void setPosition(sf::Vector2f pos) { this->position = pos; }
    void setVelocity(sf::Vector2f vel) { this->velocity = vel; }
    sf::Sprite* getSprite() {return sprite; }
    void setSprite(sf::Sprite *theSprite) { sprite = theSprite; }
    void setSpeed(float theSpeed) {speed = theSpeed; }
    float getSpeed() const { return speed; }
    Collider getCollider() {return Collider(*getSprite()); }
private:
    sf::Vector2f position;
    sf::Vector2f size;
    sf::Vector2f velocity;
    sf::Sprite* sprite;
    float speed;
};


#endif //PLATFORMER_ATTEMPT_3_CHARACTER_H

//
// Created by battl on 5/24/2024.
//

#ifndef PLATFORMER_ATTEMPT_3_GEOMETRY_H
#define PLATFORMER_ATTEMPT_3_GEOMETRY_H
#include "SFML/Graphics.hpp"
#include "Object.h"
#include <list>
#include "Collider.h"

class Player;
class Geometry : public Object {
public:
    void setSprite(sf::Sprite *sprite) { this->sprite = sprite; }
    void update(float deltaTime) override {}
    void draw(sf::RenderWindow &window) override {}
    sf::Sprite* getSprite() { return sprite; }
    bool getCanMove() { return canMove; }
    void setCanMove(bool canMove) {this->canMove = canMove; }
    void setSize(sf::Vector2f theSize) { size = theSize; }
    sf::Vector2f getSize() { return size; }
    static std::list<Geometry*> list;
    static void updateEach(float deltaTime);
    static void drawEach(sf::RenderWindow &window);
    static void checkCollisionEach(Player &player, sf::Vector2f dir, sf::RenderWindow &window);
    Collider getCollider() override {}
    sf::Vector2f getVelocity() { return velocity; }
    void setVelocity(sf::Vector2f vel) { velocity = vel; }
    bool getIsFinish() { return isFinish; }
    void setIsFinish(bool val) { isFinish = val; }

private:
    sf::Sprite* sprite;
    sf::Vector2f velocity;
    bool canMove;
    sf::Vector2f size;
    bool isFinish;

};


#endif //PLATFORMER_ATTEMPT_3_GEOMETRY_H

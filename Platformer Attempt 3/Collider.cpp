//
// Created by battl on 5/24/2024.
//

#include "Collider.h"

Collider::Collider(sf::Sprite& theSprite) : sprite(theSprite) {

}

Collider::~Collider() {

}

bool Collider::checkCollision(Collider other, sf::Vector2f& direction, float push) {

    sf::Vector2f otherPosition = other.getPosition();
    sf::Vector2f otherHalfSize = other.getHalfSize();
    sf::Vector2f thisPosition = getPosition();
    sf::Vector2f thisHalfSize = getHalfSize();

    float deltaX = thisPosition.x - otherPosition.x;
    float deltaY = thisPosition.y - otherPosition.y;

    float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
    float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

    if (intersectX < 0.0f && intersectY < 0.0f)
    {

        if (intersectX > intersectY) {
            if (deltaX > 0.0f) {
                other.move(intersectX * (push / 10), 0.0f);
                direction.x = -1.0f;
                direction.y = 0.0f;
            } else {
                other.move(-intersectX * (push / 10), 0.0f);
                direction.x = 1.0f;
                direction.y = 0.0f;
            }
        }
        else
        {
            if (deltaY > 0.0f) {
                other.move(0.0f, intersectY * (push/7));
                direction.x = 0.0f;
                direction.y = -1.0f;
            } else {
                other.move(0.0f, -intersectY * (push/7));
                direction.x = 0.0f;
                direction.y = 1.0f;
            }
        }
        return true;
    }

    return false;
}


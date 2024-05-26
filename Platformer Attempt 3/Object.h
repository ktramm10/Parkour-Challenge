//
// Created by battl on 5/24/2024.
//

#ifndef PLATFORMER_ATTEMPT_3_OBJECT_H
#define PLATFORMER_ATTEMPT_3_OBJECT_H
#include "SFML/Graphics.hpp"
#include <list>
#include "Collider.h"

class Object {
public:
    virtual void update(float deltaTime) {};
    virtual void draw(sf::RenderWindow &window) {};
    virtual Collider getCollider() {};
};


#endif //PLATFORMER_ATTEMPT_3_OBJECT_H

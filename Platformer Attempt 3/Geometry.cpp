//
// Created by battl on 5/24/2024.
//

#include "Geometry.h"
#include "Player.h"
std::list<Geometry*> Geometry::list = {};

void Geometry::updateEach(float deltaTime) {
    std::list<Geometry*>::iterator it;
    for (it = list.begin(); it != list.end(); it++) {
        (*it)->update(deltaTime);
    }
}

void Geometry::drawEach(sf::RenderWindow &window) {
    std::list<Geometry*>::iterator it;
    for (it = list.begin(); it != list.end(); it++) {
        (*it)->draw(window);
    }
}

void Geometry::checkCollisionEach(Player &player, sf::Vector2f dir, sf::RenderWindow &window) {
    std::list<Geometry *>::iterator it;
    for (it = list.begin(); it != list.end(); it++) {
        if ((*it)->getCollider().checkCollision(player.getCollider(), dir, 2.0f)) {
            player.onCollision(dir);
            if ((*it)->isFinish) {
                window.close();
            }
        }

    }
}

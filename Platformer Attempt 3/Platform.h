//
// Created by battl on 5/24/2024.
//

#ifndef PLATFORMER_ATTEMPT_3_PLATFORM_H
#define PLATFORMER_ATTEMPT_3_PLATFORM_H
#include "SFML/Graphics.hpp"
#include "Geometry.h"
#include "Collider.h"
class Platform : public Geometry {
public:
    Platform(sf::Vector2<float> size, sf::Vector2f position, const sf::Texture& texture, bool isFinish);
    ~Platform();
    void update(float deltaTime) override;
    void draw(sf::RenderWindow &window) override;
    Collider getCollider() override { return Collider(*getSprite()); }
private:
    sf::Texture texture;

};


#endif //PLATFORMER_ATTEMPT_3_PLATFORM_H

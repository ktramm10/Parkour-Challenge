//
// Created by battl on 5/24/2024.
//

#include "Platform.h"
#include <iostream>
Platform::Platform(sf::Vector2<float> size, sf::Vector2f position, const sf::Texture& theTexture, bool isFinish) {
    setIsFinish(isFinish);
    list.push_front(this);
    texture = theTexture;
    setVelocity(sf::Vector2f (0,0));
    setSprite(new sf::Sprite(texture));
    getSprite()->setTextureRect(sf::IntRect(size.x, size.y, size.x, size.y));
    setSize(getSprite()->getGlobalBounds().getSize());
    getSprite()->setOrigin(getSize() / 2.0f);
    getSprite()->setPosition(position);
    if (isFinish) {
        getSprite()->setColor(sf::Color::Red);
    }
}

void Platform::update(float deltaTime) {

}

Platform::~Platform() {

}

void Platform::draw(sf::RenderWindow &window) {
    window.draw(*getSprite());
}

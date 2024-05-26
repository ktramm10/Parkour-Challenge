//
// Created by battl on 5/25/2024.
//
#include "SFML/Graphics.hpp"
#include "Guide.h"
#include "Platform.h"
#include "Player.h"
#include <cmath>

Guide::Guide(Platform& theFinish, Player& thePlayer) : finish(theFinish), player(thePlayer){
    display = true;
    guide = (new sf::RectangleShape(sf::Vector2f (50 , 30)));
    guide->setFillColor(sf::Color::Red);
    guide->setOrigin(guide->getSize() / 2.0f);

    if (!font.loadFromFile("C:\\Users\\battl\\OneDrive\\Documents\\GitHub\\Parkour-Challenge\\Platformer Attempt 3\\Minecraft.ttf"))
        std::cout << " FONT FAILEd" << std::endl;
    text = sf::Text(distanceString, font, 50);
    text.setFillColor(sf::Color::Red);

}

Guide::~Guide() {

}

void Guide::update(float deltaTime) {
    distanceString = "Distance: " + std::to_string((int)distance);
    text.setString(distanceString);
    text.setPosition(player.getSprite()->getPosition().x - 512.0f, player.getSprite()->getPosition().y -512.0f);
    CalculateGuidePosition();
}

void Guide::draw(sf::RenderWindow &window) {
    if (display) {
        window.draw(*guide);
    }
    window.draw(text);

}

void Guide::CalculateGuidePosition() {
    float angle;
    sf::Vector2f displacement = finish.getSprite()->getPosition() - player.getSprite()->getPosition();
    distance = sqrtf(displacement.x * displacement.x + displacement.y * displacement.y);
    display = checkMinDistance(distance);
    sf::Vector2f unitVector = sf::Vector2f(displacement.x / distance, displacement.y / distance);
    if (unitVector.y > 0)
        angle = acos(unitVector.x) * (180 / 3.14159) ;
    else
        angle = -acos(unitVector.x) * (180 / 3.14159) ;
    //std::cout << "ANGLE: " << angle << "   UNIT VECTOR X: " << unitVector.x << "UNIT VECTOR Y" << unitVector.y << std::endl;
    guide->setRotation(angle);
    float scalarA = 300.0f;
    sf::Vector2f guidePosition = player.getSprite()->getPosition() + unitVector * scalarA;
    guide->setPosition(guidePosition);

}

bool Guide::checkMinDistance(float distance) {
    return distance > 500;
}

//
// Created by battl on 5/25/2024.
//

#ifndef PLATFORMER_ATTEMPT_3_GUIDE_H
#define PLATFORMER_ATTEMPT_3_GUIDE_H
#include "SFML/Graphics.hpp"
#include "Object.h"
#include <string>
class Player;
class Platform;
class Guide : Object {
public:
    Guide(Platform& theFinish, Player& thePlayer);
    ~Guide();
    void update(float deltaTime) override;
    void draw(sf::RenderWindow &window) override;
    void CalculateGuidePosition();
    bool checkMinDistance(float distance);


private:
    Platform& finish;
    Player& player;
    sf::RectangleShape* guide;
    float distance;
    sf::Font font;
    sf::Text text;
    bool display;
    std::string distanceString;

};


#endif //PLATFORMER_ATTEMPT_3_GUIDE_H

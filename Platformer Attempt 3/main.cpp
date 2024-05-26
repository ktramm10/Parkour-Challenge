#include <iostream>
#include "SFML/Graphics.hpp"
#include "Player.h"
#include "Platform.h"
#include "Guide.h"

static const float VIEW_HEIGHT = 1028.0f;
static const float SQUARE_HALF_HEIGHT = 64.0f;
static const float SURFACE = 12.0f;
static const float CENTER_X = 256.0f;

void resizeView(const sf::RenderWindow &window, sf::View& view) {
    float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
    view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}

int main() {
    sf::RenderWindow window(sf::VideoMode(512, 512), "Parkour Challenge!");

    sf::View view;
    view.setSize(sf::Vector2f(VIEW_HEIGHT , VIEW_HEIGHT));

    sf::Texture playerTexture;
    playerTexture.loadFromFile("C:\\Users\\battl\\OneDrive\\Documents\\GitHub\\Parkour-Challenge\\Platformer Attempt 3\\PlayerCharacter_Test.png");
    sf::Texture platformTexture;
    platformTexture.loadFromFile("C:\\Users\\battl\\OneDrive\\Documents\\GitHub\\Parkour-Challenge\\Platformer Attempt 3\\Terrain.png");


    Player player(sf::Vector2f(230.0f, SURFACE - player.getSize().y * 2), playerTexture, 200, 300);
    Platform rightWall(sf::Vector2f(20.0f, 2000.0f), sf::Vector2f(1247.0f, 10.0f), platformTexture, false);
    Platform leftWall(sf::Vector2f(20.0f, 2000.0f), sf::Vector2f(-734.0f, 10.0f), platformTexture, false);
    Platform floor(sf::Vector2f(2000.0f, 2000.0f), sf::Vector2f(256.0f, 1012.0f), platformTexture, false);
    Platform square1(sf::Vector2f(128.0f, 128.0f), sf::Vector2f(CENTER_X, SURFACE - (SQUARE_HALF_HEIGHT * (3.0f * 1.5f))), platformTexture, false);
    Platform square2(sf::Vector2f(128.0f, 128.0f), sf::Vector2f(CENTER_X * 2, SURFACE - (SQUARE_HALF_HEIGHT * (5.0f * 1.5f))), platformTexture, false);
    Platform square3(sf::Vector2f(128.0f, 128.0f), sf::Vector2f(CENTER_X - 200, SURFACE - (SQUARE_HALF_HEIGHT * (7.0f * 1.5f))), platformTexture, false);
    Platform square4(sf::Vector2f(128.0f, 128.0f), sf::Vector2f(CENTER_X - 200, SURFACE - (SQUARE_HALF_HEIGHT * (2.0f * 1.5f))), platformTexture,false);
    Platform square5(sf::Vector2f(128.0f, 128.0f), sf::Vector2f(CENTER_X - 400, SURFACE - (SQUARE_HALF_HEIGHT * (9.0f * 1.5f))), platformTexture,false);
    Platform square6(sf::Vector2f(128.0f, 128.0f), sf::Vector2f(CENTER_X - 100, SURFACE - (SQUARE_HALF_HEIGHT * (12.0f * 1.5f))), platformTexture,false);
    Platform square7(sf::Vector2f(128.0f, 128.0f), sf::Vector2f(CENTER_X + 400, SURFACE - (SQUARE_HALF_HEIGHT * (12.0f * 1.5f))), platformTexture, false);
    Platform square8(sf::Vector2f(128.0f, 128.0f), sf::Vector2f(CENTER_X + 700, SURFACE - (SQUARE_HALF_HEIGHT * (15.0f * 1.5f))), platformTexture,false);
    Platform square9(sf::Vector2f(128.0f, 128.0f), sf::Vector2f(CENTER_X + 1150, SURFACE - (SQUARE_HALF_HEIGHT * (17.0f * 1.5f))), platformTexture,false);
    Platform finish(sf::Vector2f(128.0f, 128.0f), sf::Vector2f(CENTER_X + 1725, SURFACE - (SQUARE_HALF_HEIGHT * (17.0f * 1.5f))), platformTexture, true);

    Guide guide(finish, player);

    sf::Clock clock;
    float deltaTime;

    // GAME LOOP
    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();

        // EVENTS
        sf::Event event;
        while(window.pollEvent(event))
        {

        switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::Resized:
                printf("New window with: %i  New window height: %i \n", event.size.width, event.size.height);
                resizeView(window, view);
                break;
        }

        }

        // Update
        player.processInput(deltaTime);
        player.update(deltaTime);
        sf::Vector2f direction;
        guide.update(deltaTime);

        if (abs(player.getSprite()->getPosition().x) > 5000 || abs(player.getSprite()->getPosition().y > 5000) )
            window.close();

        Geometry::checkCollisionEach(player, direction, window);

        view.setCenter(sf::Vector2f(player.getSprite()->getPosition().x, player.getSprite()->getPosition().y));
        window.clear();
        window.setView(view);
        player.draw(window);
        Geometry::drawEach(window);
        guide.draw(window);
        window.display();





    }
}

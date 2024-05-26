//
// Created by battl on 5/24/2024.
//

#include "Player.h"
#include <iostream>
#include <math.h>

Player::Player(sf::Vector2f pos, sf::Texture& texture, float speed, float jumpHeight) {
     playerTexture = texture;
     setSprite(new sf::Sprite(playerTexture));
     setSize(getSprite()->getGlobalBounds().getSize());
     setSpeed(speed);
     this->jumpHeight = jumpHeight;
     gravity = 980.0f;
     getSprite()->setOrigin(getHalfSize());
     getSprite()->setPosition(pos);




}

Player::~Player() {


}

void Player::processInput(float deltaTime) {
    setVelocity(sf::Vector2f (getVelocity().x * 0.2f, getVelocity().y));
    // MOVE RIGHT
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        setVelocity(sf::Vector2f(getVelocity().x + getSpeed(), getVelocity().y));
    }
    // MOVE LEFT
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        setVelocity(sf::Vector2f (getVelocity().x - getSpeed(), getVelocity().y));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canJump) {
        // JUMP
        canJump = false;
        //std::cout << "JUMPED" << std::endl;
        float impulse = -sqrtf(2.0f * gravity * jumpHeight);
        setVelocity(sf::Vector2f(getVelocity().x, impulse));

    }

}

void Player::update(float deltaTime) {
    setVelocity(sf::Vector2f (getVelocity().x, getVelocity().y  +  gravity * deltaTime));
    //std::cout << "VELOCITY X : " << getVelocity().x << "  VELICITY Y: " << getVelocity().y << std::endl;
    getSprite()->move(getVelocity() * deltaTime);

}

void Player::draw(sf::RenderWindow &window) {
    window.draw(*getSprite());
}

void Player::onCollision(sf::Vector2f direction) {
   if (direction == sf::Vector2f(1,0))
   {

   }
   else if (direction == sf::Vector2f (-1,0))
   {

   }
   else if (direction == sf::Vector2f (0, -1))
   {
       setVelocity(sf::Vector2f (getVelocity().x, 0.0f));
       canJump = true;
   }
   else
   {
       setVelocity(sf::Vector2f (getVelocity().x, 0.0f));
   }
}

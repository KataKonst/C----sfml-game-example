#pragma once
#include "Particle.hpp"
#include <SFML/Graphics.hpp>
class Dusman{


 private:
 sf::Texture textura;
 sf::Sprite sprite;


public:
int ht=0;
int n=0;
int desen=0;

   Dusman()
   {

       if (!textura.loadFromFile("dusman.png"))
      {

      }
   }


        void hit(sf::RenderWindow  &window,ParticleSystem &particles,sf::Clock &clock){

            ht=1;
            desen=1;

           }

       sf::Sprite GetSprite()
       {

           return sprite;
       }
       void  mv()
       {
           sprite.move(0,3);
       }
       void  mv2()
       {
           sprite.move(0,10);
       }
        void SetPos(const sf::Vector2f &v)
    {

        sf::Sprite sf;
        sf.setTexture(textura);
        sf.setPosition(v);
        sprite=sf;


    }
    int Colid(int max)
    {
        if(sprite.getPosition().y>=max)
            return 1;
        return 0;
    }
    void rotatie()
    {
        sprite.rotate(15);
    }


};

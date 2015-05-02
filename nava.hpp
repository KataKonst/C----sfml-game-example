#include <SFML/Graphics.hpp>
#pragma once;
class Nava{


 private:
 sf::Texture textura;
 sf::Sprite sprite;

 int x;
 int y;
 public:
      int ht=0;

     void hit()
     {
         ht=1;
     }
  Nava(sf::RenderWindow &wd)
 {
     //window=wd;
     x=wd.getSize().x;
     y=wd.getSize().y;
    if (!textura.loadFromFile("nava.gif"))
      {

      }
        sprite.setTexture(textura);
        sprite.setPosition(375,400);

 };
 private:
      void RMove()
      {
        sprite.move(10,0);

      }
       void LMove()
      {
        sprite.move(-10,0);

      }
        void UMove()
      {
        sprite.move(0,-10);

      }
        void DMove()
      {
        sprite.move(0,10);

      }

    public:
       void KeyMove()
       {

           if(GetAsyncKeyState(VK_RIGHT)&&sprite.getPosition().x<=x-70)
              RMove();
           if(GetAsyncKeyState(VK_LEFT)&&sprite.getPosition().x>=0)
              LMove();
           if(GetAsyncKeyState(VK_UP)&&sprite.getPosition().y>=0)
              UMove();
           if(GetAsyncKeyState(VK_DOWN)&&sprite.getPosition().y<=y-100)
              DMove();
       }
       sf::Sprite GetSprite()
       {

           return sprite;
       }

};

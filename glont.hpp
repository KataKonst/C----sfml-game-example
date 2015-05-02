#include <iostream>
#include  "Dusman.hpp"
#include <SFML/Graphics.hpp>
#include "nava.hpp"
using namespace std;
class glont{

public:
sf::CircleShape shape;
sf::Sprite sprite;
sf::Texture textura;


virtual void load()
{
    if (!textura.loadFromFile("rocketc.png"))
      {

      }
        sprite.setTexture(textura);
}
public:
void mv()
    {
        sprite.move(0,-10);
    }
    void mv2()
    {
        sprite.move(0,+10);
    }
   virtual void SetPos(const sf::Vector2f &v)
    {

        sprite.setPosition(v);

    }

sf::Sprite GetShape()
{
    return sprite;
}
int AxaX(int max)
{
    if(sprite.getPosition().y<=0&&sprite.getPosition().y>=-9){

    cout<<sprite.getPosition().y<<" f    ";
    return 1;
    }
    return 0;
}
int colid(Dusman en[30],int nr,int &n,sf::RenderWindow &windows,ParticleSystem &particles,sf::Clock clock,int &scor)
{
    for(int i=0;i<=nr;i++)
    {
        if(sprite.getPosition().y>(int)en[i].GetSprite().getPosition().y-50
            &&sprite.getPosition().y<(int)en[i].GetSprite().getPosition().y+50
           &&sprite.getPosition().x<(int)en[i].GetSprite().getPosition().x+100
          &&sprite.getPosition().x>(int)en[i].GetSprite().getPosition().x-10)
                     {    if(en[i].ht==0){
                          en[i].hit(windows,particles,clock);
                          scor++;
                     }

                     }

    }
}
int colidP(Nava nv)
{

        if(sprite.getPosition().y>(int)nv.GetSprite().getPosition().y-10
            &&sprite.getPosition().y<(int)nv.GetSprite().getPosition().y+50
           &&sprite.getPosition().x<(int)nv.GetSprite().getPosition().x+90
          &&sprite.getPosition().x>(int)nv.GetSprite().getPosition().x-10)
                     {
                          nv.hit();
                          return 1;

                     }
                     return 0;

    }


};

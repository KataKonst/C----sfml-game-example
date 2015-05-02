#include <SFML/Graphics.hpp>
#include <iostream>
#include<windows.h>
#include "glont.hpp"
#include  "nava.hpp"
#include "Dusman.hpp"
#include <stdio.h>
#include  <time.h>
#include <stack>
#include "Particle.hpp"
#include "Dfire.hpp"
#include  <string.h>
using namespace std;


int main()
{
    srand(0);
    sf::RenderWindow window(sf::VideoMode(750, 500), "dsasd");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
Nava nv1(window);
glont fire[100],aux;
Dusman en[30];
int dnr=0;
Dfire dfire[100];
int nr=0,nrd=0;
    int ok=1;
     int c=0;
int n=0;
int vieti=4;
int cvieti=0;
sf::Texture textura;
sf::Sprite sprite;
sf::Text txt;
int scor=0;
//sprite.setScale(800,500);

ParticleSystem particles(100);
   sf::Clock clock;
   sf::Font font;

if (!font.loadFromFile("sansation.ttf"))
{
}

if (!textura.loadFromFile("space.jpg"))
      {
           cout<<"DASDSDSD";
      }
        sprite.setTexture(textura);
for(int i=0;i<100;i++){
  dfire[i].rot();
  dfire[i].load();
  fire[i].load();
}

    while (window.isOpen())
    {
        Sleep(1000/15);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
nv1.KeyMove();
if(GetAsyncKeyState(VK_SPACE)&&nr<=10)
  {
     fire[nr].SetPos(nv1.GetSprite().getPosition());

          nr++;

  }

                  window.draw(sprite);
                  if(nrd==0)
                  {
                      dnr=0;
                      nrd=rand()%5+2;
                       for(int i=1;i<=nrd;i++)
                       {
                           sf::Vector2f v;
                           v.x=rand()%(window.getSize().x-90);
                           v.y=-50;
                           en[i].SetPos(v);
                           en[i].ht=0;


                       }


             }
                 n=0;
c=0;

      for(int i=1;i<=dnr;i++)
{
    dfire[i].mv2();
    window.draw(dfire[i].GetShape());
     if(dfire[i].GetShape().getPosition().y>=0&&i!=nr)
       if(dfire[i].colidP(nv1)&&dfire[i].hit==0){
         vieti--;
         dfire[i].hit=1;

       }

}
cvieti=0;
      for(int i=1;i<=nrd;i++)
      {
          if(en[i].Colid(window.getSize().y)&&en[i].ht!=1)
          {
              nrd=0;
              vieti--;
              break;
          }
         if(en[i].Colid(window.getSize().y))
          {
              c++;

          }

          if(!en[i].ht){
          en[i].mv();
                    window.draw(en[i].GetSprite());

          cvieti++;
          cout<<en[i].GetSprite().getPosition().x<<"\n";
          }
          if(en[i].ht==1){
                en[i].rotatie();
      window.draw(en[i].GetSprite());
en[i].mv2();
n++;
          }
if((rand()%60+1==4)&&en[i].ht==0)
          {
               dfire[dnr].SetPos(en[i].GetSprite().getPosition());
               dnr++;
               dfire[nr].hit=0;
          }







      }

      if((n==nrd&&c==n))
      {
      nrd=0;
       }

if(nr!=0)
    ok=1;
for(int i=0;i<nr;i++)
{
    fire[i].mv();
    window.draw(fire[i].GetShape());
   if(fire[i].GetShape().getPosition().y>=0&&i!=nr)
      ok=0;
      fire[i].colid(en,nrd,n,window,particles,clock,scor);

}

if(ok==1&&nr>=10)
     nr=0;
             window.draw(nv1.GetSprite());


       char f[300];
        sprintf(f,"%d",scor);
        txt.setPosition(650,30);
        window.draw(txt);
        txt.setFont(font);
        txt.setCharacterSize(24);
        txt.setColor(sf::Color::White);
        txt.setStyle(sf::Text::Bold);
        char s[100]="Scor:";
         strcat(s,f);
                 txt.setString(s);

        window.draw(txt);
        char f1[300];
        sprintf(f1,"%d",vieti);
       sf::Text tx;
        tx.setPosition(650,50);
        window.draw(txt);
        tx.setFont(font);
        tx.setCharacterSize(24);
        tx.setColor(sf::Color::White);
        tx.setStyle(sf::Text::Bold);
        char s1[100]="Vieti:";
         strcat(s1,f1);
         tx.setString(s1);

        window.draw(tx);
        window.display();
        if(vieti<=0)
        {
            while(vieti<=0)
            {
                Sleep(1000);
                if(GetAsyncKeyState(VK_SPACE))
                {
                    scor=0;
                    vieti=4;
                    nrd=0;
                }
            }
        }

                window.clear();


    }

    return 0;
}


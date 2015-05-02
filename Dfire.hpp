
class Dfire: public glont{

public:
    int hit=0;
  void SetPos(const sf::Vector2f &v)
    {

        sprite.setPosition(v.x+40,v.y);

    }
    void load()
    {
            if (!textura.loadFromFile("missile.gif"))
      {

      }
        sprite.setTexture(textura);

    }
    void rot()
    {
                sprite.rotate(90);

    }






};

#include<iostream>
#include<SFML/Graphics.hpp>
using namespace std;
using namespace sf;
RenderWindow window(VideoMode(1500, 1500), "practice_sfml");//創造視窗
int main()
{
  while (window.isOpen())
  {
      Event event;
      while(window.pollEvent(event))
      {     
      
        if(event.type == Event::Closed)window.close();
        
        window.clear(Color::White);//清除背景
    
        RectangleShape rectangle(Vector2f(120.f, 50.f));//創造長方形
        rectangle.setSize(Vector2f(100.f, 100.f));//調整大小
        shape.setFillColor(Color::Green);//設定顏色
        rectangle.move(5.0f, 5.0f);//物體移動
        
        window.draw(rectangle);//繪製圖形
        
        window.display();//視窗更新
        
      
      }
  }

  return 0;
}

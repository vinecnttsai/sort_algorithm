#include<iostream>
#include<SFML/Graphics.hpp>
using namespace std;
using namespace sf;
RenderWindow window(VideoMode(1500, 1500), "practice_sfml");//創造視窗
int main()
{
  RectangleShape rectangle(Vector2f(120.f, 50.f));//創造長方形
  rectangle.setSize(Vector2f(100.f, 100.f));//調整大小
  rectangle.setFillColor(Color::Green);//設定顏色
  rectangle.setPosition(Vector2f(650.0f,650.0f));//設定位置
  float velocity_x=5.0f,velocity_y=5.0f;
  while (window.isOpen())
  {
      Event event;
      while(window.pollEvent(event))
      {     
      
        if(event.type == Event::Closed)window.close();
        
        window.clear(Color::White);//清除背景
    
        Vector2f position=rectangle.GetPosition();
        if(position.x<=0||position.x>=1500)velocity_x*=-1;
        if(position.y<=0||position.y>=1500)velocity_y*=-1;
        rectangle.move(velocity_x, velocity_y);//物體移動
        
        window.draw(rectangle);//繪製圖形
        
        window.display();//視窗更新
        
      
      }
  }

  return 0;
}

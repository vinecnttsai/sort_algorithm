#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <sstream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <SFML/Graphics.hpp>
#include <unistd.h>
using namespace std;
using namespace sf;
RectangleShape r;

const int pia=2160,pib=1080,n=50,max_=2000;

float spacea=float(pia)/n;

int a[n];
   
RenderWindow window(VideoMode(pia, pib), "My window");
void print_array()
{
    int i;
    window.clear(Color::White);
    for(i=0;i<n;i++)
    {
        float percent=(float(a[i])/max_);
        r.setPosition(i*spacea,pib-percent*pib);
        r.setSize(Vector2f(spacea,percent*pib));
        r.setFillColor(Color::Black);
        window.draw(r);
    }
    window.display();
}
void randomarray(int a[],int n,int max)
{
    int i;
    srand(5);
    for(i=0;i<n;i++)a[i]=rand()%max_;
}
void bubblesort(int a[],int n,int start)
{
    int i,k;
    for(i=start;i<n;i++)
    {
        for(k=start;k<n-i;k++)
        {
            usleep(50);
            print_array();
            if(a[k]>a[k+1])swap(a[k],a[k+1]);

        }
    }

}
int main()
{
    bool isstart=false;
    randomarray(a,n,max_);
    while (window.isOpen())
    {
       
        Event event;

        while (window.pollEvent(event))
        {
           
            if (event.type == Event::Closed)
                window.close();
        }
        print_array();
        if(!isstart)
        {
            bubblesort(a,n,0);
            isstart=true;
        }
    }
   
    return 0;
}

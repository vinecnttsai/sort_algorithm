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
void selectionsort(int a[],int n,int start)
{
    int i,k;
    for(i=start;i<n-1;i++)
    {
        int min=i;
        print_array();
        usleep(5000);
        for(k=i+1;k<n;k++)
        {
            if(a[k]<a[min])
            {
                min=k;
            }
        }
        if(min!=i)
        {
            swap(a[i],a[min]);
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
            selectionsort(a,n,0);
            isstart=true;
        }
    }
   
    return 0;
}

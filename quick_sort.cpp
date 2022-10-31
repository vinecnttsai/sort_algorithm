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
int paritition(int a[],int left,int right)
{
    int pivot = a[left];
    print_array();
    usleep(5000);
    while(left<right)
    {
        while (left<right&&a[right]>=pivot)
        {
             --right;
        }
        a[left]=a[right];
        while (left<right&&a[left]<=pivot)
        {
            ++left;
        }
        a[right]=a[left];
    }
    a[left]=pivot;
    return left;
}
void quicksort(int a[],int left,int right)
{
    if (left<right)
    {
         print_array();
         int pivot = paritition(a, left, right);
         quicksort(a, left, pivot-1);
         quicksort(a, pivot+1, right);
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
            quicksort(a,0,n);
            isstart=true;
        }
    }
   
    return 0;
}

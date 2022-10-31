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
void merge(int a[],int l,int m,int r)
{
    int n1=m-l+1;
    int n2=r-m;
    int c[n1],d[n2],i;
    for(i=0;i<n1;i++)c[i]=a[l+i];
    for(i=0;i<n2;i++)d[i]=a[m+1+i];
    int j=0,z=0,k=l;
    usleep(5000);
    print_array();
    while(z<n1&&j<n2)
    {
        if(c[z]<d[j])
        {
            a[k]=c[z];
            k++;
            z++;
        }
        else
        {
            a[k]=d[j];
            j++;
            k++;
        }
    }
    while(z<n1)
    {
        a[k]=c[z];
        z++;
        k++;
    }
    while(j<n2)
    {
        a[k]=d[j];
        j++;
        k++;
    }
}
void mergesort(int a[],int l,int r)
{
    if(l<r)
    {
        int m=(l+r)/2;
        mergesort(a, l, m);
        mergesort(a, m+1, r);
        merge(a,l,m,r);
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
            mergesort(a,0,n);
            isstart=true;
        }
    }
   
    return 0;
}

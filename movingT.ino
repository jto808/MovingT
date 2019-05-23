#include <MeggyJrSimple.h>    // Required code, line 1 of 2.

int color;
int letter;
int counter;

struct Point
{
  int x;
  int y;
  int color;
};

Point p1={2,7,1};
Point p2={3,7,2};
Point p3={4,7,3};
Point p4={5,7,4};
Point p5={6,7,5};
Point p6={4,6,6};
Point p7={4,5,7};
Point p8={4,4,8};
Point p9={4,3,9};
Point p10={4,2,12};

Point points[] = {p1,p2,p3,p4,p5,p6,p7,p8,p9,p10};

void setup()                    // run once, when the sketch starts
{
  MeggyJrSimpleSetup();  
 color = 1;
 letter = 0;
 counter = 1;
}


void loop()
{
  drawT();
  DisplaySlate();
  moveT();
  ClearSlate();
}
// // counter++;
// // if (counter > 100)
//  //{
//  .. // counter = 1;
//  }

void moveT()
{  
  CheckButtonsPress();
  for (int i =0; i<8; i++)
  {
     if (Button_B)
     {
      color = random(8) + 1;
     }
     if (Button_Left)
     {
     if (points [i].x > 0)
     {
        points[i].x--;    
     }
      else
      {
      points[i].x = 7;
      }
     }
     if (Button_Up)
     {
     if (points [i].y < 8)
    {
      points[i].y++;
    }
    else
    {
      points[i].y = 0;
    }
    }
    if (Button_Right)
    {
      if (points [i].x < 8)
      {
         points[i].x++;
      }
    else
    {
      points[i].x = 0;
    }
    }
    if (Button_Down)
    {
       if (points [i].y > 0)
      {
        points[i].y--;
      }
      else 
      {
        points[i].y=7;
      }
    }
    if (Button_B)
    {
      if (color>1)
      {
        color--;
      }
    }
    if (Button_A)
    {
       if (color<7)
     {
        color++;
     }
    }
  }
} 


void drawT() {
  for (int i=0;i<8; i++)
  {
    DrawPx(points[i].x,points[i].y,points[i].color);
  }
}

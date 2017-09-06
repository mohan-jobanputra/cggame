#include <iostream.h>
#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <stdlib.h>

int score=0;
int nscore=0;

void gline()
{
  line(0,getmaxy()-100,getmaxx(),getmaxy()-100);  //groundline
}

void triangle(int x=0)
{
	line(20+x,getmaxy()-100,25+x,getmaxy()-120);
	line(25+x,getmaxy()-120,30+x,getmaxy()-100);
}

int main()
{

	int gd = DETECT, gm;
	int i, x, y, flag=0;
	initgraph(&gd, &gm, "C:\\TC\\BGI");

 /* get mid positions in x and y-axis */
	x = getmaxx()/2;
	y = 30;
   //int q= 200;
	char ch;
	while (1) {


		ch=getch();
		if (ch=='q')
		{
			return 0;
		}
		if(y >= getmaxy()-115 || y <= 30 || x < 0 || x  > getmaxx()){
			flag = !flag;
			

		}
     /* draws the gray board */
		setcolor(RED);
		gline();
		
		triangle();
		triangle(80);
		triangle(160);
		triangle(240);
		triangle(320);
		triangle(400);
		triangle(480);
		
		setfillstyle(SOLID_FILL, RED);
		circle(x, y, 15);
		floodfill(x, y, RED);

 /* delay for 50 milli seconds */
		delay(40);

 /* clears screen */
		cleardevice();
		if(flag){
			y = y + 5;
			if (ch>110)
				x = x + 2;
			else
				x = x - 2;
		} else {
			y = y - 5;
			if (ch>110)
				x = x + 2;
			else
				x = x - 2;
		}
		if(y >= getmaxy()-115 && y <= getmaxy()){
			if(x>=20-15 && x<=30+15){
				nscore--;score-=2;
			}
			else if(x>=100-15 && x<=110+15){ //100 110
				nscore--;score-=2;}
			else if(x>=180-15 && x<=190+15){ //100 110
				nscore--;score-=2;}
			else if(x>=260-15 && x<=270+15){ //260 270
				nscore--;score-=2;}
			else if(x>=340-15 && x<=350+15){
				nscore--; score-=2;}
			else if(x>=420-15 && x<=430+15){ //260 270
				nscore--;score-=2;}
			else if(x>=500-15 && x<=510+15){ //260 270
				nscore--;score-=2;}
			score=score++;
		}
		gotoxy(60,20);
		cout<<"Score: "<<score<<endl;
		cout<<"NScore: "<<nscore;
	}

	getch();
	closegraph();
	return 0;
}
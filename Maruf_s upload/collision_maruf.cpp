#include "iGraphics.h"
#include<iostream>
#include<string.h>
using namespace std;

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
int mposx, mposy;
int xBox = 10, yBox = 150, dxBox = 100, dyBox =100;
int xBox2 = 400, yBox2 = 150, dxBox2 = 100, dyBox2 = 100;
int r = 255, g = 255, b = 255;
int r1 = 255, g1 = 255, b1 = 255;


char bot[6][100] = { "sword\\SwordFall21.bmp","sword\\SwordFall22.bmp","sword\\SwordFall23.bmp","sword\\SwordFall24.bmp","sword\\SwordFall25.bmp","sword\\SwordFall26.bmp" };

int i = 0,lifetimebot=100000;

void collisionCheck();
void iDraw()
{
	iClear();
	iSetColor(r1, g1, b1);
	iShowImage(0, 0, 1200, 600, iLoadImage("bg.bmp"));
	//iShowImage(xBox, yBox, dxBox, dyBox,iLoadImage("HeroRun-1.bmp"));
	iShowBMP2(xBox, yBox, "Swordmaaaa.bmp", 0);
	iSetColor(r, g, b);
	iShowBMP2(xBox2, yBox2, bot[i],0);
	collisionCheck();
	//collisionCheck();
	//iFilledRectangle(1000, 700, 100, 50);

	iFilledRectangle(20, 100, (lifetimebot), 50);

}





/*function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/


void iMouseMove(int mx, int my)
{
	
}
//*******************************************************************ipassiveMouse***********************************************************************//
void iPassiveMouseMove(int mx, int my)
{
	mposx = mx;
    mposy=my;
	if (mx == 20){
		r = 255;
		g = 0;
		b = 0;
		cout << "Yahoo" << endl;
	}
	//else{
		//r = 255;
		//g = 255;
		//b = 255;
	//}


}

void iMouse(int button, int state, int mx, int my)
{
	
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		xBox += mx-(xBox+dxBox);
		yBox += my - (yBox+dyBox);
		collisionCheck();
		
	}
	
	
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		i = 0;
		xBox = 10;
		yBox = 150;
		r = 255;
		g = 255;
		b = 255;
	}
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/


void iKeyboard(unsigned char key)
{
	if (key == '\r')
	{
		
	}
	
	
}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	
	if (key == GLUT_KEY_RIGHT)
	{
		xBox += 10;
		collisionCheck();
	}
	if (key == GLUT_KEY_LEFT)
	{
		xBox -= 10;
		collisionCheck();
	}
	
	if (key == GLUT_KEY_UP)
	{
		yBox += 10;
		collisionCheck();
	}
	if (key == GLUT_KEY_DOWN)
	{
		yBox -= 10;
		collisionCheck();
	}
	
}

void collisionCheck(){
	if (xBox + dxBox > xBox2 && xBox< (xBox2 + dxBox2) && (yBox + dyBox) > yBox2 && yBox < (yBox2 + dyBox2)){
		r = rand() % 255;
		g = rand() % 255;
		b = rand() % 255;
		//strcpy(bot , "Hero-Run-1.png");
		i ++;
		lifetimebot -= 10;
		if (i >= 5)
			i = 0;
		//cout << "YES" << endl;
	}
	else{
		r = 255;
		g = 255;
		b = 255;
	}
}

int main()
{
	///srand((unsigned)time(NULL));
	iInitialize(1200, 600, "Project Title");
	///updated see the documentations
	iStart();
	return 0;
}
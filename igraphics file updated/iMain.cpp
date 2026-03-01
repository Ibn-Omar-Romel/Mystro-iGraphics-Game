#include "iGraphics.h"
#include<iostream>
using namespace std;

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
int hx = 10, hy = 150, hDx = 150, hDy = 150;
int vx =1000, vy = 150, vDx = 150, vDy = 150;
//char bot[10][100] = { "br.bmp", "hrb.bmp" };
int i = 0;
char bot[100] = "br.bmp";

void iDraw()
{
	iClear();
	
	iShowImage(hx, hy, hDx, hDy, iLoadImage("hrb.bmp"));
	iShowImage(vx, vy, vDx, vDy, iLoadImage(bot));
	collisionCheck();
	

	



	//iFilledRectangle(10, 10, 100, 100);
	//iSetColor(255, 255, 255);

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
	
}

void iMouse(int button, int state, int mx, int my)
{
	
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{

		
	}
	
	
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
	}
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/


void iKeyboard(unsigned char key)
{
	if (key == 'u')
	{
		hy += 10;
	}
	if (key == 'd')
	{
		hy -= 10;
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
		hx += 10;
		
		collisionCheck();
	}
	if (key == GLUT_KEY_LEFT)
	{
		hx -= 10;
		
		collisionCheck();
	}
	//if (key == GLUT_KEY_UP)
	//{
	//	hy += 10;
//
	//	collisionCheck();
	//}
	//if (key == GLUT_KEY_DOWN)
	//{
	//	hy -= 10;

	//	collisionCheck();
//	}
	
	
	
}
void collisionCheck(){
	if ((hx + hDx) > vx && hx<(vx + vDx) && (hy + hDy) > vy && hy < (vy + vDy)){
		//strcpy(bot, "hrb.bmp");
		//iSetColor(255, 255, 255);
		cout << "Collied" << endl;
		

	}
}


int main()
{
	///srand((unsigned)time(NULL));
	iInitialize(1600, 800, "Project Title");
	///updated see the documentations
	iStart();
	return 0;
}

#include "iGraphics.h"

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
bool standPosition = true;
int standCounter = 0;
int cindex = 0;
int cindex1 = 0;
char run[6][100] = { "henRun\\hr1.bmp", "henRun\\hr2.bmp", "henRun\\hr3.bmp", "henRun\\hr4.bmp", "henRun\\hr5.bmp", "henRun\\hr6.bmp"};
char runb[6][100] = { "henBackRun\\hbb1.bmp", "henBackRun\\hbb2.bmp", "henBackRun\\hbb3.bmp", "henBackRun\\hbb4.bmp", "henBackRun\\hbb5.bmp", "henBackRun\\hbb6.bmp" };
int cDx = 0, cDy = 0;  //change of axis
int cx = 100, cy = 50;//axis

int move = 0;  ///shift move right = 0 & left =1

void iDraw()
{
	iClear();
	//iFilledRectangle(10, 10, 100, 100);
	//iSetColor(255, 255, 255);
	iShowBMP(0, 0, "bg.bmp");  //background
	
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
		move = 0;
		standPosition = false;
		iSetTimer(5, movement);
	}
	if (key == GLUT_KEY_LEFT)
	{
		move = 1;
		standPosition = false;
		iSetTimer(5, movement);
	}
	
	if (key == GLUT_KEY_DOWN)
	{
		standPosition = 1;
	}
	
}


///For delaying image called by set timer.


void movement(){
	if (move == 0 ){
		standPosition = false;
		//move = 0;
		cDx += 10;
		cindex++;
		if (cindex >= 6){
			cindex = 0;
		}
		iShowBMP2(cx + cDx, cy + cDy, run[cindex], 0);

	}

	else if (move == 1){
		standPosition = false;
		//move = 1;
		cDx -= 10;
		cindex1++;
		if (cindex1 >= 6){
			cindex1 = 0;
		}
		iShowBMP2(cx + cDx, cy + cDy, runb[cindex1], 0);
	}
	//else if (standPosition==true){
		//iShowBMP2(cx + cDx, cy + cDy, "bg.bmp", 0);
	//}


}





int main()
{
	///srand((unsigned)time(NULL));
	iInitialize(1200, 600, "Project Title");
	///updated see the documentations
	iStart();
	return 0;
}
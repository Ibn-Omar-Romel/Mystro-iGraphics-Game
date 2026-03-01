#include "iGraphics.h"
#define screenwidth 1600
#define screenheight 800
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://

struct butonCordinate{
	int x;
	int y;
}bCordinate[8];

char button[10][100] = { "About.png", "Exit.png", "Highscore.png", "Instruction.png", "Menu.png", "New-Game.png", "Play.png", "Weapon.png" };

int gameState = 0;
void iDraw()
{
	iClear();
	
	
	
	if (gameState == 0){

		//iShowBMP2(0, 0, "bg-1.bmp", 0);
		iShowBMP2(0, 0, "eric-_j-08213.bmp", 0);
		
	}
	iShowImage(-450, 430, 1200.9665, 560.9910, iLoadImage("Menu.png"));
	iShowImage(200, -140, 1200.9665, 560.9910, iLoadImage("About.png"));
	iShowImage(800, 430, 1200.9665, 560.9910, iLoadImage("Exit.png"));
	iShowImage(200, 40, 1200.9665, 560.9910, iLoadImage("Highscore.png"));
	iShowImage(200, -50, 1200.9665, 560.9910, iLoadImage("Instruction.png"));
	iShowImage(200, 130, 1200.9665, 560.9910, iLoadImage("New-Game.png"));
	iShowImage(200, 220, 1200.9665, 560.9910, iLoadImage("Play.png"));
	

}







void iMouseMove(int mx, int my)
{
	
}
//*******************************************************************ipassiveMouse**********************************************************************//
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




void iKeyboard(unsigned char key)
{
	if (key == '\r')
	{
		
	}
	
	
}


void iSpecialKeyboard(unsigned char key)
{

	
	if (key == GLUT_KEY_RIGHT)
	{
				
	}
	if (key == GLUT_KEY_LEFT)
	{
		
	}
	
	if (key == GLUT_KEY_HOME)
	{
		
	}
	
}


int main()
{
	//int sum = 0;
	//for (int i = 7; i >= 0; i--){
		//bCordinate[i].x = 50;
		//bCordinate[i].y = sum;
		//sum += 150;
	//}
	
	iInitialize(screenwidth, screenheight, "Project Title");
	
	iStart();
	return 0;
}
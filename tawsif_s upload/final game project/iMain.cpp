#include "iGraphics.h"
#define screenwidth 1600
#define screenheight 800
#include<string>
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://

struct butonCordinate{
	int x;
	int y;
}bCordinate[8];

char button[10][100] = { "About.png", "Exit.png", "Highscore.png", "Instruction.png", "Menu.png", "New-Game.png", "Play.png", "Weapon.png" };

int gameState = 0;

char cStand[30] = /*{"Hero-Idle-1~1.bmp"};*/{ "black-2.bmp" };
//char cWalk[1][100] = {"redbg.bmp"};
char cRun[6][40] = { "HeroRun-1.bmp", "HeroRun-2.bmp", "HeroRun-3.bmp", "HeroRun-4.bmp", "HeroRun-5.bmp", "HeroRun-6.bmp"};

int cCordinateX = 0;
int cCordianteY = 100;
int cIndex = 0;
char str[100];

bool standPosition = true;
int standCounter = 0;

int indexNumber = 0;


void iDraw()
{
	iClear();
	iShowBMP2(0, 0, "Name1.bmp", 0);//name input page pic	
	//iShowBMP2(0, 0, "starting page.bmp", 0);//starting game pic

	//iShowImage(0, 0, 500, 500, iLoadImage("056.png"));
	iText(700, 300, str, GLUT_BITMAP_TIMES_ROMAN_24);
	

	
	//iShowBMP2(0, 0, cRun[cIndex], 255);
	
	//if (gameState == 0){

		
		
		
	//}
	/*
	menu codes

	iShowImage(-450, 430, 1200.9665, 560.9910, iLoadImage("Menu.png"));
	iShowImage(200, -140, 1200.9665, 560.9910, iLoadImage("About.png"));
	iShowImage(800, 430, 1200.9665, 560.9910, iLoadImage("Exit.png"));
	iShowImage(200, 40, 1200.9665, 560.9910, iLoadImage("Highscore.png"));
	iShowImage(200, -50, 1200.9665, 560.9910, iLoadImage("Instruction.png"));
	iShowImage(200, 130, 1200.9665, 560.9910, iLoadImage("New-Game.png"));
	iShowImage(200, 220, 1200.9665, 560.9910, iLoadImage("Play.png"));
	*/
	

	if (!standPosition){
		iShowBMP2(cCordinateX, cCordianteY, cRun[cIndex], 255);
		standCounter++;
		if (standCounter >= 20){

			standCounter = 0;
			cIndex = 0;
			standPosition = true;
		}

	}
	else{
		iShowBMP2(cCordinateX, cCordianteY, cStand, 0);
	

	}

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
//TAKING INPUT(NAME)
{
	if (key != '\b')
	{
		str[indexNumber] = key;
		indexNumber++;
		str[indexNumber] = '\0';
	}
	else{
		if (indexNumber <= 0)
			indexNumber = 0;
		else
			indexNumber--;
		str[indexNumber] = '\0';
	}
	
}


void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_LEFT)
	{
		cCordinateX -= 10;

		cIndex--;

		if (cIndex < 4)
			cIndex = 0;

		standPosition = false;
	}

	
	else if (key == GLUT_KEY_RIGHT)
	{
		cCordinateX += 10;

		cIndex++;

		if (cIndex >= 5)
			cIndex = 0;

		standPosition = false;
		
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
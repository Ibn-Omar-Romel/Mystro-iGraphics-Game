#include "iGraphics.h"
#define screenwidth 1600
#define screenheight 800
#include<string>
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://

struct butonCordinate{
	int x;
	int y;
}bCordinate[20];

char button[10][100] = { "About.png", "Exit.png", "Highscore.png", "Instruction.png", "Menu.png", "New-Game.png", "Play.png", "Weapon.png" };

void collisionCheck();

int gameState = 0;

char cStand[30] = { "black-2.bmp" };
char cRun[6][60] = { "hr1.bmp", "hr2.bmp", "hr3.bmp", "hr4.bmp", "hr5.bmp", "hr6.bmp" };//hero forward run
char cBack[6][20] = { "hbb1.bmp", "hbb2.bmp", "hbb3.bmp", "hbb4.bmp", "hbb5.bmp", "hbb6.bmp" };//hero bacward run

//char cBack[3][20] = { "hb1.bmp", "hb2.bmp", "hb3.bmp" };//hero backward run
char bRun[6][40] = { "HeroRun-1.bmp", "HeroRun-2.bmp", "HeroRun-3.bmp", "HeroRun-4.bmp", "HeroRun-5.bmp", "HeroRun-6.bmp"};//bot run
char ckop[5][40] = { "k1.bmp", "k2.bmp", "k3.bmp", "k4.bmp", "k5.bmp"};//bot kop


int cCordinateX = 0;
int cCordianteY = 0;

int mx = 0;
int my = 0;

int bCordinateX = 1400+mx;
int bCordinateY = 0;



int cIndex = 0;
int cIndex1 = 0;
char str[100];
bool running = false;
bool brunning = false;
bool frunning = false;
bool standPosition = false;  //true;

int standCounter = 0;
int standCounter1 = 0;

int indexNumber = 0;


void iDraw()
{
	iClear();

	iShowBMP2(0, 0, "starting page.bmp", 0);//starting game pic

	if (!standPosition){

		iShowBMP2(bCordinateX, bCordinateY, cRun[cIndex], 0);
		standCounter++;
		if (standCounter >= 20){
			standPosition = true;
			standCounter = 0;
			cIndex = 0;
		}


	}
	else{
		iShowBMP2(cCordinateX, cCordianteY, cStand, 0);
	}



}

	//iShowBMP2(0, 0, "Name1.bmp", 0);//name input page pic	

   


	//iShowBMP2(bCordinateX, bCordinateY, cRun[cIndex], 0);
	//iShowBMP2(bCordinateX, bCordinateY, cBack[cIndex], 0);



	//iShowImage(0, 0, 500, 500, iLoadImage("056.png"));
	//iText(700, 300, str, GLUT_BITMAP_TIMES_ROMAN_24);





	//iShowBMP2(0, 0, cRun[cIndex], 255);

	//if (gameState == 0){


	//iShowBMP2(cCordinateX, cCordianteY, cStand, 0);

	//}


	
	
//froward running code start
	//void playrmovement()
	//{
		//if (running)
		//{
			//iShowBMP2(bCordinateX, bCordinateY, cRun[cIndex], 0);
			//standCounter++;
			//if (standCounter >= 20)
			//{
				//standCounter = 0;
				//cIndex = 0;
				//standPosition = true;
			//}
		//}

		//if (brunning)
		//{
			//iShowBMP2(bCordinateX, bCordinateY, cBack[cIndex], 0);
			//standCounter1++;
			//if (standCounter1 >= 20)
			//{
				//standCounter1 = 0;
				//cIndex1 = 0;
				//cIndex = 0;
				//standPosition = true;
			//}
		//}
	//}





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
		cIndex1++;

		if (cIndex1 >= 6)
		{
			cIndex1 = 0;
		}
		//running = true;
		//brunning = false;
		//frunning = true;
		standPosition = false;
	}


	if (key == GLUT_KEY_RIGHT)
	{
		cCordinateX += 10;
		cIndex++;

		if (cIndex >= 6)
		{
			cIndex = 0;
		}
		//running = true; 
		//brunning = true;
		//frunning = false;
		standPosition = false;


	}

	if (key == GLUT_KEY_HOME)
	{


	}


}
	

	//bot code
//void change(){
	//cIndex++;
	//if (cIndex >= 5){
//cIndex = 0;
	//}
//}

//void collisionCheck() 
//{
	
//}


int main()
{
	iStart();
	//iSetTimer(200, change);
	
	iInitialize(screenwidth, screenheight, "Project Title");
	
	
	return 0;
}
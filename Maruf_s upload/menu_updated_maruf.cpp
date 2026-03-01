#include "iGraphics.h"
#include<iostream>
using namespace std;


//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://

#define screenWidth 1600
#define screenHeight 800
#define loop 6             ///number of buttons 
#define bsize_x 350        ///button weidth
#define bsize_y 150        ///button height

struct buttonCordinate
{
	int x;
	int y;
}bCordinate[6];


int mposx, mposy;                                                  //menu        //high  

char button[20][100] = { "Play.bmp", "Play.bmp", "Instruction.bmp", "About.bmp", "About.bmp", "About.bmp", "Menu.bmp", "Exit.bmp", "Weapnons.bmp", "Instruction.bmp" };
//char button[10][50] = { "About.bmp", "About.bmp", "About.bmp", "About.bmp", "About.bmp", "About.bmp", "About.bmp", "About.bmp", "About.bmp","About.bmp" };
char play[15] = "bg.bmp";     ///after clicking play button background appears
char highScore[25] = "bg.bmp";    ///after clicking highscore 
char ins[25] = "bg.bmp";       
char start[30] = "startingbg.bmp";  ///menu background
char name[30] = "Name.bmp";         ///after clicking play enter your name background
char inst[30] = "Romo.bmp";         ///afterclicking instruction button


int gamestate = -2;
//int subgame = -1;
void iDraw()
{
	iClear();

	
	if (gamestate == -2){
		iShowBMP(0, 0, "bg.bmp"); ///mystro
		iRectangle(100, 100, 300, 150); ///menu button
		iRectangle(1200, 100, 300, 150); ///next button


	}
	
	else if (gamestate == -1){
		///interface_menu
		iShowBMP(0, 0, "bg.bmp");///menu_interface
		for (int i = 0; i < loop; i++){
			iShowImage(bCordinate[i].x, bCordinate[i].y, 300, 165, iLoadImage(button[i]));
		}
		iShowImage(50, 600, 300, 165, iLoadImage("Menu.bmp"));
		iShowImage(1600 - 350, 600, 300, 165, iLoadImage("Exit.bmp"));

	}
	///button_click
	else if (gamestate == 0){
		///after clicking button no 1
		iShowImage(0, 0, 1600, 800, iLoadImage(start));
	}
	else if (gamestate == 1){
		///after clicking button no 2
		iShowImage(0, 0, 1600, 800, iLoadImage(name));
	}
	else if (gamestate == 2){
		///after clicking button no 3
		iShowImage(0, 0, 1600, 800, iLoadImage(inst));
	}
	else if (gamestate == 3){
		///after clicking button no 4
		iShowImage(0, 0, 1600, 800, iLoadImage(start));
	}
	else if (gamestate == 4){
		///after clicking button no 5
		iShowImage(0, 0, 1600, 800, iLoadImage(start));
	}
	else if (gamestate == 5){
		///after clicking button no 6
		iShowImage(0, 0, 1600, 800, iLoadImage(start));
	}
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
	
		if (mx>=100 && mx<=100+300 && my>=100 &&my<=100+150){
			gamestate = -1;    ///-1 mane menu
			///mystro_menu_button
		}
		else if (mx >= 1200 && mx <= 1200 + 300 && my >= 100 && my <= 100 + 150){
			
			///mystro_next_button

		}

		else if (mx >= bCordinate[0].x && mx <= bCordinate[0].x + bsize_x && my >= bCordinate[0].y && my <= bCordinate[0].y + bsize_y && gamestate == -1){
			gamestate = 0;
			///Interface_button1;
		}
		else if (mx >= bCordinate[1].x && mx <= bCordinate[1].x + bsize_x && my >= bCordinate[1].y && my <= bCordinate[1].y + bsize_y && gamestate == -1){
			gamestate = 1;
			///Interface_button2;
		}
		else if (mx >= bCordinate[2].x && mx <= bCordinate[2].x + bsize_x && my >= bCordinate[2].y && my <= bCordinate[2].y + bsize_y && gamestate == -1){
			gamestate = 2;
			///Interface_button3;
		}
		else if (mx >= bCordinate[3].x && mx <= bCordinate[3].x + bsize_x && my >= bCordinate[3].y && my <= bCordinate[3].y + bsize_y && gamestate == -1){
			gamestate = 3;
			///Interface_button4;
		}
		else if (mx >= bCordinate[4].x && mx <= bCordinate[4].x + bsize_x && my >= bCordinate[4].y && my <= bCordinate[4].y + bsize_y && gamestate == -1){
			gamestate = 4;
			///Interface_button5;
		}
		else if (mx >= bCordinate[5].x && mx <= bCordinate[5].x + bsize_x && my >= bCordinate[5].y && my <= bCordinate[5].y + bsize_y && gamestate == -1){
			gamestate = 5;
			///Interface_button6;
		}

		/*extra
		else if (mx >= bCordinate[5].x && mx <= bCordinate[5].x + bsize_x && my >= bCordinate[5].y && my <= bCordinate[5].y + bsize_y){
			gamestate = 5;
		}
		else if (mx >= bCordinate[5].x && mx <= bCordinate[5].x + bsize_x && my >= bCordinate[5].y && my <= bCordinate[5].y + bsize_y){
			gamestate = 5;
		}
		*/




    }
		

	
	
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		cout << "mx= " << mx << endl << "my= " << my << endl<<endl;
	}
}




void iKeyboard(unsigned char key)
{
	if (key == 'e')
	{
		gamestate = -1;
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
int point_x = 663, point_y = 600;

void iSpecialKeyboard(unsigned char key)
{

	
	if (key == GLUT_KEY_UP)
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
	///setting axis
	int Y = 600;
	for (int i = 0; i<loop; i++){
		bCordinate[i].x = 663;
		bCordinate[i].y = Y;
		Y-= 90;
	}
	iInitialize(screenWidth, screenHeight, "Project Title");
	
	iStart();
	return 0;
}
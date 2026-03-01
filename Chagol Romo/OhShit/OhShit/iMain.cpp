#include "iGraphics.h"
#include<iostream>
using namespace std;


//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://

#define screenWidth 1600
#define screenHeight 800
#define loop 3             ///number of buttons 
#define bsize_x 344        ///button weidth
#define bsize_y 74        ///button height

struct buttonCordinate
{
	int x;
	int y;
}bCordinate[10];


int mposx, mposy;                                                  //menu        //high  

char button[20][100] = { "Buttons\\Play.bmp", "Buttons\\NewGame.bmp", "Buttons\\Highscore.bmp" };
char stroy[5][100] = {};
char Play[4][100] = { "Buttons\\Play2.bmp", "Buttons\\Play3.bmp", "Buttons\\Play4.bmp", "Buttons\\Play5.bmp"};
//char button[10][50] = { "About.bmp", "About.bmp", "About.bmp", "About.bmp", "About.bmp", "About.bmp", "About.bmp", "About.bmp", "About.bmp","About.bmp" };


char play[40] = "BackGround\\Versus.bmp";           //                      after clicking play button background appears
char highScore[25] = "BackGround\\Highscore.bmp";   //                      after clicking highscore 

char start[30] = "BackGround\\MenuBackground.bmp";  //                      menu background
char name[30] = "BackGround\\Name.bmp";             //                       after clicking play enter your name background
char inst[30] = "BackGround\\InstructionBG.bmp";             //                      afterclicking instruction button
char abt[30] = "BackGround\\InstructionBG.bmp";
char lvl[30] = "BackGround\\Level.bmp";
char ro[30] = "BackGround\\Romo.bmp";
char cutt[30] = "BackGround\\str.bmp";


int gamestate = -2;
int about = 0;
int story = 0;
int level = 0;



void iDraw()
{
	iClear();


	if (gamestate == -2){
		iShowBMP(0, 0, "BackGround\\Mystro.bmp");                       //               Mystro Background
		//iRectangle(1200, 50, 180, 52);
		iShowBMP2(100, 50, "Buttons\\Skip.Bmp", 0);                    //              Skip Button
		iShowBMP2(1200, 50, "Buttons\\Next.Bmp", 0);                   //              Next Button
		



	}

	else if (gamestate == -1){
		///interface_menu
		iShowBMP(0, 0, "BackGround\\MenuBackground.bmp");///menu_interface
		for (int i = 0; i < loop; i++){                                                                // Menu buttons

			iShowBMP2(bCordinate[i].x, bCordinate[i].y, button[i], 0);

		}

		iShowBMP2(299, 110, "Buttons\\Instruction.bmp", 0);

		iShowBMP2(1027, 110, "Buttons\\About.bmp", 0);

		iShowBMP2(100, 700, "Buttons\\Option.bmp", 0);

		iShowBMP2(1250, 700, "Buttons\\Exit.bmp", 0);

	}
	///button_click
	else if (gamestate == 0){

		

			iShowBMP(0, 0, play);
		
	                           
	}




	else if (gamestate == 1){
		
		                           iShowBMP(0, 0, name);
		
	}
	else if (gamestate == 2){
		
		                           iShowBMP(0, 0, highScore);
	}
	else if (gamestate == 3){
		
		                           iShowBMP(0, 0, inst);
	}
	else if (gamestate == 4){
		
		                           iShowBMP(0, 0, inst);
								   iShowBMP(263, 500, "Buttons\\Romo.bmp");
								   iShowBMP(1037, 500, "Buttons\\CutterMaruf.bmp");
								   iShowBMP(650, 180, "Buttons\\Credits.bmp");
	}
	else if (gamestate == 5){
		
		                           iShowBMP(0, 0, name);
	}

	else if (gamestate == 6){

								   iShowBMP(0, 0, ro);
	}

	else if (gamestate == 7){

								   iShowBMP(0, 0, cutt);
	}

	else if (gamestate == 8){

								   iShowBMP(0, 0, inst);
	}


	else if (gamestate == 9){

								   iShowBMP(0, 0, lvl);
	}

	else if ((story == 1 || story == 2 || story == 3 || story == 4 || story == 5) && gamestate < -2){

		if (story == 1){

			iShowBMP(0, 0, "BackGround\\Story-1.bmp");
			iShowBMP2(100, 50, "Buttons\\Skip.Bmp", 0);                    
			iShowBMP2(1200, 50, "Buttons\\Next.Bmp", 0);


		}
			


		else if (story == 2){

			iShowBMP(0, 0, "BackGround\\Story-2.bmp");
			iShowBMP2(100, 50, "Buttons\\Skip.Bmp", 0);
			iShowBMP2(1200, 50, "Buttons\\Next.Bmp", 0);
		
		}
			


		else if (story == 3){

			iShowBMP(0, 0, "BackGround\\Story-3.bmp");
			iShowBMP2(100, 50, "Buttons\\Skip.Bmp", 0);
			iShowBMP2(1200, 50, "Buttons\\Next.Bmp", 0);

		}
			


		else if (story == 4){

			iShowBMP(0, 0, "BackGround\\Story-4.bmp");
			iShowBMP2(100, 50, "Buttons\\Skip.Bmp", 0);
			iShowBMP2(1200, 50, "Buttons\\Next.Bmp", 0);

		}
			


		else if (story == 5){
			
			iShowBMP(0, 0, "BackGround\\Story-5.bmp");
			iShowBMP2(100, 50, "Buttons\\Skip.Bmp", 0);
			iShowBMP2(1200, 50, "Buttons\\Next.Bmp", 0);
		
		}

	
			
	}


	else if (gamestate == 10){

		
		iShowBMP(0, 0, "BackGround\\MenuBackground.bmp");///menu_interface
		for (int i = 0; i < loop; i++){                                                                // Menu buttons

			iShowBMP2(bCordinate[i].x, bCordinate[i].y, button[i], 0);

		}

		iShowBMP2(299, 110, "Buttons\\Instruction.bmp", 0);

		iShowBMP2(1027, 110, "Buttons\\About.bmp", 0);

		iShowBMP2(100, 700, "Buttons\\Option.bmp", 0);

		iShowBMP(550, 250, "BackGround\\Sure.bmp");
		//iRectangle(908, 368, 152, 56);
		
		
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

		if (mx >= 100 && mx <= 100 + 180 && my >= 50 && my <= 50 + 52){
			gamestate = -1;    ///-1 mane menu
			///mystro_menu_button
		}
		else if (mx >= 1200 && mx <= 1200 + 180 && my >= 50 && my <= 50 + 52 && (story == 1 || story == 2 || story == 3 || story == 4 || story == 5 || story == 0)){

			story++;
			gamestate--;
			if (story > 5)
				gamestate = -1;

		}

		else if (mx >= bCordinate[0].x && mx <= bCordinate[0].x + bsize_x && my >= bCordinate[0].y && my <= bCordinate[0].y + bsize_y && gamestate == -1){
			gamestate = 0;
			///versus background;
		}

		else if (mx >= 0 && mx <= 0 + 1600 && my >= 0 && my <= 0+800 && gamestate == 0){
			gamestate = 9;
			
			///level 1 background;
		}


		else if (mx >= bCordinate[1].x && mx <= bCordinate[1].x + bsize_x && my >= bCordinate[1].y && my <= bCordinate[1].y + bsize_y && gamestate == -1){
			gamestate = 1;
			///Interface_button2;
		}
		else if (mx >= bCordinate[2].x && mx <= bCordinate[2].x + bsize_x && my >= bCordinate[2].y && my <= bCordinate[2].y + bsize_y && gamestate == -1){
			gamestate = 2;
			///Interface_button3;
		}
		else if (mx >= 299 && mx <= 299 + bsize_x && my >= 110 && my <= 110 + bsize_y && gamestate == -1){
			gamestate = 3;
			///Interface_button4;
		}
		else if (mx >= 1027 && mx <= 1027 + bsize_x && my >= 110 && my <= 110 + bsize_y && gamestate == -1){     //about button
			gamestate = 4;
			about = 1;
		
			
		}
		else if (mx >= bCordinate[5].x && mx <= bCordinate[5].x + bsize_x && my >= bCordinate[5].y && my <= bCordinate[5].y + bsize_y && gamestate == -1){
			gamestate = 5;
			///Interface_button6;
		}

		else if (mx >= 263 && mx <= 263 + 357 && my >= 500 && my <= 500 + 111 && gamestate == 4 && about == 1){   //romo button
			
			gamestate = 6;
			
		}


		else if (mx >= 1037 && mx <= 1037 + 357 && my >= 500 && my <= 500 + 111 && gamestate == 4 && about == 1){ //cutter maruf button
			
			gamestate = 7;
			
		}


		else if (mx >= 650 && mx <= 650 + 357 && my >= 180 && my <= 180 + 111 && gamestate == 4 && about == 1){  //credits button
			
			gamestate = 8;
			
		}


		else if (mx >= 1250 && mx <= 1250 + 344 && my >= 700 && my <= 700 + 74 && gamestate == -1){  //credits button

			gamestate = 10;

		}


		else if (mx >= 630 && mx <= 630 + 152 && my >= 368 && my <= 368 + 56  && gamestate == 10){  //credits button

			exit(0);
			

		}


		else if (mx >= 908 && mx <= 908 + 152 && my >= 368 && my <= 368 + 56 && gamestate == 10){  //credits button

			gamestate = -1;


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
		cout << "mx= " << mx << endl << "my= " << my << endl << endl;
	}
}




void iKeyboard(unsigned char key)
{
	if (key == 'b')
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
	int Y = 400;
	for (int i = 0; i<loop; i++){
		bCordinate[i].x = 663;
		bCordinate[i].y = Y;
		Y -= 90;
	}
	iInitialize(screenWidth, screenHeight, "Project Title");

	iStart();
	return 0;
}
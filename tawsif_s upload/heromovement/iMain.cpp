#include "iGraphics.h"
#include<iostream>
using namespace std;

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
#define jumpLimit 50
int bRunCordianteX = 0;
int bRunCordianteY = 0;
int brindex = 0;


//hero array
char cStand[20] = { "HeroIidlepos.bmp" };
char cRun[6][60] = { "hr1.bmp", "hr2.bmp", "hr3.bmp", "hr4.bmp", "hr5.bmp", "hr6.bmp" };//hero forward run
char cBack[6][60] = { "hbb1.bmp", "hbb2.bmp", "hbb3.bmp", "hbb4.bmp", "hbb5.bmp", "hbb6.bmp" };//hero bacward run
char cFall[10][100] = { "HanFa1.bmp", "HanFa2.bmp", "HanFa3.bmp", "HanFa4.bmp", "HanFa5.bmp", "HanFa6.bmp", "HanFa7.bmp", "HanFa8.bmp", "HanFa9.bmp", "HanFa10.bmp"};
char cKick[7][15] = { "HanK.bmp", "HanK1.bmp", "HanK2.bmp", "HanK3.bmp", "HanK4.bmp", "HanK5.bmp", "HanK6.bmp" };
char cPunch[5][20] = { "HanP11.bmp", "HanP22.bmp", "HanP33.bmp", "HanP44.bmp", "HanP55.bmp" };




//bot array

char bbKop1[10][50] = { "Sword-A-1.bmp", "Sword-A-2.bmp", "Sword-A-3.bmp", "Sword-A-4.bmp", "Sword-A-5.bmp", "Sword-A-6.bmp", "Sword-A-7.bmp", "Sword-A-8.bmp", "Sword-A-9.bmp", "Sword-A-10.bmp" };//A
char bbKop2[5][30] = { "Sword-D-1.bmp", "Sword-D-2.bmp", "Sword-D-3.bmp", "Sword-D-4.bmp", "Sword-D-5.bmp" };//D
char bbKop3[6][15] = { "Sword-S-1.bmp", "Sword-S-2.bmp", "Sword-S-3.bmp", "Sword-S-4.bmp", "Sword-S-5.bmp", "Sword-S-6.bmp" };//S
char bbKop4[10][50] = { "Sword-W-1.bmp", "Sword-W-2.bmp", "Sword-W-3.bmp", "Sword-W-4.bmp", "Sword-W-5.bmp", "Sword-W-6.bmp", "Sword-W-7.bmp", "Sword-W-8.bmp", "Sword-W-9.bmp", "Sword-W-10.bmp" };//W
char bbStand[20] = { "Sword-Idle-1.bmp" };
char bbBack[6][20] = { "Sword-run-1.bmp", "Sword-run-2.bmp", "Sword-run-3.bmp", "Sword-run-4.bmp", "Sword-run-5.bmp", "Sword-run-6.bmp" };
char bbRun[4][20] = { "Sword-back-1.bmp", "Sword-back-2.bmp", "Sword-back-3.bmp" };
char bbFall2[6][20] = { "Sword-Fall-2-1.bmp", "Sword-Fall-2-2.bmp", "Sword-Fall-2-3.bmp", "Sword-Fall-2-4.bmp", "Sword-Fall-2-5.bmp", "Sword-Fall-2-6.bmp" };
char bbFall1[8][20] = { "Sword-Fall-1-1.bmp", "Sword-Fall-1-2.bmp", "Sword-Fall-1-3.bmp", "Sword-Fall-1-4.bmp", "Sword-Fall-1-5.bmp", "Sword-Fall-1-6.bmp", "Sword-Fall-1-7.bmp", "Sword-Fall-1-8.bmp" };







//hero
bool running = false;
bool standing = true;
bool frunning = false;
bool brunning = false;
bool fall = false;
bool kick = false;
bool punch = false;
bool jump = false;
bool jumpUp = false;


int heroCorinate = 0;  ///for jump


int findex = 0;
int bindex = 0;
int kindex = 0;
int pindex = 0;
int flindex = 0;
int standCount = 0;




//bot
bool bbrunning = false;
bool bbstanding = true;
bool bbfrunning = false;
bool bbbrunning = false;
bool bbfalling1 = false;
bool bbfalling2 = false;
bool bbKopping1 = false;
bool bbKopping2 = false;
bool bbKopping3 = false;
bool bbKopping4 = false;


int bbfindex = 0;
int bbbindex = 0;
int bbkop1index = 0;
int bbkop2index = 0;
int bbkop3index = 0;
int bbkop4index = 0;
int bbfl1index = 0;
int bbfl2index = 0;
int bbstandCount = 0;

int bx = 1000, by = 0;


int cx = 0,cy=0;


void iDraw()
{
	iClear();



	//heroCollisionChecker();
	//botCollisionChecker();
	heroMovement();
	botMovement();
	jumpcode();
	//jumpchange();HanK1.bmp
	
	//iShowBMP(0, 0, "HanK1.bmp");
	iFilledRectangle(180, 600, heroLife / 5, 60);

	iFilledRectangle(1280, 600, botLife / 5, 60);
	iShowBMP(0, 0, "starting page.bmp");

}

//collusion code-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int heroLife = 1000, botLife = 1000;
int length = 100, height = 150;
void heroCollisionChecker(){
	if (cx + length >= bx && cx <= (bx + length) && (cy + height) >= by && cy <= (by + height)){
		if ((standing || running || fall) && (!bbstanding || !bbrunning || !bbfalling2)){
			heroLife -= .005;
		}
			
		cout << heroLife << endl;
	}

}
void botCollisionChecker(){
	if (cx + length >= bx && cx <= (bx + length) && (cy + height) >= by && cy <= (by + height)){
		if ((bbstanding || bbrunning || bbfalling2) && (!standing || !running || !fall)){
			botLife -= 0.005;
			
		}
			
		cout << "botLife: " << botLife << endl;
	}

}
//---------------------------------------------------------------------------------------------------------


//jump function-----------------------------------------------------------------
void jumpcode(){
	if (jump){
		//code 
		if (jumpUp){
			iShowBMP2(cx, cy + heroCorinate, "HeroIidlepos.bmp", 0);
		}
		else
		{
			iShowBMP2(cx, cy + heroCorinate, "HanK1.bmp", 0);
		}

	}
}
void jumpchange(){
	if (jump)
	{
		if (jumpUp){
			heroCorinate += 5;
			if (heroCorinate >= jumpLimit)
			{
				jumpUp = false;
			}
		}
		else
		{
			heroCorinate -= 5;
			if (heroCorinate < 0)
			{
				jump = false;
				heroCorinate = 0;
				standing = true;
			}
		}
	}
}




//bot sprite change----------------------------------------------------------------------------------------
void autoBotChange(){
	if (bbKopping1){
		bbkop1index++;

		if (bbkop1index >= 10){

			bbkop1index = 0;
			bbKopping1 = false;
			bbstanding = true;
		}


	}

	if (bbKopping2){
		bbkop2index++;

		if (bbkop2index >= 5){

			bbkop2index = 0;
			bbKopping2 = false;
			bbstanding = true;
		}


	}


	if (bbKopping3){
		bbkop3index++;

		if (bbkop3index >= 6){

			bbkop3index = 0;
			bbKopping3 = false;
			bbstanding = true;
		}


	}


	if (bbKopping4){
		bbkop4index++;

		if (bbkop4index >= 10){

			bbkop4index = 0;
			bbKopping4 = false;
			bbstanding = true;
		}


	}


	if (bbfalling1){
		bbfl1index++;
		if (bbfl1index >= 8){

			bbfl1index = 0;
			bbfalling1 = false;
			bbstanding = true;
		}
	}

	if (bbfalling2){
		bbfl2index++;
		if (bbfl2index >= 5){

			bbfl2index = 0;
			bbfalling2 = false;
			bbstanding = true;
		}
	}
}
//-------------------------------------------------------------------------------------------------------




//hero sprtite change-------------------------------------------------------------------------------------
void autpSpriteChange(){
	if (kick){
		kindex++;

		if (kindex >= 6){

			kindex = 0;
			kick = false;
			standing = true;
		}


	}
	if (punch){
		pindex++;

		if (pindex >= 5){

			pindex = 0;
			punch = false;
			standing = true;
		}
	}
	if (fall){
		flindex++;
		if (flindex >= 10){

			flindex = 0;
			fall = false;
			standing = true;
		}
	}

	

}
//-------------------------------------------------------------------------------------------




//bot movement-----------------------------------------------------------------------------
void botMovement(){

	if (bbstanding){
		iShowBMP2(0 + bx, 0 + by, bbStand, 0);
	}

	if (bbrunning){
		if (bbfrunning){
			if (!bbstanding){
				iShowBMP2(0 + bx, 0 + by, bbRun[bbfindex], 0);
				bbstandCount++;
				if (bbstandCount >= 600){
					bbstanding = true;
					bbstandCount = 0;
					bbfindex = 0;

				}
			}

		}
		else if (bbbrunning){//else if
			if (!bbstanding){
				iShowBMP2(0 + bx, 0 + by, bbBack[bbbindex], 0);
				bbstandCount++;
				if (bbstandCount >= 600){
					bbstanding = true;
					bbstandCount = 0;
					bbbindex = 0;
				}

			}

		}
	}
	else if (!bbrunning){//if chilo
		if (bbKopping1){
			iShowBMP2(0 + bx, 0 + by, bbKop1[bbkop1index], 0);
			if (bbkop1index >= 10){
				bbKopping1 = false;
				bbkop1index = 0;
				bbstanding = true;


			}
		}


		else if (bbKopping2){
			iShowBMP2(0 + bx, 0 + by, bbKop2[bbkop2index], 0);
			if (bbkop2index >= 5){
				bbKopping2 = false;
				bbkop2index = 0;
				bbstanding = true;

			}
		}
		else if (bbKopping3){
			iShowBMP2(0 + bx, 0 + by, bbKop3[bbkop3index], 0);
			if (bbkop3index >= 6){
				bbKopping3 = false;
				bbkop3index = 0;
				bbstanding = true;

			}
		}
		else if (bbKopping4){
			iShowBMP2(0 + bx, 0 + by, bbKop4[bbkop4index], 0);
			if (bbkop4index >= 10){
				bbKopping4 = false;
				bbkop4index = 0;
				bbstanding = true;

			}
		}

		if (bbfalling1){
			iShowBMP2(0 + bx, 0 + by, bbFall1[bbfl1index], 0);
			if (bbfl1index >= 8){
				bbfalling1 = false;
				bbfl1index = 0;
				bbstanding = true;

			}


		}
		if (bbfalling2){
			iShowBMP2(0 + bx, 0 + by, bbFall2[bbfl2index], 0);
			if (bbfl2index >= 5){
				bbfalling2 = false;
				bbfl2index = 0;
				bbstanding = true;

			}


		}

	}


}
//--------------------------------------------------------------------------------------------------



//hero movement------------------------------------------------------------------------------------
void heroMovement(){

	if (standing){
		iShowBMP2(0 + cx, 0 + cy, cStand, 0);
	}

	if (running){
		if (frunning){
			if (!standing){
				iShowBMP2(0 + cx, 0 + cy, cRun[findex], 0);
				standCount++;
				if (standCount >= 600){
					standing = true;
					standCount = 0;
					findex = 0;

				}
			}

		}
		else if (brunning){//else if
			if (!standing){
				iShowBMP2(0 + cx, 0 + cy, cBack[bindex], 0);
				standCount++;
				if (standCount >= 600){
					standing = true;
					standCount = 0;
					bindex = 0;
				}

			}

		}
	}
	else if (!running){//if chilo
		if (kick){
			iShowBMP2(0 + cx, 0 + cy, cKick[kindex], 0);
			if (kindex >= 6){
				kick = false;
				kindex = 0;
				standing = true;


			}
		}


		else if (punch){
			iShowBMP2(0 + cx, 0 + cy, cPunch[pindex], 0);
			if (pindex >= 4){
				punch = false;
				pindex = 0;
				standing = true;
				kick = false;

			}
		}
		if (fall){
			iShowBMP2(0 + cx, 0 + cy, cFall[flindex], 0);
			if (flindex >= 9){
				fall = false;
				punch = false;
				flindex = 0;
				standing = true;
				kick = false;
			}


		}

	   ////jump code starts.............
	 ////jump code ends.................

	}


}

//-------------------------------------------------------------------------------------------







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
	//hero access start
	if (key == 'k')
	{
		//kindex++;
		botCollisionChecker();
		fall = false;
		running = false;
		kick = true;
		standing = false;
		punch = false;
	
	}
	if (key == 'p')
	{
		//pindex++;
		botCollisionChecker();
		fall = false;
		punch = true;
		running = false;
		standing = false;
		kick = false;

	}

	if (key == 'f')
	{
		//flindex++;
		fall = true;
		punch = false;
		running = false;
		standing = false;
		kick = false;

	}

	if (key == ' ')
	{
		
		fall = false;
		punch = false;
		running = false;
		standing = false;
		kick = false;
		if (!jump){
			jump = true;
			jumpUp = true;
		}

	}

	//bot access start
	if (key == '0')
	{
		heroCollisionChecker();
		bbrunning = false;
		bbstanding = false;
		bbfrunning = false;
		bbbrunning = false;
		bbfalling1 = false;
		bbfalling2 = false;
		bbKopping1 = true;
		bbKopping2 = false;
		bbKopping3 = false;
		bbKopping4 = false;
	}
	if (key == '1')
	{
		heroCollisionChecker();
		bbrunning = false;
		bbstanding = false;
		bbfrunning = false;
		bbbrunning = false;
		bbfalling1 = false;
		bbfalling2 = false;
		bbKopping1 = false;
		bbKopping2 = true;
		bbKopping3 = false;
		bbKopping4 = false;
	}
	if (key == '2')
	{
		heroCollisionChecker();
		bbrunning = false;
		bbstanding = false;
		bbfrunning = false;
		bbbrunning = false;
		bbfalling1 = false;
		bbfalling2 = false;
		bbKopping1 = false;
		bbKopping2 = false;
		bbKopping3 = true;
		bbKopping4 = false;
	}
	if (key == '3')
	{
		heroCollisionChecker();
		bbrunning = false;
		bbstanding = false;
		bbfrunning = false;
		bbbrunning = false;
		bbfalling1 = false;
		bbfalling2 = false;
		bbKopping1 = false;
		bbKopping2 = false;
		bbKopping3 = false;
		bbKopping4 = true;
	}
	if (key == '4')
	{
		bbrunning = false;
		bbstanding = false;
		bbfrunning = false;
		bbbrunning = false;
		bbfalling1 = true;
		bbfalling2 = false;
		bbKopping1 = false;
		bbKopping2 = false;
		bbKopping3 = false;
		bbKopping4 = false;
	}
	if (key == '5')
	{
		bbrunning = false;
		bbstanding = false;
		bbfrunning = false;
		bbbrunning = false;
		bbfalling1 = false;
		bbfalling2 = true;
		bbKopping1 = false;
		bbKopping2 = false;
		bbKopping3 = false;
		bbKopping4 = false;
	}
	//bot move
	if (key == '9')
	{
		bbfindex++;
		bx += 10;
		if (bbfindex >= 3){
			bbfindex = 0;
		}
		bbrunning = true;
		bbstanding = false;
		bbfrunning = true;
		bbbrunning = false;
		bbfalling1 = false;
		bbfalling2 = false;
		bbKopping1 = false;
		bbKopping2 = false;
		bbKopping3 = false;
		bbKopping4 = false;

	}
	if (key == '8')
	{
		bbbindex++;
		bx -= 10;
		if (bbbindex >= 6){
			bbbindex = 0;
		}
		bbrunning = true;
		bbstanding = false;
		bbfrunning = false;
		bbbrunning = true;
		bbfalling1 = false;
		bbfalling2 = false;
		bbKopping1 = false;
		bbKopping2 = false;
		bbKopping3 = false;
		bbKopping4 = false;
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
	//bot iSpecial keyboard
	/*
	if (key == GLUT_KEY_RIGHT)
	{
	bbfindex++;
	bx += 10;
	if (bbfindex >= 3){
	bbfindex = 0;
	}
	bbrunning = true;
	bbstanding = false;
	bbfrunning = true;
	bbbrunning = false;
	bbfalling1 = false;
	bbfalling2 = false;
	bbKopping1 = false;
	bbKopping2 = false;
	bbKopping3 = false;
	bbKopping4 = false;

	}
	if (key == GLUT_KEY_LEFT)
	{
	bbbindex++;
	bx -= 10;
	if (bbbindex >= 6){
	bbbindex = 0;
	}
	bbrunning = true;
	bbstanding = false;
	bbfrunning =false;
	bbbrunning = true;
	bbfalling1 = false;
	bbfalling2 = false;
	bbKopping1 = false;
	bbKopping2 = false;
	bbKopping3 = false;
	bbKopping4 = false;
	}
	*/

	

	if (key == GLUT_KEY_RIGHT)
	{
		findex++;
		cx += 10;
		if (findex >= 6){
			findex = 0;
		}
		standing = false;
		running = true;
		frunning = true;
		brunning = false;
		fall = false;


	}
	if (key == GLUT_KEY_LEFT)
	{
		bindex++;
		cx -= 10;
		if (bindex >= 6){
			bindex = 0;
		}
		standing = false;
		running = true;
		brunning = true;
		frunning = false;
		fall = false;


	}
	
	
	
	
}

unsigned char key;
int count = 0;

void botControl(){
	if (bx - cx <= 150){
		int k = rand() % 4;
		key = k + '0';
		iKeyboard(key);

	}
}





int main()
{
	iSetTimer(200, autpSpriteChange);
	iSetTimer(100, autoBotChange);
	iSetTimer(100, jumpchange);
	//iSetTimer(rand() + 1000, botControl);

	//iSetTimer(1, heroCollisionChecker);
	//iSetTimer(1, botCollisionChecker);
	

	iInitialize(1600, 800, "Project Title");
	
	iStart();
	return 0;
}

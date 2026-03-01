#define _CRT_SECURE_NO_DEPRECATE
#include "iGraphics.h"
#include<iostream>
#include<string>
using namespace std;

//#define HIGHSCORE score
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://





//----------------------------------------------------------------------------------------------------------------------------------------------
//menu varriable start---------------------------------------------------------------------------------------------------------------------------------------------
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
char str[1000];
char str1[1000] = "CAUTION!!!!Invalid name input";
int txtindex = 0;
int txtindex1 = 0;


int gamestate = -2;
int about = 0;
int story = 0;
int level = 0;

//----------------------------------------------------------------------------------------------------------------------------------------------
//menu varrable ends-----------------------------------------------------------------------------------------------------------------------





//----------------------------------------------------------------------------------------------------------------------------------------------
///character movement varriable starts----------------------------------------------------------------------------------------------------------

//#define jumpLimit 50
int bRunCordianteX = 0;
int bRunCordianteY = 0;
int brindex = 0;

int cDirection = 0;                 ///right direction =0 , left direction =1


//hero array
char cStand[20] = { "HeroIidlepos.bmp" };
char crotateStand[20] = { "RHeroI1.bmp" };
char cRun[6][60] = { "hr1.bmp", "hr2.bmp", "hr3.bmp", "hr4.bmp", "hr5.bmp", "hr6.bmp" };//hero forward run
char cBack[6][60] = { "hbb1.bmp", "hbb2.bmp", "hbb3.bmp", "hbb4.bmp", "hbb5.bmp", "hbb6.bmp" };//hero bacward run
char cFall[15][100] = { "HanFa1.bmp", "HanFa2.bmp", "HanFa3.bmp", "HanFa4.bmp", "HanFa5.bmp", "HanFa5.bmp", "HanFa5.bmp", "HanFa5.bmp", "HanFa5.bmp", "HanFa6.bmp", "HanFa7.bmp", "HanFa8.bmp", "HanFa9.bmp", "HanFa10.bmp" };
char cKick[7][15] = { "HanK.bmp", "HanK1.bmp", "HanK2.bmp", "HanK3.bmp", "HanK4.bmp", "HanK5.bmp", "HanK6.bmp" };
char cPunch[5][20] = { "HanP11.bmp", "HanP22.bmp", "HanP33.bmp", "HanP44.bmp", "HanP55.bmp" };
char ckop1[10][20] = { "HeroD1.bmp", "HeroD2.bmp", "HeroD3.bmp", "HeroD4.bmp", "HeroD5.bmp", "HeroD6.bmp", "HeroD7.bmp" };//hero kop1 (button D)
char cKop2[10][20] = { "HeroS1.bmp", "HeroS2.bmp", "HeroS3.bmp", "HeroS4.bmp", "HeroS5.bmp", "HeroS6.bmp" };//hero kop2 (button s)
char cKop3[10][20] = { "HanW1.bmp", "HanW2.bmp", "HanW3.bmp", "HanW4.bmp", "HanW5.bmp", "HanW6.bmp", "HanW7.bmp", "HanW8.bmp" };//hero button w
char cbKop[10][20] = { "RHanW1.bmp", "RHanW2.bmp", "RHanW3.bmp", "RHanW4.bmp", "RHanW5.bmp", "RHanW6.bmp", "RHanW7.bmp", "RHanW8.bmp" };//hero reverse action




//bot array

char bbKop1[10][50] = { "Sword-A-1.bmp", "Sword-A-2.bmp", "Sword-A-3.bmp", "Sword-A-4.bmp", "Sword-A-5.bmp", "Sword-A-6.bmp", "Sword-A-7.bmp", "Sword-A-8.bmp", "Sword-A-9.bmp", "Sword-A-10.bmp" };//A
char bbKop2[5][30] = { "Sword-D-1.bmp", "Sword-D-2.bmp", "Sword-D-3.bmp", "Sword-D-4.bmp", "Sword-D-5.bmp" };//D
char bbKop3[6][15] = { "Sword-S-1.bmp", "Sword-S-2.bmp", "Sword-S-3.bmp", "Sword-S-4.bmp", "Sword-S-5.bmp", "Sword-S-6.bmp" };//S
char bbKop4[10][50] = { "Sword-W-1.bmp", "Sword-W-2.bmp", "Sword-W-3.bmp", "Sword-W-4.bmp", "Sword-W-5.bmp", "Sword-W-6.bmp", "Sword-W-7.bmp", "Sword-W-8.bmp", "Sword-W-9.bmp", "Sword-W-10.bmp" };//W
char bbStand[20] = { "Sword-Idle-1.bmp" };
char bbBack[6][20] = { "Sword-run-1.bmp", "Sword-run-2.bmp", "Sword-run-3.bmp"/*, "Sword-run-4.bmp", "Sword-run-5.bmp", "Sword-run-6.bmp"*/ };
char bbRun[4][20] = { "Sword-back-1.bmp", "Sword-back-2.bmp", "Sword-back-3.bmp" };
char bbFall2[6][20] = { "Sword-Fall-2-1.bmp", "Sword-Fall-2-2.bmp", "Sword-Fall-2-3.bmp", "Sword-Fall-2-4.bmp", "Sword-Fall-2-5.bmp", "Sword-Fall-2-6.bmp" };
char bbFall1[8][20] = { "Sword-Fall-1-1.bmp", "Sword-Fall-1-2.bmp", "Sword-Fall-1-3.bmp", "Sword-Fall-1-4.bmp", "Sword-Fall-1-5.bmp", "Sword-Fall-1-6.bmp", "Sword-Fall-1-7.bmp", "Sword-Fall-1-8.bmp" };

int count1 = 0;






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
bool kopping1 = false;
bool fKopping1 = false;
bool bKopping1 = false;
bool kopping2 = false;
bool fKopping2 = false;
bool bKopping2 = false;
bool fKopping3 = false;
bool bKopping3 = false;
bool kopping3 = false;
bool musicOn = true;






int heroCorinate = 0;  ///for jump


int findex = 0;
int bindex = 0;
int kindex = 0;
int pindex = 0;
int flindex = 0;
int k1findex = 0;
int k1bindex = 0;
int k2findex = 0;
int k2bindex = 0;
int k3findex = 0;
int k3bindex = 0;
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

int bx = 1250, by = 100;


int cx = 250, cy = 100;

int r = 255, g = 255, b = 255;
int r1 = 255, g1 = 255, b1 = 255;


//----------------------------------------------------------------------------------------------------------------------------------------------
//chracter movement varriable ends--------------------------------------------------------------------------------------------------------------





//functions start--------------------------------------------------------------------------------------------------------------------------------
//******************************************************************************************************************************************


//collusion code-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int heroLife = 1000, botLife = 1000;
int score= 0;
int length = 100, height = 150;
void heroCollisionChecker(){
	if (cx + length >= bx && cx <= (bx + length) && (cy + height) >= by && cy <= (by + height)){
		if ((standing || running || fall) && (!bbstanding || !bbrunning || !bbfalling2)&& gamestate==9){
			if (heroLife > 0 && bbKopping1){
				heroLife -= 100;
				iKeyboard('f');
			}
			else if (heroLife > 0 && bbKopping2){
				heroLife -= 120;
				iKeyboard('f');
			}
			else if (heroLife > 0 && bbKopping3){
				heroLife -= 150;
				iKeyboard('f');
			}
			else if (heroLife > 0 && bbKopping4){
				heroLife -= 200;
				iKeyboard('f');
			}
			
		}
		

		cout <<"HEROlife: "<< heroLife << endl;
	}

}
void botCollisionChecker(){
	if (cx + length >= bx && cx <= (bx + length) && (cy + height) >= by && cy <= (by + height)){
		if ((bbstanding || bbrunning || bbfalling2) && (!standing || !running || !fall) && gamestate==9){
			if (botLife > 0 && punch){
				botLife -= 10;
				score += 100;
				cout << "score punch: " << score << endl;
				cout << "botLife: " << botLife << endl;
			

			}
			else if (botLife > 0 && kick){
				botLife -= 15;
				score += 200;

				cout << "score kick : " << score << endl;
				cout << "botLife: " << botLife << endl;
				

			}
			else if (botLife > 0 && kopping1){
				botLife -= 20;
				score += 300;

				cout << "score kopping1: " << score << endl;
				cout << "botLife: " << botLife << endl;

			}
			else if (botLife > 0 && kopping2){
				botLife -= 20;
				score += 300;

				cout << "score kopping2: " << score << endl;
				cout << "botLife: " << botLife << endl;

			}
			else if (botLife > 0 && kopping1 && bKopping1){
				botLife -= 25;
				score += 455;

				cout << "score bkopping1: " << score << endl;
				cout << "botLife: " << botLife << endl;

			}
			
			//iKeyboard('4');
			

		}

		//cout << "BOTLife: " << botLife << endl;
	}

}
//---------------------------------------------------------------------------------------------------------


//jump function-----------------------------------------------------------------
/*
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
*/



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
		if (flindex >= 14){

			flindex = 0;
			fall = false;
			standing = true;
		}
	}
	if (kopping1){
		if (fKopping1){
			k1findex++;
			if (k1findex >= 7){
				k1findex = 0;
				fKopping1 = false;
				kopping1 = false;
				standing = true;
			}
		}
		else if (bKopping1){
			k1bindex++;
			if (k1bindex >= 8){
				k1bindex = 0;
				bKopping1 = false;
				kopping1 = false;
				standing = true;
				
			}
		}
	}

	



	 if (kopping2){
		if (fKopping2){
			k2findex++;
			if (k2findex >= 6){
				k2findex = 0;
				fKopping2 = false;
				kopping2 = false;
				standing = true;
			}
		}
		else if (bKopping2){
			k2bindex++;
			if (k2bindex >= 8){
				k2bindex = 0;
				bKopping2 = false;
				kopping2 = false;
				standing = true;

			}
		}
	}





	if (kopping3){
		if (fKopping3){
			k1findex++;
			if (k3findex >= 8){
				k3findex = 0;
				fKopping3 = false;
				kopping3 = false;
				standing = true;
			}
		}
		else if (bKopping3){
			k3bindex++;
			if (k3bindex >= 8){
				k3bindex = 0;
				bKopping3 = false;
				kopping3 = false;
				standing = true;

			}
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
				if (bbstandCount >= 10){      ///needs to be change
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
				if (bbstandCount >= 10){          ///needs to be change
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
		if (cDirection == 0){
			iShowBMP2(0 + cx, 0 + cy, cStand, 0);
		}
		else if (cDirection == 1){
			iShowBMP2(0 + cx, 0 + cy, crotateStand, 0);
		}
	}

	if (running){
		if (frunning){
			if (!standing){
				iShowBMP2(0 + cx, 0 + cy, cRun[findex], 0);
				standCount++;
				if (standCount >= 10){
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
				if (standCount >= 10){
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
		else if (fall){
			iShowBMP2(0 + cx, 0 + cy, cFall[flindex], 0);
			if (flindex >= 9){
				fall = false;
				punch = false;
				flindex = 0;
				standing = true;
				kick = false;
			}


		}

		//========================================
		else if (kopping1){
			if (fKopping1){
				if (!standing){
					iShowBMP2(0 + cx, 0 + cy, ckop1[k1findex], 0);
				}

			}
			else if (bKopping1){//else if
				if (!standing){
					iShowBMP2(0 + cx, 0 + cy, cbKop[k1bindex], 0);
				

				}

			}
		}



		else if (kopping2){
			if (fKopping2){
				if (!standing){
					iShowBMP2(0 + cx, 0 + cy, cKop2[k2findex], 0);
				}

			}
			else if (bKopping2){//else if
				if (!standing){
					iShowBMP2(0 + cx, 0 + cy, cbKop[k2bindex], 0);


				}

			}

		
		}
		




		else if (kopping3){
			if (fKopping3){
				if (!standing){
					iShowBMP2(0 + cx, 0 + cy, cKop3[k3findex], 0);
				}

			}
			else if (bKopping3){//else if
				if (!standing){
					iShowBMP2(0 + cx, 0 + cy, cbKop[k3bindex], 0);


				}

			}
		
		}


		//===========================================
	}


}



//bot controll function
unsigned char key;
 int freeze = 0;

void botControl(){
	if (bx - cx <= 100  && bx-cx >=-100 && gamestate==9){
		int k = rand() % 4;
		key = k + '0';
		iKeyboard(key);

	}
	if (bx - cx > (rand() % 1000) + 100 && gamestate == 9){
		key = '8';
		freeze = 0;
		//int countee = rand() % 20;
		//while (countee--){
			iKeyboard(key);
		//}
	}
	else if (bx - cx > ((rand() % 1000) + 100) * -1 && bx - cx <-100 && gamestate == 9){
		key = '9';
		freeze=0;
		//int countee = rand() % 20;
		//while (countee--){
			iKeyboard(key);
		//}
	}
	
	else if (gamestate == 9){
		freeze++;
		cout << "freeze" << endl;
		if (freeze>10){
			if (bx - cx > 0){
				key = '8';
				iKeyboard(key);
				freeze = 0;
			}
			else{
				key = '9';
				iKeyboard(key);
				freeze = 0;
			}
		}

	}
	

}


//taking user input===========================================================

/*
void takingUserName(){





while (count1 == 0){

count1++;

//cout << "Enter your username: ";


str[strlen(str) - 1] = '\0';

for (int i = 0; str[i] != '\0'; i++){


if (str[i] == ' ' || (str[i] >= 'a'  && str[i] <= 'z')){
//cout << "CAUTION!!!! Invalid name input.Must not is any Space or Lower Case letter.TRY AGAIN!!!" << endl;

count1 = 0;

break;
}

}

}



FILE* file2 = fopen("AllUserName.txt", "a");

fputs(str, file2);
fputs("\n", file2);

fclose(file2);
}
*/
//taking user input ends==============================================================================================

//-------------------------------------------------------------------------------------------


//music function===============================================
void music(){
	if (musicOn){
		PlaySound("interstellar.wav", NULL, SND_ASYNC);
	}
}
//========================================

//functions end--------------------------------------------------------------------------------------------------------------------------------
//******************************************************************************************************************************************



















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

		

			iShowBMP(0, 0, play);      //play background
                           
	}

	else if (gamestate == 1){
		
						iShowBMP(0, 0, "NameInput.bmp");                //enter your name
						iText(700, 300, str, GLUT_BITMAP_TIMES_ROMAN_24);
						
						//iText(900, 300, str1, GLUT_BITMAP_TIMES_ROMAN_24);
						//takingUserName();
						//FILE * a = fopen("kgf.txt", "w");
					//	if (a)
						//{
						//	fputs(str, a);
							
						//}
						//fclose(a);

		
	}
	else if (gamestate == 2){
		
									iShowBMP(0, 0, highScore);             // highscore
								//	highScoreFunction();
									/*if (gamestate == 6 && h)
									{
										highScoreFunction();



									}*/
	}
	else if (gamestate == 3){
		
									iShowBMP(0, 0, "BackGround\\Instructions.bmp");                   //instruction
	}
	else if (gamestate == 4){                                   //about pannel
		
		                           iShowBMP(0, 0, inst);
								   iShowBMP(263, 500, "Buttons\\Romo.bmp");   //romo button
								   iShowBMP(1037, 500, "Buttons\\CutterMaruf.bmp");   //maruf button
								   iShowBMP(650, 180, "Buttons\\Credits.bmp");        //credit button
	}
	else if (gamestate == 5){
		
		                           iShowBMP(0, 0, name);        // option pannel  music
	}

	else if (gamestate == 6){

								   iShowBMP(0, 0, ro);     //romo character info
	}

	else if (gamestate == 7){

								   iShowBMP(0, 0, cutt);    //cutter maruf character info
	}

	else if (gamestate == 8){

								   iShowBMP(0, 0, "Credit.bmp");      //
	}


	else if (gamestate == 9){
									
									//musicOn = false;
								   iShowBMP(0, 0, lvl);   //level one pic 
								  // iShowBMP2(0, 0, "HeroS6.bmp", 0);

								   heroMovement();

								   botMovement();
								   
								    iShowImage(1277, 705, 210, 66, iLoadImage("BotLife1(png).png"));
								   iShowImage(1277+3, 700, (botLife / 5) + 5, 75, iLoadImage("BotLife2(png).png"));
								   iShowBMP2(1200, 700, "Bot.bmp", 0);

									iShowImage(210, 705, 203, 66, iLoadImage("HeroLife1(png).png"));
									iShowImage(210 + 3, 700, heroLife / 5, 75, iLoadImage("HeroLife2(png).png"));
									iShowBMP2(130, 700, "Hero.bmp", 0);
									if (heroLife <= 0 || botLife <= 0){
										gamestate = 13;
									}

									char s[100];
									sprintf(s, " %d", score);
									iSetColor(255, 255, 255);
									iText(750, 700, "SCORE : ", GLUT_BITMAP_TIMES_ROMAN_24);
									iText(750 + 100, 700, s, GLUT_BITMAP_TIMES_ROMAN_24);
								

	}

//;;;;;;;;;;;;;;;;;;;;;;;;;  stroy pannel


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
////////////////////////// story panel ends

	else if (gamestate == 10){                  //Exit   pannel
		//count2 = 0;
	//	file_line_counting();
	//	highscore_function();
		
		iShowBMP(0, 0, "BackGround\\MenuBackground.bmp");///menu_interface
		for (int i = 0; i < loop; i++){                                                                // Menu buttons

			iShowBMP2(bCordinate[i].x, bCordinate[i].y, button[i], 0);

		}

		iShowBMP2(299, 110, "Buttons\\Instruction.bmp", 0);

		iShowBMP2(1027, 110, "Buttons\\About.bmp", 0);

		iShowBMP2(100, 700, "Buttons\\Option.bmp", 0);

		iShowBMP(550, 250, "BackGround\\Sure.bmp");
		
		
		
	}
	else if (gamestate == 13){
		if (!botLife){
			iShowBMP2(300, 70, "YouWin.bmp", 0);
		}
		else if (!heroLife){
			iShowBMP2(300, 70, "GameOver.bmp", 0);
		}
	}


	


}
/////highscore


/*
//int highScore[5] = { 0, 0, 0, 0, 0 };
int count2 = 0;
void file_line_counting();
void highscore_function();

void highScoreFunction();

char s[100] = "120";
char s1[100] = "HIGHSCORE   ";
char *str = s;
int scoring = 0;

int showY = 500;
char showScore[1000];
char *showScorePointer = showScore;
char showScore1[1000];
char *showScorePointer1 = showScore1;
char showScore2[1000];
char *showScorePointer2 = showScore2;
char showScore3[1000];
char *showScorePointer3 = showScore3;
char showScore4[1000];
char *showScorePointer4 = showScore4;

void highscore_function(){
	if (count2 == 0)
	{
		FILE *fp = fopen("GAME_HIGHSCORE.txt", "w");

		fprintf(fp, "%d \n", score);
		fclose(fp);
	}

	else
	{
		FILE *fpRead = fopen("GAME_HIGHSCORE.txt", "r");
		int i = 0, x;
		while (fscanf(fpRead, "%d \n", &x) != EOF)
		{

			highScore[i] = x;
			i++;

		}
		fclose(fpRead);
		for (i = 0; i<5; i++)
		{
			if (score == highScore[i])
				break;
			if ( score>highScore[i])
			{
				// shift elements forward
				for (int j = 5 - 1; j > i; j--)
					highScore[j] = highScore[j - 1];

				// insert x at pos
				highScore[i] = score;
				break;

			}

		}
		FILE *fpWrite = fopen("GAME_HIGHSCORE.txt", "w");
		for (int i = 0; i < 5; i++)
			fprintf(fpWrite, "%d \n", highScore[i]);
		fclose(fpWrite);

	}
}

void file_line_counting()
{

	FILE *fp = fopen("GAME_HIGHSCORE.txt", "r");

	char c;


	for (c = getc(fp); c != EOF; c = getc(fp))
	if (c == '\n')
		count2 = count2 + 1;
	fclose(fp);



}

void highScoreFunction(){
	FILE *fpRead = fopen("GAME_HIGHSCORE.txt", "r");
	int i = 0, x;
	while (fscanf(fpRead, "%d \n", &x) != EOF)
	{

		highScore[i] = x;
		i++;

	}
	fclose(fpRead);

	iShowBMP(0, 0, "Highscore1.bmp");
	//iShowBMP2(200, 200, "200.bmp", 0);
	//	for (i = 0; i < 5; i++)
	//{
	sprintf(showScore, "%d", highScore[0]);

	iText(1100, 350, showScorePointer, GLUT_BITMAP_TIMES_ROMAN_24);

	sprintf(showScore1, "%d", highScore[1]);

	iText(1100, 270, showScorePointer1, GLUT_BITMAP_TIMES_ROMAN_24);

	sprintf(showScore2, "%d", highScore[2]);

	iText(1100, 190, showScorePointer2, GLUT_BITMAP_TIMES_ROMAN_24);
	sprintf(showScore3, "%d", highScore[3]);

	iText(1100, 110, showScorePointer3, GLUT_BITMAP_TIMES_ROMAN_24);
	sprintf(showScore4, "%d", highScore[4]);

	iText(1100, 30, showScorePointer4, GLUT_BITMAP_TIMES_ROMAN_24);

}




*/

//////highscore ends

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
			//musicOn = true;
			///mystro_menu_button
		}
		else if (mx >= 1200 && mx <= 1200 + 180 && my >= 50 && my <= 50 + 52 && (story == 1 || story == 2 || story == 3 || story == 4 || story == 5 || story == 0)){

			story++;
			gamestate--;
			if (story > 5)
				gamestate = -1;
			//musicOn = true;

		}

		else if (mx >= bCordinate[0].x && mx <= bCordinate[0].x + bsize_x && my >= bCordinate[0].y && my <= bCordinate[0].y + bsize_y && gamestate == -1){
			gamestate = 0;
			//musicOn = true;
			///versus background;
		}

		else if (mx >= 0 && mx <= 0 + 1600 && my >= 0 && my <= 0+800 && gamestate == 0){
			gamestate = 9;
			//musicOn = false;
			///level 1 background;
		}


		else if (mx >= bCordinate[1].x && mx <= bCordinate[1].x + bsize_x && my >= bCordinate[1].y && my <= bCordinate[1].y + bsize_y && gamestate == -1){

			gamestate = 1;
			//musicOn = true;
			///Interface_button2;
		}
		else if (mx >= bCordinate[2].x && mx <= bCordinate[2].x + bsize_x && my >= bCordinate[2].y && my <= bCordinate[2].y + bsize_y && gamestate == -1){
			gamestate = 2;
			//musicOn = true;
			///Interface_button3;
		}
		else if (mx >= 299 && mx <= 299 + bsize_x && my >= 110 && my <= 110 + bsize_y && gamestate == -1){
			gamestate = 3;
			//musicOn = true;
			///Interface_button4;
		}
		else if (mx >= 1027 && mx <= 1027 + bsize_x && my >= 110 && my <= 110 + bsize_y && gamestate == -1){     //about button
			gamestate = 4;
			about = 1;
			//musicOn = true;
		
			
		}
		else if (mx >= bCordinate[5].x && mx <= bCordinate[5].x + bsize_x && my >= bCordinate[5].y && my <= bCordinate[5].y + bsize_y && gamestate == -1){
			gamestate = 5;
			//musicOn = true;
			///Interface_button6;
		}

		else if (mx >= 263 && mx <= 263 + 357 && my >= 500 && my <= 500 + 111 && gamestate == 4 && about == 1){   //romo button
			
			gamestate = 6;
			//musicOn = true;
			
		}


		else if (mx >= 1037 && mx <= 1037 + 357 && my >= 500 && my <= 500 + 111 && gamestate == 4 && about == 1){ //cutter maruf button
			
			gamestate = 7;
			//musicOn = true;
			
		}


		else if (mx >= 650 && mx <= 650 + 357 && my >= 180 && my <= 180 + 111 && gamestate == 4 && about == 1){  //credits button
			
			gamestate = 8;
			musicOn = true;
			
		}


		else if (mx >= 1250 && mx <= 1250 + 344 && my >= 700 && my <= 700 + 74 && gamestate == -1){  //credits button

			gamestate = 10;
			//musicOn = true;

		}


		else if (mx >= 630 && mx <= 630 + 152 && my >= 368 && my <= 368 + 56  && gamestate == 10){  //credits button

			exit(0);
			

		}


		else if (mx >= 908 && mx <= 908 + 152 && my >= 368 && my <= 368 + 56 && gamestate == 10){  //credits button

			gamestate = -1;
			//musicOn = true;


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
		gamestate++;
	}
}




void iKeyboard(unsigned char key)
{

	if (key == 'b')
	{
		gamestate = -1;
	}
	if (gamestate == 1 && key != '\b'){
		str[txtindex] = key;
		txtindex++;
		str[txtindex] = '\0';
	}
	else{
		if (txtindex <= 0)
			txtindex = 0;
		else
			txtindex--;

		str[txtindex] = '\0';
	}

	if (gamestate == 9){
		
		if (key == 's')
		{
			//kindex++;
			botCollisionChecker();
			fall = false;
			running = false;
			kick = true;
			standing = false;
			punch = false;



			kopping3 = false;
			kopping1 = false;
			kopping2 = false;
			fKopping1 = false;
			fKopping2 = false;
			fKopping3 = false;
			bKopping1 = false;
			bKopping2 = false;
			bKopping3 = false;

		}

		if (key == 'a')
		{
			//pindex++;
			botCollisionChecker();
			fall = false;
			punch = true;
			running = false;
			standing = false;
			kick = false;





			kopping3 = false;
			kopping1 = false;
			kopping2 = false;
			fKopping1 = false;
			fKopping2 = false;
			fKopping3 = false;
			bKopping1 = false;
			bKopping2 = false;
			bKopping3 = false;


		}

		if (key == 'f')
		{
			//flindex++;
			fall = true;
			punch = false;
			running = false;
			standing = false;
			kick = false;




			kopping3 = false;
			kopping1 = false;
			kopping2 = false;
			fKopping1 = false;
			fKopping2 = false;
			fKopping3 = false;
			bKopping1 = false;
			bKopping2 = false;
			bKopping3 = false;

		}
		if (key == 'd')
		{
			//kindex++;
			botCollisionChecker();
			fall = false;
			running = false;
			kick = false;
			standing = false;
			punch = false;
			kopping1 = true;



			kopping3 = false;

			kopping2 = false;

			fKopping2 = false;
			fKopping3 = false;

			bKopping2 = false;
			bKopping3 = false;



			if (cDirection == 0){
				fKopping1 = true;
				bKopping1 = false;



			}
			else if (cDirection == 1){
				bKopping1 = true;
				fKopping1 = false;
			}


		}


		if (key == 'w')
		{
			//kindex++;
			botCollisionChecker();
			fall = false;
			running = false;
			kick = false;
			standing = false;
			punch = false;
			kopping2 = true;




			kopping3 = false;
			kopping1 = false;

			fKopping1 = false;

			fKopping3 = false;
			bKopping1 = false;

			bKopping3 = false;

			if (cDirection == 0){
				fKopping2 = true;
				bKopping2 = false;
			}
			else if (cDirection == 1){
				bKopping2 = true;
				fKopping2 = false;
			}


		}

		/*
		if (key == 's')
		{
		//kindex++;
		botCollisionChecker();
		fall = false;
		running = false;
		kick = false;
		standing = false;
		punch = false;
		kopping3 = true;
		kopping1 = false;
		kopping2 = false;
		fKopping1 = false;
		fKopping2 = false;
		bKopping1 = false;
		bKopping2 = false;


		if (cDirection == 0){
		fKopping3 = true;
		bKopping3 = false;
		}
		else if (cDirection == 1){
		bKopping3 = true;
		fKopping3 = false;
		}


		}
		*/
		/*
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
		*/

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
			bx += rand() % 200;
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
			bx -= rand() % 400;              ///edited from 200
			
			if (bbbindex >= 3){
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
	


}



int point_x = 663, point_y = 600;

void iSpecialKeyboard(unsigned char key)
{
	if (gamestate == 9){

		if (key == GLUT_KEY_RIGHT)
		{
			findex++;
			cx += 16;
			if (findex >= 6){
				findex = 0;
			}
			cDirection = 0;
			standing = false;
			running = true;
			frunning = true;
			brunning = false;
			fall = false;


		}
		if (key == GLUT_KEY_LEFT)
		{
			bindex++;
			cx -= 16;
			if (bindex >= 6){
				bindex = 0;
			}
			cDirection = 1;
			standing = false;
			running = true;
			brunning = true;
			frunning = false;
			fall = false;


		}
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
	
	     
		iSetTimer(100, autpSpriteChange);
		iSetTimer(70, autoBotChange); //edited form 100
		iSetTimer(rand() + (rand() % 500)/*+(rand() % 2000)*/, botControl);
		if (musicOn ){
			music();
		}

		
	iInitialize(screenWidth, screenHeight, "Project Title");

	iStart();
	return 0;
}
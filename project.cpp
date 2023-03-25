#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cmath>
#include<fstream>
using namespace std;
// globle variables
int scores[1000];
int scoreCount=0;
char sign = 198;
char sign3 = 206;
char box = 219;
char sign1 = 188;
char sign2 = 200;
char lifeChar=234;

int bulletX[100];
int bulletY[100];
int bulletCount = 0;
int enemyBulletX[100];
int enemyBulletY[100];
int enemyCount = 0;
int enemy1bulletx[100];
int enemy1bullety[100];
int enemy1Count = 0;
int enemy2bulletx[100];
int enemy2bullety[100];
int enemy2Count = 0;
int bigEnemyBulletX[100];
int bigEnemyBulletY[100];
int bigEnemyCount = 0;

bool printCheckEnemy1=true;
bool printCheckEnemy2=true;
bool printCheckEnemy3=true;
int shipX = 5;
int shipY = 13;

int enemyX = 98;
int enemyY = 10;

int enemy1X = 1;
int enemy1Y = 1;

int enemy2X = 97;
int enemy2Y = 4;

int bigEnemyX = 91;
int bigEnemyY = 10;

int randomEnemy1X=58;
int randomEnemy1Y=2;
int randomEnemy2X=58;
int randomEnemy2Y=8;
char randomEnemy=box;
int healthRandom1=10;
int healthRandom2=10;
int randomValue1=0;
int randomValue2=1;
bool random1=true;
bool random2=true;
bool eraseRandom1=true;
bool eraseRandom2=true;

int smartEnemyX=54;
int smartEnemyY=3;
int smartHealth=10;
bool smartEnemy=true;
bool eraseSmart=true;

string enemyDirection = "Up";
string enemy1Direction = "right";
string enemy2Direction = "left";
string bigEnemyDirection = "up";

int timerEnemyBullet1 = 0;
int timer2 = 0;
int timer3 = 0;
int timer = 0;
int timer4 = 0;
int timer5 = 0;
int timer7 = 0;
int timerSmart=0;
int timerLife=0;
bool timerRandom1=true;
bool timerRandom2=true;
int health = 20;
int score = 0;
int healthofenemy1 = 20;
int healthofenemy2 = 20;
int healthofenemy3 = 20;
int life = 3;
int healthofbigenemy = 30;
int count = 0;

bool enemy1Active = true;
bool enemy2Active = true;
bool enemy3Active = true;
bool bigEnemy = true;
bool printBig = true;
bool collision = false;
bool eraseEnemy1=true;
bool eraseEnemy2=true;
bool eraseEnemy3=true;
bool lifeRandom=true;
int randomValue;
// function
void gotoxy(int x, int y);
char getCharAtxy(short int x, short int y);
void printShip(char ship[][5]);
void eraseShip();
void printMaze();
void moveBullet();
void generateBullet();
void removeBulletFromArray(int index);
void moveShipUp(char ship[][5]);
void moveShipDown(char ship[][5]);
void moveShipLeft(char ship[][5]);
void moveShipRight(char ship[][5]);
//Enemy1 functions
void moveEnemy(char enemy[2][5]);
void printEnemy(char enemy[2][5]);
void eraseEnemy();
//enemy2 functions 
void moveenemy1( char enemy[2][5]);
void printenemy1(char enemy[2][5]);
void eraseenemy1();
//enemy3 functions
void moveenemy2( char enemy[2][5]);
void printenemy2(char enemy[2][5]);
void eraseenemy2();
//enemy1 bullets
void printenemybullet(int, int);
void eraseenemybullet(int, int);
void removeenemybulletfromarray(int);
void moveenemybullet();
void generateenemybullet();
void enemybulletcollisionwithplayer();
//enemy2 bullets
void generateenemy1bullet();
void moveenemy1bullet();
void enemy1bulletcollisionwithplayer();
void printenemy1bullet(int, int);
void eraseenemy1bullet(int, int);
void removeenemy1bulletfromarray(int);
//enemy3 bullets
void generateenemy2bullet();
void printenemy2bullet(int, int);
void eraseenemy2bullet(int, int);
void moveenemy2bullet();
void removeenemy2bulletfromarray(int);
void enemy2bulletcollisionwithplayer();
//big enemy  functions including bullets
void printbigenemy(char bigEnemy1[3][3]);
void erasebigenemy();
void moveBigEnemy(char bigEnemy1[3][3]);
void eraseBigBulletFromArray(int);
void generateBigEnemyBullet();
void bigBulletCollisionWithPlayer();
void moveBigBullet();
//random enemy functions
void printRandomEnemy1();
void printRandomEnemy2();
void moveRandomEnemy1();
void moveRandomEnemy2();
void eraseRandomEnemy1();
void eraseRandomEnemy2();
//smart enemy functions
void printSmartEnemy();
void eraseSmartEnemy();
void moveSmartEnemy();
float distance(int,int);
//details funnction
void addScore();//add score function
void printScore();//print score function
void printLife();//print life function
void minusLife();
int printLifeChar();
void eraseLifeChar();

void minushealth();
void printhealth();
// player functions
void bulletCollisionWithEnemy();
void printBullet(int x, int y);
void eraseBullet(int x, int y);
void printBigBullet(int, int);
void eraseBigBullet(int, int);
void playerCollisionWithEnemy(char ship[][5]);
//other functions 
void gameInterface();//function where game starts 
void header();
void colorontext(int num);
string menuOption();
void printGameOver();
string optionMenu();
void optionInterface();
void clearscreen();
void writeScore(int);
void loadScore();
void writeRecord();
void loadRecord();
int largestScore();
string gameOption();
void startGame();
void newGame();
void deletePlayerBullet();
void deleteBigEnemyBullet();
void deleteEnemy1Bullet();
void deleteEnemy3Bullet();
void writePlayerBullet();
void loadPlayerBullet();
void writeEnemyBullet();
void loadEnemyBullet();
void writeBigBullet();
void loadBigBullet();
main()
{ loadScore();
    system("cls");
    string option = "0";
    while (option != "3")
    { system("cls");
        header();
        option = menuOption();
        if (option == "1")
        {
            startGame();
        }
        if (option == "2")
        {
            system("cls");
            header();
            optionInterface();
        } 
        if (option == "3")
        {
            return 0;
        }
        clearscreen();
    }
}
// functions start here
void writeBigBullet()
{
    fstream file;
    file.open("big bullet.txt",ios::out);
    for(int i=0;i<bigEnemyCount;i++)
    {
        if(i<1)
        {
            file<<bigEnemyBulletX[i];
            file<<endl;
            file<<bigEnemyBulletY[i];
        }
        else
        {
            file<<endl;
            file<<bigEnemyBulletX[i];
            file<<endl;
            file<<bigEnemyBulletY[i];
        }
    }
    file.close();
}
void loadBigBullet()
{
    fstream file;
    file.open("big bullet.txt",ios::in);
        while(!file.eof())
        {
       file>>bigEnemyBulletX[bigEnemyCount];
       file>>bigEnemyBulletY[bigEnemyCount];
        bigEnemyCount++;
        }
    file.close();
}
void writeEnemyBullet()
{
   fstream file;
    file.open("enemy bullet.txt",ios::out);
    for(int i=0;i<enemyCount;i++)
    {
        if(i<1)
        {
            file<<enemyBulletX[i];
            file<<endl;
            file<<enemyBulletY[i];
        }
        else
        {
            file<<endl;
            file<<enemyBulletX[i];
            file<<endl;
            file<<enemyBulletY[i];
        }
    }
    file.close(); 
}
void loadEnemyBullet()
{
    fstream file;
    file.open("enemy bullet.txt",ios::in);
        while(!file.eof())
        {
       file>>enemyBulletX[enemyCount];
       file>> enemyBulletY[enemyCount];
        enemyCount++;
        }
    file.close();
}
void writePlayerBullet()
{
    fstream file;
    file.open("player bullet.txt",ios::out);
    for(int i=0;i<bulletCount;i++)
    {
        file<<bulletX[i]<<endl;
        file<<bulletY[i]<<endl;
    }
    file.close();
}
void loadPlayerBullet()
{
    fstream file;
    file.open("player bullet.txt",ios::in);
        while(!file.eof())
        {
        file>>bulletX[bulletCount];
        file>>bulletY[bulletCount];
        bulletCount++;
        }
    file.close();
}
void loadRecord()
{
    fstream file;
    file.open("record.txt",ios::in);
file>>printCheckEnemy1;
file>>printCheckEnemy2;
file>>printCheckEnemy3;
file>>smartEnemyX;
file>>smartEnemyY;
file>>smartHealth;
file>>smartEnemy;
 file>>eraseSmart;
 file>>eraseRandom1;
 file>>eraseRandom2;
 file>>randomEnemy1X;
 file>>randomEnemy1Y;
 file>>randomEnemy2X;
 file>>randomEnemy2Y;
 file>>randomEnemy;
 file>>healthRandom1;
 file>>healthRandom2;
 file>>randomValue1;
 file>>randomValue2;
 file>>random1;
 file>>random2;
 file>>timerRandom1;
 file>>timerRandom2;
 file>>shipX ;
 file>>shipY ;
 file>>enemyX ;
 file>>enemyY ;
 file>>enemy1X ;
 file>>enemy1Y;
 file>>enemy2X ;
 file>>enemy2Y;
 file>>bigEnemyX;
 file>>bigEnemyY ;
 file>> enemyDirection ;
 file>>enemy1Direction;
 file>>enemy2Direction ;
 file>>bigEnemyDirection;
 file>>timerEnemyBullet1;
 file>>timer2 ;
 file>>timer3 ;
 file>>timer ;
 file>>timer4 ;
 file>>timer5 ;
 file>>timer7 ;
 file>>timerLife;
 file>>health ;
 file>>score ;
 file>>healthofenemy1 ;
 file>>healthofenemy2;
 file>>healthofenemy3 ;
 file>>life ;
 file>>healthofbigenemy ;
 file>>count ;
 file>>enemy1Active;
 file>>enemy2Active;
 file>>enemy3Active;
 file>>bigEnemy ;
 file>>printBig ;
 file>>collision ;
 file>>eraseEnemy1;
 file>>eraseEnemy2;
file>>eraseEnemy3;
    file.close();
}
void deleteEnemy3Bullet()
{
    for(int i=0;i<enemy2Count;i++)
    {
    for(int j=0;j<enemy2Count;j++)
    {
        enemy2bulletx[j]=enemy2bulletx[j+1];
        enemy2bullety[j]=enemy2bullety[j+1];
    }
    enemy2Count--;
    }
    enemy2Count=0;
}
void deleteEnemy1Bullet()
{
        for(int i=0;i<enemyCount;i++)
    {
    for(int j=0;j<enemyCount;j++)
    {
        enemyBulletX[j]=enemyBulletX[j+1];
        enemyBulletY[j]=enemyBulletY[j+1];
    }
    enemyCount--;
    }
    enemyCount=0;
}
void deleteBigEnemyBullet()
{
   for(int i=0;i<bigEnemyCount;i++)
    {
    for(int j=0;j<bigEnemyCount;j++)
    {
        bigEnemyBulletX[j]=bigEnemyBulletX[j+1];
        bigEnemyBulletY[j]=bigEnemyBulletY[j+1];
    }
    bigEnemyCount--;
    }
    bigEnemyCount=0; 
}
void deletePlayerBullet()
{
    for(int i=0;i<bulletCount;i++)
    {
    for(int j=0;j<bulletCount;j++)
    {
        bulletX[j]=bulletX[j+1];
        bulletY[j]=bulletY[j+1];
    }
    bulletCount--;
    }
    bulletCount=0;
}
void writeRecord()
{
    fstream file;
    file.open("record.txt",ios::out);
    file<<printCheckEnemy1<<endl;
    file<<printCheckEnemy2<<endl;
file<<printCheckEnemy3<<endl;
  file<<  smartEnemyX<<endl;
file<<smartEnemyY<<endl;
file<<smartHealth<<endl;
file<<smartEnemy<<endl;
 file<<eraseSmart<<endl;
 file<<eraseRandom1<<endl;
 file<<eraseRandom2<<endl;
 file<<randomEnemy1X<<endl;
 file<<randomEnemy1Y<<endl;
 file<<randomEnemy2X<<endl;
 file<<randomEnemy2Y<<endl;
 file<<randomEnemy<<endl;
 file<<healthRandom1<<endl;
 file<<healthRandom2<<endl;
 file<<randomValue1<<endl;
 file<<randomValue2<<endl;
 file<<random1<<endl;
 file<<random2<<endl;
 file<<timerRandom1<<endl;
 file<<timerRandom2<<endl;
 file<<shipX <<endl;
 file<<shipY <<endl;
 file<<enemyX <<endl;
 file<<enemyY <<endl;
 file<<enemy1X <<endl;
 file<<enemy1Y <<endl;
 file<<enemy2X <<endl;
 file<<enemy2Y <<endl;
 file<<bigEnemyX <<endl;
 file<<bigEnemyY <<endl;
 file<< enemyDirection <<endl;
 file<<enemy1Direction <<endl;
 file<<enemy2Direction <<endl;
 file<<bigEnemyDirection <<endl;
 file<<timerEnemyBullet1 <<endl;
 file<<timer2 <<endl;
 file<<timer3 <<endl;
 file<<timer <<endl;
 file<<timer4 <<endl;
 file<<timer5 <<endl;
 file<<timer7 <<endl;
 file<<timerLife<<endl;
 file<<health <<endl;
 file<<score <<endl;
 file<<healthofenemy1 <<endl;
 file<<healthofenemy2 <<endl;
 file<<healthofenemy3 <<endl;
 file<<life <<endl;
 file<<healthofbigenemy <<endl;
 file<<count <<endl;
 file<<enemy1Active <<endl;
 file<<enemy2Active <<endl;
 file<<enemy3Active <<endl;
 file<<bigEnemy <<endl;
 file<<printBig <<endl;
 file<<collision <<endl;
 file<<eraseEnemy1<<endl;
 file<<eraseEnemy2<<endl;
file<<eraseEnemy3<<endl;

    file.close();

}
void newGame()
{
smartEnemyX=54;
smartEnemyY=3;
smartHealth=10;
smartEnemy=true;
 eraseSmart=true;
 eraseRandom1=true;
 eraseRandom2=true;
 randomEnemy1X=58;
 randomEnemy1Y=2;
 randomEnemy2X=58;
 randomEnemy2Y=8;
 randomEnemy=box;
 healthRandom1=10;
 healthRandom2=10;
 randomValue1=0;
 randomValue2=1;
 random1=true;
 random2=true;
 timerRandom1=true;
 timerRandom2=true;
 shipX = 5;
 shipY = 13;
 enemyX = 98;
 enemyY = 10;
 enemy1X = 1;
 enemy1Y = 1;
 enemy2X = 97;
 enemy2Y = 4;
 bigEnemyX = 91;
 bigEnemyY = 10;
  enemyDirection = "Up";
 enemy1Direction = "right";
 enemy2Direction = "left";
 bigEnemyDirection = "up";
 timerEnemyBullet1 = 0;
 timer2 = 0;
 timer3 = 0;
 timer = 0;
 timer4 = 0;
 timer5 = 0;
 timer7 = 0;
 timerLife=0;
 health = 20;
 score = 0;
 healthofenemy1 = 20;
 healthofenemy2 = 20;
 healthofenemy3 = 20;
 life = 3;
 healthofbigenemy = 30;
 count = 0;
 enemy1Active = true;
 enemy2Active = true;
 enemy3Active = true;
 bigEnemy = true;
 printBig = true;
 collision = false;
 eraseEnemy1=true;
 eraseEnemy2=true;
eraseEnemy3=true;
 gameInterface();

}
void startGame()
{
    string option="0";
    while(option!="3")
    {
        system("cls");
        header();
        option=gameOption();
        if(option=="1")
        {
            if((life == 0 || collision == true)||(healthofbigenemy==0))
            {
                deleteEnemy3Bullet();
            deleteEnemy1Bullet();
            deleteBigEnemyBullet();
            deletePlayerBullet();
                newGame();
            }
            else
            {
            loadRecord();
         if(healthofenemy1!=0)
            {
            loadEnemyBullet();
             }
            if(healthofbigenemy!=0 && printBig==false)
            {
            loadBigBullet();
            }
            loadPlayerBullet();
            gameInterface();
            }
            clearscreen();
        }
        if(option=="2")
        {   
            deleteEnemy3Bullet();
            deleteEnemy1Bullet();
            deleteBigEnemyBullet();
            deletePlayerBullet();
            newGame();
            clearscreen();
        }
    }
}
void moveSmartEnemy()
{
  float left = distance(smartEnemyX - 1,smartEnemyY );
    float right = distance(smartEnemyX + 1, smartEnemyY);
    float up = distance(smartEnemyX, smartEnemyY - 1);
    float down = distance(smartEnemyX, smartEnemyY + 1);
    if (left <= down && left <= right && left <= up)
    {
        char next = getCharAtxy(smartEnemyX - 1, smartEnemyY);
        if (next == ' ' || next == '.')
        {
            eraseSmartEnemy();
            smartEnemyX = smartEnemyX - 1;
            printSmartEnemy();
        }
    }
    else if (right <= down && right <= left && right <= up)
    {
        char next = getCharAtxy(smartEnemyX + 1, smartEnemyY);
        if (next == ' ' || next == '.')
        {
             eraseSmartEnemy();
            smartEnemyX = smartEnemyX + 1;
            printSmartEnemy();
        }
    }
    else if (down <= left && down <= right && down <= up)
    {
        char next = getCharAtxy(smartEnemyX, smartEnemyY + 1);
        if (next == ' ' || next == '.')
        {
            eraseSmartEnemy();
            smartEnemyY = smartEnemyY + 1;
            printSmartEnemy();
        }
    }
    else
    {
        char next = getCharAtxy(smartEnemyX, smartEnemyY - 1);
        if (next == ' ' || next == '.')
        {
            eraseSmartEnemy();
            smartEnemyY = smartEnemyY - 1;
            printSmartEnemy();
        }
    }

}


float distance(int x,int y)
{
    return sqrt(pow(shipX-x,2)+pow(shipY-y,2));
}

void printSmartEnemy()
{colorontext(1);    
gotoxy(smartEnemyX,smartEnemyY);
cout<< box;
colorontext(7);}
void eraseSmartEnemy()
{
gotoxy(smartEnemyX,smartEnemyY);
cout<< " ";
}

void eraseRandomEnemy1()
{
    gotoxy(randomEnemy1X,randomEnemy1Y);
    cout<< " ";
}
void eraseRandomEnemy2()
{
    gotoxy(randomEnemy2X,randomEnemy2Y);
    cout<<" ";
}
void moveRandomEnemy1()
{
    if(timerRandom1==false)
    {
 randomValue1=rand()%4;
 timerRandom1=true;
    }
 if(randomValue1==0)// for left
{
char next=getCharAtxy(randomEnemy1X-1,randomEnemy1Y);
if(next==' '|| next =='.')
{
eraseRandomEnemy1();
randomEnemy1X--;
printRandomEnemy1();
}
else
{
    timerRandom1=false;
}
}
if(randomValue1==1)//for right
{
  char next=getCharAtxy(randomEnemy1X+1,randomEnemy1Y);
if(next==' ' || next =='.')
{
eraseRandomEnemy1();
randomEnemy1X++;
printRandomEnemy1(); 
} 
else
{
    timerRandom1=false;
} 
}
if(randomValue1==2)//for up
{
char next=getCharAtxy(randomEnemy1X,randomEnemy1Y-1);
if(next==' ' || next=='.')
{
eraseRandomEnemy1();
randomEnemy1Y--;
printRandomEnemy1();  
}
else
{
    timerRandom1=false;
}
}
if(randomValue1==3)//for down
{
char next=getCharAtxy(randomEnemy1X,randomEnemy1Y+1);
if(next==' ' || next=='.')
{
eraseRandomEnemy1();
randomEnemy1Y++;
printRandomEnemy1(); 
}
else
{
    timerRandom1=false;
}
}
}

void moveRandomEnemy2()
{
   if (timerRandom2==false)
   {
randomValue2=rand()%4;
timerRandom2=true;
   }
 if(randomValue2==0)// for left
{
char next=getCharAtxy(randomEnemy2X-1,randomEnemy2Y);
if(next==' '|| next=='.')
{
eraseRandomEnemy2();
randomEnemy2X--;
printRandomEnemy2();
}
else
{
    timerRandom2=false;
}
}
if(randomValue2==1)//for right
{
  char next=getCharAtxy(randomEnemy2X+1,randomEnemy2Y);
if(next==' '|| next=='.')
{
eraseRandomEnemy2();
randomEnemy2X++;
printRandomEnemy2();   
} 
else
{
    timerRandom2=false;
} 
}
if(randomValue2==2)//for up
{
char next=getCharAtxy(randomEnemy2X,randomEnemy2Y-1);
if(next==' '|| next=='.')
{
eraseRandomEnemy2();
randomEnemy2Y--;
printRandomEnemy2();   
}
else
{
    timerRandom2=false;
}
}
if(randomValue2==3)//for down
{
char next=getCharAtxy(randomEnemy2X,randomEnemy2Y+1);
if(next==' ' || next=='.')
{
eraseRandomEnemy2();
randomEnemy2Y++;
printRandomEnemy2(); 
}
else
{
    timerRandom2=false;
}
}
}
void printRandomEnemy1()
{colorontext(4);
    gotoxy(randomEnemy1X,randomEnemy1Y);
    cout<<randomEnemy;
colorontext(7);}
void printRandomEnemy2()
{colorontext(4);
    gotoxy(randomEnemy2X,randomEnemy2Y);
    cout<<randomEnemy;
colorontext(7);}
void eraseLifeChar()
{
    gotoxy(58,16);
    cout<< " ";
}
int printLifeChar()
{
    // int randomValue;
    if(lifeRandom==true)
    {
     randomValue=rand()%4;
    lifeRandom=false;
    }
    if(randomValue==0)
    {
    char curr=getCharAtxy(58,16);
    if(curr==' ')
    {colorontext(6);
    gotoxy(58,16);
    cout<<lifeChar;
    colorontext(7);}
    }
    else if(randomValue==1)
    {
    char curr=getCharAtxy(67,7);
    if(curr==' ')
    {colorontext(6);
    gotoxy(67,7);
    cout<<lifeChar;
    colorontext(7);}
    }
    else if(randomValue==2)
    {
    char curr=getCharAtxy(22,5);
    if(curr==' ')
    {colorontext(6);
    gotoxy(22,5);
    cout<<lifeChar;
    colorontext(7);}
    }
    else if(randomValue==3)
    {
    char curr=getCharAtxy(2,5);
    if(curr==' ')
    {colorontext(6);
    gotoxy(2,5);
    cout<<lifeChar;
    colorontext(7);}
    }
    return randomValue;
}


void playerCollisionWithEnemy(char ship[][5])
{
    if (enemy1Active == true)
    {
        if ((shipX + 5 == enemyX && (shipY == enemyY || shipY == enemyY + 1)) || ((shipX + 2 == enemyX || shipX + 2 == enemyX + 1 || shipX + 2 == enemyX + 2 || shipX + 2 == enemyX + 3 || shipX + 2 == enemyX + 4) && (shipY == enemyY+2)) || ((enemyX + 2 == shipX || enemyX + 2 == shipX + 1 || enemyX + 2 == shipX + 2 || enemyX + 2 == shipX + 3 || enemyX + 2 == shipX + 4) && (enemyY  == shipY+2))||((enemyX  == shipX || enemyX  == shipX + 1 || enemyX  == shipX + 2 || enemyX  == shipX + 3 || enemyX  == shipX + 4) && (shipY  == enemyY+2)) || ((enemyX  == shipX || enemyX  == shipX + 1 || enemyX  == shipX + 2 || enemyX  == shipX + 3 || enemyX  == shipX + 4) && (shipY+2  == enemyY)))
        {
            health = 0;
            eraseShip();
            shipX = 5;
            shipY = 13;
            if (life > 0 && health <= 0)
        {
            health = 20;
            life--;
        }
            printShip(ship);
        }
    }
    if (enemy2Active == true)
    {
        if ((shipX + 6 == enemy1X && (shipY == enemy1Y || shipY == enemy1Y + 1)) || ((shipX + 2 == enemy1X || shipX + 2 == enemy1X + 1 || shipX + 2 == enemy1X + 2 || shipX + 2 == enemy1X + 3 || shipX + 2 == enemy1X + 4) && (shipY == enemy1Y+2)) || (shipX + 5 == enemy1X && (shipY == enemy1Y || shipY == enemy1Y + 1)) || (shipX -1 == enemy1X+5 && (shipY == enemy1Y || shipY == enemy1Y + 1)))
        {
            health = 0;
            eraseShip();
            shipX = 5;
            shipY = 13;
         if (life > 0 && health <= 0)
        {
            health = 20;
            life--;
        }
            printShip(ship);
        }
    }
    if (enemy3Active == true)
    {
        if ((shipX + 5 == enemy2X && (shipY == enemy2Y || shipY == enemy2Y + 1)) || ((shipX + 2 == enemy2X || shipX + 2 == enemy2X + 1 || shipX + 2 == enemy2X + 2 || shipX + 2 == enemy2X + 3 || shipX + 2 == enemy2X + 4) && (shipY == enemy2Y+2)) || (shipX + 5 == enemy2X && (shipY == enemy2Y || shipY == enemy2Y + 1)) || ((shipX -1 == enemy2X+5 ||shipX-1==enemy2X+4 || shipX -1 == enemy2X+3 || shipX -1 == enemy2X+2 || shipX -1 == enemy2X+1|| shipX -1 == enemy2X) && (shipY == enemy2Y || shipY == enemy2Y + 1)) ||(enemy2X + 5 == shipX && (enemy2Y == shipY || enemy2Y == shipY + 1)) || (enemy2X -1 == shipX+5 && (enemy2Y == shipY || enemy2Y == shipY + 1)) || ((enemy2X  == shipX || enemy2X  == shipX + 1 || enemy2X == shipX + 2 || enemy2X  == shipX + 3 || enemy2X == shipX + 4) && (enemy2Y == shipY+2)) || 
        ((enemy2X  == shipX || enemy2X  == shipX + 1 || enemy2X == shipX + 2 || enemy2X  == shipX + 3 || enemy2X == shipX + 4) && (enemy2Y+2 == shipY)) || ((enemy2X+2==shipX+2 ||enemy2X+3==shipX+3 ||enemy2X+4==shipX+4) && (shipY+1==enemy2Y+1 ||shipY==enemy2Y+1 ||enemy2Y==shipY+1)))
        {
            health = 0;
            eraseShip();
            shipX = 5;
            shipY = 13;
            printShip(ship);
        }
    }
    if (bigEnemy == true && enemy1Active == false && enemy2Active == false && enemy3Active == false)
    {
        if ((shipX + 5 == bigEnemyX && (shipY == bigEnemyY || shipY == bigEnemy + 1 ||shipY==bigEnemy+2))||((bigEnemyX + 2 == shipX || bigEnemyX + 2 == shipX + 1 || bigEnemyX + 2 == shipX + 2 || bigEnemyX + 2 == shipX + 3 || bigEnemyX + 2 == shipX + 4) && (bigEnemyY  == shipY+2)) ||((shipX + 2 == bigEnemyX || shipX + 2 == bigEnemyX + 1 || shipX + 2 == bigEnemyX + 2 || shipX + 2 == bigEnemyX + 3 || shipX + 2 == bigEnemyX + 4) && (shipY == bigEnemyY+2))|| (shipX -1 == bigEnemyX+5 && (shipY == bigEnemyY || shipY == bigEnemyY + 1 || shipY == bigEnemyY+2))||((bigEnemyX  == shipX || bigEnemyX  == shipX + 1 || bigEnemyX  == shipX + 2 || bigEnemyX  == shipX + 3 || bigEnemyX  == shipX + 4) && (shipY+2  == bigEnemyY)) || ((bigEnemyX  == shipX || bigEnemyX  == shipX + 1 || bigEnemyX  == shipX + 2 || bigEnemyX  == shipX + 3 || bigEnemyX  == shipX + 4) && (shipY  == bigEnemyY+3)))
        {
            health = 0;
            eraseShip();
            shipX = 5;
            shipY = 13;
            printShip(ship);
        }  
    }

    if (random1==true &&bigEnemy == true && enemy1Active == false && enemy2Active == false && enemy3Active == false)
    {
        if((shipX+5==randomEnemy1X &&( shipY==randomEnemy1Y ||shipY+1==randomEnemy1Y))||((randomEnemy1X==shipX ||randomEnemy1X==shipX+1 ||randomEnemy1X==shipX+2 || randomEnemy1X==shipX+3 || randomEnemy1X==shipX+4) && (randomEnemy1Y==shipY-1))||((randomEnemy1X==shipX ||randomEnemy1X==shipX+1 ||randomEnemy1X==shipX+2 || randomEnemy1X==shipX+3 || randomEnemy1X==shipX+4) && (randomEnemy1Y==shipY+2)) || (shipX-1==randomEnemy1X && (shipY==randomEnemy1Y || shipY+1==randomEnemy1Y)))
        {
            health = 0;
            eraseShip();
            shipX = 5;
            shipY = 13;
            printShip(ship); 
        }
    }
        if (random2==true && bigEnemy == true && enemy1Active == false && enemy2Active == false && enemy3Active == false)
    {
        if((shipX+5==randomEnemy2X &&( shipY==randomEnemy2Y ||shipY+1==randomEnemy2Y))||((randomEnemy2X==shipX ||randomEnemy2X==shipX+1 ||randomEnemy2X==shipX+2 || randomEnemy2X==shipX+3 || randomEnemy2X==shipX+4) && (randomEnemy2Y==shipY-1))||((randomEnemy2X==shipX ||randomEnemy2X==shipX+1 ||randomEnemy2X==shipX+2 || randomEnemy2X==shipX+3 || randomEnemy2X==shipX+4) && (randomEnemy2Y==shipY+2)) || (shipX-1==randomEnemy2X && (shipY==randomEnemy2Y || shipY+1==randomEnemy2Y)))
        {
            health = 0;
            eraseShip();
            shipX = 5;
            shipY = 13;
            printShip(ship); 
        }
    }

            if (smartEnemy==true && bigEnemy == true && enemy1Active == false && enemy2Active == false && enemy3Active == false)
    {
        if((shipX+5==smartEnemyX &&( shipY==smartEnemyY ||shipY+1==smartEnemyY))||((smartEnemyX==shipX ||smartEnemyX==shipX+1 ||smartEnemyX==shipX+2 || smartEnemyX==shipX+3 || smartEnemyX==shipX+4) && (smartEnemyY==shipY-1))||((smartEnemyX==shipX ||smartEnemyX==shipX+1 ||smartEnemyX==shipX+2 || smartEnemyX==shipX+3 || smartEnemyX==shipX+4) && (smartEnemyY==shipY+2)) || (shipX-1==smartEnemyX && (shipY==smartEnemyY || shipY+1==smartEnemyY)))
        {
            health = 0;
            eraseShip();
            shipX = 5;
            shipY = 13;
            printShip(ship);
            eraseSmartEnemy(); 
            smartEnemyX=54;
            smartEnemyY=3;
            printSmartEnemy();
        }
    }
}
void gameInterface()
{
    char ship[2][5] = {{' ', ' ', sign, ' ', ' '},{sign2, box, box, box, sign1}};
    char enemy[2][5] = {{' ', ' ', sign3, ' ', ' '}, {'(', '_', '_', '_', ')'}};
    char bigEnemy1[3][3] = {{' ', box, box},{box, box, box},{' ', box, box}};
    system("cls");
    printMaze();
    printShip(ship);
    if(printCheckEnemy1==true)
    {printCheckEnemy1=false;
        printEnemy(enemy);
    }
    if(printCheckEnemy2==true)
    {printCheckEnemy2=false;
        printenemy1(enemy);
    }
    if(printCheckEnemy3==true)
    {printCheckEnemy3=false;
        printenemy2(enemy);
    }
    
    while (true)
    {
        printhealth();
        printScore();
        printLife();
        if (GetAsyncKeyState(VK_LEFT))
        {
            moveShipLeft(ship);
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {
            moveShipRight(ship);
        }
        if (GetAsyncKeyState(VK_UP))
        {
            moveShipUp(ship);
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
            moveShipDown(ship);
        }
        if (GetAsyncKeyState(VK_ESCAPE) || (health == 0 && life == 0) || healthofbigenemy == 0)
        {
            break;
        }
        if (GetAsyncKeyState(VK_SPACE))
        {
            generateBullet();
        }
        if (enemy1Active == false && enemy2Active == false && enemy3Active == false && bigEnemy == true)
        {
            if (printBig == true)
            {
                printbigenemy(bigEnemy1);
                printBig = false;
                printRandomEnemy1();
                printRandomEnemy2();
                printSmartEnemy();
            }
            if (timer7 == 12)
            {

                generateBigEnemyBullet();
                timer7 = 0;
            }
            timer7++;
            moveBigBullet();
            if(random1==true)
            {
            moveRandomEnemy1();
            }
            if(random2==true)
            {
                moveRandomEnemy2();
            }
            moveBigEnemy(bigEnemy1);
            if(eraseSmart==true)
            {if(timerSmart==4)
            {
            moveSmartEnemy();
            timerSmart=0;
            }
            timerSmart++;
            }
        }
        if(smartHealth==0)
        {
            smartEnemy=false;
            if(eraseSmart==true)
            {
                eraseSmartEnemy();
                eraseSmart=false;
            }
        }

        if (enemy1Active == true)
        {
            if (timerEnemyBullet1 == 30)
            {
                generateenemybullet();
                timerEnemyBullet1 = 0;
            }
            if (timer == 3)
            {
                moveEnemy(enemy);
                timer = 0;
            }
        }
        if (enemy2Active == true)
        {
            if (timer2 == 20)
            {
                generateenemy1bullet();
                timer2 = 0;
            }
            if (timer4 == 3)
            {
                moveenemy1(enemy);
                timer4 = 0;
            }
        }
        if (life > 0 && health <= 0)
        {
            health = 20;
            life--;
            eraseShip();
            shipX=5;
            shipY=13;
            printShip(ship);
        }
        if (enemy3Active == true)
        {
            if (timer3 == 20)
            {
                generateenemy2bullet();
                timer3 = 0;
            }
            if (timer5 == 3)
            {
                moveenemy2(enemy);
                timer5 = 0;
            }
        }
        if (healthofenemy1 == 0)
        {
            enemy1Active = false;
            if(eraseEnemy1==true)
            {
            eraseEnemy();
            eraseEnemy1=false;
            }
        }
        if (healthofenemy2 == 0)
        {
            enemy2Active = false;
            if(eraseEnemy2==true)
            {
            eraseenemy1();
            eraseEnemy2=false;
            }
        }
        if (healthofenemy3 == 0)
        {
            enemy3Active = false;
            if(eraseEnemy3==true)
            {
            eraseenemy2();
            eraseEnemy3=false;
            }
        }
        if(healthRandom1==0)
        {
            random1=false;
            if(eraseRandom1==true)
            {
                eraseRandomEnemy1();
                eraseRandom1=false;
            }
        }
         if(healthRandom2==0)
        {
            random2=false;
            if(eraseRandom2==true)
            {
                eraseRandomEnemy2();
                eraseRandom2=false;
            }
        }
        if(timerLife>=350)
        {int result;
              result= printLifeChar();
              if(result==0)
              {
            if((shipX+5==58 && (shipY==16 || shipY+1==16)) || ((shipX==58 ||shipX+1==58 || shipX+2==58 ||shipX+3==58||shipX+4==58)&&(shipY+2==16))|| ((shipX-1==58 ) &&(shipY==16 ||shipY+1==16)))
            {
                eraseLifeChar();
                timerLife=0;
                if(life<4 && life>=0)
                {
                life++;
                }
                lifeRandom=true;
            }
              }
              if(result==1)
              {
             if((shipX+5==67 && (shipY==7 || shipY+1==7)) || ((shipX==67 ||shipX+1==67 || shipX+2==67 ||shipX+3==67||shipX+4==67)&&(shipY+2==7))|| ((shipX-1==67 ) &&(shipY==7 ||shipY+1==7)))
            {
                gotoxy(67,7);
                cout<<" ";
                timerLife=0;
                if(life<4 && life>=0)
                {
                life++;
                }
            lifeRandom=true;
            }
              }
              if(result==2)
              {
             if((shipX+5==22 && (shipY==5 || shipY+1==5)) || ((shipX==22 ||shipX+1==22 || shipX+2==22 ||shipX+3==22||shipX+4==22)&&(shipY+2==5))|| ((shipX-1==22 ) &&(shipY==5 ||shipY+1==5)))
            {
                gotoxy(22,5);
                cout<<" ";
                timerLife=0;
                if(life<4 && life>=0)
                {
                life++;
                }
                lifeRandom=true;
            }
              }
              if(result==3)
              {
             if((shipX+5==2 && (shipY==5 || shipY+1==5)) || ((shipX==2 ||shipX+1==2 || shipX+2==2 ||shipX+3==2||shipX+4==2)&&(shipY+2==5))|| ((shipX-1==2 ) &&(shipY==5 ||shipY+1==5)))
            {
                gotoxy(2,5);
                cout<<" ";
                timerLife=0;
                if(life<4 && life>=0)
                {
                life++;
                }
                lifeRandom=true;
            }
              }
 
        }

        moveenemybullet();
        moveenemy1bullet();
        moveenemy2bullet();
        enemy2bulletcollisionwithplayer();
        enemy1bulletcollisionwithplayer();
        enemybulletcollisionwithplayer();
        bigBulletCollisionWithPlayer();
        moveBullet();
        bulletCollisionWithEnemy();
        playerCollisionWithEnemy(ship);
        timer++;
        timerEnemyBullet1++;
        timer2++;
        timer3++;
        timer4++;
        timer5++;
        timerLife++;

        Sleep(30);
    }
    scores[scoreCount]=score;
    scoreCount++;
    writeScore(score);
    writePlayerBullet();
    writeBigBullet();
    writeEnemyBullet();
    writeRecord();
    system("cls");
    printGameOver();
    int largest=0;
    if (life == 0 || collision == true)
    {
        cout << endl
             << endl
             << "you lose the game" << endl<<endl;
                largest=largestScore();
                cout<<endl<<"Highest Score :"<<largest<<endl<<endl;
            cout<<endl<<"Your Score:"<<score<<endl;
    }
    else if (healthofbigenemy == 0)
    {
        cout << endl
             << endl
             << "you won the game" << endl<<endl;
                largest=largestScore();
                cout<<endl<<"Highest Score :"<<largest<<endl<<endl;
             cout<<endl<<"Your Score:"<<score<<endl;
    } 
    Sleep(300);
      
}
void bigBulletCollisionWithPlayer()
{
    for (int i = 0; i < bigEnemyCount; i++)
    {
        if (bigEnemyBulletX[i] - 1 == shipX + 5 && (bigEnemyBulletY[i] == shipY || bigEnemyBulletY[i] == shipY + 1))
        {
            health = health - 5;
            eraseBigBullet(bigEnemyBulletX[i], bigEnemyBulletY[i]);
            eraseBigBulletFromArray(i);
        }
    }
}
void moveBigEnemy(char bigEnemy1[3][3])
{
    if (bigEnemyDirection == "up")
    {
        char next = getCharAtxy(bigEnemyX, bigEnemyY - 1);
        if (next == ' ')
        {
            erasebigenemy();
            bigEnemyY--;
            printbigenemy(bigEnemy1);
        }
        else if (next == '#')
        {
            bigEnemyDirection = "down";
        }
    }
    if (bigEnemyDirection == "down")
    {
        char next = getCharAtxy(bigEnemyX, bigEnemyY + 3);
        if (next == ' ')
        {
            erasebigenemy();
            bigEnemyY++;
            printbigenemy(bigEnemy1);
        }
        else if (next == '#')
        {
            bigEnemyDirection = "up";
        }
    }
}
void erasebigenemy()
{
    gotoxy(bigEnemyX, bigEnemyY);
    for (int i = 0; i < 3; i++)
    {
        cout << " ";
    }
    cout << endl;
    gotoxy(bigEnemyX, bigEnemyY + 1);
    for (int i = 0; i < 3; i++)
    {
        cout << " ";
    }
    cout << endl;
    gotoxy(bigEnemyX, bigEnemyY + 2);
    for (int i = 0; i < 3; i++)
    {
        cout << " ";
    }
    cout << endl;
}
void printbigenemy(char bigEnemy1[3][3])
{
    if (healthofbigenemy > 10)
    {colorontext(5);
        gotoxy(bigEnemyX, bigEnemyY);
        for (int i = 0; i < 3; i++)
        {
            cout  << bigEnemy1[0][i];
        }
        cout << endl;
        gotoxy(bigEnemyX, bigEnemyY + 1);
        for (int i = 0; i < 3; i++)
        {
            cout << bigEnemy1[1][i] ;
        }
        cout << endl;
        gotoxy(bigEnemyX, bigEnemyY + 2);
        for (int i = 0; i < 3; i++)
        {
            cout << bigEnemy1[2][i] ;
        }
        cout << endl;
    colorontext(7);}
    if (healthofbigenemy <= 10)
    {colorontext(4);
        gotoxy(bigEnemyX, bigEnemyY);
        for (int i = 0; i < 3; i++)
        {
            cout  << bigEnemy1[0][i] ;
        }
        cout << endl;
        gotoxy(bigEnemyX, bigEnemyY + 1);
        for (int i = 0; i < 3; i++)
        {
            cout  << bigEnemy1[1][i] ;
        }
        cout << endl;
        gotoxy(bigEnemyX, bigEnemyY + 2);
        for (int i = 0; i < 3; i++)
        {
            cout  << bigEnemy1[2][i];
        }
        cout << endl;
    colorontext(7);}
}
void moveenemy2bullet()
{
    for (int i = 0; i < enemy2Count; i++)
    {
        char next = getCharAtxy(enemy2bulletx[i] - 1, enemy2bullety[i]);
        if (next != ' ')
        {
            eraseenemy2bullet(enemy2bulletx[i], enemy2bullety[i]);
            removeenemy2bulletfromarray(i);
        }
        else
        {
            eraseenemy2bullet(enemy2bulletx[i], enemy2bullety[i]);
            enemy2bulletx[i] = enemy2bulletx[i] - 1;
            printenemy2bullet(enemy2bulletx[i], enemy2bullety[i]);
        }
    }
}

void enemy2bulletcollisionwithplayer()
{
    for (int i = 0; i < enemy2Count; i++)
    {
        if (enemy2bulletx[i] - 1 == shipX + 5 && (enemy2bullety[i] == shipY || enemy2bullety[i] == shipY + 1))
        {
            minushealth();
            eraseenemy2bullet(enemy2bulletx[i], enemy2bullety[i]);
            removeenemy2bulletfromarray(i);
        }
    }
}
void printenemy2bullet(int x, int y)
{
    gotoxy(x, y);
    cout << "*";
}
void eraseenemy2bullet(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}
void generateenemy2bullet()
{
    char next = getCharAtxy(enemy2X - 1, enemy2Y);
    if (next == ' ')
    {
        enemy2bulletx[enemy2Count] = enemy2X - 1;
        enemy2bullety[enemy2Count] = enemy2Y;
        enemy2Count++;
    }
}
void removeenemy2bulletfromarray(int x)
{
    for (int i = x; i < enemy2Count - 1; i++)
    {
        enemy2bulletx[i] = enemy2bulletx[i + 1];
        enemy2bullety[i] = enemy2bullety[i + 1];
    }
    enemy2Count--;
}
void printenemy2(char enemy[2][5])
{
    if (healthofenemy3 > 7)
    {colorontext(5);
        gotoxy(enemy2X, enemy2Y);
        for (int i = 0; i < 5; i++)
        {
            cout  << enemy[0][i] ;
        }
        cout << endl;
        gotoxy(enemy2X, enemy2Y + 1);
        for (int i = 0; i < 5; i++)
        {
            cout  << enemy[1][i];
        }
        cout << endl;
   colorontext(7); }
    else if (healthofenemy3 <= 7)
    {colorontext(4);
        gotoxy(enemy2X, enemy2Y);
        for (int i = 0; i < 5; i++)
        {
            cout << enemy[0][i] ;
        }
        cout << endl;
        gotoxy(enemy2X, enemy2Y + 1);
        for (int i = 0; i < 5; i++)
        {
            cout << enemy[1][i] ;
        }
        cout << endl;
    colorontext(7);}
}
void eraseenemy2()
{
    gotoxy(enemy2X, enemy2Y);
    for (int i = 0; i < 5; i++)
    {
        cout << " ";
    }
    cout << endl;
    gotoxy(enemy2X, enemy2Y + 1);
    for (int i = 0; i < 5; i++)
    {
        cout << " ";
    }
    cout << endl;
}
void moveenemy2(char enemy[2][5])
{
    if (enemy2Direction == "left")
    {
        if (count == 0)
        {
            char next = getCharAtxy(enemy2X - 8, enemy2Y + 2);
            if (next == '#')
            {
                count++;
            }
            if (next != '#' && count == 0)
            {
                eraseenemy2();
                enemy2X = enemy2X - 7;
                enemy2Y = enemy2Y + 1;
                printenemy2(enemy);
            }
        }
        if (count == 1)
        {
            char next = getCharAtxy(enemy2X - 2, enemy2Y - 1);
            if (next == '#')
            {
                count++;
            }
            if (next != '#')
            {
                eraseenemy2();
                enemy2X = enemy2X - 2;
                enemy2Y = enemy2Y - 1;
                printenemy2(enemy);
            }
        }

        if (count == 2)
        {
            count = 0;
            enemy2Direction = "right";
        }
    }
    if (enemy2Direction == "right")
    {
        if (count == 0)
        {
            char next = getCharAtxy(enemy2X + 7, enemy2Y + 2);
            if (next == '#')
            {
                count++;
            }
            if (next != '#' && count == 0)
            {
                eraseenemy2();
                enemy2X = enemy2X + 2;
                enemy2Y = enemy2Y + 1;
                printenemy2(enemy);
            }
        }
        if (count == 1)
        {
            char next = getCharAtxy(enemy2X + 8, enemy2Y - 2);
            if (next == '#')
            {
                count++;
            }
            if (next != '#')
            {
                eraseenemy2();
                enemy2X = enemy2X + 7;
                enemy2Y = enemy2Y - 1;
                printenemy2(enemy);
            }
        }
        if (count == 2)
        {
            count = 0;
            enemy2Direction = "left";
        }
    }
}

void removeenemy1bulletfromarray(int x)
{
    for (int i = x; i < enemy1Count - 1; i++)
    {
        enemy1bulletx[i] = enemy1bulletx[i + 1];
        enemy1bullety[i] = enemy1bullety[i + 1];
    }
    enemy1Count--;
}
void moveenemy1bullet()
{
    for (int i = 0; i < enemy1Count; i++)
    {
        char next = getCharAtxy(enemy1bulletx[i], enemy1bullety[i] + 1);
        if (next != ' ')
        {
            eraseenemy1bullet(enemy1bulletx[i], enemy1bullety[i]);
            removeenemy1bulletfromarray(i);
        }
        else
        {
            eraseenemy1bullet(enemy1bulletx[i], enemy1bullety[i]);
            enemy1bullety[i] = enemy1bullety[i] + 1;
            printenemy1bullet(enemy1bulletx[i], enemy1bullety[i]);
        }
    }
}
void enemy1bulletcollisionwithplayer()
{
    for (int i = 0; i < enemy1Count; i++)
    {
        if (enemy1bullety[i] + 1 == shipY && (enemy1bulletx[i] == shipX || enemy1bulletx[i] == shipX + 1 || enemy1bulletx[i] == shipX + 2 || enemy1bulletx[i] == shipX + 3 || enemy1bulletx[i] == shipX + 4))
        {
            health--;
            eraseenemy1bullet(enemy1bulletx[i], enemy1bullety[i]);
            removeenemy1bulletfromarray(i);
        }
    }
}
void eraseenemy1bullet(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}
void printenemy1bullet(int x, int y)
{
    gotoxy(x, y);
    cout << "*";
}
void printenemy1(char enemy[2][5])
{
    if (healthofenemy2 > 7)
    {colorontext(5);
        gotoxy(enemy1X, enemy1Y);
        for (int i = 0; i < 5; i++)
        {
            cout  << enemy[0][i];
        }
        cout << endl;
        gotoxy(enemy1X, enemy1Y + 1);
        for (int i = 0; i < 5; i++)
        {
            cout  << enemy[1][i] ;
        }
        cout << endl;
   colorontext(7); }
    else if (healthofenemy2 <= 7)
    {colorontext(4);
        gotoxy(enemy1X, enemy1Y);
        for (int i = 0; i < 5; i++)
        {
            cout  << enemy[0][i] ;
        }
        cout << endl;
        gotoxy(enemy1X, enemy1Y + 1);
        for (int i = 0; i < 5; i++)
        {
            cout  << enemy[1][i] ;
        }
        cout << endl;
    colorontext(7);}
}
void eraseenemy1()
{
    gotoxy(enemy1X, enemy1Y);
    for (int i = 0; i < 5; i++)
    {
        cout << " ";
    }
    cout << endl;
    gotoxy(enemy1X, enemy1Y + 1);
    for (int i = 0; i < 5; i++)
    {
        cout << " ";
    }
    cout << endl;
}
void moveenemy1(char enemy[2][5])
{
    if (enemy1Direction == "left")
    {
        char next1 = getCharAtxy(enemy1X - 1, enemy1Y);
        if (next1 != '#')
        {
            eraseenemy1();
            enemy1X--;
            printenemy1(enemy);
        }
        else if (next1 == '#')
        {
            enemy1Direction = "right";
        }
    }
    if (enemy1Direction == "right")
    {
        char next1 = getCharAtxy(enemy1X + 5, enemy1Y);
        if (next1 != '#')
        {
            eraseenemy1();
            enemy1X++;
            printenemy1(enemy);
        }
        else if (next1 == '#')
        {
            enemy1Direction = "left";
        }
    }
}
void generateenemy1bullet()
{
    char next = getCharAtxy(enemy1X, enemy1Y + 2);
    if (next == ' ')
    {
        enemy1bulletx[enemy1Count] = enemy1X;
        enemy1bullety[enemy1Count] = enemy1Y + 2;
        gotoxy(enemy1X, enemy1Y + 2);
        cout << "*";
        enemy1Count++;
    }
}
void printScore()
{
    gotoxy(109, 8);
    cout << "score: " << score;
}
void printhealth()
{
    gotoxy(109, 10);
    cout << "Health: " << health << " ";
}
void minushealth()
{
    health = health - 1;
}
void moveEnemy(char enemy[2][5])
{
    if (enemyDirection == "Up")
    {
        char next = getCharAtxy(enemyX, enemyY - 1);
        if (next != '#')
        {
            eraseEnemy();
            enemyY--;
            printEnemy(enemy);
        }
        if (next == '#')
        {
            enemyDirection = "Down";
        }
    }
    if (enemyDirection == "Down")
    {
        char next = getCharAtxy(enemyX, enemyY + 2);
        if (next != '#')
        {
            eraseEnemy();
            enemyY++;
            printEnemy( enemy);
        }
        if (next == '#')
        {
            enemyDirection = "Up";
        }
    }
}
void printEnemy(char enemy[2][5])
{
    if (healthofenemy1 > 7)
    {colorontext(5);
        gotoxy(enemyX, enemyY);
        for (int index = 0; index < 5; index++)
        {
            cout  << enemy[0][index] ;
        }
        gotoxy(enemyX, enemyY + 1);
        for (int index = 0; index < 5; index++)
        {
            cout  << enemy[1][index];
        }
        cout << endl;
   colorontext(7); }
    else if (healthofenemy1 <= 7)
    {colorontext(4);
        gotoxy(enemyX, enemyY);
        for (int index = 0; index < 5; index++)
        {
            cout  << enemy[0][index];
        }
        gotoxy(enemyX, enemyY + 1);
        for (int index = 0; index < 5; index++)
        {
            cout << enemy[1][index];
        }
        cout << endl;
    colorontext(7);}
}
void eraseEnemy()
{
    gotoxy(enemyX, enemyY);
    for (int index = 0; index < 6; index++)
    {
        cout << " ";
    }
    cout<<endl;
    gotoxy(enemyX, enemyY + 1);
    for (int index = 0; index < 6; index++)
    {
        cout << " ";
    }
}
void moveShipLeft(char ship[][5])
{
    char next = getCharAtxy(shipX - 1, shipY);
    if (next == ' ')
    {
        eraseShip();
        shipX = shipX - 1;
        printShip(ship);
    }
}
void moveShipRight(char ship[][5])
{
    char next = getCharAtxy(shipX + 6, shipY);
    if (next == ' ')
    {
        eraseShip();
        shipX = shipX + 1;
        printShip(ship);
    }
}
void moveShipUp(char ship[][5])
{
    char next = getCharAtxy(shipX, shipY - 1);
    if (next == ' ')
    {
        eraseShip();
        shipY = shipY - 1;
        printShip(ship);
    }
}
void moveShipDown( char ship[][5])
{
    char next = getCharAtxy(shipX, shipY + 2);
    if (next == ' ')
    {
        eraseShip();
        shipY = shipY + 1;
        printShip(ship);
    }
}
void generateBullet()
{
    if (shipX < 98)
    {
        bulletX[bulletCount] = shipX + 7;
        bulletY[bulletCount] = shipY;
        gotoxy(shipX + 7, shipY);
        cout << ".";
        bulletCount++;
    }
}
void removeBulletFromArray(int index)
{
    for (int x = index; x < bulletCount - 1; x++)
    {
        bulletX[x] = bulletX[x + 1];
        bulletY[x] = bulletY[x + 1];
    }
    bulletCount--;
}
void printShip(char ship[][5])
{

if(health>7)
{
    colorontext(2);
gotoxy(shipX,shipY);
for(int i=0;i<5;i++)
{
    cout<<ship[0][i];
}
cout<<endl;
gotoxy(shipX,shipY+1);
for(int i=0;i<5;i++)
{
    cout<< ship[1][i];
}
    colorontext(7);
}
if(health<=7)
{
    colorontext(4);
gotoxy(shipX,shipY);
for(int i=0;i<5;i++)
{
    cout<<ship[0][i];
}
cout<<endl;
gotoxy(shipX,shipY+1);
for(int i=0;i<5;i++)
{
    cout<< ship[1][i];
}
    colorontext(7);
}
}
void eraseShip()
{
gotoxy(shipX,shipY);
for(int i=0;i<5;i++)
{
    cout<<" ";
}
cout<<endl;
gotoxy(shipX,shipY+1);
for(int i=0;i<5;i++)
{
    cout<<" ";
}
}
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
void printMaze()
{colorontext(1);
    cout<< "##########################################################################################################"<< endl;
    cout << "#                                                                                                        #"<< endl;
    cout << "#                                                                                                        #"<< endl;
    cout<< "#                                                                                                        #"<< endl;
    cout << "#                                                                                                        #" << endl;
    cout<< "#                                                                                                        #"<< endl;
    cout<< "#                                                                                                        #"<< endl;
    cout<< "#                                                                                                        #"<< endl;
    cout<< "#                                                                                                        #" << endl;
    cout<< "#                                                                                                        #" << endl;
    cout<< "#                                                                                                        #" << endl;
    cout<< "#                                                                                                        #"<< endl;
    cout<< "#                                                                                                        #" << endl;
    cout<< "#                                                                                                        #"<< endl;
    cout<< "#                                                                                                        #" << endl;
    cout<< "#                                                                                                        #"<< endl;
    cout<< "#                                                                                                        #"<< endl;
    cout<< "##########################################################################################################" << endl;
colorontext(7);}
void moveBullet()
{
    for (int x = 0; x < bulletCount; x++)
    {
        char next = getCharAtxy(bulletX[x] + 1, bulletY[x]);
        if (next != ' ')
        {
            eraseBullet(bulletX[x], bulletY[x]);
            removeBulletFromArray(x);
        }
        else
        {
            eraseBullet(bulletX[x], bulletY[x]);
            bulletX[x] = bulletX[x] + 1;
            printBullet(bulletX[x], bulletY[x]);
        }
    }
}
void printBullet(int x, int y)
{
    gotoxy(x, y);
    cout << ".";
}
void eraseBullet(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}
void bulletCollisionWithEnemy()
{
    for (int x = 0; x < bulletCount; x++)
    {
        if (bulletX[x] + 1 == enemyX && (bulletY[x] == enemyY || bulletY[x] == enemyY + 1))
        {
            if (enemy1Active == true)
            {
                addScore();
                eraseBullet(bulletX[x], bulletY[x]);
                removeBulletFromArray(x);
                healthofenemy1--;
            }
        }
        if (bulletX[x] + 1 == enemy1X && (bulletY[x] == enemy1Y || bulletY[x] == enemy1Y + 1))
        {
            if (enemy2Active == true)
            {
                addScore();
                eraseBullet(bulletX[x], bulletY[x]);
                removeBulletFromArray(x);
                healthofenemy2--;
            }
        }
        if (bulletX[x] + 1 == enemy2X && (bulletY[x] == enemy2Y || bulletY[x] == enemy2Y + 1))
        {
            if (enemy3Active == true)
            {
                addScore();
                eraseBullet(bulletX[x], bulletY[x]);
                removeBulletFromArray(x);
                healthofenemy3--;
            }
        }
        if (bulletX[x] + 1 == bigEnemyX && (bulletY[x] == bigEnemyY || bulletY[x] == bigEnemyY + 1))
        {
            if (bigEnemy == true && enemy1Active == false && enemy2Active == false && enemy3Active == false)
            {
                addScore();
                eraseBullet(bulletX[x], bulletY[x]);
                removeBulletFromArray(x);
                healthofbigenemy--;
            }
        }

        if(bulletX[x]+1==randomEnemy1X &&bulletY[x]==randomEnemy1Y)
        {
            if (random1 == true && enemy1Active == false && enemy2Active == false && enemy3Active == false)
            {
            addScore();
            eraseBullet(bulletX[x], bulletY[x]);
             removeBulletFromArray(x);
             healthRandom1--;
            } 
        }

         if(bulletX[x]+1==randomEnemy2X &&bulletY[x]==randomEnemy2Y)
        {
            if (random2 == true && enemy1Active == false && enemy2Active == false && enemy3Active == false)
            {
            addScore();
            eraseBullet(bulletX[x], bulletY[x]);
             removeBulletFromArray(x);
             healthRandom2--;
            } 
        }
        if(bulletX[x]+1==smartEnemyX &&bulletY[x]==smartEnemyY)
        {
            if (smartEnemy == true && enemy1Active == false && enemy2Active == false && enemy3Active == false)
            {
            addScore();
             eraseBullet(bulletX[x], bulletY[x]);
             removeBulletFromArray(x);
            smartHealth--;
            }
        }
    }
}
void addScore()
{
    score++;
}
char getCharAtxy(short int x, short int y)
{
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coordBufSize;
    coordBufSize.X = 1;
    coordBufSize.Y = 1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}
void eraseenemybullet(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}
void printenemybullet(int x, int y)
{
    gotoxy(x, y);
    cout << "*";
}
void moveenemybullet()
{
    for (int i = 0; i < enemyCount; i++)
    {
        char next = getCharAtxy(enemyBulletX[i] - 1, enemyBulletY[i]);

        if (next != ' ')
        {
            eraseenemybullet(enemyBulletX[i], enemyBulletY[i]);
            removeenemybulletfromarray(i);
        }
        else
        {
            eraseenemybullet(enemyBulletX[i], enemyBulletY[i]);
            enemyBulletX[i] = enemyBulletX[i] - 1;
            printenemybullet(enemyBulletX[i], enemyBulletY[i]);
        }
    }
}
void removeenemybulletfromarray(int x)
{
    for (int i = x; i < enemyCount - 1; i++)
    {
        enemyBulletX[i] = enemyBulletX[i + 1];
        enemyBulletY[i] = enemyBulletY[i + 1];
    }
    enemyCount--;
}
void generateenemybullet()
{
    char next = getCharAtxy(enemyX - 2, enemyY + 1);
    if (next == ' ')
    {
        enemyBulletX[enemyCount] = enemyX - 1;
        enemyBulletY[enemyCount] = enemyY + 1;
        gotoxy(enemyX - 1, enemyY + 1);
        cout << "*";
        enemyCount++;
    }
}
void enemybulletcollisionwithplayer()
{
    for (int i = 0; i < enemyCount; i++)
    {
        if (enemyBulletX[i] - 1 == shipX + 5 && (enemyBulletY[i] == shipY || enemyBulletY[i] == shipY + 1))
        {
            minushealth();
            eraseenemybullet(enemyBulletX[i], enemyBulletY[i]);
            removeenemybulletfromarray(i);
        }
    }
}
void printBigBullet(int x, int y)
{
    gotoxy(x, y);
    cout << "@";
}
void eraseBigBullet(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}
void moveBigBullet()
{

    for (int i = 0; i < bigEnemyCount; i++)
    {
        char next = getCharAtxy(bigEnemyBulletX[i] - 1, bigEnemyBulletY[i]);

        if (next != ' ')
        {
            eraseBigBullet(bigEnemyBulletX[i], bigEnemyBulletY[i]);
            eraseBigBulletFromArray(i);
        }
        else 
        {
            eraseBigBullet(bigEnemyBulletX[i], bigEnemyBulletY[i]);
            bigEnemyBulletX[i] = bigEnemyBulletX[i] - 1;
            printBigBullet(bigEnemyBulletX[i], bigEnemyBulletY[i]);
        }
    }
}
void eraseBigBulletFromArray(int x)
{
    for (int i = x; i < bigEnemyCount - 1; i++)
    {
        bigEnemyBulletX[i] = bigEnemyBulletX[i + 1];
        bigEnemyBulletY[i] = bigEnemyBulletY[i + 1];
    }
    bigEnemyCount--;
}
void generateBigEnemyBullet()
{
    char next = getCharAtxy(bigEnemyX - 1, bigEnemyY + 1);
    if (next == ' ')
    {
        bigEnemyBulletX[bigEnemyCount] = bigEnemyX - 1;
        bigEnemyBulletY[bigEnemyCount] = bigEnemyY + 1;
        gotoxy(bigEnemyX - 1, bigEnemyY + 1);
        cout << "@";
        bigEnemyCount++;
    }
}
void printLife()
{
    gotoxy(109, 12);
    cout << "life remaining: " << life;
}
void minusLife()
{
    life--;
}
int largestScore()
{
    int largest=scores[0];
    for(int i=1;i<scoreCount;i++)
    {
        
        if(largest<scores[i])
        {
            largest=scores[i];
        }
        
    }
    return largest;
}
void loadScore()
{
    fstream file;
    file.open("score data.txt",ios::in);
    while(!file.eof())
    {
        file>>scores[scoreCount];
        scoreCount++;
    }
    file.close();
}
void writeScore(int score)
{
fstream file;
file.open("score data.txt",ios::app);
file<<score<<endl;
file.close();
}
void header()
{
    colorontext(3);
    cout << " ## ##   ###  ##    ####   ### ##            ##   ##    ##     ### ##  " << endl;
    cout << "##   ##   ##  ##     ##     ##  ##           ##   ##     ##     ##  ## " << endl;
    cout << "####      ##  ##     ##     ##  ##           ##   ##   ## ##    ##  ## " << endl;
    cout << " #####    ## ###     ##     ##  ##           ## # ##   ##  ##   ## ##  " << endl;
    cout << "    ###   ##  ##     ##     ## ##            # ### #   ## ###   ## ##  " << endl;
    cout << "##   ##   ##  ##     ##     ##                ## ##    ##  ##   ##  ## " << endl;
    cout << " ## ##   ###  ##    ####   ####              ##   ##  ###  ##  #### ## " << endl;
    colorontext(7);
}
void colorontext(int num)
{ 
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, num);
}
string menuOption()
{
    cout << "Select one of the following: " << endl;
    cout << "1.Start game" << endl;
    cout << "2.Option" << endl;
    cout << "3.exit" << endl;
    string option;
    cout << "Option:";
    cin >> option;
    return option;
}
void printGameOver()
{   colorontext(3);
    cout << " ## ##     ##     ##   ##  ### ###            ## ##   ### ###  ### ###  ### ##  " << endl;
    cout << "##   ##     ##     ## ##    ##  ##           ##   ##   ##  ##   ##  ##   ##  ## " << endl;
    cout << "##        ## ##   # ### #   ##               ##   ##   ##  ##   ##       ##  ## " << endl;
    cout << "##  ###   ##  ##  ## # ##   ## ##            ##   ##   ##  ##   ## ##    ## ##  " << endl;
    cout << "##   ##   ## ###  ##   ##   ##               ##   ##   ### ##   ##       ## ##  " << endl;
    cout << "##   ##   ##  ##  ##   ##   ##  ##           ##   ##    ###     ##  ##   ##  ## " << endl;
    cout << "##   ##   ##  ##  ##   ##   ##  ##           ##   ##    ###     ##  ##   ##  ## " << endl;
    cout << " ## ##   ###  ##  ##   ##  ### ###            ## ##      ##    ### ###  #### ## " << endl;
    colorontext(7);}
string optionMenu()
{
    cout << "Select the following" << endl;
    cout << "1.Keys" << endl;
    cout << "2.instruction" << endl;
    cout << "3.Exit" << endl;
    string option;
    cout << "Option: ";
    cin >> option;
    return option;
}
void optionInterface()
{   string option = "0";
    while (option != "3")
    {
        system("cls");
        header();
        option = optionMenu();
        if (option == "1")
        {
            system("cls");
            header();
            cout << "keys:" << endl;
            cout << "up\t\t\t\tGo up " << endl;
            cout << "down\t\t\t\tGo down " << endl;
            cout << "left\t\t\t\tGo left " << endl;
            cout << "right\t\t\t\tGo right " << endl;
            cout << "space\t\t\t\tfire " << endl;
            cout << "esc\t\t\t\t Exit " << endl;
            clearscreen();
        }
        if (option == "2")
        { system("cls");
            header();
            cout << "Instruction:" << endl;
            cout << "If payer hit enemy health become zero and if life and health become zero than you lose."<<endl<<"If you kill all three enemy and also big enemy than you won the game" << endl;
            clearscreen();
        }
    }
}
void clearscreen()
{   system("pause");
    system("cls");
}
string gameOption()
{
    cout<<"Select one of the following:"<<endl<<endl;
    cout<<"1.continue"<<endl;
    cout<< "2.New"<<endl;
    cout<< "3.exit"<<endl;
    string option;
    cout<< "Option: ";
    cin>>option;
    return option;
}
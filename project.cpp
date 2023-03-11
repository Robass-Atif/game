#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
using namespace std;

// globle variables
 char sign = 198;
char sign3 = 206;
char box = 219;
char sign1 = 188;
char sign2 = 200;

int bulletX[1000];
int bulletY[1000];
int bulletCount = 0;

int count = 0;

int enemybulletx[1000];
int enemybullety[1000];
int enemycount = 0;

int enemy1bulletx[1000];
int enemy1bullety[1000];
int enemy1count = 0;

int enemy2bulletx[1000];
int enemy2bullety[1000];
int enemy2count = 0;

int bigEnemyBulletX[1000];
int bigEnemyBulletY[1000];
int bigEnemycount = 0;

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

string enemyDirection = "Up";
string enemy1direction = "right";
string enemy2direction = "left";
string bigEnemyDirection = "up";

int timer1 = 0;
int timer2 = 0;
int timer3 = 0;

int timer = 0;
int timer4 = 0;
int timer5 = 0;
int timer7 = 0;

int health = 20;
int score = 0;
int healthofenemy1 = 20;
int healthofenemy2 = 20;
int healthofenemy3 = 20;
int life = 9;
int healthofbigenemy = 30;

bool enemy1active = true;
bool enemy2active = true;
bool enemy3active = true;
bool bigEnemy = true;
bool printBig = true;
bool collision = false;

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

void moveEnemy(char enemy[2][5]);
void printEnemy(char enemy[2][5]);
void eraseEnemy();

void moveenemy1( char enemy[2][5]);
void printenemy1(char enemy[2][5]);
void eraseenemy1();

void moveenemy2( char enemy[2][5]);
void printenemy2(char enemy[2][5]);
void eraseenemy2();

void printenemybullet(int, int);
void eraseenemybullet(int, int);
void removeenemybulletfromarray(int);
void moveenemybullet();
void generateenemybullet();
void enemybulletcollisionwithplayer();

void generateenemy1bullet();
void moveenemy1bullet();
void enemy1bulletcollisionwithplayer();
void printenemy1bullet(int, int);
void eraseenemy1bullet(int, int);
void removeenemy1bulletfromarray(int);

void generateenemy2bullet();
void printenemy2bullet(int, int);
void eraseenemy2bullet(int, int);
void moveenemy2bullet();
void removeenemy2bulletfromarray(int);
void enemy2bulletcollisionwithplayer();

void printbigenemy(char bigEnemy1[3][3]);
void erasebigenemy();
void moveBigEnemy(char bigEnemy1[3][3]);
void eraseBigBulletFromArray(int);
void generateBigEnemyBullet();
void bigBulletCollisionWithPlayer();

void addScore();
void printScore();
void printLife();
void minusLife();

void minushealth();
void printhealth();

void bulletCollisionWithEnemy();
void printBullet(int x, int y);
void eraseBullet(int x, int y);
void printBigBullet(int, int);
void eraseBigBullet(int, int);
void playerCollisionWithEnemy(char ship[][5]);
void moveBigBullet();

void gameInterface();
void header();
void colorontext(int num);
string menuOption();
void printGameOver();
string optionMenu();
void optionInterface();
void clearscreen();
main()
{
    system("cls");
    string option = "0";

    while (option != "3")
    {
        system("cls");
        header();
        option = menuOption();
        if (option == "1")
        {
            gameInterface();
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
// functions start here
// functions start here
void playerCollisionWithEnemy(char ship[][5])
{
    if (enemy1active == true)
    {
        if ((shipX + 5 == enemyX && (shipY == enemyY || shipY == enemyY + 1)) || ((shipX + 2 == enemyX || shipX + 2 == enemyX + 1 || shipX + 2 == enemyX + 2 || shipX + 2 == enemyX + 3 || shipX + 2 == enemyX + 4) && (shipY == enemyY+2)) || ((enemyX + 2 == shipX || enemyX + 2 == shipX + 1 || enemyX + 2 == shipX + 2 || enemyX + 2 == shipX + 3 || enemyX + 2 == shipX + 4) && (enemyY  == shipY+2)))

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
    if (enemy2active == true)
    {
        if ((shipX + 5 == enemy1X && (shipY == enemy1Y || shipY == enemy1Y + 1)) || ((shipX + 2 == enemy1X || shipX + 2 == enemy1X + 1 || shipX + 2 == enemy1X + 2 || shipX + 2 == enemy1X + 3 || shipX + 2 == enemy1X + 4) && (shipY == enemy1Y+2)) || (shipX + 5 == enemy1X && (shipY == enemy1Y || shipY == enemy1Y + 1)) || (shipX -1 == enemy1X+5 && (shipY == enemy1Y || shipY == enemy1Y + 1)))

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

    if (enemy3active == true)
    {
        if ((shipX + 5 == enemy2X && (shipY == enemy2Y || shipY == enemy2Y + 1)) || ((shipX + 2 == enemy2X || shipX + 2 == enemy2X + 1 || shipX + 2 == enemy2X + 2 || shipX + 2 == enemy2X + 3 || shipX + 2 == enemy2X + 4) && (shipY == enemy2Y+2)) || (shipX + 5 == enemy2X && (shipY == enemy2Y || shipY == enemy2Y + 1)) || (shipX -1 == enemy2X+5 && (shipY == enemy2Y || shipY == enemy2Y + 1)))
        {
            health = 0;
            eraseShip();
            shipX = 5;
            shipY = 13;
            printShip(ship);
        }
    }

    if (bigEnemy == true)
    {
        if ((shipX + 5 == bigEnemyX && (shipY == bigEnemyY || shipY == bigEnemy + 1 ||shipY==bigEnemy+2))||((bigEnemyX + 2 == shipX || bigEnemyX + 2 == shipX + 1 || bigEnemyX + 2 == shipX + 2 || bigEnemyX + 2 == shipX + 3 || bigEnemyX + 2 == shipX + 4) && (bigEnemyY  == shipY+2)) ||((shipX + 2 == bigEnemyX || shipX + 2 == bigEnemyX + 1 || shipX + 2 == bigEnemyX + 2 || shipX + 2 == bigEnemyX + 3 || shipX + 2 == bigEnemyX + 4) && (shipY == bigEnemyY+2))|| (shipX -1 == bigEnemyX+5 && (shipY == bigEnemyY || shipY == bigEnemyY + 1 || shipY == bigEnemyY+2)))
        {
            health = 0;
            eraseShip();
            shipX = 5;
            shipY = 13;
            printShip(ship);
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
    printEnemy(enemy);
    printenemy1(enemy);
    printenemy2(enemy);

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

        if (enemy1active == false && enemy2active == false && enemy3active == false && bigEnemy == true)
        {

            if (printBig == true)
            {
                printbigenemy(bigEnemy1);
                printBig = false;
            }
            if (timer7 == 12)
            {

                generateBigEnemyBullet();
                timer7 = 0;
            }
            timer7++;
            moveBigBullet();
            moveBigEnemy(bigEnemy1);
        }
        if (enemy1active == true)
        {
            if (timer1 == 30)
            {
                generateenemybullet();
                timer1 = 0;
            }
            if (timer == 3)
            {
                moveEnemy(enemy);
                timer = 0;
            }
        }

        if (enemy2active == true)
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
        if (enemy3active == true)
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
            enemy1active = false;
            eraseEnemy();
        }
        if (healthofenemy2 == 0)
        {
            enemy2active = false;
            eraseenemy1();
        }
        if (healthofenemy3 == 0)
        {
            enemy3active = false;
            eraseenemy2();
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
        timer1++;
        timer2++;
        timer3++;
        timer4++;
        timer5++;

        Sleep(30);
    }

    system("cls");
    printGameOver();
    if (life == 0 || collision == true)
    {
        cout << endl
             << endl
             << "you lose the game" << endl;
    }
    else if (healthofbigenemy == 0)
    {
        cout << endl
             << endl
             << "you won the game" << endl;
    }
    getch();
    exit(0);
}

void bigBulletCollisionWithPlayer()
{
    for (int i = 0; i < bigEnemycount; i++)
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
    for (int i = 0; i < enemy2count; i++)
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
    for (int i = 0; i < enemy2count; i++)
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
        enemy2bulletx[enemy2count] = enemy2X - 1;
        enemy2bullety[enemy2count] = enemy2Y;
        enemy2count++;
    }
}
void removeenemy2bulletfromarray(int x)
{
    for (int i = x; i < enemy2count - 1; i++)
    {
        enemy2bulletx[i] = enemy2bulletx[i + 1];
        enemy2bullety[i] = enemy2bullety[i + 1];
    }
    enemy2count--;
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
            cout << "\033[31m" << enemy[0][i] << "\033[0m";
        }
        cout << endl;
        gotoxy(enemy2X, enemy2Y + 1);
        for (int i = 0; i < 5; i++)
        {
            cout << "\033[31m" << enemy[1][i] << "\033[0m";
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

    if (enemy2direction == "left")
    {

        if (count == 0)
        {
            char next = getCharAtxy(enemy2X - 8, enemy2Y + 2);
            if (next == '#')
            {
                count++;
            }
            if (next == ' ' && count == 0)
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
            if (next == ' ')
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
            enemy2direction = "right";
        }
    }
    if (enemy2direction == "right")
    {

        if (count == 0)
        {
            char next = getCharAtxy(enemy2X + 7, enemy2Y + 2);
            if (next == '#')
            {
                count++;
            }
            if (next == ' ' && count == 0)
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
            if (next == ' ')
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
            enemy2direction = "left";
        }
    }
}

void removeenemy1bulletfromarray(int x)
{
    for (int i = x; i < enemy1count - 1; i++)
    {
        enemy1bulletx[i] = enemy1bulletx[i + 1];
        enemy1bullety[i] = enemy1bullety[i + 1];
    }
    enemy1count--;
}
void moveenemy1bullet()
{

    for (int i = 0; i < enemy1count; i++)
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
    for (int i = 0; i < enemy1count; i++)
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
    if (enemy1direction == "left")
    {
        char next1 = getCharAtxy(enemy1X - 1, enemy1Y);
        if (next1 == ' ')
        {
            eraseenemy1();
            enemy1X--;
            printenemy1(enemy);
        }
        else if (next1 == '#')
        {
            enemy1direction = "right";
        }
    }

    if (enemy1direction == "right")
    {
        char next1 = getCharAtxy(enemy1X + 5, enemy1Y);
        if (next1 == ' ')
        {
            eraseenemy1();
            enemy1X++;
            printenemy1(enemy);
        }
        else if (next1 == '#')
        {
            enemy1direction = "left";
        }
    }
}

void generateenemy1bullet()
{
    char next = getCharAtxy(enemy1X, enemy1Y + 2);
    if (next == ' ')
    {
        enemy1bulletx[enemy1count] = enemy1X;
        enemy1bullety[enemy1count] = enemy1Y + 2;
        gotoxy(enemy1X, enemy1Y + 2);
        cout << "*";
        enemy1count++;
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
        if (next == ' ')
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
        if (next == ' ')
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
            if (enemy1active == true)
            {
                addScore();
                eraseBullet(bulletX[x], bulletY[x]);
                removeBulletFromArray(x);
                healthofenemy1--;
            }
        }
        if (bulletX[x] + 1 == enemy1X && (bulletY[x] == enemy1Y || bulletY[x] == enemy1Y + 1))
        {
            if (enemy2active == true)
            {
                addScore();
                eraseBullet(bulletX[x], bulletY[x]);
                removeBulletFromArray(x);
                healthofenemy2--;
            }
        }
        if (bulletX[x] + 1 == enemy2X && (bulletY[x] == enemy2Y || bulletY[x] == enemy2Y + 1))
        {
            if (enemy3active == true)
            {
                addScore();
                eraseBullet(bulletX[x], bulletY[x]);
                removeBulletFromArray(x);
                healthofenemy3--;
            }
        }
        if (bulletX[x] + 1 == bigEnemyX && (bulletY[x] == bigEnemyY || bulletY[x] == bigEnemyY + 1))
        {
            if (bigEnemy == true && enemy1active == false && enemy2active == false && enemy3active == false)
            {
                addScore();
                eraseBullet(bulletX[x], bulletY[x]);
                removeBulletFromArray(x);
                healthofbigenemy--;
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
    for (int i = 0; i < enemycount; i++)
    {
        char next = getCharAtxy(enemybulletx[i] - 1, enemybullety[i]);

        if (next != ' ')
        {
            eraseenemybullet(enemybulletx[i], enemybullety[i]);
            removeenemybulletfromarray(i);
        }
        else
        {
            eraseenemybullet(enemybulletx[i], enemybullety[i]);
            enemybulletx[i] = enemybulletx[i] - 1;
            printenemybullet(enemybulletx[i], enemybullety[i]);
        }
    }
}

void removeenemybulletfromarray(int x)
{
    for (int i = x; i < enemycount - 1; i++)
    {
        enemybulletx[i] = enemybulletx[i + 1];
        enemybullety[i] = enemybullety[i + 1];
    }
    enemycount--;
}

void generateenemybullet()
{
    char next = getCharAtxy(enemyX - 2, enemyY + 1);
    if (next == ' ')
    {
        enemybulletx[enemycount] = enemyX - 1;
        enemybullety[enemycount] = enemyY + 1;
        gotoxy(enemyX - 1, enemyY + 1);
        cout << "*";
        enemycount++;
    }
}

void enemybulletcollisionwithplayer()
{
    for (int i = 0; i < enemycount; i++)
    {
        if (enemybulletx[i] - 1 == shipX + 5 && (enemybullety[i] == shipY || enemybullety[i] == shipY + 1))
        {
            minushealth();
            eraseenemybullet(enemybulletx[i], enemybullety[i]);
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

    for (int i = 0; i < bigEnemycount; i++)
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
    for (int i = x; i < bigEnemycount - 1; i++)
    {
        bigEnemyBulletX[i] = bigEnemyBulletX[i + 1];
        bigEnemyBulletY[i] = bigEnemyBulletY[i + 1];
    }
    bigEnemycount--;
}

void generateBigEnemyBullet()
{
    char next = getCharAtxy(bigEnemyX - 1, bigEnemyY + 1);
    if (next == ' ')
    {
        bigEnemyBulletX[bigEnemycount] = bigEnemyX - 1;
        bigEnemyBulletY[bigEnemycount] = bigEnemyY + 1;
        gotoxy(bigEnemyX - 1, bigEnemyY + 1);
        cout << "@";
        bigEnemycount++;
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
{
    colorontext(3);
    cout << " ## ##     ##     ##   ##  ### ###            ## ##   ### ###  ### ###  ### ##  " << endl;
    cout << "##   ##     ##     ## ##    ##  ##           ##   ##   ##  ##   ##  ##   ##  ## " << endl;
    cout << "##        ## ##   # ### #   ##               ##   ##   ##  ##   ##       ##  ## " << endl;
    cout << "##  ###   ##  ##  ## # ##   ## ##            ##   ##   ##  ##   ## ##    ## ##  " << endl;
    cout << "##   ##   ## ###  ##   ##   ##               ##   ##   ### ##   ##       ## ##  " << endl;
    cout << "##   ##   ##  ##  ##   ##   ##  ##           ##   ##    ###     ##  ##   ##  ## " << endl;
    cout << "##   ##   ##  ##  ##   ##   ##  ##           ##   ##    ###     ##  ##   ##  ## " << endl;
    cout << " ## ##   ###  ##  ##   ##  ### ###            ## ##      ##    ### ###  #### ## " << endl;
    colorontext(7);
}

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
{
    string option = "0";
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
        {
            system("cls");
            header();
            cout << "Instruction:" << endl;
            cout << "1. play good" << endl;
            clearscreen();
        }
    }
}
void clearscreen()
{
    cout << "press any key to continue!" << endl;
    getch();
    system("cls");
}

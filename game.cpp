#include <iostream>
#include <windows.h>
using namespace std;

// globle variables

char sign = 198;
char sign3=206;
char box = 219;
char sign1 = 188;
char sign2 = 200;
char ship1[] = {' ', ' ', sign, ' ', ' '};
char ship2[] = {sign2, box, box, box, sign1};

char enemy1[] = {' ', ' ', sign3, ' ', ' '};
char enemy2[] = {'(', '_', '_', '_', ')'};

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

int shipX = 5;
int shipY = 12;

int enemyX = 91;
int enemyY = 10;

int enemy1X = 1;
int enemy1Y = 1;

int enemy2X = 97;
int enemy2Y = 4;

string enemyDirection = "Up";
string enemy1direction = "right";
string enemy2direction = "left";

int timer1 = 0;
int timer = 0;
int health = 20;
int score = 0;

// function

void gotoxy(int x, int y);
char getCharAtxy(short int x, short int y);
void printTank();
void eraseTank();
void printMaze();
void moveBullet();
void generateBullet();
void removeBulletFromArray(int index);
void moveTankUp();
void moveTankDown();
void moveTankLeft();
void moveTankRight();

void moveEnemy();
void printEnemy();
void eraseEnemy();

void moveenemy1();
void printenemy1();
void eraseenemy1();

void moveenemy2();
void printenemy2();
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

void addScore();
void printScore();

void minushealth();
void printhealth();

void bulletCollisionWithEnemy();
void printBullet(int x, int y);
void eraseBullet(int x, int y);

main()
{
    system("cls");
    printMaze();
    printTank();
    printEnemy();
    printenemy1();
    printenemy2();
    while (true)
    {
        printhealth();
        printScore();
        if (GetAsyncKeyState(VK_LEFT))
        {
            moveTankLeft();
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {
            moveTankRight();
        }
        if (GetAsyncKeyState(VK_UP))
        {
            moveTankUp();
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
            moveTankDown();
        }
        if (GetAsyncKeyState(VK_ESCAPE) || health == 0 || score == 50)
        {
            return 0;
        }
        if (GetAsyncKeyState(VK_SPACE))
        {
            generateBullet();
        }

        if (timer == 3)
        {
            moveenemy1();
            moveEnemy();
            moveenemy2();



            timer = 0;
        }

        if (timer1 == 20)
        {
            generateenemybullet();
            generateenemy1bullet();
            generateenemy2bullet();
            timer1 = 0;
        }
                    moveenemybullet();

            moveenemy1bullet();
            moveenemy2bullet();
            
        enemy2bulletcollisionwithplayer();
        enemy1bulletcollisionwithplayer();
        enemybulletcollisionwithplayer();
        moveBullet();
        bulletCollisionWithEnemy();
        timer++;
        timer1++;
        Sleep(30);
    }
}

// functions start here

void moveenemy2bullet()
{
    for (int i = 0; i < enemy2count; i++)
    {
        char next = getCharAtxy(enemy2bulletx[i]-1, enemy2bullety[i] );
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

void printenemy2()
{
    gotoxy(enemy2X, enemy2Y);
    for (int i = 0; i < 5; i++)
    {
        cout <<"\033[35m"<< enemy1[i]<<"\033[0m";
    }
    cout << endl;
    gotoxy(enemy2X, enemy2Y + 1);
    for (int i = 0; i < 5; i++)
    {
        cout <<"\033[35m"<< enemy2[i]<<"\033[0m";
    }
    cout << endl;
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

void moveenemy2()
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
                printenemy2();
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
                printenemy2();
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
                printenemy2();
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
                printenemy2();
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
        if (enemy1bullety[i] == shipY && (enemy1bulletx[i] == shipX || enemy1bulletx[i] == shipX + 1 || enemy1bulletx[i] == shipX + 2 || enemy1bulletx[i] == shipX + 3 || enemy1bulletx[i] == shipX + 4))
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
void printenemy1()
{
    gotoxy(enemy1X, enemy1Y);
    for (int i = 0; i < 5; i++)
    {
        cout <<"\033[35m"<< enemy1[i]<<"\033[0m";
    }
    cout << endl;
    gotoxy(enemy1X, enemy1Y + 1);
    for (int i = 0; i < 5; i++)
    {
        cout <<"\033[35m"<< enemy2[i]<<"\033[0m";
    }
    cout << endl;
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

void moveenemy1()
{
    if (enemy1direction == "left")
    {
        char next1 = getCharAtxy(enemy1X - 1, enemy1Y);
        if (next1 == ' ')
        {
            eraseenemy1();
            enemy1X--;
            printenemy1();
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
            printenemy1();
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
    cout << "Health: " << health;
}

void minushealth()
{
    health--;
}

void moveEnemy()
{

    if (enemyDirection == "Up")
    {
        char next = getCharAtxy(enemyX, enemyY - 1);
        if (next == ' ')
        {
            eraseEnemy();
            enemyY--;
            printEnemy();
        }
        if (next == '#')
        {
            enemyDirection = "Down";
        }
    }
    if (enemyDirection == "Down")
    {
        char next = getCharAtxy(enemyX, enemyY + 4);
        if (next == ' ')
        {
            eraseEnemy();
            enemyY++;
            printEnemy();
        }
        if (next == '#')
        {
            enemyDirection = "Up";
        }
    }
}

void printEnemy()
{
    gotoxy(enemyX, enemyY);
    for (int index = 0; index < 5; index++)
    {
        cout <<"\033[35m"<< enemy1[index]<<"\033[0m";
    }
    gotoxy(enemyX, enemyY + 1);
    for (int index = 0; index < 5; index++)
    {
        cout<<"\033[35m" << enemy2[index]<<"\033[0m";
    }
}
void eraseEnemy()
{
    gotoxy(enemyX, enemyY);
    for (int index = 0; index < 6; index++)
    {
        cout << " ";
    }
    gotoxy(enemyX, enemyY + 1);
    for (int index = 0; index < 6; index++)
    {
        cout << " ";
    }
}

void moveTankLeft()
{
    char next = getCharAtxy(shipX - 1, shipY);
    if (next == ' ')
    {
        eraseTank();
        shipX = shipX - 1;
        printTank();
    }
}

void moveTankRight()
{
    char next = getCharAtxy(shipX + 6, shipY);
    if (next == ' ')
    {
        eraseTank();
        shipX = shipX + 1;
        printTank();
    }
}

void moveTankUp()
{
    char next = getCharAtxy(shipX, shipY - 1);
    if (next == ' ')
    {
        eraseTank();
        shipY = shipY - 1;
        printTank();
    }
}

void moveTankDown()
{
    char next = getCharAtxy(shipX, shipY + 2);
    if (next == ' ')
    {
        eraseTank();
        shipY = shipY + 1;
        printTank();
    }
}

void generateBullet()
{
    bulletX[bulletCount] = shipX + 7;
    bulletY[bulletCount] = shipY;
    gotoxy(shipX + 7, shipY);
    cout << ".";
    bulletCount++;
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

void printTank()
{
    gotoxy(shipX, shipY);
    for (int index = 0; index < 6; index++)
    {
        cout <<"\033[32m"<< ship1[index]<<"\033[0m";
    }
    gotoxy(shipX, shipY + 1);
    for (int index = 0; index < 6; index++)
    {
        cout<<"\033[32m" << ship2[index]<<"\033[0m";
    }
}

void eraseTank()
{
    gotoxy(shipX, shipY);
    for (int index = 0; index < 6; index++)
    {
        cout << " ";
    }
    gotoxy(shipX, shipY + 1);
    for (int index = 0; index < 6; index++)
    {
        cout << " ";
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
{
    cout <<"\033[31m"<< "##########################################################################################################" <<"\033[0m"<< endl;
    cout <<"\033[31m"<< "#                                                                                                        #" <<"\033[0m"<< endl;
    cout <<"\033[31m"<< "#                                                                                                        #" <<"\033[0m"<< endl;
    cout <<"\033[31m"<< "#                                                                                                        #" <<"\033[0m"<< endl;
    cout <<"\033[31m"<< "#                                                                                                        #" <<"\033[0m"<< endl;
    cout <<"\033[31m"<< "#                                                                                                        #" <<"\033[0m"<< endl;
    cout <<"\033[31m"<< "#                                                                                                        #" <<"\033[0m"<< endl;
    cout <<"\033[31m"<< "#                                                                                                        #" <<"\033[0m"<< endl;
    cout <<"\033[31m"<< "#                                                                                                        #" <<"\033[0m"<< endl;
    cout <<"\033[31m"<< "#                                                                                                        #" <<"\033[0m"<< endl;
    cout <<"\033[31m"<< "#                                                                                                        #" <<"\033[0m"<< endl;
    cout <<"\033[31m"<< "#                                                                                                        #" <<"\033[0m"<< endl;
    cout <<"\033[31m"<< "#                                                                                                        #" <<"\033[0m"<< endl;
    cout <<"\033[31m"<< "#                                                                                                        #" <<"\033[0m"<< endl;
    cout <<"\033[31m"<< "#                                                                                                        #" <<"\033[0m"<< endl;
    cout <<"\033[31m"<< "#                                                                                                        #" <<"\033[0m"<< endl;
    cout <<"\033[31m"<< "#                                                                                                        #" <<"\033[0m"<< endl;
    cout <<"\033[31m"<< "##########################################################################################################" <<"\033[0m"<< endl;
}

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
            addScore();
            eraseBullet(bulletX[x], bulletY[x]);
            removeBulletFromArray(x);
        }
        if (bulletX[x] + 1 == enemy1X && (bulletY[x] == enemy1Y || bulletY[x] == enemy1Y + 1))
        {
            addScore();
            eraseBullet(bulletX[x], bulletY[x]);
            removeBulletFromArray(x);
        }
        if (bulletX[x] + 1 == enemy2X && (bulletY[x] == enemy2Y || bulletY[x] == enemy2Y + 1))
        {
            addScore();
            eraseBullet(bulletX[x], bulletY[x]);
            removeBulletFromArray(x);
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

//  if(enemy2direction=="left")
//     {
//         char next=getCharAtxy(enemy2X-1,enemy2Y);
//         if(next ==' ')
//         {
//             if(enemy2X>76)
//             {
//                 eraseenemy2();
//                 enemy2X--;
//                 printenemy2();
//             }
//             else if(enemy2X==76 || enemy2Y>7)
//             {
//                 eraseenemy2();
//                 enemy2Y--;
//                 printenemy2();
//             }
//             else if (enemy2Y==7 || enemy2X> )
//         }
//         else if(next=='#')
//         {
//             enemy2direction="right";
//         }
//     }
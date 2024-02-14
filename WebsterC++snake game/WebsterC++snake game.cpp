#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>//file handling save username
#include <conio.h>
#include <windows.h>

using namespace std;

bool gameOver;


void Setup() {
   
}

void Draw() {
   
}

/*Student: Muslima Rizayeva
function that handles user input to control the game*/
void Input() {
        if (_kbhit()) {
            switch (_getch()) {
            case 'a':
                dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 'w':
                dir = UP;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'x':
                gameOver = true;
                break;
            }
        }
    }
   
}
/*Student: Aminov Humoyunmirzo
function that controls the direction of movements */
void Logic()
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;

    for (int i = 1; i < nTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }
    if (x >= width) x = 0; else if (x < 0) x = width - 1;
    if (y >= height) y = 0; else if (y < 0) y = height - 1;

    for (int i = 0; i < nTail; i++)
        if (tailX[i] == x && tailY[i] == y)
            gameOver = true;

    if (x == fruitX && y == fruitY)
    {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }
}
//Abdurauf's part function for save the score
void SaveScore(string name, int score) {
    ofstream file;
    file.open("snake_game_scores.txt", ios::out);
    file << "Player: " << name << " Score: " << score << endl;
    file.close();
}

int main() {
    string playerName;
    cout << "Enter your name: ";
    cin >> playerName;
    Setup();
    while (!gameOver) {
        Draw();
        Input();
        Logic();
        Sleep(10);
    }
    cout << "Game Over" << endl << "Your Score: " << score << endl;
    SaveScore(playerName, score);
    cout << "Press 'r' to restart or any other key to exit." << endl;
    if (_getch() == 'r') {
        main();
    }
    return 0;
}
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

void Input() {
   
}

void Logic() {
    
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
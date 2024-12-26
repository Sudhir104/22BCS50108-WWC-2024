#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class FruitJunction {
private:
    vector<vector<char> > grid;
    int playerX, playerY;
    int score;
    int fruitsToCollect;

public:
    FruitJunction(int gridSize, int fruitCount) : score(0), fruitsToCollect(fruitCount) {
        grid.resize(gridSize, vector<char>(gridSize, '.'));
        playerX = gridSize / 2;
        playerY = gridSize / 2;
        grid[playerX][playerY] = 'P'; 
        placeFruits(fruitCount);
    }

    void placeFruits(int count) {
        for (int i = 0; i < count; ++i) {
            if (!placeSingleFruit()) {
                cout << "No more space to place fruits! Game Over!" << endl;
                exit(0);
            }
        }
    }

    bool placeSingleFruit() {
        int attempts = 0;
        while (attempts < 100) { 
            int x = rand() % grid.size();
            int y = rand() % grid[0].size();
            if (grid[x][y] == '.') { 
                grid[x][y] = 'F';
                return true;
            }
            attempts++;
        }
        return false; 
    }

    void displayGrid() {
        system("clear"); 
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                cout << grid[i][j] << " "; 
            }
            cout << endl;
        }
        cout << "Score: " << score << endl;
        cout << "Fruits to collect: " << fruitsToCollect - score << endl;
    }

    void movePlayer(char direction) {
        int newX = playerX;
        int newY = playerY;

        switch (direction) {
            case 'w': newX--; break;
            case 's': newX++; break; 
            case 'a': newY--; break; 
            case 'd': newY++; break; 
            default: cout << "Invalid move! Use w/a/s/d." << endl; return;
        }

        if (newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size()) {
            grid[playerX][playerY] = '.';
            playerX = newX;
            playerY = newY;

            if (grid[playerX][playerY] == 'F') {
                score++;
                if (score >= fruitsToCollect) {
                    cout << "Congratulations! You've collected all the fruits!" << endl;
                    exit(0); 
                } else {
                    placeSingleFruit(); 
                }
            }

            grid[playerX][playerY] = 'P';
        } else {
            cout << "Move out of bounds! Try again." << endl;
        }
    }

    void play() {
        char move;
        while (true) {
            displayGrid();
            cout << "Enter your move (w/a/s/d) or 'q' to quit: ";
            cin >> move;

            if (move == 'q') {
                cout << "Thanks for playing! Your final score is: " << score << endl;
                break;
            }

            movePlayer(move);
        }
    }
};

int main() {
    srand(static_cast<unsigned int>(time(0))); 

    int gridSize, fruitCount;
    cout << "Enter grid size (e.g., 5 for a 5x5 grid): ";
    cin >> gridSize;
    cout << "Enter number of fruits to collect: ";
    cin >> fruitCount;

    FruitJunction game(gridSize, fruitCount);
    game.play();
    return 0;
}
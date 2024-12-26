#include <iostream>
using namespace std;
int lastRemaining(int n) {
    int head = 1;
    int step = 1;  
    bool leftToRight = true;  
    while (n > 1) {
        if (leftToRight || n % 2 == 1) {
            head += step;
        }
        n /= 2;
        step *= 2;  
        leftToRight = !leftToRight;  
    }
    return head;
}

int main() {
    int n = 9;  
    cout << "Last remaining number: " << lastRemaining(n) << std::endl;
    return 0;
}
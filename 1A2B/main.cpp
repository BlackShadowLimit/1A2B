//
//  main.cpp
//  1A2B
//
//  Created by Arthur on 2022/3/27.
//

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int read(); // this fuction is for reading the number
void split(int); // this fuction is for splitint each number
void check(int, int); //  this fuction is for checking the number
int A[4]; // array to store each number
// fuction read
int read() {
    int g_r;
    cin >> g_r;
    if (sizeof(g_r) != 4) {
        cout << "Out of range, try again\n";
        read();
    }
    split(g_r);
    for (int i = 0; i <= 3; i++) {
        for (int j = i + 1; j <= 3; j++) {
            if (A[i] != A[j]) {
                continue;
            } else {
                cout << "\ntry again\n";
                read();
            }
        }
    }

    return g_r;
}

// fuction split
void split(int s) {
    for (int i = 3; i >= 0; i--) {
        A[i] = s % 10;
        s = (s - (s % 10)) / 10;
    }
}

// fuction check

void check(int ans, int gus) {
    int a = 0, b = 0;
    
    // split answer and guess number
    int Ans[4], Gus[4];
    split(ans);
    for (int i = 0; i <= 3; i++) {
        Ans[i] = A[i];
    }
    split(gus);
    for (int i = 0; i <= 3; i++) {
        Gus[i] = A[i];
    }
    
    // check
    for (int i = 0; i <= 3; i++) {
        for (int j = 0; j <= 3; j++) {
            if (Ans[i] == Gus[j]) {
                if (i == j) {
                    a++;
                } else {
                    b++;
                }
            }
        }
    }
    if (a == 4) {
        cout << "Bingo\n";
    } else {
        cout << "\t" << a << "A" << b << "B\n";
        a = 0;
        b = 0;
    }
}


// this is main fuction
int main () {
    int ans = 0, gus = 1;
    
    // opening
    cout << "\tWelcome to 1A2B game\t";
    cout << "\n============================\n";
    
    // declare answer
    while (1) {
        srand(time(0));
        ans = rand() % 10000 + 1;
        ans = ans - 1000;
        if (ans >= 0) {
            split(ans);
            for (int i = 0; i <= 3; i++) {
                for (int j = 0; j <= 3; j++) {
                    if (A[i] != A[j]) {
                        continue;
                    } else {
                        break;
                    }
                }
            }
            break;
        }
    }
    cout << ans;
    cout << "Records\tHints\n" ;
    cout << "-------\t-----\n";
    while (ans != gus) {
        gus = read();
        check(ans, gus);
    }
    
    
}

#include <stdio.h> 
#include <stdlib.h> 
#include<time.h>

int main(void)
{
    int key = 2;
    int door[5] = { 0 };//0=exit 1,2=chest 3,4=nothing
    bool check[5] = { 0 };

    srand(time(0));

    for (int i = 0; i < 5; i++) {
        bool K = false;
        while (K != true) {
            door[i] = rand() % 5;
            if (check[door[i]] == 0) {
                K = true;
                check[door[i]] = 1;
            }
        }
    }

    return 0;
}
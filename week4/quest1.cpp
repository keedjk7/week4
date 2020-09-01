#include<iostream>
#include <stdlib.h> 
#include<time.h>

using namespace std;

int Chest(int door[5]) {
    //srand(time(0));
    int RANDOM = rand() % 10;
    if (RANDOM == 9) {
        cout << "You die from trap in a chest";
        return -1;
    }
    else if (RANDOM>= 4&&RANDOM<9) {
        cout << "You get nothing\n";
        return 0;
    }
    else if (RANDOM >= 1&&RANDOM<4) {
        cout << "You get a key\n";
        return 1;
    }
    else {
        cout << "You get a dead eye";
        return 2;
    }
}

int main()
{
    int key = 2,input,EXIT = 0,Death;
    int door[5] = { 0 };//0=exit 1,2=chest 3=nothing 4=dead
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
        if (door[i] == 4) {
            Death = i;
        }
    }
    while (key != 0 && EXIT == 0 ) {            
        cout<<"\nGate 1 : Thanathos";
        if (check[0] == 1) {
            cout<<"   (Closing)";
        }
        else {
            cout<<"   (Opened)";
        }

        cout<<"\nGate 2 : Hel";
        if (check[1] == 1) {
            cout<<"   (Closing)";
        }
        else {
            cout<<"   (Opened)";
        }

        cout<<"\nGate 3 : Hades";
        if (check[2] == 1) {
            cout<<"   (Closing)";
        }
        else {
            cout<<"   (Opened)";
        }            
        
        cout<<"\nGate 4 : Anubius";
        if (check[3] == 1) {
            cout<<"   (Closing)";
        }
        else {
            cout<<"   (Opened)";
        }            
        cout << "\nGate 5 : Ankou";
        if (check[4] == 1) {
            cout<<"   (Closing)";
        }
        else {
            cout<<"   (Opened)";
        }
        cout << "\n\nKey = " << key << "\n";
        int pass = false;
        while (pass!=true) {
            cout << "Select the gate you want to enter : ";
            cin >> input;
            if (check[input-1]==0) {
                cout << "The gate you have selected has already been used\nInput again -> ";
            }
            else {
                pass = true;
            }
        }
        key -= 1;
        check[input-1] = 0;
        if (door[input-1] == 4) {
            cout << "You die from entering a gate which inside monsters\n";
            EXIT = 2;
        }
        else if (door[input-1] == 0) {
            cout << "Congratulations, You survive\n";
            EXIT = 1;
        }
        else if(door[input-1]==3){
            cout << "The gate you enter is nothing\n";
        }
        else {
            char Q;
            int Re;
            cout << "You found the chest\nWould you like to open this chest ? <Y/N>";
            cin >> Q;
            if (Q == 'Y') {
                Re=Chest(door);
                
                if (Re == -1) {
                    EXIT == 2;
                }
                else if (Re == 1) {
                    key++;
                }
                else if (Re == 2) {
                    check[Death] = 0;
                }
            }
        }
    }
    if (key == 0 && EXIT == 0) {
        cout <<"KEY = "<< key << "\nYou can't find the exit.You die";
    }
    cout << "\n\nMAP\n\n";
    for (int i = 0; i < 5; i++) {

        if (i == 0) {
            cout << "\nGate 1 : Thanathos";
        }
        else if (i == 1) {
            cout << "\nGate 2 : Hel";
        }
        else if (i == 2) {
            cout << "\nGate 3 : Hades";
        }
        else if (i == 3) {
            cout << "\nGate 4 :Anubius";
        }
        else {
            cout << "\nGate 5 :Ankou";
        }

        if (door[i] == 0) {
            cout << "-----> EXIT\n";
        }
        else if (door[i] == 1 || door[i] == 2) {
            cout << "-----> A Chest\n";
        }
        else if (door[i] == 3) {
            cout << "-----> Nothing\n";
        }
        else {
            cout << "----->Monster\n";
        }
    }
    return 0;
}
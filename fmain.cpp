#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "fclasses.h"

using namespace std;

void start();

int main()
{

    //arxiko menu k klhsh ths sunarthshs start() gia na arxisei h proswmoiwsh

    srand(time(0));

    char answer;
    do
    {

          cout<<endl<<endl<<endl<<"Project C++ 2011-2012"<<endl
               <<endl<<endl<<endl<<"A maritime ecosystem"<<endl<<endl<<endl;

          cout<< "(s). Start" << endl
               << "Press 's' to start the programm and after 'p' to pause the simulation" << endl;

          cin >> answer;

          if(answer == 's') start();
          else cout << "Error! Press 's' to start the programm" << endl;

        }while(answer != 's');


        cout<<endl<< endl<< endl;

    system("pause");
    return 0;
}








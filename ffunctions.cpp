#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "fclasses.h"
#include <conio.h>

using namespace std;



char map[10][10];
int map2[10][10];

char letters[] = {'f', 'z', 'M', 'S', 'A', 'F', 'D', 'O', 'X', 'T'};

int x, y, w, z, e1, e2, d;

char l;

int days, weeks;

void start();
void pause(int, int);

void (*ptr)(void);
void (*ptr2) (int ,int);

vector <Operations> sy;

//Dhmiourgos gia thn arxikh tyxaia dhmiourgia twn antikeimenwn k thn prosthikh tous sto xarth
System :: System()
{

       size = rand() % 100 + 50;

       do
       {
                pos_x = rand() % 11;
                pos_y = rand() % 11;

       }while(map2[pos_x][pos_y] == 1);

       letter = letters[rand() % 9];

       map[pos_x][pos_y] = letter ;

       map2[pos_x][pos_y] = 1;

       age = rand() % 5;
       degree = rand() % 3 + 1;
       quantity = rand() % 100 + 20;
       food = 0;


};

//Dhmiourgos me 3 orismata otan sumbainei h anaparagwgh
System :: System(char l, int a, int s)
{
    letter = l;
    age = a;
    size = s;

    do
    {
        pos_x = rand() % 11;
        pos_y = rand() % 11;

    }while(map2[pos_x][pos_y] == 1);

    map[pos_x][pos_y] = letter ;
    map2[pos_x][pos_y] = 1;

    degree = rand() % 3 + 1;
    quantity = rand() % 100 + 20;
    food = 0;
}

//Dhmiourgos me 4 orismata gia thn dhmiourgia antikeimenou apo to xrhsth
System :: System(char l, int x, int y, int a)
{
    size = rand() % 100 + 50;

    pos_x = x;
    pos_y = y;

    letter = l;

    map[pos_x][pos_y] = letter ;

    map2[pos_x][pos_y] = 1;

    age = a;
    degree = rand() % 3 + 1;
    quantity = rand() % 100 + 20;
    food = 0;
}

System :: ~System(){}

Operations :: Operations()
{
    System();
}

Operations :: Operations(char l, int a, int s)
{
    System(l, a, s);
}

Operations :: Operations(char l, int x, int y, int a)
{
    System(l, x, y, a);
}

Operations :: ~Operations() {}

void System :: set_size(int s) { size = s; }

int System :: get_size() { return size; }

void System :: set_pos_x(int x){ pos_x = x; }

int System :: get_pos_x() { return pos_x; }

void System::set_pos_y(int y) { pos_y = y; }

int System::get_pos_y() { return pos_y; }

void System :: set_age(int a) { age = a; }

int System :: get_age() { return age; }

void System :: set_degree(int deg) { degree = deg; }

int System :: get_degree() { return degree; }

void System :: set_food(int f) { food = f; }

int System :: get_food() { return food; }

void System :: set_quantity(int q) { quantity = q; }

int System :: get_quantity() { return quantity; }

char System :: get_letter() { return letter; }


void wait ( int seconds )
{
  clock_t endwait;
  endwait = clock () + seconds * CLOCKS_PER_SEC ;
  while (clock() < endwait) {}
}


//arxikh tuxaia dhmioyrgia antikeimenwn
void init()
{
     for(int i = 0; i < 10; i++)
     {
             for(int j = 0; j < 10; j++)
             {
                     map2[i][j] = 0;
                     map[i][j] = '~';
             }
     }

     for(int k = 0; k < 20; k++)
     {
            Operations s = Operations :: Operations();
            sy.push_back(s);
     }

}

//boithitikh sunarthsh gia ton elegxo twn oriwn tou pinaka
bool limits(int x, int y)
{
    if(x<0 || y<0 || x>9 || y>9) return true;
}


//h leitourgia ths kinhshs
void Operations :: moving(int i)
{
    w = sy[i].get_pos_x();

    z = sy[i].get_pos_y();

    do
    {
        x = w + ((rand() %3 ) - 1);
        y = z + ((rand() %3 ) - 1);

    }while( limits(x,y) || map2[x][y] == 1); //elegxoume h nea thesi na einai entos tou pinaka k na mhn einai kateillhmenh

    map[w][z] = '~';
    map2[w][z] = 0;

    sy[i].set_pos_x(x);
    sy[i].set_pos_y(y);

    map[x][y] = sy[i].get_letter();
    map2[x][y] = 1;
}

//h leitourgia ths trofhs
void Operations :: eating(int i)
{
    w = sy[i].get_pos_x();

    z = sy[i].get_pos_y();

    l = sy[i].get_letter();


    for(int k = w - 1; k < w + 2; k++)
    {
        for(int m = z - 1; m < z + 2; m++)
        {
            if(k == w && m == z || limits(w,z)) continue;

            else if(map2[k][m] == 1)
            {
                switch (l)
                {
                    case 'M':
                    {
                        if(map[k][m] == 'f')
                        {
                            for(int t = 0; t < sy.size(); t++)
                            {
                                if(k == sy[t].get_pos_x() && m == sy[t].get_pos_y())
                                {
                                    e1 = sy[i].get_size();
                                    e2 = sy[t].get_size();
                                    d = sy[i].get_degree();
                                    sy[i].set_size((e1+e2)/d);
                                    sy[i].set_food(e2);
                                    map[k][m] = '~';
                                    sy.erase(sy.begin() + t);
                                    break;
                                }
                            }
                        }

                    case 'A':
                    {
                        if(map[k][m] == 'M' || map[k][m] == 'z')
                        {
                            for(int t = 0; t < sy.size(); t++)
                            {
                                if(k == sy[t].get_pos_x() && m == sy[t].get_pos_y())
                                {
                                    e1 = sy[i].get_size();
                                    e2 = sy[t].get_size();
                                    d = sy[i].get_degree();
                                    sy[i].set_size((e1+e2)/d);
                                    sy[i].set_food(e2);
                                    map[k][m] = '~';
                                    sy.erase(sy.begin() + t);
                                    break;
                                }
                            }
                        }
                    }

                    case 'S':
                    {
                        if(map[k][m] == 'z')
                        {
                            for(int t = 0; t < sy.size(); t++)
                            {
                                if(k == sy[t].get_pos_x() && m == sy[t].get_pos_y())
                                {
                                    e1 = sy[i].get_size();
                                    e2 = sy[t].get_size();
                                    d = sy[i].get_degree();
                                    sy[i].set_size((e1+e2)/d);
                                    sy[i].set_food(e2);
                                    map[k][m] = '~';
                                    sy.erase(sy.begin() + t);
                                    break;
                                }
                            }
                        }
                    }

                    case 'F':
                    {
                        if(map[k][m] == 'z' || map[k][m] == 'S' || map[k][m] == 'T' || map[k][m] == 'O')
                        {
                            for(int t = 0; t < sy.size(); t++)
                            {
                                if(k == sy[t].get_pos_x() && m == sy[t].get_pos_y())
                                {
                                    e1 = sy[i].get_size();
                                    e2 = sy[t].get_size();
                                    d = sy[i].get_degree();
                                    sy[i].set_size((e1+e2)/d);
                                    sy[i].set_food(e2);
                                    map[k][m] = '~';
                                    sy.erase(sy.begin() + t);
                                    break;
                                }
                            }
                        }
                    }

                    case 'D':
                    {
                        if(map[k][m] == 'z' || map[k][m] == 'S' || map[k][m] == 'A')
                        {
                            for(int t = 0; t < sy.size(); t++)
                            {
                                if(k == sy[t].get_pos_x() && m == sy[t].get_pos_y())
                                {
                                    e1 = sy[i].get_size();
                                    e2 = sy[t].get_size();
                                    d = sy[i].get_degree();
                                    sy[i].set_size((e1+e2)/d);
                                    sy[i].set_food(e2);
                                    map[k][m] = '~';
                                    sy.erase(sy.begin() + t);
                                    break;
                                }
                            }
                        }
                    }

                    case 'X':
                    case 'T':
                    {
                        if(map[k][m] == 'z' || map[k][m] == 'S')
                        {
                            for(int t = 0; t < sy.size(); t++)
                            {
                                if(k == sy[t].get_pos_x() && m == sy[t].get_pos_y())
                                {
                                    e1 = sy[i].get_size();
                                    e2 = sy[t].get_size();
                                    d = sy[i].get_degree();
                                    sy[i].set_size((e1+e2)/d);
                                    sy[i].set_food(e2);
                                    map[k][m] = '~';
                                    sy.erase(sy.begin() + t);
                                    break;
                                }
                            }
                        }
                    }

                    case 'O':
                    {
                        if(map[k][m] == 'z' || map[k][m] == 'A')
                        {
                            for(int t = 0; t < sy.size(); t++)
                            {
                                if(k == sy[t].get_pos_x() && m == sy[t].get_pos_y())
                                {
                                    e1 = sy[i].get_size();
                                    e2 = sy[t].get_size();
                                    d = sy[i].get_degree();
                                    sy[i].set_size((e1+e2)/d);
                                    sy[i].set_food(e2);
                                    map[k][m] = '~';
                                    sy.erase(sy.begin() + t);
                                    break;
                                }
                            }
                        }
                    }

                    default: continue;
                }
            }
        }
    }
}
}

//h leitourgia ths anaparagwghs
void Operations :: reproducting(int i)
{
    w = sy[i].get_pos_x();

    z = sy[i].get_pos_y();

    l = sy[i].get_letter();


    for(int k = w - 1; k < w + 2; k++)
    {
        for(int m = z - 1; m < z + 2; m++)
        {
            if(k == w && m == z || limits(w,z)) continue;
            else if(map[k][m] == l)
            {
                for(int t = 0; t < sy.size(); t++)
                {
                    if(k == sy[t].get_pos_x() && m == sy[t].get_pos_y())
                    {
                        Operations s = Operations :: Operations(l, 0, 0);
                        sy.push_back(s);

                        return;
                    }
                }
            }
        }
    }
}

//ektupwsh tou xarth
void showInfo()
{
     for( int i = 0; i < 10; i++)
     {
          for( int j = 0; j < 10; j++)
          {
               cout << map[i][j];
               if (j == 9) { cout<<endl<< endl; }

          }
     }
}

//ektelesh leitourgiwn : kinhsh, trofh, anaparagwgh
void cont()
{
    char answer;
    for(int i = 0; i < sy.size(); i++)
    {
        sy[i].moving(i);
        sy[i].eating(i);
        sy[i].reproducting(i);


    }
}

//sunarthsh gia na ektupwnontai plhrofories gia kathe organismo
void info()
{
    ptr2 = &pause;

    int a, an;
    for(int i = 0; i < sy.size(); i++)
    {
        cout<< i+1 << "." << sy[i].get_letter() << endl << endl;
    }

    cout<<"Press 1 - " << sy.size() << endl;

    cin>> a;

    cout<<"Choose one from below: "<< endl
        <<"1. Position in map "<< endl
        <<"2. Size " << endl
        <<"3. Age " << endl
        <<"4. Degree of growth "<< endl
        <<"5. Needed quantity of food  " <<endl
        <<"6. Food " << endl;

    cin>>an;

    switch(an)
    {
        case 1:
        {
            cout<< "The x position is:  "<< sy[a].get_pos_x() <<endl
                << "The y position is:  " << sy[a].get_pos_y() <<endl;
                break;
        }

        case 2:
        {
            cout<< "Size:  " << sy[a].get_size() <<endl;
            break;
        }

        case 3:
        {
            cout << "Age:  " << sy[a].get_age() <<endl;
            break;
        }

        case 4:
        {
            cout << "Degree of growth:  " << sy[a].get_degree() <<endl;
            break;
        }

        case 5:
        {
            cout<< "Needed quantity of food: " << sy[a].get_quantity() <<endl;
            break;
        }
        case 6:
        {
            cout<< "Food:  " << sy[a].get_food() <<endl;
            break;
        }
    }

    cout<<endl<<endl<<endl;
    ptr2(days,weeks);

}

//sunarthsh gia to meso oro tou megethous mias kathgorias organismwn
void average()
{
    float ave = 0.0;
    int sum[8];
    int c[8];
    char l;
    int temp = 0;

    ptr2 = &pause;

    cout << "Choose a letter from below: " << endl;
    for(int i = 2; i < 10; i++)
    {
        cout << letters[i] << endl;
        sum[i-2] = 0;
        c[i-2] = 0;
    }

    cin>>l;

    for(int i = 0; i < sy.size(); i++)
    {
        if(sy[i].get_letter() == l)
        {
            switch(l)
            {
                case 'M':
                {
                    sum[0] = sum[0] + sy[i].get_size();
                    c[0] = c[0] + 1;
                    temp = 0;
                    break;
                }
                case 'A':
                {
                    sum[1] = sum[1] + sy[i].get_size();
                    c[1]++;
                    temp = 1;
                    break;
                }
                case 'S':
                {
                    sum[2] = sum[2] + sy[i].get_size();
                    c[2]++;
                    temp = 2;
                    break;
                }
                case 'F':
                {
                    sum[3] = sum[3] + sy[i].get_size();
                    c[3]++;
                    temp = 3;
                    break;
                }
                case 'D':
                {
                    sum[4] = sum[4] + sy[i].get_size();
                    c[4]++;
                    temp = 4;
                    break;
                }
                case 'O':
                {
                    sum[5] = sum[5] + sy[i].get_size();
                    c[5]++;
                    temp = 5;
                    break;
                }
                case 'X':
                {
                    sum[6] = sum[6] + sy[i].get_size();
                    c[6]++;
                    temp = 6;
                    break;
                }
                case 'T':
                {
                    sum[7] = sum[7] + sy[i].get_size();
                    c[7]++;
                    temp = 7;
                    break;
                }

            }
        }

    }

    ave = (float) sum[temp]/(float) c[temp];
    cout<< sum[temp] << endl << c[temp] << endl;
    cout<< "Average size is: " << ave <<endl;

    cout<<endl<<endl<<endl;
    ptr2(days,weeks);
}

//dhmiourgia organismou kai prosthiki tou sto xarth
void create()
{
    char l;

    ptr2 = &pause;

    cout << "Choose a letter from below: " << endl;
    for(int i = 2; i < 10; i++)
    {
        cout << letters[i] << endl;
    }

    cin>>l;
    do
    {
        cout<<endl<<"Give the x position:  "<<endl;
        cin>>x;
        cout<<endl<<"Give the y position:  "<<endl;
        cin>>y;

    }while(map2[x][y] == 1);


    Operations s = Operations :: Operations(l, x, y, 2);
    sy.push_back(s);
    ptr2(days,weeks);
}

void addNets()
{
    int le;
    do
    {
        cout<<"Give x and y to determine the net's initial cell"<<endl;
        cout<<"Give x position:  "<<endl;
        cin>>x;
        cout<<endl<<"Give y position:  "<<endl;
        cin>>y;
    }while(limits(x,y));

    do
    {
        cout<<"Give the length and the width of the net"<<endl;
        cout<<"Give a number of cells to determine the length of the net:  "<< endl;
        cin>>le;
        cout<<endl<<"Give a number of cells to determine the width of the net:  "<<endl;
        cin>>w;
    }while(limits(x+le, y+w));

    for(int i = x; i < x+le; i++)
    {
        for(int j = 0; j < y+w; j++)
        {
            for(int k = 0; k < sy.size(); k++)
            {
                if(sy[k].get_pos_x() == i && sy[k].get_pos_y() == j)
                {
                    sy.erase(sy.begin() + k);
                }
            }

            map[i][j] = '*';
        }
    }

    showInfo();
    for(int i = x; i < x+le; i++)
    {
        for(int j = 0; j < y+w; j++)
        {
            map[i][j] = '~';
        }
    }
    cout<<"After the net the ecosystem is like this: "<<endl<<endl;
    showInfo();
    ptr2(days,weeks);

}

void addPollution()
{
    int le;
    do
    {
        cout<<"Give x and y to determine the pollution's initial cell"<<endl;
        cout<<"Give x position:  "<<endl;
        cin>>x;
        cout<<endl<<"Give y position:  "<<endl;
        cin>>y;
    }while(limits(x,y));

    do
    {
        cout<<"Give the length and the width of the pollution"<<endl;
        cout<<"Give a number of cells to determine the length of the pollution:  "<< endl;
        cin>>le;
        cout<<endl<<"Give a number of cells to determine the width of the pollution:  "<<endl;
        cin>>w;
    }while(limits(x+le, y+w));

    for(int i = x; i < x+le; i++)
    {
        for(int j = 0; j < y+w; j++)
        {
            for(int k = 0; k < sy.size(); k++)
            {
                if(sy[k].get_pos_x() == i && sy[k].get_pos_y() == j)
                {
                    int s = sy[k].get_size();
                    sy[k].set_size(s-10);
                }
            }

            map[i][j] = '~';
        }
    }

    ptr2(days,weeks);
}

//sunarthsh pou kaleitai otan patame to koumpi 'p' gia n kanoume pause ths proswoiwshs
void pause(int days, int weeks)
{
    ptr  = &start;
    ptr2 = &pause;


    char answer;


        cout<< "Menu:" << endl
        << "(i). Info Per Organism" << endl
        << "(a). Average Size for a category" << endl
        << "(n). Number of living organisms" << endl
        << "(c). Create a new organism" <<endl
        << "(N). Add net" <<endl
        << "(P). Add Pollution" <<endl
        << "(r). Resume" << endl
        << "(R). Restart" << endl
        << "Press a letter" << endl;
        cin >> answer;
        switch(answer)
        {
            case 'i':
            {
                info();
                break;
            }
            case 'a':
            {
                average();
                break;
            }
            case 'n':
            {
                cout<<"Number of living organisms: "<< endl
                    <<sy.size()<<endl;
                ptr2(days, weeks);
                break;
            }
            case 'c':
            {
                create();
                break;
            }
            case 'N':
            {
                addNets();
                break;
            }
            case 'P':
            {
                addPollution();
                break;
            }
            case 'r':
            {
                for( ; ; )
                {
                    cont();
                    showInfo();
                    wait(5);
                    if(kbhit())
                    {
                        cin>>answer;
                        if(answer == 'p')
                        {
                            ptr2(days,weeks);
                            break;
                        }
                        else if(answer != 'p') continue;
                    }

                    days++;
                    cout<< "Day:  " << days << endl << endl;
                    if(days == 7 * weeks)
                    {
                        cout<<"Week:  "<< weeks << endl << endl;
                        weeks++;
                    }
                    answer = ' ';

                }
                break;
            }

            case 'R':
            {
                ptr();
                break;
            }

            default: return;

        }

}

//sunarthsh gia na arxisei h proswmoiwsh
void start()
{
    ptr2 = &pause;

    char answer;
    days = 0;
    weeks = 1;

    init();
    showInfo();

    cout<<endl<< endl<< endl;
    cout<<endl<< endl<< endl;

    for( ; ; )
    {
        cont();
        showInfo();
        wait(5);

        //elegxos an patithike to koumpi 'p' wste n ginei pause ths proswmoiwshs
        if(kbhit())
        {
            cin>>answer;
            if(answer == 'p') ptr2(days,weeks);
            break;
        }

        cout<<endl<< endl<< endl;
        cout<<endl<< endl<< endl;

        //Metrame tis meres ths proswmoiwshs
        days++;
        cout<< "Day:  " << days << endl << endl;

        //Elegxoume meta apo kathe mera an trafhkan oi organismoi
        for(int i = 0; i < sy.size(); i++)
        {
            if(sy[i].get_size() < 20)
            {
                if(sy[i].get_food() != sy[i].get_quantity()) sy[i].set_size(sy[i].get_size() - 10);
            }
        }

        //Metrame tis ebdomades ths proswmoiwshs
        if(days == 7 * weeks)
        {
            cout<<"Week:  "<< weeks << endl << endl;
            weeks++;

            //Elegxos gia thanatous
            for(int i = 0; i < sy.size(); i++)
            {
                if(sy[i].get_size() < 20) sy.erase(sy.begin() + i);
            }
        }
        answer = ' ';
    }
}








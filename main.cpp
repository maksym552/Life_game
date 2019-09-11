#include <iostream>
#include <time.h>
#include <windows.h>
#include <cstdlib>
#include <stdlib.h>
using namespace std;
HANDLE hOut;
char tab[25][25],tab2[25][25],l[25][25],h[25][25],m[25][25];
string istota;
void wybor(),gra(),menu();
int ilezywych()
{
    int g=0;
    for(int i=0; i<25; i++)
    {
        for(int j=0; j<25; j++)
        {
            if(tab[i][j]=='0')
                g++;
        }
    }
    return g;
}
class Pole
{
public:

    void add()
    {
        for(int i=0; i<25; i++)
        {
            for(int j=0; j<25; j++)
            {
                int x;
                x=rand()%2;
                if(x==1)
                    tab[i][j]='0';
                else
                    tab[i][j]=' ';
            }
        }
    }
    void write()
    {
        hOut = GetStdHandle( STD_OUTPUT_HANDLE );
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED |BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED);
        cout<<"  +--------------------------------------------------+"<<endl;
        for(int i=0; i<25; i++)
        {
            cout<<" |";
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
            for(int j=0; j<25; j++)
            {
                if (tab[i][j]!='0')
                {
                    cout<<tab[i][j];
                }
                else
                {
                    SetConsoleTextAttribute( hOut, BACKGROUND_GREEN|FOREGROUND_GREEN);
                    cout<<tab[i][j];

                }
                cout<<" ";
                SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            }
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED |BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED);
            cout<<" |"<<endl;
        }
        cout<<"  +--------------------------------------------------+"<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
        cout<<"Na planszy jest jeszcze: "<<ilezywych()<<" "<<istota<<"/ow/y/e";
    }
    void copyfromtab2()
    {
        for(int i=0; i<25; i++)
        {
            for(int j=0; j<25; j++)
            {
                tab[i][j]=tab2[i][j];
            }
        }
    }

};
class Life
{
public:
    void check()
    {
        for(int i=0; i<25; i++)
        {
            for(int j=0; j<25; j++)
            {
                tab2[i][j] = circle(i,j);
            }
        }
    }
    char circle(int a,int b)
    {
        int sasiad=0;
        /*Narozniki*/
        if ((a == 0)&&(b == 0))
        {
            if (tab[a + 1][b] == '0')
                sasiad++;
            if (tab[a + 1][b + 1] == '0')
                sasiad++;
            if (tab[a][b + 1] == '0')
                sasiad++;
        }
        if ((a == 24)&& (b == 0))
        {
            if (tab[a - 1][b] == '0')
                sasiad++;
            if (tab[a - 1][b + 1] == '0')
                sasiad++;
            if (tab[a][b + 1] == '0')
                sasiad++;
        }
        if ((a == 0)&& (b == 24))
        {
            if (tab[a + 1][b] == '0')
                sasiad++;
            if (tab[a + 1][b - 1] == '0')
                sasiad++;
            if (tab[a][b - 1] == '0')
                sasiad++;
        }
        if ((a == 24)&& (b == 24))
        {
            if (tab[a - 1][b] == '0')
                sasiad++;
            if (tab[a - 1][b - 1] == '0')
                sasiad++;
            if (tab[a][b - 1] == '0')
                sasiad++;
        }
        /*boki*/
        if ((a>=1 )&& (a<=23) && (b==0))
        {
            if (tab[a - 1][b] == '0')
                sasiad++;
            if (tab[a - 1][b + 1] == '0')
                sasiad++;
            if (tab[a][b + 1] == '0')
                sasiad++;
            if (tab[a + 1][b + 1] == '0')
                sasiad++;
            if (tab[a + 1][b] == '0')
                sasiad++;
        }
        if ((a>=1) && (a<=23) && (b==24))
        {
            if (tab[a - 1][b] == '0')
                sasiad++;
            if (tab[a - 1][b - 1] == '0')
                sasiad++;
            if (tab[a][b - 1] == '0')
                sasiad++;
            if (tab[a + 1][b - 1] == '0')
                sasiad++;
            if (tab[a + 1][b] == '0')
                sasiad++;

        }
        if ((b>=1) && (b<=23) && (a==0))
        {
            if (tab[a][b-1] == '0')
                sasiad++;
            if (tab[a][b + 1] == '0')
                sasiad++;
            if (tab[a+1][b] == '0')
                sasiad++;
            if (tab[a + 1][b - 1] == '0')
                sasiad++;
            if (tab[a + 1][b+1] == '0')
                sasiad++;

        }
        if ((b>=1) && (b<=23) && (a==24))
        {
            if (tab[a][b-1] == '0')
                sasiad++;
            if (tab[a][b + 1] == '0')
                sasiad++;
            if (tab[a-1][b] == '0')
                sasiad++;
            if (tab[a - 1][b - 1] == '0')
                sasiad++;
            if (tab[a - 1][b+1] == '0')
                sasiad++;

        }
        /*srodek*/
        if ((a >= 1) && (a <= 23) && (b >= 1) && (b <= 23))
        {
            if (tab[a+1][b] == '0')
                sasiad++;
            if (tab[a-1][b] == '0')
                sasiad++;
            if (tab[a][b+1] == '0')
                sasiad++;
            if (tab[a][b-1] == '0')
                sasiad++;
            if (tab[a+1][b+1] == '0')
                sasiad++;
            if (tab[a+1][b-1] == '0')
                sasiad++;
            if (tab[a-1][b+1] == '0')
                sasiad++;
            if (tab[a-1][b-1] == '0')
                sasiad++;
        }
        char c;
        if(tab[a][b]=='0')
        {
            if (sasiad==2 || sasiad==3)
                c='0';
            else
                c=0;
        }
        else if(tab[a][b] != '0')
        {
            if(sasiad==3)
                c = '0';
            else
                c = ' ';
        }
        return c;

    }
};
void gra()
{
    //S
    m[14][0]='L';
    m[10][1]='L';
    m[10][2]='L';
    m[10][3]='L';
    m[11][0]='L';
    m[12][1]='L';
    m[12][2]='L';
    m[13][3]='L';
    m[14][2]='L';
    m[14][1]='L';
    //T
    m[10][5]='L';
    m[10][6]='L';
    m[10][7]='L';
    m[10][8]='L';
    m[10][9]='L';
    m[11][7]='L';
    m[12][7]='L';
    m[13][7]='L';
    m[14][7]='L';
    //A
    m[10][12]='L';
    m[11][11]='L';
    m[11][13]='L';
    m[12][11]='L';
    m[12][13]='L';
    m[13][11]='L';
    m[13][13]='L';
    m[14][11]='L';
    m[14][13]='L';
    m[13][12]='L';
    //R
    m[10][15]='L';
    m[10][16]='L';
    m[10][17]='L';
    m[11][15]='L';
    m[11][18]='L';
    m[12][15]='L';
    m[12][17]='L';
    m[12][16]='L';
    m[13][15]='L';
    m[13][17]='L';
    m[14][15]='L';
    m[14][18]='L';
    //T
    m[10][20]='L';
    m[10][21]='L';
    m[10][22]='L';
    m[10][23]='L';
    m[10][24]='L';
    m[11][22]='L';
    m[12][22]='L';
    m[13][22]='L';
    m[14][22]='L';
    hOut = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED |BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED);
    cout<<"  +--------------------------------------------------+"<<endl;
    for(int i=0; i<25; i++)
    {
        cout<<" |";
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
        for(int j=0; j<25; j++)
        {
            if (m[i][j]!='L')
            {
                cout<<m[i][j];
            }
            else
            {
                SetConsoleTextAttribute( hOut, BACKGROUND_GREEN|BACKGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_BLUE);
                cout<<m[i][j];

            }
            cout<<" ";
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
        }
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED |BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED);
        cout<<" |"<<endl;
    }
    cout<<"  +--------------------------------------------------+"<<endl;
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
    int a;
    cout<<"Podaj ile faz zycia: ";
    cin>>a;
    cout<<"Jak nazwiesz swoje formy zycia: ";
    cin>>istota;
    system("cls");
    srand(time(NULL));
    Pole tab1;
    Life life1;
    tab1.add();
    tab1.write();
    cout<<endl<<endl;
    for(int i=0; i<=a; i++)
    {

        life1.check();
        tab1.copyfromtab2();
        system("cls");
        tab1.write();
        cout<<endl<<endl;
        Sleep(300);

    }
    cout<<"Czy wrocic do Menu? T/N ";
    char pp;
    cin>>pp;
    if((pp=='T')||(pp=='t'))
    {
        system("cls");
        menu();
    }
    else
        exit(0);

}
void menu()
{
    h[4][6]='G';
    h[4][7]='A';
    h[4][8]='M';
    h[4][9]='E';
    h[4][10]=' ';
    h[4][11]='O';
    h[4][12]='F';
    h[4][13]=' ';
    h[4][14]='L';
    h[4][15]='I';
    h[4][16]='F';
    h[4][17]='E';
    h[10][8]='M';
    h[10][9]='A';
    h[10][10]='I';
    h[10][11]='N';
    h[10][12]=' ';
    h[10][13]='M';
    h[10][14]='E';
    h[10][15]='N';
    h[10][16]='U';
    h[12][9]='1';
    h[12][10]=' ';
    h[12][11]=' ';
    h[12][12]='P';
    h[12][13]='L';
    h[12][14]='A';
    h[12][15]='Y';
    h[13][9]='2';
    h[13][10]=' ';
    h[13][11]=' ';
    h[13][12]='E';
    h[13][13]='X';
    h[13][14]='I';
    h[13][15]='T';
    hOut = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED |BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED);
    cout<<"  +--------------------------------------------------+"<<endl;
    for(int i=0; i<25; i++)
    {
        cout<<" |";
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
        for(int j=0; j<25; j++)
        {
            if (h[i][j]!='#')
            {
                cout<<h[i][j];
            }
            else
            {
                SetConsoleTextAttribute( hOut, BACKGROUND_GREEN|BACKGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_BLUE);
                cout<<h[i][j];

            }
            cout<<" ";
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
        }
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED |BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED);
        cout<<" |"<<endl;
    }
    cout<<"  +--------------------------------------------------+"<<endl;
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
    wybor();
}
void wybor()
{
    cout<<"Podaj liczbe polecenia: ";
    int b;
    cin>>b;
    switch(b)
    {
    case 1:
        system("cls");
        gra();
        break;
    case 2:
        system("exit");
        break;
    default:
        cout<<"Nie wybrano zadnej z opcji spróbuj ponownie"<<endl;
        wybor();
        break;
    }
}
void poczatek()
{
    l[12][10-2]='L';
    l[12][11-2]='O';
    l[12][12-2]='A';
    l[12][13-2]='D';
    l[12][14-2]='I';
    l[12][15-2]='N';
    l[12][16-2]='G';
    l[13][6-2]='|';
    l[13][20-2]='|';
    l[21][16]='C';
    l[21][17]='R';
    l[21][18]='E';
    l[21][19]='A';
    l[21][20]='T';
    l[21][21]='E';
    l[21][22]='D';
    l[22][19]='B';
    l[22][20]='Y';
    l[23][17]='M';
    l[23][18]='A';
    l[23][19]='K';
    l[23][20]='S';
    l[23][21]='Y';
    l[23][22]='M';
    l[24][15]='J';
    l[24][16]='E';
    l[24][17]='R';
    l[24][18]='M';
    l[24][19]='O';
    l[24][20]='L';
    l[24][21]='O';
    l[24][22]='N';
    l[24][23]='E';
    l[24][24]='K';
    for(int k=5; k<=18; k++)
    {
        hOut = GetStdHandle( STD_OUTPUT_HANDLE );
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED |BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED);
        cout<<"  +--------------------------------------------------+"<<endl;
        for(int i=0; i<25; i++)
        {
            cout<<" |";
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
            for(int j=0; j<25; j++)
            {
                if (l[i][j]!='#')
                {
                    cout<<l[i][j];
                }
                else
                {
                    SetConsoleTextAttribute( hOut, BACKGROUND_GREEN|BACKGROUND_BLUE|BACKGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_RED);
                    cout<<l[i][j];

                }
                cout<<" ";
                SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            }
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED |BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED);
            cout<<" |"<<endl;
        }
        cout<<"  +--------------------------------------------------+"<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
        l[13][k]='#';
        Sleep(100);
        system("cls");
    }
    menu();
}
int main()
{
    poczatek();
    return 0;
}

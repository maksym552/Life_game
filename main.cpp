#include <iostream>
#include <time.h>
#include <windows.h>
#include <cstdlib>
using namespace std;
int tab[10][10],tab2[10][10];
class Pole{
    public:

    void add(){
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                tab[i][j]=rand()%2;
            }
        }
    }
    void write(){
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                cout<<tab[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    void copyfromtab2(){
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                tab[i][j]=tab2[i][j];
            }
        }
    }

};
class Life{
    public:
    void check(){
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                  tab2[i][j] = circle(i,j);
            }
        }
    }
    int circle(int a,int b){
        int sasiad=0;
        /*Narozniki*/
        if ((a == 0)&&(b == 0)) {
            if (tab[a + 1][b] == 1) sasiad++;
            if (tab[a + 1][b + 1] == 1) sasiad++;
            if (tab[a][b + 1] == 1) sasiad++;
        }
         if ((a == 9)&& (b == 0)) {
            if (tab[a - 1][b] == 1) sasiad++;
            if (tab[a - 1][b + 1] == 1) sasiad++;
            if (tab[a][b + 1] == 1) sasiad++;
        }
         if ((a == 0)&& (b == 9)) {
            if (tab[a + 1][b] == 1) sasiad++;
            if (tab[a + 1][b - 1] == 1) sasiad++;
            if (tab[a][b - 1] == 1) sasiad++;
        }
         if ((a == 9)&& (b == 9)) {
            if (tab[a - 1][b] == 1) sasiad++;
            if (tab[a - 1][b - 1] == 1) sasiad++;
            if (tab[a][b - 1] == 1) sasiad++;
        }
        /*boki*/
         if ((a>=1 )&& (a<=8) && (b==0)){
            if (tab[a - 1][b] == 1) sasiad++;
            if (tab[a - 1][b + 1] == 1) sasiad++;
            if (tab[a][b + 1] == 1) sasiad++;
            if (tab[a + 1][b + 1] == 1) sasiad++;
            if (tab[a + 1][b] == 1) sasiad++;
        }
         if ((a>=1) && (a<=8) && (b==9)){
            if (tab[a - 1][b] == 1) sasiad++;
            if (tab[a - 1][b - 1] == 1) sasiad++;
            if (tab[a][b - 1] == 1) sasiad++;
            if (tab[a + 1][b - 1] == 1) sasiad++;
            if (tab[a + 1][b] == 1) sasiad++;

        }
         if ((b>=1) && (b<=8) && (a==0)){
            if (tab[a][b-1] == 1) sasiad++;
            if (tab[a][b + 1] == 1) sasiad++;
            if (tab[a+1][b] == 1) sasiad++;
            if (tab[a + 1][b - 1] == 1) sasiad++;
            if (tab[a + 1][b+1] == 1) sasiad++;

        }
         if ((b>=1) && (b<=8) && (a==9)){
            if (tab[a][b-1] == 1) sasiad++;
            if (tab[a][b + 1] == 1) sasiad++;
            if (tab[a-1][b] == 1) sasiad++;
            if (tab[a - 1][b - 1] == 1) sasiad++;
            if (tab[a - 1][b+1] == 1) sasiad++;

        }
        /*srodek*/
         if ((a >= 1) && (a <= 8) && (b >= 1) && (b <= 8)){
            if (tab[a+1][b] == 1) sasiad++;
            if (tab[a-1][b] == 1) sasiad++;
            if (tab[a][b+1] == 1) sasiad++;
            if (tab[a][b-1] == 1) sasiad++;
            if (tab[a+1][b+1] == 1) sasiad++;
            if (tab[a+1][b-1] == 1) sasiad++;
            if (tab[a-1][b+1] == 1) sasiad++;
            if (tab[a-1][b-1] == 1) sasiad++;
        }
        int c;
        if(tab[a][b]==1){
            if (sasiad==2 || sasiad==3) c=1;
            else c=0;
        }
        else if(tab[a][b] == 0) {
            if(sasiad==3) c = 1;
            else c = 0;
        }
        return c;

    }
};
int main()
{
    srand(time(NULL));
    Pole tab1;
    Life life1;
    tab1.add();
    tab1.write();cout<<endl<<endl;
    for(int i=0;i<11;i++){

            life1.check();
            tab1.copyfromtab2();
            tab1.write();cout<<endl<<endl;
            Sleep(300);
    }
    return 0;
}

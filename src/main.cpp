#include "game.h"
#include "plant.h"

int main()
{
    string username=getusername();
    int money=1;
    if (username=="hack")
        money=999999;
    int storage[6]={0,0,0,0,0,0};
    plant* plants[4][4];
    for (int i=0;i<4;i++)
        for (int j=0;j<4;j++)
            plants[i][j]= nullptr;
    menu(money,storage,plants);
    for (int i=0;i<4;i++)
        for (int j=0;j<4;j++)
            delete plants[i][j];
}

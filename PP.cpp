#include <bits/stdc++.h>
using namespace std;
class plant
{
    int RemainingTime=30;
protected: char type;
public:
    int GetTime();
    bool decrement(int& PassedTime,int (&storage)[6]);
    char GetType()
    {
        return type;
    }
    plant (char type='0')
    {
        this-> type = type;
    }
    ~plant (){
        cout<<"Plant of type "<<type<<" was collected\n";
        type='0';
    }
    virtual int eat (){}
};
class fruit : public plant
{
protected:
    virtual int eat ()
    {
        cout<<"You Like Fruits In General\n";
        if  (type =='S')
            return 2;
        return 2;
    }
public:
    fruit(char type='0'):plant(type){};
};
class tree final : public fruit
{
    int eat ()
    {
        cout<<"You Like Tree Fruits\n";
        if (type=='B')
            return 2;
        return 2;
    }
public:
    tree(char type='0'):fruit(type){cout<< "tree of type "<<type<<" was planted\n";};
};
class bush : public fruit
{
public:
    bush(char type='0'):fruit(type){cout<< "bush of type "<<type<<" was planted\n";};
};
class flower : public plant
{
public:
    flower(char type='0'):plant(type){cout<< "flower of type "<<type<<" was planted\n";};
};
void menu (int& money, int (&storage)[6],plant* (&plants)[4][4]);
bool poor (int& money, int price);
string getusername();
void showplants(plant* (&plants)[4][4]);
void Fbuy (char type,plant* (&plants)[4][4]);
void buy (int& money, plant* (&plants)[4][4]);
bool anyempty(plant* (&plants)[4][4]);
void store(char type,int (&storage)[6]);
void sell(int& money,int (&storage)[6]);
void Fsell(int& price, int& money, int& type,int (&storage)[6],int& quantity);
void GoEat(int& money, plant* (&plants)[4][4]);
void help();
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
void menu(int& money, int (&storage)[6], plant* (&plants)[4][4] )
{
    cout<<"\n ----------------------------------------- \n MENU (type what do you want to do)\n";
    cout<<" buy\n sell\n eat\n show plants\n show money\n wait\n quit\n help\n";
    string option;
    while (option!="buy"&&option!="sell"&&option!="show plants"&&option!="quit"&&option!="show money"&&option!="wait"&& option != "help"&& option != "eat")
        getline(cin, option);
    if (option=="buy"){
        buy(money, plants);
        menu(money,storage,plants);
    }
    else if (option=="sell")
    {
        sell(money,storage);
        menu(money,storage,plants);
    }
    else if (option=="eat")
    {
        GoEat(money, plants);
        menu(money,storage,plants);
    }
    else if (option=="show plants")
    {
        showplants(plants);
        menu(money,storage,plants);
    }
    else if (option=="quit")
    {
        cout<<"ARE YOU SURE? YOU WILL LOSE ALL PROGRESS (Yes/No)"<<endl;
        while (option!="Yes"&&option!="NO"&&option!="no"&&option!="yes")
            cin>>option;
        if (option=="NO"||option=="no")
            menu(money,storage,plants);
    }
    else if (option=="show money")
    {
        cout<<"money= "<<money<<endl;
        menu(money,storage,plants);
    }
    else if (option=="wait")
    {
        cout<<"How many seconds will you wait????\n";
        int n; cin>>n;
        for (long long i=0;i<n*(9e7);i++);
        for (int k=0;k<16;k++){
            for (int i=0;i<4;i++){
                for (int j=0;j<4;j++){
                    if (plants[i][j]!=nullptr){
                        bool flag=plants[i][j]->decrement(n,storage);
                        if(flag)
                            plants[i][j]=nullptr;
                    }
                }
            }
        }
        cout<<"You are a very patient person\n";
        menu (money, storage, plants);
    }
    else if (option=="help")
    {
        help(); menu(money, storage, plants);
    }
}
int plant::GetTime() {
    return RemainingTime;
}
bool plant::decrement(int &PassedTime,int (&storage)[6]) {
    RemainingTime -= PassedTime;
    PassedTime=0;
    if (RemainingTime <= 0){
        store(type,storage);
        delete this;
        return true;
    }
    return false;
}
void store(char type, int (&storage)[6])
{
    if (type =='A')
        storage[0]++;
    else if (type=='B')
        storage[1]++;
    else if (type=='G')
        storage[2]++;
    else if (type=='S')
        storage[3]++;
    else if (type=='R')
        storage[4]++;
    else
        storage[5]++;
}
bool poor (int& money, int price)
{
    if (money<price)
    {
        cout<<"YOU POOR THING HAHAHAHH CAN'T AFFORD A PLANT AHAHAHHAHAHA\n";
        return true;
    }
    else
        money-=price;
        return false;
}
string getusername()
{
    cout<< "HELLO, AND WELCOME TO AgriTopia)\n";
    string hi="";
    while (hi!="HI"&&hi!="hi"&&hi!="Hi"&&hi!="hI")
    {
        cout<<"(Type hi to continue)\n";
        cin>>hi;
        if (hi=="skip")
            return "skip";
        if (hi=="hack")
            return "hack";
    }
    cout<< "in AgriTopia you can explore a variety of building and their different mechanics\n";
    while (hi!="OK"&&hi!="Ok"&&hi!="oK"&&hi!="ok")
    {
        cout<<"(Type ok to continue)\n";
        cin>>hi;
    }
    hi="";
    cout<< "But of course, that's only if you can pay for these buildings.\n";
    while (hi!="OK"&&hi!="Ok"&&hi!="oK"&&hi!="ok")
    {
        cout<<"(Type ok to continue)\n";
        cin>>hi;
    }
    cout<<"So Anyways, here are your options MR. .... oh wait what was your name again?\n";
    string username; cin>>username;
    cout<<"Ok "<<username<<", now choose a building to buy:\n school: 9999999999999999999 EGP\n petshop: 9999999999999999999 EGP\n hospital: 9999999999999999999 EGP\n greenhouse: 9 EGP\n (you currently have 10 EGP)\n";
    cin>>hi;
    while (hi!="Greenhouse"&&hi!="greenhouse")
    {
        cout<<"Invalid choice: not enough money or wrong building maybe idk.\n DUDE JUST WRITE green house\n";
        cin>>hi;
    }
    cout<<" OK go plant\n";
    return username;
}
void showplants(plant* (&plants)[4][4])
{
    for(int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            if (plants[i][j]==nullptr)
                cout<<"0 ";
            else
                cout<<plants[i][j]->GetType()<<" ";
        }
        cout<<endl;
    }
}
void buy(int& money, plant* (&plants)[4][4])
{
    cout<<"options:\n fruits\n flowers\n";
    string option;
    while (option!="fruits"&& option !="flowers")
        cin>>option;
    if (option =="fruits")
        {
            cout<<"options:\n trees\n bushes\n";
            while (option!="trees"&& option !="bushes")
                cin>>option;
            string type;
            if (option=="trees")
            {
                cout<<"options: banana 1EGP\n apple 1EGP \n";
                while (type!="banana"&& type !="apple")
                    cin>>type;
                if (type=="banana"){
                    if(!poor(money,1))
                        Fbuy('B', plants);

                }else{
                    if(!poor(money,1))
                        Fbuy('A', plants);
                }
            }
            else
            {
                cout<<"options: gooseberry 1EGP\n strawberry 1EGP \n";
                while (type!="gooseberry"&& type !="strawberry")
                    cin>>type;
                if (type=="gooseberry")
                {
                    if(!poor(money,1))
                        Fbuy('G', plants);
                }
                else
                {
                    if(!poor(money,1))
                        Fbuy('S', plants);
                }
            }
    }
    else
    {
        string type;
        cout<<"options: rose 1EGP\n tulip 1EGP \n";
        while (type!="rose"&& type !="tulip")
            cin>>type;
        if (type=="rose")
        {
            if(!poor(money,1))
            Fbuy('R', plants);
        }
        else
        {
            if(!poor(money,1))
            Fbuy('T', plants);
        }
    }
}
bool anyempty(plant* (&plants)[4][4])
{
    for(int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            if (plants[i][j]==nullptr)
                return true;
        }
    }
    cout<<"NO Empty\n";
    return false;
}
void Fbuy (char type,plant* (&plants)[4][4])
{
    if (anyempty(plants))
    {
        cout<<"Choose empty space:\n";
        showplants(plants);
        int i,j;
        cout<<endl<<"Row: "; cin>>i;
        cout<<"column: "; cin>>j;
        if (plants[i][j]==nullptr)
        {
            if (type=='A'||type=='B')
            {
                plants[i][j]= new tree(type);
            }
            else if (type=='G'||type=='S')
            {
                plants[i][j]= new bush(type);
            }
            else
            {
                plants[i][j]= new flower(type);
            }
        }
        else
        {
            cout<<"NOT EMPTY. please, try again";
            Fbuy(type,plants);
        }
    }
}
void sell(int& money,int (&storage)[6])
{
    cout<<"You currently have:"<<endl;
    int c=0;
    if (storage[0]!=0)
    {
        c++;
        cout<<c<<"- apples, you currently own "<<storage[0]<<" of it"<<endl;
    }
    if (storage[1]!=0)
    {
        c++;
        cout<<c<<"- bananas, you currently own "<<storage[1]<<" of it"<<endl;
    }
    if (storage[2]!=0)
    {
        c++;
        cout<<c<<"- gooseberrys, you currently own "<<storage[2]<<" of it"<<endl;
    }
    if (storage[3]!=0)
    {
        c++;
        cout<<c<<"- strawberrys, you currently own "<<storage[3]<<" of it"<<endl;
    }
    if (storage[4]!=0)
    {
        c++;
        cout<<c<<"- roses, you currently own "<<storage[4]<<" of it"<<endl;
    }
    if (storage[5]!=0)
    {
        c++;
        cout<<c<<"- tulips, you currently own "<<storage[5]<<" of it"<<endl;
    }
    if (c==0)
        cout<<" Nothing, nothing to sell. Try seeking professional help\n";
    else{
        string option; cin>>option;
        while (option!="apples"&& option!="bananas"&& option!="gooseberrys"&& option!="strawberrys"&& option!="roses"&& option!="tulips")
        {
            cout <<"Please enter the name of the plant (E.g. apples, roses). Also try seeking professional help\n";
            cin>>option;
        }
        int type,quantity,price;
        if (option=="apples"){
            type=0;
            price=2;
        }else if (option=="bananas"){
            type=1;
            price=2;
        }else if (option=="gooseberrys"){
            type=2;
            price=2;
        }else if (option=="strawberrys"){
            type=3;
            price=2;
        }else if (option=="roses"){
            type=4;
            price=2;
        }else{
            type=5;
            price=2;
        }
        cout<<"please enter the quantity you want to sell\n";
        cin>>quantity;
        while (quantity>storage[type]||quantity<0)
        {
            if (quantity<0)
                cout<<"huh?\n";
            else
                cout<<"You don't have "<<quantity<<" of this plant. Enter a quantity you have ,please";
            cin>>quantity;
        }
        Fsell(price,money,type, storage, quantity);
    }
}
void Fsell(int& price, int& money, int& type,int (&storage)[6],int& quantity)
{
    storage[type]-=quantity;
    money+=price*quantity;
    cout<<"You earned "<<price*quantity<<" EGP\n";
}
void GoEat(int& money, plant* (&plants)[4][4]){
    for (int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            if (plants[i][j]!=nullptr&&plants[i][j]->GetType()!='R'&&plants[i][j]->GetType()!='T'){
                int n= plants[i][j]->eat();
                money+=n;
                cout<<"you have earned "<<n<<endl;
                delete plants[i][j];
                plants[i][j]=nullptr;
            }
        }
    }
}
void help ()
{
    cout<<"you can use buy to buy, be aware that you must not have less money than needed\n";
    cout<<"you can use sell to earn money buy selling plants stored in your storage\n";
    cout<<"you can use eat to earn money by eating planted fruits directly without having to wait. However, this may or may not cause effects\n";
    cout<<"you can use wait to wait for plants to mature. this is needed before selling\n";
    cout<<"you can use show plants to show currently planted plants\n";
    cout<<"show money shows current money\n";
    cout<<"quit ends the game\n";
    cout<<"you cab use help to call for help\n";
}

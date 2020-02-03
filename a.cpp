
#include<bits/stdc++.h>

using namespace std;

int n;

class Bot
{
    public:

    string name;

    bool first_turn;

    pair < int , int > curposition;

    void _move(string direction , string name){

        if(direction == "L"){
            if(name.compare("Bot1") == 0){
                cout << "LEFT1\n\n";
            }
            else{
                cout << "LEFT2\n\n";
            }
        }
        else if(direction == "R"){
            if(name.compare("Bot1") == 0){
                cout << "RIGHT1\n\n";
            }
            else{
                cout << "RIGHT2\n\n";
            }
        }
        else if(direction == "U"){
            if(name.compare("Bot1") == 0){
                cout << "UP1\n\n";
            }
            else{
                cout << "UP2\n\n";
            }
        }
        else if(direction == "D"){
            if(name.compare("Bot1") == 0){
                cout << "DOWN1\n\n";
            }
            else{
                cout << "DOWN2\n\n";
            }
        }
    }


};

void Show(vector < vector < char> > grid , pair < int , int > b1pos , pair < int , int > b2pos){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(i == b1pos.first && j == b1pos.second){
                cout << "B1  ";
            }
            else if(i == b2pos.first && j == b2pos.second){
                cout << "B2  ";
            }
            else{
                cout << grid[i][j] << "  ";
            }
        }
        cout << "\n";
    }
//    cin.ignore();
//    cout << "Press Enter\n";
//    cin.get();
cout << "\n";
}


int main(){


    cout << "Input Grid size:\n";
    cin >> n;

    vector < vector < char> > grid;
    vector < pair < int , int > > dirtycell;

    for(int i = 0 ; i < n ; i++){
        vector < char > t(n);
        for(int j = 0 ; j < n ; j++){
            cin >> t[j];
            if(t[j] == 'd'){
                dirtycell.push_back(make_pair(i , j));
            }
        }
        grid.push_back(t);
    }

    system("clear");
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }


    Bot bot1 , bot2;

    bot1.name = "Bot1";
    bot2.name = "Bot2";

    bot1.curposition.first = 0;
    bot2.curposition.first = n-1;
    bot1.curposition.second = n-1;
    bot2.curposition.second = 0;

    while(!dirtycell.empty()){
        int b1x = bot1.curposition.first;
        int b1y = bot1.curposition.second;

        int b2x = bot2.curposition.first;
        int b2y = bot2.curposition.second;

        vector < pair < int , int > >::iterator it , bot1targeted;
        int dist = n*2;
        for(it = dirtycell.begin() ; it != dirtycell.end() ; it++){
            int distfrombot1 = abs(b1x - it->first) + abs(b1y - it->second);
            if(dist > distfrombot1){
                bot1targeted = it;
                dist = distfrombot1;
            }
        }

        int xd = bot1.curposition.first - bot1targeted->first;
        int yd = bot1.curposition.second - bot1targeted->second;


        cout << "Bot 1 target: ("  << bot1targeted->first << ", " << bot1targeted->second << ")\n";

        if(xd < 0){
            while(xd < 0){
                cout << "\n\n";
                Show(grid , bot1.curposition , bot2.curposition);
                bot1._move("D" , bot1.name);
                bot1.curposition.first+=1;
                Show(grid , bot1.curposition , bot2.curposition);
                xd++;
            }
        }
        else{
            while(xd > 0){
                //system("clear");
                cout << "\n\n";
                Show(grid , bot1.curposition , bot2.curposition);
                bot1._move("U" , bot1.name);
                bot1.curposition.first-=1;
                Show(grid , bot1.curposition , bot2.curposition);
                xd--;
            }
        }

        if(yd < 0){
            while(yd < 0){
                //system("clear");
                cout << "\n\n";
                Show(grid , bot1.curposition , bot2.curposition);
                bot1._move("R" , bot1.name);
                bot1.curposition.second+=1;
                Show(grid , bot1.curposition , bot2.curposition);
                yd++;
            }
        }
        else{
            while(yd > 0){
                //system("clear");
                cout << "\n\n";
                Show(grid , bot1.curposition , bot2.curposition);
                bot1._move("L" , bot1.name);
                bot1.curposition.second-=1;
                Show(grid , bot1.curposition , bot2.curposition);
                yd--;
            }
        }

        grid[bot1targeted->first][bot1targeted->second] = '-';
        cout << "\nCLEAN1: (" << bot1targeted->first << ", " << bot1targeted->second << ")\n\n";
        dirtycell.erase(bot1targeted);

        if(dirtycell.empty()){
            break;
        }


        cout << "Press Enter";
        cin.ignore();
        cin.get();
        system("clear");

        vector < pair < int , int > >::iterator bot2targeted;
        dist = n*2;
        for(it = dirtycell.begin() ; it != dirtycell.end() ; it++){
            int distfrombot2 = abs(b2x - it->first) + abs(b2y - it->second);
            if(dist > distfrombot2){
                bot2targeted = it;
                dist = distfrombot2;
            }
        }

        xd = bot2.curposition.first - bot2targeted->first;
        yd = bot2.curposition.second - bot2targeted->second;

        cout << "Bot 2 target: ("  << bot2targeted->first << ", " << bot2targeted->second << ")\n";


        if(xd < 0){
            while(xd < 0){
                //system("clear");
                cout << "\n\n";
                Show(grid , bot1.curposition , bot2.curposition);
                bot2._move("D" , bot2.name);
                bot2.curposition.first+=1;
                Show(grid , bot1.curposition , bot2.curposition);
                xd++;
            }
        }
        else{
            while(xd > 0){
                //system("clear");
                cout << "\n\n";
                Show(grid , bot1.curposition , bot2.curposition);
                bot2._move("U" , bot2.name);
                bot2.curposition.first-=1;
                Show(grid , bot1.curposition , bot2.curposition);
                xd--;
            }
        }

        if(yd < 0){
            while(yd < 0){
                //system("clear");
                cout << "\n\n";
                Show(grid , bot1.curposition , bot2.curposition);
                bot2._move("R" , bot2.name);
                bot2.curposition.second+=1;
                Show(grid , bot1.curposition , bot2.curposition);
                yd++;
            }
        }
        else{
            while(yd > 0){
                //system("clear");
                cout << "\n\n";
                Show(grid , bot1.curposition , bot2.curposition);
                bot2._move("L" , bot2.name);
                bot2.curposition.second-=1;
                Show(grid , bot1.curposition , bot2.curposition);
                yd--;
            }
        }

        grid[bot2targeted->first][bot2targeted->second] = '-';
        cout << "\nCLEAN2: (" << bot2targeted->first << ", " << bot2targeted->second << ")\n\n";
        dirtycell.erase(bot2targeted);


        cout << "Press Enter";
        cin.get();
        system("clear");


    }


    cout << "All cleaned :)\n";


}

#include <iostream>
#include <string>
using namespace std;

struct Player
{
    string name;
    string homeTown;
    int age;
    int numGames;
};

int main()
{
    int numOfPlayers;
    cout << "How many esports players are there at TTU who major in CSC? " << endl;
    cin >> numOfPlayers;
    cout << "Please enter in information about each players: " << endl;

    //Array that stores amount of players
    Player* players = new Player[numOfPlayers];
    int **playersHours = new int* [numOfPlayers];

    string name;
    int mostHours = 0;
    int leastHours = 0;
    for(int i = 0; numOfPlayers > i; i++)
    {
        cout << "Player " << i+1 << endl;
        cout << "\tNAME:\t";
        cin.ignore();
        getline(cin, players[i].name);
        cout << "\tHOMETOWN:\t";
        getline(cin, players[i].homeTown);
        cout << "\tAGE:\t";
        cin >> players[i].age;
        cout << "\tHOW MANY GAMES DOES " << players[i].name << " PLAY ";
        cin >> players[i].numGames;

        //Size of of the array that contains number of games a players played
        int size = players[i].numGames;
        //array that contains amount of hours a players played per game
        playersHours[i] = new int[size];
        
        for (int j = 0; j < size; j++)
        {
            cout << "\t\tNUMBERS OF HOURS " << players[i].name << " PLAYED GAME " << j+1 << ": ";
            cin >> playersHours[i][j];
        }
        
    }
    string most, least;
    mostHours = std::numeric_limits<int>::min(); 
    leastHours = std::numeric_limits<int>::max();
    for (int i = 0; i < numOfPlayers; i++)
    {
        int Hours = 0;
        for(int j = 0; j < players[i].numGames; j++)
        {
            Hours += playersHours[i][j];
        }
        if(Hours > mostHours)
        {
            most = players[i].name;
            mostHours = Hours; 
        }

        if(Hours < leastHours)
        {
            least = players[i].name;
            leastHours = Hours; 
        }
    }
    cout << "\nThe player who played the most hours (" << mostHours << " hours) is "  << most << endl;
    cout << "The player who played the least hours (" << leastHours << " hours) is " << least << endl; 
    
    
    delete[] players;
}
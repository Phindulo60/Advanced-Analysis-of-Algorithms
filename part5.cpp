#include<iostream>
#include<bits/stdc++.h>
#include<sstream>
#include<cstring>

using namespace std;

char side_to_move;
int number_of_moves;
string game_space;
string cols[7] ={"a", "b", "c", "d", "e", "f", "g"};

vector<string> tokenize(string s, string del)
{   
    vector<string> denos;
    int start = 0;
    int end = s.find(del);
    while (end != -1) {
        denos.push_back(s.substr(start, end - start));
        start = end + del.size();
        end = s.find(del, start);
    }
    denos.push_back(s.substr(start, end - start));

    return denos;
}

bool compareFunction (char a, char b)
{
    return a<b;
}

void formCongoBoard(string game_space)
{
    vector<vector<string>> matrix_of_congo;
    vector<string> rows =tokenize(game_space, "/");
    for (int i=0; i < rows.size(); i++)
    {
        string row =rows[i];
        vector<string> rows_of_congo;
        for (int j =0; j < row.length(); j++)
        {
            if (isdigit(row[j]))
            {
                
                int x =(int)row[j] - '0';
                for (int k=0; k < x; k++)
                {
                    rows_of_congo.push_back("0");
                }
            }
            else 
            {
                stringstream ss;
                string element;
                ss << row[j];
                ss >> element;
                rows_of_congo.push_back(element);
            }
        }
        matrix_of_congo.push_back(rows_of_congo);

    }

    vector<string> definitions;
    
    vector<string> white_pawn;
    vector<string> black_pawn;
    vector<string> white_superpawn;
    vector<string> black_superpawn;
    vector<string> white_giraffe;
    vector<string> black_giraffe;
    vector<string> white_monkey;
    vector<string> black_monkey;
    vector<string> white_elephant;
    vector<string> black_elephant;
    vector<string> white_lion;
    vector<string> black_lion;
    vector<string> white_crocodile;
    vector<string> black_crocodile;
    vector<string> white_zebra;
    vector<string> black_zebra;

    vector< vector<string>> positions;

    for (int i =0; i< 7; i++)
    {
        for (int j=0; j < 7; j++)
        {
            if (matrix_of_congo[i][j] =="P")
            {
                string col =cols[j];
                white_pawn.push_back(col + to_string(7 - i));
            }
            else if (matrix_of_congo[i][j] =="G")
            {
                string col =cols[j];
                white_giraffe.push_back(col + to_string(7 - i)); 
            }
            else if (matrix_of_congo[i][j] =="M")
            {
                string col =cols[j];
                white_monkey.push_back(col + to_string(7 - i));
            }
            else if(matrix_of_congo[i][j] =="E")
            {
                string col =cols[j];
                white_elephant.push_back(col + to_string(7 - i));
            }
            else if(matrix_of_congo[i][j] =="L")
            {
                string col =cols[j];
                white_lion.push_back(col + to_string(7 - i));
            }
            else if(matrix_of_congo[i][j] =="C")
            {
                string col =cols[j];
                white_crocodile.push_back(col + to_string(7 - i));
            }
            else if(matrix_of_congo[i][j] =="Z")
            {
                string col = cols[j];
                white_zebra.push_back(col + to_string(7 - i));
            }

            else if(matrix_of_congo[i][j] =="p")
            {
                string col =cols[j];
                black_pawn.push_back(col + to_string(7 - i));
            }
            else if (matrix_of_congo[i][j] =="g")
            {
                string col =cols[j];
                black_giraffe.push_back(col + to_string(7 - i)); 
            }
            else if (matrix_of_congo[i][j] =="m")
            {
                string col =cols[j];
                black_monkey.push_back(col + to_string(7 - i));
            }
            else if(matrix_of_congo[i][j] =="e")
            {
                string col =cols[j];
                black_elephant.push_back(col + to_string(7 - i));
            }
            else if(matrix_of_congo[i][j] =="l")
            {
                string col =cols[j];
                black_lion.push_back(col + to_string(7 - i));
            }
            else if(matrix_of_congo[i][j] =="c")
            {
                string col =cols[j];
                black_crocodile.push_back(col + to_string(7 - i));
            }
            else if(matrix_of_congo[i][j] =="z")
            {
                string col = cols[j];
                black_zebra.push_back(col + to_string(7 - i));
            }

            else if (matrix_of_congo[i][j] =="s")
            {
                string col = cols[j];
                black_superpawn.push_back(col + to_string(7 - i));
            }
            else if (matrix_of_congo[i][j] =="S"){
                string col =cols[j];
                white_superpawn.push_back(col + to_string(7 - i));
            }

        }
    }

    definitions.push_back("white pawn: ");
    definitions.push_back("black pawn: ");
    definitions.push_back("white superpawn: ");
    definitions.push_back("black superpawn: ");
    definitions.push_back("white giraffe: ");
    definitions.push_back("black giraffe: ");
    definitions.push_back("white monkey: ");
    definitions.push_back("black monkey: ");
    definitions.push_back("white elephant: ");
    definitions.push_back("black elephant: ");
    definitions.push_back("white lion: ");
    definitions.push_back("black lion: ");
    definitions.push_back("white crocodile: ");
    definitions.push_back("black crocodile: ");
    definitions.push_back("white zebra: ");
    definitions.push_back("black zebra: ");
    string side_to_play ="side to play: ";

    positions.push_back(white_pawn);
    positions.push_back(black_pawn);
    positions.push_back(white_superpawn);
    positions.push_back(black_superpawn);
    positions.push_back(white_giraffe);
    positions.push_back(black_giraffe);
    positions.push_back(white_monkey);
    positions.push_back(black_monkey);
    positions.push_back(white_elephant);
    positions.push_back(black_elephant);
    positions.push_back(white_lion);
    positions.push_back(black_lion);
    positions.push_back(white_crocodile);
    positions.push_back(black_crocodile);
    positions.push_back(white_zebra);
    positions.push_back(black_zebra);

    stringstream ss;
    string element;
    ss << side_to_move;
    ss >> element;
    if (element =="b")
    {
        element ="black";
        side_to_play =side_to_play + element;
    }
    else{

        element ="white";
        side_to_play =side_to_play + element;
    }

    for (int i=0; i < positions.size(); i++)
    {
        sort(positions[i].begin(), positions[i].end());
        cout<<definitions[i];
        for (int j=0; j <positions[i].size(); j++)
        {   
            cout <<positions[i][j]<<" ";
        }
        if(positions.size() !=1){
         cout<<endl;
        }
    }
    cout<<side_to_play<<endl;


    

    

}

void storeFens(vector<string> fens)
{
    
    for (int i=0; i < fens.size(); i++)
    {
        vector<string> arr =tokenize(fens[i], " ");
        
        for (int i=0; i < arr.size(); i++)
        {
            if (i ==0)
            {
                game_space =arr[i];
            }
            else if (i ==1)
            {
                string move =arr[i];
                side_to_move =move[0];
            }
            else 
            {
                stringstream ss(arr[i]);
                ss >> number_of_moves;
            }
        }
    
        formCongoBoard(game_space);
        
        if (i%fens.size() ==0)
        {
            cout <<endl;
        }
    }
    
}
int main()
{
    int N;
    cin>>N;
    string FEN;
    vector<string> fens;
    getline(cin , FEN);

    for (int i =0; i < N;  i++)
    {
        getline(cin ,FEN);
        fens.push_back(FEN);
    }

    storeFens(fens);
return 0;
}
// 2
// gmelecz/ppppppp/7/7/7/PPPPPPP/GMELECZ w 0
// 1m1El2/P1P2P1/1S4C/4S2/1E3S1/1P3c1/2GL3 b 79
// 2l4/7/4z2/4c2/PP2EP1/3L2p/7 b 23
#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<sstream>
#include<cstring>

using namespace std;

char side_to_move;
int number_of_moves;
string game_space;
string files[7] ={"a", "b", "c", "d", "e", "f", "g"};

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

bool emptyOrOppPeiceForWhite(vector< vector<string>> matrix_of_congo, int xP ,int yP)
{   
    bool oppOrEmpty = false;
    char opposition;
    string element =matrix_of_congo[xP][yP];
    opposition =element[0];
    if (opposition >=97 && opposition <=122 || matrix_of_congo[xP][yP] =="0")
    {
        oppOrEmpty = true;
    }
    return oppOrEmpty;
}

bool emptyOrOppPeiceForBlack(vector< vector<string>> matrix_of_congo, int xp ,int yp)
{   
    bool oppOrEmpty = false;
    char opposition;
    string element =matrix_of_congo[xp][yp];
    opposition =element[0];
    if ( opposition>=65 && opposition<=90 || matrix_of_congo[xp][yp] =="0")
    {
        oppOrEmpty = true;
    }
    return oppOrEmpty;
}

bool notCaptureBackwards(vector< vector<string>> matrix_of_congo, int xp ,int yp)
{   
    bool oppOrEmpty = false;
    if (matrix_of_congo[xp][yp] =="0")
    {
        oppOrEmpty = true;
    }
    return oppOrEmpty;
}

void convertToFen(vector< vector<string> > matrix_of_congo, string move_side, int move_number, string outcome){

    vector<string> ranks;
    for (int i =0; i < 7; i++){
        int k = 0;
        string rank="";
        for (int j=0; j < 7; j++){
            char opposition;
            string element =matrix_of_congo[i][j];
            opposition =element[0];

            if (opposition =='0'){
                k +=1;
            }
            else if (opposition>=65 && opposition<=90 || opposition >=97 && opposition <=122)
            {
                if (k !=0)
                {
                    rank =rank + to_string(k);
                    k =0;
                }
                rank =rank + matrix_of_congo[i][j];
            }
        }

        if (k !=0){
            rank =rank + to_string(k);
        }

        ranks.push_back(rank);
    }

    string game_space ="";
    for (int i=0; i < ranks.size(); i++){
        if ((i+1)%ranks.size()==0){
            game_space =game_space + ranks[i];
        }
        else {
            game_space =game_space + ranks[i] + "/";
        }
    }

    cout << game_space <<" "<<move_side<<" "<<to_string(move_number)<<endl;
    cout <<outcome<<endl;

}

void LionMoves(vector< vector<string>> matrix_of_congo, string the_move)
{
    int rank1, rank2, first_file, second_file;

    // rank1 =the_move[1] - 48;
    // rank2 =the_move[3] - 48;

    // stringstream change;
    // stringstream convert;
    // string element1, element2;
    // change << the_move[0];
    // change >> element1;
    // convert << the_move[2];
    // convert >> element2;

    // for (int i =0; i <7; i++){
        
    //     if (element1 == files[i]){
    //         first_file =i;
    //     }
    // }

    // for (int i=0; i < 7; i++){
    //     if (element2 == files[i]){
    //         second_file =i;
    //     }
    // }
    stringstream ss;
    string element;
    ss << side_to_move;
    ss >> element;
    //swap(matrix_of_congo[rank2][second_file], matrix_of_congo[rank1][first_file]);

    // for (int i =0; i <7; i++){
    //     for (int j=0; j < 7; j++){
    //         cout <<matrix_of_congo[i][j]<<" ";
    //     }
    //     cout <<endl;
    // }

    cout <<the_move<<endl;

    
    // if (element =="w")
    // {
    //     string outcome;
    //     if (matrix_of_congo[rank2][second_file] == "l"){
    //         outcome ="White wins";
    //         swap(matrix_of_congo[rank2][second_file], matrix_of_congo[rank1][first_file]);
    //         matrix_of_congo[rank1][first_file] ="0";

    //         // convertToFen(matrix_of_congo, "b", number_of_moves, outcome);

    //         for (int i =0; i <7; i++){
    //             for (int j=0; j < 7; j++){
    //                 cout <<matrix_of_congo[i][j]<<" ";
    //             }
    //             cout <<endl;
    //         }

    //     }  
    //     else {

    //         if (emptyOrOppPeiceForWhite(matrix_of_congo, rank2, second_file) ==true)
    //         {
    //           swap(matrix_of_congo[rank2][second_file], matrix_of_congo[rank1][first_file]);
    //             matrix_of_congo[rank1][first_file] ="0";
    //         }
    //         outcome ="Continue";
    //         // convertToFen(matrix_of_congo, "b", number_of_moves, outcome);
    //         for (int i =0; i <7; i++){
    //             for (int j=0; j < 7; j++){
    //                 cout <<matrix_of_congo[i][j]<<" ";
    //             }
    //             cout <<endl;
    //         }
    //     }
    // }

    // else if (element =="b")
    // {
    //     string outcome;
    //     if (matrix_of_congo[rank2][second_file] == "L"){
    //         outcome ="Black wins";
    //         swap(matrix_of_congo[rank2][second_file], matrix_of_congo[rank1][first_file]);
    //         matrix_of_congo[rank1][first_file] ="0";

    //         // convertToFen(matrix_of_congo, "w", number_of_moves + 1, outcome);

    //         for (int i =0; i <7; i++){
    //             for (int j=0; j < 7; j++){
    //                 cout <<matrix_of_congo[i][j]<<" ";
    //             }
    //             cout <<endl;
    //         }
    //     }
    //     else {

    //         if (emptyOrOppPeiceForBlack(matrix_of_congo, rank2, second_file) ==true){
    //             swap(matrix_of_congo[rank2][second_file], matrix_of_congo[rank1][first_file]);
    //             matrix_of_congo[rank1][first_file] ="0";
    //         }
    //         outcome ="Continue";
    //         // convertToFen(matrix_of_congo, "w", number_of_moves + 1, outcome);

    //         for (int i =0; i <7; i++){
    //             for (int j=0; j < 7; j++){
    //                 cout <<matrix_of_congo[i][j]<<" ";
    //             }
    //             cout <<endl;
    //         }
    //     }

    // }  
}

void formCongoBoard(string game_space, string the_move)
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

    
    LionMoves(matrix_of_congo, the_move);
    
}

void storeFens(vector<string> fensAndMoves)
{
    for (int i=0; i < fensAndMoves.size(); i++)
    {
        vector<string> arr =tokenize(fensAndMoves[2*i], " ");
        string the_move =fensAndMoves[2*i+1];
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
        formCongoBoard(game_space, the_move);
        
    }
    
}
int main()
{
    int N;
    cin>>N;
    cin.ignore();
    vector<string> fensAndMoves;
    int newInput =2*N;
    for (int i =0; i < newInput; i++)
    {
        string FEN;
        getline(cin ,FEN);
        fensAndMoves.push_back(FEN);
    }

    storeFens(fensAndMoves);
return 0;
}


// 3
// 2ele1z/ppppppp/7/7/7/PPP1PPP/2ELE1Z w 4
// d1d2
// 1z5/pPp1lP1/5ep/4P1e/4L1p/2p2pP/7 b 35
// f5f7
// 1z5/pPp1lP1/5ep/4P1e/4L1p/2p2pP/7 b 12
// g4e4
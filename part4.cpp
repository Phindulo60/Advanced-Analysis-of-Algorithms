#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<sstream>
#include <string>
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

bool checkVerticalPiece(vector< vector<string>> matrix_of_congo, int xl, int yl, int xL, int yL)
{   
    bool clearPath =true;

    stringstream ss;
    string element;
    ss << side_to_move;
    ss >> element;
    if (element =="w"){
        for (int i=xL; i > xl + 1; i--){
            if (matrix_of_congo[i-1][yl] !="0")
            {
                clearPath =false;
            }
        }
    }
    else if (element =="b") {
        for (int i =xl+1; i < xL; i++){
            if (matrix_of_congo[i][yl] !="0"){
                clearPath =false;
            }
        }
    }
    return clearPath;
}

bool checkDiagonalPiece(vector< vector<string>> matrix_of_congo, int xl, int yl, int xL, int yL)
{
    bool clearPath =false;

    stringstream ss;
    string element;
    ss << side_to_move;
    ss >> element;

    if (element =="w"){
        if (xL-2 ==xl && yL+2 ==yl && matrix_of_congo[xL-1][yL+1] =="0"){
            clearPath =true;
        }
        if(xL-2 ==xl && yL-2 ==yl && matrix_of_congo[xL-1][yL-1] =="0"){
            clearPath =true;    
        }
    }
    else if(element =="b") {
        if (xl+2 ==xL && yl+2 ==yL && matrix_of_congo[xl+1][yl+1] =="0"){
            clearPath =true;
        }
        if (xl+2 ==xL && yl-2 ==yL && matrix_of_congo[xl+1][yl-1] =="0"){
            clearPath =true;
        }
    }

    return clearPath;

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

void clearForwhite(vector<vector<string>> &matrix_of_congo){
    
    for (int i =0; i < 7; i++){
        string pos =matrix_of_congo[3][i];
        char opposition =pos[0];
        if ( opposition >=65 && opposition <=90)
        {
            matrix_of_congo[3][i] ="0";
        }
    }
}

void clearForBlack(vector<vector<string>> &matrix_of_congo)
{
    for (int i=0; i < 7; i++){
        string pos =matrix_of_congo[3][i];
        char opposition =pos[0];
        if (opposition >=97 && opposition <=122)
        {
            matrix_of_congo[3][i] ="0";
        }
    }
}

void ZebraMoves(vector< vector<string>> matrix_of_congo, vector<string> &moves)
{
    if (side_to_move =='w')
    {
        for( int i = 0; i < 7; i++){
            for(int j = 0; j < 7; j++){
                if( matrix_of_congo[i][j] =="Z" ){
                    if(((j+1) < 7) && ((i-2) >= 0)){
                        if( matrix_of_congo[i-2][j+1] == "0"||matrix_of_congo[i-2][j+1] == "e"|| matrix_of_congo[i-2][j+1] == "p"||matrix_of_congo[i-2][j+1] == "l"||matrix_of_congo[i-2][j+1] == "z"){
                            string col8 = files[j+1];
                        string col9 = files[j];
                            string new_pos6 = (col9 + to_string(7 - i));
                            string new_pos7 = (col8 + to_string(7 - (i-2)));
                            moves.push_back(new_pos6 + new_pos7);
                        }
                    }
                    if(((j-2) >= 0) && ((i-1) >= 0)){
                        if(matrix_of_congo[i-1][j-2] == "0"||matrix_of_congo[i-1][j-2] == "e"|| matrix_of_congo[i-1][j-2] == "p"||matrix_of_congo[i-1][j-2] == "l"||matrix_of_congo[i-1][j-2] == "z"){
                                string col8 = files[j-2];
                        string col9 = files[j];
                            string new_pos6 = (col9 + to_string(7 - i));
                            string new_pos7 = (col8 + to_string(7 - (i-1)));
                            moves.push_back(new_pos6 + new_pos7);
                        }
                    }
                    
                    if(((i-2) >= 0) && ((j-1) >= 0)){
                        if(matrix_of_congo[i-2][j-1] == "0"||matrix_of_congo[i-2][j-1] == "e"|| matrix_of_congo[i-2][j-1] == "p"||matrix_of_congo[i-2][j-1] == "l"||matrix_of_congo[i-2][j-1] == "z"){
                            string col8 = files[j-1];
                        string col9 = files[j];
                            string new_pos6 = (col9 + to_string(7 - i));
                            string new_pos7 = (col8 + to_string(7 - (i-2)));
                            moves.push_back(new_pos6 + new_pos7);
                        }
                    }
                    if(((i+2) < 7) && ((j-1) >= 0)){
                        if(matrix_of_congo[i+2][j-1] == "0"||matrix_of_congo[i+2][j-1] == "e"|| matrix_of_congo[i+2][j-1] == "p"||matrix_of_congo[i+2][j-1] == "l"||matrix_of_congo[i+2][j-1] == "z"){
                            string col8 = files[j-1];
                        string col9 = files[j];
                            string new_pos6 = (col9 + to_string(7 - i));
                            string new_pos7 = (col8 + to_string(7 - (i+2)));
                            moves.push_back(new_pos6 + new_pos7);
                        }
                    }
                    if(((i+1) < 7) && ((j-2) >= 0)){
                        if(matrix_of_congo[i+1][j-2] == "0"||matrix_of_congo[i+1][j-2] == "e"|| matrix_of_congo[i+1][j-2] == "p"||matrix_of_congo[i+1][j-2] == "l"||matrix_of_congo[i+1][j-2] == "z" ){
                        string col8 = files[j-2];
                        string col9 = files[j];
                            string new_pos6 = (col9 + to_string(7 - i));
                            string new_pos7 = (col8 + to_string(7 - (i+1)));
                            moves.push_back(new_pos6 + new_pos7);
                        
                        }
                    }
                    if(((i+1) < 7) && ((j+2) < 7) ){
                        if(matrix_of_congo[i+1][j+2] == "0"||matrix_of_congo[i+1][j+2] == "e"|| matrix_of_congo[i+1][j+2] == "p"||matrix_of_congo[i+1][j+2] == "l"||matrix_of_congo[i+1][j+2] == "z"){
                            string col8 = files[j+2];
                        string col9 = files[j];
                            string new_pos6 = (col9 + to_string(7 - i));
                            string new_pos7 = (col8 + to_string(7 - (i+1)));
                            moves.push_back(new_pos6 + new_pos7);
                        }
                    }
                    if(((j+1) < 7) && ((i+2) < 7)){
                        if( matrix_of_congo[i+2][j+1] == "0" || matrix_of_congo[i+2][j+1] == "e"|| matrix_of_congo[i+2][j+1] == "p"||matrix_of_congo[i+2][j+1] == "l"||matrix_of_congo[i+2][j+1] == "z"){
                            string col8 = files[j+1];
                        string col9 = files[j];
                            string new_pos6 = (col9 + to_string(7 - i));
                            string new_pos7 = (col8 + to_string(7 - (i+2)));
                            moves.push_back(new_pos6 + new_pos7);
                        }
                    }
                    if((j+2) < 7 && (i-1) >= 0){
                        if(matrix_of_congo[i-1][j+2] == "0"||matrix_of_congo[i-1][j+2] == "e"|| matrix_of_congo[i-1][j+2] == "p"||matrix_of_congo[i-1][j+2] == "l"||matrix_of_congo[i-1][j+2] == "z" ){
                            string col8 = files[j+2];
                        string col9 = files[j];
                            string new_pos6 = (col9 + to_string(7 - i));
                            string new_pos7 = (col8 + to_string(7 - (i-1)));
                            moves.push_back(new_pos6 + new_pos7);
                        }
                    }
                }
            }
        }
    }
    else if (side_to_move =='b')
    {
        for( int i = 0; i < 7; i++){
    	    for(int j = 0; j < 7; j++){
    		    if( matrix_of_congo[i][j] == "z" ){
    			    if(((j+1) < 7) && ((i-2) >= 0)){
	    		        if( matrix_of_congo[i-2][j+1] == "0"||matrix_of_congo[i-2][j+1] == "E"|| matrix_of_congo[i-2][j+1] == "P"||matrix_of_congo[i-2][j+1] == "L"||matrix_of_congo[i-2][j+1] == "Z"){
	    		            string col8 = files[j+1];
	    			        string col9 = files[j];
		                    string new_pos6 = (col9 + to_string(7 - i));
		                    string new_pos7 = (col8 + to_string(7 - (i-2)));
		                    moves.push_back(new_pos6 + new_pos7);
	    		        }
    		        }
    		        if(((j-2) >= 0) && ((i-1) >= 0)){
    		      	    if(matrix_of_congo[i-1][j-2] == "0"||matrix_of_congo[i-1][j-2] == "E"|| matrix_of_congo[i-1][j-2] == "P"||matrix_of_congo[i-1][j-2] == "L"||matrix_of_congo[i-1][j-2] == "Z"){
    		      	    	string col8 = files[j-2];
	    			        string col9 = files[j];
		                    string new_pos6 = (col9 + to_string(7 - i));
		                    string new_pos7 = (col8 + to_string(7 - (i-1)));
		                    moves.push_back(new_pos6 + new_pos7);
    		      	    }
    		        }
    		      
    		        if(((i-2) >= 0) && ((j-1) >= 0)){
    		     		if(matrix_of_congo[i-2][j-1] == "0"||matrix_of_congo[i-2][j-1] == "E"|| matrix_of_congo[i-2][j-1] == "P"||matrix_of_congo[i-2][j-1] == "L"||matrix_of_congo[i-2][j-1] == "Z"){
    		     		    string col8 = files[j-1];
	    			        string col9 = files[j];
		                    string new_pos6 = (col9 + to_string(7 - i));
		                    string new_pos7 = (col8 + to_string(7 - (i-2)));
		                    moves.push_back(new_pos6 + new_pos7);
    		     		}
    		        }
    		        if(((i+2) < 7) && ((j-1) >= 0)){
    		     		if(matrix_of_congo[i+2][j-1] == "0"||matrix_of_congo[i+2][j-1] == "E"|| matrix_of_congo[i+2][j-1] == "P"||matrix_of_congo[i+2][j-1] == "L"||matrix_of_congo[i+2][j-1] == "Z"){
    		     		    string col8 = files[j-1];
	    			        string col9 = files[j];
		                    string new_pos6 = (col9 + to_string(7 - i));
		                    string new_pos7 = (col8 + to_string(7 - (i+2)));
		                    moves.push_back(new_pos6 + new_pos7);
    		     		}
    		        }
    		        if(((i+1) < 7) && ((j-2) >= 0)){
    		     		if(matrix_of_congo[i+1][j-2] == "0"||matrix_of_congo[i+1][j-2] == "E"|| matrix_of_congo[i+1][j-2] == "P"||matrix_of_congo[i+1][j-2] == "L"||matrix_of_congo[i+1][j-2] == "Z" ){
    		   			    string col8 = files[j-2];
	    			        string col9 = files[j];
		                    string new_pos6 = (col9 + to_string(7 - i));
		                    string new_pos7 = (col8 + to_string(7 - (i+1)));
		                    moves.push_back(new_pos6 + new_pos7);
    		     		
    		     		}
    		        }
    		        if(((i+1) < 7) && ((j+2) < 7) ){
    		     		if(matrix_of_congo[i+1][j+2] == "0"||matrix_of_congo[i+1][j+2] == "E"|| matrix_of_congo[i+1][j+2] == "P"||matrix_of_congo[i+1][j+2] == "L"||matrix_of_congo[i+1][j+2] == "Z"){
    		     		    string col8 = files[j+2];
	    			        string col9 = files[j];
		                    string new_pos6 = (col9 + to_string(7 - i));
		                    string new_pos7 = (col8 + to_string(7 - (i+1)));
		                    moves.push_back(new_pos6 + new_pos7);
    		     		}
    		        }
    		        if(((j+1) < 7) && ((i+2) < 7)){
    		     		if( matrix_of_congo[i+2][j+1] == "0"||matrix_of_congo[i+2][j+1] == "E"|| matrix_of_congo[i+2][j+1] == "P"||matrix_of_congo[i+2][j+1] == "l"||matrix_of_congo[i+2][j+1] == "Z"){
    		     		    string col8 = files[j+1];
	    			        string col9 = files[j];
		                    string new_pos6 = (col9 + to_string(7 - i));
		                    string new_pos7 = (col8 + to_string(7 - (i+2)));
		                    moves.push_back(new_pos6 + new_pos7);
    		     		}
    		        }
    		        if((j+2) < 7 && (i-1) >= 0){
    		     		if(matrix_of_congo[i-1][j+2] == "0"||matrix_of_congo[i-1][j+2] == "E"|| matrix_of_congo[i-1][j+2] == "P"||matrix_of_congo[i-1][j+2] == "L"||matrix_of_congo[i-1][j+2] == "Z" ){
    		     		    string col8 = files[j+2];
	    			        string col9 = files[j];
		                    string new_pos6 = (col9 + to_string(7 - i));
		                    string new_pos7 = (col8 + to_string(7 - (i-1)));
		                    moves.push_back(new_pos6 + new_pos7);
    		     	    }
    		        }
    		    }
    	    }
        }
    }
}

void ElephantMoves(vector< vector<string>> matrix_of_congo, vector<string> &moves)
{
    if ( side_to_move =='w')
    {
        for( int i = 0; i < 7; i++){
            for(int j = 0; j < 7; j++){
                int count = 0;
                if( matrix_of_congo[i][j] =="E" ){
                    if((j-2) < 7 && (j-2) >= 0){
                        if( matrix_of_congo[i][j-2] == "0" || matrix_of_congo[i][j-2] == "e" || matrix_of_congo[i][j-2] == "l" || matrix_of_congo[i][j-2] == "z" || matrix_of_congo[i][j-2] == "p"){
                        string col8 = files[j-2];
                        string col9 = files[j];
                        string new_pos6 = (col9 + to_string(7 - i));
                        string new_pos7 = (col8 + to_string(7 - i));
                        moves.push_back(new_pos6 + new_pos7);
                        }
                    }
                    if((j-1) < 7 && (j-1) >= 0){
                        if( matrix_of_congo[i][j-1] == "0" || matrix_of_congo[i][j-1] == "e" || matrix_of_congo[i][j-1] == "l" || matrix_of_congo[i][j-1] == "z" || matrix_of_congo[i][j-1] == "p"){
                            string col6 = files[j-1];
                            string col7 = files[j];
                            string new_pos4 = (col7 + to_string(7 - i));
                            string new_pos5 = (col6 + to_string(7 - i));
                            moves.push_back(new_pos4 + new_pos5);
                        }
                    }
                    if((i+1) < 7 && (i+1) >= 0){
                        if( matrix_of_congo[i+1][j] == "0" || matrix_of_congo[i+1][j] == "e" || matrix_of_congo[i+1][j] == "l" || matrix_of_congo[i+1][j] == "z" || matrix_of_congo[i+1][j] == "p"){
                            string col7 = files[j];
                            string new_pos4 = (col7 + to_string(7 - i));
                            string new_pos5 = (col7 + to_string(7 - (i+1)));
                            moves.push_back(new_pos4 + new_pos5);
                        }
                    }	
                    if((i+2) < 7 && (i+2) >= 0){
                        if( matrix_of_congo[i+2][j] == "0" || matrix_of_congo[i+2][j] == "e" || matrix_of_congo[i+2][j] == "l" || matrix_of_congo[i+2][j] == "z" || matrix_of_congo[i+2][j] == "p"){
                            string col7 = files[j];
                            string new_pos4 = (col7 + to_string(7 - i));
                            string new_pos5 = (col7 + to_string(7 - (i+2)));
                            moves.push_back(new_pos4 + new_pos5);
                        }
                    }
                    if((j+2) < 7 && (j+2) >= 0){
                        if( matrix_of_congo[i][j+2] == "0" || matrix_of_congo[i][j+2] == "e" || matrix_of_congo[i][j+2] == "l" || matrix_of_congo[i][j+2] == "z" || matrix_of_congo[i][j+2] == "p"){
                            string col1 = files[j+2];
                            string col2 = files[j];
                            string new_pos = (col2 + to_string(7 - i));
                            string new_pos1 = (col1 + to_string(7 - i));
                            moves.push_back(new_pos + new_pos1);
                        }
                    }
                    if((j+1) < 7 && (j+1) >= 0){
                        if( matrix_of_congo[i][j+1] == "0" || matrix_of_congo[i][j+1] == "e" || matrix_of_congo[i][j+1] == "l" || matrix_of_congo[i][j+1] == "z" || matrix_of_congo[i][j+1] == "p"){
                            string col3 = files[j+1];
                            string col4 = files[j];
                            string new_pos2 = (col4 + to_string(7 - i));
                            string new_pos3 = (col3 + to_string(7 - i));
                            moves.push_back(new_pos2 + new_pos3);
                        }
                    }
                    if((i-1) < 7 && (i-1) >= 0){
                        if( matrix_of_congo[i-1][j] == "0" || matrix_of_congo[i-1][j] == "e" || matrix_of_congo[i-1][j] == "l" || matrix_of_congo[i-1][j] == "z" || matrix_of_congo[i-1][j] == "p"){
                            string col7 = files[j];
                            string new_pos4 = (col7 + to_string(7 - i));
                            string new_pos5 = (col7 + to_string(7 - (i-1)));
                            moves.push_back(new_pos4 + new_pos5);
                        }
                    }
                    if((i-2) < 7 && (i-2) >= 0){
                        if( matrix_of_congo[i-2][j] == "0" || matrix_of_congo[i-2][j] == "e" || matrix_of_congo[i-2][j] == "l" || matrix_of_congo[i-2][j] == "z" || matrix_of_congo[i-2][j] == "p"){
                            string col7 = files[j];
                            string new_pos4 = (col7 + to_string(7 - i));
                            string new_pos5 = (col7 + to_string(7 - (i-2)));
                            string new_ela = new_pos4 + new_pos5;
                            moves.push_back(new_ela);        
                        }
                    }		
                        
                }
            
            }
        }
    }
    else if (side_to_move =='b')
    {
        for( int i = 0; i < 7; i++){
    	    for(int j = 0; j < 7; j++){
    		    if( matrix_of_congo[i][j] =="e" ){
    			    if((j-2) < 7 && (j-2) >= 0){
	    		        if( matrix_of_congo[i][j-2] == "0"|| matrix_of_congo[i][j-2] == "E"|| matrix_of_congo[i][j-2] == "L"||matrix_of_congo[i][j-2] == "P"||matrix_of_congo[i][j-2] == "Z"){
                            string col8 = files[j-2];
                            string col9 = files[j];
                            string new_pos6 = (col9 + to_string(7 - i));
                            string new_pos7 = (col8 + to_string(7 - i));
                            moves.push_back(new_pos6 + new_pos7);
	    			    }
    			    }
    				if((j-1) < 7 && (j-1) >= 0){
		    		    if( matrix_of_congo[i][j-1] == "0"||matrix_of_congo[i][j-1] == "E"||matrix_of_congo[i][j-1] == "L"||matrix_of_congo[i][j-1] == "P"||matrix_of_congo[i][j-1] == "Z"){
		    			   string col6 = files[j-1];
		    			   string col7 = files[j];
				           string new_pos4 = (col7 + to_string(7 - i));
				           string new_pos5 = (col6 + to_string(7 - i));
				           moves.push_back(new_pos4 + new_pos5);
		    			}
    				}
                    if((i+1) < 7 && (i+1) >= 0){
                        if( matrix_of_congo[i+1][j] == "0"||matrix_of_congo[i+1][j] == "E"|| matrix_of_congo[i+1][j] == "L"|| matrix_of_congo[i+1][j] == "P"|| matrix_of_congo[i+1][j] == "Z"){
                            string col7 = files[j];
                            string new_pos4 = (col7 + to_string(7 - i));
                            string new_pos5 = (col7 + to_string(7 - (i+1)));
                            moves.push_back(new_pos4 + new_pos5);
                        }
                    }	
                    if((i+2) < 7 && (i+2) >= 0){
                        if( matrix_of_congo[i+2][j] == "0"|| matrix_of_congo[i+2][j] == "E"|| matrix_of_congo[i+2][j] == "L"|| matrix_of_congo[i+2][j] == "P"|| matrix_of_congo[i+2][j] == "Z"){
                            string col7 = files[j];
                            string new_pos4 = (col7 + to_string(7 - i));
                            string new_pos5 = (col7 + to_string(7 - (i+2)));
                            moves.push_back(new_pos4 + new_pos5);
                        }
                    }
                    if((j+2) < 7 && (j+2) >= 0){
                        if( matrix_of_congo[i][j+2] == "0"|| matrix_of_congo[i][j+2] == "E"|| matrix_of_congo[i][j+2] == "L"|| matrix_of_congo[i][j+2] == "P"|| matrix_of_congo[i][j+2] == "Z"){
                            string col1 = files[j+2];
                            string col2 = files[j];
                            string new_pos = (col2 + to_string(7 - i));
                            string new_pos1 = (col1 + to_string(7 - i));
                            moves.push_back(new_pos + new_pos1);
                        }
                    }
                    if((j+1) < 7 && (j+1) >= 0){
                        if( matrix_of_congo[i][j+1] == "0"|| matrix_of_congo[i][j+1] == "E"|| matrix_of_congo[i][j+1] == "L"|| matrix_of_congo[i][j+1] == "P"|| matrix_of_congo[i][j+1] == "Z"){
                            string col3 = files[j+1];
                            string col4 = files[j];
                            string new_pos2 = (col4 + to_string(7 - i));
                            string new_pos3 = (col3 + to_string(7 - i));
                            moves.push_back(new_pos2 + new_pos3);
                        }
                    }
                    if((i-1) < 7 && (i-1) >= 0){
                        if( matrix_of_congo[i-1][j] == "0"|| matrix_of_congo[i-1][j] == "E"|| matrix_of_congo[i-1][j] == "L"|| matrix_of_congo[i-1][j] == "P"|| matrix_of_congo[i-1][j] == "Z"){
                            string col7 = files[j];
                            string new_pos4 = (col7 + to_string(7 - i));
                            string new_pos5 = (col7 + to_string(7 - (i-1)));
                            moves.push_back(new_pos4 + new_pos5);
                        }
                    }
                    if((i-2) < 7 && (i-2) >= 0){
                        if( matrix_of_congo[i-2][j] == "0"|| matrix_of_congo[i-2][j] == "E"|| matrix_of_congo[i-2][j] == "L"|| matrix_of_congo[i-2][j] == "P"|| matrix_of_congo[i-2][j] == "Z"){
                            string col7 = files[j];
                            string new_pos4 = (col7 + to_string(7 - i));
                            string new_pos5 = (col7 + to_string(7 - (i-2)));
                            moves.push_back(new_pos4 + new_pos5);
                        }
                    }			
                }
    	    }
        }
    }
}

void PawnMoves(vector< vector<string>> matrix_of_congo, vector<string> &moves)
{
    if (side_to_move =='w')
    {
        for( int i = 0; i < 7; i++){
            for(int j = 0; j < 7; j++){
                if( matrix_of_congo[i][j] =="P" ){
            
                    if(i > 3 ){
                        if( ((j-1) >= 0)){
                            if( matrix_of_congo[i-1][j-1] == "0"||matrix_of_congo[i-1][j-1] == "e"|| matrix_of_congo[i-1][j-1] == "p"||matrix_of_congo[i-1][j-1] == "l"||matrix_of_congo[i-1][j-1] == "z"){
                                string col8 = files[j-1];
                                string col9 = files[j];
                                string new_pos6 = (col9 + to_string(7 - i));
                                string new_pos7 = (col8 + to_string(7 - (i-1)));
                                moves.push_back(new_pos6 + new_pos7);
                            }
                        }
                        if( matrix_of_congo[i-1][j] == "0"||matrix_of_congo[i-1][j] == "e"|| matrix_of_congo[i-1][j] == "p"||matrix_of_congo[i-1][j] == "l"||matrix_of_congo[i-1][j] == "z"){
                            string col8 = files[j];
                            string col9 = files[j];
                            string new_pos6 = (col9 + to_string(7 - i));
                            string new_pos7 = (col8 + to_string(7 - (i-1)));
                            moves.push_back(new_pos6 + new_pos7);
                        }
                        if((j+1) < 7){
                            if( matrix_of_congo[i-1][j+1] == "0"||matrix_of_congo[i-1][j+1] == "e"|| matrix_of_congo[i-1][j+1] == "p"||matrix_of_congo[i-1][j+1] == "l"||matrix_of_congo[i-1][j+1] == "z"){
                                string col8 = files[j+1];
                                string col9 = files[j];
                                string new_pos6 = (col9 + to_string(7 - i));
                                string new_pos7 = (col8 + to_string(7 - (i-1)));
                                moves.push_back(new_pos6 + new_pos7);
                            }
                        }
                    }
                    if(i == 3){
                        if((j-1) >=0 ){
                            if( matrix_of_congo[i-1][j-1] == "0"||matrix_of_congo[i-1][j-1] == "e"|| matrix_of_congo[i-1][j-1] == "p"||matrix_of_congo[i-1][j-1] == "l"||matrix_of_congo[i-1][j-1] == "z"){
                                string col8 = files[j-1];
                                string col9 = files[j];
                                string new_pos6 = (col9 + to_string(7 - i));
                                string new_pos7 = (col8 + to_string(7 - (i-1)));
                                moves.push_back(new_pos6 + new_pos7);
                            }
                        }
                        if( matrix_of_congo[i-1][j] == "0"||matrix_of_congo[i-1][j] == "e"|| matrix_of_congo[i-1][j] == "p"||matrix_of_congo[i-1][j] == "l"||matrix_of_congo[i-1][j] == "z"){
                            string col8 = files[j];
                            string col9 = files[j];
                            string new_pos6 = (col9 + to_string(7 - i));
                            string new_pos7 = (col8 + to_string(7 - (i-1)));
                            moves.push_back(new_pos6 + new_pos7);
                        }
                        if((j+1) < 7){
                            if( matrix_of_congo[i-1][j+1] == "0"||matrix_of_congo[i-1][j+1] == "e"|| matrix_of_congo[i-1][j+1] == "p"||matrix_of_congo[i-1][j+1] == "l"||matrix_of_congo[i-1][j+1] == "z"){
                                string col8 = files[j+1];
                                string col9 = files[j];
                                string new_pos6 = (col9 + to_string(7 - i));
                                string new_pos7 = (col8 + to_string(7 - (i-1)));
                                moves.push_back(new_pos6 + new_pos7);
                            }
                        }
                        
                    }
                    if( i < 3){
                        if( ((j-1) >= 0)&&( (i-1)>=0)){
                            if( matrix_of_congo[i-1][j-1] == "0"||matrix_of_congo[i-1][j-1] == "e"|| matrix_of_congo[i-1][j-1] == "p"||matrix_of_congo[i-1][j-1] == "l"||matrix_of_congo[i-1][j-1] == "z"){
                                string col8 = files[j-1];
                                string col9 = files[j];
                                string new_pos6 = (col9 + to_string(7 - i));
                                string new_pos7 = (col8 + to_string(7 - (i-1)));
                                moves.push_back(new_pos6 + new_pos7);
                            }
                        }
                        if( matrix_of_congo[i-1][j] == "0"||matrix_of_congo[i-1][j] == "e"|| matrix_of_congo[i-1][j] == "p"||matrix_of_congo[i-1][j] == "l"||matrix_of_congo[i-1][j] == "z"){
                            string col8 = files[j];
                            string col9 = files[j];
                            string new_pos6 = (col9 + to_string(7 - i));
                            string new_pos7 = (col8 + to_string(7 - (i-1)));
                            moves.push_back(new_pos6 + new_pos7);
                        }
                        if((j+1) < 7){
                            if( matrix_of_congo[i-1][j+1] == "0"||matrix_of_congo[i-1][j+1] == "e"|| matrix_of_congo[i-1][j+1] == "p"||matrix_of_congo[i-1][j+1] == "l"||matrix_of_congo[i-1][j+1] == "z"){
                                string col8 = files[j+1];
                                string col9 = files[j];
                                string new_pos6 = (col9 + to_string(7 - i));
                                string new_pos7 = (col8 + to_string(7 - (i-1)));
                                moves.push_back(new_pos6 + new_pos7);
                            }
                        }
                        if( matrix_of_congo[i+1][j] == "0"){
                                string col8 = files[j];
                                string col9 = files[j];
                                string new_pos6 = (col9 + to_string(7 - i));
                                string new_pos7 = (col8 + to_string(7 - (i+1)));
                                moves.push_back(new_pos6 + new_pos7);
                        }
                        if( matrix_of_congo[i+1][j] == "0"){
                            if( matrix_of_congo[i+2][j] == "0"){
                                string col8 = files[j];
                                string col9 = files[j];
                                string new_pos6 = (col9 + to_string(7 - i));
                                string new_pos7 = (col8 + to_string(7 - (i+2)));
                                moves.push_back(new_pos6 + new_pos7);
                            }
                        }
                    }		      
                }	
            }
        }
    }
    else if (side_to_move =='b')
    {
        for( int i = 0; i < 7; i++){
    	    for(int j = 0; j < 7; j++){
    		    if( matrix_of_congo[i][j] =="p" ){
    			    if( i < 3){
    				    if(((i+1) < 7) && ((j-1) >= 0)){
					        if( matrix_of_congo[i+1][j-1] == "0"||matrix_of_congo[i+1][j-1] == "E"|| matrix_of_congo[i+1][j-1] == "P"||matrix_of_congo[i+1][j-1] == "L"||matrix_of_congo[i+1][j-1] == "Z"){
					            string col8 = files[j-1];
                                string col9 = files[j];
                                string new_pos6 = (col9 + to_string(7 - i));
                                string new_pos7 = (col8 + to_string(7 - (i+1)));
                                moves.push_back(new_pos6 + new_pos7);
					        }
					    }
					    if((i+1) < 7 ){
					        if( matrix_of_congo[i+1][j] == "0"||matrix_of_congo[i+1][j] == "E"|| matrix_of_congo[i+1][j] == "P"||matrix_of_congo[i+1][j] == "L"||matrix_of_congo[i+1][j] == "Z"){
                                string col8 = files[j];
                                string col9 = files[j];
                                string new_pos6 = (col9 + to_string(7 - i));
                                string new_pos7 = (col8 + to_string(7 - (i+1)));
                                moves.push_back(new_pos6 + new_pos7);
					        }
					    }
					    if(((i+1) < 7) && ((j+1) < 7)){
                            if( matrix_of_congo[i+1][j+1] == "0"||matrix_of_congo[i+1][j+1] == "E"|| matrix_of_congo[i+1][j+1] == "P"||matrix_of_congo[i+1][j+1] == "L"||matrix_of_congo[i+1][j+1] == "Z"){
                                string col8 = files[j+1];
                                string col9 = files[j];
                                string new_pos6 = (col9 + to_string(7 - i));
                                string new_pos7 = (col8 + to_string(7 - (i+1)));
                                moves.push_back(new_pos6 + new_pos7);
                            }
					    }	          
    		        }
    		        if(i == 3){
    		      		if( matrix_of_congo[i+1][j] == "0"||matrix_of_congo[i+1][j] == "E"|| matrix_of_congo[i+1][j] == "P"||matrix_of_congo[i+1][j] == "L"||matrix_of_congo[i+1][j] == "Z"){
                            string col8 = files[j];
                            string col9 = files[j];
                            string new_pos6 = (col9 + to_string(7 - i));
                            string new_pos7 = (col8 + to_string(7 - (i+1)));
                            moves.push_back(new_pos6 + new_pos7);
					    }
					    if((j+1) < 7){
							if( matrix_of_congo[i+1][j+1] == "0"||matrix_of_congo[i+1][j+1] == "E"|| matrix_of_congo[i+1][j+1] == "P"||matrix_of_congo[i+1][j+1] == "L"||matrix_of_congo[i+1][j+1] == "Z"){
                                string col8 = files[j+1];
                                string col9 = files[j];
                                string new_pos6 = (col9 + to_string(7 - i));
                                string new_pos7 = (col8 + to_string(7 - (i+1)));
                                moves.push_back(new_pos6 + new_pos7);
							}
					    }
					    if((j-1) >= 0){
							if( matrix_of_congo[i+1][j-1] == "0"||matrix_of_congo[i+1][j-1] == "E"|| matrix_of_congo[i+1][j-1] == "P"||matrix_of_congo[i+1][j-1] == "L"||matrix_of_congo[i+1][j-1] == "Z"){
                                string col8 = files[j-1];
                                string col9 = files[j];
                                string new_pos6 = (col9 + to_string(7 - i));
                                string new_pos7 = (col8 + to_string(7 - (i+1)));
                                moves.push_back(new_pos6 + new_pos7);
							}
					    }
    		        }
    		        if( i > 3){
    		      	    if(((i+1) < 7) && ((j+1) < 7)){
					        if( matrix_of_congo[i+1][j+1] == "0"||matrix_of_congo[i+1][j+1] == "E"|| matrix_of_congo[i+1][j+1] == "P"||matrix_of_congo[i+1][j+1] == "L"||matrix_of_congo[i+1][j+1] == "Z"){
                                string col8 = files[j+1];
                                string col9 = files[j];
                                string new_pos6 = (col9 + to_string(7 - i));
                                string new_pos7 = (col8 + to_string(7 - (i+1)));
                                moves.push_back(new_pos6 + new_pos7);
					        }
					    }
					    if(((i+1) < 7) && ((j-1) >= 0)){
					        if( matrix_of_congo[i+1][j-1] == "0"||matrix_of_congo[i+1][j-1] == "E"|| matrix_of_congo[i+1][j-1] == "P"||matrix_of_congo[i+1][j-1] == "L"||matrix_of_congo[i+1][j-1] == "Z"){
                                string col8 = files[j-1];
                                string col9 = files[j];
                                string new_pos6 = (col9 + to_string(7 - i));
                                string new_pos7 = (col8 + to_string(7 - (i+1)));
                                moves.push_back(new_pos6 + new_pos7);
					        }
					    }
					    if((i+1) < 7 ){
					        if( matrix_of_congo[i+1][j] == "0"||matrix_of_congo[i+1][j] == "E"|| matrix_of_congo[i+1][j] == "P"||matrix_of_congo[i+1][j] == "L"||matrix_of_congo[i+1][j] == "Z"){
                                string col8 = files[j];
                                string col9 = files[j];
                                string new_pos6 = (col9 + to_string(7 - i));
                                string new_pos7 = (col8 + to_string(7 - (i+1)));
                                moves.push_back(new_pos6 + new_pos7);
					        }
					    }
					    if( matrix_of_congo[i-1][j] == "0"){
                            string col8 = files[j];
                            string col9 = files[j];
                            string new_pos6 = (col9 + to_string(7 - i));
                            string new_pos7 = (col8 + to_string(7 - (i-1)));
                            moves.push_back(new_pos6 + new_pos7);
					    }
					    if( matrix_of_congo[i-1][j] == "0"){
						    if( matrix_of_congo[i-2][j] == "0"){
                                string col8 = files[j];
                                string col9 = files[j];
                                string new_pos6 = (col9 + to_string(7 - i));
                                string new_pos7 = (col8 + to_string(7 - (i-2)));
                                moves.push_back(new_pos6 + new_pos7);
							}
				        }
    		        }
                }
            }
        }
    }
}

void getTheNeiboringPieces(vector< vector<string> > matrix_of_congo ,vector<string> &moves, int xl, int yl,int xL,int yL, string element){
    
    if (element =="w"){
        string file =files[yL];
        if ((xL - 1) >= 4 && emptyOrOppPeiceForWhite(matrix_of_congo, xL - 1, yL) ==true) {
        string uppermove =files[yL];
        int newPos =xL - 1;
        moves.push_back(file + to_string(7 - xL) + uppermove + to_string(7 - newPos));
        }
        if ((xL + 1) <=6 && emptyOrOppPeiceForWhite(matrix_of_congo, xL + 1, yL) == true){

            string lowerMove =files[yL];
            int newPos =xL + 1;
            moves.push_back(file + to_string(7 - xL) + lowerMove + to_string(7 - newPos));
        }
        if ( (yL - 1) >=2 && emptyOrOppPeiceForWhite(matrix_of_congo, xL, yL- 1) == true ){
            
            string leftMove =files[yL - 1];
            moves.push_back(file + to_string(7 - xL) + leftMove + to_string(7 - xL));
        }
        if ((yL + 1) <= 4 && emptyOrOppPeiceForWhite(matrix_of_congo, xL, yL + 1) == true){
            
            string rightMove =files[yL + 1];
            moves.push_back(file + to_string(7 - xL) + rightMove + to_string(7 - xL));
        }

        if ( (xL - 1) >=4 && (yL - 1) >=2 && emptyOrOppPeiceForWhite(matrix_of_congo, xL-1, yL-1) == true){
            string leftUpperDiaMove =files[yL -1];
            int newPos =xL - 1;
            moves.push_back(file + to_string(7 - xL) + leftUpperDiaMove + to_string(7 - newPos));
        }

        if ((xL+1) <=6 && (yL-1)>=2 && emptyOrOppPeiceForWhite(matrix_of_congo, xL+1, yL-1) == true){
            string leftLowerDiaMove =files[yL-1];
            int newPos =xL + 1;
            moves.push_back(file + to_string(7 - xL) + leftLowerDiaMove + to_string(7 - newPos));
        }
        if ((xL-1) >=4 && (yL+1) <=4 && emptyOrOppPeiceForWhite(matrix_of_congo, xL-1, yL+1) == true){
            string rightUpperDiaMove =files[yL + 1];
            int newPos =xL - 1;
            moves.push_back(file + to_string(7 - xL) + rightUpperDiaMove + to_string(7 - newPos));
        }

        if ((xL + 1) <=6 && (yL+1) <=4 && emptyOrOppPeiceForWhite(matrix_of_congo, xL+1, yL+1) == true){
            string rightLowerDiaMove =files[yL + 1];
            int newPos =xL + 1;
            moves.push_back(file + to_string(7 - xL) + rightLowerDiaMove + to_string(7 - newPos));
        }
    } 
    else if (element =="b") {
        string file =files[yl];

        if ((xl + 1) <= 2 && emptyOrOppPeiceForBlack(matrix_of_congo, xl + 1, yl) ==true) {
        string uppermove =files[yl];
        int newPos =xl + 1;
        moves.push_back(file + to_string(7 - xl) + uppermove + to_string(7 - newPos));
        }

        if ((xl - 1) >=0 && emptyOrOppPeiceForBlack(matrix_of_congo, xl - 1, yl) == true){

            string lowerMove =files[yl];
            int newPos =xl - 1;
            moves.push_back(file + to_string(7 - xl) + lowerMove + to_string(7 - newPos));
        }

        if ( (yl - 1) >=2 && emptyOrOppPeiceForBlack(matrix_of_congo, xl, yl - 1) == true ){
            
            string leftMove =files[yl - 1];
            moves.push_back(file + to_string(7 - xl) + leftMove + to_string(7 - xl));
        }

        if ((yl + 1) <= 4 && emptyOrOppPeiceForBlack(matrix_of_congo, xl, yl + 1) == true){
            
            string rightMove =files[yl + 1];
            moves.push_back(file + to_string(7 - xl) + rightMove + to_string(7 - xl));
        }

        if ( (xl - 1) >=0 && (yl - 1) >=2 && emptyOrOppPeiceForBlack(matrix_of_congo, xl-1, yl-1) == true){
            string leftUpperDiaMove =files[yl -1];
            int newPos =xl - 1;
            moves.push_back(file + to_string(7 - xl) + leftUpperDiaMove + to_string(7 - newPos));
        }
        if ((xl+1) <=2 && (yl-1) >=2 && emptyOrOppPeiceForBlack(matrix_of_congo, xl+1, yl-1) == true){
            string leftLowerDiaMove =files[yl-1];
            int newPos =xl + 1;
            moves.push_back(file + to_string(7 - xl) + leftLowerDiaMove + to_string(7 - newPos));
        }

        if ((xl-1) >=0 && (yl+1) <=4 && emptyOrOppPeiceForBlack(matrix_of_congo, xl-1, yl+1) == true){
            string rightUpperDiaMove =files[yl + 1];
            int newPos =xl - 1;
            moves.push_back(file + to_string(7 - xl) + rightUpperDiaMove + to_string(7 - newPos));
        }

        if ((xl + 1) <=2 && (yl+1) <=4 && emptyOrOppPeiceForBlack(matrix_of_congo, xl+1, yl+1) == true){
            string rightLowerDiaMove =files[yl + 1];
            int newPos =xl + 1;
            moves.push_back(file + to_string(7 - xl) + rightLowerDiaMove + to_string(7 - newPos));
        }

    }
        
}

void LionMoves(vector< vector<string>> matrix_of_congo, vector<string> &moves)
{
    int xl, yl; //position of the black lion
    int xL, yL; //position of the white lion

    for (int i =0; i < 7; i++){
        for (int j=0; j < 7; j++){
            
            if (matrix_of_congo[i][j] =="L"){
                xL =i;
                yL =j;
            }
            else if(matrix_of_congo[i][j] =="l"){
                xl =i;
                yl =j;
            }
        }
    }
    //this part converts the side to move to a string instead of char
    stringstream ss;
    string element;
    ss << side_to_move;
    ss >> element;
    if (element =="w")
    {
        //check if both lions are in the same file
        if (yl == yL){
            if (checkVerticalPiece(matrix_of_congo, xl, yl, xL, yL) == true){
                string file =files[yL];
                moves.push_back(file + to_string(7 - xL) + file + to_string(7 - xl));
            }
            getTheNeiboringPieces(matrix_of_congo, moves, xl, yl, xL, yL, element);
            
        }
        //When the two lions are not in the same file
        else {
            if (checkDiagonalPiece(matrix_of_congo, xl, yl, xL, yL) ==true){
                string wLion =files[yL];
                string bLion =files[yl];
                moves.push_back(wLion + to_string(7 - xL) + bLion + to_string(7 - xl));

            }
            getTheNeiboringPieces(matrix_of_congo, moves, xl, yl, xL, yL, element);

            
        }
    }

    //When black is playing
    else if (element =="b") {

        if(yl == yL){
            if (checkVerticalPiece(matrix_of_congo, xl, yl, xL, yL) == true){
            string file =files[yl];
            moves.push_back(file + to_string(7 - xl) + file + to_string(7 - xL));
            }

            getTheNeiboringPieces(matrix_of_congo, moves, xl, yl, xL, yL, element);
        }
        else {
            if (checkDiagonalPiece(matrix_of_congo, xl, yl, xL, yL) ==true){
                string wLion =files[yL];
                string bLion =files[yl];
                moves.push_back(bLion + to_string(7 - xl) + wLion + to_string(7 - xL));

            }
            getTheNeiboringPieces(matrix_of_congo, moves, xl, yl, xL, yL, element);
        }
    }
}

int evaluation(vector<vector<string>> matrix_of_congo)
{
    int countblack = 0;
    int countwhite = 0;
    int blacklionn = 0;
    int whitelionn = 0;
    int total = 0;
    
		for( int i = 0; i < 7; i++){
			for(int j = 0; j < 7; j++){
			// start of white zebra possible movements and eliminations
			    if(matrix_of_congo[i][j] == "L"){
					whitelionn = whitelionn + 10000;
				}
				if(matrix_of_congo[i][j] == "l"){
					blacklionn = blacklionn + 10000; 
				}
                if(matrix_of_congo[i][j] =="Z"){
                    countwhite = countwhite + 300;
                }
                if(matrix_of_congo[i][j] =="P"){
                    countwhite = countwhite + 100;
                }
                if(matrix_of_congo[i][j] =="E"){
                    countwhite = countwhite + 200;
                }
                if( matrix_of_congo[i][j] =="e"){
                    countblack = countblack + 200;
                }
                if( matrix_of_congo[i][j] =="p"){
                    countblack = countblack + 100;
                }
                if( matrix_of_congo[i][j] =="z"){
                    countblack = countblack + 300;
                }		
		    }
		}
    
    if(side_to_move == 'w'){
        if( (whitelionn == 0) && (blacklionn == 10000)){
            total = (-1)*10000;
		}
        if( (whitelionn == 10000) && (blacklionn == 0)){
            total = 10000;
		}
        if( (whitelionn == 10000) && (blacklionn == 10000)){
            total = countwhite - countblack;
        }
    }
    else if(side_to_move == 'b'){
        if( (whitelionn == 0) && (blacklionn == 10000)){
            total = 10000;
		}
        if( (whitelionn == 10000) && (blacklionn == 0)){
            total = (-1)*10000;
            
		}
        if (  (whitelionn == 10000) && (blacklionn == 10000)){
            total = (-1)*(countwhite-countblack);
        }
    }
    return total;
}

string convertToFen(vector< vector<string> > matrix_of_congo, string move_side, int move_number, string outcome){

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

    string state ="";
    for (int i=0; i < ranks.size(); i++){
        if ((i+1)%ranks.size()==0){
            state = state + ranks[i];
        }
        else {
            state = state + ranks[i] + "/";
        }
    }
    string nextState = state + " " + move_side + " " + to_string(move_number);
    return nextState;

}

string makemove(vector< vector<string>> matrix_of_congo, string the_move)
{
    int rank1, rank2, first_file, second_file;

    string gameState;

    rank1 =the_move[1] - 48;
    rank2 =the_move[3] - 48;
    string element1, element2;
    element1.push_back(the_move[0]);
    element2.push_back(the_move[2]);

    for (int i =0; i <7; i++){
        
        if (element1 == files[i]){
            first_file =i;
        }
    }

    for (int i=0; i < 7; i++){
        if (element2 == files[i]){
            second_file =i;
        }
    }
    stringstream ss;
    string element;
    ss << side_to_move;
    ss >> element;
    

    int x_initial =7-rank1;
    int x_final =7-rank2;
    if (element =="w")
    {
        string outcome;
        if (x_initial ==3 && x_final ==3){
            swap(matrix_of_congo[x_final][second_file], matrix_of_congo[x_initial][first_file]);
            matrix_of_congo[x_initial][first_file] = "0";
            clearForwhite(matrix_of_congo);
            outcome ="Continue";
            gameState = convertToFen(matrix_of_congo, "b", number_of_moves, outcome);

        }
        else if (x_final ==3 && x_initial !=3){
            clearForwhite(matrix_of_congo);
            swap(matrix_of_congo[x_final][second_file], matrix_of_congo[x_initial][first_file]);
            matrix_of_congo[x_initial][first_file] ="0";
            outcome ="Continue";
            gameState = convertToFen(matrix_of_congo, "b", number_of_moves, outcome);
        }

        else if (x_initial ==3 && x_final !=3){
            if (matrix_of_congo[x_final][second_file] =="l")
            {
                swap(matrix_of_congo[x_final][second_file], matrix_of_congo[x_initial][first_file]);
                matrix_of_congo[x_initial][first_file] ="0";
                clearForwhite(matrix_of_congo);
                outcome ="White wins";
                gameState = convertToFen(matrix_of_congo, "b", number_of_moves, outcome);
            }
            else {
                swap(matrix_of_congo[x_final][second_file], matrix_of_congo[x_initial][first_file]);
                matrix_of_congo[x_initial][first_file] ="0";
                clearForwhite(matrix_of_congo);
                outcome ="Continue";
                gameState = convertToFen(matrix_of_congo, "b", number_of_moves, outcome);
            }
        }
        else if (x_initial !=3 && x_final !=3){
            
            if (matrix_of_congo[x_final][second_file] =="l"){
                swap(matrix_of_congo[x_final][second_file], matrix_of_congo[x_initial][first_file]);
                matrix_of_congo[x_initial][first_file] ="0";
                clearForwhite(matrix_of_congo);
                outcome ="White wins";
                gameState = convertToFen(matrix_of_congo, "b", number_of_moves, outcome);
            }
            else {
                swap(matrix_of_congo[x_final][second_file], matrix_of_congo[x_initial][first_file]);
                matrix_of_congo[x_initial][first_file] ="0";
                clearForwhite(matrix_of_congo);
                outcome ="Continue";
                gameState = convertToFen(matrix_of_congo, "b", number_of_moves, outcome);
            }
        }
    }

    else if (element =="b")
    {
        string outcome;
        if (x_initial ==3 && x_final ==3){
            swap(matrix_of_congo[x_final][second_file], matrix_of_congo[x_initial][first_file]);
            matrix_of_congo[x_initial][first_file] ="0";
            clearForBlack(matrix_of_congo);
            outcome ="Continue";
            gameState = convertToFen(matrix_of_congo, "w", number_of_moves + 1, outcome);
        }
        else if (x_final ==3 && x_initial !=3){
            clearForBlack(matrix_of_congo);
            swap(matrix_of_congo[x_final][second_file], matrix_of_congo[x_initial][first_file]);
            matrix_of_congo[x_initial][first_file] ="0";
            outcome ="Continue";
            gameState = convertToFen(matrix_of_congo, "w", number_of_moves + 1, outcome);
        }
        else if (x_initial ==3 && x_final !=3){
            
            if (matrix_of_congo[x_final][second_file] =="L"){
                swap(matrix_of_congo[x_final][second_file], matrix_of_congo[x_initial][first_file]);
                matrix_of_congo[x_initial][first_file] ="0";
                clearForBlack(matrix_of_congo);
                outcome ="Black wins";
                gameState = convertToFen(matrix_of_congo, "w", number_of_moves + 1, outcome);
            }
            else {
                swap(matrix_of_congo[x_final][second_file], matrix_of_congo[x_initial][first_file]);
                matrix_of_congo[x_initial][first_file] ="0";
                clearForBlack(matrix_of_congo);
                outcome ="Continue";
                gameState = convertToFen(matrix_of_congo, "w", number_of_moves + 1, outcome);
            }
        }
        else if (x_initial !=3 && x_final !=3){

            if (matrix_of_congo[x_final][second_file] =="L"){
                swap(matrix_of_congo[x_final][second_file], matrix_of_congo[x_initial][first_file]);
                matrix_of_congo[x_initial][first_file] ="0";
                clearForBlack(matrix_of_congo);
                outcome ="Black wins";
                gameState = convertToFen(matrix_of_congo, "w", number_of_moves + 1, outcome);
            }
            else {
                swap(matrix_of_congo[x_final][second_file], matrix_of_congo[x_initial][first_file]);
                matrix_of_congo[x_initial][first_file] ="0";
                clearForBlack(matrix_of_congo);
                outcome ="Continue";
                gameState = convertToFen(matrix_of_congo, "w", number_of_moves + 1, outcome);
            }
        }
    }

    return gameState;


}

vector< vector<string>> formCongoBoard(string state)
{   
    vector<vector<string>> matrix_of_congo;
    vector<string> rows =tokenize(state, "/");
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

    
    return matrix_of_congo;
    
}

bool isGameOver(string state)
{
    if(state.find('L') != string::npos && state.find('l') != string::npos){ // i can find L and l
        return false;
    }
    return true;
}

void printBoard(vector<vector<string>> matrix_of_congo)
{
    for (int i =0; i < 7; i++)
    {
        for (int j=0; j < 7; j++)
        {
            cout << matrix_of_congo[i][j] <<" ";
        }
        cout <<endl;
    }
}

int minimax(string gameState, int depth)
{

    vector<string> arr =tokenize(gameState, " ");

    game_space =arr[0];

    string move =arr[1];
    side_to_move =move[0];

    stringstream ss(arr[2]);
    ss >> number_of_moves;

    vector< vector<string>> matrix_of_congo = formCongoBoard(game_space);

    if (isGameOver(game_space) == true || depth <= 0)
    {
        return evaluation(matrix_of_congo);
    }

    int value = -10000000;
    vector<string> moves;

    LionMoves(matrix_of_congo, moves);
    PawnMoves(matrix_of_congo, moves);
    ElephantMoves(matrix_of_congo, moves);
    ZebraMoves(matrix_of_congo, moves);

    for(int i=0; i < moves.size(); i++)
    {
        string nextState = makemove(matrix_of_congo, moves[i]);

        int val = -minimax(nextState, depth - 1);
        
        value = max(value, val);

        if (i != moves.size()-1)
        {
            //gameState =board;
            game_space =arr[0];
            
            string move =arr[1];
            side_to_move =move[0];

            stringstream ss(arr[2]);
            ss >> number_of_moves;

            matrix_of_congo = formCongoBoard(game_space);
        }
    }
    return value;

}

void storeFens(vector<string> fens)
{
    for (int i=0; i < fens.size(); i++)
    {
        cout << minimax(fens[i], 2) <<endl;
    }
    
}
int main()
{
    int N;
    cin>>N;
    cin.ignore();
    vector<string> fens;

    for (int i =0; i < N;  i++)
    {
        string FEN;
        getline(cin ,FEN);
        fens.push_back(FEN);
    }

    storeFens(fens);
return 0;

}

// 3
// 2ele1z/ppppppp/7/7/7/PPP1PPP/2ELE1Z w 4
// 1z5/pPp1lP1/5ep/4P1e/4L1p/2p2pP/7 b 35
// 1z5/pPp1lP1/5ep/4P1e/4L1p/2p2pP/7 w 12
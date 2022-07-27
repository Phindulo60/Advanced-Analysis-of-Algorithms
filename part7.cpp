#include<iostream>
#include<bits/stdc++.h>
#include<sstream>
#include<cstring>
#include <cctype>

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
                for (int k=0; k < x; k++){
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
    
    int countblack = 0;
    int countwhite = 0;
    int blacklionn = 0;
    int whitelionn = 0;
    int countblack1 = 0;
    int countwhite1 = 0;
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
					 countblack1 = 10000;
					 //cout << countblack1 << endl;
				}
        if( (whitelionn == 10000) && (blacklionn == 0)){
					  countwhite1 = 10000;
					  total = (-1)*countwhite1;
					  //cout << total << endl;
				}
        if( (whitelionn == 10000) && (blacklionn == 10000)){
    	total = countwhite - countblack;
    	//cout << total << endl;
        }
    }
    if(side_to_move == 'b'){
        if( (whitelionn == 0) && (blacklionn == 10000)){
					 countblack1 = 10000;
					 //cout << countblack1 << endl;
				}
        if( (whitelionn == 10000) && (blacklionn == 0)){
					  countwhite1 = 10000;
					  total =  (-1)*countwhite1;
					  //cout  << total << endl;
				}
        
        if (  (whitelionn == 10000) && (blacklionn == 10000)){
    	total = (-1)*(countwhite-countblack);
    	//cout << total << endl; 
        }
    }
    		        
   int  whitemob = 0;
   int blackmob = 0;
   int mobilitysc = 0;
   int attacksc = 0;
   int atb = 0;
   int atw = 0;
   
         	for( int i = 0; i < 7; i++){
			for(int j = 0; j < 7; j++){
			
			// Start of mobilities of pieces
				if( matrix_of_congo[i][j] =="Z" ){
                    			if(((j+1) < 7) && ((i-2) >= 0)){
                        			if( matrix_of_congo[i-2][j+1] == "0"){
                            				whitemob = whitemob + 1;
						}
					    }
					    if(((j-2) >= 0) && ((i-1) >= 0)){
						if(matrix_of_congo[i-1][j-2] == "0"){
						        whitemob = whitemob + 1;
						}
					    }
					    
					    if(((i-2) >= 0) && ((j-1) >= 0)){
						if(matrix_of_congo[i-2][j-1] == "0"){
						    whitemob = whitemob + 1;
						}
					    }
					    if(((i+2) < 7) && ((j-1) >= 0)){
						if(matrix_of_congo[i+2][j-1] == "0"){
						    whitemob = whitemob + 1;
						}
					    }
					    if(((i+1) < 7) && ((j-2) >= 0)){
						if(matrix_of_congo[i+1][j-2] == "0" ){
						whitemob = whitemob + 1;
						
						}
					    }
					    if(((i+1) < 7) && ((j+2) < 7) ){
						if(matrix_of_congo[i+1][j+2] == "0"){
						    whitemob = whitemob + 1;
						}
					    }
					    if(((j+1) < 7) && ((i+2) < 7)){
						if( matrix_of_congo[i+2][j+1] == "0" ){
						    whitemob = whitemob + 1;
						}
					    }
					    if((j+2) < 7 && (i-1) >= 0){
						if(matrix_of_congo[i-1][j+2] == "0" ){
						    whitemob = whitemob + 1;
						}
					    }
					}
					
					if( matrix_of_congo[i][j] =="E" ){
                    				if((j-2) < 7 && (j-2) >= 0){
                        				if( matrix_of_congo[i][j-2] == "0" ){
                        					whitemob = whitemob + 1;
						}
					    }
					    if((j-1) < 7 && (j-1) >= 0){
						if( matrix_of_congo[i][j-1] == "0" ){
						    whitemob = whitemob + 1;
						}
					    }
					    if((i+1) < 7 && (i+1) >= 0){
						if( matrix_of_congo[i+1][j] == "0" ){
						    whitemob = whitemob + 1;
						}
					    }	
					    if((i+2) < 7 && (i+2) >= 0){
						if( matrix_of_congo[i+2][j] == "0" ){
						    whitemob = whitemob + 1;
						}
					    }
					    if((j+2) < 7 && (j+2) >= 0){
						if( matrix_of_congo[i][j+2] == "0" ){
						    whitemob = whitemob + 1;
						}
					    }
					    if((j+1) < 7 && (j+1) >= 0){
						if( matrix_of_congo[i][j+1] == "0" ){
						    whitemob = whitemob + 1;
						}
					    }
					    if((i-1) < 7 && (i-1) >= 0){
						if( matrix_of_congo[i-1][j] == "0" ){
						    whitemob = whitemob + 1;
						}
					    }
					    if((i-2) < 7 && (i-2) >= 0){
						if( matrix_of_congo[i-2][j] == "0" ){
						    whitemob = whitemob + 1;    
						}
					    }		
						
					}
					
					if( matrix_of_congo[i][j] =="P" ){
            
						    if(i > 3 ){
							if( ((j-1) >= 0)){
							    if( matrix_of_congo[i-1][j-1] == "0"){
								whitemob = whitemob + 1; 
							    }
							}
							if( matrix_of_congo[i-1][j] == "0"){
							    whitemob = whitemob + 1; 
							}
							if((j+1) < 7){
							    if( matrix_of_congo[i-1][j+1] == "0"){
								whitemob = whitemob + 1; 
							    }
							}
						    }
						    if(i == 3){
							if((j-1) >=0 ){
							    if( matrix_of_congo[i-1][j-1] == "0"){
								whitemob = whitemob + 1; 
							    }
							}
							if( matrix_of_congo[i-1][j] == "0"){
							    whitemob = whitemob + 1; 
							}
							if((j+1) < 7){
							    if( matrix_of_congo[i-1][j+1] == "0"){
								whitemob = whitemob + 1; 
							    }
							}
							
						    }
						    if( i < 3){
							if( ((j-1) >= 0)&&( (i-1)>=0)){
							    if( matrix_of_congo[i-1][j-1] == "0"){
								whitemob = whitemob + 1; 
							    }
							}
							if( matrix_of_congo[i-1][j] == "0"){
							    whitemob = whitemob + 1; 
							}
							if((j+1) < 7){
							    if( matrix_of_congo[i-1][j+1] == "0"){
								whitemob = whitemob + 1; 
							    }
							}
							if( matrix_of_congo[i+1][j] == "0"){
								whitemob = whitemob + 1; 
							}
							if( matrix_of_congo[i+1][j] == "0"){
							    if( matrix_of_congo[i+2][j] == "0"){
								whitemob = whitemob + 1; 
							    }
							}
						    }
						   }
						   
				/*if( matrix_of_congo[i][j] =="L" ){
						
				}*/
				if( matrix_of_congo[i][j] == "z" ){
    			    		if(((j+1) < 7) && ((i-2) >= 0)){
			    		        if( matrix_of_congo[i-2][j+1] == "0"){
			    		            blackmob = blackmob + 1;
			    		        	}
			    		        }
			    		        if(((j-2) >= 0) && ((i-1) >= 0)){
			    		      	    if(matrix_of_congo[i-1][j-2] == "0"){
			    		      	    	blackmob = blackmob + 1;
			    		      	    }
			    		        }
			    		      
			    		        if(((i-2) >= 0) && ((j-1) >= 0)){
			    		     		if(matrix_of_congo[i-2][j-1] == "0"){
			    		     		    blackmob = blackmob + 1;
			    		     		}
			    		        }
			    		        if(((i+2) < 7) && ((j-1) >= 0)){
			    		     		if(matrix_of_congo[i+2][j-1] == "0"){
			    		     		    blackmob = blackmob + 1;
			    		     		}
			    		        }
			    		        if(((i+1) < 7) && ((j-2) >= 0)){
			    		     		if(matrix_of_congo[i+1][j-2] == "0"){
			    		   			blackmob = blackmob + 1;
			    		     		
			    		     		}
			    		        }
			    		        if(((i+1) < 7) && ((j+2) < 7) ){
			    		     		if(matrix_of_congo[i+1][j+2] == "0"){
			    		     		    blackmob = blackmob + 1;
			    		     		}
			    		        }
			    		        if(((j+1) < 7) && ((i+2) < 7)){
			    		     		if( matrix_of_congo[i+2][j+1] == "0"){
			    		     		    blackmob = blackmob + 1;
			    		     		}
			    		        }
			    		        if((j+2) < 7 && (i-1) >= 0){
			    		     		if(matrix_of_congo[i-1][j+2] == "0"){
			    		     		    blackmob = blackmob + 1;
			    		     	    }
			    		        }
			    		    }
			    		    		   
					if( matrix_of_congo[i][j] =="e" ){
		    			    if((j-2) < 7 && (j-2) >= 0){
			    		        if( matrix_of_congo[i][j-2] == "0"){
				           		blackmob = blackmob + 1;
			    			    }
		    			    }
		    				if((j-1) < 7 && (j-1) >= 0){
				    		    if( matrix_of_congo[i][j-1] == "0"){
				    			   blackmob = blackmob + 1;
				    			}
		    				}
					    if((i+1) < 7 && (i+1) >= 0){
						if( matrix_of_congo[i+1][j] == "0"){
						    blackmob = blackmob + 1;
						}
					    }	
					    if((i+2) < 7 && (i+2) >= 0){
						if( matrix_of_congo[i+2][j] == "0"){
						    blackmob = blackmob + 1;
						}
					    }
					    if((j+2) < 7 && (j+2) >= 0){
						if( matrix_of_congo[i][j+2] == "0"){
						    blackmob = blackmob + 1;
						}
					    }
					    if((j+1) < 7 && (j+1) >= 0){
						if( matrix_of_congo[i][j+1] == "0"){
						    blackmob = blackmob + 1;
						}
					    }
					    if((i-1) < 7 && (i-1) >= 0){
						if( matrix_of_congo[i-1][j] == "0"){
						    blackmob = blackmob + 1;
						}
					    }
					    if((i-2) < 7 && (i-2) >= 0){
						if( matrix_of_congo[i-2][j] == "0"){
						    blackmob = blackmob + 1;
						}
					    }			
					}
					
					if( matrix_of_congo[i][j] =="p" ){
		    			    if( i < 3){
		    				    if(((i+1) < 7) && ((j-1) >= 0)){
								if( matrix_of_congo[i+1][j-1] == "0"){
									blackmob = blackmob + 1;
								}
							    }
					    if((i+1) < 7 ){
					        if( matrix_of_congo[i+1][j] == "0"){
						        blackmob = blackmob + 1;
					        }
					    }
					    if(((i+1) < 7) && ((j+1) < 7)){
						    if( matrix_of_congo[i+1][j+1] == "0"){
						        blackmob = blackmob + 1;
						    }
					    }	          
		    		        }
		    		        if(i == 3){
		    		      		if( matrix_of_congo[i+1][j] == "0"){
						    blackmob = blackmob + 1;
							    }
					    if((j+1) < 7){
							if( matrix_of_congo[i+1][j+1] == "0"){
								blackmob = blackmob + 1;
							}
					    }
					    if((j-1) >= 0){
							if( matrix_of_congo[i+1][j-1] == "0"){
								blackmob = blackmob + 1;
							}
					    }
		    		        }
		    		        if( i > 3){
		    		      	    if(((i+1) < 7) && ((j+1) < 7)){
					        if( matrix_of_congo[i+1][j+1] == "0"){
						        blackmob = blackmob + 1;
					        }
					    }
					    if(((i+1) < 7) && ((j-1) >= 0)){
					        if( matrix_of_congo[i+1][j-1] == "0"){
						        blackmob = blackmob + 1;
					        }
					    }
					    if((i+1) < 7 ){
					        if( matrix_of_congo[i+1][j] == "0"){
						        blackmob = blackmob + 1;
					        }
					    }
					    if( matrix_of_congo[i-1][j] == "0"){
						    blackmob = blackmob + 1;
					    }
					    if( matrix_of_congo[i-1][j] == "0"){
						    if( matrix_of_congo[i-2][j] == "0"){
						        blackmob = blackmob + 1;
							}
				        }
		    		        }
				}
				// End of possible mobilities
				
			//Start of possible attacking moves
				//first part
			if( matrix_of_congo[i][j] =="Z" ){
				    if(((j+1) < 7) && ((i-2) >= 0)){
				        if( matrix_of_congo[i-2][j+1] == "e"|| matrix_of_congo[i-2][j+1] == "p"||matrix_of_congo[i-2][j+1] == "z"){
				            atw = atw + 1;
				        }
				        if( matrix_of_congo[i-2][j+1] == "l"){
				        	atw = atw + 10;
				        }
				    }
				    if(((j-2) >= 0) && ((i-1) >= 0)){
				        if(matrix_of_congo[i-1][j-2] == "e"|| matrix_of_congo[i-1][j-2] == "p"||matrix_of_congo[i-1][j-2] == "z"){
				               atw = atw + 1;
				        }
				        if( matrix_of_congo[i-1][j-2] == "l"){
				        	atw = atw + 10;
				        }
				    }
				    
				    if(((i-2) >= 0) && ((j-1) >= 0)){
				        if(matrix_of_congo[i-2][j-1] == "e"|| matrix_of_congo[i-2][j-1] == "p"||matrix_of_congo[i-2][j-1] == "z"){
				            atw = atw + 1;
				        }
				        if( matrix_of_congo[i-2][j-1] == "l"){
				        	atw = atw + 10;
				        }
				    }
				    if(((i+2) < 7) && ((j-1) >= 0)){
				        if(matrix_of_congo[i+2][j-1] == "e"|| matrix_of_congo[i+2][j-1] == "p"||matrix_of_congo[i+2][j-1] == "z"){
				            atw = atw + 1;
				        }
				        if( matrix_of_congo[i-2][j-1] == "l"){
				        	atw = atw + 10;
				        }
				    }
				    if(((i+1) < 7) && ((j-2) >= 0)){
				        if(matrix_of_congo[i+1][j-2] == "e"|| matrix_of_congo[i+1][j-2] == "p"||matrix_of_congo[i+1][j-2] == "z" ){
				        atw = atw + 1;
				        }
				        if( matrix_of_congo[i+1][j-2] == "l"){
				        	atw = atw + 10;
				        }
				    }
				    if(((i+1) < 7) && ((j+2) < 7) ){
				        if(matrix_of_congo[i+1][j+2] == "e"|| matrix_of_congo[i+1][j+2] == "p"||matrix_of_congo[i+1][j+2] == "z"){
				            atw = atw + 1;
				        }
				        if( matrix_of_congo[i+1][j+2] == "l"){
				        	atw = atw + 10;
				        }
				    }
				    if(((j+1) < 7) && ((i+2) < 7)){
				        if(  matrix_of_congo[i+2][j+1] == "e"|| matrix_of_congo[i+2][j+1] == "p"||matrix_of_congo[i+2][j+1] == "z"){
				            atw = atw + 1;
				        }
				        if( matrix_of_congo[i+2][j+1] == "l"){
				        	atw = atw + 10;
				        }
				    }
				    if((j+2) < 7 && (i-1) >= 0){
				        if(matrix_of_congo[i-1][j+2] == "e"|| matrix_of_congo[i-1][j+2] == "p"||matrix_of_congo[i-1][j+2] == "z" ){
				            atw = atw + 1;
				        }
				        if( matrix_of_congo[i-1][j+2] == "l"){
				        	atw = atw + 10;
				        }
				    }
				}
				
			if( matrix_of_congo[i][j] =="E" ){
		            if((j-2) < 7 && (j-2) >= 0){
		                if(matrix_of_congo[i][j-2] == "e" || matrix_of_congo[i][j-2] == "z" || matrix_of_congo[i][j-2] == "p"){
		                atw = atw + 1;
		                }
		                if( matrix_of_congo[i][j-2] == "l"){
				        	atw = atw + 10;
				        }
		            }
                    if((j-1) < 7 && (j-1) >= 0){
                        if(matrix_of_congo[i][j-1] == "e" || matrix_of_congo[i][j-1] == "z" || matrix_of_congo[i][j-1] == "p"){
                            atw = atw + 1;
                        }
                        if( matrix_of_congo[i][j-1] == "l"){
				        	atw = atw + 10;
				        }
                    }
                    if((i+1) < 7 && (i+1) >= 0){
                        if(matrix_of_congo[i+1][j] == "e"|| matrix_of_congo[i+1][j] == "z" || matrix_of_congo[i+1][j] == "p"){
                            atw = atw + 1;
                        }
                        if( matrix_of_congo[i+1][j] == "l"){
				        	atw = atw + 10;
				        }
                    }	
                    if((i+2) < 7 && (i+2) >= 0){
                        if( matrix_of_congo[i+2][j] == "e" || matrix_of_congo[i+2][j] == "z" || matrix_of_congo[i+2][j] == "p"){
                            atw = atw + 1;
                        }
                        if( matrix_of_congo[i+2][j] == "l"){
				        	atw = atw + 10;
				        }
                    }
                    if((j+2) < 7 && (j+2) >= 0){
                        if( matrix_of_congo[i][j+2] == "e" || matrix_of_congo[i][j+2] == "z" || matrix_of_congo[i][j+2] == "p"){
                            atw = atw + 1;
                        }
                        if( matrix_of_congo[i][j+2] == "l"){
				        	atw = atw + 10;
				        }
                    }
                    if((j+1) < 7 && (j+1) >= 0){
                        if( matrix_of_congo[i][j+1] == "e" || matrix_of_congo[i][j+1] == "z" || matrix_of_congo[i][j+1] == "p"){
                            atw = atw + 1;
                        }
                        if( matrix_of_congo[i][j+1] == "l"){
				        	atw = atw + 10;
				        }
                    }
                    if((i-1) < 7 && (i-1) >= 0){
                        if(matrix_of_congo[i-1][j] == "e" || matrix_of_congo[i-1][j] == "z" || matrix_of_congo[i-1][j] == "p"){
                            atw = atw + 1;
                        }
                        if( matrix_of_congo[i-1][j] == "l"){
				        	atw = atw + 10;
				        }
                    }
                    if((i-2) < 7 && (i-2) >= 0){
                        if(matrix_of_congo[i-2][j] == "e"|| matrix_of_congo[i-2][j] == "z" || matrix_of_congo[i-2][j] == "p"){
                            atw = atw + 1; 
                        }
                        if( matrix_of_congo[i-2][j] == "l"){
				        	atw = atw + 10;
				        }
                    }		
                        
                }
                
                if( matrix_of_congo[i][j] =="P" ){
            
                    if(i > 3 ){
                        if( ((j-1) >= 0)){
                            if( matrix_of_congo[i-1][j-1] == "e"|| matrix_of_congo[i-1][j-1] == "p"||matrix_of_congo[i-1][j-1] == "z"){
                                atw = atw + 1;
                            }
                            if( matrix_of_congo[i-1][j-1] == "l"){
				        	atw = atw + 10;
				        }
                        }
                        if( matrix_of_congo[i-1][j] == "e"|| matrix_of_congo[i-1][j] == "p"||matrix_of_congo[i-1][j] == "z"){
                            atw = atw + 1;
                        }
                        if( matrix_of_congo[i-1][j] == "l"){
				        	atw = atw + 10;
				        }
                        if((j+1) < 7){
                            if(matrix_of_congo[i-1][j+1] == "e"|| matrix_of_congo[i-1][j+1] == "p"||matrix_of_congo[i-1][j+1] == "z"){
                                atw = atw + 1;
                            }
                            if( matrix_of_congo[i-1][j+1] == "l"){
				        	atw = atw + 10;
				        }
                        }
                    }
                    if(i == 3){
                        if((j-1) >=0 ){
                            if(matrix_of_congo[i-1][j-1] == "e"|| matrix_of_congo[i-1][j-1] == "p"||matrix_of_congo[i-1][j-1] == "z"){
                                atw = atw + 1;
                            }
                            if( matrix_of_congo[i-1][j-1] == "l"){
				        	atw = atw + 10;
				        }
                        }
                        if(matrix_of_congo[i-1][j] == "e"|| matrix_of_congo[i-1][j] == "p"||matrix_of_congo[i-1][j] == "z"){
                           atw = atw + 1;
                        }
                        if( matrix_of_congo[i-1][j] == "l"){
				        	atw = atw + 10;
				        }
                        if((j+1) < 7){
                            if(matrix_of_congo[i-1][j+1] == "e"|| matrix_of_congo[i-1][j+1] == "p"||matrix_of_congo[i-1][j+1] == "z"){
                                atw = atw + 1;
                            }
                            if( matrix_of_congo[i-1][j+1] == "l"){
				        	atw = atw + 10;
				        }
                        }
                        
                    }
                    if( i < 3){
                        if( ((j-1) >= 0)&&( (i-1)>=0)){
                            if(matrix_of_congo[i-1][j-1] == "e"|| matrix_of_congo[i-1][j-1] == "p"||matrix_of_congo[i-1][j-1] == "z"){
                                atw = atw + 1;
                            }
                            if( matrix_of_congo[i-1][j-1] == "l"){
				        	atw = atw + 10;
				        }
                        }
                        if(matrix_of_congo[i-1][j] == "e"|| matrix_of_congo[i-1][j] == "p"||matrix_of_congo[i-1][j] == "z"){
                            atw = atw + 1;
                        }
                        if( matrix_of_congo[i-1][j] == "l"){
				        	atw = atw + 10;
				        }
                        if((j+1) < 7){
                            if(matrix_of_congo[i-1][j+1] == "e"|| matrix_of_congo[i-1][j+1] == "p"||matrix_of_congo[i-1][j+1] == "z"){
                                atw = atw + 1;
                            }
                            if( matrix_of_congo[i-1][j+1] == "l"){
				        	atw = atw + 10;
				        }
                        }
                       
                    }		      
                }
                
                		//SEcond part
                		if( matrix_of_congo[i][j] == "z" ){
    			    if(((j+1) < 7) && ((i-2) >= 0)){
	    		        if(matrix_of_congo[i-2][j+1] == "E"|| matrix_of_congo[i-2][j+1] == "P"||matrix_of_congo[i-2][j+1] == "Z"){
	    		            atb = atb + 1;
	    		        }
	    		        if( matrix_of_congo[i-2][j+1] == "L"){
				        	atb = atb + 10;
				        }
    		        }
    		        if(((j-2) >= 0) && ((i-1) >= 0)){
    		      	    if(matrix_of_congo[i-1][j-2] == "E"|| matrix_of_congo[i-1][j-2] == "P"||matrix_of_congo[i-1][j-2] == "Z"){
    		      	    	atb = atb + 1;
    		      	    }
    		      	    if( matrix_of_congo[i-1][j-2] == "L"){
				        	atb = atb + 10;
				        }
    		        }
    		      
    		        if(((i-2) >= 0) && ((j-1) >= 0)){
    		     		if(matrix_of_congo[i-2][j-1] == "E"|| matrix_of_congo[i-2][j-1] == "P"||matrix_of_congo[i-2][j-1] == "Z"){
    		     		    atb = atb + 1;
    		     		}
    		     		if( matrix_of_congo[i-2][j-1] == "L"){
				        	atb = atb + 10;
				        }
    		        }
    		        if(((i+2) < 7) && ((j-1) >= 0)){
    		     		if(matrix_of_congo[i+2][j-1] == "E"|| matrix_of_congo[i+2][j-1] == "P"||matrix_of_congo[i+2][j-1] == "Z"){
    		     		    atb = atb + 1;
    		     		}
    		     		if( matrix_of_congo[i+2][j-1] == "L"){
				        	atb = atb + 10;
				        }
    		        }
    		        if(((i+1) < 7) && ((j-2) >= 0)){
    		     		if(matrix_of_congo[i+1][j-2] == "E"|| matrix_of_congo[i+1][j-2] == "P"||matrix_of_congo[i+1][j-2] == "Z" ){
    		   			   atb = atb + 1;
    		     		}
    		     		if( matrix_of_congo[i+2][j-2] == "L"){
				        	atb = atb + 10;
				        }
    		        }
    		        if(((i+1) < 7) && ((j+2) < 7) ){
    		     		if(matrix_of_congo[i+1][j+2] == "E"|| matrix_of_congo[i+1][j+2] == "P"||matrix_of_congo[i+1][j+2] == "Z"){
    		     		    atb = atb + 1;
    		     		}
    		     		if( matrix_of_congo[i+1][j+2] == "L"){
				        	atb = atb + 10;
				        }
    		        }
    		        if(((j+1) < 7) && ((i+2) < 7)){
    		     		if(matrix_of_congo[i+2][j+1] == "E"|| matrix_of_congo[i+2][j+1] == "P"||matrix_of_congo[i+2][j+1] == "Z"){
    		     		    atb = atb + 1;
    		     		}
    		     		if( matrix_of_congo[i+2][j+1] == "L"){
				        	atb = atb + 10;
				        }
    		        }
    		        if((j+2) < 7 && (i-1) >= 0){
    		     		if(matrix_of_congo[i-1][j+2] == "E"|| matrix_of_congo[i-1][j+2] == "P"||matrix_of_congo[i-1][j+2] == "Z" ){
    		     		    atb = atb + 1;
    		     	    }
    		     	    if( matrix_of_congo[i-1][j+2] == "L"){
				        	atb = atb + 10;
				        }
    		        }
    		    }
    		    
    		    if( matrix_of_congo[i][j] =="e" ){
    			    if((j-2) < 7 && (j-2) >= 0){
	    		        if( matrix_of_congo[i][j-2] == "E"||matrix_of_congo[i][j-2] == "P"||matrix_of_congo[i][j-2] == "Z"){
				           atb = atb + 1;
		    			    }
		    			    if( matrix_of_congo[i][j-2] == "L"){
				        	atb = atb + 10;
				        }
	    			    }
    				if((j-1) < 7 && (j-1) >= 0){
		    		    if(matrix_of_congo[i][j-1] == "E"||matrix_of_congo[i][j-1] == "P"||matrix_of_congo[i][j-1] == "Z"){
		    			   atb = atb + 1;
		    			}
		    			if( matrix_of_congo[i][j-1] == "L"){
				        	atb = atb + 10;
				        }
    				}
		            if((i+1) < 7 && (i+1) >= 0){
		                if(matrix_of_congo[i+1][j] == "E"|| matrix_of_congo[i+1][j] == "P"|| matrix_of_congo[i+1][j] == "Z"){
		                    atb = atb + 1;
		                }
		                if( matrix_of_congo[i+1][j] == "L"){
				        	atb = atb + 10;
				        }
		            }	
		            if((i+2) < 7 && (i+2) >= 0){
		                if(matrix_of_congo[i+2][j] == "E"|| matrix_of_congo[i+2][j] == "P"|| matrix_of_congo[i+2][j] == "Z"){
		                    atb = atb + 1;
		                }
		                if( matrix_of_congo[i+2][j] == "L"){
				        	atb = atb + 10;
				        }
		            }
		            if((j+2) < 7 && (j+2) >= 0){
		                if(matrix_of_congo[i][j+2] == "E"||matrix_of_congo[i][j+2] == "P"|| matrix_of_congo[i][j+2] == "Z"){
		                    atb = atb + 1;
		                }
		                if( matrix_of_congo[i][j+2] == "L"){
				        	atb = atb + 10;
				        }
		            }
		            if((j+1) < 7 && (j+1) >= 0){
		                if(matrix_of_congo[i][j+1] == "E"|| matrix_of_congo[i][j+1] == "P"|| matrix_of_congo[i][j+1] == "Z"){
		                    atb = atb + 1;
		                }
		                if( matrix_of_congo[i][j+1] == "L"){
				        	atb = atb + 10;
				        }
		            }
		            if((i-1) < 7 && (i-1) >= 0){
		                if(matrix_of_congo[i-1][j] == "E"||matrix_of_congo[i-1][j] == "P"|| matrix_of_congo[i-1][j] == "Z"){
		                    atb = atb + 1;
		                }
		                if( matrix_of_congo[i-1][j] == "L"){
				        	atb = atb + 10;
				        }
		            }
		            if((i-2) < 7 && (i-2) >= 0){
		                if(matrix_of_congo[i-2][j] == "E"|| matrix_of_congo[i-2][j] == "P"|| matrix_of_congo[i-2][j] == "Z"){
		                    atb = atb + 1;
		                }
		                if( matrix_of_congo[i-2][j] == "L"){
				        	atb = atb + 10;
				        }
		            }			
		        }
		        
		        
		        if( matrix_of_congo[i][j] =="p" ){
    			    if( i < 3){
    				    if(((i+1) < 7) && ((j-1) >= 0)){
					        if( matrix_of_congo[i+1][j-1] == "E"|| matrix_of_congo[i+1][j-1] == "P"||matrix_of_congo[i+1][j-1] == "Z"){
					            atb = atb + 1;
					        }
					        if( matrix_of_congo[i+1][j-1] == "L"){
				        	atb = atb + 10;
				                }
					    }
					    if((i+1) < 7 ){
					        if(matrix_of_congo[i+1][j] == "E"|| matrix_of_congo[i+1][j] == "P"||matrix_of_congo[i+1][j] == "Z"){
						        atb = atb + 1;
					        }
					        if( matrix_of_congo[i+1][j] == "L"){
				        	atb = atb + 10;
				        }
					    }
					    if(((i+1) < 7) && ((j+1) < 7)){
						    if(matrix_of_congo[i+1][j+1] == "E"|| matrix_of_congo[i+1][j+1] == "P"||matrix_of_congo[i+1][j+1] == "Z"){
						        atb = atb + 1;
                            			}
                            			if( matrix_of_congo[i+1][j+1] == "L"){
				        	atb = atb + 10;
				              }
					    }	          
    		        		}
    		        if(i == 3){
    		      		if( matrix_of_congo[i+1][j] == "E"|| matrix_of_congo[i+1][j] == "P"||matrix_of_congo[i+1][j] == "Z"){
		                    atb = atb + 1;
					    }
					    if( matrix_of_congo[i+1][j] == "L"){
				        	atb = atb + 10;
				        }
					    if((j+1) < 7){
							if( matrix_of_congo[i+1][j+1] == "E"|| matrix_of_congo[i+1][j+1] == "P"||matrix_of_congo[i+1][j+1] == "Z"){
								atb = atb + 1;
							}
							if( matrix_of_congo[i+1][j+1] == "L"){
								atb = atb + 10;
							}
					    }
					    if((j-1) >= 0){
							if(matrix_of_congo[i+1][j-1] == "E"|| matrix_of_congo[i+1][j-1] == "P"||matrix_of_congo[i+1][j-1] == "Z"){
								atb = atb + 1;
							}
							if( matrix_of_congo[i+1][j-1] == "L"){
								atb = atb + 10;
							}
					    }
    		        }
    		        if( i > 3){
    		      	    if(((i+1) < 7) && ((j+1) < 7)){
					        if(matrix_of_congo[i+1][j+1] == "E"|| matrix_of_congo[i+1][j+1] == "P"||matrix_of_congo[i+1][j+1] == "Z"){
						        atb = atb + 1;
					        }
					        if( matrix_of_congo[i+1][j+1] == "L"){
				        	     atb = atb + 10;
				                }
					    }
					    if(((i+1) < 7) && ((j-1) >= 0)){
					        if(matrix_of_congo[i+1][j-1] == "E"|| matrix_of_congo[i+1][j-1] == "P"||matrix_of_congo[i+1][j-1] == "Z"){
						        atb = atb + 1;
					        }
					        if( matrix_of_congo[i+1][j-1] == "L"){
							atb = atb + 10;
						}
					    }
					    if((i+1) < 7 ){
					        if(matrix_of_congo[i+1][j] == "E"|| matrix_of_congo[i+1][j] == "P"||matrix_of_congo[i+1][j] == "Z"){
						        atb = atb + 1;
					        }
					        if( matrix_of_congo[i+1][j] == "L"){
							atb = atb + 10;
						}
					    }
					    
    		        }
                }
			
				
			}
		   }
		   
	if(side_to_move == 'w'){
        	attacksc = attacksc + atw;
        }
	    if(side_to_move == 'b'){
		attacksc = attacksc + atb;
	    }
		   
		   //cout << blackmob << endl;
	int rawScore = 0;
	rawScore = total + mobilitysc + attacksc;
	
	cout << rawScore << endl;
   

    
    /*string side_to_play ="side to play: ";

    
    positions.push_back(white_zebra);
    positions.push_back(black_zebra);

    stringstream ss;
    string element;
    ss << side_to_move;
    ss >> element;
    if (element =="b"){
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
        //cout<<definitions[i];
        for (int j=0; j <positions[i].size(); j++)
        {   
            cout <<positions[i][j]<<" ";
        }
        if(positions.size() !=1){
         cout<<endl;
        }
    }
    //cout<<side_to_play<<endl;*/


    

    
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
    
    //if( )
return 0;
}
// 2
// gmelecz/ppppppp/7/7/7/PPPPPPP/GMELECZ w 0
// 1m1El2/P1P2P1/1S4C/4S2/1E3S1/1P3c1/2GL3 b 79
// 2l4/7/4z2/4c2/PP2EP1/3L2p/7 b 23

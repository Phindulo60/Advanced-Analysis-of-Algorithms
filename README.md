# Data-Visualization-and-Exploration
This repository will consist of all the programming assessments i had for a Wits University honours course(Data Visualization and Exploration)


## Congo Game Design and Implementation
Congo is a chess variant, invented by Demian Freeling at the age of seven in 1982. 

### Rules of the game
The Lion moves like a chessking, but may not leave his castle at his side of the river. In addition, lions can capture other lions if they `see' it, i.e., if 
there is a vertical or diagonal line with no pieces between the two lions, the lion may jump to the other lion and capture it.
The Giraffe moves and captures by jumping to the second square in a straight or diagonal direction. A jump cannot be blocked by interposing pieces of either color. 
In addition it has the king's move, without the right to capture with it.

The Monkey moves without capturing as a chessking, i.e., one square in an arbitrary direction, but captures by jumping a straight or diagonally adjacent piece, to 
the square immediately beyond, which must be vacant for the capture to take place. From there it may proceed in a similar fashion, free to switch from straight to 
diagonal jumps and vice versa. This is called 'multiple capture'. During a multiple capture the monkey may visit the same square more than once, but it may not capture 
the same piece more than once. After the completion of a multiple capture, all captured pieces are removed simultaneously. If Lion is captured, this terminates the move as well as the game.

The Elephant can move to the first and second square in a straight direction. The move to the second square is a jump and cannot be blocked by interposing pieces of either color.

The Crocodile moves and captures using the king's move, i.e., one square in an arbitrary direction. Outside the river it also can move on the file towards the 
river (including the river square) as a rook. Inside the river it also move to another river square as a rook. A crocodile cannot drown.

A Zebra moves like a knight in usual chess.

Pawns move and capture both straight and diagonally forward. Across the river a pawn may also move one or two squares straight back, without the right to capture or jump.

If a pawn moves to the last row, it is promoted to a Superpawn. A superpawn has the additional powers of moving and capturing one square straight sideways and going one 
or two square straight backwards or diagonally backward. When going backwards, it may neither capture nor jump. A superpawns right to go backwards does not depend on its 
position: they may go backwards at both sides and on the river.


The lion may not leave his castle.
In the middle of the board, there is a river. This river enhances the movement capabilities of the crocodile, as mentioned above. In addition, pieces other than 
the crocodile can drown in the river. It is allowed to move a piece other than the crocodile to the river. However, if the player does not move that piece out of 
the river at his next turn, then the piece `drowns' and is taken out of play.

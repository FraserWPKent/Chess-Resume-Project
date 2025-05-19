#include <cmath>
#include <iostream>
#ifndef BOARD_H
#define BOARD_H


/* Try to use bitboards to optimize this
 Resources Used to understand bitboards:
    https://www.chessprogramming.org/Bitboards#Bitboard_Basics
    https://en.wikipedia.org/wiki/Bitboard
    https://stackoverflow.com/questions/65806830/how-to-use-bitboards-in-chess
    https://stackoverflow.com/questions/21222905/generating-bitboard-masks-for-move?rq=3
    https://youtu.be/w4FFX_otR-4?si=gYaJDhGEYcgTFOCm

    /Project started on may 12th 2025
*/

class Board{
    private:
        // Bitboard variables to keep track of all black peices
        unsigned long long int blackKing;
        unsigned long long int blackQueens;
        unsigned long long int blackRooks;
        unsigned long long int blackKnights;
        unsigned long long int blackBishops;
        unsigned long long int blackPawns;

        // Bitboard variables to keep track of all white peices
        unsigned long long int whiteKing;
        unsigned long long int whiteQueens;
        unsigned long long int whiteRooks;
        unsigned long long int whiteKnights;
        unsigned long long int whiteBishops;
        unsigned long long int whitePawns;

        // General Vars
        bool whiteTurn;
        // int castlingRights;
        // int enPassant;
        unsigned long long int boardOccupied;

        void setBoard(){
            // Setting up the initial board state for a standard chess board. Maybe convert these to set numbers instead of pows
            blackRooks = (long long int)pow(2,63)+(long long int)pow(2,56);
            blackKnights = pow(2,62)+pow(2,57);
            blackBishops = pow(2,61) + pow(2,58);
            blackQueens = pow(2,60);
            blackKing = pow(2,59);
            blackPawns = 0;
            for(int x = 0; x < 8; x++){
                blackPawns += pow(2,55-x);
            }

            // Setting up white peices
            whiteRooks = pow(2,7)+pow(2,0);
            whiteKnights = pow(2,6)+pow(2,1);
            whiteBishops = pow(2,5) + pow(2,2);
            whiteQueens = pow(2,4);
            whiteKing = pow(2,3);
            whitePawns = 0;
            for(int x = 0; x < 8; x++){
                whitePawns += pow(2,8+x);
            }
            boardOccupied = 18446462598732906495;

            std::cout << whiteRooks << std::endl;

            
        }
    
    public:


        Board(){
            setBoard();
        }
        Board(const Board &copyBoard){

        }

        // Simple print board function for testint to see if the bit board works. May need optimiziation later.
        // Likeyly gonna switch to a non console format later on anyways
        void printBoard(){
            unsigned long long int power = 0;
            char cur = '0';
            for(int x = 63; x >= 0; x--){
                cur = '0';
                power = (unsigned long long int)pow(2,x);
                
                if((boardOccupied & power) > 0){
                    if(((power&whitePawns)|(power&blackPawns)) > 0){
                        cur = 'P';
                    }
                    else if(((power&whiteRooks)|(power&blackRooks))>0){
                        cur = 'R';
                    }
                    else if(((power&whiteKnights)|(power&blackKnights))>0){
                        cur = 'H';
                    }
                    else if(((power&whiteBishops)|(power&blackBishops))>0){
                        cur = 'B';
                    }
                    else if(((power&whiteQueens)|(power&blackQueens))>0){
                        cur = 'Q';
                    }
                    else if(((power&whiteKing)|(power&blackKing))>0){
                        cur = 'K';
                    }
                }
                std::cout << cur << " ";

                if(x%8 == 0){
                    std::cout << std::endl;
                }
            }

        }
        

};

#endif
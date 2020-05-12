//
// Created by pankaj on 12/05/20.
//

#include "TicTacToe.h"
#include<iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

TicTacToe::TicTacToe()
{
    //ctor
    game_finished=false;
    srand(time(0));
    if ( (rand() % 2 ) ==0 )
        player=HUMAN;
    else
        player=MACHINE;


}

TicTacToe::~TicTacToe()
{
    //dtor
}
int TicTacToe::changeTurn()
{
    player=player*-1;
    return 0;

}

int TicTacToe::displayBoard()
{
    int i,j,piece;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            piece=board[i][j];
            if(piece==100)
                cout<<"X ";
            else if (piece==200)
                cout<<"O ";
            else
                cout<<piece<<" ";

        }
        cout<<endl;

    }
    return 0;

}
bool TicTacToe::gameFinished()
{
    int i,j;
    int value=100;
    if (board[0][0]==value && board [0][1]==value && board [0][2] ==value)
        return true;
    if (board[1][0]==value && board [1][1]==value && board [1][2] ==value)
        return true;
    if (board[2][0]==value && board [2][1]==value && board [2][2] ==value)
        return true;
    if (board[0][0]==value && board [1][1]==value && board [2][2] ==value)
        return true;
    if (board[0][0]==value && board [1][0]==value && board [2][0] ==value)
        return true;
    if (board[0][1]==value && board [1][1]==value && board [2][1] ==value)
        return true;
    if (board[0][2]==value && board [1][2]==value && board [2][2] ==value)
        return true;
    if (board[2][0]==value && board [1][1]==value && board [0][2] ==value)
        return true;
    value=200;
    if (board[0][0]==value && board [0][1]==value && board [0][2] ==value)
        return true;
    if (board[1][0]==value && board [1][1]==value && board [1][2] ==value)
        return true;
    if (board[2][0]==value && board [2][1]==value && board [2][2] ==value)
        return true;
    if (board[0][0]==value && board [1][1]==value && board [2][2] ==value)
        return true;
    if (board[0][0]==value && board [1][0]==value && board [2][0] ==value)
        return true;
    if (board[0][1]==value && board [1][1]==value && board [2][1] ==value)
        return true;
    if (board[0][2]==value && board [1][2]==value && board [2][2] ==value)
        return true;
    if (board[2][0]==value && board [1][1]==value && board [0][2] ==value)
        return true;



    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            if (board[i][j]<10)
                return false;

    return true;

}
int TicTacToe::getPlayer()
{
    return player;

}
int  TicTacToe::getWinner()
{
    int i,j;
    int value=MACHINE_PIECE;
    if (board[0][0]==value && board [0][1]==value && board [0][2] ==value)
        return 1;
    if (board[1][0]==value && board [1][1]==value && board [1][2] ==value)
        return 1;
    if (board[2][0]==value && board [2][1]==value && board [2][2] ==value)
        return 1;
    if (board[0][0]==value && board [1][1]==value && board [2][2] ==value)
        return 1;
    if (board[0][0]==value && board [1][0]==value && board [2][0] ==value)
        return 1;
    if (board[0][1]==value && board [1][1]==value && board [2][1] ==value)
        return 1;
    if (board[0][2]==value && board [1][2]==value && board [2][2] ==value)
        return 1;
    if (board[2][0]==value && board [1][1]==value && board [0][2] ==value)
        return 1;
    value=HUMAN_PIECE;
    if (board[0][0]==value && board [0][1]==value && board [0][2] ==value)
        return -1;
    if (board[1][0]==value && board [1][1]==value && board [1][2] ==value)
        return -1;
    if (board[2][0]==value && board [2][1]==value && board [2][2] ==value)
        return -1;
    if (board[0][0]==value && board [1][1]==value && board [2][2] ==value)
        return -1;
    if (board[0][0]==value && board [1][0]==value && board [2][0] ==value)
        return -1;
    if (board[0][1]==value && board [1][1]==value && board [2][1] ==value)
        return -1;
    if (board[0][2]==value && board [1][2]==value && board [2][2] ==value)
        return -1;
    if (board[2][0]==value && board [1][1]==value && board [0][2] ==value)
        return -1;


    return 0;


}

bool TicTacToe::isMoveLegal(int move)
{
    int i,j,move_copy;
    move--;
    i=move/3;
    j= move %3;

    if (board[i][j]==move+1 )
        return true;
    return false;
}

int TicTacToe::makeMachineMove()
{
    int move,player;
    player=MACHINE;
    int i,j;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
        {
            move=i*3+j+1;
            if(isMoveLegal(move))
            {

                updateBoard(move,player);
                return 0;

            }


        }



    return 0;
}



int TicTacToe::makeMove(int player)
{
    int move;

    if (player==HUMAN)
    {
        do{
            cout<<"Enter your move :";
            cin>>move;


        }while(!isMoveLegal(move));
        changeTurn();

        updateBoard(move,player);
    }
    else{
        cout<<"Computers Turn"<<endl;
        minimax(MACHINE,0);

        changeTurn();


    }

    return 0;
}
int TicTacToe::max(int x, int y)
{
    if(x==UNINITIALIZED)
        return y;
    if (y>x)
        return y;
    return x;

}


int TicTacToe::min(int x, int y)
{
    if(x==UNINITIALIZED)
        return y;
    if (y<x)
        return y;
    return x;

}
int TicTacToe::minimax(int player,int depth)
{
    if (gameFinished())
    {
        int winner=getWinner();
        return winner*1000;


    }
    int move,movelist[9],movelist_count;
    int best_move,prev_bestmove;
    int best_score=UNINITIALIZED;
    int score=0,prev_bestscore;
    int i,j;
    movelist_count=0;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
        {
            move=i*3+j+1;
            if(isMoveLegal(move))
            {
                prev_bestmove=best_move;
                prev_bestscore=best_score;
                updateBoard(move,player);
                score=minimax(player*-1,depth+1);

                board[i][j]=i*3+j+1;

                if (player==MACHINE )
                {

                    best_score=max(best_score,score);
                    if(best_score==score){
                        if (best_score!=prev_bestscore)
                        {
                            best_move=move;

                            movelist[0]=move;
                            movelist_count=1;
                        }
                        else
                        {
                            best_move=move;
                            movelist[movelist_count]=move;
                            movelist_count++;


                        }}


                }
                else
                {
                    best_score=min(best_score,score);
                    if(best_score==score){
                        if (best_score!=prev_bestscore)
                        {
                            best_move=move;

                            movelist[0]=move;
                            movelist_count=1;
                        }
                        else
                        {
                            best_move=move;
                            movelist[movelist_count]=move;
                            movelist_count++;

                        }
                    }


                }




            }


        }

    if (depth==0)
    {

        best_move=pickBestMove(movelist,movelist_count);
        updateBoard(best_move,player);


    }
    return best_score;


}
int TicTacToe::pickBestMove(int movelist[],int movelist_count)
{
    return movelist[(rand() % movelist_count )];


}
int TicTacToe::setBoard()
{
    int i,j;
    int count=1;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            board[i][j]=count;
            count++;

        }


    }

    return 0;
}
int  TicTacToe::updateBoard(int move,int player)
{
    int i,j;

    move--;
    int piece=HUMAN_PIECE;
    if(player==MACHINE)
        piece=MACHINE_PIECE;
    i=move/3;
    j= move %3;
    board[i][j]=piece;
    return 0;
}
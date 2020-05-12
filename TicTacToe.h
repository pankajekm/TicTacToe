//
// Created by pankaj on 12/05/20.
//
#ifndef TICTACTOE_H
#define TICTACTOE_H

#define HUMAN -1
#define MACHINE 1
#define HUMAN_PIECE 100
#define MACHINE_PIECE 200
#define UNINITIALIZED -10000
class TicTacToe
{
public:

    TicTacToe();
    virtual ~TicTacToe();
    int changeTurn();
    int displayBoard();
    bool gameFinished();
    int getPlayer();

    int getWinner();
    bool isMoveLegal(int move);
    int makeMachineMove();
    int makeMove(int player);
    int max(int x,int y);
    int min(int x,int y);
    int minimax(int player,int depth);
    int pickBestMove(int movelist[],int movelist_count);

    int setBoard();
    int updateBoard(int move,int player);


protected:

private:
    int board[9][9];
    bool game_finished;
    int player;


};

#endif // TICTACTOE_H
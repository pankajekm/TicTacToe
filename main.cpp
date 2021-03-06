//Copyright (c) 2020, Pankaj Kumar G
//All rights reserved.
// SPDX-License-Identifier: BSD 3-Clause
#include <iostream>
#include "TicTacToe.h"

using namespace std;

int main()
{
    TicTacToe game;

    game.setBoard();

    while(!game.gameFinished())
    {
        game.displayBoard();

        if (game.getPlayer()==HUMAN)
            game.makeMove(HUMAN);
        else
            game.makeMove(MACHINE);


    }
    game.displayBoard();
    int winner=game.getWinner();
    cout<<"Game Status:" <<winner<<endl;

    return 0;
}
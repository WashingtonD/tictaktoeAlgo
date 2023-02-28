#include <iostream>
#include <vector>
#include <string>
#include <windows.h>

using namespace std;

const int z = 3; /// Z - constant weigth-value for new lines started by algo
const int x = 2; /// X - constant weigth-value for continued lines by algo
const int y = 1; /// Y - constant weigth-value for blocked lines for opponent
const string Empty = string(3,' ') + "|" + string(3,' ') + "|" + string(3,' ');
const string NotEmptyStart = " | ";

int getDecisionPoints(vector<int> board, int positionToMove);
void printBoard(vector<int> board);




/// Returns -1 if algo win || 1 if user win || 0 if draw || 2 if still possibility of turn
 int checkIfGameEnded(vector<int> board){
        /// Iterate each line for 3 symbols in row.
        /// Check if there is no empty cells
        if(board[1] + board[2] + board[3] == -3)
            return -1;
        else if(board[1] + board[2] + board[3] == 3)
            return 1;
        if(board[4] + board[5] + board[6] == -3)
            return -1;
        else if(board[4] + board[5] + board[6] == 3)
            return 1;
        if(board[7] + board[8] + board[9] == -3)
            return -1;
        else if(board[7] + board[8] + board[9] == 3)
            return 1;
        if(board[1] + board[4] + board[7] == -3)
            return -1;
        else if(board[1] + board[4] + board[7] == 3)
            return 1;
        if(board[2] + board[5] + board[8] == -3)
            return -1;
        else if(board[2] + board[5] + board[8] == 3)
            return 1;
        if(board[3] + board[6] + board[9] == -3)
            return -1;
        else if(board[3] + board[6] + board[9] == 3)
            return 1;
        if(board[1] + board[5] + board[9] == -3)
            return -1;
        else if(board[1] + board[5] + board[9] == 3)
            return 1;
        if(board[3] + board[5] + board[7] == -3)
            return -1;
        else if(board[3] + board[5] + board[7] == 3)
            return 1;
       for(int i = 1; i < board.size(); i++)
            if(board[i] == 0)
                return 2;
return 0;
}

vector<int> populateBoardAtTheBegining(){
    vector<int> emptyVector = vector<int>();
    for(int i = 0; i < 10; i++)
    {
        emptyVector.push_back(0);
    }
    emptyVector[0] = -1;
    for(int i =1;i<10;i++)
        emptyVector[i] = 0;
    return emptyVector;
}

 vector<int> getDecisionVector(vector<int> board){
    vector<int> decisionVector = populateBoardAtTheBegining(); /// All the 0s
    for(int i = 1; i < board.size(); i++){
        if(board[i] != 0)
            decisionVector[i] = -1;
        else
            decisionVector[i] = getDecisionPoints(board, i);
    }
    return decisionVector;
}

 int getDecisionPoints(vector<int> board, int positionToMove){
    int userLinesToBeStarted = 0;
    int userLinesToBeContinued = 0;
    int opponentLinesToBeBlocked = 0;
    switch(positionToMove){
        case 1:
        if((board[2] == -1 && board[3] == -1) || (board[4] == -1 && board[7] == -1) || (board[5] == -1 && board[9] == -1))
            return 100;
        if((board[2] == 1 && board[3] == 1) || (board[5] == 1 && board[9] == 1) || (board[4] == 1 && board[7] == 1))
            return 50;
        /// First line, positions: 1,2,3
        if(board[2] + board[3] == 1)
            opponentLinesToBeBlocked++;
        else if(board[2] == 0 && board[3] == 0)
            userLinesToBeStarted++;
        else if(board[2] + board[3] == -1)
            userLinesToBeContinued++;
        /// Second line, positions 1,5,9
        if(board[5] + board[9] == 1)
            opponentLinesToBeBlocked++;
        else if(board[5] == 0 && board[9] == 0)
            userLinesToBeStarted++;
        else if(board[5] + board[9] == -1)
            userLinesToBeContinued++;
        /// Third line, positions: 1,4,7
        if(board[4] + board[7] == 1)
            opponentLinesToBeBlocked++;
        else if(board[4] == 0 && board[7] == 0)
            userLinesToBeStarted++;
        else if(board[4] + board[7] == -1)
            userLinesToBeContinued++;
        return (userLinesToBeContinued * x) + (userLinesToBeStarted * z) + (opponentLinesToBeBlocked * y);
        break;
        case 2:
            if((board[1] == -1 && board[3] == -1) || (board[5] == -1 && board[8] == -1))
                return 100;
            if((board[1] == 1 && board[3] == 1) || (board[5] == 1 && board[8] == 1))
                return 50;
        /// First line, positions 1,2,3
        if(board[1] + board[3] == 1)
            opponentLinesToBeBlocked++;
        else if(board[1] == 0 && board[3] == 0)
            userLinesToBeStarted++;
        else if(board[1] + board[3] == -1)
            userLinesToBeContinued++;
        /// Second line, positions 2,5,8
        if(board[5] + board[8] == 1)
            opponentLinesToBeBlocked++;
        else if(board[5] == 0 && board[8] == 0)
            userLinesToBeStarted++;
        else if(board[5] + board[8] == -1)
            userLinesToBeContinued++;
        return (userLinesToBeContinued * x) + (userLinesToBeStarted * z) + (opponentLinesToBeBlocked * y);
        break;
        case 3:
        if((board[1] == -1 && board[2] == -1) || (board[6] == -1 && board[9] == -1) || (board[5] == -1 && board[7] == -1))
            return 100;
        if((board[1] == 1 && board[2] == 1) || (board[6] == 1 && board[9] == 1) || (board[5] == 1 && board[7] == 1))
            return 50;
        /// First line, positions: 1,2,3
        if(board[1] + board[2] == 1)
            opponentLinesToBeBlocked++;
        else if(board[1] == 0 && board[2] == 0)
            userLinesToBeStarted++;
        else if(board[1] + board[2] == -1)
            userLinesToBeContinued++;
        /// Second line, positions: 3,6,9
        if(board[6] + board[9] == 1)
            opponentLinesToBeBlocked++;
        else if(board[6] == 0 && board[9] == 0)
            userLinesToBeStarted++;
        else if(board[6] + board[9] == -1)
            userLinesToBeContinued++;
        /// Third line, positions: 3,5,7
        if(board[5] + board[7] == 1)
            opponentLinesToBeBlocked++;
        else if(board[5] == 0 && board[7] == 0)
            userLinesToBeStarted++;
        else if(board[5] + board[7] == -1)
            userLinesToBeContinued++;
        return (userLinesToBeContinued * x) + (userLinesToBeStarted * z) + (opponentLinesToBeBlocked * y);
        break;
        case 4:
        if((board[1] == -1 && board[7] == -1) || (board[5] == -1 && board[6] == -1))
            return 100;
        if((board[1] == 1 && board[7] == 1) || (board[5] == 1 && board[7] == 1))
            return 50;
        /// First line, positions: 1,4,7
        if(board[1] + board[7] == 1)
            opponentLinesToBeBlocked++;
        else if(board[1] == 0 && board[7] == 0)
            userLinesToBeStarted++;
        else if(board[1] + board[7] == -1)
            userLinesToBeContinued++;
        /// Second line, positions: 4,5,6
        if(board[5] + board[6] == 1)
            opponentLinesToBeBlocked++;
        else if(board[5] == 0 && board[6] == 0)
            userLinesToBeStarted++;
        else if(board[5] + board[6] == -1)
            userLinesToBeContinued++;
        return (userLinesToBeContinued * x) + (userLinesToBeStarted * z) + (opponentLinesToBeBlocked * y);
        break;
        case 5:
        if((board[1] == -1 && board[9] == -1) || (board[3] == -1 && board[7] == -1) ||
                (board[2] == -1 && board[8] == -1) || (board[4] == -1 && board[6] == -1))
            return 100;
        if((board[1] == 1 && board[9] == 1) || (board[3] == 1 && board[7] == 1) ||
                (board[2] == 1 && board[8] == 1) || (board[4] == 1 && board[6] == 1))
            return 50;
        /// First line, positions: 1,5,9
        if(board[1] + board[9] == 1)
            opponentLinesToBeBlocked++;
        else if(board[1] == 0 && board[9] == 0)
            userLinesToBeStarted++;
        else if(board[1] + board[9] == -1)
            userLinesToBeContinued++;
        /// Second line, positions: 3,5,7
        if(board[3] + board[7] == 1)
            opponentLinesToBeBlocked++;
        else if(board[3] == 0 && board[7] == 0)
            userLinesToBeStarted++;
        else if(board[3] + board[7] == -1)
            userLinesToBeContinued++;
        /// Third line, positions: 2,5,8
        if(board[2] + board[8] == 1)
            opponentLinesToBeBlocked++;
        else if(board[2] == 0 && board[8] == 0)
            userLinesToBeStarted++;
        else if(board[2] + board[8] == -1)
            userLinesToBeContinued++;
        /// Fourth line, positions: 4,5,6
        if(board[4] + board[6] == 1)
            opponentLinesToBeBlocked++;
        else if(board[4] == 0 && board[6] == 0)
            userLinesToBeStarted++;
        else if(board[4] + board[6] == -1)
            userLinesToBeContinued++;
        return (userLinesToBeContinued * x) + (userLinesToBeStarted * z) + (opponentLinesToBeBlocked * y);
        break;
        case 6:
        if((board[3] == -1 && board[9] == -1) || (board[4] == -1 && board[5] == -1))
            return 100;
        if((board[3] == 1 && board[9] == 1) || (board[4] == 1 && board[5] == 1))
            return 50;
        /// First Line, positions: 1,6,9
        if(board[1] + board[9] == 1)
            opponentLinesToBeBlocked++;
        else if(board[1] == 0 && board[9] == 0)
            userLinesToBeStarted++;
        else if(board[1] + board[9] == -1)
            userLinesToBeContinued++;
        /// Second Line, positions: 4,5,6
        if(board[5] + board[6] == 1)
            opponentLinesToBeBlocked++;
        else if(board[5] == 0 && board[6] == 0)
            userLinesToBeStarted++;
        else if(board[5] + board[6] == -1)
            userLinesToBeContinued++;
        return (userLinesToBeContinued * x) + (userLinesToBeStarted * z) + (opponentLinesToBeBlocked * y);
        break;
        case 7:
        if((board[1] == -1 && board[4] == -1) || (board[8] == -1 && board[9] == -1) || (board[5] == -1 && board[3] == -1))
            return 100;
        if((board[1] == 1 && board[4] == 1) || (board[8] == 1 && board[9] == 1) || (board[5] == -1 && board[3] == -1))
            return 50;
        /// First line, positions: 1,4,7
        if(board[1] + board[4] == 1)
            opponentLinesToBeBlocked++;
        else if(board[1] == 0 && board[4] == 0)
            userLinesToBeStarted++;
        else if(board[1] + board[4] == -1)
            userLinesToBeContinued++;
        /// Second line, positions: 7,8,9
        if(board[8] + board[9] == 1)
            opponentLinesToBeBlocked++;
        else if(board[8] == 0 && board[9] == 0)
            userLinesToBeStarted++;
        else if(board[8] + board[9] == -1)
            userLinesToBeContinued++;
        /// Third line, positions: 3,5,7
        if(board[3] + board[5] == 1)
            opponentLinesToBeBlocked++;
        else if(board[3] == 0 && board[5] == 0)
            userLinesToBeStarted++;
        else if(board[3] + board[5] == -1)
            userLinesToBeContinued++;
        return (userLinesToBeContinued * x) + (userLinesToBeStarted * z) + (opponentLinesToBeBlocked * y);
        break;
        case 8:
        if((board[7] == -1 && board[9] == -1) || (board[2] == -1 && board[5] == -1))
            return 100;
        if((board[7] == 1 && board[9] == 1) || (board[2] == 1 && board[5] == 1))
            return 50;
        /// First line, positions: 7,8,9
        if(board[7] + board[9] == 1)
            opponentLinesToBeBlocked++;
        else if(board[7] == 0 && board[9] == 0)
            userLinesToBeStarted++;
        else if(board[7] + board[9] == -1)
            userLinesToBeContinued++;
        /// Second line, positions: 2,5,8
        if(board[2] + board[5] == 1)
            opponentLinesToBeBlocked++;
        else if(board[2] == 0 && board[5] == 0)
            userLinesToBeStarted++;
        else if(board[2] + board[5] == -1)
            userLinesToBeContinued++;
        return (userLinesToBeContinued * x) + (userLinesToBeStarted * z) + (opponentLinesToBeBlocked * y);
        break;
        case 9:
        if((board[1] == -1 && board[5] == -1) || (board[7] == -1 && board[8] == -1) || (board[3] == -1 && board[6] == -1))
            return 100;
        if((board[1] == 1 && board[5] == 1) || (board[7] == 1 && board[8] == 1) || (board[3] == -1 && board[6] == -1))
            return 50;
        /// First line, positions: 3,6,9
        if(board[3] + board[6] == 1)
            opponentLinesToBeBlocked++;
        else if(board[3] == 0 && board[6] == 0)
            userLinesToBeStarted++;
        else if(board[3] + board[6] == -1)
            userLinesToBeContinued++;
        /// Second line, positions: 1,5,9
        if(board[1] + board[5] == 1)
            opponentLinesToBeBlocked++;
        else if(board[1] == 0 && board[5] == 0)
            userLinesToBeStarted++;
        else if(board[1] + board[5] == -1)
            userLinesToBeContinued++;
        /// Third line, positions: 7,8,9
        if(board[7] + board[8] == 1)
            opponentLinesToBeBlocked++;
        else if(board[7] == 0 && board[8] == 0)
            userLinesToBeStarted++;
        else if(board[7] + board[8] == -1)
            userLinesToBeContinued++;
        return (userLinesToBeContinued * x) + (userLinesToBeStarted * z) + (opponentLinesToBeBlocked * y);
        break;
    }
}

/// Default vector of board and vector of decision should have 10 positions, because of more readable indexes, so the first position will be -1;
 void game(){
    vector<int> board;
    board = populateBoardAtTheBegining();
    bool whosTurnToMove = false; // false => algoritms turn to move && true => user time to move
    while(checkIfGameEnded(board) == 2){
    if(!whosTurnToMove)
    {
         vector<int> decisionVector = getDecisionVector(board);
         int theBestMove = -1;
         for(int i = 1; i < decisionVector.size(); i++){
             if(decisionVector[i] > theBestMove)
                 theBestMove = i;
         }
         board[theBestMove] = -1;
         if(theBestMove == 100)
             break;
         whosTurnToMove = true;
    }
    else{
        /// User Logic of move.
        /// Get int position, check if possible and move.
        int number;
        while(true){
            cout << endl << "Where you want to move?";
            cin >> number;
            if(number >= 1 && number < 10 && board[number] == 0){
                board[number] = 1;
                whosTurnToMove = false;
                break;
            }
            else{
                cout << endl << "Incorect position, try again!";
                Sleep(1500);
                system("cls");
                printBoard(board);
            }
    }
  }
    system("cls");
    printBoard(board);
  switch(checkIfGameEnded(board))
  {
      case -1:
        cout << "Algo win";
        return;
      case 1:
        cout << "User win";
        return;
      case 0:
        cout << "There is a draw";
        return;
  }
}
}


void printBoard(vector<int> board){
    int i = 1;
    while(i < 10){
        cout << Empty << endl;
        cout << " ";
        if(board[i] == 1)
            cout << "O";
        else if(board[i] == -1)
            cout << "X";
        else
            cout << "*";
        cout << NotEmptyStart;
        i++;
        if(board[i] == 1)
            cout << "O";
        else if(board[i] == -1)
            cout << "X";
        else
            cout << "*";
        cout << NotEmptyStart;
        i++;
        if(board[i] == 1)
            cout << "O";
        else if(board[i] == -1)
            cout << "X";
        else
            cout << "*";
        i++;
        cout << endl << Empty << endl;
    }
}

int main(){
game();
return 0;
}

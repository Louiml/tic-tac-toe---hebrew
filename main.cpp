
#include <iostream>
using namespace std;
void displayBoard(char board[9])
{
    cout << endl;
    cout << "מצב מועצת המנהלים הנוכחי:" << endl;
    cout << endl;

    string SPACES = "       ";

    for (int row=0;row<3;row++)
    {
        cout<<SPACES;
        for (int col=0;col<3;col++)
        {
            if (col!=2)
            {
                cout<<board[col + row*3];
                cout<<'|';
            }
            else
            {
                cout << board[col + row*3]<<endl;
            }
        }

        cout<<SPACES;
        if (row!=2)
        {
            cout <<"-----"<<endl;
        }
        else
        {
            cout<<endl;
        }
    }
}


int main()
{
    int chosenSquare = 0;
    const char PLAYER_X ='X', PLAYER_O='O';
    char lastPlayer =PLAYER_O, currentPlayer=PLAYER_X;

    char board[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

    displayBoard(board);

    for (int session=0; session<9; session++)
    {
        cout << "מחשב " << currentPlayer <<", הזן אחד מהמספרים מהטבלה: ";
        cin >> chosenSquare;
        while ((chosenSquare<=0 || chosenSquare>9) || (board[chosenSquare-1]=='X' || board[chosenSquare-1]=='O'));
        {
            if (chosenSquare<=0 || chosenSquare>9)
            {
                cout <<"לא בחירה חוקית. נסה שוב."<<endl;
                cout << "מחשב " << currentPlayer <<", הזן אחד מהמספרים מהטבלה: ";
                cin >> chosenSquare;
            }
            else if (board[chosenSquare-1]=='X' || board[chosenSquare-1]=='O')
            {
                cout <<"הריבוע הזה לא זמין. נסה שוב."<<endl;
                cout << "מחשב " << currentPlayer <<", הזן אחד מהמספרים מהטבלה: ";
                cin >> chosenSquare;
            }
        }

        if(currentPlayer==PLAYER_X)
        {

            if (board[chosenSquare-1]!='X' && board[chosenSquare-1]!='O')
            {
                board[chosenSquare-1]='X';
            }
            swap(currentPlayer, lastPlayer);;
        }
        else
        {
            if (board[chosenSquare-1]!='X' && board[chosenSquare-1]!='O')
            {
                board[chosenSquare-1]='O';
            }
            swap(currentPlayer, lastPlayer);
        }
        displayBoard(board);
        if (board[0]==board[3] && board[3]==board[6])
        {
            cout << "מחשב " << lastPlayer <<  " מנצח בעמודה השמאלית!" <<endl;
            break;
        }
        else if (board[1]==board[4] && board[4]==board[7])
        {
            cout << "מחשב " << lastPlayer <<  " מנצח בעמודה האמצעית!" <<endl;
            break;
        }
        else if (board[2]==board[5] && board[5]==board[7])
        {
            cout << "מחשב " << lastPlayer <<  " מנצח בעמודה הימנית!" <<endl;
            break;
        }
        else if (board[0]==board[1] && board[1]==board[2])
        {
            cout << "מחשב " << lastPlayer <<  " מנצח בשורה העליונה!" <<endl;
            break;
        }
        else if (board[3]==board[4] && board[4]==board[5])
        {
            cout << "מחשב " << lastPlayer <<  " מנצח בשורה האמצעית!" <<endl;
            break;
        }
        else if (board[6]==board[7] && board[7]==board[8])
        {
            cout << "מחשב " << lastPlayer <<  " מנצח בשורה התחתונה!" <<endl;
            break;
        }
        else if (board[0]==board[4] && board[4]==board[8])
        {
            cout << "מחשב " << lastPlayer <<  " מנצח באלכסון כלפי מטה!" <<endl;
            break;
        }
        else if (board[2]==board[4] && board[4]==board[6])
        {
            cout << "מחשב " << lastPlayer <<  " מנצח באלכסון כלפי מעלה!" <<endl;
            break;
        }
        else if (session==8)
        {
            cout << " אף אחד לא מנצח." <<endl;
        }
    }
    cout << endl;
    return 0;
}

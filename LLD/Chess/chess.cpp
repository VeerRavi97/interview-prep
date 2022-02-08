
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// forward declarations
class ChessBoard;
class Player;
class Move;
class Cell;
class CellPosition;
class Piece;
class Account;
class Time;

// enums

enum Color
{
    BLACK,
    WHITE,
};

class Chess
{
    ChessBoard chessBoard;
    vector<Player> player;
    Player currentPlayer;
    vector<Move> movesList;
    GameStatus gameStatus;

public:
    bool playerMove(CellPosition fromPosition, CellPosition toPosition, Piece piece);
    bool endGame();
    void changeTurn();
};
class Player
{

    Account account;
    Color color;
    Time timeLeft;
};
class Time
{

    int mins;
    int secs;
};

class Account
{

    string username;
    string password;

    string name;
    string email;
    string phone;
};

enum GameStatus
{

    ACTIVE,
    PAUSED,
    FORTFEIGHT,
    BLACK_WIN,
    WHITE_WIN,
};

class ChessBoard
{

    vector<vector<Cell>> board;

public:
    void resetBoard();
    void updateBoard(Move move);
};
class Cell
{

    Color color;
    Piece piece;
    CellPosition position;
};

class CellPosition
{

    char ch;
    int i;
};

class Move
{

    Player turn;
    Piece piece;
    Piece killedPiece;
    CellPosition startPosition;
    CellPosition endPosition;
};

class Piece
{

    Color color;

public:
    bool move(CellPosition fromPosition, CellPosition toPosition);
    virtual vector<CellPosition> possibleMoves(CellPosition fromPosition);
    virtual bool validate(CellPosition fromPosition, CellPosition toPosition);
};
class Knight : public Piece
{

public:
    bool move(CellPosition fromPosition, CellPosition toPosition);
    vector<CellPosition> possibleMoves(CellPosition fromPosition);
    bool validate(CellPosition fromPosition, CellPosition toPosition);
};

class Bishop : Piece
{

public:
    bool move(CellPosition fromPosition, CellPosition toPosition);
    vector<CellPosition> possibleMoves(CellPosition fromPosition);
    bool validate(CellPosition fromPosition, CellPosition toPosition);
};

class rook : Piece
{

public:
    bool move(CellPosition fromPosition, CellPosition toPosition);
    vector<CellPosition> possibleMoves(CellPosition fromPosition);
    bool validate(CellPosition fromPosition, CellPosition toPosition);
};

class King : Piece
{

public:
    bool move(CellPosition fromPosition, CellPosition toPosition);
    vector<CellPosition> possibleMoves(CellPosition fromPosition);
    bool validate(CellPosition fromPosition, CellPosition toPosition);
};

class Queen : Piece
{

public:
    bool move(CellPosition fromPosition, CellPosition toPosition);
    vector<CellPosition> possibleMoves(CellPosition fromPosition);
    bool validate(CellPosition fromPosition, CellPosition toPosition);
};

class Pawn : Piece
{

public:
    bool move(CellPosition fromPosition, CellPosition toPosition);
    vector<CellPosition> possibleMoves(CellPosition fromPosition);
    bool validate(CellPosition fromPosition, CellPosition toPosition);
};
#ifndef BOARD_
#define BOARD_

enum class GameState {
    Ongoing,
    Victory,
    Defeat
};

class Board {
private:
    GameState state;
public:
    Board(int);
    void show_field(int x, int y);
    void mark_field(int x, int y);
    GameState get_state();
    friend std::ostream& operator<<(std::ostream& os, const Board& board);
};

class BoardCommand {
protected:
    int x, y;
public:
    virtual void execute(Board&) = 0;
    static std::unique_ptr<BoardCommand> parse(std::istream& is);
};


class ShowCommand : public BoardCommand {
public:
    ShowCommand(int x, int y);
    void execute(Board& board) override;
};

class MarkCommand : public BoardCommand {
public:
    MarkCommand(int x, int y);
    void execute(Board& board) override;
};

class UnknownCommand : public BoardCommand {
public:
    UnknownCommand();
    void execute(Board& board) override;
};

#endif

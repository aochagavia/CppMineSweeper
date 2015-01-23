#include "Board.h"

// The board itself
Board::Board(int) {
    this->state = GameState::Ongoing;
}

void Board::show_field(int x, int y) {

}

void Board::mark_field(int x, int y) {

}

GameState Board::get_state() {
    return this->state;
}

std::ostream& operator<<(std::ostream& os, const Board& board) {
    return os << "Printing board";
}

// Command related stuff
std::unique_ptr<BoardCommand> BoardCommand::parse(std::istream& is) {
    char type;
    int x, y;
    std::cin >> type >> x >> y;

    BoardCommand* cmd;
    switch (type) {
    case 'm':
        cmd = new MarkCommand(x, y);
        break;
    case 's':
        cmd = new ShowCommand(x, y);
        break;
    default:
        cmd = new UnknownCommand();
        break;
    }

    return std::unique_ptr<BoardCommand>(cmd);
}

ShowCommand::ShowCommand(int x, int y) { this->x = x; this->y = y; }

void ShowCommand::execute(Board& board) {
    board.show_field(this->x, this->y);
}

MarkCommand::MarkCommand(int x, int y) { this->x = x; this->y = y; }

void MarkCommand::execute(Board& board) {
    board.mark_field(this->x, this->y);
}

// The unknown command does nothing
UnknownCommand::UnknownCommand() { this->x = 0; this->y = 0; }
void UnknownCommand::execute(Board& board) {}

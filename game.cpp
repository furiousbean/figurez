#include "const.h"
#include "board.h"
#include "game.h"
#include <QPainter>

Game::Game(QPixmap *pixmap, GameParams *gp) {
    canvas = pixmap;
    Gp = gp;
    board = new Board(canvas, Gp);
    selected = 0;
    draw_grid();
    score = 0;
    board -> insert_new();
    update_score(0);
}

void Game::reset() {
    delete board;
    board = new Board(canvas, Gp);
    selected = 0;
    draw_grid();
    score = 0;
    board -> insert_new();
    update_score(0);
    emit repaint();
}

Game::~Game() {
    delete(board);
}

void Game::push_field(int Xpos, int Ypos) {
    if (selected) {
        if (board -> have_something(Xpos, Ypos)) {
            board -> remove_selection(Xsel, Ysel);
            board -> draw_selection(Xpos, Ypos);
            Xsel = Xpos; Ysel = Ypos; selected = 1;
        } else {
            int result = board -> move(Xsel, Ysel, Xpos, Ypos);
            if (!result) emit moveFailed(); else {
                int delta = board -> get_delta();
                if (delta) update_score(delta); else {
                    board -> insert_new();
                    board -> get_delta();
                }
                selected = 0;
            }
        }
    } else {
        if (board -> have_something(Xpos, Ypos)) {
            board -> draw_selection(Xpos, Ypos);
            Xsel = Xpos; Ysel = Ypos; selected = 1;
        }
    }
    emit repaint();
}

void Game::draw_grid() {
    QPainter painter(canvas);
    painter.fillRect(QRect(0, 0, canvas -> width(), canvas -> height()),  Qt::white);
    painter.setPen(QPen(Qt::gray, Gp -> get_LineWidth(), Qt::SolidLine, Qt::RoundCap,
        Qt::MiterJoin));
    for (int i = 0; i <= Gp -> get_W(); ++i)
        painter.drawLine(QPointF(i * (Gp -> get_CellWidth() + Gp -> get_LineWidth()) + Gp -> get_LineWidth() / 2, 0), 
            QPointF(i * (Gp -> get_CellWidth() + Gp -> get_LineWidth())  + Gp -> get_LineWidth() / 2, canvas -> height()));
    for (int i = 0; i <= Gp -> get_H(); ++i)
        painter.drawLine(QPointF(0, i * (Gp -> get_CellHeight() + Gp -> get_LineWidth()) + Gp -> get_LineWidth() / 2), 
            QPointF(canvas -> width(), i * (Gp -> get_CellHeight() + Gp -> get_LineWidth())  + Gp -> get_LineWidth() / 2));
}

void Game::update_score(int delta) {
    score += delta * Gp -> get_ScoreMultiplier();
    emit showScore(score);
}

int Game::get_score() {
    return score;
}

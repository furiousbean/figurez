#include "const.h"
#include "board.h"
#include "game.h"

Game::Game(QPixmap *pixmap, QStatusBar *statusbar, QLabel *label) {
    canvas = pixmap;
    infobar = statusbar;
    scorelabel = label;
    board = new Board(canvas);
    selected = 0;
    draw_grid();
    score = 0;
    board -> insert_new();
    update_score(0);
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
            if (!result) infobar -> showMessage("Can't move it: there's no way.", 2000); else {
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
}

void Game::draw_grid() {
    QPainter painter(canvas);
    painter.fillRect(QRect(0, 0, canvas -> width(), canvas -> height()),  Qt::white);
    painter.setPen(QPen(Qt::gray, LineWidth, Qt::SolidLine, Qt::RoundCap,
        Qt::MiterJoin));
    for (int i = 0; i <= W; i++)
        painter.drawLine(QPointF(i * (CellWidth + LineWidth) + LineWidth / 2, 0), 
            QPointF(i * (CellWidth + LineWidth)  + LineWidth / 2, canvas -> height()));
    for (int i = 0; i <= H; i++)
        painter.drawLine(QPointF(0, i * (CellHeight + LineWidth)  + LineWidth / 2), 
            QPointF(canvas -> width(), i * (CellHeight + LineWidth)  + LineWidth / 2));  
}

void Game::update_score(int delta) {
    score += delta * ScoreMultiplier;
    scorelabel -> setText("Score: " + QString::number(score));
}

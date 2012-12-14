#include "const.h"

GameParams::GameParams() : W(9), H(9), CellWidth(48), CellHeight(48), LineWidth(1), NewFCount(3), ScoreMultiplier(2) { }

GameParams::GameParams(int w, int h, int cellwidth, int cellheight, int linewidth, int newfcount, int scoremultiplier) {
        W = w;
        H = h;
        CellWidth = cellwidth;
        CellHeight = cellheight;
        LineWidth = linewidth;
        NewFCount = newfcount;
        ScoreMultiplier = scoremultiplier;
    }

int GameParams::get_W() const {return W;}
int GameParams::get_H() const {return H;}
int GameParams::get_CellWidth() const {return CellWidth;}
int GameParams::get_CellHeight() const {return CellHeight;}
int GameParams::get_LineWidth() const {return LineWidth;}
int GameParams::get_NewFCount() const {return NewFCount;}
int GameParams::get_ScoreMultiplier() const {return ScoreMultiplier;}

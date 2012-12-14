#ifndef CONST_H
#define CONST_H

class GameParams{
private:
    int W;
    int H;
    int CellWidth;
    int CellHeight;
    int LineWidth;
    int NewFCount;
    int ScoreMultiplier;

public:
    GameParams();

    GameParams(int w, int h, int cellwidth, int cellheight, int linewidth, int newfcount, int scoremultiplier);

    int get_W() const;
    int get_H() const;
    int get_CellWidth() const;
    int get_CellHeight() const;
    int get_LineWidth() const;
    int get_NewFCount() const;
    int get_ScoreMultiplier() const;
};
#endif //CONST_H
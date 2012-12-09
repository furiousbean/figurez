#include "figure.h"
#include "rectangle.h"
#include "diamond.h"
#include "hline.h"
#include "vline.h"
#include "const.h"
#include "board.h"
#include <QVector>
#include <QPair>
#include <cmath>


Board::Board(QPixmap *pixmap) {
	canvas = pixmap;
	for (int i = 0; i < W; i++)
		for (int j = 0; j < H; j++)
			field[i][j] = 0;
	delta = 0;
}

Board::~Board() {
	for (int i = 0; i < W; i++)
		for (int j = 0; j < H; j++)
			if (have_something(i, j)) delete(field[i][j]);
}

int Board::have_something(int Xpos, int Ypos) {
	return (field[Xpos][Ypos] != 0);
}

void Board::draw_selection(int Xpos, int Ypos) {
	field[Xpos][Ypos] -> draw_selection();
}

void Board::remove_selection(int Xpos, int Ypos) {
	field[Xpos][Ypos] -> remove_selection();
}

void Board::insert_new() {
	QVector<QPair<int, int> > LuckWheel;
	for (int i = 0; i < W; i++)
		for (int j = 0; j < H; j++)
			if (!have_something(i, j)) LuckWheel.push_back(qMakePair(i, j));
	for (int k = 0; k < NewFCount && !LuckWheel.isEmpty(); k++) {
		int p = rand() % LuckWheel.size();
		int frand = rand() % 4;
		switch(frand) {
		  case 0: field[LuckWheel[p].first][LuckWheel[p].second] = new Rectangle(canvas, LuckWheel[p].first, LuckWheel[p].second);
		  break;
		  case 1: field[LuckWheel[p].first][LuckWheel[p].second] = new Hline(canvas, LuckWheel[p].first, LuckWheel[p].second);
		  break;
		  case 2: field[LuckWheel[p].first][LuckWheel[p].second] = new Vline(canvas, LuckWheel[p].first, LuckWheel[p].second);
		  break;
		  case 3: field[LuckWheel[p].first][LuckWheel[p].second] = new Diamond(canvas, LuckWheel[p].first, LuckWheel[p].second);		  
	    }
		remove_figs(LuckWheel[p].first, LuckWheel[p].second);
		LuckWheel.remove(p);
	}
}

int Board::get_delta() {
	int tmp = delta; delta = 0;
	return tmp;
}

int Board::move(int Xold, int Yold, int Xnew, int Ynew) {
	int **markField = new int*[W];
	for (int i = 0; i < W; i++)
	  markField[i] = new int[H];
	for (int i = 0; i < W; i++)
		for (int j = 0; j < H; j++)
			markField[i][j] = have_something(i, j);

	rec_check(markField, Xold, Yold);
	int passed = markField[Xnew][Ynew];
    for (int i = 0; i < W; i++)
	    delete [] markField[i];
	delete [] markField;

	if (!passed) return 0;
	field[Xnew][Ynew] = field[Xold][Yold]; field[Xold][Yold] = 0;
	field[Xnew][Ynew] -> move(Xnew, Ynew);
	remove_figs(Xnew, Ynew);
	return 1;
}

void Board::rec_check(int ** markField, int Xpos, int Ypos) {
	markField[Xpos][Ypos] = 1;
	if (Xpos > 0 && ! markField[Xpos - 1][Ypos]) rec_check(markField, Xpos - 1, Ypos);
	if (Xpos < W - 1 && ! markField[Xpos + 1][Ypos]) rec_check(markField, Xpos + 1, Ypos);
	if (Ypos > 0 && ! markField[Xpos][Ypos - 1]) rec_check(markField, Xpos, Ypos - 1);
	if (Ypos < H - 1 && ! markField[Xpos][Ypos + 1]) rec_check(markField, Xpos, Ypos + 1);
}

void Board::remove_figs(int Xpos, int Ypos) {
	int **patternField = new int*[W];
	for (int i = 0; i < W; i++)
	  patternField[i] = new int[H];
	for (int i = 0; i < W; i++)
		for (int j = 0; j < H; j++)
			if (have_something(i, j))
			    patternField[i][j] = field[Xpos][Ypos] -> get_type() == field[i][j] -> get_type();
			else patternField[i][j] = 0;
	field[Xpos][Ypos] -> match_pattern(patternField);
	for (int i = 0; i < W; i++)
		for (int j = 0; j < H; j++)
			if (patternField[i][j] == -1) {
				delta++;
				delete field[i][j];
				field[i][j] = 0;
			}
    for (int i = 0; i < W; i++)
	    delete [] patternField[i];
	delete [] patternField;
}

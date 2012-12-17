#ifndef FIGURE_H
#define FIGURE_H

#include "const.h"

class QPixmap;

/*!
 * Asbtract figure class description
 */

class Figure {
protected:
    int Xpos, Ypos;
    QPixmap *canvas;
    const GameParams *Gp;
    virtual void show() = 0; /**< method which draw a figure */
    void hide(); /**< hides figure */
    void select(); /**< draw selection background */

public:
    Figure(QPixmap &ncanvas, const GameParams &gp, int nXpos, int nYpos);
    void draw_selection(); /**< makes figure selected */
    void remove_selection(); /**< makes figure unselected */
    void move(int nXPos, int nYPos); /**< repaints figure in new position */
    virtual void match_pattern(int ** pattern) const = 0; /**< returns matrix with remove positions */
    virtual int get_type() const = 0; /**< returns figure type */
    virtual ~Figure();
};

#endif //FIGURE_H

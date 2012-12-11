#ifndef FIGURE_H
#define FIGURE_H

class QPixmap;

/*!
 * Asbtract figure class description
 */

class Figure {
protected:
    int type, Xpos, Ypos;
    QPixmap *canvas;
    virtual void show() = 0; /**< method which draw a figure */
    void hide(); /**< hides figure */
    void select(); /**< draw selection background */

public:
    void draw_selection(); /**< makes figure selected */
    void remove_selection(); /**< makes figure unselected */
    void move(int nXPos, int nYPos); /**< repaints figure in new position */
    virtual void match_pattern(int ** pattern) = 0; /**< returns matrix with remove positions */
    int get_type(); /**< returns figure type */
    virtual ~Figure();
};

#endif //FIGURE_H

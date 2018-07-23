#ifndef SCOREBUTTON_H
#define SCOREBUTTON_H

#include <QObject>
#include <QLabel>
#include "../utility.h"

class ScoreButton : public QLabel
{
    Q_OBJECT

//Constructor
public:
    ScoreButton(QWidget * parent, ScoreSource scoreSource, bool normalizedLF);

//Variables
private:
    float score;
    bool learningMode, learningShow;
    bool isBestScore;
    ScoreSource scoreSource;
    bool normalizedLF;

//Metodos
private:
    void getScoreColor(int &r, int &g, int &b, float score);
    void draw();

protected:
    void enterEvent(QEvent *e) Q_DECL_OVERRIDE;
    void leaveEvent(QEvent *e) Q_DECL_OVERRIDE;
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;

public:
    void setScore(float score, bool isBest);
    void setLearningMode(bool value);
    void setLearningShow(bool value);
    void setNormalizedLF(bool value);

signals:
    void spreadLearningShow(bool value);
};

#endif // SCOREBUTTON_H

#ifndef CPP_QT_TPMINIPROJET_MYSCENE_H
#define CPP_QT_TPMINIPROJET_MYSCENE_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QKeyEvent>
#include <QPainter>
#include <QLabel>
#include <QTextEdit>
#include <QAudioFormat>
#include <QAudioSink>
#include <QFile>

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

class MyScene : public QGraphicsScene {
    Q_OBJECT
private :
    QString pseudo;
    double vitesse;
    QGraphicsPixmapItem* singe;
    QGraphicsTextItem* textScore;
    QGraphicsTextItem* textMeilleurScore;
    QTimer* timer1;
    QTimer* timer2;
    QTimer* timer3;
    QList<QGraphicsPixmapItem*> bananesList;
    QList<QGraphicsPixmapItem*> gorillesList;

public:
    static int nbrBananesRecup;
    static bool gameIsOn;
    MyScene(QString newPseudo = "pseudo", QObject* parent = nullptr);
    virtual ~MyScene();
    void keyPressEvent(QKeyEvent* event);
    void drawBackground(QPainter* painter, const QRectF &rect);
    void bestScore();
    void sonBananeManger();

public slots :
    void updateGame();
    void insererBananes();
    void insererGorilles();
};


#endif //CPP_QT_TPMINIPROJET_MYSCENE_H

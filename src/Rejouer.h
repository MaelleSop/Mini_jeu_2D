#ifndef MINIPROJET_REJOUER_H
#define MINIPROJET_REJOUER_H

#include <iostream>
#include <QtWidgets>
#include <QGraphicsProxyWidget>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QPainter>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QLabel>
#include <QGraphicsView>
#include <QMainWindow>
#include <QWidget>
#include <QScreen>

using namespace std;

class Rejouer : public QMainWindow{
    Q_OBJECT
private :
    QLabel* txt;
    QPushButton* rejouer;
    QString pseudo;
    QLabel* score;

public :
    Rejouer(QString newPseudo = "pseudo", QWidget* parent = nullptr);

public slots:
    void relancer();
};


#endif //MINIPROJET_REJOUER_H

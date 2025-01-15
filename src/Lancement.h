#ifndef MINIPROJET_LANCEMENT_H
#define MINIPROJET_LANCEMENT_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsProxyWidget>
#include <QTimer>
#include <QPainter>
#include <QPushButton>
#include <QSize>
#include <QLabel>
#include <QLineEdit>

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QMainWindow>


using namespace std;

class Lancement : public QMainWindow {
Q_OBJECT
private :
    QPushButton* bouton;
    QLineEdit* lineEdit;

public :
    Lancement(QWidget* parent = nullptr);

public slots :
    void recupPseudoPlay();
};


#endif //MINIPROJET_LANCEMENT_H

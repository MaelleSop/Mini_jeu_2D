#include "Rejouer.h"
#include "MainWindow.h"
#include "MyScene.h"


Rejouer::Rejouer(QString newPseudo, QWidget* parent) : QMainWindow(parent), pseudo(newPseudo){
    this->resize(500,840);

    QWidget* widget = new QWidget;

    QLabel* background = new QLabel(this);
    background->setPixmap(QPixmap("img/fond_jungle"));
    background->setGeometry(QRect(0, 0, this->width(), this->height()));
    background->setAttribute(Qt::WA_TransparentForMouseEvents);

    QVBoxLayout* layout = new QVBoxLayout();
    widget->setLayout(layout);

    //QLabel message
    this->txt = new QLabel("Vous avez perdu !");
    QFont font("Arial", 32);
    this->txt->setFont(font);
    this->txt->setStyleSheet("font-weight: bold;");
    layout->addWidget(txt);

    //QLabel qui affiche le score
    int nbrBananes = MyScene::nbrBananesRecup;
    this->score = new QLabel();
    QString txtScore = "Score : " + QString::number(nbrBananes);
    this->score->setText(txtScore);
    QFont font2("Arial", 32);
    this->score->setFont(font2);
    this->score->setStyleSheet("font-weight: bold;");
    layout->addWidget(score);

    //Bouton rejouer
    this->rejouer = new QPushButton();
    QPixmap pixmap("img/rejouer.png"); // Chemin vers l'image
    QIcon icon(pixmap);
    this->rejouer->setIcon(icon);
    this->rejouer->setIconSize(pixmap.size());
    connect(rejouer, SIGNAL(clicked()), this, SLOT(relancer()));
    layout->addWidget(rejouer);

    layout->setAlignment(Qt::AlignCenter);
    widget->setLayout(layout);
    this->setCentralWidget(widget);
}

void Rejouer::relancer(){
    close();
    MainWindow* mainWindow = new MainWindow(pseudo, this);
    mainWindow->show();
}

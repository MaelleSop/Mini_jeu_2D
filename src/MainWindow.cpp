#include "MainWindow.h"
#include "Utils.h"

MainWindow::MainWindow(QString newPseudo, QWidget *parent) : QMainWindow(parent), pseudo(newPseudo){

    this->mainScene = new MyScene(newPseudo);
    this->mainView = new QGraphicsView;
    this->mainView->setScene(mainScene);

    this->setCentralWidget(mainView);
    this->setWindowTitle("My main window");
    this->setFixedSize(500, 840);

    timer1 = new QTimer(this);
    connect(timer1, SIGNAL(timeout()), this, SLOT(update()));
    timer1->start(10);

    regleMenu = menuBar()->addMenu(tr("&Regle"));
    QAction* actionRegle = new QAction(tr("&About"), this);
    connect(actionRegle, SIGNAL(triggered()), this, SLOT(slot_aboutRegle()));
    regleMenu->addAction(actionRegle);
}

MainWindow::~MainWindow(){
    delete mainScene;
}

void MainWindow::update(){
    bool valuePerdu = MyScene::gameIsOn;
    if(!valuePerdu){
        close();
        MyScene::gameIsOn = true;
        Rejouer* windowRejouer = new Rejouer(pseudo);
        windowRejouer->show();
    }
}

void MainWindow::slot_aboutRegle(){
    QMessageBox regles;
    regles.setText("Voici les règles du jeu :\nL'objectif du petit singe est de mangé le plus de bananes possible en esquivant le méchant gorille. S'il vous attrape vous avez perdu. Attention à vous, plus vous mangez de bananes, plus la vitesse augmente. ");
    regles.setModal(true);
    regles.exec();
}

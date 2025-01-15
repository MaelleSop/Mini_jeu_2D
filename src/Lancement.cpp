#include <QBoxLayout>
#include <QGroupBox>
#include <QLineEdit>
#include "Lancement.h"
#include "MainWindow.h"


Lancement::Lancement(QWidget* parent) : QMainWindow(parent){
    this->resize(500,800);

    this->setWindowTitle("Bienvenue !");

    QWidget* mainWidget = new QWidget();

    QLabel* background = new QLabel(this);
    background->setPixmap(QPixmap("img/fond_jungle"));
    background->setGeometry(QRect(0, 0, this->width(), this->height()));
    background->setAttribute(Qt::WA_TransparentForMouseEvents);

    QVBoxLayout* layout = new QVBoxLayout();

    QLabel* nom = new QLabel("Banana Feast");
    nom->setStyleSheet("font-weight: bold; color: yellow;");
    QFont nomFont("Arial",36);
    nom->setFont(nomFont);
    nom->setAlignment(Qt::AlignCenter);
    layout->addWidget(nom);

    QLabel* txtScore = new QLabel("Meilleur score actuel : ");
    txtScore->setStyleSheet("font-weight: bold;");
    QFont txtFont("Arial",24);
    txtScore->setFont(txtFont);
    txtScore->setAlignment(Qt::AlignCenter);
    layout->addWidget(txtScore);

    QFile file("fichier/scores.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        int numeroLigne = 2;
        QTextStream in(&file);
        QString ligne;
        for (int i = 1; i <= numeroLigne; ++i) {
            ligne = in.readLine();
            if(i == numeroLigne){
                QLabel* meilleurScore = new QLabel;
                meilleurScore->setText(ligne);
                meilleurScore->setStyleSheet("font-weight: bold;");
                QFont fontScore("Arial",24);
                meilleurScore->setFont(fontScore);
                meilleurScore->setAlignment(Qt::AlignCenter);
                layout->addWidget(meilleurScore);
                break;
            }
        }
        file.close();
    }

    this->bouton = new QPushButton("Play");
    this->bouton->setFixedSize(450,30);
    QLabel* pseudo = new QLabel("Entrer un pseudo :");
    pseudo->setStyleSheet("font-weight: bold;");
    QFont font("Arial", 32);
    pseudo->setFont(font);
    this->lineEdit = new QLineEdit();
    this->lineEdit->setFixedSize(450,30);

    layout->addWidget(pseudo);
    layout->addWidget(lineEdit);
    layout->addWidget(bouton);

    connect(bouton, SIGNAL(clicked()), this, SLOT(recupPseudoPlay()));

    layout->setAlignment(Qt::AlignCenter);
    mainWidget->setLayout(layout);
    this->setCentralWidget(mainWidget);
}

void Lancement::recupPseudoPlay() {
    QString Qpseudo = lineEdit->text();

    close();

    MainWindow* mainWindow = new MainWindow(Qpseudo,this);
    mainWindow->show();
}

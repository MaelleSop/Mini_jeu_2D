#include <QApplication>
#include "MainWindow.h"
#include "Lancement.h"


int main(int argc, char *argv[]) {
    QApplication application(argc, argv);
    Lancement pageLancement;
    pageLancement.show();
    return application.exec();
}

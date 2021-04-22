//This is the main function

#include <QApplication>

#include "_GM.h"

_GM * game;

int main(int argc, char *argv[])
{    
    QApplication a(argc, argv);
    game = new _GM();
    game->show();

    return a.exec();
}

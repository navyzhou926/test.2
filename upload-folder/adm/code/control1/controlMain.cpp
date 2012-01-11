
#include <QApplication>

#include "controlwin.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    ControlWin *win = new ControlWin;
    win->resize(1,1);;


    app.exec();
}

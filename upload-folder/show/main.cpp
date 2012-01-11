
#include <QApplication>
#include "frame.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    Frame frm;
    frm.show();

    return app.exec();
}

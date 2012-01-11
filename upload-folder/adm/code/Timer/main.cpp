
#include <QApplication>
#include "mylabel.h"



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

   MyLabel *label = new MyLabel;
   label->show();

    app.exec();
}

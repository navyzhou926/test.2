#include <QApplication>
#include <QLabel>

int main(int argc, char * argv[])
{
	QApplication app(argc, argv);

	QLabel *win = new QLabel("<center><font color = #0000ff><h1><i>Waiting order....</i>""</font></h1></center>");
	win->resize(800,480);
	win->show();

	app.exec();
}

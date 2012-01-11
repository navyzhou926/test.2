#include <stdio.h>
#include <QApplication>
#include <QLabel>

int main(int argc, char * argv[])
{
	QApplication app(argc, argv);

	//QString str = "<center><font color = #0000ff><h1><i>Sync files finished <br> Start to play after 3 seconds</i>""</font></h1></center>";
	QString str = "hello word";

	QLabel *win = new QLabel();
	win->resize(800,480);
	win->show();
	printf("show execut \n");
	win->setText(str);
	sleep(3);
	//QString strNew = win->text();
	//win->setText(strNew+str);
	sleep(3);
//	win->font("<center><font color = #0000ff><h1><i>Sync files finished <br> Start to play after 1 second</i>""</font></h1></center>");
	sleep(1);

	app.exec();
}

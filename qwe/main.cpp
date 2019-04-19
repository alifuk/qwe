#include "mainpage.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Mainpage w;
	w.show();
	return a.exec();
}

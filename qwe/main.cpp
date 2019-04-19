#include "qwe.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	qwe w;
	w.show();
	return a.exec();
}

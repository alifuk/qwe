#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_main_page.h"

class Mainpage : public QMainWindow
{
	Q_OBJECT

public:
	Mainpage(QWidget *parent = Q_NULLPTR);

public slots:
	void muj();
	void fit();
private:
	Ui::MainpageClass ui;
	QGraphicsScene* scene;
	float f_zoom;
protected:
	bool Mainpage::eventFilter(QObject *obj, QEvent *event);
};

#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_main_page.h"

class Mainpage : public QMainWindow
{
	Q_OBJECT

public:
	Mainpage(QWidget *parent = Q_NULLPTR);

private:
	Ui::MainpageClass ui;
	QGraphicsScene scene;
};

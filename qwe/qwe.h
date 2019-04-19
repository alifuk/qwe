#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_qwe.h"

class qwe : public QMainWindow
{
	Q_OBJECT

public:
	qwe(QWidget *parent = Q_NULLPTR);

private:
	Ui::qweClass ui;
};

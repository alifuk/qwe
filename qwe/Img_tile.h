#pragma once

#include <QWidget>
#include "ui_Img_tile.h"

class Img_tile : public QWidget
{
	Q_OBJECT

public:
	Img_tile(QWidget *parent = Q_NULLPTR);
	~Img_tile();

private:
	Ui::Img_tile ui;
};

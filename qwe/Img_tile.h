#pragma once

#include <QWidget>
#include "ui_Img_tile.h"

class Img_tile : public QWidget
{
	Q_OBJECT

public:
	Img_tile(std::string filepath, QWidget *parent = Q_NULLPTR);
	~Img_tile();

	std::string filepath;

private:
	Ui::Img_tile ui;
	int a;
	QGraphicsScene* scene;
};

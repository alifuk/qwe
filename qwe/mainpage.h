#pragma once

#include <QtWidgets/QMainWindow>

#include "ui_main_page.h"
#include "krokosled.h"

using namespace std;

class Mainpage : public QMainWindow
{
	Q_OBJECT

public:
	Mainpage(QWidget *parent = Q_NULLPTR);
	krokosled getSelectedState();

public slots:
	void fit();
	void add_image();
	void add_step();
	void add_state();
	void delete_state();
private:
	Ui::MainpageClass ui;
	QGraphicsScene* scene;
	float f_zoom;
	vector<krokosled> states;
	int number_of_states;

protected:
	bool Mainpage::eventFilter(QObject *obj, QEvent *event); 
	virtual void keyPressEvent(QKeyEvent * event);
};

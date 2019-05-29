#pragma once

#include <QtWidgets/QMainWindow>

#include "ui_main_page.h"
#include "krokosled.h"
#include "StateListModel.h"

using namespace std;

class Mainpage : public QMainWindow
{
	Q_OBJECT

public:
	Mainpage(QWidget *parent = Q_NULLPTR);
	Krokosled getSelectedState();

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

	vector<string> filepaths;
	string getSelectedFilepath();

	StateListModel* state_list_model;

protected:
	bool Mainpage::eventFilter(QObject *obj, QEvent *event); 
	virtual void keyPressEvent(QKeyEvent * event);
};

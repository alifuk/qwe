#pragma once

#include <QtWidgets/QMainWindow>

#include "ui_main_page.h"
#include "krokosled.h"
#include "StateListModel.h"

using namespace std;

enum steps_type
{
	rotate,
	resize
};

class Mainpage : public QMainWindow
{
	Q_OBJECT

public:
	Mainpage(QWidget *parent = Q_NULLPTR);
	Krokosled getSelectedState();

public slots:
	void fit();
	void add_image();
	void show_steps();
	void add_step(steps_type name_of_step);
	void add_state();
	void hide_step_selector();
	void delete_state();

	void show_pure_img();
private:
	Ui::MainpageClass ui;
	QGraphicsScene* scene;
	float f_zoom;
	int number_of_steps;

	vector<string> filepaths;
	string getSelectedFilepath();

	StateListModel* state_list_model;
	Krokosled* Mainpage::getCurrentKrokosled();

protected:
	bool Mainpage::eventFilter(QObject *obj, QEvent *event); 
	virtual void keyPressEvent(QKeyEvent * event);
};

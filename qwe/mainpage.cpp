#include "mainpage.h"
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"

#include "qfiledialog.h"
#include "qgraphicssceneevent.h"
#include "qmessagebox.h"

#include "Img_tile.h"
#include "StateListModel.h"

#include <QKeyEvent>

void Mainpage::keyPressEvent(QKeyEvent* event)
{
	//QKeyEvent eve = &event;
	if (event->key() == Qt::Key_D)
	{
		getSelectedFilepath();
		int a = 8;
		//myLabel->setText("You pressed ESC");
	}
	else {
		QMainWindow::keyPressEvent(event);
	}

}


void Mainpage::add_image() {

	QFileDialog d(this);
	d.setFileMode(QFileDialog::ExistingFiles);
	if (d.exec()) {
		QStringList files = d.selectedFiles();
		for (int i = 0; i < files.length(); i++) {
			std::string filepath = files[i].toStdString();
			auto iterator = std::find(filepaths.begin(), filepaths.end(), filepath);
			if (iterator != filepaths.end()) {
				QMessageBox* mb = new QMessageBox();
				mb->setText(QString::fromStdString( filepath + " already in list"));
				mb->exec();
				continue;
			}

			//QListWidgetItem* m = new QListWidgetItem(tr(files[i].toLocal8Bit().data()), ui.listWidget);
			filepaths.push_back(filepath);

			QListWidgetItem* fileitem = new QListWidgetItem();
			Img_tile* tile = new Img_tile(filepath, this);
			ui.lw_basefiles->addItem(fileitem);
			fileitem->setSizeHint(QSize(tile->width(), tile->height()));
			ui.lw_basefiles->setItemWidget(fileitem, tile);
		}
	}
}

void Mainpage::show_steps()
{
	ui.frame->show();
}

void Mainpage::add_step()
{
	QPushButton* buttonSender = qobject_cast<QPushButton*>(sender()); // retrieve the button you have clicked
	QString buttonText = buttonSender->text();
	QMessageBox mb;
	mb.setText(buttonText);
	mb.exec();
}

void Mainpage::add_state()
{
	state_list_model->addState();

}

void Mainpage::hide_step_selector()
{
	ui.frame->hide();
}

void Mainpage::delete_state()
{
}

void Mainpage::show_pure_img()
{
	string filepath = getSelectedFilepath();


	cv::Mat img;
	img = cv::imread(filepath, 0);

	auto items = scene->items();
	int numma = items.size();

	if (numma == 1) {
		scene->removeItem(items.at(0));
	}

	QPixmap p = QPixmap::fromImage(QImage(img.data, img.cols, img.rows, QImage::Format_Grayscale8));
	QPixmap* pi = &p;
	scene->addPixmap(*pi);
	scene->setSceneRect(0, 0, img.cols, img.rows);
	if (!ui.cb_keep_zoom->isChecked()) {
		fit();
	}

}


void Mainpage::fit() {
	this->ui.graphicsView->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
}

Mainpage::Mainpage(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	connect(ui.btn_load_img, SIGNAL(clicked()), this, SLOT(add_image()));
	connect(ui.btn_add_step, SIGNAL(clicked()), this, SLOT(show_steps()));
	connect(ui.btn_add_state, SIGNAL(clicked()), this, SLOT(add_state()));
	connect(ui.btn_hide, SIGNAL(clicked()), this, SLOT(hide_step_selector()));

	connect(ui.lw_basefiles, SIGNAL(itemSelectionChanged()), this, SLOT(show_pure_img()));

	connect(ui.btn_add_krok_load_image, SIGNAL(clicked()), this, SLOT(add_step()));


	connect(ui.btn_fit, SIGNAL(clicked()), this, SLOT(fit()));
	ui.graphicsView->setEnabled(true);

	state_list_model = new StateListModel();
	ui.lv_states->setModel(state_list_model);

	filepaths = vector<string>();
		
	ui.graphicsView->setDragMode(QGraphicsView::DragMode::ScrollHandDrag);
	ui.graphicsView->scale(1.1, 1.1);
	f_zoom = 1;
	scene = new QGraphicsScene();
	scene->installEventFilter(this);

	ui.graphicsView->setScene(scene);
	ui.graphicsView->show();

	//connect(scene, SIGNAL(wheelEvent(QWheelEvent* evente)), this, SLOT(zoom()));

	
}

string Mainpage::getSelectedFilepath()
{
	QListWidgetItem* selected = ui.lw_basefiles->selectedItems()[0];
	//ui.lw_basefile
	Img_tile* wid = (Img_tile*)ui.lw_basefiles->itemWidget(selected);
	return wid->filepath;
}

bool Mainpage::eventFilter(QObject *obj, QEvent *event) {
	if (event->type() == QEvent::GraphicsSceneWheel) {
		QGraphicsSceneWheelEvent* a = static_cast<QGraphicsSceneWheelEvent*> (event);
		int d = a->delta();
		if (d > 0) {
			ui.graphicsView->scale(1.1, 1.1);
		}
		else {
			ui.graphicsView->scale(0.9, 0.9);
		}
		event->accept();
		return true;
	}

	if (event->type() == QEvent::KeyPress) {
		//QKeyEvent* key = static_cast<QKeyEvent*>(event);
		int d = 8;
	}
	return false;
}
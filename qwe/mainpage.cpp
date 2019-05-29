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

void Mainpage::add_step()
{

	/*
	QMessageBox msgBox;
	msgBox.setText("The document has been modified.");
	msgBox.exec();
	*/
}

void Mainpage::add_state()
{
	state_list_model->addState();

}

void Mainpage::delete_state()
{
}


void Mainpage::fit() {
	this->ui.graphicsView->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
}

Mainpage::Mainpage(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	connect(ui.btn_load_img, SIGNAL(clicked()), this, SLOT(add_image()));
	connect(ui.btn_add_step, SIGNAL(clicked()), this, SLOT(add_step()));
	connect(ui.btn_add_state, SIGNAL(clicked()), this, SLOT(add_state()));

	connect(ui.btn_fit, SIGNAL(clicked()), this, SLOT(fit()));
	ui.graphicsView->setEnabled(true);

	state_list_model = new StateListModel();
	ui.lv_states->setModel(state_list_model);

	filepaths = vector<string>();

	//cv::Mat* img = new cv::Mat(1000, 2000, CV_8UC1, cv::Scalar(80));
	cv::Mat img;
	img = cv::imread("computar.png",0);
	
	ui.graphicsView->setDragMode(QGraphicsView::DragMode::ScrollHandDrag);
	ui.graphicsView->scale(1.1, 1.1);
	f_zoom = 1;
	scene = new QGraphicsScene();
	scene->installEventFilter(this);

	//connect(scene, SIGNAL(wheelEvent(QWheelEvent* evente)), this, SLOT(zoom()));

	QPixmap p = QPixmap::fromImage(QImage(img.data, img.cols, img.rows, QImage::Format_Grayscale8));
	QPixmap* pi = &p;
	scene->addPixmap(*pi);

	ui.graphicsView->setScene(scene);
	
	ui.graphicsView->show();

	//ui.graphicsView->fitInView(scene.sceneRect(), Qt::KeepAspectRatio);
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
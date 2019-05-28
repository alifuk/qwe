#include "mainpage.h"
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "qfiledialog.h"
#include "qgraphicssceneevent.h"

#include "Img_tile.h"


void Mainpage::load_image() {

	QFileDialog d(this);
	d.setFileMode(QFileDialog::ExistingFiles);
	if (d.exec()) {
		QStringList files = d.selectedFiles();
		//files.at(0);
		for (int i = 0; i < files.length(); i++) {
			std::string filepath = files[i].toStdString();
			//QListWidgetItem* m = new QListWidgetItem(tr(files[i].toLocal8Bit().data()), ui.listWidget);

			QListWidgetItem* myit = new QListWidgetItem();
			Img_tile* tile = new Img_tile(filepath, this);
			ui.listWidget_2->addItem(myit);

			myit->setSizeHint(QSize(tile->width(), tile->height()));
			ui.listWidget_2->setItemWidget(myit, tile);
		}
	}
}

void Mainpage::muj() {
	

	//QListWidgetItem 
	//QListWidgetItem* m = new QListWidgetItem(tr("asd"), ui.listWidget);
}

void Mainpage::fit() {
	this->ui.graphicsView->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
}

Mainpage::Mainpage(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	connect(ui.btn_load_img, SIGNAL(clicked()), this, SLOT(load_image()));

	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(muj()) );
	connect(ui.btn_fit, SIGNAL(clicked()), this, SLOT(fit()));
	ui.graphicsView->setEnabled(true);

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
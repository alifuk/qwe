#include "mainpage.h"
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "qfiledialog.h"

void Mainpage::muj() {

	//QListWidgetItem 
	this->ui.pushButton->setText("asdss");
	QFileDialog d(this);
	d.exec();


	//QListWidgetItem* m = new QListWidgetItem(tr("asd"), ui.listWidget);
}

Mainpage::Mainpage(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(muj()) );
	//cv::Mat* img = new cv::Mat(1000, 2000, CV_8UC1, cv::Scalar(80));
	cv::Mat img;
	img = cv::imread("computar.png",0);
	

	QGraphicsScene* scene = new QGraphicsScene();
	QPixmap p = QPixmap::fromImage(QImage(img.data, img.cols, img.rows, QImage::Format_Grayscale8));
	QPixmap* pi = &p;
	scene->addPixmap(*pi);

	ui.graphicsView->setScene(scene);
	
	ui.graphicsView->show();

	//ui.graphicsView->fitInView(scene.sceneRect(), Qt::KeepAspectRatio);
}

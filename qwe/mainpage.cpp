#include "mainpage.h"
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"


Mainpage::Mainpage(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	cv::Mat* img = new cv::Mat(1000, 2000, CV_8UC1, cv::Scalar(80));

	//cv::Mat temp; // make the same cv::Mat
	//cvtColor(img, temp, CV_BGR2RGB); // cvtColor Makes a copt, that what i need
	
	QImage dest((const uchar *)(*img).data, (*img).cols, (*img).rows, (*img).step, QImage::Format_Grayscale8);
	dest.bits();

	QGraphicsScene* scene = new QGraphicsScene();
	QPixmap* pixmap = new QPixmap("C:/img.jpg");
	//QPixmap* pixmap = QPixmap::fromImage( dest );
	//QPixmap pixmap = QPixmap::fromImage(dest);
	//scene.addPixmap(QPixmap::fromImage(dest));
	scene->addPixmap(*pixmap);

	ui.graphicsView->setScene(scene);
	
	ui.graphicsView->show();

	//ui.graphicsView->fitInView(scene.sceneRect(), Qt::KeepAspectRatio);
}

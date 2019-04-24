#include "mainpage.h"
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"


Mainpage::Mainpage(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//cv::Mat* img = new cv::Mat(1000, 2000, CV_8UC1, cv::Scalar(80));
	cv::Mat img;
	img = cv::imread("computar.png",0);
	//cv::Mat temp; // make the same cv::Mat
	//cvtColor(img, temp, CV_BGR2RGB); // cvtColor Makes a copt, that what i need
	

	QGraphicsScene* scene = new QGraphicsScene();
	QPixmap p = QPixmap::fromImage(QImage(img.data, img.cols, img.rows, QImage::Format_Grayscale8));
	QPixmap* pi = &p;
	scene->addPixmap(*pi);

	ui.graphicsView->setScene(scene);
	
	ui.graphicsView->show();

	//ui.graphicsView->fitInView(scene.sceneRect(), Qt::KeepAspectRatio);
}

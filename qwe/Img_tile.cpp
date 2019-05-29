#include "Img_tile.h"

#include "opencv2/core.hpp"
#include "opencv2/imgcodecs.hpp"

using namespace std;
using namespace cv;

Img_tile::Img_tile(std::string _filepath, QWidget *parent)
	: QWidget(parent)
{
	ui = Ui::Img_tile();
	ui.setupUi(this);
	filepath = _filepath;

	ui.lbl_name->setText(QString::fromStdString(filepath));
	ui.lbl_name->setToolTip(QString::fromStdString(filepath));

	Mat thumb = imread(filepath);
	QPixmap p = QPixmap::fromImage(QImage(thumb.data, thumb.cols, thumb.rows, QImage::Format_Grayscale8));
	QPixmap* pi = &p;


	scene = new QGraphicsScene();
	scene->addPixmap(*pi);

	ui.graphicsView->setScene(scene);
	ui.graphicsView->show();

	ui.graphicsView->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);


}

Img_tile::~Img_tile()
{
}

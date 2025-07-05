
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    moilmaploader = new MoilMaploader();
    /*
    hbox_main = new QHBoxLayout();
    btn = new QPushButton("Download Table", this);
    hbox_main->addWidget(btn,1);
    this->centralWidget()->setLayout(hbox_main);
    QObject::connect(btn, &QPushButton::clicked, &downloader, &Downloader::fetchTable);
    */

    initMat();
    // QPixmap pixmap(":/images/pattern_1920.jpg"); // For images embedded in Qt's resource system
    // ui->label->setPixmap(pixmap);

    openImage("images/pattern_1920.jpg");

    QToolBar *toolBar = addToolBar(tr("&File"));
    openImageAction = new QAction(QIcon(":/images/image.svg"), tr("&Load Image"), this);
    toolBar->addAction(openImageAction);
    connect(openImageAction, SIGNAL(triggered()), this, SLOT(openImageUi()));

    QObject::connect(moilmaploader, SIGNAL(tableReady(const cv::Mat&, const cv::Mat&)), this, SLOT(processTable(const cv::Mat&, const cv::Mat&)));
    QObject::connect(ui->pushButton, &QPushButton::clicked, moilmaploader, &MoilMaploader::fetchTable);

    //QObject::connect(&downloader, &Downloader::tableReady, [&](const cv::Mat& mat){
    //        qDebug() << "First value:" << mat.at<float>(0, 0);
    //});

    //QObject::connect(&moilmaploader, &MoilMaploader::tableReady,this, &MainWindow::my_func );

}
void MainWindow::processTable(const cv::Mat& mat1, const cv::Mat& mat2)
{
    mat1.copyTo(mapX);
    mat2.copyTo(mapY);
    DisplayCh();

    // QMessageBox msgBox;
    // msgBox.setText("OK");
    // msgBox.exec();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::doRemap(Mat &Src, Mat &Dest, Mat &mapX, Mat &mapY)
{
remap( Src, Dest, mapX, mapY, INTER_CUBIC, BORDER_CONSTANT, Scalar(0, 0, 0));
}

void MainWindow::openImageUi()
{

    QString filename = QFileDialog::getOpenFileName(this,
        tr("Open Image"), ".", tr("Image Files (*.png *.jpg *.bmp)"));
    if (!filename.isEmpty())
        openImage(filename);
}

void MainWindow::openImage(QString filename)
{
    if (!filename.isEmpty()) {
        readImage(filename);
    }

}

void MainWindow::readImage(QString filename)
{
    std::string fname = filename.toUtf8().constData();
    image_input = imread(fname, IMREAD_COLOR);
    cv::resize(image_input, image_display, Size(640, 480));
    cvtColor(image_display, image_display, COLOR_BGR2RGB);
    DisplayWindow(image_display, ui->label, 0, 0, 640, 480);
}

void MainWindow::initMat()
{
    double w = 1920;
    double h = 1080;
    image_result = Mat(h, w, CV_8UC3);
    mapX = Mat(h, w, CV_32F);
    mapY = Mat(h, w, CV_32F);
}

void MainWindow::DisplayCh() {

    if (image_input.empty()) return;

    doRemap(image_input, image_result, mapX, mapY);
    cv::resize(image_result, image_display, Size(640, 480));
    cvtColor(image_display, image_display, COLOR_BGR2RGB);
    DisplayWindow(image_display, ui->label_2, 640, 0, 640, 480);

}

void MainWindow::DisplayWindow(Mat& src, QLabel *p_label, int x, int y, int w, int h)
{
    QImage q_image1 = QImage((uchar*)src.data, src.cols, src.rows, src.step, QImage::Format_RGB888);
    p_label->setPixmap(QPixmap::fromImage(q_image1));
    p_label->setStyleSheet("border:1px solid black;");
    p_label->setGeometry(x, y, w, h);
}

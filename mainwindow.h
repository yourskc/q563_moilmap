#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QPushButton>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QFile>
#include <QDebug>
#include <QHBoxLayout>
#include <QWidget>
#include <QMessageBox>
#include <QMainWindow>
#include <QString>
#include <QFileDialog>

#include "moilmaploader.h"
#include <opencv2/opencv.hpp>
using namespace cv;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void processTable(const cv::Mat& mat1, const cv::Mat& mat2);
private slots:
    void openImageUi();
private:
    Ui::MainWindow *ui;

    MoilMaploader *moilmaploader;
    QPushButton *btn;
    QHBoxLayout *hbox_main;
    QAction *openImageAction;
    Mat image_input, image_input_s;
    Mat image_result;
    Mat mapX, mapY, image_display;

    void initMat();
    void openImage(QString filename);
    void readImage(QString filename);
    void DisplayCh();
    void DisplayWindow(cv::Mat& src, QLabel *p_label, int x, int y, int w, int h);

    void doRemap(Mat &Src, Mat &Dest, Mat &mapX, Mat &mapY);
};

#endif // MAINWINDOW_H

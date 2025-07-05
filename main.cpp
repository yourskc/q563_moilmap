#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QDebug>

#include <opencv2/opencv.hpp>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    // QPushButton btn("Download Table");

    // MoilMaploader moilmaploader;
    // QObject::connect(&btn, &QPushButton::clicked, &moilmaploader, &MoilMaploader::fetchTable);
    // QObject::connect(&downloader, &Downloader::tableReady, [&](const cv::Mat& mat){
    //        qDebug() << "First value:" << mat.at<float>(0, 0);
    //});
    // QObject::connect(&downloader1, &Downloader::tableReady, &a, &QApplication::aboutQt);
    // QObject::connect(&moilmaploader, &MoilMaploader::tableReady, &a, processTable(const cv::Mat&, const cv::Mat&));
    // btn.show();

    w.showMaximized();
    return a.exec();
}

void my_func(){

}


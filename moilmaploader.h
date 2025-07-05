#ifndef MOILMAPLOADER_H
#define MOILMAPLOADER_H


#include <QApplication>
#include <QPushButton>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QFile>
#include <QDebug>
#include <QUrlQuery>
#include <QHttpMultiPart>
#include <opencv2/opencv.hpp>

const QString API_URL = "140.112.12.82/api/map.php";
const QString API_KEY = "6de4b51f6effe65421eefae641240e6349fe1632fcb16f72bb0a667073de6a5e";
const QString MAPN = "2";

class MoilMaploader : public QObject {
    Q_OBJECT
public:
    MoilMaploader(QObject* parent = nullptr) : QObject(parent) {
        connect(&manager, &QNetworkAccessManager::finished, this, &MoilMaploader::onFinished);
    }

    void fetchTable() {

        QNetworkRequest request;
        // GET
        // API_URL.append("?P0=100&P1=20&P3=0&P4=0&P5=0&P6=0");

        request.setUrl(QUrl("http://140.112.12.82/moilmap/api/map.php"));
        // request.setRawHeader("Authorization", ("Bearer 6de4b51f6effe65421eefae641240e6349fe1632fcb16f72bb0a667073de6a5e").toUtf8());
        QString token = QString("Bearer ") + API_KEY;
        request.setRawHeader("Authorization", token.toUtf8());

        // GET
        // manager.get(request);

        QHttpMultiPart *multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);
        QHttpPart textPart;
/*
        textPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data;name=\"program\""));
        textPart.setBody("0");
        multiPart->append(textPart);
        textPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data;name=\"senWidth\""));
        textPart.setBody("1.55");
        multiPart->append(textPart);
        textPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data;name=\"senHeight\""));
        textPart.setBody("1.55");
        multiPart->append(textPart);
        textPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data;name=\"iCx\""));
        textPart.setBody("944");
        multiPart->append(textPart);
        textPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data;name=\"iCy\""));
        textPart.setBody("525");
        multiPart->append(textPart);
        textPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data;name=\"Ratio\""));
        textPart.setBody("1");
        multiPart->append(textPart);
        textPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data;name=\"imgWidth\""));
        textPart.setBody("1920");
        multiPart->append(textPart);
        textPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data;name=\"imgHeight\""));
        textPart.setBody("1080");
        multiPart->append(textPart);
        textPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data;name=\"caliRatio\""));
        textPart.setBody("1");
        multiPart->append(textPart);

        textPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data;name=\"P0\""));
        textPart.setBody("0");
        multiPart->append(textPart);
        textPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data;name=\"P1\""));
        textPart.setBody("0");
        multiPart->append(textPart);
        textPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data;name=\"P2\""));
        textPart.setBody("-20.772");
        multiPart->append(textPart);
        textPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data;name=\"P3\""));
        textPart.setBody("-35.661");
        multiPart->append(textPart);
        textPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data;name=\"P4\""));
        textPart.setBody("-13.097");
        multiPart->append(textPart);
        textPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data;name=\"P5\""));
        textPart.setBody("370.36");
*/

        textPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data;name=\"program\""));
        textPart.setBody("0");
        multiPart->append(textPart);
        textPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data;name=\"senWidth\""));
        textPart.setBody("2");
        multiPart->append(textPart);
        textPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data;name=\"senHeight\""));
        textPart.setBody("2");
        multiPart->append(textPart);
        textPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data;name=\"iCx\""));
        textPart.setBody("1120");
        multiPart->append(textPart);
        textPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data;name=\"iCy\""));
        textPart.setBody("520");
        multiPart->append(textPart);
        textPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data;name=\"Ratio\""));
        textPart.setBody("1");
        multiPart->append(textPart);
        textPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data;name=\"imgWidth\""));
        textPart.setBody("1920");
        multiPart->append(textPart);
        textPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data;name=\"imgHeight\""));
        textPart.setBody("1080");
        multiPart->append(textPart);
        textPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data;name=\"caliRatio\""));
        textPart.setBody("3");
        multiPart->append(textPart);

        textPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data;name=\"P0\""));
        textPart.setBody("0");
        multiPart->append(textPart);
        textPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data;name=\"P1\""));
        textPart.setBody("0");
        multiPart->append(textPart);
        textPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data;name=\"P2\""));
        textPart.setBody("0");
        multiPart->append(textPart);
        textPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data;name=\"P3\""));
        textPart.setBody("0");
        multiPart->append(textPart);
        textPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data;name=\"P4\""));
        textPart.setBody("0");
        multiPart->append(textPart);
        textPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data;name=\"P5\""));
        textPart.setBody("130");

        multiPart->append(textPart);
        textPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data;name=\"mapN\""));
        textPart.setBody(MAPN.toUtf8());

        multiPart->append(textPart);
        manager.post(request, multiPart);
    }

signals:
    void tableReady(const cv::Mat& mat1, const cv::Mat& mat2);

private slots:
    void onFinished(QNetworkReply* reply) {
        //if (reply->error() != QNetworkReply::NoError) {
        //    qWarning() << "Error:" << reply->errorString();
        //    reply->deleteLater();
        //    return;
        //}

        QByteArray data = reply->readAll();

        qDebug() << "data size = " << data.size();

        int rows = *(int *)data.constData();
        int cols = *(int *)(data.constData() + 4);
        // check rows and cols
        int count = rows * cols;
        qDebug() << "(rows,cols)=(" << rows << "," << cols << ")";

        // Check values
        /*
        float floats[count];
        memcpy(floats, data.constData()+16, count*4);
        for (int i = 0; i < 10; ++i) {
            qDebug() << "Float" << i << ":" << floats[i];
        }
        */

        cv::Mat mat1((int)rows, (int)cols, CV_32FC1);
        cv::Mat mat2((int)rows, (int)cols, CV_32FC1);

        memcpy(mat1.data, data.constData()+16, count*4);

if ( MAPN == "2" ) {
        int xmap_size = 16 + ( rows*cols )*4 ;
        rows = *(int *)(data.constData() + xmap_size );
        cols = *(int *)(data.constData() + xmap_size + 4);
        qDebug() << "(rows,cols)=(" << rows << "," << cols << ")";

        count = rows * cols;
        memcpy(mat2.data, data.constData()+xmap_size+16, count*4);
}
        qDebug() << "before emit";
        emit tableReady(mat1, mat2);
        qDebug() << "after emit";
        reply->deleteLater();
    }

private:
    QNetworkAccessManager manager;
};

#endif // MOILMAPLOADER_H

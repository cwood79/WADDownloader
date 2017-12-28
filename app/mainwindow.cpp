#include "mainwindow.h"
#include "ui_mainwindow.h"

const QString MainWindow::QUERY_STRING = QString("https://legacy.doomworld.com/idgames//api/api.php?action=search&query=");

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_searchbutton_clicked()
{

    // grab input
    QString searchText = ui->searchbar->text();
    QString searchCategory = ui->category->currentText();
    QString sortCategory = ui->sortcategory->currentText();
    QString order = ui->order->currentText();

    /*QTextStream(stdout) << "Search text is " + searchText << endl;
    QTextStream(stdout) << "Search category is " + searchCategory << endl;
    QTextStream(stdout) << "Sort category is " + sortCategory << endl;
    QTextStream(stdout) << "Order is " + order << endl; */

    search(searchText, searchCategory, sortCategory, order);
}

void MainWindow::search(QString searchText, QString searchCategory, QString sortCategory, QString order)
{
    manager = new QNetworkAccessManager(this);
    QString urlSearch = searchText.toLower();
    QString urlSearchCategory = searchCategory.toLower();
    QString urlSortCategory = sortCategory.toLower();
    QString urlSortOrder = order.toLower();

    // API URL
    // https://legacy.doomworld.com/idgames//api/api.php?action=search&query
    QString urlString = QString(QUERY_STRING) + urlSearch + "&type=" + urlSearchCategory + "&sort="
            + urlSortCategory + "&dir=" + urlSortOrder + "&out=json";

    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onResult(QNetworkReply*)));

    QTextStream(stdout) << "Calling API at " + urlString << endl;
    QUrl url(urlString);
    QNetworkReply* currentReply = manager->get(QNetworkRequest(url));
}

void MainWindow::onResult(QNetworkReply* reply)
{
    if(reply->error() == QNetworkReply::NoError)
    {
        QTextStream(stdout) << "JSON RECEIVED!" << endl;
        QString strReply = (QString)reply->readAll();
        QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());

        QJsonObject root = jsonResponse.object();
        QJsonObject content = root["content"].toObject();
        QJsonArray files = content["file"].toArray();

        foreach (const QJsonValue & file, files)
        {
            QJsonObject obj = file.toObject();
            QTextStream(stdout) << "title is " + obj["title"].toString()<< endl;
            QTextStream(stdout) << "filename is " + obj["filename"].toString()<< endl;
            QTextStream(stdout) << "date is " + obj["date"].toString()<< endl;
            QTextStream(stdout) << "size is " + obj["size"].toInt()<< endl;
            QTextStream(stdout) << "author is " + obj["author"].toString()<< endl;
            double rating = obj["rating"].toDouble();
            QTextStream(stdout) << rating<< endl;

        }

    }

    else
    {
       qDebug() << "ERROR" << endl;
       delete reply;
    }

}


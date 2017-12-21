#include "mainwindow.h"
#include "ui_mainwindow.h"

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

    // send json request here
    // update textbrowser
    // grab input
    QString searchText = ui->searchbar->text();
    QString searchCategory = ui->category->currentText();
    QString sortCategory = ui->sortcategory->currentText();
    QString order = ui->order->currentText();

    QTextStream(stdout) << "Search text is " + searchText << endl;
    QTextStream(stdout) << "Search category is " + searchCategory << endl;
    QTextStream(stdout) << "Sort category is " + sortCategory << endl;
    QTextStream(stdout) << "Order is " + order << endl;

    // api address
    //https://legacy.doomworld.com/idgames//api/api.php
    search(searchText, searchCategory, sortCategory, order);
}

void MainWindow::search(QString searchText, QString searchCategory, QString sortCategory, QString order)
{
    QNetworkAccessManager networkManager;
    // API URL
    //https://legacy.doomworld.com/idgames//api/api.php?action=

    QUrl url("https://legacy.doomworld.com/idgames//api/api.php?action=ping&out=json");
    QNetworkRequest request;
    request.setUrl(url);
    //request.setHeader(QNetworkRequest::ContentTypeHeader, “application/json”);

    QNetworkReply* currentReply = networkManager.get(request);

    connect(&networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onResult(QNetworkReply*)));

    ui->textBrowser->setText("Search!");

}

void MainWindow::onResult(QNetworkReply* reply)
{
    if(reply->error() == QNetworkReply::NoError)
    {
        QJsonDocument document = QJsonDocument::fromJson(reply->readAll());
        QJsonObject root = document.object();
        ui->textBrowser->append(root.keys().at(0) + ": " + root.value(root.keys().at(0)).toString());
        QJsonValue jv = root.value("content");

        QTextStream(stdout) << "root size is" + root.size() << endl;



    }
    else
    {
       qDebug() << "ERROR" << endl;
    }

}


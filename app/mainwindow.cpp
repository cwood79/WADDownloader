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

    // API URL
    //https://legacy.doomworld.com/idgames//api/api.php?action=
    // https://legacy.doomworld.com/idgames//api/api.php?action=search&query=chest&type=filename&sort=date&out=json
    QString urlString = "https://legacy.doomworld.com/idgames//api/api.php?action=search&query=" + urlSearch + "&type=" + urlSearchCategory + "&sort="
            + urlSortCategory + "out=json";

    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onResult(QNetworkReply*)));

    QUrl url(urlString);
    QNetworkReply* currentReply = manager->get(QNetworkRequest(url));
}

void MainWindow::onResult(QNetworkReply* reply)
{
    if(reply->error() == QNetworkReply::NoError)
    {
        QTextStream(stdout) << "JSON RECEIVED!" << endl;
        QStringList fileNames;

        // parse json reply
        QString strReply = (QString)reply->readAll();
        QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());
        QJsonObject jsonObject = jsonResponse.object();
        QJsonArray jsonArray = jsonObject["file"].toArray();

        foreach(const QJsonValue & value, jsonArray)
        {
            QJsonObject obj = value.toObject();
            fileNames.append(obj["title"].toString());

        }



        // Display file names
        for(int i =0; i < fileNames.length(); i++)
        {
            ui->textBrowser->append(fileNames.at(i));
        }
    }
    else
    {
       qDebug() << "ERROR" << endl;
       delete reply;
    }

}


#include "mainwindow.h"
#include "ui_mainwindow.h"

const QString MainWindow::QUERY_STRING = QString("https://legacy.doomworld.com/idgames//api/api.php?action=search&query=");
const QString MainWindow::NEW_YORK_URL = QString("http://youfailit.net/pub/");

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_searchbutton_clicked() {
    // grab input
    QString searchText = ui->searchbar->text();
    QString searchCategory = ui->category->currentText();
    QString sortCategory = ui->sortcategory->currentText();
    QString order = ui->order->currentText();

    // clear text browser and search results
    wadSearchList.clear();
    ui->textBrowser->setText("");
    ui->textBrowser->show();


    /*QTextStream(stdout) << "Search text is " + searchText << endl;
    QTextStream(stdout) << "Search category is " + searchCategory << endl;
    QTextStream(stdout) << "Sort category is " + sortCategory << endl;
    QTextStream(stdout) << "Order is " + order << endl; */

    search(searchText, searchCategory, sortCategory, order);
}

void MainWindow::search(QString searchText, QString searchCategory, QString sortCategory, QString order) {
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

void MainWindow::onResult(QNetworkReply* reply) {
    if(reply->error() == QNetworkReply::NoError) {
        QTextStream(stdout) << "JSON RECEIVED!" << endl;
        QString strReply = (QString)reply->readAll();
        QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());

        QJsonObject root = jsonResponse.object();
        QJsonObject content = root["content"].toObject();
        QJsonArray files = content["file"].toArray();

        foreach (const QJsonValue & file, files) {
            QJsonObject obj = file.toObject();

           // QTextStream(stdout) << "" << endl;

            QString title = obj["title"].toString();
           // QTextStream(stdout) << "title is " + title<< endl;

            QString filename = obj["filename"].toString();
         //   QTextStream(stdout) << "filename is " + filename << endl;

            QString description = obj["description"].toString();
         //   QTextStream(stdout) << "description is " + description << endl;

            QString date = obj["date"].toString();
        //    QTextStream(stdout) << "date is " + date << endl;

            int size = obj["size"].toInt();
         //   QTextStream(stdout) << size << endl;

            QString author = obj["author"].toString();
        //    QTextStream(stdout) << "author is " + author<< endl;

            double rating = obj["rating"].toDouble();
        //    QTextStream(stdout) << rating<< endl;
            //update textbrowser
            Wad * wadFile = new Wad(title, filename, description, date, size, author, rating);
            wadSearchList.append(wadFile);

        }

        updateDisplay(wadSearchList);


    }

    else {
       qDebug() << "ERROR" << endl;
       delete reply;
    }

}

void MainWindow::updateDisplay(QList<Wad*> searchList) {
    QString searchHTML = "";
    foreach(Wad * w , searchList){

      //  QTextStream(stdout) << w->toHTML() << endl;
        searchHTML += w->toHTML();


    }

    ui->textBrowser->setHtml(searchHTML);
    ui->textBrowser->show();
}

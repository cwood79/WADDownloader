#include "mainwindow.h"
#include "ui_mainwindow.h"

const QString MainWindow::QUERY_STRING = QString("https://legacy.doomworld.com/idgames//api/api.php?action=search&query=");
//const QString MainWindow::NEW_YORK_URL = QString("http://youfailit.net/pub/idgames/");

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    manager = new QNetworkAccessManager(this);

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

    // clear search results and listwidget before searching again
    wadSearchList.clear();
    ui->listWidget->clear();

    search(searchText, searchCategory, sortCategory, order);
}

// Function to handle api call and search
void MainWindow::search(QString searchText, QString searchCategory, QString sortCategory, QString order) {
    QString urlSearch = searchText.toLower();
    QString urlSearchCategory = searchCategory.toLower();
    QString urlSortCategory = sortCategory.toLower();
    QString urlSortOrder = order.toLower();

    // API URL
    // https://legacy.doomworld.com/idgames//api/api.php?action=search&query
    QString urlString = QString(QUERY_STRING) + urlSearch + "&type=" + urlSearchCategory + "&sort="
            + urlSortCategory + "&dir=" + urlSortOrder + "&out=json";

    // Disconnect all slots before adding a new one
    disconnect(manager,0,0,0);

    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onResult(QNetworkReply*)));

    QTextStream(stdout) << "Calling API at " + urlString << endl;
    QUrl url(urlString);
    manager->get(QNetworkRequest(url));
}

// Function to handle api call results
void MainWindow::onResult(QNetworkReply* reply) {
    if(reply->error() == QNetworkReply::NoError) {
        QTextStream(stdout) << "JSON RECEIVED!" << endl;
        QString strReply = (QString)reply->readAll();
        QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());

        QJsonObject root = jsonResponse.object();
        QJsonObject content = root["content"].toObject();
        QJsonArray files = content["file"].toArray();

        // Parsing JSON from api request and creating Wad objects for display
        foreach (const QJsonValue & file, files) {
            QJsonObject obj = file.toObject();

            // Getting fields from JSON object from api call
            QString title = obj["title"].toString();
            QString filename = obj["filename"].toString();
            QString dir = obj["dir"].toString();
            QString description = obj["description"].toString();
            QString date = obj["date"].toString();
            int size = obj["size"].toInt();
            QString author = obj["author"].toString();
            double rating = obj["rating"].toDouble();

            Wad * wadFile = new Wad(title, filename, dir, description, date, size, author, rating);
            wadSearchList.append(wadFile);

        }

        updateDisplay(wadSearchList);
    }

    // Error handling if api call fails
    else {
       qDebug() << "ERROR" << endl;
       delete reply;
    }

    reply->deleteLater();

}

// Update listWidget to display results
void MainWindow::updateDisplay(QList<Wad*> searchList) {

    foreach(Wad * w , searchList){
       // Creating a new ListWidgetItem whose parent is the listWidget
       QListWidgetItem *listWidgetItem = new QListWidgetItem(ui->listWidget);

       // Adding ListWidgetItem to listWidget
       ui->listWidget->addItem(listWidgetItem);

       //Creating an object of the designed widget to add to listWidget
       //Setting fields of widget with data from api call
       WadListWidget * wadlistwidget = new WadListWidget();
       wadlistwidget->setFields(*w);

       //Making sure that the listWidgetItem has the same size as the wadlistwidget
       listWidgetItem->setSizeHint (wadlistwidget->sizeHint());

       // Add the itemWidget to the list
       ui->listWidget->setItemWidget (listWidgetItem, wadlistwidget);

    }

    ui->listWidget->show();
}


void MainWindow::on_downloadbutton_clicked() {

    // Check if searchlist has been made or a row has been selected
    if(wadSearchList.isEmpty() || ui->listWidget->currentRow() == -1)
    {

        // error message here
        return;
    }

    QTextStream(stdout) << "Downloading file in row " + ui->listWidget->currentRow() << endl;

    // Grab index from UI to find wad in wadSearchList
    int index = ui->listWidget->currentRow();

    Wad * wadDownload = wadSearchList.at(index);

    QTextStream(stdout) << "DOWNLOAD!" << endl;

    // Grab information from wad
    QString filename = wadDownload->getFileName();
    QString directory= wadDownload->getDir();

    doDownload(filename, directory);
}

void MainWindow::doDownload(QString filename, QString directory) {

    // Disconnect all slots before adding a new one
    disconnect(manager,0,0,0);

    connect(manager, SIGNAL(finished(QNetworkReply*)),
               this, SLOT(replyFinished(QNetworkReply*)));

    // Open Connection and download
    manager->get(QNetworkRequest(QUrl("http://youfailit.net/pub/idgames/" + directory + filename)));

}

void MainWindow::replyFinished(QNetworkReply *reply) {

    if(reply->error()) {
        qDebug() << "ERROR!";
        qDebug() << reply->errorString();
    }
    else {

        QTextStream(stdout) << "REPLY!" << endl;
        QTextStream(stdout) << reply->header(QNetworkRequest::ContentTypeHeader).toString() << endl;
        QTextStream(stdout) << reply->header(QNetworkRequest::LastModifiedHeader).toDateTime().toString()<< endl;
        QTextStream(stdout) << reply->header(QNetworkRequest::ContentLengthHeader).toULongLong()<< endl;
        QTextStream(stdout) << reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt()<< endl;
        QTextStream(stdout) << reply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString()<< endl;
        QTextStream(stdout) << reply->header(QNetworkRequest::ContentTypeHeader).toString()<< endl;
        QTextStream(stdout) << reply->url().toString() << endl;

        QTextStream(stdout) << "Reply Filename is " + reply->url().fileName() << endl;

        QFile *file = new QFile(reply->url().fileName());
        if(file->open(QFile::Append))
        {
                file->write(reply->readAll());
                file->flush();
                file->close();
        }
        delete file;
   }

   reply->deleteLater();

}


void MainWindow::on_settingsbutton_clicked() {
    // open settings window
    QTextStream(stdout) << "SETTINGS!" << endl;
}

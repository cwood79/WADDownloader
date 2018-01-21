#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include <QScriptEngine>
#include <QScriptValueIterator>
#include <Iterator>
#include "wad.h"
#include "resources\uis\wadlistwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    static const QString QUERY_STRING;
    static const QString NEW_YORK_URL;
    explicit MainWindow(QWidget *parent = 0);
    QList<Wad*> wadSearchList;
    ~MainWindow();

private slots:
    void on_searchbutton_clicked();
    void search(QString searchText, QString searchCategory, QString sortCategory, QString order);
    void onResult(QNetworkReply* reply);
    void updateDisplay(QList<Wad*> searchList);

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *manager;
};

#endif // MAINWINDOW_H

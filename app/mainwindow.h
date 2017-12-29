#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include <QScriptEngine>
#include <QScriptValueIterator>

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
    ~MainWindow();

private slots:
    void on_searchbutton_clicked();
    void search(QString searchText, QString searchCategory, QString sortCategory, QString order);
    void onResult(QNetworkReply* reply);

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *manager;
};

#endif // MAINWINDOW_H

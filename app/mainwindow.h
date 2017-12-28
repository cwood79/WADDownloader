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
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_searchbutton_clicked();
    void search(QString searchText, QString searchCategory, QString sortCategory, QString order);
    void onResult(QNetworkReply* reply);

private:
    Ui::MainWindow *ui;
    //static const QString API_URL = "https://legacy.doomworld.com/idgames//api/api.php?action=";
    QNetworkAccessManager *manager;
};

#endif // MAINWINDOW_H

#ifndef WADLISTWIDGET_H
#define WADLISTWIDGET_H

#include <QWidget>

namespace Ui {
class WadListWidget;
}

class WadListWidget : public QWidget
{
    Q_OBJECT

public:
    explicit WadListWidget(QWidget *parent = 0);
    ~WadListWidget();

private:
    Ui::WadListWidget *ui;

};

#endif // WADLISTWIDGET_H

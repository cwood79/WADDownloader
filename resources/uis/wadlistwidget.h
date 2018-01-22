#ifndef WADLISTWIDGET_H
#define WADLISTWIDGET_H

#include <QWidget>
#include "../../app/wad.h"

namespace Ui {
class WadListWidget;
}

class WadListWidget : public QWidget
{
    Q_OBJECT

public:
    explicit WadListWidget(QWidget *parent = 0);
    ~WadListWidget();
    void setFields(Wad w);

private:
    Ui::WadListWidget *ui;

};

#endif // WADLISTWIDGET_H

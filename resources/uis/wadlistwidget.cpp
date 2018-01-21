#include "wadlistwidget.h"
#include "ui_wadlistwidget.h"

WadListWidget::WadListWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WadListWidget)
{
    ui->setupUi(this);
}

WadListWidget::~WadListWidget()
{
    delete ui;
}

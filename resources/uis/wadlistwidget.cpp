#include "wadlistwidget.h"
#include "ui_wadlistwidget.h"

// Class for widgets for search results
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

// TODO: Put this in a constructor at some point
// Function to set fields of WadListWidget
void WadListWidget::setFields(Wad w)
{

    ui->titleText->setText(w.getTitle());
    ui->filenameField->setText(w.getFileName());
    ui->description->setText(w.getDescription());
    ui->dateField->setText(w.getDate());
    ui->sizeField->setText(QString::number(w.getFileSize()/1024)+"KB"); // convert to KB for display
    ui->authorField->setText(w.getAuthor());
}

#include "vendawindow.h"
#include "ui_vendawindow.h"

VendaWindow::VendaWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VendaWindow)
{
    ui->setupUi(this);
}

VendaWindow::~VendaWindow()
{
    delete ui;
}

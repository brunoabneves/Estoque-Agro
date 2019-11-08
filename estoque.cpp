#include "estoque.h"
#include "ui_estoque.h"

Estoque::Estoque(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Estoque)
{
    ui->setupUi(this);
}

Estoque::~Estoque()
{
    delete ui;
}

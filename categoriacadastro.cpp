#include "categoriacadastro.h"
#include "ui_categoriacadastro.h"

CategoriaCadastro::CategoriaCadastro(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CategoriaCadastro)
{
    ui->setupUi(this);
}

CategoriaCadastro::~CategoriaCadastro()
{
    delete ui;
}

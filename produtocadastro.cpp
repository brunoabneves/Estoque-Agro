#include "produtocadastro.h"
#include "ui_produtocadastro.h"

ProdutoCadastro::ProdutoCadastro(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ProdutoCadastro)
{
    ui->setupUi(this);
}

ProdutoCadastro::~ProdutoCadastro()
{
    delete ui;
}

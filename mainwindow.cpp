#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pBCadastroProd_clicked()
{
    connectionOpen();
    pcObjeto = new ProdutoCadastro(this);
    pcObjeto->show();
}

void MainWindow::on_pBCadastroCategoria_clicked()
{
    CategoriaCadastro categoriaCadastro;
    categoriaCadastro.exec();
}

void MainWindow::on_pBEstoque_clicked()
{
    Estoque estoque;
    estoque.exec();
}

void MainWindow::on_pBVenda_clicked()
{
    VendaWindow vendaWindow;
    vendaWindow.exec();
}

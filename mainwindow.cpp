#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSqlDatabase bd = QSqlDatabase::addDatabase("QSQLITE");
    bd.setDatabaseName("/home/bruno/Documentos/Qt/Projetos/estoque-agro/BD/teste");

    if(!bd.open()){
        qDebug("Não foi possível abrir o banco de dados");
    }else{
        qDebug("Banco de dados aberto com sucesso!");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pBCadastroProd_clicked()
{
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

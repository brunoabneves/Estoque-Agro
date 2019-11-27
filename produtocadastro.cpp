#include "produtocadastro.h"
#include "ui_produtocadastro.h"
#include <QMessageBox>
#include "mainwindow.h"

ProdutoCadastro::ProdutoCadastro(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ProdutoCadastro)
{
    ui->setupUi(this);

    QSqlQueryModel *modal = new QSqlQueryModel();

    QSqlQuery query;
    query.prepare("SELECT nome FROM categoria");

    query.exec();
    modal->setQuery(query);
    ui->comboBoxCategoria->setModel(modal);

}

ProdutoCadastro::~ProdutoCadastro()
{
    delete ui;
}

void ProdutoCadastro::on_actionSalvar_triggered()
{
    QString nome = ui->lineEditNome->text();
    QString precoCusto = ui->lineEditPrecoCusto->text();
    QString precoVenda = ui->lineEditPrecoVenda->text();
    QString descricao = ui->lineEditDescricao->text();
    QString categoriaNome = ui->comboBoxCategoria->currentText();

    QSqlQuery query;
    QSqlQuery query2;

    //prepara a query para depois executar
    query.prepare("INSERT INTO produto (nome, preco_custo, preco_venda, descricao) VALUES"
                  "('"+nome+"','"+precoCusto+"','"+precoVenda+"','"+descricao+"')");

    query2.prepare("INSERT INTO produto_categoria (id_produto, id_categoria) VALUES "
                   "((select prod.id_produto from produto prod where prod.nome ='"+nome+"') ,"
                   "(select cat.id from categoria cat where cat.nome = '"+categoriaNome+"'))");

    //Se a query for executada, mostra uma mensagem, limpa os campos e retorna o cursor para o nome
    if(query.exec()){
        query2.exec();
        qDebug("Registro Inserido");

        QMessageBox::information(this, "", "Registro gravado com sucesso");
        ui->lineEditNome->clear();
        ui->lineEditPrecoCusto->clear();
        ui->lineEditPrecoVenda->clear();
        ui->lineEditDescricao->clear();
        ui->comboBoxCategoria->clear();

        ui->lineEditNome->setFocus();

    }else{
        qDebug("Erro ao inserir registro!");
        qDebug() << query.lastError().text();
    }
}

void ProdutoCadastro::on_pB_SearchByName_clicked()
{
    QString nome = ui->lineEditNome->text();

    MainWindow connection;

    QSqlQueryModel *modal = new QSqlQueryModel();

    QSqlQuery *query = new QSqlQuery(connection.mydb);

    query->prepare("SELECT * FROM produto WHERE produto.nome = '"+nome+"'");

    query->exec();
    modal->setQuery(*query);
    ui->tableView->setModel(modal);

    //qDebug >>(modal->rowCount());
}

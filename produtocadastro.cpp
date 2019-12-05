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
                   "((select prod.id from produto prod where prod.nome ='"+nome+"') ,"
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

    query->prepare("SELECT * FROM produto WHERE produto.nome LIKE '%"+nome+"%'");

    query->exec();
    modal->setQuery(*query);
    ui->tableView->setModel(modal);

    //qDebug >>(modal->rowCount());
}

void ProdutoCadastro::on_pB_SearchByCategorie_clicked()
{
    MainWindow connection;

    QString categoriaNome = ui->comboBoxCategoria->currentText();

    QSqlQueryModel *modal = new QSqlQueryModel();

    QSqlQuery *query = new QSqlQuery(connection.mydb);

    query->prepare("select * from produto where produto.id in "
                   "(select produto_categoria.id_produto from produto_categoria where "
                   "produto_categoria.id_categoria = (select id from categoria "
                   "where categoria.nome like '%"+categoriaNome+"%'))");

    query->exec();
    modal->setQuery(*query);
    ui->tableView->setModel(modal);
}

void ProdutoCadastro::on_tableView_activated(const QModelIndex &index)
{
    QString val = ui->tableView->model()->data(index).toString();

    QSqlQuery query, query2;
    query.prepare("SELECT * FROM produto where id='"+val+"' or nome='"+val+"' or "
                  "descricao='"+val+"'");

    query2.prepare("SELECT nome FROM categoria WHERE id=(SELECT id_categoria FROM "
                   "produto_categoria WHERE id_produto = (SELECT id FROM produto WHERE nome = '"+val+"'))");

    if(query.exec() && query2.exec()){
        while(query.next()){
            ui->lineEditNome->setText(query.value(1).toString());
            ui->lineEditPrecoCusto->setText(query.value(2).toString());
            ui->lineEditPrecoVenda->setText(query.value(3).toString());
            ui->lineEditDescricao->setText(query.value(4).toString());
        }
        if(query2.next()){
            if(query2.value(0).toString()=="Medicamentos")
                ui->comboBoxCategoria->setCurrentIndex(0);
            if(query2.value(0).toString()=="Rações")
                ui->comboBoxCategoria->setCurrentIndex(1);
            if(query2.value(0).toString()=="Sementes")
                ui->comboBoxCategoria->setCurrentIndex(2);
            if(query2.value(0).toString()=="Acessórios")
                ui->comboBoxCategoria->setCurrentIndex(3);
            if(query2.value(0).toString()=="PetShop")
                ui->comboBoxCategoria->setCurrentIndex(4);
        }
    }
}


void ProdutoCadastro::on_actionAtualizar_triggered()
{
    QString nome = ui->lineEditNome->text();
    QString precoCusto = ui->lineEditPrecoCusto->text();
    QString precoVenda = ui->lineEditPrecoVenda->text();
    QString descricao = ui->lineEditDescricao->text();

    QSqlQuery query;

    query.prepare("UPDATE produto SET nome='"+nome+"', preco_custo='"+precoCusto+"',"
                  "preco_venda='"+precoVenda+"', descricao='"+descricao+"' "
                  "WHERE produto.id = (SELECT id FROM produto WHERE nome = '"+nome+"')");

    if(query.exec()){
        qDebug("Registro alterado");

        QMessageBox::information(this, "", "Registro alterado com sucesso");
        ui->lineEditNome->clear();
        ui->lineEditPrecoCusto->clear();
        ui->lineEditPrecoVenda->clear();
        ui->lineEditDescricao->clear();
        ui->comboBoxCategoria->clear();

        ui->lineEditNome->setFocus();

    }else{
        qDebug("Erro ao alterar registro!");
        qDebug() << query.lastError().text();
    }
}

#include "produtocadastro.h"
#include "ui_produtocadastro.h"
#include <QMessageBox>

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

void ProdutoCadastro::on_actionSalvar_triggered()
{
    QString nome = ui->lineEditNome->text();
    QString precoCusto = ui->lineEditPrecoCusto->text();
    QString precoVenda = ui->lineEditPrecoVenda->text();
    QString descricao = ui->lineEditDescricao->text();

    QSqlQuery query;
    //prepara a query para depois executar
    query.prepare("insert into produto (nome, preco_custo, preco_venda, descricao) values"
                  "('"+nome+"','"+precoCusto+"','"+precoVenda+"','"+descricao+"')");

    //Se a query for executada, mostra uma mensagem, limpa os campos e retorna o cursor para o nome
    if(query.exec()){
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

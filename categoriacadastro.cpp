#include "categoriacadastro.h"
#include "ui_categoriacadastro.h"
#include <QMessageBox>

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

void CategoriaCadastro::on_pBSalvar_clicked()
{
    QString nome = ui->lineEdit_nome->text();

    QSqlQuery query;
    query.prepare("insert into categoria (nome) values ('"+nome+"')");

    if(query.exec()){
        QMessageBox::information(this, "", "Registro gravado com sucesso");
        ui->lineEdit_nome->clear();
        ui->lineEdit_nome->setFocus();

    }else{
        qDebug("Erro ao inserir registro!");
        qDebug() << query.lastError().text();
    }
}

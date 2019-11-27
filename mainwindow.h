#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "produtocadastro.h"
#include "categoriacadastro.h"
#include "estoque.h"
#include "vendawindow.h"
#include <QtSql>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QSqlDatabase mydb;
    void connectionClose()
    {
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }

    bool connectionOpen()
    {
        QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName("/home/bruno/Documentos/Qt/Projetos/estoque-agro/BD/teste");

        if(!mydb.open()){
            qDebug("Não foi possível abrir o banco de dados");
            return false;
        }else{
            qDebug("Banco de dados aberto com sucesso!");
            return true;
        }
    }

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pBCadastroProd_clicked();

    void on_pBCadastroCategoria_clicked();

    void on_pBEstoque_clicked();

    void on_pBVenda_clicked();

private:
    Ui::MainWindow *ui;
    ProdutoCadastro *pcObjeto;
};

#endif // MAINWINDOW_H

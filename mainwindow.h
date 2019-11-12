#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "produtocadastro.h"
#include "categoriacadastro.h"
#include "estoque.h"
#include "vendawindow.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

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

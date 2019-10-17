#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "produtocadastro.h"

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

private:
    Ui::MainWindow *ui;
    ProdutoCadastro *pcObjeto;
};

#endif // MAINWINDOW_H

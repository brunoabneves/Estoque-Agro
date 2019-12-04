#ifndef PRODUTOCADASTRO_H
#define PRODUTOCADASTRO_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>

namespace Ui {
class ProdutoCadastro;
}

class ProdutoCadastro : public QMainWindow
{
    Q_OBJECT

public:
    explicit ProdutoCadastro(QWidget *parent = nullptr);
    ~ProdutoCadastro();

private slots:

    void on_actionSalvar_triggered();

    void on_pB_SearchByName_clicked();

    void on_pB_SearchByCategorie_clicked();

    void on_tableView_activated(const QModelIndex &index);

private:
    Ui::ProdutoCadastro *ui;
};

#endif // PRODUTOCADASTRO_H

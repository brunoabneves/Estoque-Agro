#ifndef CATEGORIACADASTRO_H
#define CATEGORIACADASTRO_H

#include <QDialog>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>

namespace Ui {
class CategoriaCadastro;
}

class CategoriaCadastro : public QDialog
{
    Q_OBJECT

public:
    explicit CategoriaCadastro(QWidget *parent = 0);
    ~CategoriaCadastro();

private slots:
    void on_pBSalvar_clicked();

private:
    Ui::CategoriaCadastro *ui;
};

#endif // CATEGORIACADASTRO_H

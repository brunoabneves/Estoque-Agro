#ifndef PRODUTOCADASTRO_H
#define PRODUTOCADASTRO_H

#include <QMainWindow>

namespace Ui {
class ProdutoCadastro;
}

class ProdutoCadastro : public QMainWindow
{
    Q_OBJECT

public:
    explicit ProdutoCadastro(QWidget *parent = nullptr);
    ~ProdutoCadastro();

private:
    Ui::ProdutoCadastro *ui;
};

#endif // PRODUTOCADASTRO_H

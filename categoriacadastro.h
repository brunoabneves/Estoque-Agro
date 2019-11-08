#ifndef CATEGORIACADASTRO_H
#define CATEGORIACADASTRO_H

#include <QDialog>

namespace Ui {
class CategoriaCadastro;
}

class CategoriaCadastro : public QDialog
{
    Q_OBJECT

public:
    explicit CategoriaCadastro(QWidget *parent = 0);
    ~CategoriaCadastro();

private:
    Ui::CategoriaCadastro *ui;
};

#endif // CATEGORIACADASTRO_H

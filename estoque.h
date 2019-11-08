#ifndef ESTOQUE_H
#define ESTOQUE_H

#include <QDialog>

namespace Ui {
class Estoque;
}

class Estoque : public QDialog
{
    Q_OBJECT

public:
    explicit Estoque(QWidget *parent = 0);
    ~Estoque();

private:
    Ui::Estoque *ui;
};

#endif // ESTOQUE_H

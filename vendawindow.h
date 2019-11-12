#ifndef VENDAWINDOW_H
#define VENDAWINDOW_H

#include <QDialog>

namespace Ui {
class VendaWindow;
}

class VendaWindow : public QDialog
{
    Q_OBJECT

public:
    explicit VendaWindow(QWidget *parent = 0);
    ~VendaWindow();

private:
    Ui::VendaWindow *ui;
};

#endif // VENDAWINDOW_H

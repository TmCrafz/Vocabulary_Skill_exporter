#ifndef CONVERTTXT_H
#define CONVERTTXT_H

#include <QDialog>

namespace Ui {
class ConvertTxt;
}

class ConvertTxt : public QDialog
{
    Q_OBJECT

public:
    explicit ConvertTxt(QWidget *parent = 0);
    ~ConvertTxt();

private:
    Ui::ConvertTxt *ui;
};

#endif // CONVERTTXT_H

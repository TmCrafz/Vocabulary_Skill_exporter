#ifndef DIALOGCONVERTTXT_H
#define DIALOGCONVERTTXT_H

#include <QDialog>

namespace Ui {
class DialogConvertTxt;
}

class DialogConvertTxt : public QDialog
{
    Q_OBJECT

public:
    explicit DialogConvertTxt(QWidget *parent = 0);
    ~DialogConvertTxt();

private:
    Ui::DialogConvertTxt *ui;
};

#endif // DIALOGCONVERTTXT_H

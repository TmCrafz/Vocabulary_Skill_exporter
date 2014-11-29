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

    std::string trim(std::string str);


private slots:


    void on_pushBtnChooseTxt_clicked();

    void on_pushBtnChooseXmlSave_clicked();

    void on_pushBtnConvert_clicked();

private:
    Ui::DialogConvertTxt *ui;
    QString txtPath;
    QString xmlPath;
};

#endif // DIALOGCONVERTTXT_H

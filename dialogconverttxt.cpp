#include "dialogconverttxt.h"
#include "ui_dialogconverttxt.h"

DialogConvertTxt::DialogConvertTxt(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogConvertTxt)
{
    ui->setupUi(this);
}

DialogConvertTxt::~DialogConvertTxt()
{
    delete ui;
}

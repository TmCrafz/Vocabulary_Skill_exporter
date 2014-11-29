#include "converttxt.h"
#include "ui_converttxt.h"

ConvertTxt::ConvertTxt(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConvertTxt)
{
    ui->setupUi(this);
}

ConvertTxt::~ConvertTxt()
{
    delete ui;
}

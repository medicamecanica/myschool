#include "modelcontorl.h"
#include "ui_modelcontorl.h"

ModelContorl::ModelContorl(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModelContorl)
{
    ui->setupUi(this);
}

ModelContorl::~ModelContorl()
{
    delete ui;
}

#ifndef MODELCONTORL_H
#define MODELCONTORL_H

#include <QWidget>

namespace Ui {
class ModelContorl;
}

class ModelContorl : public QWidget
{
    Q_OBJECT

public:
    explicit ModelContorl(QWidget *parent = nullptr);
    ~ModelContorl();

private:
    Ui::ModelContorl *ui;
};

#endif // MODELCONTORL_H

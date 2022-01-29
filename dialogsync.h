#ifndef DIALOGSYNC_H
#define DIALOGSYNC_H

#include <QDialog>

namespace Ui {
class DialogSync;
}

class DialogSync : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSync(QWidget *parent = nullptr);
    ~DialogSync();

private slots:
    void sync();
private:
    Ui::DialogSync *ui;
};

#endif // DIALOGSYNC_H

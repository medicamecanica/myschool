#ifndef USERCONNECTION_H
#define USERCONNECTION_H

#include "util.h"

#include <QSettings>
#include <QWidget>

namespace Ui {
class UserConection;
}

class UserConnection : public QWidget
{
    Q_OBJECT

public:
    explicit UserConnection(QWidget *parent = nullptr);
    ~UserConnection();
    //declare static metod get token
     QString getToken();

    

private slots:
    void on_connection_clicked();
    void on_reply_finished();
private:
    Ui::UserConection *ui;
    //instance settings from Util class
    QSettings *settings=Util::getSettings();
    void getSettings();
    //create url, user and password pointers fields
    QString url, user, password,token;
    


};

#endif // USERCONNECTION_H

#include "userconnection.h"
#include "ui_userconnection.h"
#include "dolibarrapibuilder.h"

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

UserConnection::UserConnection(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserConection)
{
    ui->setupUi(this);
    settings=Util::getSettings();
    getSettings();
    //print  qdebug setting path
    qDebug()<<settings->fileName();
    //connect ui->btn_connection to slot on_connection_clicked
    connect(ui->btn_conn,SIGNAL(clicked()),this,SLOT(on_connection_clicked()));
}
//implement static method get token from settings
QString UserConnection::getToken()
{
    
    return settings->value("token").toString();
}
UserConnection::~UserConnection()
{
    delete ui;
}
//get settings url, user and password from file usersettings
void UserConnection::getSettings()
{
    settings->beginGroup("user");

     this->url = settings->value("url").toString();
    this->user = settings->value("user").toString();
    this->password = settings->value("password").toString();
    //loaf text fields with settings
    ui->lineEdit_url->setText(url);
    ui->lineEdit_user->setText(user);
    ui->lineEdit_password->setText(password);

    settings->endGroup();
}
//create slot to consume api login resource and get token
void UserConnection::on_connection_clicked()
{
    //first save settings user, password and url
    settings->beginGroup("user");
    settings->setValue("url", ui->lineEdit_url->text());
    settings->setValue("user", ui->lineEdit_user->text());
    settings->setValue("password", ui->lineEdit_password->text());
    //save settings
    settings->endGroup();

   //instance dolibarrapibuilder
    DolibarrApiBuilder *dolibarrapibuilder = new DolibarrApiBuilder();

    //create dolibarrapi object with url, user and password parameters
    DolibarrApi *dolibarrapi = dolibarrapibuilder->build(ui->lineEdit_url->text(),ui->lineEdit_user->text(),ui->lineEdit_password->text());
    //connect dolibarrapi loginDone signal to slot and show successfull message
    connect(dolibarrapi, &DolibarrApi::loginDone, this, [=](){
        QMessageBox::information(this, "Success", "Login successfull");
    });
    //connect dolibarrapi error signal to slot and show error message
    connect(dolibarrapi, &DolibarrApi::error, this, [=](){
        QMessageBox::critical(this, "Error", "Login error");
    });
    //consume login emit login else emit error
    dolibarrapi->login();



}

void UserConnection::on_reply_finished()
{

}








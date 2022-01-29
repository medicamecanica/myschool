#include "dolibarrapi.h"
#include "util.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>

DolibarrApi::DolibarrApi(QObject *parent) : QObject(parent)
{

}

DolibarrApi::~DolibarrApi()
{


}
//implement getter and setter methods for url, user and password
QString DolibarrApi::url() const
{
    return url_;
}

void DolibarrApi::setUrl(const QString &url)
{
    url_ = url;
}
QString DolibarrApi::user() const
{
    return user_;
}
void DolibarrApi::setUser(const QString &user)
{
    user_ = user;
}
QString DolibarrApi::password() const
{
    return password_;
}
void DolibarrApi::setPassword(const QString &password)
{
    password_ = password;
}
QString DolibarrApi::token() const
{
    return token_;
}
void DolibarrApi::setToken(const QString &token)
{
    token_ = token;
}
 //implement login method to consume synchronous request to login
void DolibarrApi::login(){
    //create request url
    QString url = url_ + APIPATH+"/login";
    //create request json body  with user and password parameters
    QJsonObject jsonBody;
    jsonBody.insert("login", user_);
    jsonBody.insert("password", password_);
    const QByteArray json = QJsonDocument(jsonBody).toJson();
    //create network manager
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    //debug url
    qDebug() << url;

     QNetworkRequest request( (QUrl(url)));
    //get reply and connect to finihed and error signals
    qDebug()<<request.url();
    request.setHeader( QNetworkRequest::ContentTypeHeader,"application/json");
    request.setRawHeader("Accept","application/json");
    QNetworkReply *reply = manager->post(request, json);
     qDebug() << reply;
    //connect reply finished with lambda function and valide error
    connect(reply, &QNetworkReply::finished, [this,reply](){
         qDebug() << reply;
         QVariant statusCode = reply->attribute( QNetworkRequest::HttpStatusCodeAttribute );
         qDebug()<<statusCode;
        if(reply->error()){
            qDebug() << reply->errorString();
            emit error(reply->error());
            return;
        }else{

            //get reply data
            QByteArray data = reply->readAll();
            //create json document
            QJsonDocument doc = QJsonDocument::fromJson(data);
            //get json object
            QJsonObject json = doc.object();
            //debug json
            qDebug() << doc.toJson();
            //get token from json object
            this->token_ = json.value("success").toObject().value("token").toString();
            //save token in settings
            QSettings *settings=Util::getSettings();
            settings->beginGroup("user");
            settings->setValue("token", this->token_);
            settings->endGroup();
            //emit signal to notify that login is done
            emit loginDone(this->token_);
        }
    });


}

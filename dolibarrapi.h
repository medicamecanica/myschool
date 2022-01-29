#ifndef DOLIBARRAPI_H
#define DOLIBARRAPI_H

#include <QNetworkReply>
#include <QObject>

class DolibarrApi : public QObject
{
    Q_OBJECT
public:
    explicit DolibarrApi(QObject *parent = nullptr);
    ~DolibarrApi();
    //define properties methods for url, user and password
    Q_PROPERTY(QString url READ url WRITE setUrl NOTIFY urlChanged)
    Q_PROPERTY(QString user READ user WRITE setUser NOTIFY userChanged)
    Q_PROPERTY(QString password READ password WRITE setPassword NOTIFY passwordChanged)
    Q_PROPERTY(QString token READ token WRITE setToken NOTIFY tokenChanged)
    //define getter and setter methods for url, user and password
    QString url() const;
    void setUrl(const QString &url);
    QString user() const;
    void setUser(const QString &user);
    QString password() const;
    void setPassword(const QString &password);
    QString token() const;
    void setToken(const QString &token);

    void login();
private:
    //define user, password, url, token properties
    QString user_, password_, url_, token_;
    //create const string segment url
    const QString APIPATH = "/api/index.php";





signals:
    void loginDone(QString token);
    void error(QNetworkReply::NetworkError error);
    //define changed property signals for url, user and password and token
    void urlChanged(QString url);
    void userChanged(QString user);
    void passwordChanged(QString password);
    void tokenChanged(QString token);

};

#endif // DOLIBARRAPI_H

#ifndef UTIL_H
#define UTIL_H

#include <QCoreApplication>
#include <QSettings>
#include <QString>
#include <QtDebug>


//create class Util with static settings acces file
class Util
{
public:
//add constructor and destructor declarations
    Util();
    ~Util();
//add static method to get settings url, user and password from file usersettings
    static QString getSettings(QString key)
    {
        QSettings settings("usersettings.ini", QSettings::IniFormat);
        settings.beginGroup("database");
        QString value = settings.value(key).toString();
        settings.endGroup();
        return value;
    }
    //create static method to get settings object
    static QSettings* getSettings()
    {
        //get aplication path and  concatenate so separator
        QString path = QCoreApplication::applicationDirPath() + "/usersettings.ini";
        //ddebug path
        qDebug()<<path;
        QSettings *settings = new QSettings(path, QSettings::IniFormat);
        settings->beginGroup("database");

        return settings;
    }
    //create static method for get token from settings
    static QString getToken()
    {
        QSettings *settings = Util::getSettings();
        return settings->value("token").toString();
    }

};

#endif // UTIL_H

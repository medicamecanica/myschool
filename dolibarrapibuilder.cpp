#include "dolibarrapi.h"
#include "dolibarrapibuilder.h"
#include "util.h"
#include "util.h"

DolibarrApiBuilder::DolibarrApiBuilder(QObject *parent) : QObject(parent)
{

}
//create builder method to return dolibarrapi object from url, user and password parameters
DolibarrApi* DolibarrApiBuilder::build(QString url, QString user, QString password)
{
    //create dolibarrapi object
    DolibarrApi *dolibarrapi = new DolibarrApi();

    //create dolibarrapi object with url, user and password parameters
    dolibarrapi->setUrl(url);
    dolibarrapi->setUser(user);
    dolibarrapi->setPassword(password);
    //return dolibarrapi object
    return dolibarrapi;
}
//create builder method to return dolibarrapi with no parameters then load token from settings
DolibarrApi* DolibarrApiBuilder::build()
{
    //create dolibarrapi object
    DolibarrApi *dolibarrapi = new DolibarrApi();
    //load token from settings
    QString token = Util::getToken();
    //set token to dolibarrapi object
    dolibarrapi->setToken(token);
    //return dolibarrapi object
    return dolibarrapi;
}

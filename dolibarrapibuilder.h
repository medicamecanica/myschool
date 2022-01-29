#ifndef DOLIBARRAPIBUILDER_H
#define DOLIBARRAPIBUILDER_H

#include "dolibarrapi.h"

#include <QObject>

class DolibarrApiBuilder : public QObject
{
    Q_OBJECT
public:
    explicit DolibarrApiBuilder(QObject *parent = nullptr);

    DolibarrApi *build(QString url, QString user, QString password);
    DolibarrApi *build();
signals:

};

#endif // DOLIBARRAPIBUILDER_H

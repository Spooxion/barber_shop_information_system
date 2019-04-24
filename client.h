#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include<QString>
#include <QLineEdit>

class Client
{

private:
    QString first_name;
    QString third_name;
    QString last_service;
    QString number;
    QString data;
    QString time;
    QString cost;

public:
    Client(QString First_name, QString Third_name, QString Number, QString Last_service,QString Data,QString Time,QString Cost);
    Client();
    ~Client();

    void setFirstName (QString First_name);
    void setThirdName (QString Third_name);
    void setLastService (QString Last_service);
    void setNumber (QString Number);
    void setData (QString Data);
    void setTime (QString Time);
    void setCost (QString Cost);

    QString getFirstName();
    QString getThirdName();
    QString getLastService();
    QString getNumber();
    QString getData();
    QString getTime();
    QString getCost();
 };

#endif // CLIENT_H

#include "client.h"

Client::Client(QString First_name, QString Third_name, QString Number, QString Last_service,QString Data,QString Time,QString Cost)
{
    first_name= First_name;
    third_name=Third_name;
    number=Number;
    last_service=Last_service;
    data=Data;
    time=Time;
    cost=Cost;
}

void Client::setFirstName(QString First_name){first_name = First_name;}
void Client::setThirdName(QString Third_name){third_name=Third_name;}
void Client::setLastService(QString Last_service){last_service=Last_service;}
void Client::setNumber (QString Number){number=Number;}
void Client::setData (QString Data){data=Data;}
void Client::setTime (QString Time){time=Time;}
void Client::setCost (QString Cost){cost=Cost;}

QString Client::getFirstName(){return first_name;}
QString Client::getThirdName(){return third_name;}
QString Client::getNumber(){return number;}
QString Client::getLastService(){return last_service;}
QString Client::getData(){return data;}
QString Client::getTime(){return time;}
QString Client::getCost(){return cost;}

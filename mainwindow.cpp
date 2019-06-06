#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStringRef>
#include <QList>
#include <QFileDialog>
#include <QTextCodec>
#include <QWidget>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    serch = new SerchWindow(this);
    ui->statusBar->visibleRegion();



    QPixmap *backgnd = new QPixmap(":Images/Images/back.png");
    QPalette *palette = new QPalette;
    palette->setBrush(QPalette::Window, QBrush(*backgnd));
    this->setPalette(*palette);

    QWidget::setWindowTitle("Информационная система \"Парикмахерская\" " );
    QRegExp Const_int ("^[0-9]+$");
    QRegExp Const_word ("^[А-Яа-яA-Za-z]{,50}$");
    QRegExpValidator *word_check = new QRegExpValidator(Const_word, this);
    QRegExpValidator *int_check = new QRegExpValidator(Const_int, this);

    ui->pushButton_edit_client->setToolTip("Для редактирования информации,\nнажмите на любую яйчейку необходимого клиента,\nзамените необходимые поля, а затем примените редактирование.");
    ui->pushButton_2->setToolTip("Для удаления клиента из таблицы,\nнажмите на любую яйчейку необходимого клиента,\nа затем нажмите на эту кнопку.");
    ui->pushButton->setToolTip("Для добовления клиента,\nзаполните все поля и нажмите на эту кнопку.");
    ui->pushButton_3->setToolTip("Для поиска клиента,\nукажите необходимые поля,\nа затем нажмите на эту кнопку.");
    ui->pushButton_cancel->setVisible(0);
    ui->label_18->setVisible(0);
    //ui->pushButton_genirate->setVisible(0);
    //ui->lineEdit->setVisible(0);

    ui->label->setStyleSheet("color: rgb(220, 220, 220)");
    ui->label_2->setStyleSheet("color: rgb(220, 220, 220)");
    ui->label_3->setStyleSheet("color: rgb(220, 220, 220)");
    ui->label_4->setStyleSheet("color: rgb(220, 220, 220)");
    ui->label_5->setStyleSheet("color: rgb(220, 220, 220)");
    ui->label_6->setStyleSheet("color: rgb(220, 220, 220)");
    ui->label_7->setStyleSheet("color: rgb(220, 220, 220)");
    ui->label_8->setStyleSheet("color: rgb(220, 220, 220)");
    ui->label_9->setStyleSheet("color: rgb(220, 220, 220)");
    ui->label_10->setStyleSheet("color: rgb(220, 220, 220)");
    ui->label_11->setStyleSheet("color: rgb(220, 220, 220)");
    ui->label_12->setStyleSheet("color: rgb(220, 220, 220)");
    ui->label_13->setStyleSheet("color: rgb(220, 220, 220)");
    ui->label_14->setStyleSheet("color: rgb(220, 220, 220)");
    ui->label_15->setStyleSheet("color: rgb(220, 220, 220)");
    ui->label_16->setStyleSheet("color: rgb(220, 220, 220)");
    ui->label_17->setStyleSheet("color: rgb(220, 220, 220)");
    ui->label_18->setStyleSheet("color: rgb(220, 220, 220)");

    ui->comboBox_data->setStyleSheet("QComboBox { background-color: rgb(200, 200, 200);}");
    ui->comboBox_data_2->setStyleSheet("QComboBox { background-color: rgb(200, 200, 200);}");
    ui->comboBox_time->setStyleSheet("QComboBox { background-color: rgb(200, 200, 200);}");
    ui->comboBox_time_2->setStyleSheet("QComboBox { background-color: rgb(200, 200, 200);}");
    ui->comboBox_lastservice->setStyleSheet("QComboBox { background-color: rgb(200, 200, 200);}");
    ui->comboBox_lastservice_2->setStyleSheet("QComboBox { background-color: rgb(200, 200, 200);}");
    ui->lineEdit_firstname->setStyleSheet("QLineEdit { background-color: rgb(220, 220, 220);}");
    ui->lineEdit_firstname_2->setStyleSheet("QLineEdit { background-color: rgb(220, 220, 220);}");
    ui->lineEdit_thirdname->setStyleSheet("QLineEdit { background-color: rgb(220, 220, 220);}");
    ui->lineEdit_thirdname_2->setStyleSheet("QLineEdit { background-color: rgb(220, 220, 220);}");
    ui->lineEdit_cost->setStyleSheet("QLineEdit { background-color: rgb(220, 220, 220);}");
    ui->lineEdit_cost_2->setStyleSheet("QLineEdit { background-color: rgb(220, 220, 220);}");
    ui->lineEdit_number->setStyleSheet("QLineEdit { background-color: rgb(220, 220, 220);}");
    ui->lineEdit_number_2->setStyleSheet("QLineEdit { background-color: rgb(220, 220, 220);}");
    ui->pushButton->setStyleSheet("QPushButton { background-color: rgb(200, 200, 200)}");
    ui->pushButton_2->setStyleSheet("QPushButton { background-color: rgb(200, 200, 200)}");
    ui->pushButton_3->setStyleSheet("QPushButton { background-color: rgb(200, 200, 200)}");
    ui->pushButton_edit_client->setStyleSheet("QPushButton { background-color: rgb(200, 200, 200)}");
    ui->tableWidget->setStyleSheet("QTableWiget { background-color: rgb(200, 200, 200)}");

    ui->lineEdit_number->setMaxLength(11);
    ui->lineEdit_number_2->setMaxLength(11);
    ui->lineEdit_cost->setMaxLength(4);
    ui->lineEdit_cost_2->setMaxLength(4);
    ui->lineEdit_firstname->setMaxLength(20);
    ui->lineEdit_firstname_2->setMaxLength(20);
    ui->lineEdit_thirdname->setMaxLength(15);
    ui->lineEdit_thirdname_2->setMaxLength(15);
    ui->lineEdit->setMaxLength(4);

    ui->lineEdit_firstname->setValidator(word_check);
    ui->lineEdit_firstname_2->setValidator(word_check);
    ui->lineEdit_thirdname->setValidator(word_check);
    ui->lineEdit_thirdname_2->setValidator(word_check);
    ui->lineEdit_cost->setValidator(int_check);
    ui->lineEdit_cost_2->setValidator(int_check);
    ui->lineEdit_number->setValidator(int_check);
    ui->lineEdit_number_2->setValidator(int_check);
    ui->lineEdit->setValidator(int_check);

    QDateTime date1 = QDateTime::currentDateTime();
     set_standart_combobox_time();
    //19:30 до 00::00
    if ((date1.time().hour() >= 19) )
    {

        ui->comboBox_data->addItem("");
        ui->comboBox_data->addItem(date1.addDays(+1).toString("dd/MM/yy"));
        ui->comboBox_data->addItem(date1.addDays(+2).toString("dd/MM/yy"));
        ui->comboBox_data->addItem(date1.addDays(+3).toString("dd/MM/yy"));
        ui->comboBox_data->addItem(date1.addDays(+4).toString("dd/MM/yy"));
        ui->comboBox_data->addItem(date1.addDays(+5).toString("dd/MM/yy"));
        ui->comboBox_data->addItem(date1.addDays(+6).toString("dd/MM/yy"));
        ui->comboBox_data->addItem(date1.addDays(+7).toString("dd/MM/yy"));

        ui->comboBox_data_2->addItem("");
        ui->comboBox_data_2->addItem(date1.addDays(+1).toString("dd/MM/yy"));
        ui->comboBox_data_2->addItem(date1.addDays(+2).toString("dd/MM/yy"));
        ui->comboBox_data_2->addItem(date1.addDays(+3).toString("dd/MM/yy"));
        ui->comboBox_data_2->addItem(date1.addDays(+4).toString("dd/MM/yy"));
        ui->comboBox_data_2->addItem(date1.addDays(+5).toString("dd/MM/yy"));
        ui->comboBox_data_2->addItem(date1.addDays(+6).toString("dd/MM/yy"));
        ui->comboBox_data_2->addItem(date1.addDays(+7).toString("dd/MM/yy"));
    }

    if(date1.time().hour() < 10)
    {

        ui->comboBox_data->addItem("");
        ui->comboBox_data->addItem(date1.toString("dd/MM/yy"));
        ui->comboBox_data->addItem(date1.addDays(+1).toString("dd/MM/yy"));
        ui->comboBox_data->addItem(date1.addDays(+2).toString("dd/MM/yy"));
        ui->comboBox_data->addItem(date1.addDays(+3).toString("dd/MM/yy"));
        ui->comboBox_data->addItem(date1.addDays(+4).toString("dd/MM/yy"));
        ui->comboBox_data->addItem(date1.addDays(+5).toString("dd/MM/yy"));
        ui->comboBox_data->addItem(date1.addDays(+6).toString("dd/MM/yy"));

        ui->comboBox_data_2->addItem("");
        ui->comboBox_data_2->addItem(date1.toString("dd/MM/yy"));
        ui->comboBox_data_2->addItem(date1.addDays(+1).toString("dd/MM/yy"));
        ui->comboBox_data_2->addItem(date1.addDays(+2).toString("dd/MM/yy"));
        ui->comboBox_data_2->addItem(date1.addDays(+3).toString("dd/MM/yy"));
        ui->comboBox_data_2->addItem(date1.addDays(+4).toString("dd/MM/yy"));
        ui->comboBox_data_2->addItem(date1.addDays(+5).toString("dd/MM/yy"));
        ui->comboBox_data_2->addItem(date1.addDays(+6).toString("dd/MM/yy"));
    }
    // 10:00 до 19:30
    if ((date1.time().hour()>=10 && date1.time().hour() <=19))
    {
        ui->comboBox_data->addItem("");
        ui->comboBox_data->addItem(date1.toString("dd/MM/yy"));
        ui->comboBox_data->addItem(date1.addDays(+1).toString("dd/MM/yy"));
        ui->comboBox_data->addItem(date1.addDays(+2).toString("dd/MM/yy"));
        ui->comboBox_data->addItem(date1.addDays(+3).toString("dd/MM/yy"));
        ui->comboBox_data->addItem(date1.addDays(+4).toString("dd/MM/yy"));
        ui->comboBox_data->addItem(date1.addDays(+5).toString("dd/MM/yy"));
        ui->comboBox_data->addItem(date1.addDays(+6).toString("dd/MM/yy"));


        ui->comboBox_data_2->addItem("");
        ui->comboBox_data_2->addItem(date1.toString("dd/MM/yy"));
        ui->comboBox_data_2->addItem(date1.addDays(+1).toString("dd/MM/yy"));
        ui->comboBox_data_2->addItem(date1.addDays(+2).toString("dd/MM/yy"));
        ui->comboBox_data_2->addItem(date1.addDays(+3).toString("dd/MM/yy"));
        ui->comboBox_data_2->addItem(date1.addDays(+4).toString("dd/MM/yy"));
        ui->comboBox_data_2->addItem(date1.addDays(+5).toString("dd/MM/yy"));
        ui->comboBox_data_2->addItem(date1.addDays(+6).toString("dd/MM/yy"));
    }

    ui->comboBox_time_2->addItem("");
    ui->comboBox_time_2->addItem("10:00");
    ui->comboBox_time_2->addItem("10:30");
    ui->comboBox_time_2->addItem("11:00");
    ui->comboBox_time_2->addItem("11:30");
    ui->comboBox_time_2->addItem("12:00");
    ui->comboBox_time_2->addItem("12:30");
    ui->comboBox_time_2->addItem("13:00");
    ui->comboBox_time_2->addItem("13:30");
    ui->comboBox_time_2->addItem("14:00");
    ui->comboBox_time_2->addItem("14:30");
    ui->comboBox_time_2->addItem("15:00");
    ui->comboBox_time_2->addItem("15:30");
    ui->comboBox_time_2->addItem("16:00");
    ui->comboBox_time_2->addItem("16:30");
    ui->comboBox_time_2->addItem("17:00");
    ui->comboBox_time_2->addItem("17:30");
    ui->comboBox_time_2->addItem("18:00");
    ui->comboBox_time_2->addItem("18:30");
    ui->comboBox_time_2->addItem("19:00");
    ui->comboBox_time_2->addItem("19:30");

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    if (is_edit == false){ui->pushButton->setText("Добавить");}
}

static QString file_name="Новый проект";

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::GetRandomString()
{
   const QString possibleCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
   const int randomStringLength = 12;

   QString randomString;
   for(int i=0; i<randomStringLength; ++i)
   {
       int index = qrand() % possibleCharacters.length();
       QChar nextChar = possibleCharacters.at(index);
       randomString.append(nextChar);
   }
   return randomString;
}

QString MainWindow::GetRandomNumber()
{
   const QString possibleCharacters("1234567890");
   const int randomStringLength = 11;

   QString randomString;
   for(int i=0; i<randomStringLength; ++i)
   {
       int index = qrand() % possibleCharacters.length();
       QChar nextChar = possibleCharacters.at(index);
       randomString.append(nextChar);
   }
   return randomString;
}

QString MainWindow::GetRandomCost()
{
   const QString possibleCharacters("123456789");
   const int randomStringLength = 4;

   QString randomString;
   for(int i=0; i<randomStringLength; ++i)
   {
       int index = qrand() % possibleCharacters.length();
       QChar nextChar = possibleCharacters.at(index);
       randomString.append(nextChar);
   }
   return randomString;
}

void MainWindow::on_pushButton_clicked()
{
    if (is_edit == false)
    {
    QString  first_name = ui->lineEdit_firstname->text();
    QString  third_name = ui->lineEdit_thirdname->text();
    QString  number = ui->lineEdit_number->text();
    QString  last_service = ui->comboBox_lastservice->currentText();
    QString  data = ui->comboBox_data->currentText();
    QString  time = ui->comboBox_time->currentText();
    QString  cost = ui->lineEdit_cost->text();

    if (first_name.isEmpty()   ||
        third_name.isEmpty()   ||
        number.isEmpty()       ||
        last_service.isEmpty() ||
        data.isEmpty()         ||
        time.isEmpty()         ||
        cost.isEmpty())
    {
    QMessageBox::information(0, "Информация", "Необходимо заполнить все поля, чтобы записать клиента.");
    }
    else
    {
    Client *client1 = new Client (first_name,third_name,number,last_service,data,time,cost);
    this->client_vector.push_back(client1);

    QString buffer;
        buffer.setNum(counter + 1);
        rows.push_back(buffer);

        ui->tableWidget->insertRow(static_cast<short>(counter));
        ui->tableWidget->setVerticalHeaderLabels(rows);

        QTableWidgetItem *item = new QTableWidgetItem();
        item->setText(standart_register(client_vector[counter]->getFirstName()));
        ui->tableWidget->setItem(static_cast<short>(counter), 0, item);

        QTableWidgetItem *item1 = new QTableWidgetItem();
        item1->setText(standart_register(client_vector[counter]->getThirdName()));
        ui->tableWidget->setItem(static_cast<short>(counter), 1, item1);

        QTableWidgetItem *item2 = new QTableWidgetItem();
        item2->setText(this->client_vector[counter]->getNumber());
        ui->tableWidget->setItem(static_cast<short>(counter), 2, item2);

        QTableWidgetItem *item3 = new QTableWidgetItem();
        item3->setText(this->client_vector[counter]->getLastService());
        ui->tableWidget->setItem(static_cast<short>(counter),3,item3);

        QTableWidgetItem *item4 = new QTableWidgetItem();
        item4->setText(this->client_vector[counter]->getData());
        ui->tableWidget->setItem(static_cast<short>(counter),4,item4);

        QTableWidgetItem *item5 = new QTableWidgetItem();
        item5->setText(this->client_vector[counter]->getTime());
        ui->tableWidget->setItem(static_cast<short>(counter),5,item5);

        QTableWidgetItem *item6 = new QTableWidgetItem();
        item6->setText(this->client_vector[counter]->getCost());
        ui->tableWidget->setItem(static_cast<short>(counter),6,item6);

        line_edit_1_clear();
        counter++;
    }
    }
    if (is_edit == true)
    {
        QString  first_name = ui->lineEdit_firstname->text();
        QString  third_name = ui->lineEdit_thirdname->text();
        QString  number = ui->lineEdit_number->text();
        QString  last_service = ui->comboBox_lastservice->currentText();
        QString  data = ui->comboBox_data->currentText();
        QString  time = ui->comboBox_time->currentText();
        QString  cost = ui->lineEdit_cost->text();

        client_vector[static_cast<unsigned int>(chosed_row)]->setFirstName(standart_register(first_name));
        client_vector[static_cast<unsigned int>(chosed_row)]->setThirdName(standart_register(third_name));
        client_vector[static_cast<unsigned int>(chosed_row)]->setNumber(number);
        client_vector[static_cast<unsigned int>(chosed_row)]->setLastService(last_service);
        client_vector[static_cast<unsigned int>(chosed_row)]->setData(data);
        client_vector[static_cast<unsigned int>(chosed_row)]->setTime(time);
        client_vector[static_cast<unsigned int>(chosed_row)]->setCost(cost);

        bool old_blocked = ui->tableWidget->blockSignals(true);
        ui->tableWidget ->item(chosed_row, 0)->setText(client_vector[static_cast<unsigned int>(chosed_row)]->getFirstName());
        ui->tableWidget ->item(chosed_row, 1)->setText(client_vector[static_cast<unsigned int>(chosed_row)]->getThirdName());
        ui->tableWidget ->item(chosed_row, 2)->setText(client_vector[static_cast<unsigned int>(chosed_row)]->getNumber());
        ui->tableWidget ->item(chosed_row, 3)->setText(client_vector[static_cast<unsigned int>(chosed_row)]->getLastService());
        ui->tableWidget ->item(chosed_row, 4)->setText(client_vector[static_cast<unsigned int>(chosed_row)]->getData());
        ui->tableWidget ->item(chosed_row, 5)->setText(client_vector[static_cast<unsigned int>(chosed_row)]->getTime());
        ui->tableWidget ->item(chosed_row, 6)->setText(client_vector[static_cast<unsigned int>(chosed_row)]->getCost());
        ui->tableWidget->blockSignals(old_blocked);

        is_edit = false;
        line_edit_1_clear();
        ui->pushButton_cancel->setVisible(0);

        QMessageBox::information(this,"Информация","Информация о клиенте была изменена","ОК");
        ui->pushButton->setText("Добавить");
        can_you_delite = true;

    }

}

void MainWindow::line_edit_1_clear()
{
    ui->lineEdit_firstname->clear();
    ui->lineEdit_thirdname->clear();
    ui->lineEdit_number->clear();
    ui->comboBox_lastservice->setCurrentIndex(0);
    ui->comboBox_data->setCurrentIndex(0);
    ui->comboBox_time->setCurrentIndex(0);
    ui->lineEdit_cost->clear();
}

void MainWindow::line_edit_2_clear()
{
ui->lineEdit_firstname_2->clear();
ui->lineEdit_thirdname_2->clear();
ui->lineEdit_number_2->clear();
ui->comboBox_lastservice_2->setCurrentIndex(0);
ui->comboBox_data_2->setCurrentIndex(0);
ui->comboBox_time_2->setCurrentIndex(0);
ui->lineEdit_cost_2->clear();
}

void MainWindow::on_tableWidget_cellPressed(int row, int column)
{
    chosed_row = row;

    quest = true;
    edit_quest = true;
}

void MainWindow::on_pushButton_2_clicked()
{
    if(counter == 0 ){QMessageBox::warning(this, "", "Таблица пустая.");}
    if (client_vector.size()!=0 && chosed_row <= static_cast<int>(client_vector.size()) && quest == true && can_you_delite)
    {
    try {
        chosed_row = ui->tableWidget->selectionModel()->currentIndex().row();

       ui->tableWidget->removeRow(chosed_row);

        for(int i = chosed_row; i < rows.size() - 1; ++i)
        {
            QString str;
            str.setNum(i+1);
            rows[i] = str;
        }
        rows.erase(--rows.end());
        ui->tableWidget->setVerticalHeaderLabels(rows);

        client_vector.erase(client_vector.begin() + chosed_row);
        counter--;
        chosed_row= static_cast<int>(client_vector.size()) - 1;

        } catch (...) {
            return;
        }
        quest = false;
        edit_quest = false;
    }
}



void MainWindow::on_pushButton_3_clicked()
{
    QString firstname_string = ui->lineEdit_firstname_2->text().toLower();
       QString thirdname_string = ui->lineEdit_thirdname_2->text().toLower();
       QString number_string = ui->lineEdit_number_2->text();
       QString lastservice_string = ui->comboBox_lastservice_2->currentText();
       QString date_string = ui->comboBox_data_2->currentText();
       QString time_string = ui->comboBox_time_2->currentText();
       QString cost_string = ui->lineEdit_cost_2->text();
       bool is_table_update = false;


       if(client_vector.size() == 0)
       {
           QMessageBox::warning(this, "Ошибка", "Добавьте, или откройте базу с клиентами, чтобы осуществить поиск.");
           is_show_error = true;
       }

       if(firstname_string.isEmpty()   &&
          thirdname_string.isEmpty()   &&
          number_string.isEmpty()      &&
          lastservice_string.isEmpty() &&
          date_string.isEmpty()        &&
          time_string.isEmpty()        &&
          cost_string.isEmpty()        &&
          is_show_error == false       )

       {QMessageBox::warning(this, "Ошибка", "Укажите критерии поиска.");}

       else
       {
       serch->serch_results.clear();

       line_edit_2_clear();

       for(size_t i = 0; i < client_vector.size(); ++i)
       {
           bool firstname_is_serch = true;
           bool thirdname_is_serch = true;
           bool number_is_serch = true;
           bool lastservice_is_serch = true;
           bool date_is_serch = true;
           bool time_is_serch = true;
           bool cost_is_serch = true;

           if(!firstname_string.isEmpty())
           {
               QString firstname_ = client_vector[i]->getFirstName().toLower();
               if(!firstname_.contains(firstname_string)){firstname_is_serch = false;}
           }

           if(!thirdname_string.isEmpty())
           {
               QString thirdname_ = client_vector[i]->getThirdName().toLower();
               if(!thirdname_.contains(thirdname_string)){thirdname_is_serch = false;}
           }

           if(!number_string.isEmpty())
           {
               QString number_ = client_vector[i]->getNumber();
               if(number_ != number_string){number_is_serch = false;}
           }

           if(!lastservice_string.isEmpty())
           {
               QString lastservice_ = client_vector[i]->getLastService();
               if(lastservice_ != lastservice_string){lastservice_is_serch = false;}
           }

           if(!date_string.isEmpty())
           {
               QString date_ = client_vector[i]->getData();
               if(date_ != date_string){date_is_serch = false;}
           }

           if(!time_string.isEmpty())
           {
               QString time_ = client_vector[i]->getTime();
               if(time_ != time_string){time_is_serch = false;}

           }

           if(!cost_string.isEmpty())
           {
               QString cost_ = client_vector[i]->getCost();
               if(cost_ != cost_string){cost_is_serch = false;}
           }


           if(firstname_is_serch && thirdname_is_serch && number_is_serch && lastservice_is_serch && date_is_serch && time_is_serch && cost_is_serch)
           {
                 serch->serch_results.push_back(client_vector[i]);
           }
           serch->updateTable();
           is_table_update= true;
           }
       int serch_row_count = serch->rowCount();
       if (serch_row_count == 0 && is_show_error == false){QMessageBox::warning(this, "Ошибка", "Соответствий критериям поиска не было найдено.");}
       if (is_table_update == true){serch->show();}

   }
       is_show_error = false;
//}
   }

void MainWindow::on_comboBox_lastservice_currentIndexChanged(int index)
{
    if (ui->comboBox_lastservice->currentIndex() == 1){ui->lineEdit_cost->setText("350");}
    if (ui->comboBox_lastservice->currentIndex() == 2){ui->lineEdit_cost->setText("550");}
    if (ui->comboBox_lastservice->currentIndex() == 3){ui->lineEdit_cost->setText("900");}
    if (ui->comboBox_lastservice->currentIndex() == 4){ui->lineEdit_cost->setText("600");}
    if (ui->comboBox_lastservice->currentIndex() == 5){ui->lineEdit_cost->setText("1500");}
    if (ui->comboBox_lastservice->currentIndex() == 6){ui->lineEdit_cost->setText("2000");}
    if (ui->comboBox_lastservice->currentIndex() == 7){ui->lineEdit_cost->setText("1800");}
    if (ui->comboBox_lastservice->currentIndex() == 8){ui->lineEdit_cost->setText("2500");}
    if (ui->comboBox_lastservice->currentIndex() == 9){ui->lineEdit_cost->setText("1400");}
}

void MainWindow::on_comboBox_data_currentIndexChanged(const QString &arg1)
{
    bool is_today = false;
    ui->comboBox_time->clear();
    set_standart_combobox_time();

    if ((ui->comboBox_data->currentText() == QDate::currentDate().toString("dd/MM/yy") && is_today == true))
    {

        int current_time_hour     = QTime::currentTime().hour();
        int current_time_minutes  = QTime::currentTime().minute();
        QString buffer;

        if (current_time_minutes<30)
        {
            QString true_time;
            true_time.append(QString::number(current_time_hour).append(":30"));;
            ui->comboBox_time->addItem("");
            ui->comboBox_time->addItem(true_time);
            buffer = true_time;
        }
        if(current_time_minutes >= 30)
        {
            QString true_time;
            true_time.append(QString::number(current_time_hour+1).append(":00"));;
            ui->comboBox_time->addItem("");
            ui->comboBox_time->addItem(true_time);
            buffer=true_time;
        }    
        for (int i=current_time_hour; i<19;)
        {
            QString last_two_char = buffer.mid(3,2);
            if (last_two_char == "30")
            {
                QString true_time1;
                true_time1.append(QString::number(i+1).append(":00"));;
                ui->comboBox_time->addItem(true_time1);
                buffer = true_time1;

            }

            else
            {
                QString true_time1;
                true_time1.append(QString::number(i+1).append(":30"));;
                ui->comboBox_time->addItem(true_time1);
                buffer = true_time1;
                i++;
            }
        }

        }

}

void MainWindow::set_standart_combobox_time()
{
    ui->comboBox_time->clear();
    ui->comboBox_time->addItem("");
    ui->comboBox_time->addItem("10:00");
    ui->comboBox_time->addItem("10:30");
    ui->comboBox_time->addItem("11:00");
    ui->comboBox_time->addItem("11:30");
    ui->comboBox_time->addItem("12:00");
    ui->comboBox_time->addItem("12:30");
    ui->comboBox_time->addItem("13:00");
    ui->comboBox_time->addItem("13:30");
    ui->comboBox_time->addItem("14:00");
    ui->comboBox_time->addItem("14:30");
    ui->comboBox_time->addItem("15:00");
    ui->comboBox_time->addItem("15:30");
    ui->comboBox_time->addItem("16:00");
    ui->comboBox_time->addItem("16:30");
    ui->comboBox_time->addItem("17:00");
    ui->comboBox_time->addItem("17:30");
    ui->comboBox_time->addItem("18:00");
    ui->comboBox_time->addItem("18:30");
    ui->comboBox_time->addItem("19:00");
    ui->comboBox_time->addItem("19:30");
}

void MainWindow::on_pushButton_edit_client_clicked()
{
    if(counter == 0 )
    {
        QMessageBox::warning(this, "", "Таблица пустая. Вам нечего редактировать.");
        edit_quest = false;

    }
    else
    {
    if (edit_quest == true)
    {
        ui->pushButton_cancel->setVisible(1);
        can_you_delite = false;
        ui->pushButton->setText("Применить редактирование");
        set_standart_combobox_time();

        chosed_row = ui->tableWidget->selectionModel()->currentIndex().row();
        unsigned int i = static_cast<unsigned int>(chosed_row);

        QString service_local = client_vector[i] ->getLastService();
        QString date_local = client_vector[i] -> getData();
        QString time_local = client_vector[i] -> getTime();

        int service_local_index = ui->comboBox_lastservice->findText(service_local);
        int date_local_index = ui->comboBox_data->findText(date_local);
        int time_local_index = ui->comboBox_time->findText(time_local);

        ui->lineEdit_firstname->setText(standart_register(client_vector[i]->getFirstName()));
        ui->lineEdit_thirdname->setText(standart_register(client_vector[i]->getThirdName()));
        ui->lineEdit_number->setText(client_vector[i]->getNumber());
        ui->lineEdit_cost->setText(client_vector[i]->getCost());

        ui->comboBox_lastservice->setCurrentIndex(service_local_index);
        ui->comboBox_data->setCurrentIndex(0);
        ui->comboBox_time->setCurrentIndex(0);

        is_edit = true;
        quest = false;
        edit_quest = false;
    }
    else
    {
        QMessageBox::warning(this, "Предупреждения", "Чтобы отредактировать клиента, нажмите на любое поле нужного клиента в таблице.");
        edit_quest = false;
    }
    }
}

void MainWindow::show_project()
{
    QWidget::setWindowTitle("Парикмахерская\" "+file_name);
}

QString MainWindow::standart_register(QString string)
  {
      QString string1 = string.right(string.size()-1).toLower();
      QString string2 = string.left(1).toUpper();
      string = string2.append(string1);
      return string;
  }

void MainWindow::show_vector_in_table(){
    ui->tableWidget->setRowCount(0);
    if (client_vector.size() != 0)
     {
      for(unsigned int i=0;i<client_vector.size();i++)
      {
          QString buffer;
          buffer.setNum(counter + 1);
          rows.push_back(buffer);

          ui->tableWidget->insertRow(static_cast<short>(counter));
          ui->tableWidget->setVerticalHeaderLabels(rows);

          QTableWidgetItem *item = new QTableWidgetItem(); 
          item->setText(standart_register(client_vector[counter]->getFirstName()));
          ui->tableWidget->setItem(static_cast<short>(counter), 0, item);

          QTableWidgetItem *item1 = new QTableWidgetItem();
          item1->setText(standart_register(client_vector[counter]->getThirdName()));
          ui->tableWidget->setItem(static_cast<short>(counter), 1, item1);

          QTableWidgetItem *item2 = new QTableWidgetItem();
          item2->setText(this->client_vector[counter]->getNumber());
          ui->tableWidget->setItem(static_cast<short>(counter), 2, item2);

          QTableWidgetItem *item3 = new QTableWidgetItem();
          item3->setText(this->client_vector[counter]->getLastService());
          ui->tableWidget->setItem(static_cast<short>(counter),3,item3);

          QTableWidgetItem *item4 = new QTableWidgetItem();
          item4->setText(this->client_vector[counter]->getData());
          ui->tableWidget->setItem(static_cast<short>(counter),4,item4);

          QTableWidgetItem *item5 = new QTableWidgetItem();
          item5->setText(this->client_vector[counter]->getTime());
          ui->tableWidget->setItem(static_cast<short>(counter),5,item5);

          QTableWidgetItem *item6 = new QTableWidgetItem();
          item6->setText(this->client_vector[counter]->getCost());
          ui->tableWidget->setItem(static_cast<short>(counter),6,item6);

          line_edit_1_clear();
          counter++;
      }
     }
}

void MainWindow::on_action_save_triggered()
{
    QStringList save_project;
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    if(file_name=="Новый проект")
    {
         QString my_file = QFileDialog::getSaveFileName(this, tr("Сохранить как"), QDir::currentPath(), tr("File (*.txt)") );
         if(!my_file.isEmpty()){file_name=my_file;}
    }

    QFile file(file_name);
    file.remove();
   if ((file.open(QIODevice::WriteOnly)))
        {
        for(unsigned int i=0;i<client_vector.size();i++)
            {
                save_project<<client_vector[i]->getFirstName().toUtf8()<<"\n";
                save_project<<client_vector[i]->getThirdName().toUtf8()<<"\n";
                save_project<<client_vector[i]->getNumber().toUtf8()<<"\n";
                save_project<<client_vector[i]->getLastService().toUtf8()<<"\n";
                save_project<<client_vector[i]->getData().toUtf8()<<"\n";
                save_project<<client_vector[i]->getTime().toUtf8()<<"\n";
                save_project<<client_vector[i]->getCost().toUtf8()<<"\n";
            }
            QTextStream stream(&file);
            foreach(QString s, save_project){stream<<s;}
         }

         file.close();
         show_project();
}

void MainWindow::on_action_save_as_triggered()
{
    QStringList save_project;
    for(unsigned int i=0;i<client_vector.size();i++)
        {
            save_project<<client_vector[i]->getFirstName().toUtf8()<<"\n";
            save_project<<client_vector[i]->getThirdName().toUtf8()<<"\n";
            save_project<<client_vector[i]->getNumber().toUtf8()<<"\n";
            save_project<<client_vector[i]->getLastService().toUtf8()<<"\n";
            save_project<<client_vector[i]->getData().toUtf8()<<"\n";
            save_project<<client_vector[i]->getTime().toUtf8()<<"\n";
            save_project<<client_vector[i]->getCost().toUtf8()<<"\n";
        }
    QString my_file = QFileDialog::getSaveFileName(this, tr("Сохранить как"), QDir::currentPath(), tr("File (*.txt)") );
    if(!my_file.isEmpty())
    {
    QFile young(my_file);
    QFile old(file_name);
    old.close();
    young.open(QIODevice::WriteOnly);
    old.open(QIODevice::ReadOnly);
    QByteArray my_buf = old.readAll();
    young.write(my_buf);
    young.close();
    file_name=my_file;
    show_project();

    }
}

void MainWindow::on_action_open_triggered()
{
        QMessageBox:: StandardButton reply = QMessageBox::question(this,
                                                                   "Предупреждение","Сохранить текущий проект перед открытием следующего?",
                                                                   QMessageBox::Yes | QMessageBox::No);
             if (reply==QMessageBox::Yes)
             {
                 on_action_save_triggered();

             }



                chosed_row = 0;
                counter = 0;
                rows.clear();
                client_vector.clear();

                QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
                QString my_file =  QFileDialog::getOpenFileName(this, tr("Открыть"), QDir::currentPath(), tr("File (*.txt)"));
                QStringList open_project;
                if(!my_file.isEmpty())
                {
                    file_name=my_file;
                    client_vector.clear();
                    QFile file(file_name);

                    if (file.open(QIODevice::ReadOnly))
                    {
                    while(!file.atEnd()){open_project<<file.readLine( );}
                    }
                    file.close();

        for(int i=0;i<open_project.size();i+=7){

           QString firstname1 = open_project[i];
           QString thirdname1 = open_project[i+1];
           QString number1 = open_project[i+2];
           QString lastservice1 = open_project[i+3];
           QString date1 = open_project[i+4];
           QString time1 = open_project[i+5];
           QString cost1 = open_project[i+6];

           firstname1.remove(firstname1.size() - 1, 2);
           thirdname1.remove(thirdname1.size() - 1, 2);
           number1.remove(number1.size() - 1, 2);
           lastservice1.remove(lastservice1.size() - 1, 2);
           date1.remove(date1.size() - 1, 2);
           time1.remove(time1.size() - 1, 2);
           cost1.remove(cost1.size() - 1, 2);

           Client *client1 = new Client(firstname1, thirdname1, number1, lastservice1, date1, time1, cost1);
           client_vector.push_back(client1);
        }
        line_edit_1_clear();
        line_edit_2_clear();
        show_vector_in_table();
        show_project();
      }
}



void MainWindow::on_action_close_triggered()
{
    QMessageBox:: StandardButton reply = QMessageBox::question(this,"Выход","Сохранить перед закрытием?",QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
         if (reply==QMessageBox::Yes)
         {
             on_action_save_triggered();
             QApplication::quit();
         }
         if (reply==QMessageBox::No)
         {
             QApplication::quit();
         }
}

void MainWindow::on_action_csv_triggered()
{




        if(counter<=0){
            QMessageBox *msgBox = new QMessageBox(QMessageBox::Information,"Внимание","Таблица пуста!!!",QMessageBox::Ok);
            msgBox->setButtonText(QMessageBox::Ok, tr("ОК"));
            if(msgBox->exec() == QMessageBox::Ok){}}
        else{
        QString S33="Файл сохранён по пути";
        QString S34 = QFileDialog::getSaveFileName(this,tr("Сохранить"),QDir::currentPath(),tr("Документы Excel (*.csv);"),0,QFileDialog::DontConfirmOverwrite);
        QString h1;
        if (!S34.isNull()){
        QFile f(S34);
        QFile::remove(S34);
            if( f.open( (QIODevice::ReadOnly | QIODevice::WriteOnly | QIODevice::Append) ))
            {
                QTextStream ts(&f);
                QStringList strList;
                for( int c = 0; c < ui->tableWidget->horizontalHeader()->count(); ++c )
                strList << ui->tableWidget->model()->headerData(c, Qt::Horizontal).toString();
                for( int r = 0; r < ui->tableWidget->verticalHeader()->count(); ++r )
                {
                ts << ui->tableWidget->model()->headerData(r-counter, Qt::Vertical).toString();
                for( int c =0; c < ui->tableWidget->horizontalHeader()->count(); ++c )
                {
                    ts << ui->tableWidget->model()->data(ui->tableWidget->model()->index(r, c), Qt::DisplayRole).toString() << ";";
                }
                ts << "\n";
                }
                  f.close();
            }
         S33=S33+" "+S34;
         QMessageBox *msgBox = new QMessageBox(QMessageBox::Information,"Внимание",S33,QMessageBox::Ok);
         msgBox->setButtonText(QMessageBox::Ok, tr("ОК"));
         if(msgBox->exec() == QMessageBox::Ok){}
          exit(1);}
         else{
            QMessageBox *msgBox = new QMessageBox(QMessageBox::Information,"Внимание","Неверно выбран файл!",QMessageBox::Ok);
            msgBox->setButtonText(QMessageBox::Ok, tr("ОК"));
            if(msgBox->exec() == QMessageBox::Ok){}
          }
          }


}

void MainWindow::on_pushButton_cancel_clicked()
{
    is_edit = false;
    line_edit_1_clear();
    ui->pushButton->setText("Добавить");
    can_you_delite = true;
    ui->pushButton_cancel->setVisible(0);
}


void MainWindow::on_pushButton_genirate_clicked()
{


    for (int i=0;i<ui->lineEdit->text().toInt(); i++)
    {
        QString buf;
        QFile file("russian_surnames.txt");


        QString  first_name = GetRandomString();
        QString  third_name = GetRandomString();
        QString  number = GetRandomNumber();
        ui->comboBox_lastservice->setCurrentIndex(rand() % 9 +1);
        QString  last_service = ui->comboBox_lastservice->currentText();
        ui->comboBox_lastservice->setCurrentIndex(0);
        ui->comboBox_data->setCurrentIndex(rand() % 5 +1);
        QString  data = ui->comboBox_data->currentText();
        ui->comboBox_lastservice->setCurrentIndex(0);
        ui->comboBox_time->setCurrentIndex(rand() % 7 +1);
        QString  time = ui->comboBox_time->currentText();
        ui->comboBox_time->setCurrentIndex(0);
        on_comboBox_lastservice_currentIndexChanged(0);
        QString  cost = ui->lineEdit_cost->text();

        Client *client1 = new Client (first_name,third_name,number,last_service,data,time,cost);
        this->client_vector.push_back(client1);

        QString buffer;
            buffer.setNum(counter + 1);
            rows.push_back(buffer);

            ui->tableWidget->insertRow(static_cast<short>(counter));
            ui->tableWidget->setVerticalHeaderLabels(rows);

            QTableWidgetItem *item = new QTableWidgetItem();
            item->setText(standart_register(client_vector[counter]->getFirstName()));
            ui->tableWidget->setItem(static_cast<short>(counter), 0, item);

            QTableWidgetItem *item1 = new QTableWidgetItem();
            item1->setText(standart_register(client_vector[counter]->getThirdName()));
            ui->tableWidget->setItem(static_cast<short>(counter), 1, item1);

            QTableWidgetItem *item2 = new QTableWidgetItem();
            item2->setText(this->client_vector[counter]->getNumber());
            ui->tableWidget->setItem(static_cast<short>(counter), 2, item2);

            QTableWidgetItem *item3 = new QTableWidgetItem();
            item3->setText(this->client_vector[counter]->getLastService());
            ui->tableWidget->setItem(static_cast<short>(counter),3,item3);

            QTableWidgetItem *item4 = new QTableWidgetItem();
            item4->setText(this->client_vector[counter]->getData());
            ui->tableWidget->setItem(static_cast<short>(counter),4,item4);

            QTableWidgetItem *item5 = new QTableWidgetItem();
            item5->setText(this->client_vector[counter]->getTime());
            ui->tableWidget->setItem(static_cast<short>(counter),5,item5);

            QTableWidgetItem *item6 = new QTableWidgetItem();
            item6->setText(this->client_vector[counter]->getCost());
            ui->tableWidget->setItem(static_cast<short>(counter),6,item6);

            counter++;




    }

    ui->lineEdit->clear();
    ui->comboBox_data->setCurrentIndex(0);
    ui->comboBox_time->setCurrentIndex(0);
    ui->comboBox_lastservice->setCurrentIndex(0);

}

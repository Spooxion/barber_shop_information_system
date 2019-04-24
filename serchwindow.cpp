#include "serchwindow.h"

#include "ui_serchwindow.h"

SerchWindow::SerchWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SerchWindow)
{
    ui->setupUi(this);
    QPixmap *backgnd = new QPixmap(":/new/back/Images/Images/back.png");
    QPalette *palette = new QPalette;
    palette->setBrush(QPalette::Window, QBrush(*backgnd));
    this->setPalette(*palette);
    ui->label->setStyleSheet("color: rgb(220, 220, 220)");
}

int SerchWindow::rowCount(){
    int row_count = ui->tableWidget->rowCount();
    return row_count;
}
void SerchWindow::updateTable()
{
    //TODO: update inf in table, use vector
    ui->tableWidget->setRowCount(static_cast<int>(serch_results.size()));
    ui->tableWidget->setVerticalHeaderLabels(rows);

   for (unsigned int i=0; i < serch_results.size(); ++i)
        {

        QTableWidgetItem *item = new QTableWidgetItem();
        item->setText(serch_results[i]->getFirstName());
        ui->tableWidget->setItem(static_cast<int>(i), 0, item);

        QTableWidgetItem *item1 = new QTableWidgetItem();
        item1->setText(serch_results[i]->getThirdName());
        ui->tableWidget->setItem(static_cast<int>(i), 1, item1);

        QTableWidgetItem *item2 = new QTableWidgetItem();
        item2->setText(serch_results[i]->getNumber());
        ui->tableWidget->setItem(static_cast<int>(i), 2, item2);

        QTableWidgetItem *item3 = new QTableWidgetItem();
        item3->setText(serch_results[i]->getLastService());
        ui->tableWidget->setItem(static_cast<int>(i), 3, item3);

        QTableWidgetItem *item4 = new QTableWidgetItem();
        item4->setText(serch_results[i]->getData());
        ui->tableWidget->setItem(static_cast<int>(i), 4, item4);

        QTableWidgetItem *item5 = new QTableWidgetItem();
        item5->setText(serch_results[i]->getTime());
        ui->tableWidget->setItem(static_cast<int>(i), 5, item5);

        QTableWidgetItem *item6 = new QTableWidgetItem();
        item6->setText(serch_results[i]->getCost());
        ui->tableWidget->setItem(static_cast<int>(i), 6, item6);
        }
}

SerchWindow::~SerchWindow()
{
    delete ui;
}

void SerchWindow::on_pushButton_clicked()
{
    ui->tableWidget->setRowCount(0);
    this->close();
}

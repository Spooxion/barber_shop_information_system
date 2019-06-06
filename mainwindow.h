#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QMessageBox>
#include <QPixmap>
#include <QLineEdit>
#include <QMenu>
#include <QHeaderView>
#include <vector>
#include <QDate>
#include <QTime>
#include <QDateTime>
#include <QDebug>
#include <QtDebug>
#include "client.h"
#include "serchwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_tableWidget_cellPressed(int row, int column);
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_comboBox_lastservice_currentIndexChanged(int index);
    void on_comboBox_data_currentIndexChanged(const QString &arg1);
    void on_pushButton_edit_client_clicked();
    void on_action_open_triggered();
    void on_action_save_triggered();
    void on_action_save_as_triggered();
    void on_action_csv_triggered();
    void on_action_close_triggered();
    void line_edit_1_clear();
    void line_edit_2_clear();
    void show_project();
    void show_vector_in_table();
    void set_standart_combobox_time();
    QString standart_register(QString string);
    QString GetRandomString();
    QString GetRandomNumber();
    QString GetRandomCost();
    void on_pushButton_cancel_clicked();
    void on_pushButton_genirate_clicked();

private:
    Ui::MainWindow *ui;
    int chosed_row;
    bool is_project_save = false;
    bool quest = false;
    bool edit_quest = false;
    bool is_edit = false;
    bool can_you_delite = true;
    bool is_show_error = false;
    unsigned int counter = 0;
    QStringList rows;
    std::vector <Client*> client_vector;
    SerchWindow *serch;
};

#endif // MAINWINDOW_H

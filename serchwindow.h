#ifndef SERCHWINDOW_H
#define SERCHWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QMessageBox>
#include <QPixmap>
#include <QLineEdit>
#include <QHeaderView>
#include <vector>

#include "client.h"

namespace Ui {
class SerchWindow;
}

class SerchWindow : public QMainWindow
{
    Q_OBJECT

public:
    std::vector <Client*> serch_results;
    QStringList columns;
    QStringList rows;
    explicit SerchWindow(QWidget *parent = nullptr);
    void updateTable();
    int rowCount();
    void showTitle();
    ~SerchWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::SerchWindow *ui;

};

#endif // SERCHWINDOW_H

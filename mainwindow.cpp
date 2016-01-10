#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore/qmath.h>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    double dx = ui->x2Val->text().toDouble() - ui->x1Val->text().toDouble();
    double dy = ui->y2Val->text().toDouble() - ui->y1Val->text().toDouble();

    double dl = qSqrt(dx * dx + dy * dy);

    double az = qAtan2(dx,dy) * 200 / M_PI;
    if(az < 0)
        az += 400;

    //double az = dx + dy;
    ui->azymut_wynik->setText(QString::number(az));
    ui->dlugosc_wynik->setText(QString::number(dl));
}

void MainWindow::on_actionZamknij_triggered()
{
    this->close();
}

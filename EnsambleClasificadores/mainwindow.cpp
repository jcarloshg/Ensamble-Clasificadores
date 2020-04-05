#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QDebug>
#include <Qfile>
#include <fstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_abrirArchivo_clicked()
{
    rutaArchivo = QFileDialog::getOpenFileName(
                this, tr("Selecione el archivo :)"), "..//", "Text files (*.txt)");

    QFile archivo(rutaArchivo);
    if(!archivo.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream leer(&archivo);
    QString aux;

    leer >> aux;
    elementos = aux.toInt();

    leer >> aux;
    atributos = aux.toInt();

    leer >> aux;
    clases = aux.toInt();

    qDebug() << elementos << atributos << clases;

    int row = 1;
    while (!leer.atEnd()) {
        QString plok;
        leer >> plok;
        QStringList lista = plok.split(',', QString::SkipEmptyParts);
        qDebug() << "row " << row << "\n" << lista;
        row++;
    }
}

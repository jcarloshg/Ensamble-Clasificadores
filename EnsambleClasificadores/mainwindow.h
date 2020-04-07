#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_abrirArchivo_clicked();
    void actualizarDatos();

private:
    Ui::MainWindow *ui;
    QString rutaArchivo;
    int elementos;
    int atributos;
    int clases;
};
#endif // MAINWINDOW_H

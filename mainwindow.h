#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "spectrwidget.h"
#include "form_spectr.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
signals:
    void get_control(Form_Spectr  *control);
private slots:
    void closing();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

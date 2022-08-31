#ifndef __mainwindow_H
#define __mainwindow_H

#include "ui_mainwindow.h"

class MainWindow final : public QMainWindow
{
public:
    explicit MainWindow(QWidget *pWgt = nullptr);

private:
    Ui::MainWindow ui{};
};

#endif /*__mainwindow_H*/
#ifndef __mainwindow_H
#define __mainwindow_H

#include "MainWindowBase.h"

class MainWindow : public MainWindowBase
{
public:
    explicit MainWindow(QWidget *pWgt = nullptr);
    //void addDevice() override;
};

#endif /*__mainwindow_H*/
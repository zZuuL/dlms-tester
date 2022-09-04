#ifndef __mainwindow_H
#define __mainwindow_H

#include "mainwindowbase.h"

class MainWindow final : public MainWindowBase
{
public:
    explicit MainWindow(QWidget *pWgt = nullptr);
};

#endif /*__mainwindow_H*/
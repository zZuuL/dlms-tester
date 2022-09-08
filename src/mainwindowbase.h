#ifndef __mainwindowbase_H
#define __mainwindowbase_H

#include "ui_mainwindow.h"


//---------------------------------------------------------------------------//

class MainWindowBase : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowBase(QWidget *pWgt = 0);

private slots:
    void actionHandler();

private:
    Ui::MainWindow ui_;
};


//---------------------------------------------------------------------------//


#endif /*__mainwindowbase_H*/

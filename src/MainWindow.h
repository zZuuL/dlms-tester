#ifndef __mainwindow_H
#define __mainwindow_H

#include "MainWindowBase.h"

//---------------------------------------------------------------------------//

class MainWindow : public MainWindowBase
{
public:
    explicit MainWindow(QWidget *pWgt = nullptr);

    bool init() override;
    bool fini() override;
    void adddevice() override;
};


//---------------------------------------------------------------------------//



#endif /*__mainwindow_H*/
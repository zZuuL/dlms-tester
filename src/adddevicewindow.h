#ifndef __adddevicewindow_H
#define __adddevicewindow_H

#include "ui_adddevicewindow.h"

//---------------------------------------------------------------------------//

class AddDeviceWindow final : public QDialog
{
public:
    explicit AddDeviceWindow(QWidget* pWgt /*= 0*/);

private:
    Ui::AddDeviceWindow ui_;
};

//---------------------------------------------------------------------------//



#endif /*__adddevicewindow_H*/

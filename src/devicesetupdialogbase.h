#ifndef __devicesetupdialogbase_H
#define __devicesetupdialogbase_H


#include "ui_devicesetupdialog.h"


//---------------------------------------------------------------------------//

class DeviceSetupDialogBase : public QDialog
{
public:
    explicit DeviceSetupDialogBase(QWidget* pWgt = 0);
private:
    Ui::DeviceSetupDialog ui_;
};

//---------------------------------------------------------------------------//


#endif /*__devicesetupdialogbase_*/

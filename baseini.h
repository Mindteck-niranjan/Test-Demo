/////////////////////////////////////////////////////////////////////////////
///
/// @copyright
///     Copyright (C) 2021 Remote Diagnostic Technologies Ltd.
///
/// @brief
///    The baseini class - Basically variable declaration and
///    function declaration  has been done in this class.
///
/// @authors Qt Creator Wizard and Saptarshi
///
//////////////////////////////////////////////////////////////////////////////
#ifndef BASEINI_H
#define BASEINI_H

#include"Common/Variables/inivariableenum.h"
#include "MajorModules/ConfigFileUtility/configfileutility.h"
#include "MajorModules/UserInterface/UserInterfaceVariables.h"
/////////////////////////////////////////////////////////////////////////////
/// @brief
/// This is MpmVariableTable Class
//////////////////////////////////////////////////////////////////////////////
class BaseINI {
 public:
    BaseINI();
    ~BaseINI();
    void setFloat(IniVariable ini, float *variable);
    void setInt(IniVariable ini, int32_t *variable);
    void setFactoryAlarmLimitsFloat(
            IniVariable iniAlarm,
            IniVariable ini,
            CDefaultMedicalValue <float> *variableAlarm,
            float *variable,
            ConfigFileZone configZone);
    void setFactoryAlarmLimitsInt(
            IniVariable iniAlarm,
            IniVariable ini,
            CDefaultMedicalValue <int32_t> *variableAlarm,
            int32_t *variable,
            ConfigFileZone configZone);
    int32_t updateIniFloat(IniVariable ini,
                           CDefaultMedicalValue <float> variableAlarm,
                           float var);
    int32_t updateIniInt(IniVariable ini,
                           CDefaultMedicalValue <int32_t> variableAlarm,
                           int32_t var);

 protected:
    // Variable declarations

    // Mutex for Control variables
    pthread_mutex_t *m_mutexCtrl;

    // ConfigFileUtility module pointer
    ConfigFileUtility *m_configFileUtility;


    // Pointer to set and get the DemoMedicalReading variable value in UI module
    UserInterfaceVariables* m_uiVariableInstance;
};

#endif  // BASEINI_H

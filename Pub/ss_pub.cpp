﻿#include <QMetaType>
#include "ss_pub.h"

PUBComClass  PUB_SS;

PUBComClass::PUBComClass()
{

}

PUBComClass::~PUBComClass()
{

}

QString PUBComClass::Pub_GetUserDataPath()
{
    /// 得到application data目录 programdata
    char szPath[256];
    QString UserDataPath=NULL;
    TCHAR path[300];
    SHGetFolderPath(NULL, CSIDL_COMMON_APPDATA, NULL, 0, path);
    QString strPath = QString::fromWCharArray(path);
    strcpy(szPath, strPath.toLocal8Bit().data());
#if  HHT_CHINA
    strcat(szPath, "\\Newline assistant\\Settings");
#else
    strcat(szPath, "\\Newline assistant\\Settings");
#endif

    QDir dir;
    QString  dataPath = hhtHelper::CharToQString(szPath);
    qDebug()<<"dataPath: "<<dataPath;
    UserDataPath = dataPath.replace(QRegExp("\\\\"),"/");
    if (false == dir.exists(UserDataPath))
    {
        bool result = dir.mkpath(UserDataPath);
        if(!result){
            return NULL;
        }
    }
    qDebug()<<"UserDataPath: "<<UserDataPath;
    return UserDataPath;
}

int PUBComClass::Pub_CheckAppRunning()
{
    HANDLE hMutex;
    //创建句柄
    hMutex = ::CreateMutex(NULL, FALSE, (LPCWSTR)"PanelInspector");
    if (NULL == hMutex)
    {
        return 1;
    }
    if (ERROR_ALREADY_EXISTS == ::GetLastError())
    {
        QMessageBox::warning(NULL, "Warning", "The program is already running.");
        CloseHandle(hMutex);
        return 1;
    }
    return 0;
}
void PUBComClass::openWindowsApp(QString fileName)
{
	emit signal_openWindowsApp(fileName);
}
void PUBComClass::SendallapptoAndroid811()
{
	emit signal_SendallapptoAndroid811();
}
void PUBComClass::TcpconnectSendallapp()
{
	emit signal_TcpconnectSendallapp();
}
void PUBComClass::TimerCheckdeleteapp()
{
	emit signal_TimerCheckdeleteapp();
}
void PUBComClass::Timerstop()
{
	emit signal_Timerstop();
}
void PUBComClass::PostOpenApp(QString strAppName)
{
    emit signal_openProcFromFileName(strAppName);
}

void PUBComClass::PostOpenAppX5X7(QString strAppName)
{
    emit signal_openProcFromFileNameX5X7(strAppName);
}

void PUBComClass::PostOpenComFailed()
{
    emit SignalOpenComFailed();
}

void PUBComClass::PostOpenComSuccess()
{
    emit SignalOpenComSuccess();
}

void PUBComClass::PostConnectTcpSuccess()
{
    emit SignalConnectTcpSuccess();
}

void PUBComClass::PostTotalPkgNum(int nTotalPkgNum)
{
    emit SignalTotalPkgNum(nTotalPkgNum);
}

void PUBComClass::PostCurrentPkgNum(int nCurrentPkgNum)
{
    emit SignalCurrentPkgNum(nCurrentPkgNum);
}

void PUBComClass::PostSendFileToAndroidFailed()
{
    emit SignalSendFileToAndroidFailed();
}

void PUBComClass::PostCameraStatusCheck()
{
    emit SignalCameraStatusCheck();
}

void PUBComClass::PostPubUsbStatusCheck()
{
    emit SignalPubUsbStatusCheck();
}

void PUBComClass::PostClearAllApp()
{
    emit SignalClearAllApp();
}

void PUBComClass::PostX9FirmwareCheck()
{
    emit SignalX9FirmwareCheck();
}

void PUBComClass::PostFileNameTooLong()
{
    emit SignalFileNameTooLong();
}

void PUBComClass::closeUpload()
{
	emit signalcloseUpload();
}

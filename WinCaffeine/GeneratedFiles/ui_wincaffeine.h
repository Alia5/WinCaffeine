/********************************************************************************
** Form generated from reading UI file 'wincaffeine.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINCAFFEINE_H
#define UI_WINCAFFEINE_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WinCaffeineClass
{
public:
    QWidget *centralWidget;
    QCheckBox *SleepBox;
    QCheckBox *MonitorBox;

    void setupUi(QMainWindow *WinCaffeineClass)
    {
        if (WinCaffeineClass->objectName().isEmpty())
            WinCaffeineClass->setObjectName(QStringLiteral("WinCaffeineClass"));
        WinCaffeineClass->resize(203, 72);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WinCaffeineClass->sizePolicy().hasHeightForWidth());
        WinCaffeineClass->setSizePolicy(sizePolicy);
        WinCaffeineClass->setMinimumSize(QSize(203, 72));
        WinCaffeineClass->setMaximumSize(QSize(203, 72));
        QIcon icon;
        icon.addFile(QStringLiteral(":/WinCaffeine/wincaf.png"), QSize(), QIcon::Normal, QIcon::Off);
        WinCaffeineClass->setWindowIcon(icon);
        WinCaffeineClass->setToolTipDuration(-1);
        WinCaffeineClass->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        centralWidget = new QWidget(WinCaffeineClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        SleepBox = new QCheckBox(centralWidget);
        SleepBox->setObjectName(QStringLiteral("SleepBox"));
        SleepBox->setGeometry(QRect(20, 10, 121, 17));
        MonitorBox = new QCheckBox(centralWidget);
        MonitorBox->setObjectName(QStringLiteral("MonitorBox"));
        MonitorBox->setGeometry(QRect(20, 40, 121, 17));
        WinCaffeineClass->setCentralWidget(centralWidget);

        retranslateUi(WinCaffeineClass);

        QMetaObject::connectSlotsByName(WinCaffeineClass);
    } // setupUi

    void retranslateUi(QMainWindow *WinCaffeineClass)
    {
        WinCaffeineClass->setWindowTitle(QApplication::translate("WinCaffeineClass", "WinCaffeine", 0));
        SleepBox->setText(QApplication::translate("WinCaffeineClass", "Keep system awake", 0));
        MonitorBox->setText(QApplication::translate("WinCaffeineClass", "Keep screens on", 0));
    } // retranslateUi

};

namespace Ui {
    class WinCaffeineClass: public Ui_WinCaffeineClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINCAFFEINE_H

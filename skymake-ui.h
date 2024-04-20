/********************************************************************************
** Form generated from reading UI file 'skymakeFgYCke.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef SKYMAKEFGYCKE_H
#define SKYMAKEFGYCKE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *HL_Dest;
    QLabel *LB_Prefix;
    QLineEdit *LE_Prefix;
    QPushButton *BTN_SelDest;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *HL_SkySel;
    QComboBox *CB_TypeSelect;
    QComboBox *CB_SkySelect;
    QCheckBox *CHK_OW;
    QPushButton *BTN_Create;
    QWidget *gridLayoutWidget;
    QGridLayout *GL_IDs;
    QLabel *LB_VarID;
    QLabel *LB_ID;
    QLineEdit *LE_VarID;
    QLineEdit *LE_ID;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *HL_Modes;
    QLabel *LB_Mode;
    QComboBox *CB_Mode;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 235);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 781, 41));
        HL_Dest = new QHBoxLayout(horizontalLayoutWidget);
        HL_Dest->setObjectName("HL_Dest");
        HL_Dest->setContentsMargins(0, 0, 0, 0);
        LB_Prefix = new QLabel(horizontalLayoutWidget);
        LB_Prefix->setObjectName("LB_Prefix");

        HL_Dest->addWidget(LB_Prefix);

        LE_Prefix = new QLineEdit(horizontalLayoutWidget);
        LE_Prefix->setObjectName("LE_Prefix");

        HL_Dest->addWidget(LE_Prefix);

        BTN_SelDest = new QPushButton(horizontalLayoutWidget);
        BTN_SelDest->setObjectName("BTN_SelDest");
        BTN_SelDest->setMinimumSize(QSize(0, 33));

        HL_Dest->addWidget(BTN_SelDest);

        horizontalLayoutWidget_2 = new QWidget(centralwidget);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(10, 60, 781, 41));
        HL_SkySel = new QHBoxLayout(horizontalLayoutWidget_2);
        HL_SkySel->setObjectName("HL_SkySel");
        HL_SkySel->setContentsMargins(0, 0, 0, 0);
        CB_TypeSelect = new QComboBox(horizontalLayoutWidget_2);
        CB_TypeSelect->setObjectName("CB_TypeSelect");
        CB_TypeSelect->setMaximumSize(QSize(200, 16777215));

        HL_SkySel->addWidget(CB_TypeSelect);

        CB_SkySelect = new QComboBox(horizontalLayoutWidget_2);
        CB_SkySelect->setObjectName("CB_SkySelect");

        HL_SkySel->addWidget(CB_SkySelect);

        CHK_OW = new QCheckBox(centralwidget);
        CHK_OW->setObjectName("CHK_OW");
        CHK_OW->setGeometry(QRect(670, 140, 121, 27));
        BTN_Create = new QPushButton(centralwidget);
        BTN_Create->setObjectName("BTN_Create");
        BTN_Create->setGeometry(QRect(680, 170, 111, 41));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(10, 110, 261, 84));
        GL_IDs = new QGridLayout(gridLayoutWidget);
        GL_IDs->setObjectName("GL_IDs");
        GL_IDs->setHorizontalSpacing(11);
        GL_IDs->setContentsMargins(0, 0, 0, 0);
        LB_VarID = new QLabel(gridLayoutWidget);
        LB_VarID->setObjectName("LB_VarID");

        GL_IDs->addWidget(LB_VarID, 1, 0, 1, 1);

        LB_ID = new QLabel(gridLayoutWidget);
        LB_ID->setObjectName("LB_ID");

        GL_IDs->addWidget(LB_ID, 0, 0, 1, 1);

        LE_VarID = new QLineEdit(gridLayoutWidget);
        LE_VarID->setObjectName("LE_VarID");

        GL_IDs->addWidget(LE_VarID, 1, 1, 1, 1);

        LE_ID = new QLineEdit(gridLayoutWidget);
        LE_ID->setObjectName("LE_ID");

        GL_IDs->addWidget(LE_ID, 0, 1, 1, 1);

        horizontalLayoutWidget_3 = new QWidget(centralwidget);
        horizontalLayoutWidget_3->setObjectName("horizontalLayoutWidget_3");
        horizontalLayoutWidget_3->setGeometry(QRect(450, 170, 221, 41));
        HL_Modes = new QHBoxLayout(horizontalLayoutWidget_3);
        HL_Modes->setObjectName("HL_Modes");
        HL_Modes->setContentsMargins(0, 0, 0, 0);
        LB_Mode = new QLabel(horizontalLayoutWidget_3);
        LB_Mode->setObjectName("LB_Mode");
        LB_Mode->setMaximumSize(QSize(36, 16777215));
        LB_Mode->setBaseSize(QSize(0, 0));

        HL_Modes->addWidget(LB_Mode);

        CB_Mode = new QComboBox(horizontalLayoutWidget_3);
        CB_Mode->setObjectName("CB_Mode");

        HL_Modes->addWidget(CB_Mode);

        MainWindow->setCentralWidget(centralwidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        LB_Prefix->setText(QCoreApplication::translate("MainWindow", "Destination:", nullptr));
        BTN_SelDest->setText(QCoreApplication::translate("MainWindow", "Select", nullptr));
        CHK_OW->setText(QCoreApplication::translate("MainWindow", "Avoid Overwrite", nullptr));
        BTN_Create->setText(QCoreApplication::translate("MainWindow", "Make!", nullptr));
        LB_VarID->setText(QCoreApplication::translate("MainWindow", "Variant ID", nullptr));
        LB_ID->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        LB_Mode->setText(QCoreApplication::translate("MainWindow", "Mode", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // SKYMAKEFGYCKE_H

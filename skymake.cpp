//Qt
#include <QApplication>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QTextEdit>
#include <QLineEdit>
#include <QComboBox>
#include <QFileDialog>
#include <QDirModel>
#include <QCheckBox>
#include <QObject>

//cstd
#include <iostream>
#include <string>
#include <filesystem>

//external
#include "skylanders.h"
#include "skymake.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    bool isInAdvanced = false;
    bool OW = false;

    // Create the main window
    QWidget window;
    window.setWindowTitle("Skymake");
    QGridLayout *L_Window = new QGridLayout(&window);
    window.setFixedSize(600, 150);

    QVBoxLayout *L_Buttons = new QVBoxLayout();
    L_Window -> addLayout(L_Buttons, 0, 1);

    QGridLayout *L_Content = new QGridLayout;
    L_Window -> addLayout(L_Content, 0, 0);

    QLabel *LB_Msg = new QLabel("Welcome to Skymake!");
    L_Window -> addWidget(LB_Msg, 2, 0);
    
    // "Overwrite" checkbox
    QCheckBox *CHK_OW = new QCheckBox("Avoid overwrite");
    L_Window -> addWidget(CHK_OW, 2, 1);

    // Buttons
    QPushButton *BTN_Create = new QPushButton("Make!");
    QPushButton *BTN_Mode = new QPushButton("Mode: Basic");
    L_Buttons -> addWidget(BTN_Create);
    L_Buttons -> addWidget(BTN_Mode);

    // Combo Box
    QComboBox *CB_SkySelect = new QComboBox;
    L_Content -> addWidget(CB_SkySelect, 0, 0, 1, 0);
    for (const auto &[Name, IDs] : skylanderMap)
        CB_SkySelect -> addItem(QString::fromStdString(Name), IDs.first);

    // ID/VarID prompt
    QHBoxLayout *L_Adv_Container = new QHBoxLayout;
    QLabel *LB_ID = new QLabel("ID:");
    QLabel *LB_VarID = new QLabel("Variant (hex):");
    QLineEdit *LE_ID = new QLineEdit;
    QLineEdit *LE_VarID = new QLineEdit;
    L_Adv_Container -> addWidget(LB_ID);
    L_Adv_Container -> addWidget(LE_ID);
    L_Adv_Container -> addWidget(LB_VarID);
    L_Adv_Container -> addWidget(LE_VarID);
    L_Content -> addLayout(L_Adv_Container, 1, 0, 1, 0);
    for(int i = 0; i < L_Adv_Container -> count(); ++i) {
        QLayoutItem *tempQItem = L_Adv_Container -> itemAt(i);
        if (tempQItem) {
            QWidget* tempQWidget = tempQItem -> widget();
            if (tempQWidget) tempQWidget -> setDisabled(true);
        }
    }
    // set initial values
    QString QS_SelSky = CB_SkySelect -> currentText();
    std::pair<uint16_t, uint16_t> IDs = skylanderMap[QS_SelSky.toStdString()];
    LE_ID -> setText(QString::fromStdString(std::to_string(IDs.first)));
    std::stringstream VarIDHex;
    VarIDHex << std::hex << IDs.second;
    LE_VarID -> setText(QString::fromStdString("0x" + VarIDHex.str()));

    // Destination
    QLabel *LB_Prefix = new QLabel;
    LB_Prefix -> setText("Destination:");
    L_Content -> addWidget(LB_Prefix, 2, 0);
    QLineEdit *LE_Prefix = new QLineEdit;
    L_Content -> addWidget(LE_Prefix, 2, 1);
    QPushButton *BTN_SelDest = new QPushButton("Select");
    L_Content -> addWidget(BTN_SelDest, 2, 2);

    // Button Actions
    QObject::connect(BTN_Create, &QPushButton::clicked, [&LE_Prefix, &LB_Msg, &CB_SkySelect, &CHK_OW, &OW, &isInAdvanced, &LE_ID, &LE_VarID]() {
        QString QS_Dest = LE_Prefix -> text();
        QString QS_SelSky = CB_SkySelect -> currentText();
        LB_Msg -> setText("Last created: " + QS_Dest + " - " + QS_SelSky);
        bool Sw[2] = {OW, isInAdvanced};
        uint16_t ID = 0;
        uint16_t varID = 0;
        if (!QS_Dest.isEmpty()) {
            if (std::filesystem::exists(QS_Dest.toStdString())) {
                if (!isInAdvanced) {
                    if (CreateSkylander(QS_SelSky.toStdString(), QS_Dest.toStdString(), Sw, ID, varID))
                        LB_Msg -> setText("Last created: " + QS_Dest + " - " + QS_SelSky);
                    else 
                        LB_Msg -> setText("Couldn't Create: " + QS_Dest + " - " + QS_SelSky);
                }
                else {
                    bool IDSetSuccessfully = false, VarSetSuccessfully = false;
                    QString QS_ID = LE_ID -> text();
                    QString QS_VarID = LE_VarID -> text();
                    try {
                        size_t pos;
                        ID = static_cast<std::uint16_t>(std::stoul(QS_ID.toStdString(), &pos));
                        IDSetSuccessfully = true;
                    } catch (const std::invalid_argument&) {
                        LB_Msg -> setText("Invalid ID!");
                        IDSetSuccessfully = false;
                    } catch (const std::out_of_range&) {
                        LB_Msg -> setText("ID is too big!");
                        IDSetSuccessfully = false;
                    }
                    try {
                        size_t pos;
                        varID = static_cast<std::uint16_t>(std::stoul(QS_VarID.toStdString(), &pos, 0));
                        VarSetSuccessfully = true;
                    } catch (const std::invalid_argument&) {
                        LB_Msg -> setText("Invalid Variant ID!");
                        VarSetSuccessfully = false;
                    } catch (const std::out_of_range&) {
                        LB_Msg -> setText("Variant ID is too big!");
                        VarSetSuccessfully = false;
                    }
                    if (VarSetSuccessfully && IDSetSuccessfully) {
                        if (CreateSkylander(QS_SelSky.toStdString(), QS_Dest.toStdString(), Sw, ID, varID))
                            LB_Msg -> setText("Last created: " + QS_Dest + " - " + QS_SelSky);
                        else 
                            LB_Msg -> setText("Couldn't Create: " + QS_Dest + " - " + QS_SelSky);
                    }
                }
            }
            else LB_Msg -> setText("Invalid destination!");
        }
        else LB_Msg -> setText("No destination specified!");
    });

    QObject::connect(BTN_Mode, &QPushButton::clicked, [&BTN_Mode, &isInAdvanced, &CB_SkySelect, &L_Content, &L_Adv_Container, &window, &LB_ID] {
        switch(isInAdvanced) {
            case true:
                BTN_Mode -> setText("Mode: Basic");
                isInAdvanced = false;
                CB_SkySelect -> setDisabled(false);
                for(int i = 0; i < L_Adv_Container -> count(); ++i) {
                    QLayoutItem *tempQItem = L_Adv_Container -> itemAt(i);
                    if (tempQItem) {
                        QWidget* tempQWidget = tempQItem -> widget();
                        if (tempQWidget) tempQWidget -> setDisabled(true);
                    }
                }
                break;
            case false:
                BTN_Mode -> setText("Mode: Advanced");
                isInAdvanced = true;
                CB_SkySelect -> setDisabled(true);
                for(int i = 0; i < L_Adv_Container -> count(); ++i) {
                    QLayoutItem *tempQItem = L_Adv_Container -> itemAt(i);
                    if (tempQItem) {
                        QWidget* tempQWidget = tempQItem -> widget();
                        if (tempQWidget) tempQWidget -> setDisabled(false);
                    }
                }
                break;
        }
    });

    QObject::connect(BTN_SelDest, &QPushButton::clicked, [&LE_Prefix, &window] {
        QString filePath = QFileDialog::getExistingDirectory(&window, "Select Folder", QDir::homePath());
        LE_Prefix -> setText(filePath);
    });

    QObject::connect(CHK_OW, &QCheckBox::stateChanged, [&CHK_OW, &OW] {
        OW = CHK_OW -> isChecked();
    });

    QObject::connect(CB_SkySelect, &QComboBox::currentTextChanged, [&CB_SkySelect, &LE_ID, &LE_VarID] {
        QString QS_SelSky = CB_SkySelect -> currentText();
        std::pair<uint16_t, uint16_t> IDs = skylanderMap[QS_SelSky.toStdString()];
        LE_ID -> setText(QString::fromStdString(std::to_string(IDs.first)));
        std::stringstream VarIDHex;
        VarIDHex << std::hex << IDs.second;
        LE_VarID -> setText(QString::fromStdString("0x" + VarIDHex.str()));
    });

    // Show the window
    window.show();

    return app.exec();
}
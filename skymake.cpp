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
#include <QCheckBox>
#include <QObject>

//cstd
#include <iostream>
#include <string>
#include <filesystem>

//external
#include "skylanders.h"
#include "skymake.h"
#include "skymake-ui.h"

std::map<std::string, uint8_t> MLS_Modes = {
    {"Basic", 0},
    {"Advanced", 1},
    {"Random", 2},
};

QStringList getCategoryEntries(uint16_t category) {
    QStringList entries = {};
    switch (category) {
        case 1:
            for (const auto &[Name, IDs] : MLS_Core)
                entries << QString::fromStdString(Name);
            break;
        case 2:
            for (const auto &[Name, IDs] : MLS_Giants)
                entries << QString::fromStdString(Name);
            break;
        case 3:
            for (const auto &[Name, IDs] : MLS_Swappers)
                entries << QString::fromStdString(Name);
            break;
        case 4:
            for (const auto &[Name, IDs] : MLS_TrapMasters)
                entries << QString::fromStdString(Name);
            break;
        case 5:
            for (const auto &[Name, IDs] : MLS_Minis)
                entries << QString::fromStdString(Name);
            break;
        case 6:
            for (const auto &[Name, IDs] : MLS_Superchargers)
                entries << QString::fromStdString(Name);
            break;
        case 7:
            for (const auto &[Name, IDs] : MLS_Sensei)
                entries << QString::fromStdString(Name);
            break;
        case 8:
            for (const auto &[Name, IDs] : MLS_Traps)
                entries << QString::fromStdString(Name);
            break;
        case 9:
            for (const auto &[Name, IDs] : MLS_Vehicles)
                entries << QString::fromStdString(Name);
            break;
        case 10:
            for (const auto &[Name, IDs] : MLS_CreationCrystals)
                entries << QString::fromStdString(Name);
            break;
        case 11:
            for (const auto &[Name, IDs] : MLS_Scraps)
                entries << QString::fromStdString(Name);
            break;
        case 12:
            for (const auto &[Name, IDs] : MLS_Debug)
                entries << QString::fromStdString(Name);
            break;
        case 13:
            for (const auto &[Name, IDs] : MLS_Items)
                entries << QString::fromStdString(Name);
            break;
        case 14:
            for (const auto &[Name, IDs] : MLS_LevelPacks)
                entries << QString::fromStdString(Name);
            break;
        case 15:
            for (const auto &[Name, IDs] : MLS_Adventures)
                entries << QString::fromStdString(Name);
            break;
    }
    //for (const QString& element: entries) std::cout << element.toStdString() << " \n";
    //std::cout << "------";
    return entries;
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    uint8_t mode = 0;
    bool OW = false;
    QString QS_SelCat; // Currently selected category


    // Create the main window
    
    QMainWindow window;
    Ui::MainWindow UI;
    UI.setupUi(&window);
    // set title
    window.setWindowTitle("Skymake");
    window.setFixedSize(800, 235);

    // Welcome message
    UI.statusBar->showMessage("Welcome to Skymake!");

    // populate categoties
    for (const auto &[Category, Number]: MLS_Categories)
        UI.CB_TypeSelect -> addItem(QString::fromStdString(Category));
    QS_SelCat = UI.CB_TypeSelect -> currentText();
    
    // populate skylander entries
    UI.CB_SkySelect -> addItems(getCategoryEntries(MLS_Categories[QS_SelCat.toStdString()]));
    
    // populate modes
    UI.CB_Mode -> addItems({"Basic", "Advanced", "Random"});

    // disable ID and VarID LineEdits
    for(int i = 0; i < UI.GL_IDs -> count(); ++i) {
        QLayoutItem *tempQItem = UI.GL_IDs -> itemAt(i);
        if (tempQItem) {
            QWidget* tempQWidget = tempQItem -> widget();
            if (tempQWidget) tempQWidget -> setDisabled(true);
        }
    }

    // set initial values
    QString QS_SelSky = UI.CB_SkySelect -> currentText();
    std::pair<uint16_t, uint16_t> IDs = getSkylanderIDs(QS_SelSky.toStdString(), MLS_Categories[QS_SelCat.toStdString()]);
    UI.LE_ID -> setText(QString::fromStdString(std::to_string(IDs.first)));
    std::stringstream VarIDHex;
    VarIDHex << std::hex << IDs.second;
    UI.LE_VarID -> setText(QString::fromStdString("0x" + VarIDHex.str()));

    // File Select Dialog
    QObject::connect(UI.BTN_SelDest, &QPushButton::clicked, [&UI, &window] {
        QString filePath = QFileDialog::getExistingDirectory(&window, "Select Folder", QDir::homePath());
        UI.LE_Prefix -> setText(filePath);
    });


    // Checkbox interaction
    QObject::connect(UI.CHK_OW, &QCheckBox::stateChanged, [&UI, &OW] {
        OW = UI.CHK_OW -> isChecked();
    });

    // update the skylander selection combo box upon changing the category
    QObject::connect(UI.CB_TypeSelect, &QComboBox::currentTextChanged, [&UI, &QS_SelCat] {
        // Disconnect and clear CB_SkySelect to avoid conflicts
        UI.CB_SkySelect->disconnect();
        UI.CB_SkySelect -> clear();

        QS_SelCat = UI.CB_TypeSelect -> currentText();
        UI.CB_SkySelect -> addItems(getCategoryEntries(MLS_Categories[QS_SelCat.toStdString()]));

        // Refresh the grayed-out ID and Variant boxes
        QString QS_SelSky = UI.CB_SkySelect -> currentText();
        std::pair<uint16_t, uint16_t> IDs = getSkylanderIDs(QS_SelSky.toStdString(), MLS_Categories[QS_SelCat.toStdString()]);
        UI.LE_ID -> setText(QString::fromStdString(std::to_string(IDs.first)));
        std::stringstream VarIDHex;
        VarIDHex << std::hex << IDs.second;
        UI.LE_VarID -> setText(QString::fromStdString("0x" + VarIDHex.str()));

        // Reconnect CB_SkySelect
        QObject::connect(UI.CB_SkySelect, &QComboBox::currentTextChanged, [&UI, &QS_SelCat] {
            // Refresh the grayed-out ID and Variant boxes
            QString QS_SelSky = UI.CB_SkySelect -> currentText();
            std::pair<uint16_t, uint16_t> IDs = getSkylanderIDs(QS_SelSky.toStdString(), MLS_Categories[QS_SelCat.toStdString()]);
            UI.LE_ID -> setText(QString::fromStdString(std::to_string(IDs.first)));
            std::stringstream VarIDHex;
            VarIDHex << std::hex << IDs.second;
            UI.LE_VarID -> setText(QString::fromStdString("0x" + VarIDHex.str()));
        });
    });

    QObject::connect(UI.CB_SkySelect, &QComboBox::currentTextChanged, [&UI, &QS_SelCat] {
        // Refresh the grayed-out ID and Variant boxes
        QString QS_SelSky = UI.CB_SkySelect -> currentText();
        std::pair<uint16_t, uint16_t> IDs = getSkylanderIDs(QS_SelSky.toStdString(), MLS_Categories[QS_SelCat.toStdString()]);
        UI.LE_ID -> setText(QString::fromStdString(std::to_string(IDs.first)));
        std::stringstream VarIDHex;
        VarIDHex << std::hex << IDs.second;
        UI.LE_VarID -> setText(QString::fromStdString("0x" + VarIDHex.str()));
    });

    QObject::connect(UI.CB_Mode, &QComboBox::currentTextChanged, [&UI, &mode] {
        mode = MLS_Modes[UI.CB_Mode->currentText().toStdString()];
        std::cerr << mode;
    });

    /*
    // Button Actions
    QObject::connect(BTN_Create, &QPushButton::clicked, [&LE_Prefix, &LB_Msg, &CB_SkySelect, &CHK_OW, &OW, &isInAdvanced, &LE_ID, &LE_VarID, &QS_SelCat]() {
        QString QS_Dest = LE_Prefix -> text();
        QString QS_SelSky = CB_SkySelect -> currentText();
        LB_Msg -> setText("Last created: " + QS_Dest + " - " + QS_SelSky);
        bool Sw[2] = {OW, isInAdvanced};
        uint16_t ID = 0;
        uint16_t varID = 0;
        if (!QS_Dest.isEmpty()) {
            if (std::filesystem::exists(QS_Dest.toStdString())) {
                if (!isInAdvanced) {
                    if (CreateSkylander(QS_SelSky.toStdString(), QS_Dest.toStdString(), Sw, ID, varID, MLS_Categories[QS_SelCat.toStdString()]))
                        LB_Msg -> setText("Last created: " + QS_Dest + " - " + QS_SelSky+ ".");
                    else 
                        LB_Msg -> setText("Couldn't create skylander figure.");
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
                            LB_Msg -> setText("Last created: " + QS_Dest + " - Custom (" + QString::fromStdString(std::to_string(ID)) + ", " + QString::fromStdString(std::to_string(varID)) + ").");
                        else 
                            LB_Msg -> setText("Couldn't create skylander figure.");
                    }
                }
            }
            else LB_Msg -> setText("Invalid destination!");
        }
        else LB_Msg -> setText("No destination specified!");
    });

    QObject::connect(BTN_Mode, &QPushButton::clicked, [&BTN_Mode, &isInAdvanced, &CB_SkySelect, &L_Content, &L_Adv_Container, &window, &LB_ID, &CB_TypeSelect] {
        switch(isInAdvanced) {
            case true:
                BTN_Mode -> setText("Mode: Basic");
                isInAdvanced = false;
                CB_SkySelect -> setDisabled(false);
                CB_TypeSelect -> setDisabled(false);
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
                CB_TypeSelect -> setDisabled(true);
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
    */

    // Show the window
    window.show();
    return app.exec();
}
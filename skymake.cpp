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
    window.setFixedSize(600, 125);

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
    QPushButton *BTN_Mode = new QPushButton("Basic mode");
    L_Buttons -> addWidget(BTN_Create);
    L_Buttons -> addWidget(BTN_Mode);

    // Combo Box
    QComboBox *CB_SkySelect = new QComboBox;
    L_Content -> addWidget(CB_SkySelect, 0, 0, 1, 0);
    for (const auto &[Name, IDs] : skylanderMap)
        CB_SkySelect -> addItem(QString::fromStdString(Name), IDs.first);

    // Destination
    QLabel *LB_Prefix = new QLabel;
    LB_Prefix -> setText("Destination:");
    L_Content -> addWidget(LB_Prefix, 1, 0);
    QLineEdit *LE_Prefix = new QLineEdit;
    L_Content -> addWidget(LE_Prefix, 1, 1);
    QPushButton *BTN_SelDest = new QPushButton("Select");
    L_Content -> addWidget(BTN_SelDest, 1, 2);

    // Button Actions
    QObject::connect(BTN_Create, &QPushButton::clicked, [&LE_Prefix, &LB_Msg, &CB_SkySelect, &CHK_OW, &OW, &isInAdvanced]() {
        QString QS_Dest = LE_Prefix -> text();
        QString QS_SelSky = CB_SkySelect -> currentText();
        LB_Msg -> setText("Last created: " + QS_Dest + " - " + QS_SelSky);
        bool Sw[2] = {OW, isInAdvanced};
        uint16_t ID = 0;
        uint16_t varID = 0;
        if (!QS_Dest.isEmpty()) {
            if (std::filesystem::exists(QS_Dest.toStdString())) {
                if (CreateSkylander(QS_SelSky.toStdString(), QS_Dest.toStdString(), Sw, ID, varID))
                    LB_Msg -> setText("Last created: " + QS_Dest + " - " + QS_SelSky);
                else 
                    LB_Msg -> setText("Couldn't Create: " + QS_Dest + " - " + QS_SelSky);
            }
            else LB_Msg -> setText("Invalid destination!");
        }
        else LB_Msg -> setText("No destination specified!");

    });

    QObject::connect(BTN_Mode, &QPushButton::clicked, [&BTN_Mode, &isInAdvanced] {
        switch(isInAdvanced) {
            case true:
                BTN_Mode -> setText("Basic mode");
                isInAdvanced = false;
                break;
            case false:
                BTN_Mode -> setText("Advanced mode");
                isInAdvanced = true;
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

    // Show the window
    window.show();

    return app.exec();
}
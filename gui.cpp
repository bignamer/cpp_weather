#include "gui.h"

void setupGUI(QWidget &window, QGridLayout *layout, QPushButton *&refreshButton,
                QLineEdit *&inputField, QLabel *& sceneHeader, QLabel *&countryHeader, QLabel *&cityHeader,
                QLabel *&regionHeader, QLabel *&temperatureHeader,
                QLabel *&humidityHeader, QLabel *&windHeader, QLabel *&uvHeader,
                QLabel *&sceneLabel, QLabel *&countryLabel, QLabel *&cityLabel,
                QLabel *&regionLabel, QLabel *&temperatureLabel, QLabel *&humidityLabel,
                QLabel *&windLabel, QLabel *&uvLabel) {

    
       
    // Creating labels with terminal-style appearance
    sceneHeader = new QLabel("Scene:");
    sceneHeader->setStyleSheet("font-weight: bold; font-size: 12pt;");
    countryHeader = new QLabel("Country:");
    countryHeader->setStyleSheet("font-weight: bold; font-size: 12pt;");
    cityHeader = new QLabel("City:");
    cityHeader->setStyleSheet("font-weight: bold; font-size: 12pt;");
    regionHeader = new QLabel("Region:");
    regionHeader->setStyleSheet("font-weight: bold; font-size: 12pt;");
    temperatureHeader = new QLabel("Temperature:");
    temperatureHeader->setStyleSheet("font-weight: bold; font-size: 12pt;");
    humidityHeader = new QLabel("Humidity:");
    humidityHeader->setStyleSheet("font-weight: bold; font-size: 12pt;");
    windHeader = new QLabel("Wind Speed:");
    windHeader->setStyleSheet("font-weight: bold; font-size: 12pt;");
    uvHeader = new QLabel("UV Index:");
    uvHeader->setStyleSheet("font-weight: bold; font-size: 12pt;");


    // Creating labels for displaying weather information

    sceneLabel = new QLabel("");
    countryLabel = new QLabel("");
    cityLabel = new QLabel("");
    regionLabel = new QLabel("");
    temperatureLabel = new QLabel("");
    humidityLabel = new QLabel("");
    windLabel = new QLabel("");
    uvLabel = new QLabel("");

    // Creating refresh button

    refreshButton = new QPushButton("Refresh");
    refreshButton->setStyleSheet("font-weight: bold; font-size: 12pt;");

    // Creating input field for city

    inputField = new QLineEdit("City");
    inputField->setStyleSheet("font-size: 12pt;");

    // Adding widgets to layout
    layout->addWidget(sceneHeader, 0, 0);
    layout->addWidget(sceneLabel, 0, 1);
    layout->addWidget(countryHeader, 1, 0);
    layout->addWidget(countryLabel, 1, 1);
    layout->addWidget(cityHeader, 2, 0);
    layout->addWidget(cityLabel, 2, 1);
    layout->addWidget(regionHeader, 3, 0);
    layout->addWidget(regionLabel, 3, 1);
    layout->addWidget(temperatureHeader, 4, 0);
    layout->addWidget(temperatureLabel, 4, 1);
    layout->addWidget(humidityHeader, 5, 0);
    layout->addWidget(humidityLabel, 5, 1);
    layout->addWidget(windHeader, 6, 0);
    layout->addWidget(windLabel, 6, 1);
    layout->addWidget(uvHeader, 7, 0);
    layout->addWidget(uvLabel, 7, 1);
    layout->addWidget(inputField, 8, 0);
    layout->addWidget(refreshButton, 8, 1);
}



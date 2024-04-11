#include <QApplication>
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include "gui.h"
#include "api.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Weather Information");
    QGridLayout *layout = new QGridLayout(&window);

    QPushButton *refreshButton;
    QLineEdit *inputField;
    QLabel *conditionHeader, *countryHeader, *cityHeader, *regionHeader, *temperatureHeader, *humidityHeader, *windHeader, *uvHeader;
    QLabel *conditionLabel, *countryLabel, *cityLabel, *regionLabel, *temperatureLabel, *humidityLabel, *windLabel, *uvLabel;

    setupGUI(window, layout, refreshButton, inputField, conditionHeader, countryHeader, cityHeader, regionHeader, temperatureHeader, humidityHeader, windHeader, uvHeader, conditionLabel, countryLabel, cityLabel, regionLabel, temperatureLabel, humidityLabel, windLabel, uvLabel);

    QObject::connect(refreshButton, &QPushButton::clicked, [&]() {
        QString cityName = inputField->text();
        cityLabel->setText(cityName);
        updateWeatherInfo(cityName, conditionLabel, countryLabel, cityLabel, regionLabel, temperatureLabel, humidityLabel, windLabel, uvLabel);
    });

    window.setLayout(layout);
    window.show();

    updateWeatherInfo(cityLabel->text(), conditionLabel, countryLabel, cityLabel, regionLabel, temperatureLabel, humidityLabel, windLabel, uvLabel);

    return app.exec();
}
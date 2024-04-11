#ifndef API_H
#define API_H

#include <QString>
#include <QLabel>

void updateWeatherInfo(const QString &cityName, QLabel *conditionLabel, QLabel *countryLabel, QLabel *cityLabel, QLabel *regionLabel, QLabel *temperatureLabel, QLabel *humidityLabel, QLabel *windLabel, QLabel *uvLabel);

#endif // API_H

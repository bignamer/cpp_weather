#include "api.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include "key.h"

void updateWeatherInfo(const QString &cityName, QLabel *conditionLabel, QLabel *countryLabel, QLabel *cityLabel, QLabel *regionLabel, QLabel *temperatureLabel, QLabel *humidityLabel, QLabel *windLabel, QLabel *uvLabel) {
    QString apiKey = API_KEY;
    QNetworkAccessManager *manager = new QNetworkAccessManager();

    QString apiUrl = "http://api.weatherapi.com/v1/current.json?key=" + apiKey + "&q=" + cityName + "&aqi=no";

    QNetworkReply *reply = manager->get(QNetworkRequest(QUrl(apiUrl)));

    QObject::connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray responseData = reply->readAll();
            QJsonDocument jsonResponse = QJsonDocument::fromJson(responseData);
            QJsonObject jsonObject = jsonResponse.object();
            QJsonObject locationObject = jsonObject["location"].toObject();
            QJsonObject currentObject = jsonObject["current"].toObject();
            QJsonObject conditionObject = currentObject["condition"].toObject();

            conditionLabel->setText(conditionObject["text"].toString());
            countryLabel->setText(locationObject["country"].toString());
            cityLabel->setText(locationObject["name"].toString());
            regionLabel->setText(locationObject["region"].toString());
            temperatureLabel->setText(QString::number(currentObject["temp_c"].toDouble()) + " C");
            humidityLabel->setText(QString::number(currentObject["humidity"].toInt()) + " %");
            uvLabel->setText(QString::number(currentObject["uv"].toInt()));

            double windKph = currentObject["wind_kph"].toDouble();
            double windMps = windKph * 0.27778;
            windLabel->setText(QString::number(windMps) + " m/s");

        } else {

            conditionLabel->setText("N/A");
            countryLabel->setText("N/A");
            cityLabel->setText("N/A");
            regionLabel->setText("N/A");
            temperatureLabel->setText("N/A");
            humidityLabel->setText("N/A");
            windLabel->setText("N/A");
            uvLabel->setText("N/A");

        }

        reply->deleteLater();
        manager->deleteLater();
    });
}



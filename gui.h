#ifndef GUI_H
#define GUI_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>

void setupGUI(QWidget &window, QGridLayout *layout, QPushButton *&refreshButton, QLineEdit *&inputField, QLabel *&conditionHeader, QLabel *&countryHeader, QLabel *&cityHeader, QLabel *&regionHeader, QLabel *&temperatureHeader, QLabel *&humidityHeader, QLabel *&uvHeader, QLabel *&windHeader, QLabel *&conditionLabel, QLabel *&countryLabel, QLabel *&cityLabel, QLabel *&regionLabel, QLabel *&temperatureLabel, QLabel *&humidityLabel, QLabel *&windLabel, QLabel *&uvLabel);

#endif // GUI_H

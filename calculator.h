#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include <QApplication>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>
#include <QJSEngine>
#include <QQmlEngine>

class Calculator : public QWidget
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);

private slots:
    void buttonClicked(const QString &text, QLineEdit *display);

private:
    double evalExpression(const QString &expression);

};


#endif // CALCULATOR_H

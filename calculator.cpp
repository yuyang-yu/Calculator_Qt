#include "calculator.h"

Calculator::Calculator(QWidget *parent) : QWidget(parent)
{
    // Create interface elements
    QLineEdit *display = new QLineEdit();
    display->setReadOnly(true);

    // Create buttons
    QPushButton *buttons[16];
    for (int i = 0; i < 10; ++i) {
        buttons[i] = new QPushButton(QString::number(i));
    }
    buttons[10] = new QPushButton("+");
    buttons[11] = new QPushButton("-");
    buttons[12] = new QPushButton("*");
    buttons[13] = new QPushButton("/");
    buttons[14] = new QPushButton("=");
    buttons[15] = new QPushButton("C");

    // Create layout
    QGridLayout *layout = new QGridLayout();
    layout->addWidget(display, 0, 0, 1, 4);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            layout->addWidget(buttons[i * 4 + j], i + 1, j);
        }
    }

    // Set layout
    setLayout(layout);

    // Connect button click signals to slots
    for (int i = 0; i < 16; ++i) {
        connect(buttons[i], &QPushButton::clicked, [=]() {
            buttonClicked(buttons[i]->text(), display);
        });
    }
}

void Calculator::buttonClicked(const QString &text, QLineEdit *display)
{
    if (text == "=") {
        // Evaluate the expression
        QString expression = display->text();
        display->setText(QString::number(evalExpression(expression)));
    } else if (text == "C") {
        // Clear the display
        display->clear();
    } else {
        // Append the button's text to the display
        display->setText(display->text() + text);
    }
}

double Calculator::evalExpression(const QString &expression)
{
    // Evaluate the expression using QJSEngine
    QJSEngine engine;
    QJSValue result = engine.evaluate(expression);
    if (result.isNumber()) {
        return result.toNumber();
    } else {
        return 0.0; // Handle error case
    }
}



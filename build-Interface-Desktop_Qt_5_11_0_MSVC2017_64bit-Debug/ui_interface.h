/********************************************************************************
** Form generated from reading UI file 'interface.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERFACE_H
#define UI_INTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Interface
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *EJE_X;
    QLabel *label_2;
    QLineEdit *EJE_Z;
    QLineEdit *EJE_Y;
    QLineEdit *DIRECTION;
    QGraphicsView *graphicsView;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QLabel *label_5;
    QProgressBar *LUX_BAR;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *INICIO;
    QPushButton *PAUSE;
    QLabel *label;
    QLineEdit *PUERTO;
    QPushButton *GAME;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QLabel *label_6;
    QLineEdit *STEPS;
    QLabel *label_7;
    QPushButton *LED;

    void setupUi(QWidget *Interface)
    {
        if (Interface->objectName().isEmpty())
            Interface->setObjectName(QStringLiteral("Interface"));
        Interface->resize(628, 217);
        layoutWidget = new QWidget(Interface);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(160, 10, 181, 91));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        EJE_X = new QLineEdit(layoutWidget);
        EJE_X->setObjectName(QStringLiteral("EJE_X"));
        EJE_X->setReadOnly(true);

        gridLayout->addWidget(EJE_X, 0, 1, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        EJE_Z = new QLineEdit(layoutWidget);
        EJE_Z->setObjectName(QStringLiteral("EJE_Z"));
        EJE_Z->setReadOnly(true);

        gridLayout->addWidget(EJE_Z, 3, 1, 1, 1);

        EJE_Y = new QLineEdit(layoutWidget);
        EJE_Y->setObjectName(QStringLiteral("EJE_Y"));
        EJE_Y->setReadOnly(true);

        gridLayout->addWidget(EJE_Y, 2, 1, 1, 1);

        DIRECTION = new QLineEdit(Interface);
        DIRECTION->setObjectName(QStringLiteral("DIRECTION"));
        DIRECTION->setGeometry(QRect(190, 140, 151, 51));
        DIRECTION->setReadOnly(true);
        graphicsView = new QGraphicsView(Interface);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(350, 10, 271, 151));
        graphicsView->setAutoFillBackground(false);
        QBrush brush(QColor(222, 136, 60, 255));
        brush.setStyle(Qt::NoBrush);
        graphicsView->setBackgroundBrush(brush);
        layoutWidget1 = new QWidget(Interface);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 141, 171, 51));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout->addWidget(label_5);

        LUX_BAR = new QProgressBar(layoutWidget1);
        LUX_BAR->setObjectName(QStringLiteral("LUX_BAR"));
        LUX_BAR->setValue(24);

        verticalLayout->addWidget(LUX_BAR);

        layoutWidget2 = new QWidget(Interface);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(11, 11, 135, 99));
        verticalLayout_2 = new QVBoxLayout(layoutWidget2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        INICIO = new QPushButton(layoutWidget2);
        INICIO->setObjectName(QStringLiteral("INICIO"));

        verticalLayout_2->addWidget(INICIO);

        PAUSE = new QPushButton(layoutWidget2);
        PAUSE->setObjectName(QStringLiteral("PAUSE"));

        verticalLayout_2->addWidget(PAUSE);

        label = new QLabel(layoutWidget2);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        PUERTO = new QLineEdit(layoutWidget2);
        PUERTO->setObjectName(QStringLiteral("PUERTO"));
        PUERTO->setReadOnly(true);

        verticalLayout_2->addWidget(PUERTO);

        GAME = new QPushButton(Interface);
        GAME->setObjectName(QStringLiteral("GAME"));
        GAME->setGeometry(QRect(460, 170, 161, 41));
        widget = new QWidget(Interface);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(352, 163, 91, 51));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_2->addWidget(label_6, 0, 0, 1, 2);

        STEPS = new QLineEdit(widget);
        STEPS->setObjectName(QStringLiteral("STEPS"));
        STEPS->setReadOnly(true);

        gridLayout_2->addWidget(STEPS, 0, 2, 1, 1);

        label_7 = new QLabel(widget);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_2->addWidget(label_7, 1, 0, 1, 1);

        LED = new QPushButton(widget);
        LED->setObjectName(QStringLiteral("LED"));
        LED->setAutoFillBackground(false);
        LED->setCheckable(false);
        LED->setChecked(false);

        gridLayout_2->addWidget(LED, 1, 1, 1, 2);


        retranslateUi(Interface);

        QMetaObject::connectSlotsByName(Interface);
    } // setupUi

    void retranslateUi(QWidget *Interface)
    {
        Interface->setWindowTitle(QApplication::translate("Interface", "Interface", nullptr));
        label_3->setText(QApplication::translate("Interface", "Y Axis", nullptr));
        label_4->setText(QApplication::translate("Interface", "Z Axis", nullptr));
        label_2->setText(QApplication::translate("Interface", "X Axis", nullptr));
        label_5->setText(QApplication::translate("Interface", "Luminosity", nullptr));
        INICIO->setText(QApplication::translate("Interface", "START", nullptr));
        PAUSE->setText(QApplication::translate("Interface", "PAUSE", nullptr));
        label->setText(QApplication::translate("Interface", "Port:", nullptr));
        GAME->setText(QApplication::translate("Interface", "GAME", nullptr));
        label_6->setText(QApplication::translate("Interface", "steps", nullptr));
        label_7->setText(QApplication::translate("Interface", "LED", nullptr));
        LED->setText(QApplication::translate("Interface", "LIGHT ON", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Interface: public Ui_Interface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFACE_H

/********************************************************************************
** Form generated from reading UI file 'presenterwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRESENTERWINDOW_H
#define UI_PRESENTERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PresenterWindow
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QListWidget *listWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditId;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEditText;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEditAsw;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *lineEditScore;
    QPushButton *pushButton;

    void setupUi(QWidget *PresenterWindow)
    {
        if (PresenterWindow->objectName().isEmpty())
            PresenterWindow->setObjectName(QStringLiteral("PresenterWindow"));
        PresenterWindow->resize(579, 535);
        verticalLayout_3 = new QVBoxLayout(PresenterWindow);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        listWidget = new QListWidget(PresenterWindow);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout_2->addWidget(listWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(PresenterWindow);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEditId = new QLineEdit(PresenterWindow);
        lineEditId->setObjectName(QStringLiteral("lineEditId"));

        horizontalLayout->addWidget(lineEditId);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(PresenterWindow);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEditText = new QLineEdit(PresenterWindow);
        lineEditText->setObjectName(QStringLiteral("lineEditText"));

        horizontalLayout_2->addWidget(lineEditText);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(PresenterWindow);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lineEditAsw = new QLineEdit(PresenterWindow);
        lineEditAsw->setObjectName(QStringLiteral("lineEditAsw"));

        horizontalLayout_3->addWidget(lineEditAsw);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(PresenterWindow);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        lineEditScore = new QLineEdit(PresenterWindow);
        lineEditScore->setObjectName(QStringLiteral("lineEditScore"));

        horizontalLayout_4->addWidget(lineEditScore);


        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_2->addLayout(verticalLayout);

        pushButton = new QPushButton(PresenterWindow);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_2->addWidget(pushButton);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(PresenterWindow);

        QMetaObject::connectSlotsByName(PresenterWindow);
    } // setupUi

    void retranslateUi(QWidget *PresenterWindow)
    {
        PresenterWindow->setWindowTitle(QApplication::translate("PresenterWindow", "PresenterWindow", 0));
        label->setText(QApplication::translate("PresenterWindow", "Id:", 0));
        label_2->setText(QApplication::translate("PresenterWindow", "Question text:", 0));
        label_3->setText(QApplication::translate("PresenterWindow", "Answer:", 0));
        label_4->setText(QApplication::translate("PresenterWindow", "Score:", 0));
        pushButton->setText(QApplication::translate("PresenterWindow", "Add", 0));
    } // retranslateUi

};

namespace Ui {
    class PresenterWindow: public Ui_PresenterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRESENTERWINDOW_H

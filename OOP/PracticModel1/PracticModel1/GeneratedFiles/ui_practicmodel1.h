/********************************************************************************
** Form generated from reading UI file 'practicmodel1.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRACTICMODEL1_H
#define UI_PRACTICMODEL1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PracticModel1Class
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *labelScore;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PracticModel1Class)
    {
        if (PracticModel1Class->objectName().isEmpty())
            PracticModel1Class->setObjectName(QStringLiteral("PracticModel1Class"));
        PracticModel1Class->resize(578, 400);
        centralWidget = new QWidget(PracticModel1Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(2600, 2600));

        horizontalLayout_2->addWidget(label_2);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        labelScore = new QLabel(centralWidget);
        labelScore->setObjectName(QStringLiteral("labelScore"));

        horizontalLayout_3->addWidget(labelScore);


        verticalLayout_2->addLayout(horizontalLayout_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout->addWidget(listWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        PracticModel1Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(PracticModel1Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 578, 21));
        PracticModel1Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(PracticModel1Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        PracticModel1Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(PracticModel1Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        PracticModel1Class->setStatusBar(statusBar);

        retranslateUi(PracticModel1Class);

        QMetaObject::connectSlotsByName(PracticModel1Class);
    } // setupUi

    void retranslateUi(QMainWindow *PracticModel1Class)
    {
        PracticModel1Class->setWindowTitle(QApplication::translate("PracticModel1Class", "PracticModel1", 0));
        label_2->setText(QApplication::translate("PracticModel1Class", "Score:", 0));
        labelScore->setText(QApplication::translate("PracticModel1Class", "k", 0));
        label->setText(QApplication::translate("PracticModel1Class", "Answer:", 0));
        pushButton->setText(QApplication::translate("PracticModel1Class", "Answer", 0));
    } // retranslateUi

};

namespace Ui {
    class PracticModel1Class: public Ui_PracticModel1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRACTICMODEL1_H

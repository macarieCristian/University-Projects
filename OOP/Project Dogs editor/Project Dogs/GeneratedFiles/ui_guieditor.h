/********************************************************************************
** Form generated from reading UI file 'guieditor.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUIEDITOR_H
#define UI_GUIEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GuiEditor
{
public:

    void setupUi(QWidget *GuiEditor)
    {
        if (GuiEditor->objectName().isEmpty())
            GuiEditor->setObjectName(QStringLiteral("GuiEditor"));
        GuiEditor->resize(400, 300);

        retranslateUi(GuiEditor);

        QMetaObject::connectSlotsByName(GuiEditor);
    } // setupUi

    void retranslateUi(QWidget *GuiEditor)
    {
        GuiEditor->setWindowTitle(QApplication::translate("GuiEditor", "GuiEditor", 0));
    } // retranslateUi

};

namespace Ui {
    class GuiEditor: public Ui_GuiEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUIEDITOR_H

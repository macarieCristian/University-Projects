#ifndef GUIEDITOR_H
#define GUIEDITOR_H

#include <QWidget>
#include "ui_guieditor.h"

class GuiEditor : public QWidget
{
	Q_OBJECT

public:
	GuiEditor(QWidget *parent = 0);
	~GuiEditor();

private:
	Ui::GuiEditor ui;
};

#endif // GUIEDITOR_H

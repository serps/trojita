/* Copyright (C) 2012 Mildred <mildred-pub@mildred.fr>

   This file is part of the Trojita Qt IMAP e-mail client,
   http://trojita.flaska.net/

   This program is free software, you can do what you want with it, including
   changing its license (which is this text right here).
*/

#include <QEvent>

#include "TagWidget.h"

namespace Gui
{

TagWidget::TagWidget(const QString &buttonText, QWidget *parent, Qt::WindowFlags f) :
    QLabel(buttonText, parent, f)
{
    commonInit();
}

TagWidget::TagWidget(const QString &tagName, const QString &buttonText, QWidget *parent, Qt::WindowFlags f) :
    QLabel(tagName + " | " + buttonText, parent, f), m_tagName(tagName)
{
    commonInit();
}

bool TagWidget::event(QEvent *e)
{
    if (e->type() == QEvent::MouseButtonPress) {
        if (!m_tagName.isEmpty())
            emit removeClicked(m_tagName);
        emit clicked();
        return true;
    }

    return QLabel::event(e);
}

QString TagWidget::tagName() const
{
    return m_tagName;
}

void TagWidget::commonInit()
{
    static const QString tagStyle = QString::fromUtf8( \
        "border: 1px solid %1;" \
        "border-radius: 4px;"   \
        "background-color: %2;" \
        "color: %3;").arg(
                         palette().light().color().name(),
                         palette().toolTipBase().color().name(),
                         palette().toolTipText().color().name()
                         );

    setStyleSheet(tagStyle);
}

} // namespace Gui

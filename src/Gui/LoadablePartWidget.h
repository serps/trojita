#ifndef LOADABLEPARTWIDGET_H
#define LOADABLEPARTWIDGET_H

#include <QStackedWidget>

#include "AbstractPartWidget.h"
#include "SimplePartWidget.h"

class QPushButton;

namespace Gui {

/** @short Widget which implements "click-through" for loading message parts on demand

  When a policy dictates that certain body parts should not be shown unless
  really required, this widget comes to action.  It provides a click-wrapped
  meaning of showing huge body parts.  No data are transfered unless the user
  clicks a button.
*/
class LoadablePartWidget : public QStackedWidget, public AbstractPartWidget
{
    Q_OBJECT
public:
    LoadablePartWidget( QWidget* parent,
                        Imap::Network::MsgPartNetAccessManager* _manager,
                        Imap::Mailbox::TreeItemPart* _part,
                        QObject* _wheelEventFilter );
    QString quoteMe() const;
    virtual void reloadContents() {}
private slots:
    void loadClicked();
private:
    Imap::Network::MsgPartNetAccessManager* manager;
    Imap::Mailbox::TreeItemPart* part;
    SimplePartWidget* realPart;
    QObject* wheelEventFilter;
    QPushButton* loadButton;

    LoadablePartWidget(const LoadablePartWidget&); // don't implement
    LoadablePartWidget& operator=(const LoadablePartWidget&); // don't implement
};

}

#endif // LOADABLEPARTWIDGET_H
#ifndef GUI_PARTWIDGETFACTORY_H
#define GUI_PARTWIDGETFACTORY_H

#include "Imap/Network/MsgPartNetAccessManager.h"

#include <QCoreApplication>

namespace Gui {

class PartWidgetFactory
{
    Q_DECLARE_TR_FUNCTIONS(PartWidgetFactory)
    enum { ExpensiveFetchThreshold = 50*1024 };
public:
    PartWidgetFactory( Imap::Network::MsgPartNetAccessManager* _manager, QObject* _wheelEventFilter );
    QWidget* create( Imap::Mailbox::TreeItemPart* part );
    QWidget* create( Imap::Mailbox::TreeItemPart* part, int recursionDepth );
    Imap::Mailbox::Model* model() const;
private:
    Imap::Network::MsgPartNetAccessManager* manager;
    QObject* wheelEventFilter;

    PartWidgetFactory(const PartWidgetFactory&); // don't implement
    PartWidgetFactory& operator=(const PartWidgetFactory&); // don't implement
};

}

#endif // GUI_PARTWIDGETFACTORY_H
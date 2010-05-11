/* Copyright (C) 2007 Jan Kundrát <jkt@gentoo.org>

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; see the file COPYING.  If not, write to
   the Free Software Foundation, Inc., 51 Franklin Steet, Fifth Floor,
   Boston, MA 02110-1301, USA.
*/
#ifndef IMAP_SOCKET_H
#define IMAP_SOCKET_H

#include <memory>
#include <QAbstractSocket>

namespace Imap {

    /** @short A common wrapepr class for implementing remote sockets

      This class extends the basic QIODevice-like API by a few handy methods,
    so that the upper layers do not have to worry about low-level socket details.
*/
    class Socket: public QObject {
        Q_OBJECT
    public:
        /** @short Returns true if there's enough data to read, including the CR-LF pair */
        virtual bool canReadLine() = 0;

        /** @short Read at most @arg maxSize bytes from the socket */
        virtual QByteArray read( qint64 maxSize ) = 0;

        /** @short Read a line from the socket (up to the @arg maxSize bytes) */
        virtual QByteArray readLine( qint64 maxSize = 0 ) = 0;

        /** @short Write the contents of the @arg byteArray buffer to the socket */
        virtual qint64 write( const QByteArray& byteArray ) = 0;

        /** @short Negotiate and start encryption with the remote peer

          Please note that this function can throw an exception if the
        underlying socket implementation does not support TLS (an example of
        such an implementation is QProcess-backed socket).
*/
        virtual void startTls() = 0;

        /** @short Return true if the socket is no longer usable */
        virtual bool isDead() = 0;

        virtual ~Socket() {};
    signals:
        /** @short The socket is ready for use, including encryption, if requested */
        void connected();

        /** @short The socket got disconnected */
        void disconnected( const QString );

        /** @short Some data could be read from the socket */
        void readyRead();
    };

    typedef std::auto_ptr<Socket> SocketPtr;

};

#endif /* IMAP_SOCKET_H */
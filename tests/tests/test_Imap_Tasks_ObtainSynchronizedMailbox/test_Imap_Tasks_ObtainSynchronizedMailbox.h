/* Copyright (C) 2006 - 2011 Jan Kundrát <jkt@gentoo.org>

   This file is part of the Trojita Qt IMAP e-mail client,
   http://trojita.flaska.net/

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or the version 3 of the License.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; see the file COPYING.  If not, write to
   the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.
*/

#ifndef TEST_IMAP_TASKS_OBTAINSYNCHRONIZEDMAILBOXTASK
#define TEST_IMAP_TASKS_OBTAINSYNCHRONIZEDMAILBOXTASK

#include "test_LibMailboxSync/test_LibMailboxSync.h"

class QSignalSpy;

class ImapModelObtainSynchronizedMailboxTest : public LibMailboxSync
{
    Q_OBJECT
private slots:

    void testSyncEmptyMinimal();
    void testSyncEmptyNormal();
    void testSyncWithMessages();
    void testSyncTwoLikeCyrus();
    void testSyncTwoInParallel();
    void testResyncNoArrivals();
    void testResyncOneNew();
    void testResyncUidValidity();
    void testDecreasedUidNext();
    void testFlagReSyncBenchmark();
    void testReloadReadsFromCache();
    void testCacheNoChange();
    void testCacheUidValidity();
    void testCacheArrivals();
    void testCacheArrivalRaceDuringUid();
    void testCacheArrivalRaceDuringUid2();
    void testCacheArrivalRaceDuringFlags();
    void testCacheExpunges();
    void testCacheExpungesDuringUid();
    void testCacheExpungesDuringSelect();
private:
    void justKeepTask();
};

#endif

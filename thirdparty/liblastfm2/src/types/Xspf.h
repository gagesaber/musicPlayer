/*
   Copyright 2009 Last.fm Ltd. 
      - Primarily authored by Max Howell, Jono Cole and Doug Mansell

   This file is part of liblastfm.

   liblastfm is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   liblastfm is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with liblastfm.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef LASTFM_XSPF_H
#define LASTFM_XSPF_H

#include <lastfm/Track>
#include <QList>

namespace lastfm
{
    class LASTFM_DLLEXPORT Xspf : public QObject
    {
        Q_OBJECT
    public:
        /** pass in the playlist node! */
        Xspf( const class QDomElement& playlist_node, QObject* parent );

        QString title() const{ return m_title; }

        bool isEmpty() const { return m_tracks.isEmpty(); }
        Track takeFirst() { return m_tracks.takeFirst(); }

    signals:
        void expired();

    private slots:
        void onExpired();

    private:
        QList<Track> m_tracks;
        QString m_title;
    };
}

#endif

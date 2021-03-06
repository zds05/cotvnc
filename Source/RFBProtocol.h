/* RFBProtocol.h created by helmut on Tue 16-Jun-1998 */

/* Copyright (C) 1998-2000  Helmut Maierhofer <helmut.maierhofer@chello.at>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

#import <AppKit/AppKit.h>
#import "ByteReader.h"
#import "FrameBufferUpdateReader.h"

#define	MAX_MSGTYPE	rfbServerCutText

@interface RFBProtocol : ByteReader
{
    id			typeReader;
    id			msgTypeReader[MAX_MSGTYPE + 1];
    BOOL		isStopped;
    BOOL		shouldUpdate;

    CARD16		numberOfEncodings;
    CARD32		encodings[16];
}

- (id)initTarget:(id)aTarget serverInfo:(id)info;
- (void)setFrameBuffer:(id)aBuffer;
- (void)requestIncrementalFrameBufferUpdateForVisibleRect:(id)aReader;
- (void)continueUpdate;
- (void)stopUpdate;

- (void)requestUpdate:(NSRect)frame incremental:(BOOL)aFlag;
- (void)setPixelFormat:(rfbPixelFormat*)aFormat;

- (CARD16)numberOfEncodings;
- (CARD32*)encodings;
- (void)changeEncodingsTo:(CARD32*)newEncodings length:(CARD16)l;
- (void)setEncodings;

- (FrameBufferUpdateReader*)frameBufferUpdateReader;

@end

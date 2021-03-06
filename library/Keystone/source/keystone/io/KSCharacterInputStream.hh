// 
// $Id: KSCharacterInputStream.hh 54 2010-01-21 23:16:48Z brian $
// Keystone Framework
// 
// Copyright (c) 2010 Wolter Group New York, Inc., All rights reserved.
// 
// This software ("WGNY Software") is supplied to you by Wolter Group New York
// ("WGNY") in consideration of your acceptance of the terms of the Agreement
// under which the software was licensed to you. Your use or installation of
// this Software constitutes acceptance of these terms.  If you do not agree
// with these terms, do not use or install this software.
// 
// The WGNY Software is provided by WGNY on an "AS IS" basis.  WGNY MAKES NO
// WARRANTIES, EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION THE IMPLIED
// WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY AND FITNESS FOR A
// PARTICULAR PURPOSE, REGARDING THE WGNY SOFTWARE OR ITS USE AND OPERATION
// ALONE OR IN COMBINATION WITH YOUR PRODUCTS.
// 
// IN NO EVENT SHALL WGNY BE LIABLE FOR ANY SPECIAL, INDIRECT, INCIDENTAL OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) ARISING IN ANY WAY OUT OF THE USE, REPRODUCTION, MODIFICATION
// AND/OR DISTRIBUTION OF THE WGNY SOFTWARE, HOWEVER CAUSED AND WHETHER UNDER
// THEORY OF CONTRACT, TORT (INCLUDING NEGLIGENCE), STRICT LIABILITY OR
// OTHERWISE, EVEN IF WGNY HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// 
// Designed and Engineered by Wolter Group in New York City
// 

#if !defined(__KEYSTONE_KSCHARACTERINPUTSTREAM__)
#define __KEYSTONE_KSCHARACTERINPUTSTREAM__ 1

#include <CoreFoundation/CoreFoundation.h>

#include "KSInputStream.hh"
#include "KSTypes.hh"
#include "KSStatus.hh"

#include "CFStringAdditions.hh"

#define KEYSTONE_CLASS_KSCharacterInputStream "KSCharacterInputStream"

typedef enum KSCharacterInputStreamMask_ {
  KSCharacterInputStreamOptionNone              = 0,
  KSCharacterInputStreamOptionDiscardDelimiter  = 1 << 0,
  KSCharacterInputStreamOptionDiscardGreedy     = 1 << 1
} KSCharacterInputStreamMask;

typedef int KSCharacterInputStreamOptions;

/**
 * An input stream filter which treats the underlying stream as a sequence
 * of characters.
 * 
 * @author BWW
 */
class KSCharacterInputStream : public KSInputStream {
private:
  KSInputStream       *_istream;
  CFMutableStringRef  _buffer;
  CFStringEncoding    _encoding;
  bool                _bom;
  
protected:
  KSLength findCharacterOffsetInBuffer(CFCharacterSetRef term, KSLength start = 0);
  
public:
  KSCharacterInputStream(KSInputStream *stream, CFStringEncoding encoding = kDefaultStringEncoding, bool bom = true);
  virtual ~KSCharacterInputStream();
  
  virtual unsigned long getTypeID() const { return KSCharacterInputStreamTypeID; }
  
  KSInputStream *   getInputStream(void) const;
  CFStringEncoding  getEncoding(void) const;
  bool              useByteOrderMarker(void) const;
  CFIndex           getBufferLength(void) const;
  
  virtual KSStatus read(KSByte *bytes, KSLength count, KSLength *actual);
  virtual KSStatus readCharacter(UniChar *character, KSLength *actual);
  virtual KSStatus readCharacters(CFStringRef *string, KSLength count, KSLength *actual);
  virtual KSStatus readUntilCharacterInSetAsCFString(CFStringRef *string, CFCharacterSetRef term, KSCharacterInputStreamOptions options, KSLength *actual);
  virtual KSStatus readLineAsCFString(CFStringRef *string, KSCharacterInputStreamOptions options, KSLength *actual);
  virtual KSStatus close(void);
  
};

#endif __KEYSTONE_KSCHARACTERINPUTSTREAM__



// 
// $Id: KSBoolean.hh 21 2008-12-15 03:45:09Z brian $
// Keystone Framework
// 
// Copyright (c) 2008 Wolter Group New York, Inc., All rights reserved.
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

#if !defined(__KEYSTONE_KSBOOLEAN__)
#define __KEYSTONE_KSBOOLEAN__ 1

#include <CoreFoundation/CoreFoundation.h>

#include "KSObject.hh"
#include "KSTypes.hh"

#define KEYSTONE_CLASS_KSBoolean "KSBoolean"

/**
 * A number.  A Keystone wrapper around the CFNumber type.
 * 
 * @author Brian William Wolter &lt;<a href="mailto:brian@woltergroup.net">brian@woltergroup.net</a>&gt;
 */
class KSBoolean : public KSObject {
private:
  bool    _boolean;
  
public:
  KSBoolean(bool b);
  virtual ~KSBoolean();
  
  virtual unsigned long getTypeID() const { return KSBooleanTypeID; }
  
  bool getBooleanValue(void) const;
  bool isTrue(void) const;
  
  virtual bool isEqual(KSObject *o) const;
  virtual CFHashCode getHashCode(void) const;
  virtual CFStringRef copyDescription(void) const;
  
};

extern const KSBoolean *kKSTrue;      ///< Singleton KSBoolean true value
extern const KSBoolean *kKSFalse;     ///< Singleton KSBoolean false value

#endif __KEYSTONE_KSBOOLEAN__



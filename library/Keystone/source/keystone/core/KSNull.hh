// 
// $Id: KSNull.hh 25 2008-12-23 01:45:48Z brian $
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

#if !defined(__KEYSTONE_KSNULL__)
#define __KEYSTONE_KSNULL__ 1

#include <CoreFoundation/CoreFoundation.h>

#include "KSObject.hh"
#include "KSTypes.hh"

#define KEYSTONE_CLASS_KSNull "KSNull"

/**
 * A null type.
 * 
 * @author Brian William Wolter &lt;<a href="mailto:brian@woltergroup.net">brian@woltergroup.net</a>&gt;
 */
class KSNull : public KSObject {
public:
  KSNull();
  virtual ~KSNull();
  
  virtual unsigned long getTypeID() const { return KSNullTypeID; }
  
  virtual bool isEqual(KSObject *o) const;
  virtual CFStringRef copyDescription(void) const;
  
};

extern const KSNull *__kKSNull;   ///< Singleton KSNull value
#define kKSNull ((KSNull *)__kKSNull)

#endif __KEYSTONE_KSNULL__



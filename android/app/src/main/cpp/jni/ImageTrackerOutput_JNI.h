//
//  Created by Andy Chu on 6/1/17.
//  Copyright © 2017 Viro Media. All rights reserved.
//
//  Permission is hereby granted, free of charge, to any person obtaining
//  a copy of this software and associated documentation files (the
//  "Software"), to deal in the Software without restriction, including
//  without limitation the rights to use, copy, modify, merge, publish,
//  distribute, sublicense, and/or sell copies of the Software, and to
//  permit persons to whom the Software is furnished to do so, subject to
//  the following conditions:
//
//  The above copyright notice and this permission notice shall be included
//  in all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
//  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
//  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
//  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
//  CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
//  TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
//  SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef ANDROID_IMAGETRACKEROUTPUT_JNI_H
#define ANDROID_IMAGETRACKEROUTPUT_JNI_H

#include <memory>

#include "VRODefines.h"
#include VRO_C_INCLUDE

#if ENABLE_OPENCV

#include "VROARImageTracker.h"
#include "PersistentRef.h"

namespace ImageTrackerOutput {
    inline jlong jptr(std::shared_ptr<VROARImageTrackerOutput> tracker) {
        PersistentRef<VROARImageTrackerOutput> *nativeTracker = new PersistentRef<VROARImageTrackerOutput>(tracker);
        return reinterpret_cast<intptr_t>(nativeTracker);
    }

    inline std::shared_ptr<VROARImageTrackerOutput> native(jlong ptr) {
        PersistentRef<VROARImageTrackerOutput> *persistentOutput = reinterpret_cast<PersistentRef<VROARImageTrackerOutput> *>(ptr);
        return persistentOutput->get();
    }
}

#endif /* ENABLE_OPENCV */

#endif //ANDROID_IMAGETRACKEROUTPUT_JNI_H

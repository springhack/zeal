/*
 *  Author: SpringHack - springhack@live.cn
 *  Last modified: 2022-11-01 17:08:19
 *  Filename: ../util/macos_platform.mm
 *  Description: Created by SpringHack using vim automatically.
 */
#import <AppKit/AppKit.h>

#include "macos_platform.h"

namespace macos {

void setDockEnabled(bool enable) {
  ProcessSerialNumber psn = {0, kCurrentProcess};
  if (enable) {
    TransformProcessType(&psn, kProcessTransformToForegroundApplication);
  } else {
    TransformProcessType(&psn, kProcessTransformToUIElementApplication);
  }
  // if (enable) {
  //   [NSApp setActivationPolicy:NSApplicationActivationPolicyRegular];
  // } else {
  //   [NSApp setActivationPolicy:NSApplicationActivationPolicyAccessory];
  // }
}

}

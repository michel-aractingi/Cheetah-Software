#include "ControllerBridge.h"

void ControllerBridge::runController() {
  _mutex.lock();

  u32 idx = 0;
  for(u32 leg = 0; leg < 4; leg++) {
    for(u32 joint = 0; joint < 3; joint++) {
      _legController->commands[leg].qDes[joint] = command.q_des[idx];
      _legController->commands[leg].qdDes[joint] = command.qd_des[idx];
      _legController->commands[leg].kpJoint(joint,joint) = command.kp_joint[idx];
      _legController->commands[leg].kdJoint(joint,joint) = command.kd_joint[idx];
      _legController->commands[leg].tauFeedForward[joint] = command.tau_ff[idx];
      idx++;
    }
  }


  _mutex.unlock();
}
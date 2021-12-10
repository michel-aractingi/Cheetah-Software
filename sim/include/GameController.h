/*! @file GameController.h
 *  @brief Code to read the Logitech F310 Game Controller
 *  Creates a DriverCommand object to be sent to the robot controller
 *  Used in the development simulator and in the robot control mode
 */

#ifndef PROJECT_GAMECONTROLLER_H
#define PROJECT_GAMECONTROLLER_H

#include "SimUtilities/GamepadCommand.h"
#include <QtCore/QObject>

#include <lcm-cpp.hpp>
#include <thread>
#include "gamepad_lcmt.hpp"

class QGamepad;  // for an unknown reason, #including <QtGamepad/QGamepad> here
                 // makes compilation *very* slow

class GameController : public QObject {
  Q_OBJECT
 public:
  explicit GameController(QObject *parent = 0);
  void updateGamepadCommand(GamepadCommand &gamepadCommand);
  void findNewController();
  ~GameController();

 private:
  QGamepad *_qGamepad = nullptr;

  // if no joystick, set up the lcmt_channel for it
  gamepad_lcmt _gamepad_lcmt;
  lcm::LCM _lcm;
  void handleLCMJoystick(const lcm::ReceiveBuffer* rbuf,
                         const std::string& chan,
                         const gamepad_lcmt* msg);
  void lcmJoystickThread(){ while(true){ _lcm.handle();  } }
  std::thread _lcmThread;
};

#endif  // PROJECT_GAMECONTROLLER_H

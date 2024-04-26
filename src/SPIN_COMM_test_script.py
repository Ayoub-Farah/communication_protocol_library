"""
Copyright (c) 2021-2024 LAAS-CNRS

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation, either version 2.1 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with this program.  If not, see <https://www.gnu.org/licenses/>.

SPDX-License-Identifier: LGLPV2.1
"""

"""
@brief  This is a class for the factory test of Twitst 1.4.1

@author Luiz Villa <luiz.villa@laas.fr>
@author Guillaume Arthaud <thomas.walter@laas.fr>
"""

import serial,  find_devices
from Twist_Class import Twist_Device

twist_vid = 0x2fe3
twist_pid = 0x0100

Twist_ports = find_devices.find_twist_device_ports(twist_vid, twist_pid)
print(Twist_ports)

Twist = Twist_Device(twist_port= Twist_ports[0])


# message = Twist.sendCommand("IDLE")
# print(message)

# message = Twist.sendCommand( "BUCK", "LEG2", "ON")
# print(message)
# message = Twist.sendCommand( "BUCK", "LEG1", "ON")
# print(message)

# message = Twist.sendCommand("LEG","LEG1","ON")
# print(message)
# message = Twist.sendCommand("LEG","LEG2","ON")
# print(message)

# message = Twist.sendCommand("DEAD_TIME_RISING", "LEG1", 300)
# print(message)
# message = Twist.sendCommand("DEAD_TIME_FALLING", "LEG1", 100)
# print(message)

# message = Twist.sendCommand("POWER_ON")
# print(message)

# message = Twist.sendCommand("DUTY", "LEG1", 0.5)
# print(message)
# message = Twist.sendCommand("DUTY", "LEG2", 0.5)
# print(message)

# message = Twist.sendCommand("PHASE_SHIFT", "LEG2", 180)



#---------------REFERENCE TEST------------------------------------

duty_cycle = [0.1, 0.2, 0.3, 0.4, 0.5, 0.8, 0.9]
phase_shift = [0, 30, 60, 90, 120, 180, 220]

for duty, phase in zip(duty_cycle, phase_shift):
  Twist.sendCommand("DUTY", "LEG1", duty)
  Twist.sendCommand("DUTY", "LEG2", duty)
  Twist.sendCommand("PHASE_SHIFT", "LEG2", phase)

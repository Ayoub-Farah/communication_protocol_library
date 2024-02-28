/*
 * Copyright (c) 2024 LAAS-CNRS
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU Lesser General Public License as published by
 *   the Free Software Foundation, either version 2.1 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU Lesser General Public License for more details.
 *
 *   You should have received a copy of the GNU Lesser General Public License
 *   along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 * SPDX-License-Identifier: LGLPV2.1
 */

/**
 * @date   2024
 *
 * @author Ayoub Farah Hassan <ayoub.farah-hassan@laas.fr>
 */

#include "analog_comm.h"

#include "AnalogCommunication.h"

/////
// Public object to interact with the class

AnalogCommunication analogCommunication;

void AnalogCommunication::init()
{
    analog_comm_init();
}

float32_t AnalogCommunication::getAnalogCommValue()
{
    return analog_comm_get_value();
}

void AnalogCommunication::setAnalogCommValue(uint32_t analog_bus_value)
{
    analog_comm_set_value(analog_bus_value);
}


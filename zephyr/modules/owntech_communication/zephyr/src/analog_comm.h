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
 * @author Luiz Villa <luiz.villa@laas.fr>
 * @author Ayoub Farah Hassan <ayoub.farah-hassan@laas.fr>
 */

#ifndef ANALOG_COMM_H_
#define ANALOG_COMM_H_

#include <zephyr/kernel.h>
#include "arm_math.h"


/**
 * @brief    Initilializes the analog communication
 */
void analog_comm_init();

/**
 * @brief    Converts the values of the analog communication bus via ADC 4
 *
 * @return  a foat32_t value for analog communication bus
 */
float32_t analog_comm_get_value();

/**
 * @brief    Sets the value of the DAC2 which is used in the analog communication
 *
 * @param[in] analog_bus_value
 */
void analog_comm_set_value(uint32_t analog_bus_value);

#endif // ANALOG_COMM_H

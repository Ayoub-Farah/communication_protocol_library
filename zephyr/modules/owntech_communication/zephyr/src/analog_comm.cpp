/*
 * Copyright (c) 2022 LAAS-CNRS
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
 * @date   2022
 *
 * @author Luiz Villa <luiz.villa@laas.fr>
 */


#include "analog_comm.h"

// OwnTech Power API
#include "DataAPI.h"
#include "SpinAPI.h"


// OwnTech peripherals used in the analog communication
uint8_t analog_comm_adc_number = 4;
uint8_t analog_comm_dac_number = 2;
uint8_t analog_comm_dac_channel = 1;


void analog_comm_init()
{
    data.enableShieldChannel(4, ANALOG_COMM);
    spin.dac.initConstValue(analog_comm_dac_number);
}

void analog_comm_trigger()
{
    spin.adc.triggerSoftwareConversion(analog_comm_adc_number, 1);
}

float32_t analog_comm_get_value()
{
	return data.getLatest(ANALOG_COMM);
}

void analog_comm_set_value(uint32_t analog_comm_value)
{
    spin.dac.setConstValue(analog_comm_dac_number, analog_comm_adc_number, analog_comm_value);
}

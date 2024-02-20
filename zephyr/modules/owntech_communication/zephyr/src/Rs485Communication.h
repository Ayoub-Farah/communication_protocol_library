/*
 * Copyright (c) 2023 LAAS-CNRS
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
 * @date   2023-2024
 *
 * @author Ayoub Farah Hassan <ayoub.farah-hassan@laas.fr>
 */

#ifndef RS485COMMUNICATION_H_
#define RS485COMMUNICATION_H_

#include <stdint.h>

#ifdef CONFIG_OWNTECH_COMMUNICATION_ENABLE_RS485

/////
// Static class definition

class Rs485Communication
{
    public :
        /**
         * @brief Default configuration for RS485 communication using a 10Mbit/s speed
         *
         * @param transmission_buffer Pointer to the transmitted buffer
         * @param reception_buffer Pointer to the recevied buffer
         * @param data_size Size of the sent and received data (in byte)
         * @param user_function Callback function called when we received data
         *
         * @warning the size of transmission_buffer and reception_buffer must be the same
         */
        void configureDefault(uint8_t *transmission_bufer, uint8_t *reception_buffer, uint16_t data_size, void (*user_function)());

        /**
         * @brief Custom configuration for RS485 communication to choose the communication speed
         *
         * @param transmission_buffer Pointer to the transmitted buffer
         * @param reception_buffer Pointer to the recevied buffer
         * @param data_size Size of the sent and received data (in byte)
         * @param user_function Callback function called when we received data
         * @param baudrate communication speed in bit/s
         * @param oversampling_8 True for oversampling (and multiply communication speed by 2), false if you want to keep the normal speed communication
         *
         * @warning the size of transmission_buffer and reception_buffer must be the same
         */
        void configure(uint8_t *transmission_bufer, uint8_t *reception_buffer, uint16_t data_size, void (*user_function)(void), uint32_t baudrate, bool oversampling_8);

        /**
         * @brief start a transmission i.e. you send what is contained in the transmission buffer
        */
        void startTransmission();

        /**
         * @brief Turn on the RS485 communication
         *
         * @remark The RS485 is automatically turned on when initializing with configureDefault or configure, no need to call this function
        */
        void turnOnCommunication();

        /**
         * @brief Turn off the RS485
        */
        void turnOffCommunication();
};

/////
// Public object to interact with the class

extern Rs485Communication rs485Communication;

#endif // CONFIG_OWNTECH_COMMUNICATION_ENABLE_RS485

#endif // RS485COMMUNICATION_H_

/*
 * State machine with learning capabilities.
 *
 * Copyright (C) 2014 Poliprojekt.pl sp. z o.o.
 * Author: Marek Smigielski <marek.smigielski@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */

#ifndef _TEST_
#include <Arduino.h>
#else
#include "mock_arduino.h"
#endif

#include "SimpleMemory.h"

namespace q_behave {

SimpleMemory::SimpleMemory(StateMap _stateMap, double* _internalMemmory[]) : Memory(_stateMap) {
	this->internalMemmory=_internalMemmory;

}

void SimpleMemory::storeInternal(int memoryNumber) {
	int position = 0;
	for (int i = 0; i < stateMap.stateCount; i++) {
		for (int j = 0; j < stateMap.states[i].actionCount; j++) {
			internalMemmory[memoryNumber][position++] =
					stateMap.states[i].actions[j].quality;
		}
	}
}

void SimpleMemory::loadInternal(int memoryNumber) {
	int position = 0;
	for (int i = 0; i < stateMap.stateCount; i++) {
		for (int j = 0; j < stateMap.states[i].actionCount; j++) {
			stateMap.states[i].actions[j].quality =
					internalMemmory[memoryNumber][position++];
		}
	}
}

} /* namespace q_behave */

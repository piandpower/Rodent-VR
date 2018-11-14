// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <string>
#include <map>
#include "CoreMinimal.h"

/**
 * 
 */
class RODENT_VR_API BallInput
{
public:
	/**
		Returns the amount of movement that has been detected since the last
		call to get_movement_delta()
	*/
	static void get_movement_delta(float* out_x, float* out_y);

	/**
		Initializes module for reading movement input.
		This component reads movement input by measuring the changes in position measured by
		two optical computer mice placed 90 degrees from each other on the equator of a 
		ball. The mice should be placed such that the Y axis of the device points upward.
		Mouse B should be placed directly behind the rodent, and Mouse A should be placed on the side.

		The component works by reading the Y axis deltas of the two optical mice simultaneously.
		Mouse A's Y delta represents movement in X, while Mouse B's Y delta represents movement in Y.

		The method takes as input a map of configuration parameters. The confiuration parameters that
		are accepted by this module are: "mouse_a_name" and "mouse_b_name".
		The names of the computer mice can be found on Windows by:
		Opening Windows' Device Manager > Selecting a device > Details > Device instance path.
	*/
	static void initialize(std::wstring mouse_a_name, std::wstring mouse_b_name);

	/**
		Starts reading from input devices to determine movement.
		Input devices are read on a separate thread and accumulated.
		Call get_movement_delta() to determine how much movement
		has occurred since the last call.
	*/
	static void start();

	/**
		Stops reading from input devices and terminates reading thread.
	*/
	static void stop();
	BallInput();
	~BallInput();
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "NIDAQ.generated.h"

#define DAQmxErrChk(functionCall) if( DAQmxFailed(error=(functionCall)) ) goto Error; else
#define Debug(time, color, x) if(GEngine){GEngine->AddOnScreenDebugMessage(-1, time, color, x);}
/**
 * 
 */
UCLASS()
class RODENT_VR_API UNIDAQ : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category="Maze Events")
	static void control_NIDAQ(bool isOn, FString deviceName);
	
	UFUNCTION(BlueprintCallable, Category="Maze Events")
	static void init_NIDAQ();

	static void NIDAQ_write_digital(const char* deviceName, unsigned long data);
};

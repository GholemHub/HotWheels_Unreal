// Fill out your copyright notice in the Description page of Project Settings.


#include "C_Wheel_Front.h"

UC_Wheel_Front::UC_Wheel_Front()
{
	AxleType = EAxleType::Front;
	bAffectedByEngine = true;
	bAffectedBySteering = true;
	MaxSteerAngle = 45;
}

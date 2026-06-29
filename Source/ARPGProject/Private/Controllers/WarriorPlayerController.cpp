// Fill out your copyright notice in the Description page of Project Settings.


#include "Controllers/WarriorPlayerController.h"

AWarriorPlayerController::AWarriorPlayerController()
{
	HeroTeamID = FGenericTeamId(0);
}

FGenericTeamId AWarriorPlayerController::GetGenericTeamId() const
{
	return HeroTeamID;
}

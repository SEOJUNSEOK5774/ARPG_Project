// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/StartUpData/MyDataAsset_StartUpBase.h"
#include "WarriorTypes/WarriorStructTypes.h"
#include "DataAsset_HeroStartUp.generated.h"


/**
 * 
 */
UCLASS()
class ARPGPROJECT_API UDataAsset_HeroStartUp : public UMyDataAsset_StartUpBase
{
	GENERATED_BODY()

public:
		virtual void GiveToAbilitiesSystemComponent(UWarriorAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1) override;

	
private:
	UPROPERTY(EditAnywhere, Category = "StartUpData", meta = (TitleProperty = "InputTag"))
	TArray< FWarriorHeroAbilitySet> HeroStartUpAbilitySets;
};

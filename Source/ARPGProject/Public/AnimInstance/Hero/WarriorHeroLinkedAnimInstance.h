// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnimInstance/WarriorBaseAnimInstance.h"
#include "WarriorHeroLinkedAnimInstance.generated.h"

class UWarriorCharacterAnimInstance;
/**
 * 
 */
UCLASS()
class ARPGPROJECT_API UWarriorHeroLinkedAnimInstance : public UWarriorBaseAnimInstance
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintPure, meta = (BlueprintThreadSafe))
	UWarriorCharacterAnimInstance* GetHeroAnimInstance() const;

};

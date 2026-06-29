// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "MyDataAsset_StartUpBase.generated.h"

class UWarriorGameplayAbility;
class UWarriorAbilitySystemComponent;
class UGameplayEffect;
/**
 * 
 */
UCLASS()
class ARPGPROJECT_API UMyDataAsset_StartUpBase : public UDataAsset
{
	GENERATED_BODY()

public:
	virtual void GiveToAbilitiesSystemComponent(UWarriorAbilitySystemComponent* InASCToGive , int32 ApplyLevel = 1);

protected:
	UPROPERTY(EditAnywhere, Category = "StartUpData")
	TArray<TSubclassOf<UWarriorGameplayAbility>> ActivataOnGivenAbilities;

	UPROPERTY(EditAnywhere, Category = "StartUpData")
	TArray<TSubclassOf<UWarriorGameplayAbility>> ReactiveAbilities;

	UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
	TArray< TSubclassOf < UGameplayEffect > > StartUpGameplayEffects;


	void GrantAbiilties(const TArray<TSubclassOf<UWarriorGameplayAbility>>& InAbilitiesToGive , UWarriorAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1);
	
};

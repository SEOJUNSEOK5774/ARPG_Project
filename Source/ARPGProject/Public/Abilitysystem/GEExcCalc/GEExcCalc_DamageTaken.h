// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectExecutionCalculation.h"
#include "GEExcCalc_DamageTaken.generated.h"

/**
 * 
 */
UCLASS()
class ARPGPROJECT_API UGEExcCalc_DamageTaken : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()
	

public:
	UGEExcCalc_DamageTaken();

	virtual void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;
};

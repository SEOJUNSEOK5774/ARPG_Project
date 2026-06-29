// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstance/Hero/WarriorHerorAnimInstance.h"
#include "Characters/WarriorHeroCharacter.h"

void UWarriorHerorAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	if (OwningCharacter)
	{
		OwningHeroCharacter = Cast<AWarriorHeroCharacter>(OwningCharacter);
	}
		
}

void UWarriorHerorAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);
	{
		if (bHAsAcceleration)
		{
			IdelElpasedTime = 0.f;

			bShouldEnterRelaxState = false;
		}

		else
		{
			IdelElpasedTime += DeltaSeconds;

			bShouldEnterRelaxState = (IdelElpasedTime >= EnterRelaxStateThreshold);
		}
	}
}

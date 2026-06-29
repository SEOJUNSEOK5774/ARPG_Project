// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstance/Hero/WarriorHeroLinkedAnimInstance.h"
#include "AnimInstance/Hero/WarriorHerorAnimInstance.h"

UWarriorCharacterAnimInstance* UWarriorHeroLinkedAnimInstance::GetHeroAnimInstance() const
{
    return Cast<UWarriorCharacterAnimInstance>(GetOwningComponent()->GetAnimInstance());
     
}

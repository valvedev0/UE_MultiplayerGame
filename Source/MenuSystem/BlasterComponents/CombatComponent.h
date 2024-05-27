// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CombatComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MENUSYSTEM_API UCombatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCombatComponent();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//make this a friend class of BlasterCharacter so that it can access all the fns and variables
	friend class ABlasterCharacter;

	void EquipWeapon(class AWeapon* WeaponToEquip);
	//function to register replicated variables
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:

	class ABlasterCharacter* Character;
	//this variable needs to be replicated in order to animate the client side and it needs to be registered as well.
	UPROPERTY(Replicated)
	AWeapon* EquippedWeapon;

public:	
	// Called every frame
	
};

// vibrunazo

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataAsset_StartupDataBase.generated.h"

class UWarriorAbilitySystemComponent;
class UWarriorGameplayAbility;
/**
 * 
 */
UCLASS()
class WARRIOR_API UDataAsset_StartupDataBase : public UDataAsset
{
	GENERATED_BODY()

public:
	virtual void GiveToAbilitySystemComponent(UWarriorAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1);

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Startup Data")
	TArray< TSubclassOf< UWarriorGameplayAbility > > ActivateOnGivenAbilities;
	
	UPROPERTY(EditDefaultsOnly, Category = "Startup Data")
	TArray< TSubclassOf< UWarriorGameplayAbility > > ReactiveAbilities;

	static void GrantAbilities(TArray< TSubclassOf< UWarriorGameplayAbility > >& InAbilitiesToGive, UWarriorAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1);
	

	
	
};

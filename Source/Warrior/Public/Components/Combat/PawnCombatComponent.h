// vibrunazo

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/PawnExtensionComponentBase.h"
#include "PawnCombatComponent.generated.h"

class AWarriorWeaponBase;
/**
 * 
 */
UCLASS()
class WARRIOR_API UPawnCombatComponent : public UPawnExtensionComponentBase
{
	GENERATED_BODY()

public:
	/**Register a spawned weapon in the CharacterCarriedWeaponsMap
	 * 
	 * @param InWeaponTagToRegister Used as index to look up weapon in map
	 * @param InWeaponToRegister Reference to the weapon actor placed in the character's socket
	 * @param bRegisterAsEquippedWeapon Player weapons will start unequipped, enemies will start equipped
	 */
	UFUNCTION(BlueprintCallable, Category = "Warrior|Combat")
	void RegisterSpawnedWeapon(FGameplayTag InWeaponTagToRegister, AWarriorWeaponBase* InWeaponToRegister, bool bRegisterAsEquippedWeapon = false);

	/**Retrieves the spawned weapon Actor in the Character's socket by tag
	 * 
	 * @param InWeaponTagToGet tag to look up
	 * @return The spawned weapon
	 */
	UFUNCTION(BlueprintCallable, Category = "Warrior|Combat")
	AWarriorWeaponBase* GetCarriedWeaponByTag(FGameplayTag InWeaponTagToGet) const;

	/**Retrieves the spawned weapon Actor in the Character's socket
	 * 
	 * @return The spawned weapon
	 */
	UFUNCTION(BlueprintCallable, Category = "Warrior|Combat")
	AWarriorWeaponBase* GetCurrentEquippedWeapon() const;

	/**Tag of the currently equipped weapon */
	UPROPERTY(BlueprintReadWrite, Category = "Warrior|Combat")
	FGameplayTag CurrentEquippedWeaponTag;

	

private:
	TMap<FGameplayTag, AWarriorWeaponBase*> CharacterCarriedWeaponsMap;
	
};

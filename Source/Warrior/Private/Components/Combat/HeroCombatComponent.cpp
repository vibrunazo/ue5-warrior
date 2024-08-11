// vibrunazo


#include "Components/Combat/HeroCombatComponent.h"

#include "Items/Weapons/WarriorHeroWeapon.h"

AWarriorHeroWeapon* UHeroCombatComponent::GetHeroCarriedWeaponByTag(FGameplayTag InWeaponTag) const
{
	return Cast<AWarriorHeroWeapon>(GetCarriedWeaponByTag(InWeaponTag));
}

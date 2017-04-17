/**
 * Adds the functionality for plugins to restrict player arsenals. By default
 * this API does not restrict any weapons, however a players arsenal can be
 * restricted by calling {@link #cs_setWeaponRestrictions} and removed
 * via {@link #cs_resetWeaponRestrictions}.
 */

#if defined _cs_weapon_restrict_included
  #endinput
#endif
#define _cs_weapon_restrict_included

#pragma reqlib "cs_weapon_restrictions"

#include <amxconst>

/*******************************************************************************
 * NATIVES
 ******************************************************************************/

/**
 * Returns a bitsum consisting of all of the {@code CSW_*} constants a player
 * is allowed to use.
 */
native cs_getAllowedWeapons(const id);

/**
 * Restricts the specified players arsenal to the specified weapons bitsum.
 * 
 * @param id       The player to restrict
 * @param weapons  A bitsum of {@code CSW_*} weapon constants representing the
 *                   weapons a player is allowed to use
 * @param fallback The {@code CSW_*} constant to fall back on if the player's
 *                   current weapon is not within the bitsum of available weapons.
 *                   If this weapon is not included within {@code weapons}, then
 *                   it will automatically be included
 * @param strip    {@code true} to strip weapons that the player is not allowed
 *                   to use, {@code false} otherwise
 * 
 * @noreturn
 */
native cs_setWeaponRestrictions(const id, const weapons,
                                const fallback = CSW_KNIFE,
                                const bool: strip = false);

/**
 * Removes any restrictions on a player's arsenal.
 */
native cs_resetWeaponRestrictions(const id);

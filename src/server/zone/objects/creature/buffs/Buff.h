/*
Copyright (C) 2007 <SWGEmu>
 
This File is part of Core3.
 
This program is free software; you can redistribute 
it and/or modify it under the terms of the GNU Lesser 
General Public License as published by the Free Software
Foundation; either version 2 of the License, 
or (at your option) any later version.
 
This program is distributed in the hope that it will be useful, 
but WITHOUT ANY WARRANTY; without even the implied warranty of 
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
See the GNU Lesser General Public License for
more details.
 
You should have received a copy of the GNU Lesser General 
Public License along with this program; if not, write to
the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 
Linking Engine3 statically or dynamically with other modules 
is making a combined work based on Engine3. 
Thus, the terms and conditions of the GNU Lesser General Public License 
cover the whole combination.
 
In addition, as a special exception, the copyright holders of Engine3 
give you permission to combine Engine3 program with free software 
programs or libraries that are released under the GNU LGPL and with 
code included in the standard release of Core3 under the GNU LGPL 
license (or modified versions of such code, with unchanged license). 
You may copy and distribute such a system following the terms of the 
GNU LGPL for Engine3 and the licenses of the other code concerned, 
provided that you include the source code of that other code when 
and as the GNU LGPL requires distribution of source code.
 
Note that people who make modified versions of Engine3 are not obligated 
to grant this special exception for their modified versions; 
it is their choice whether to do so. The GNU Lesser General Public License 
gives permission to release a modified version without this exception; 
this exception also makes it possible to release a modified version 
which carries forward this exception.
*/
#ifndef BUFF_H_
#define BUFF_H_

#include "BuffObject.h"

#include "../skillmods/SkillModList.h"

#include "../CreatureObject.h"
#include "../../player/PlayerObject.h"

class BuffObject;

/* some pseudo random Buff Types */

// It's potentially possible to have same icon for multiple buffs
// just not sure if they are different CRC or not.
class BuffCRC {
public:
	static const uint32 TEST_FIRST = 0x1967AF38;
	static const uint32 TEST_SECOND = 0xA24A7A5B;
	static const uint32 FOOD_DESSERT_BOFA_TREAT = 0x8B72DED3;
	static const uint32 FOOD_DISH_TRAVEL_BISCUITS = 0x62932AF7;
	static const uint32 FOOD_DRINK_SPICED_TEA = 0x717401BC;
	static const uint32 FOOD_DESSERT_BLOB_CANDY = 0x8268C9CB;
	static const uint32 FOOD_DRINK_CAF = 0x0BDFFC50;
	static const uint32 FOOD_DESSERT_PKNEB = 0xF12D3826;
	static const uint32 FOOD_DISH_KANALI_WAFERS = 0xFCBAD7ED;
	static const uint32 FOOD_DRINK_JAWA_BEER = 0x1D9DAE11;
	static const uint32 FOOD_DISH_TELTIER_NOODLES = 0x9AC8258E;
	static const uint32 FOOD_DESSERT_ALMOND_KWEVVU_CRISP_MUNCHIES = 0x8B82942E;
	static const uint32 FOOD_DISH_VEGHASH = 0xD94616DE;
	static const uint32 FOOD_DISH_GRUUVAN_SHAAL = 0x6F291A67;
	static const uint32 FOOD_DISH_SCRIMPI = 0xBCB608D9;
	static const uint32 FOOD_DISH_AHRISA = 0x234F7DA8;
	static const uint32 FOOD_DISH_RAKRIRIAN_BURNOUT_SAUCE = 0xC2D87307;
	static const uint32 FOOD_DISH_VEGEPARSINE = 0xF02878A3;
	static const uint32 FOOD_DISH_BIVOLI_TEMPARI = 0x2114D76D;
	static const uint32 FOOD_DISH_TERRATTA = 0x904ACDDB;
	static const uint32 FOOD_DISH_THAKITILLO = 0xDC5D4FD7;
	static const uint32 FOOD_DISH_VERCUPTI_OF_AGAZZA_BOLERUUEE = 0x50AFB0A1;
	static const uint32 FOOD_DRINK_GRALINYN_JUICE = 0x58BEB487;
	static const uint32 FOOD_DRINK_DEUTERIUM_PYRO = 0x522345BE;
	static const uint32 FOOD_DRINK_CORELLIAN_ALE = 0x02AE6B5E;
	static const uint32 FOOD_DRINK_DURINDFIRE = 0x728B0811;
	static const uint32 FOOD_DRINK_VERONIAN_BERRY_WINE = 0xABA01703;
	static const uint32 FOOD_DRINK_ITHORIAN_MIST = 0xBA83D0E2;
	static const uint32 FOOD_DRINK_CORELLIAN_BRANDY = 0xDFB97272;
	static const uint32 FOOD_DRINK_VAYERBOK = 0x188D3769;
	static const uint32 FOOD_DRINK_ELSHANDRUU_PICA_THUNDERCLOUD = 0x22B58BFA;
	static const uint32 FOOD_DRINK_VASARIAN_BRANDY = 0x292DD6D3;
	static const uint32 FOOD_DRINK_ACCARRAGM = 0xE61D3848;
	static const uint32 FOOD_DRINK_GARRMORL = 0x6B9D4C68;
	static const uint32 FOOD_DESSERT_WON_WON = 0xC4104F19;
	static const uint32 FOOD_DESSERT_CHANDAD = 0x7E4BED62;
	static const uint32 FOOD_DESSERT_DWEEZEL = 0x752E4991;
	static const uint32 FOOD_DESSERT_KIWIK_CLUSJO_SWIRL = 0x1B25BCC9;
	static const uint32 FOOD_DESSERT_VAGNERIAN_CANAPE = 0xFB554185;
	static const uint32 FOOD_DRINK_BREATH_OF_HEAVEN = 0xF87AA911;
	static const uint32 FOOD_MITIGATE_DAMAGE = 0x3B105001;
	static const uint32 FOOD_HEAL_RECOVERY = 0xB9EB6FC6;
	static const uint32 FOOD_INCAP_RECOVERY = 0x635AC195;
	static const uint32 FOOD_DODGE_ATTACK = 0x030F591C;
	static const uint32 FOOD_ATTACK_ACCURACY = 0x1E197C45;
	static const uint32 FOOD_POISON_DISEASE_RESIST = 0x6CB96F62;
	static const uint32 FOOD_BLEED_RESIST = 0x015260E8;
	static const uint32 FOOD_FIRE_RESIST = 0xF72CBED5;
	static const uint32 FOOD_XP_INCREASE = 0xD006C190;
	static const uint32 FOOD_CRAFT_BONUS = 0x65F96F03;
	static const uint32 FOOD_EXPERIMENT_BONUS = 0x9B38A4CB;
	static const uint32 FOOD_REDUCE_CLONE_WOUNDS = 0x9961A0F0;
	static const uint32 FOOD_REDUCE_SPICE_DOWNTIME = 0x956C8A0E;
	static const uint32 FOOD_ACCELERATE_ENTERTAINER_BUFF = 0x13F08F86;
	static const uint32 MEDICAL_ENHANCE_HEALTH = 0x98321369;
	static const uint32 MEDICAL_ENHANCE_STRENGTH = 0x815D85C5;
	static const uint32 MEDICAL_ENHANCE_CONSTITUTION = 0x7F86D2C6;
	static const uint32 MEDICAL_ENHANCE_ACTION = 0x4BF616E2;
	static const uint32 MEDICAL_ENHANCE_QUICKNESS = 0x71B5C842;
	static const uint32 MEDICAL_ENHANCE_STAMINA = 0xED0040D9;
	static const uint32 MEDICAL_ENHANCE_POISON = 0x391AC375;
	static const uint32 MEDICAL_ENHANCE_DISEASE = 0x3595876;
	static const uint32 PERFORMANCE_ENHANCE_DANCE_MIND = 0x11C1772E;
	static const uint32 PERFORMANCE_ENHANCE_MUSIC_FOCUS = 0x2E77F586;
	static const uint32 PERFORMANCE_ENHANCE_MUSIC_WILLPOWER = 0x3EC6FCB6;
	static const uint32 SPICE_BOOSTER_BLUE_UP = 0x18A5AEFB;
	static const uint32 SPICE_BOOSTER_BLUE_DOWN = 0xC62DFBF1;
	static const uint32 SPICE_CRASH_N_BURN_UP = 0x5E1BE4D6;
	static const uint32 SPICE_CRASH_N_BURN_DOWN = 0xA920056F;
	static const uint32 SPICE_DROID_LUBE_UP = 0x0C969AE9;
	static const uint32 SPICE_DROID_LUBE_DOWN = 0x7E3B0A02;
	static const uint32 SPICE_GIGGLEDUST_UP = 0x3E41BA17;
	static const uint32 SPICE_GIGGLEDUST_DOWN = 0xC11922D4;
	static const uint32 SPICE_GREY_GABAKI_UP = 0xE5C9CD20;
	static const uint32 SPICE_GREY_GABAKI_DOWN = 0xD2121CC4;
	static const uint32 SPICE_GUNJACK_UP = 0x09B6F8FC;
	static const uint32 SPICE_GUNJACK_DOWN = 0x13305C97;
	static const uint32 SPICE_MUON_GOLD_UP = 0xFBE87E37;
	static const uint32 SPICE_MUON_GOLD_DOWN = 0x8228D074;
	static const uint32 SPICE_NEUTRON_PIXEY_UP = 0x5DC6921F;
	static const uint32 SPICE_NEUTRON_PIXEY_DOWN = 0x8D549786;
	static const uint32 SPICE_PYREPENOL_UP = 0x1EBC62E5;
	static const uint32 SPICE_PYREPENOL_DOWN = 0x813D6F28;
	static const uint32 SPICE_SCRAMJET_UP = 0x2E03F676;
	static const uint32 SPICE_SCRAMJET_DOWN = 0xA02DF2DE;
	static const uint32 SPICE_SEDATIVE_H4B_UP = 0xD7A72ACF;
	static const uint32 SPICE_SEDATIVE_H4B_DOWN = 0x35D64963;
	static const uint32 SPICE_SHADOWPAW_UP = 0x3AAD2B89;
	static const uint32 SPICE_SHADOWPAW_DOWN = 0xE506BE60;
	static const uint32 SPICE_SWEETBLOSSOM_UP = 0x7EC00CB8;
	static const uint32 SPICE_SWEETBLOSSOM_DOWN = 0x5B3DB3C1;
	static const uint32 SPICE_THRUSTER_HEAD_UP = 0x530E31B7;
	static const uint32 SPICE_THRUSTER_HEAD_DOWN = 0x3AE01653;
	static const uint32 SPICE_YARROCK_UP = 0xE7F8C957;
	static const uint32 SPICE_YARROCK_DOWN = 0xA664F2EC;
	static const uint32 SPICE_KLIKNIK_BOOST_UP = 0x37173CAD;
	static const uint32 SPICE_KLIKNIK_BOOST_DOWN = 0x7DE346EF;
	static const uint32 SPICE_KWI_BOOST_UP = 0x629FA918;
	static const uint32 SPICE_KWO_BOOST_DOWN = 0x714E1687;
	static const uint32 JEDI_FORCE_RUN_1 = 0x9A04E4F8;
	static const uint32 JEDI_FORCE_RUN_2 = 0x9747C221;
	static const uint32 JEDI_FORCE_RUN_3 = 0x9386DF96;
	static const uint32 JEDI_FORCE_SPEED_1 = 0xA8A97B7F;
	static const uint32 JEDI_FORCE_SPEED_2 = 0xA5EA5DA6;
	static const uint32 JEDI_FORCE_ARMOR_1 = 0xFB65D2D6;
	static const uint32 JEDI_FORCE_ARMOR_2 = 0xF626F40F;
	static const uint32 JEDI_FORCE_SHIELD_1 = 0x10900417;
	static const uint32 JEDI_FORCE_SHIELD_2 = 0x1DD322CE;
	static const uint32 JEDI_FORCE_PROTECTION_1 = 0x6F1A719D;
	static const uint32 JEDI_FORCE_FEEDBACK_1 = 0xB9EC27B0;
	static const uint32 JEDI_FORCE_FEEDBACK_2 = 0xB4AF0169;
	static const uint32 JEDI_FORCE_ABSORB_1 = 0xA7FCF8F0;
	static const uint32 JEDI_FORCE_ABSORB_2 = 0xAABFDE29;
	static const uint32 JEDI_RESIST_DISEASE = 0xD9925CB4;
	static const uint32 JEDI_RESIST_POISON = 0x2F969FE7;
	static const uint32 JEDI_RESIST_BLEEDING = 0xADA10184;
	static const uint32 JEDI_RESIST_STATES = 0xB0457693;
	static const uint32 JEDI_AVOID_INCAPACITATION = 0x4FDD1C66;
	static const uint32 JEDI_AVOID_INCAPACITATION_1 = 0xA077BD29;
	static const uint32 JEDI_AVOID_INCAPACITATION_2 = 0xAD349BF0;
	static const uint32 JEDI_AVOID_INCAPACITATION_3 = 0xA9F58647;
	static const uint32 JEDI_AVOID_INCAPACITATION_4 = 0xB7B2D642;
	static const uint32 JEDI_AVOID_INCAPACITATION_5 = 0xB373CBF5;
	static const uint32 SKILL_BUFF_MELEE_ACCURACY = 0x548DE45B;
	static const uint32 SKILL_BUFF_RANGED_DEFENSE = 0xA6407812;
	static const uint32 SKILL_BUFF_CARBINE_ACCURACY = 0xA996D07E;
	static const uint32 SKILL_BUFF_CARBINE_SPEED = 0xC6148607;
	static const uint32 SKILL_BUFF_MASK_SCENT = 0x30EB839E;
	static const uint32 SKILL_BUFF_MELEE_DEFENSE = 0xC78FA3B7;
	static const uint32 SKILL_BUFF_ONEHANDMELEE_ACCURACY = 0x05C34219;
	static const uint32 SKILL_BUFF_ONEHANDMELEE_SPEED = 0x0696D76F;
	static const uint32 SKILL_BUFF_PISTOL_ACCURACY = 0x55471D61;
	static const uint32 SKILL_BUFF_PISTOL_SPEED = 0x26F41BAD;
	static const uint32 SKILL_BUFF_RIFLE_ACCURACY = 0x33ADEE46;
	static const uint32 SKILL_BUFF_RIFLE_SPEED = 0x1F7E043E;
	static const uint32 SKILL_BUFF_UNARMED_ACCURACY = 0x027D9E64;
	static const uint32 SKILL_BUFF_UNARMED_SPEED = 0x133ADA2F;
	static const uint32 SKILL_BUFF_TWOHANDMELEE_ACCURACY = 0x8F47051E;
	static const uint32 SKILL_BUFF_TWOHANDMELEE_SPEED = 0x5F1BD61A;
	static const uint32 SKILL_BUFF_RANGED_ACCURACY = 0x33329A7B;
	static const uint32 SKILL_BUFF_THROWN_ACCURACY = 0xBFEEDABF;
	static const uint32 SKILL_BUFF_THROWN_SPEED = 0x232EE11E;
	static const uint32 SKILL_BUFF_HEAVY_WEAPON_ACCURACY = 0xAFDFE174;
	static const uint32 SKILL_BUFF_HEAVY_WEAPON_SPEED = 0x311A7044;
	static const uint32 FORCE_RANK_SUFFERING = 0xF531B147;
	static const uint32 FORCE_RANK_SERENITY = 0xA09E5934;
	static const uint32 SKILL_BUFF_POLEARM_ACCURACY = 0xF0C5EEED;
	static const uint32 SKILL_BUFF_POLEARM_SPEED = 0x6F675FB6;	
};

class BuffType {
	public:
		static const int OTHER = 0;
		static const int FOOD = 1;
		static const int MEDICAL = 3;
		static const int PERFORMANCE = 4;
		static const int SPICE = 5;
		static const int SKILL = 6;
		static const int JEDI = 7;
		static const int INNATE = 8;
};

class Buff {

private:
	bool active;
	//bool activate;
	//bool deactivate;

protected:
	int buffType;
	float buffDuration;
	uint32 buffCRC;
	uint32 buffDownerCRC;
	

	
	// HAM Values - can be negative
	int healthBuff;
	int actionBuff;
	int mindBuff;
	
	int strengthBuff;
	int constitutionBuff;
	
	int staminaBuff;
	int quicknessBuff;
	
	int willpowerBuff;
	int focusBuff;
	
	int forcePowerBuff;
	//int forceRegenBuff;
	
	SkillModList skillModBuffs;
	

public:
	Buff(uint32 crc) {
		setBuffCRC(crc);
		setBuffDuration(0.0f);
		setBuffDownerCRC(0);
		
		// Defaults
		setBuffType(BuffType::OTHER);
		setHealthBuff(0);
		setActionBuff(0);
		setMindBuff(0);
		setStrengthBuff(0);
		setConstitutionBuff(0);
		setStaminaBuff(0);
		setQuicknessBuff(0);
		setWillpowerBuff(0);
		setFocusBuff(0);
		setForcePowerBuff(0);
		//setForceRegenBuff(0);
		
		active = false;
	}
	
	Buff(uint32 crc, int type, float duration) {
		setBuffCRC(crc);
		setBuffType(type);
		setBuffDuration(duration); // set in seconds?
		setBuffDownerCRC(0);

		// Defaults
		setHealthBuff(0);
		setActionBuff(0);
		setMindBuff(0);
		setStrengthBuff(0);
		setConstitutionBuff(0);
		setStaminaBuff(0);
		setQuicknessBuff(0);
		setWillpowerBuff(0);
		setFocusBuff(0);
		setForcePowerBuff(0);
		//setForceRegenBuff(0);
		
		active = false;
	}
	
	// TODO:  Need to do a better job with Shock Wounds
	bool activateBuff(CreatureObject* creo) {		
		// default to update client by not specifying true attrib
		if(getHealthBuff() != 0)
		{
			// sets both maxHealthBar and setHealthmax
			creo->setMaxHealthBar(creo->getHealthMax() + getHealthBuff());
			creo->setHealthBar(MIN(creo->getHealth() + getHealthBuff() - creo->getHealthWounds(), creo->getHealthMax() - creo->getHealthWounds()));
		}
		
		if(getActionBuff() != 0) {
			creo->setMaxActionBar(creo->getActionMax() + getActionBuff());
			creo->setActionBar(MIN(creo->getAction() + getActionBuff() - creo->getActionWounds(), creo->getActionMax() - creo->getActionWounds()));
		}
		
		if(getMindBuff() != 0) {
			creo->setMaxMindBar(creo->getMindMax() + getMindBuff());
			creo->setMindBar(MIN(creo->getMind() + getMindBuff() - creo->getMindWounds(), creo->getMindMax() - creo->getMindWounds()));
		}
		
		if(getStrengthBuff() != 0) {
			creo->setMaxStrengthBar(creo->getStrengthMax() + getStrengthBuff());
			creo->setStrengthBar(MIN(creo->getStrength() + getStrengthBuff(), creo->getStrengthMax()));
		}
		
		if(getConstitutionBuff() != 0) {
			creo->setMaxConstitutionBar(creo->getConstitutionMax() + getConstitutionBuff());
			creo->setConstitutionBar(MIN(creo->getConstitution() + getConstitutionBuff(), creo->getConstitutionMax()));
		}
		
		if(getStaminaBuff() != 0) {
			creo->setMaxStaminaBar(creo->getStaminaMax() + getStaminaBuff());
			creo->setStaminaBar(MIN(creo->getStamina() + getStaminaBuff(), creo->getStaminaMax()));
		}
		
		if(getQuicknessBuff() != 0) {
			creo->setMaxQuicknessBar(creo->getQuicknessMax() + getQuicknessBuff());
			creo->setQuicknessBar(MIN(creo->getQuickness() + getQuicknessBuff(), creo->getQuicknessMax()));
		}
		
		if(getWillpowerBuff() != 0) {
			creo->setMaxWillpowerBar(creo->getWillpowerMax() + getWillpowerBuff());
			creo->setWillpowerBar(MIN(creo->getWillpower() + getWillpowerBuff(), creo->getWillpowerMax()));
		}
		
		if(getFocusBuff() != 0) {
			creo->setMaxFocusBar(creo->getFocusMax() + getFocusBuff());
			creo->setFocusBar(MIN(creo->getFocus() + getFocusBuff(), creo->getFocusMax()));
		}
		
		if(getForcePowerBuff() != 0) {
			((PlayerObject*)creo)->setMaxForcePowerBar(((PlayerObject*)creo)->getForcePowerMax() + getForcePowerBuff());
			((PlayerObject*)creo)->setForcePowerBar(MIN(((PlayerObject*)creo)->getForcePower() + getForcePowerBuff(), ((PlayerObject*)creo)->getForcePowerMax()));				
		}

		//if(getForceRegenBuff() > 0) {
		//	((PlayerObject*)creo)->setForceRegen(((PlayerObject*)creo)->getForceRegen() + getForceRegenBuff());		
		//}
		
		// TODO: Add Skill Mods

//		((PlayerObject*) creo)->addBuff(getCRC(), duration);
		creo->addBuff(getBuffCRC(), getBuffDuration());

		active = true;
		return true;
		
	}
	
	
	// TODO:  Need to do a better job with Shock Wounds
	void downerBuff(CreatureObject* creo) {		
		Buff *buff = new Buff(getBuffDownerCRC(), BuffType::SPICE, round(getBuffDuration() / 3.0));
		
		// The Min Value of their total bar - 1 or the downer
		buff->setHealthBuff(-1 * MIN(creo->getHealthMax() - 1, getHealthBuff()));
		buff->setActionBuff(-1 * MIN(creo->getActionMax() - 1, getActionBuff()));
		buff->setMindBuff(-1 * MIN(creo->getMindMax() - 1, getMindBuff()));
		buff->setStrengthBuff(-1 * MIN(creo->getStrengthMax() - 1, getStrengthBuff()));
		buff->setConstitutionBuff(-1 * MIN(creo->getConstitutionMax() - 1, getConstitutionBuff()));
		buff->setStaminaBuff(-1 * MIN(creo->getStaminaMax() - 1, getStaminaBuff()));
		buff->setQuicknessBuff(-1 * MIN(creo->getQuicknessMax() - 1, getQuicknessBuff()));
		buff->setWillpowerBuff(-1 * MIN(creo->getWillpowerMax() - 1, getWillpowerBuff()));
		buff->setFocusBuff(-1 * MIN(creo->getFocusMax() - 1, getFocusBuff()));
		buff->setForcePowerBuff(-1 * MIN(((PlayerObject*)creo)->getForcePowerMax() - 1, getForcePowerBuff()));
		
		// TODO: Switch Skill Mods?
		BuffObject* bo = new BuffObject(buff);
		creo->applyBuff(bo);
	}
	
	bool deActivateBuff(CreatureObject* creo, bool updateClient = true) {
		if (!active) {
			creo->sendSystemMessage("buff not active - report repo steps to McMahon");
			return false;
		}
		
		if(getHealthBuff() != 0)
			creo->setMaxHealthBar(creo->getHealthMax() - getHealthBuff(), updateClient);
		
		if(getActionBuff() != 0)
			creo->setMaxActionBar(creo->getActionMax() - getActionBuff(), updateClient);
		
		if(getMindBuff() != 0)
			creo->setMaxMindBar(creo->getMindMax() - getMindBuff(), updateClient);
		
		if(getStrengthBuff() != 0)
			creo->setMaxStrengthBar(creo->getStrengthMax() - getStrengthBuff(), updateClient);
		
		if(getConstitutionBuff() != 0)
			creo->setMaxConstitutionBar(creo->getConstitutionMax() - getConstitutionBuff(), updateClient);
		
		if(getStaminaBuff() != 0)
			creo->setMaxStaminaBar(creo->getStaminaMax() - getStaminaBuff(), updateClient);
		
		if(getQuicknessBuff() != 0)
			creo->setMaxQuicknessBar(creo->getQuicknessMax() - getQuicknessBuff(), updateClient);
		
		if(getWillpowerBuff() != 0)
			creo->setMaxWillpowerBar(creo->getWillpowerMax() - getWillpowerBuff(), updateClient);
		
		if(getFocusBuff() != 0)
			creo->setMaxFocusBar(creo->getFocusMax() - getFocusBuff(), updateClient);
		
		if(getForcePowerBuff() != 0)
			((PlayerObject*)creo)->setMaxForcePowerBar(((PlayerObject*)creo)->getForcePowerMax() - getForcePowerBuff(), updateClient);

		//if(getForceRegenBuff() != 0)
		//	((PlayerObject*)creo)->setForceRegen(((PlayerObject*)creo)->getForceRegen() - getForceRegenBuff());

		// TODO: Remove Skill Mods
		
		// Remove from client buff list
		if (updateClient)
			creo->addBuff(getBuffCRC(), 0.0f);
		
		active = false;
		
		// Activate Downer
		if (getBuffType() == BuffType::SPICE && updateClient && getBuffDownerCRC() > 0)
			downerBuff(creo);
		
		return true;
	}
	
	// Getters
	inline uint32 getBuffCRC() {
		return buffCRC;
	}
	inline uint32 getBuffDownerCRC() {
		return buffDownerCRC;
	}
	inline int getBuffType() {
		return buffType;
	}
	inline float getBuffDuration() {
		return buffDuration;
	}
	inline int getHealthBuff() {
		return healthBuff;
	}
	inline int getActionBuff() {
		return actionBuff;
	}
	inline int getMindBuff() {
		return mindBuff;
	}
	inline int getStrengthBuff() {
		return strengthBuff;
	}
	inline int getConstitutionBuff() {
		return constitutionBuff;
	}
	inline int getStaminaBuff() {
		return staminaBuff;
	}
	inline int getQuicknessBuff() {
		return quicknessBuff;
	}
	inline int getWillpowerBuff() {
		return willpowerBuff;
	}
	inline int getFocusBuff() {
		return focusBuff;
	}
	inline int getForcePowerBuff() {
		return forcePowerBuff;
	}
	//inline int getForceRegenBuff() {
	//	return forceRegenBuff;
	//}
	
	// Setters
	inline void setBuffCRC(uint32 crc) {
		buffCRC = crc;
	}
	inline void setBuffDownerCRC(uint32 crc) {
		buffDownerCRC = crc;
	}
	inline void setBuffType(int type) {
		buffType = type;
	}
	inline void setBuffDuration(float duration) {
		buffDuration = duration;
	}
	inline void setHealthBuff(int health) {
		healthBuff = health;
	}
	inline void setActionBuff(int action) {
		actionBuff = action;
	}
	inline void setMindBuff(int mind) {
		mindBuff = mind;
	}
	inline void setStrengthBuff(int strength) {
		strengthBuff = strength;
	}
	inline void setConstitutionBuff(int constitution) {
		constitutionBuff = constitution;
	}
	inline void setStaminaBuff(int stamina) {
		staminaBuff = stamina;
	}
	inline void setQuicknessBuff(int quickness) {
		quicknessBuff = quickness;
	}
	inline void setWillpowerBuff(int willpower) {
		willpowerBuff = willpower;
	}
	inline void setFocusBuff(int focus) {
		focusBuff = focus;
	}
	inline void setForcePowerBuff(int force) {
		forcePowerBuff = force;
	}
	//inline void setForceRegenBuff(int regen) {
	//	forceRegenBuff = regen;
	//}
	
	// Skill Mods
	
	SkillModList* getSkillModBuffList() {
		return &skillModBuffs;
	}
	
	int getSkillModBuff(const string& name) {
		int bonus = skillModBuffs.get(name);
		return bonus;
	}
	
	bool hasSkillModBuff(const string& name) {
		return skillModBuffs.containsKey(name);
	}
	
	void removeSkillModBuff(string& name) {
		skillModBuffs.remove(name);
	}
	
	void addSkillModBuff(string mod, int val) {
		if(hasSkillModBuff(mod))
			removeSkillModBuff(mod);
		
		skillModBuffs.put(mod, val);
	}
};

#endif /*BUFF_H_*/

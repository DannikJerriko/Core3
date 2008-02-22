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

#ifndef CONTAINERIMPLEMENTATION_H_
#define CONTAINERIMPLEMENTATION_H_

#include "TangibleObject.h"

#include "Container.h"

class ContainerImplementation : public ContainerServant {
protected:
	VectorMap<uint64, SceneObject*> items;
	 
public:
	ContainerImplementation(uint64 oid) : ContainerServant(oid) {
		objectCRC = 0x3969E83B;
		
		items.setInsertPlan(SortedVector<VectorMapEntry<uint64, SceneObject*>*>::NO_DUPLICATE);
		items.setNullValue(NULL);

		stringstream loggingname;
		loggingname << "Container = 0x" << oid;
		setLoggingName(loggingname.str());
	
		setLogging(false);
		setGlobalLogging(true);
	}
		
	virtual ~ContainerImplementation() {
		for (int i = 0; i < items.size(); ++i) {
			SceneObject* item = items.get(i);
			
			if (item->isTangible())
				((TangibleObject*) item)->setContainer(NULL);
			
			delete item;
		}
		
		items.removeAll();
	}
	
	void addObject(SceneObject* obj) {
		uint64 oid = obj->getObjectID(); 
		items.put(oid, obj);
	}

	SceneObject* getObject(int index) {
		return items.get(index);
	}

	SceneObject* getObject(uint64 oid) {
		return items.get(oid);
	}

	void removeObject(int index) {
		SceneObject* item = items.get(index);
	
		items.remove(index);

		if (item->isTangible())
			((TangibleObject*) item)->setContainer(NULL);
	}

	void removeObject(uint64 oid) {
		SceneObject* item = items.get(oid);
		
		items.drop(oid);
		
		if (item != NULL && item->isTangible())
			((TangibleObject*) item)->setContainer(NULL);
	}

	int objectsSize() {
		return items.size();
	}
	
	bool isEmpty() {
		return items.isEmpty();
	}

};

#endif /*CONTAINERIMPLEMENTATION_H_*/

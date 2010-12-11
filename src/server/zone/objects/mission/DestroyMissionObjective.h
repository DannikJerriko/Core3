/*
 *	server/zone/objects/mission/DestroyMissionObjective.h generated by engine3 IDL compiler 0.60
 */

#ifndef DESTROYMISSIONOBJECTIVE_H_
#define DESTROYMISSIONOBJECTIVE_H_

#include "engine/orb/DistributedObjectBroker.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

namespace server {
namespace zone {
namespace objects {
namespace mission {

class MissionObject;

} // namespace mission
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::mission;

namespace server {
namespace zone {
namespace objects {
namespace mission {

class MissionObserver;

} // namespace mission
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::mission;

namespace server {
namespace zone {
namespace objects {
namespace scene {

class SceneObject;

} // namespace scene
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::scene;

namespace server {
namespace zone {
namespace templates {

class SharedObjectTemplate;

} // namespace templates
} // namespace zone
} // namespace server

using namespace server::zone::templates;

namespace server {
namespace zone {
namespace objects {
namespace area {

class MissionSpawnActiveArea;

} // namespace area
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::area;

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace lair {

class LairObject;

} // namespace lair
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::lair;

#include "server/zone/templates/TemplateReference.h"

#include "engine/util/Observer.h"

#include "engine/util/Observable.h"

#include "server/zone/objects/mission/MissionObjective.h"

namespace server {
namespace zone {
namespace objects {
namespace mission {

class DestroyMissionObjective : public MissionObjective {
public:
	DestroyMissionObjective(MissionObject* mission);

	void initializeTransientMembers();

	void activate();

	void abort();

	void complete();

	void spawnLair();

	void destroyObjectFromDatabase();

	int notifyObserverEvent(MissionObserver* observer, unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2);

	void setLairTemplateToSpawn(SharedObjectTemplate* sp);

	DistributedObjectServant* _getImplementation();

	void _setImplementation(DistributedObjectServant* servant);

protected:
	DestroyMissionObjective(DummyConstructorParameter* param);

	virtual ~DestroyMissionObjective();

	friend class DestroyMissionObjectiveHelper;
};

} // namespace mission
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::mission;

namespace server {
namespace zone {
namespace objects {
namespace mission {

class DestroyMissionObjectiveImplementation : public MissionObjectiveImplementation {
protected:
	TemplateReference<SharedObjectTemplate*> lairTemplateToSpawn;

	ManagedReference<MissionSpawnActiveArea* > spawnActiveArea;

	ManagedReference<LairObject* > lairObject;

public:
	DestroyMissionObjectiveImplementation(MissionObject* mission);

	DestroyMissionObjectiveImplementation(DummyConstructorParameter* param);

	void finalize();

	void initializeTransientMembers();

	void activate();

	void abort();

	void complete();

	void spawnLair();

	void destroyObjectFromDatabase();

	int notifyObserverEvent(MissionObserver* observer, unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2);

	void setLairTemplateToSpawn(SharedObjectTemplate* sp);

	DestroyMissionObjective* _this;

	operator const DestroyMissionObjective*();

	DistributedObjectStub* _getStub();
protected:
	virtual ~DestroyMissionObjectiveImplementation();

	void _initializeImplementation();

	void _setStub(DistributedObjectStub* stub);

	void lock(bool doLock = true);

	void lock(ManagedObject* obj);

	void rlock(bool doLock = true);

	void wlock(bool doLock = true);

	void wlock(ManagedObject* obj);

	void unlock(bool doLock = true);

	void runlock(bool doLock = true);

	void _serializationHelperMethod();

	friend class DestroyMissionObjective;
};

class DestroyMissionObjectiveAdapter : public MissionObjectiveAdapter {
public:
	DestroyMissionObjectiveAdapter(DestroyMissionObjectiveImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void finalize();

	void initializeTransientMembers();

	void activate();

	void abort();

	void complete();

	void spawnLair();

	void destroyObjectFromDatabase();

	int notifyObserverEvent(MissionObserver* observer, unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2);

};

class DestroyMissionObjectiveHelper : public DistributedObjectClassHelper, public Singleton<DestroyMissionObjectiveHelper> {
	static DestroyMissionObjectiveHelper* staticInitializer;

public:
	DestroyMissionObjectiveHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<DestroyMissionObjectiveHelper>;
};

} // namespace mission
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::mission;

#endif /*DESTROYMISSIONOBJECTIVE_H_*/

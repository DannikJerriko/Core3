/*
 *	server/zone/managers/auction/AuctionManager.h generated by engine3 IDL compiler 0.60
 */

#ifndef AUCTIONMANAGER_H_
#define AUCTIONMANAGER_H_

#include "engine/core/Core.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

namespace server {
namespace zone {

class ZoneServer;

} // namespace zone
} // namespace server

using namespace server::zone;

namespace server {
namespace zone {
namespace managers {
namespace object {

class ObjectManager;

} // namespace object
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::object;

namespace server {
namespace zone {

class ZoneServer;

} // namespace zone
} // namespace server

using namespace server::zone;

namespace server {
namespace zone {
namespace objects {
namespace creature {

class CreatureObject;

} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature;

namespace server {
namespace zone {
namespace managers {
namespace auction {

class AuctionsMap;

} // namespace auction
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::auction;

namespace server {
namespace zone {
namespace objects {
namespace auction {

class AuctionItem;

} // namespace auction
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::auction;

namespace server {
namespace zone {
namespace objects {
namespace tangible {

class TangibleObject;

} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible;

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

#include "server/zone/packets/auction/AuctionQueryHeadersResponseMessage.h"

#include "engine/log/Logger.h"

#include "engine/core/ManagedService.h"

#include "system/util/VectorMap.h"

namespace server {
namespace zone {
namespace managers {
namespace auction {

class AuctionManager : public ManagedService {
public:
	static const int MAXBAZAARPRICE = 20000;

	static const int MAXSALES = 20;

	static const int SALESFEE = 20;

	static const int CHECKEVERY = 2;

	static const int MAXVENDORPRICE = 99999999;

	static const int ITEMSPERPAGE = 100;

	AuctionManager(ZoneServer* server);

	void initialize();

	void addSaleItem(CreatureObject* player, unsigned long long objectid, TangibleObject* vendor, const UnicodeString& description, int price, unsigned int duration, bool auction, bool premium);

	AuctionItem* createVendorItem(CreatureObject* player, SceneObject* objectToSell, TangibleObject* vendor, const UnicodeString& description, int price, unsigned int duration, bool auction, bool premium);

	int checkSaleItem(CreatureObject* player, SceneObject* object, TangibleObject* vendor, int price, bool premium);

	void getItemAttributes(CreatureObject* player, unsigned long long objectid);

	void getData(CreatureObject* player, int extent, unsigned long long vendorObjectID, int screen, unsigned int category, int count, int offset);

	void getAuctionData(CreatureObject* player, TangibleObject* vendor, String& search, int screen, unsigned int category, int count, int offset);

	int checkRetrieve(CreatureObject* player, unsigned long long objectIdToRetrieve, TangibleObject* vendor);

	void retrieveItem(CreatureObject* player, unsigned long long objectid, unsigned long long vendorID);

	void buyItem(CreatureObject* player, unsigned long long objectid, int price1, int price2);

	void doAuctionBid(CreatureObject* player, AuctionItem* item, int price1, int price2);

	void doInstantBuy(CreatureObject* player, AuctionItem* item, int price1, int price2);

	int checkBidAuction(CreatureObject* player, AuctionItem* item, int price1, int price2);

	void cancelItem(CreatureObject* player, unsigned long long objectID);

	AuctionQueryHeadersResponseMessage* fillAuctionQueryHeadersResponseMessage(CreatureObject* player, TangibleObject* vendor, SortedVector<ManagedReference<AuctionItem* > >* items, int screen, unsigned int category, int count, int offset);

	AuctionsMap* getAuctionMap();

	void checkVendorItems();

	void checkAuctions();

	DistributedObjectServant* _getImplementation();

	void _setImplementation(DistributedObjectServant* servant);

protected:
	AuctionManager(DummyConstructorParameter* param);

	virtual ~AuctionManager();

	friend class AuctionManagerHelper;
};

} // namespace auction
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::auction;

namespace server {
namespace zone {
namespace managers {
namespace auction {

class AuctionManagerImplementation : public ManagedServiceImplementation, public Logger {
protected:
	ManagedReference<AuctionsMap* > auctionMap;

	ManagedReference<ZoneServer* > zoneServer;

public:
	static const int MAXBAZAARPRICE = 20000;

	static const int MAXSALES = 20;

	static const int SALESFEE = 20;

	static const int CHECKEVERY = 2;

	static const int MAXVENDORPRICE = 99999999;

	static const int ITEMSPERPAGE = 100;

	AuctionManagerImplementation(ZoneServer* server);

	AuctionManagerImplementation(DummyConstructorParameter* param);

	void initialize();

	void addSaleItem(CreatureObject* player, unsigned long long objectid, TangibleObject* vendor, const UnicodeString& description, int price, unsigned int duration, bool auction, bool premium);

private:
	String getVendorUID(SceneObject* vendor);

public:
	AuctionItem* createVendorItem(CreatureObject* player, SceneObject* objectToSell, TangibleObject* vendor, const UnicodeString& description, int price, unsigned int duration, bool auction, bool premium);

	int checkSaleItem(CreatureObject* player, SceneObject* object, TangibleObject* vendor, int price, bool premium);

	void getItemAttributes(CreatureObject* player, unsigned long long objectid);

	void getData(CreatureObject* player, int extent, unsigned long long vendorObjectID, int screen, unsigned int category, int count, int offset);

	void getAuctionData(CreatureObject* player, TangibleObject* vendor, String& search, int screen, unsigned int category, int count, int offset);

private:
	void refundAuction(AuctionItem* item);

public:
	int checkRetrieve(CreatureObject* player, unsigned long long objectIdToRetrieve, TangibleObject* vendor);

	void retrieveItem(CreatureObject* player, unsigned long long objectid, unsigned long long vendorID);

	void buyItem(CreatureObject* player, unsigned long long objectid, int price1, int price2);

	void doAuctionBid(CreatureObject* player, AuctionItem* item, int price1, int price2);

	void doInstantBuy(CreatureObject* player, AuctionItem* item, int price1, int price2);

	int checkBidAuction(CreatureObject* player, AuctionItem* item, int price1, int price2);

	void cancelItem(CreatureObject* player, unsigned long long objectID);

	AuctionQueryHeadersResponseMessage* fillAuctionQueryHeadersResponseMessage(CreatureObject* player, TangibleObject* vendor, SortedVector<ManagedReference<AuctionItem* > >* items, int screen, unsigned int category, int count, int offset);

	AuctionsMap* getAuctionMap();

	void checkVendorItems();

	void checkAuctions();

	WeakReference<AuctionManager*> _this;

	operator const AuctionManager*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~AuctionManagerImplementation();

	void finalize();

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
	bool readObjectMember(ObjectInputStream* stream, const String& name);
	int writeObjectMembers(ObjectOutputStream* stream);

	friend class AuctionManager;
};

class AuctionManagerAdapter : public ManagedServiceAdapter {
public:
	AuctionManagerAdapter(AuctionManager* impl);

	void invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void initialize();

	void getItemAttributes(CreatureObject* player, unsigned long long objectid);

	void getData(CreatureObject* player, int extent, unsigned long long vendorObjectID, int screen, unsigned int category, int count, int offset);

	void retrieveItem(CreatureObject* player, unsigned long long objectid, unsigned long long vendorID);

	void buyItem(CreatureObject* player, unsigned long long objectid, int price1, int price2);

	void doAuctionBid(CreatureObject* player, AuctionItem* item, int price1, int price2);

	void doInstantBuy(CreatureObject* player, AuctionItem* item, int price1, int price2);

	int checkBidAuction(CreatureObject* player, AuctionItem* item, int price1, int price2);

	void cancelItem(CreatureObject* player, unsigned long long objectID);

	AuctionsMap* getAuctionMap();

	void checkVendorItems();

	void checkAuctions();

};

class AuctionManagerHelper : public DistributedObjectClassHelper, public Singleton<AuctionManagerHelper> {
	static AuctionManagerHelper* staticInitializer;

public:
	AuctionManagerHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<AuctionManagerHelper>;
};

} // namespace auction
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::auction;

#endif /*AUCTIONMANAGER_H_*/

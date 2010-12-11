/*
 *	server/zone/objects/area/SpawnArea.cpp generated by engine3 IDL compiler 0.60
 */

#include "SpawnArea.h"

#include "server/zone/objects/creature/aigroup/AiGroup.h"

#include "server/zone/objects/area/SpawnObserver.h"

/*
 *	SpawnAreaStub
 */

SpawnArea::SpawnArea() : ActiveArea(DummyConstructorParameter::instance()) {
	SpawnAreaImplementation* _implementation = new SpawnAreaImplementation();
	_impl = _implementation;
	_impl->_setStub(this);
}

SpawnArea::SpawnArea(DummyConstructorParameter* param) : ActiveArea(param) {
}

SpawnArea::~SpawnArea() {
}


void SpawnArea::registerObservers() {
	SpawnAreaImplementation* _implementation = (SpawnAreaImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);

		method.executeWithVoidReturn();
	} else
		_implementation->registerObservers();
}

int SpawnArea::notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2) {
	SpawnAreaImplementation* _implementation = (SpawnAreaImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addUnsignedIntParameter(eventType);
		method.addObjectParameter(observable);
		method.addObjectParameter(arg1);
		method.addSignedLongParameter(arg2);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->notifyObserverEvent(eventType, observable, arg1, arg2);
}

void SpawnArea::addTemplate(unsigned int tempCRC) {
	SpawnAreaImplementation* _implementation = (SpawnAreaImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);
		method.addUnsignedIntParameter(tempCRC);

		method.executeWithVoidReturn();
	} else
		_implementation->addTemplate(tempCRC);
}

void SpawnArea::setTier(int n) {
	SpawnAreaImplementation* _implementation = (SpawnAreaImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);
		method.addSignedIntParameter(n);

		method.executeWithVoidReturn();
	} else
		_implementation->setTier(n);
}

void SpawnArea::setSpawnConstant(int n) {
	SpawnAreaImplementation* _implementation = (SpawnAreaImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);
		method.addSignedIntParameter(n);

		method.executeWithVoidReturn();
	} else
		_implementation->setSpawnConstant(n);
}

bool SpawnArea::isStaticArea() {
	SpawnAreaImplementation* _implementation = (SpawnAreaImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 11);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isStaticArea();
}

bool SpawnArea::isDynamicArea() {
	SpawnAreaImplementation* _implementation = (SpawnAreaImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 12);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isDynamicArea();
}

DistributedObjectServant* SpawnArea::_getImplementation() {

	_updated = true;
	return _impl;
}

void SpawnArea::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;}

/*
 *	SpawnAreaImplementation
 */

SpawnAreaImplementation::SpawnAreaImplementation(DummyConstructorParameter* param) : ActiveAreaImplementation(param) {
	_initializeImplementation();
}


SpawnAreaImplementation::~SpawnAreaImplementation() {
}


void SpawnAreaImplementation::finalize() {
}

void SpawnAreaImplementation::_initializeImplementation() {
	_setClassHelper(SpawnAreaHelper::instance());

	_serializationHelperMethod();
}

void SpawnAreaImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (SpawnArea*) stub;
	ActiveAreaImplementation::_setStub(stub);
}

DistributedObjectStub* SpawnAreaImplementation::_getStub() {
	return _this;
}

SpawnAreaImplementation::operator const SpawnArea*() {
	return _this;
}

void SpawnAreaImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void SpawnAreaImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void SpawnAreaImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void SpawnAreaImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void SpawnAreaImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void SpawnAreaImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void SpawnAreaImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void SpawnAreaImplementation::_serializationHelperMethod() {
	ActiveAreaImplementation::_serializationHelperMethod();

	_setClassName("SpawnArea");

	addSerializableVariable("spawnCreatureTemplates", &spawnCreatureTemplates);
	addSerializableVariable("observers", &observers);
	addSerializableVariable("tier", &tier);
	addSerializableVariable("spawnConstant", &spawnConstant);
}

SpawnAreaImplementation::SpawnAreaImplementation() {
	_initializeImplementation();
	// server/zone/objects/area/SpawnArea.idl(65):  		spawnConstant = 0;
	spawnConstant = 0;
	// server/zone/objects/area/SpawnArea.idl(66):  		Logger.setLoggingName("SpawnArea");
	Logger::setLoggingName("SpawnArea");
}

void SpawnAreaImplementation::registerObservers() {
}

int SpawnAreaImplementation::notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2) {
	// server/zone/objects/area/SpawnArea.idl(73):  		return 1;
	return 1;
}

void SpawnAreaImplementation::addTemplate(unsigned int tempCRC) {
	// server/zone/objects/area/SpawnArea.idl(77):  		spawnCreatureTemplates.add(tempCRC);
	(&spawnCreatureTemplates)->add(tempCRC);
}

void SpawnAreaImplementation::setTier(int n) {
	// server/zone/objects/area/SpawnArea.idl(81):  		tier = n;
	tier = n;
}

void SpawnAreaImplementation::setSpawnConstant(int n) {
	// server/zone/objects/area/SpawnArea.idl(85):  		spawnConstant = n;
	spawnConstant = n;
}

bool SpawnAreaImplementation::isStaticArea() {
	// server/zone/objects/area/SpawnArea.idl(89):  		return false;
	return false;
}

bool SpawnAreaImplementation::isDynamicArea() {
	// server/zone/objects/area/SpawnArea.idl(93):  		return false;
	return false;
}

/*
 *	SpawnAreaAdapter
 */

SpawnAreaAdapter::SpawnAreaAdapter(SpawnAreaImplementation* obj) : ActiveAreaAdapter(obj) {
}

Packet* SpawnAreaAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		registerObservers();
		break;
	case 7:
		resp->insertSignedInt(notifyObserverEvent(inv->getUnsignedIntParameter(), (Observable*) inv->getObjectParameter(), (ManagedObject*) inv->getObjectParameter(), inv->getSignedLongParameter()));
		break;
	case 8:
		addTemplate(inv->getUnsignedIntParameter());
		break;
	case 9:
		setTier(inv->getSignedIntParameter());
		break;
	case 10:
		setSpawnConstant(inv->getSignedIntParameter());
		break;
	case 11:
		resp->insertBoolean(isStaticArea());
		break;
	case 12:
		resp->insertBoolean(isDynamicArea());
		break;
	default:
		return NULL;
	}

	return resp;
}

void SpawnAreaAdapter::registerObservers() {
	((SpawnAreaImplementation*) impl)->registerObservers();
}

int SpawnAreaAdapter::notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2) {
	return ((SpawnAreaImplementation*) impl)->notifyObserverEvent(eventType, observable, arg1, arg2);
}

void SpawnAreaAdapter::addTemplate(unsigned int tempCRC) {
	((SpawnAreaImplementation*) impl)->addTemplate(tempCRC);
}

void SpawnAreaAdapter::setTier(int n) {
	((SpawnAreaImplementation*) impl)->setTier(n);
}

void SpawnAreaAdapter::setSpawnConstant(int n) {
	((SpawnAreaImplementation*) impl)->setSpawnConstant(n);
}

bool SpawnAreaAdapter::isStaticArea() {
	return ((SpawnAreaImplementation*) impl)->isStaticArea();
}

bool SpawnAreaAdapter::isDynamicArea() {
	return ((SpawnAreaImplementation*) impl)->isDynamicArea();
}

/*
 *	SpawnAreaHelper
 */

SpawnAreaHelper* SpawnAreaHelper::staticInitializer = SpawnAreaHelper::instance();

SpawnAreaHelper::SpawnAreaHelper() {
	className = "SpawnArea";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void SpawnAreaHelper::finalizeHelper() {
	SpawnAreaHelper::finalize();
}

DistributedObject* SpawnAreaHelper::instantiateObject() {
	return new SpawnArea(DummyConstructorParameter::instance());
}

DistributedObjectServant* SpawnAreaHelper::instantiateServant() {
	return new SpawnAreaImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* SpawnAreaHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new SpawnAreaAdapter((SpawnAreaImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}


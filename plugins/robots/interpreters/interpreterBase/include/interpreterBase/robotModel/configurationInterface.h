#pragma once

#include <QtCore/QObject>
#include <QtCore/QHash>

#include "interpreterBase/robotModel/portInfo.h"
#include "interpreterBase/robotModel/robotParts/pluggableDevice.h"

#include "interpreterBase/interpreterBaseDeclSpec.h"

namespace interpreterBase {
namespace robotModel {

class ROBOTS_INTERPRETER_BASE_EXPORT ConfigurationInterface : public QObject
{
	Q_OBJECT

public:
	enum PortDirection {
		defaultDirection
		, input
		, output
	};

	virtual ~ConfigurationInterface() {}

	/// Adds device to robot configuration and initializes process of its configuring on a port device is bound to.
	/// Device configuration can be deferred until unlockConfiguring is called.
	/// @param device - device to be added to configuration. Transfers ownership.
	virtual void configureDevice(robotParts::PluggableDevice * const device) = 0;

	virtual void lockConfiguring() = 0;

	/// Guaranteed to emit allDevicesConfigured() if there were requests for device configuration, if all devices
	/// respond about their configuration status.
	virtual void unlockConfiguring() = 0;

	/// Returns all configured devices with given port direction. Allows to enumerate configured devices.
	virtual QList<robotParts::PluggableDevice *> pluggableDevices(
			PortDirection direction = defaultDirection) const = 0;

	/// Returns configured device on a given port or nullptr if no device is configured there.
	virtual robotParts::PluggableDevice *pluggableDevice(
			PortInfo const &port
			, PortDirection direction = defaultDirection) const = 0;

	/// \todo Implement some convenience methods that cast generic PluggableDevice to desired sensor/motor type.

	virtual void clearDevice(PortInfo const &port) = 0;

	/// Force configuration to emit allDevicesConfigured() when all devices are actually configured, even if no
	/// configuration requests are pending. In later case it will emit immediately.
	virtual void configure() = 0;

signals:
	/// Emitted when all devices are configured (or failed to configure) and model is ready to work.
	void allDevicesConfigured();
};

}
}

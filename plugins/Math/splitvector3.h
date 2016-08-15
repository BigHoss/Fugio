#ifndef SPLITVECTOR3_H
#define SPLITVECTOR3_H

#include <QObject>

#include <fugio/node_interface.h>
#include <fugio/node_control_interface.h>
#include <fugio/pin_interface.h>
#include <fugio/pin_control_interface.h>

#include <fugio/core/variant_interface.h>

#include <fugio/core/uuid.h>

#include <fugio/nodecontrolbase.h>

class SplitVector3Node : public fugio::NodeControlBase
{
	Q_OBJECT

public:
	Q_INVOKABLE explicit SplitVector3Node( QSharedPointer<fugio::NodeInterface> pNode );

	virtual ~SplitVector3Node( void ) {}

	//-------------------------------------------------------------------------
	// NodeControlInterface

	virtual void inputsUpdated( qint64 pTimeStamp );

private:
	QSharedPointer<fugio::PinInterface>			 mPinInput;

	QSharedPointer<fugio::PinInterface>			 mPinOutX;
	fugio::VariantInterface						*mOutX;

	QSharedPointer<fugio::PinInterface>			 mPinOutY;
	fugio::VariantInterface						*mOutY;

	QSharedPointer<fugio::PinInterface>			 mPinOutZ;
	fugio::VariantInterface						*mOutZ;
};


#endif // SPLITVECTOR3_H

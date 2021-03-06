#include "painterpin.h"

PainterPin::PainterPin( QSharedPointer<fugio::PinInterface> pPin )
	: PinControlBase( pPin ), mSource( nullptr )
{

}

void PainterPin::setSource( PainterInterface *pSource )
{
	mSource = pSource;
}

void PainterPin::render(QPainter &pPainter)
{
	if( mSource )
	{
		mSource->render( pPainter );
	}
}

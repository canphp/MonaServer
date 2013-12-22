/*
Copyright 2014 Mona
mathieu.poux[a]gmail.com
jammetthomas[a]gmail.com

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License received along this program for more
details (or else see http://www.gnu.org/licenses/).

This file is a part of Mona.
*/

#pragma once

#include "Mona/Mona.h"
#include "Mona/Decoding.h"
#include "Mona/HTTP/HTTPPacket.h"

namespace Mona {

class HTTPPacketBuilding : public Decoding, public HTTPPacket, virtual Object {
public:
	HTTPPacketBuilding(Invoker& invoker, const UInt8* data, UInt32 size, std::shared_ptr<PoolBuffer>& ppBuffer) : _ppBuffer(ppBuffer),HTTPPacket(*ppBuffer),Decoding("HTTPPacketBuilding", invoker, data, size) {}

private:
	const UInt8* decodeRaw(Exception& ex, PoolBuffer& pBuffer, UInt32 times,const UInt8* data,UInt32& size) { return build(pBuffer,data,size); }

	const std::shared_ptr<PoolBuffer>	 _ppBuffer;
};


} // namespace Mona
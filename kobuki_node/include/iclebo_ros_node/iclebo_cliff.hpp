#ifndef __ICLEBO_CLIFF_DATA_HPP__
#define __ICLEBO_CLIFF_DATA_HPP__

#include <ecl/containers.hpp>
#include <packet_handler/payload_base.hpp>
#include <iclebo_comms/iCleboHeader.h>
#include <iclebo_comms/iCleboCliff.h>

namespace iclebo {

class iCleboCliffData : public packet_handler::payloadBase
{
public:
	// container
	iclebo_comms::iCleboCliff data;
	
	iCleboCliffData() 
	{
		data.bottom.resize(3);
	}
	
	// methods
	bool serialise( ecl::PushAndPop<unsigned char> & byteStream )
	{
		if(!(byteStream.size()>0)) { 
			ROS_WARN_STREAM("iclebo_ros_node: iclebo_cliff: serialise failed. empty byte stream."); 
			return false; 
		}

		buildBytes( data.header_id, 		byteStream );
		buildBytes( data.bottom[0], byteStream );
		buildBytes( data.bottom[1], byteStream );
		buildBytes( data.bottom[2], byteStream );
		return true;
	}

	bool deserialise( ecl::PushAndPop<unsigned char> & byteStream )
	{
		if(!(byteStream.size()>0)) { 
			ROS_WARN_STREAM("iclebo_ros_node: iclebo_cliff: deserialise failed. empty byte stream."); 
			return false; 
		}

		buildVariable( data.header_id, 		byteStream );
		buildVariable( data.bottom[0], byteStream );
		buildVariable( data.bottom[1], byteStream );
		buildVariable( data.bottom[2], byteStream );

		//showMe();
		return constrain();
	}

	bool constrain()
	{
		return true;
	}

	void showMe()
	{
		//printf("--[%02x || %03d | %03d | %03d]\n", data.bump, bottom[2], bottom[1], bottom[0] );
	}
};

} // namespace iclebo

#endif /* __ICLEBO_IR_DATA_HPP__ */

#include "ros/ros.h" 
#include "std_msgs/Int32.h" 
#include "geomerty_msgs/Point.h"
#include "visualization_msgs/Marker.h"

class SubscribeAndPublish {
public:
	SubscribeAndPublish() {
		publisher = n.advertise<visualization_msgs::Marker>("/output", 10);
		subscriber = n.subscribe("/input", 10, &SubscribeAndPublish::callback, this);
		counter = 0;
	}

	void callback(const geomerty_msgs::Point& point) {
		visualization_msgs::Marker marker;
		marker.header.frame_id = "points";
		marker.ns = "namespace";
		marker.id = counter;
		marker.type = visualization_msgs::Marker::POINTS;
		marker.action = visualization_msgs::Marker::ADD;
		marker.point.push_back(point);
		publisher.publish(marker);
		counter++;
	}

private:
	int counter;
	ros::NodeHandle n;
	ros::Publisher publisher;
	ros::Subscriber subscriber;
};

int main(int argc, char **argv) {
	ros::init(argc, argv, "subscribe_and_publish");
	SubscribeAndPublish SAPObject;
	ros::spin();
	return 0;
}
#include <ros/ros.h>
#include <my_package_msgs/Counter.h>

class MyPackageNode {
public:
	MyPackageNode(const ros::NodeHandle &n, const ros::NodeHandle &np):
		n_(n),
		np_(np),
		publisher_(n_.advertise<my_package_msgs::Counter>("counter", 10, false)),
                counter_(0),
                publisher_timer_(n_.createTimer(ros::Duration(1.0), &MyPackageNode::publisherTimerCallback, this, false, true))
	{
		ROS_INFO("MyPackageNode object created");
	}
private:
	void publisherTimerCallback( const ros::TimerEvent &e)
	{
		my_package_msgs::Counter counter_msg;
		counter_msg.data = counter_;
		publisher_.publish(counter_msg);
		counter_++;
	}
	ros::NodeHandle n_;
	ros::NodeHandle np_;
	ros::Publisher publisher_;
	int counter_;
	ros::Timer publisher_timer_;
};

int main(int argc, char *argv[])
{
	ros::init(argc, argv, "my_package_node");
	MyPackageNode mpn(ros::NodeHandle(), ros::NodeHandle("~"));
	ros::spin();
	return 0;
}

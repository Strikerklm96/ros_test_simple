//compile with: g++ listener.cpp -o listener -I/opt/ros/hydro/include -L/opt/ros/hydro/lib -Wl,-rpath,/opt/ros/hydro/lib -lroscpp -lrosconsole -lrostime -lroscpp_serialization

#include "ros/ros.h"
#include "std_msgs/String.h"

using namespace std;

void chatterCallback(const std_msgs::String::ConstPtr& msg)//this function will be called when new data arrives
{
    cout << "\nListener heard: [" << msg->data << "]";//why doesn't this work?
    //ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{
    std::string myNodeName = "listener";
    ros::init(argc, argv, myNodeName);

    ros::NodeHandle nodeHandle;
    std::string topicName = "chatter";//this is the topic to subscribe to
    int bufferSize = 1000;//size of buffer, if messages accumulate, start throwing away after this many pile up
    ros::Subscriber sub = nodeHandle.subscribe(topicName, bufferSize, chatterCallback);

    ros::spin();//enters a loop, calling message callbacks as fast as possible. Don't worry though, if there's nothing for it to do it won't use much CPU

    return 0;
}

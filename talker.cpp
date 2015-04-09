//compile with: g++ talker.cpp -o talker -I/opt/ros/hydro/include -L/opt/ros/hydro/lib -Wl,-rpath,/opt/ros/hydro/lib -lroscpp -lrosconsole -lrostime -lroscpp_serialization

#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

using namespace std;

int main(int argc, char **argv)
{
    string myNodeName = "talker_test1";
    ros::init(argc, argv, myNodeName);


    ros::NodeHandle nodeHandle;
    string topicName = "chatter";//this is the name the listener will look for
    int bufferSize = 1000;//size of buffer, if messages accumulate, start throwing away after this many pile up
    ros::Publisher chatter_pub = nodeHandle.advertise<std_msgs::String>(topicName, bufferSize);


    int numPerSecond = 10;
    ros::Rate loop_rate(numPerSecond);

    int count = 0;
    while (ros::ok())
    {
        std_msgs::String stdMsg;
        stringstream sStream;
        sStream << "hello world " << count;
        stdMsg.data = sStream.str();

        chatter_pub.publish(stdMsg);
        cout << "\nPublished New Data!";

        ros::spinOnce();
        loop_rate.sleep();
        ++count;
    }

    return 0;
}

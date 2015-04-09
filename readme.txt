Install Ros



Start Ros: roscore
	To confirm that it is working, try running roscore in another terminal, if it says it can't start, the first one worked! Leave the terminal that is running ros open.



Build The Talker Program:
	g++ talker.cpp -o talker -I/opt/ros/hydro/include -L/opt/ros/hydro/lib -Wl,-rpath,/opt/ros/hydro/lib -lroscpp -lrosconsole -lrostime -lroscpp_serialization



Build The Listener Program:
	g++ listener.cpp -o listener -I/opt/ros/hydro/include -L/opt/ros/hydro/lib -Wl,-rpath,/opt/ros/hydro/lib -lroscpp -lrosconsole -lrostime -lroscpp_serialization


Run The Programs
	./listener
	./talker


Other:
	Type rosnode list to list the current nodes up, if you have the talker running, you should see a node called talker_test1
	If you have the listener running, you should see a node called listener
	Original Files: http://wiki.ros.org/ROS/Tutorials/WritingPublisherSubscriber%28c%2B%2B%29

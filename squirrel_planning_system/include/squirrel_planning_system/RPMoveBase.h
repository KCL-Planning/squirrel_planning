#include <ros/ros.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <actionlib/client/simple_action_client.h>
#include "squirrel_planning_dispatch_msgs/ActionDispatch.h"
#include "squirrel_planning_dispatch_msgs/ActionFeedback.h"
#include "move_base_msgs/MoveBaseAction.h"
#include "mongodb_store/message_store.h"
#include "geometry_msgs/PoseStamped.h"


#ifndef KCL_movebase
#define KCL_movebase

/**
 * This file defines the RPMoveBase class.
 * RPMoveBase is used to connect ROSPlan to the MoveBase library.
 * PDDL "goto_waypoint" actions become "move_base_msgs::MoveBase" actions.
 * Waypoint goals are fetched by name from the SceneDB (implemented by mongoDB).
 */
namespace KCL_rosplan {

	class RPMoveBase
	{

	private:

		mongodb_store::MessageStoreProxy message_store;
		actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> action_client;
		ros::Publisher action_feedback_pub;

	public:

		/* constructor */
		RPMoveBase(ros::NodeHandle &nh, std::string &actionserver);

		/* listen to and process action_dispatch topic */
		void dispatchCallback(const squirrel_planning_dispatch_msgs::ActionDispatch::ConstPtr& msg);
	};
}
#endif

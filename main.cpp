
#include <ros/ros.h>
#include <ros/console.h>

#include <sensor_msgs/Image.h>

#include "mainwindow.h"
#include <QApplication>



void generic_callback(const sensor_msgs::Image& msg_in)
{
    // this is a generic callback, called from the generic subscriber.
    // this and the other examples below exist to help expedite
    // you writing this program.
}

/**
 * Node name: pnr_display
 *
 * Topics published:
 *     <none>
 *
 * Topics subscribed:
 *     ?????
 */
int main(int argc, char *argv[])
{
    ros::init(argc, argv, "pnr_display");
    ros::NodeHandle nh("pnr_display");

    ros::Publisher generic_publisher
        = nh.advertise<___topic_object___>("___topic_name___", 1);

    ros::Subscriber generic_subscriber
        = nh.subscribe("___topic_name___", 1, generic_callback)


    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    // start the app
    int err = a.exec();
    if (err) {
      ROS_ERROR("Qt did not start properly. Error: %d", err);
      return err;
    }

    while (ros::ok())
    {
        // main program loop (i.e. listen for callbacks and events)


    }
}

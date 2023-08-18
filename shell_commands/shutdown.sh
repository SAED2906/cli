#!/bin/bash

# Display a message and prompt the user for action
echo "Do you want to shutdown your computer? (y/n)"
read choice

# Check the user's choice
if [ "$choice" == "y" ] || [ "$choice" == "Y" ]; then
    # Perform the shutdown
    sudo shutdown -h now
else
    if [ "$choice" == "n"] || [ "$choice" == "N" ]; then
        echo "Shutdown cancelled."
    else
        echo "Unkown input."
        ./shutdown.sh
    fi
fi


#!/bin/bash

# Delay for a short time to allow authentication to take effect
sudo sleep 0.1

# Lock the screen using i3lock (replace with appropriate locking command)
i3lock

# Wait for a few seconds
sleep 3

# Trigger system hibernation
echo disk > /sys/power/state


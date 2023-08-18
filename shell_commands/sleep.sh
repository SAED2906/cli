#!/bin/bash

# Delay for a short time to allow authentication to take effect
sudo sleep 0.1

# Lock the screen using i3lock
i3lock

# Wait for a few seconds
sleep 3

# Set the system to deep sleep mode
echo "deep" | sudo tee /sys/class/sleep/sleep_state

# Trigger system suspend to RAM
echo "mem" | sudo tee /sys/power/state


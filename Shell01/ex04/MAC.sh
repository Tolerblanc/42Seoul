#!/bin/bash
ifconfig -a ether | grep ether | awk '{print $2}'

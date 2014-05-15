#!/usr/bin/python

import sys, subprocess

if len(sys.argv) < 2:
	print "Please specify an output file"

fp = open(sys.argv[1], 'w')
while True:
	subprocess.call('MOZ_HOST_BIN=/home/tag/Work/firefox/obj-x86_64-unknown-linux-gnu/dist/bin TEST_PATH=testCheck make mochitest-robotium', stdout=fp, stderr=fp, shell=True)
	subprocess.call('MOZ_HOST_BIN=/home/tag/Work/firefox/obj-x86_64-unknown-linux-gnu/dist/bin TEST_PATH=testCheck2 make mochitest-robotium', stdout=fp, stderr=fp, shell=True)
	subprocess.call('MOZ_HOST_BIN=/home/tag/Work/firefox/obj-x86_64-unknown-linux-gnu/dist/bin TEST_PATH=testCheck3 make mochitest-robotium', stdout=fp, stderr=fp, shell=True)
fp.close()


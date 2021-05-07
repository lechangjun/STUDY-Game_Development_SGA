#!/usr/bin/env python

#python system 셋팅
import argparse
import os
import subprocess
import sys
import uuid
from tempfile import NamedTemporaryFile

import yaml


os.system('cd~')
os.system('ls -ail')


stream = os.popen('ls -la')
output = stream.readlines()



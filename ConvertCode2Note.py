# -*- coding: utf-8 -*-

import os
import argparse

parser = argparse.ArgumentParser()
parser.add_argument('filename', help='filename to convert')
args = parser.parse_args()
filename = args.filename
if filename.endswith('.'):
    filename += 'cc'

if not os.path.exists(filename):
    print('no such file: {}'.format(filename))
    exit(-1)

with open(filename) as fr:
    text = fr.readlines()

pos = 1
for line in text[1:]:
    if not line.strip() or line.startswith('//'):
        pos += 1
    else:
        break

title = text[0].replace('//', '###')
comment = ''.join([line.replace('// ', '').replace('题目', '`题目`').replace('解法', '`解法`')
           for line in text[1:pos]])

start = pos
for line in text[pos:]:
    if not line.startswith('class Solution'):
        pos += 1
    else:
        start = pos
        break
for line in text[pos:]:
    if not line.startswith('};'):
        pos += 1
    else:
        break
code = ''.join(['```c++\n'] + text[start:pos+1] + ['```'])

with open('note.md', 'w') as fw:
    fw.write(title)
    fw.write(comment)
    fw.write(code)





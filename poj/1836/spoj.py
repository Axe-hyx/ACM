# -*- coding:utf-8 -*-

import sys
import getopt
import commands


def main(argv):
    pid = ""

    try:
        # 这里的 h 就表示该选项无参数，i:表示 i 选项后需要有参数
        opts, args = getopt.getopt(argv, "hf:", ["pid="])
    except getopt.GetoptError:
        print 'Error: spoj.py -f <pid>'
        print '   or: spoj.py --pid=<problemid>'
        sys.exit(2)

    for opt, arg in opts:
        if opt == "-h":
            print 'Error: spoj.py -f <pid>'
            print '   or: spoj.py --pid=<problemid>'

            sys.exit()
        elif opt in ("-p", "--infile", "-f"):
            pid = arg

    print 'Problem : ', pid
    a, b = commands.getstatusoutput('poj -u weifu -p woof0418 -n ' + pid + ' main.cpp -l 4')
    print b


if __name__ == "__main__":
    main(sys.argv[1:])

#!/usr/local/bin/python3
import sys
import math
from optparse import OptionParser

def isprime(n) :
    if n<2 : return False
    for i in range(2, int(math.sqrt(n))+1) :
        if (n%i == 0) : return False
    return True

def prime(n) :
    for i in range(2, n+1) :
        print("Try:", i)
        if isprime(i) : yield i

def main() :
#    for i in range(1, int(sys.argv[1])) :
#        if isprime(i) : print(i)

    parser = OptionParser()
    parser.add_option("-s", "--start", dest="start", type="int", metavar="NUM", help="starting number for search")
    parser.add_option("-e", "--end", dest="end", type="int", metavar="NUM", help="ending number for search")
    parser.add_option("-n", "--numprimes", dest="numprimes", type="int", metavar="NUM", help="number of primes")

    parser.add_option("-c", "--count",
                      dest="count", default=False, action="store_true"
                      help="count the number of primes")

    (options, args) = parser.parse_args()
    print("s: ", options.start)
    print("e: ", options.end)
    print("n: ", options.numprimes)

    if options.end!=None or options.numprimes!=None) :
        print("ERROR")
        parser.print_help()
        exit(1)
    else :
        p = 0
        i = options.start
        while( (options.numprimes == 0

main()

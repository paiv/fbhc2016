#!/usr/bin/env python
from __future__ import print_function
import random


def generate(nights, stars):
    print(nights)
    for i in range(nights):
        print(stars)
        for k in range(stars):
            print(' '.join([str(x) for x in [random.randint(-10000,10000), random.randint(-10000,10000)]]))


if __name__ == '__main__':
    generate(50, 2000)
    # generate(10, 1000)

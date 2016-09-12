#!/usr/bin/python

import os, glob, re
from fabricate import *
import inspect

base_dir = os.path.dirname(os.path.abspath(inspect.getfile(inspect.currentframe()))) # script directory

def script_relative(path):
    return os.path.abspath(os.path.join(base_dir, path))

setup(dirs=[base_dir, script_relative('../FastLED')])

classes = [re.sub(r'\.cpp', '', name) for name in glob.glob(script_relative('*.cpp'))] + [script_relative('../FastLED/hsv2rgb')]
test_sources = [re.sub(r'\.cpp', '', name) for name in glob.glob(script_relative('test/*.cpp'))]
cflags = '-DPLATFORM_DUMMY=1 -I/opt/X11/include -O0 -g3 -Wall -Wno-c++11-extensions'.split() + [
        '-I' + script_relative(inc)
        for inc in ['.', '../FastLED', '../CImg', '../pattern/Catch/single_include']
    ]
ldflags = '-L/opt/X11/lib -lX11'.split()
build_dir = script_relative('build')

def preview():
    build_and_run('mains/preview', 'preview')

def test():
    build_and_run('mains/test', 'test', extra_sources=test_sources)

def build_and_run(main, name, extra_sources=[]):
    build(main, name, extra_sources)
    shell(oname(build_dir, name), silent=False)

def build(main, name, extra_sources=[]):
    sources = classes + [script_relative(main)] + extra_sources
    objects = compile(sources)
    link(name, objects)

def oname(build_dir, filename):
    return os.path.join(build_dir, os.path.basename(filename))

def compile(sources):
    objects = [oname(build_dir, s+'.o') for s in sources]
    for source, object in zip(sources, objects):
        run('c++', '-c', source+'.cpp', '-o', object, cflags)
    return objects

def link(target, objects):
    run('c++', objects, '-o', oname(build_dir, target), ldflags)

def check():
    return int(outofdate(build))

def clean():
    autoclean()

# def rebuild():
#     clean()
#     build()

main()
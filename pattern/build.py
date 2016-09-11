import os, glob, re
from fabricate import *

setup(dirs=['.', '../FastLED'])

classes = [re.sub(r'\.cpp', '', name) for name in glob.glob('*.cpp')] + ['../FastLED/hsv2rgb']
cflags = '-DPLATFORM_DUMMY=1 -I. -I/opt/X11/include -I../FastLED -I../CImg -I../pattern/Catch/single_include -O0 -g3 -Wall'.split()
ldflags = '-L/opt/X11/lib -lX11'.split()
build_dir = 'build'

def preview():
    build_and_run('mains/preview', 'preview')

def test():
    build_and_run('mains/test', 'test')

def build_and_run(main, name):
    build(main, name)
    shell(oname(build_dir, name), silent=False)

def build(main, name):
    sources = classes + [main]
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
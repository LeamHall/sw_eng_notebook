from setuptools import setup, Extension

module = Extension(
    'spam', 
    sources=['spammodule.c']
)

setup(
    name='Spam',
    version='0.0.1',
    description='Test of writing C extension for Python',
    ext_modules=[module],
)

    

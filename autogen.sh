#!/bin/sh

aclocal
automake
autoreconf -v --install || exit 1

./configure "$@"

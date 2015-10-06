#!/usr/bin/perl -wT

use strict;

for(my $i = 0; $i<20; $i++){
    mkdir sprintf "c++%02d", $i;
}

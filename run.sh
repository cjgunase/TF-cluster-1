#!/bin/bash

/usr/bin/time -v ./tf-cluster -1 1.5 -2 1.2 -3 0.8 -c spearman -e correlation-matrix/example/base-clean/rma_salt.txt -t correlation-matrix/example/base-clean/TFs.txt -k 100

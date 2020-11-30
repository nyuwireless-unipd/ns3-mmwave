#!/bin/bash
# This script is necessary to correclty build the documentation and 
# update the repository that contains the doc's website.

git clone https://github.com/nyuwireless-unipd/ns3-mmwave-doc.git docs
doxygen docs/doxygen.conf
cd docs
git add .
git commit -m "Update documentation"
git push

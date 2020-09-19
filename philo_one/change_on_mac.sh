#!/bin/sh

#colors
GREEN='\033[1;32m'
RESET='\033[0m'
RED='\033[1;31m'

if [[ $OSTYPE != "linux-gnu" ]];
then
sed -i '2s/-lpthread//' ./Makefile ;
printf "${GREEN}done!\n${RESET}" ;
else
printf "${RED}LOL is Linux bro)\n${RESET}";
fi

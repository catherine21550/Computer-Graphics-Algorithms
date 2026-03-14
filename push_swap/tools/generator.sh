#!/bin/bash

if [ $# -eq 0 ]; then
  echo "Usage: $0 <number_of_integers>"
  echo "Generates the specified number of random integers within the range of INT_MIN to INT_MAX."
  exit 1
fi

num_integers=$1

for i in $(seq 1 $num_integers); do
  openssl rand -hex 4 | awk '{printf "%d ", (strtonum("0x" $0) % (2147483647 * 2 + 1)) - 2147483647}'
done

echo ""

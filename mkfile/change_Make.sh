#!/bin/bash

if [ -z "$1" ]; then  # Check for no arguments
  echo "Usage: $0 [1|2|3|4]"
  echo "  1: Rename mkfile/Makefile_campus to mkfile/Makefile and move it to the current directory."
  echo "  2: Rename mkfile/Makefile_home to mkfile/Makefile and move it to the current directory."
  echo "  3: Rename Makefile to Makefile_campus and move it to the mkdir/ directory."
  echo "  4: Rename Makefile to Makefile_home and move it to the mkdir/ directory."
  exit 1
elif [ "$1" == "1" ]; then
  if mv mkfile/Makefile_campus mkfile/Makefile; then
    echo "Makefile_campus renamed successfully."
    if mv mkfile/Makefile ./; then  # Move to current directory
      echo "Makefile moved successfully."
    else
      echo "Error: Failed to move Makefile."
      exit 1
    fi
  else
    echo "Error: Failed to rename Makefile_campus."
    exit 1
  fi
elif [ "$1" == "2" ]; then
  if mv mkfile/Makefile_home mkfile/Makefile; then
    echo "Makefile_home renamed successfully."
    if mv mkfile/Makefile ./; then  # Move to current directory
      echo "Makefile moved successfully."
    else
      echo "Error: Failed to move Makefile."
      exit 1
    fi
  else
    echo "Error: Failed to rename Makefile_home."
    exit 1
  fi
elif [ "$1" == "3" ]; then
  if mv Makefile Makefile_campus; then
    echo "Makefile renamed to Makefile_campus"
    if mv Makefile_campus mkfile/; then
      echo "Makefile_campus moved to mkfile/"
    else
      echo "Error moving Makefile_campus"
      exit 1
    fi
  else
    echo "Error renaming Makefile"
    exit 1
  fi
elif [ "$1" == "4" ]; then # Corrected logic for option 4
  if mv Makefile Makefile_home; then
    echo "Makefile renamed to Makefile_home"
    if mv Makefile_home mkfile/; then
      echo "Makefile_home moved to mkfile/"
    else
      echo "Error moving Makefile_home"
      exit 1
    fi
  else
    echo "Error renaming Makefile"
    exit 1
  fi
else
  echo "Usage: $0 [1|2|3|4]"
  echo "  1: Rename mkfile/Makefile_campus to mkfile/Makefile and move it to the current directory."
  echo "  2: Rename mkfile/Makefile_home to mkfile/Makefile and move it to the current directory."
  echo "  3: Rename Makefile to Makefile_campus and move it to the mkfile/ directory."
  echo "  4: Rename Makefile to Makefile_home and move it to the mkfile/ directory."
  exit 1
fi
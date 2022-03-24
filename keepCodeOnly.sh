#!/bin/bash

dirsToRemove=".git .test_main .test_files gnlTester"
filesToRemove=".gitignore MakeFile"

echo "Removing directories:\n$dirsToRemove"
rm -rf $dirsToRemove

echo "Removing files"
rm $filesToRemove

echo "Removing script"
rm $0

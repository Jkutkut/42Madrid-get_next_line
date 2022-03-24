#!/bin/bash

removeDebug() {
	dirsToRemove=".git .test_main .test_files gnlTester"
	filesToRemove=".gitignore MakeFile"

	echo "Removing directories:\n$dirsToRemove"
	rm -rf $dirsToRemove

	echo "Removing files"
	rm $filesToRemove
}

cleanRepo() {
	echo "Keep Bonus o Mandatory? [B/M]"
	read response -n1

	case $response in
		b|B)
			echo "Bonus"
			for i in $(ls *bonus*); do
				f=$(echo $i | sed 's/_bonus//')
				rm $f
				mv $f $i
			done
			;;
		m|M)
			echo "Mandatory"
			rm *_bonus.c *_bonus.h
			;;
		*)
			echo "Error"
			return
			;;
	esac
	# removeDebug
}

cleanRepo
# rm $0

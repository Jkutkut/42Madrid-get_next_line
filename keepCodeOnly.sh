#!/bin/sh

removeDebug() {
	dirsToRemove=".git .test_main .test_files gnlTester"
	filesToRemove=".gitignore MakeFile"

	echo "Removing directories:\n$dirsToRemove"
	rm -rf $dirsToRemove

	echo "Removing files"
	rm $filesToRemove
}

cleanRepo() {
	echo "Keep Bonus o Mandatory? [B/M] \c"
	read response

	case $response in
		b|B)
			echo "Removing mandatory..."
			for i in $(ls *bonus*); do
				f=$(echo $i | sed 's/_bonus//')
				rm $f
				mv $i $f
			done
			;;
		m|M)
			echo "Removing bonus..."
			rm *_bonus.c *_bonus.h
			;;
		*)
			echo "Error"
			return
			;;
	esac
	echo "\c  Done!"
	removeDebug
}

cleanRepo
rm $0

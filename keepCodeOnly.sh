#!/bin/bash

removeDebug() {
	# dirsToRemove=".git .test_main .test_files gnlTester"
	# filesToRemove=".gitignore MakeFile"

	# echo "Removing directories:\n$dirsToRemove"
	# rm -rf $dirsToRemove

	# echo "Removing files"
	# rm $filesToRemove
}

removeCode() {
	echo "Bonus o Mandatory? [B/M]"
	read response -n1

	case $response in
		b|B)
			echo "Bonus"
			;;
		m|M)
			echo "Mandatory"
			;;
		*)
			echo "Error"
	esac

	# rm $0
}

echo "Removing script"
rm $0

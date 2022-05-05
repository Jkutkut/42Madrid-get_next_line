#!/bin/sh

removeDebug() {
	dirsToRemove=".git tests"
	filesToRemove=".gitignore Makefile"

	echo "Removing directories:\n$dirsToRemove"
	rm -rf $dirsToRemove

	echo "Removing files:\n$filesToRemove"
	rm $filesToRemove
}

cleanRepo() {
	echo "Keep Bonus o Mandatory? [B/M] \c"
	read response

	case $response in
		b|B)
			echo "Removing mandatory..."
			for i in $(ls src/*bonus*); do
				f=$(echo $i | sed 's/_bonus//')
				rm $f
				mv $i $f
			done
			;;
		m|M)
			echo "Removing bonus..."
			rm src/*_bonus.c include/*_bonus.h
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

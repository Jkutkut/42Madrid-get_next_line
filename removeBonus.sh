#!/bin/bash

removeCode() {
	echo "Bonus o Mandatory? [B/M]"
	read response

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


removeCode
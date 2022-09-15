##################################################################
# Robert Maldonado, CS 2318-003, Assignment 2 Part 1 Program A   #
##################################################################
# Description : This program first asks the user for an integer, # 
# then a string of up to 35 characters in length, then lastly a  #
# character. It will also return the users input.                #
##################################################################
			.data
string:			.space 81
intPrmpt:		.asciiz "Enter an integer: "
userInt:		.asciiz "Your integer is: "
strPrmpt:		.asciiz "Enter a string: "
userStr:		.asciiz "Your string is: "
charPrmpt:		.asciiz "Enter a character: "
userChar:		.asciiz "Your character is: "
newline: 		.asciiz "\n"

			.text
			.globl main
main:
			li $v0, 4
			la $a0, intPrmpt
			syscall
			li $v0, 5
			syscall
			
			move $t0, $v0
			li $v0, 4
			la $a0, userInt
			syscall
			
			li $v0, 1
			move $a0, $t0
			syscall
			
			li $v0, 4        
			la $a0, newline
			syscall
			
			li $v0, 4
			la $a0, strPrmpt
			syscall
			li $v0, 8
			la $a0, string
			li $a1, 36
			syscall
			
			li $v0, 4        
			la $a0, newline
			syscall
			
			li $v0, 4
			la $a0, userStr
			syscall
			la $a0, string
			syscall
			
			li $v0, 4        
			la $a0, newline
			syscall
			
			li $v0, 4
			la $a0, charPrmpt
			syscall
			li $v0, 12
			syscall
			move $t0, $v0
			
			li $v0, 4        
			la $a0, newline
			syscall
			
			li $v0, 4
			la $a0, userChar
			syscall
			li $v0, 11
			move $a0, $t0
			syscall
			
			li $v0, 10
			syscall
			

#Robert Maldonado, CS 2318-003, Assignment 2 Part 1 Program D
#This program takes input from the user to calculate the weighted average.
#It takes 3 different scores, all of them calculated differently, then adds
#them together to get the final score.

			.data
exam1Prompt:      	.asciiz "Enter score for Exam 1: "
exam2Prompt:       	.asciiz "Enter score for Exam 2: "
exam3Prompt:       	.asciiz "Enter score for Final Exam: "
avgScore:             	.asciiz "The weighted average is:  "

            		.text
            		.globl main
main:
			#Exam score 1 prompt
           		li $v0, 4
          	  	la $a0, exam1Prompt
          	  	syscall
            		li $v0, 5
            		syscall              
            		move $t0, $v0
            		
			#Exam score 2 prompt
            		li $v0, 4
           		la $a0, exam2Prompt  
            		syscall
            		li $v0, 5
            		syscall               
            		move $t1, $v0

			#Exam score 3 prompt
            		li $v0, 4
           		la $a0, exam3Prompt   
            		syscall
            		li $v0, 5
            		syscall               
            		move $t2, $v0

            		#Finding exam 1 score
            		li $t5, 63
            		mul $t0, $t0, $t5
            		li $t5, 256
            		div $t0, $t0,$t5
            		
            		#Finding exam 2 score
            		sll $t1, $t1, 7
            		li $t5, 504
            		div $t1, $t1, $t5
            		
            		#Finding final exam score
            		sra $t2, $t2, 1

 			#Finding the final average
            		li $t4, 0     
            		add $t4, $t4, $t0
            		add $t4, $t4, $t1
            		add $t4, $t4, $t2
            
			#Outputting the average score to user
            		li $v0, 4
            		la $a0, avgScore
            		syscall
            		li $v0, 1
            		move $a0, $t4
            		syscall
			
			#Exiting the program
            		li $v0, 10      
            		syscall

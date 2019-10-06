# Zachary Wayne ID:zwayne ID#:115649422 Sec#:0103 
# Find the nth digit of a generalized fibonacci sequence recursively
	.data

v0:	.word 0
v1:	.word 0
num:	.word 0
ans:	.word 0

	.text
 
main:	li $sp, 0x7ffffffc #init $sp
	
	li $v0, 5
	syscall #scan a number
	move $t0, $v0
	sw $t0, v0
	sw $t0, ($sp) #store value and move $sp down
	sub $sp, $sp, 4

	li $v0, 5
	syscall #scan a number
	move $t0, $v0
	sw $t0, v1
	sw $t0, ($sp) #store value and move $sp down
	sub $sp, $sp, 4

	li $v0, 5
	syscall #scan a number
	move $t0, $v0
	sw $t0, num
	sw $t0, ($sp)	#store value and move $sp down
	sub $sp, $sp, 4

	jal gfn #calling gfn()

	add $sp, $sp, 12 #pop args
	
	move $t0, $v0
	sw $t0, ans #store result

	li $v0, 1
	lw $a0, ans
	syscall #print result

	li $v0, 11
	li $a0, 10 #print newline
	syscall

	li $v0, 10 #exit
	syscall
			#prologue
gfn:	sub $sp, $sp,24 #set $sp
	sw $ra, 24($sp) #save $ra
	sw $fp, 20($sp) #save $fp
	add $fp, $sp,24 #set new $fp

	lw $t0, 12($fp) #load and restore all parameters
	sw $t0, 16($sp)
	
	lw $t0, 8($fp)
	sw $t0, 12($sp)
	
	lw $t0, 4($fp)
	sw $t0, 8($sp)
	
	li $t0, 0 
	sw $t0, 4($sp)

	jal gfn_helper #call gfn_helper()
			#epilogue
	lw $ra, 24($sp) #restore $ra
	lw $fp, 20($sp) #restore $fp
	add $sp, $sp, 24 #reset $fp
	jr $ra #jump back to caller
				#prologue
gfn_helper:	sub $sp, $sp, 12 #set $sp
	sw $ra, 12($sp) #save $ra
	sw $fp, 8($sp) #save $fp
	add $fp, $sp, 12 #set new $fp

	lw $t0, 16($fp) #Load all values
	lw $t1, 12($fp)
	lw $t2, 8($fp)
	lw $t3, 4($fp)

	bgez $t2, else1 #if(n >=0)

	li $t4, -1 #ans = -1
	sw $t4, 4($sp)
	j endfunc

else1:	beqz $t2, if1	#if(n == 0)
	beq $t2, $t3, if1 # || if(n == i)

	add $t3, $t3, 1 # i+=1 
	add $t0, $t0, $t1 # n0 + n1 
	
	sw $t1, ($sp) # restore values
	sub $sp, $sp, 4
	sw $t0, ($sp)
	sub $sp, $sp, 4
	sw $t2, ($sp)
	sub $sp, $sp, 4
	sw $t3, ($sp)
	sub $sp, $sp, 4
	
	jal gfn_helper #recall itself

	add $sp, $sp, 16 #pop args
	
if1:	sw $t0, 4($sp) # ans = n0

	#epilogue
endfunc:lw $t0, 4($sp) #put return value for safe keepings
	move $v0, $t0
	lw $ra, 12($sp) #restore $ra
	lw $fp, 8($sp) #restore $fp
	add $sp, $sp, 12 #r eset $fp
	jr $ra #go back to caller



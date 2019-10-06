#Zachary Wayne ID:zwayne ID#:115649422 Sec#:0103
#Find the nth digit of a generalized fibonacci sequence
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
	sw $t0, ($sp) #store number(v0) and change $sp
	sub $sp, $sp, 4

	li $v0, 5
	syscall #scan a number
	move $t0, $v0
	sw $t0, v1
	sw $t0, ($sp) #store number(v1) and change $sp
	sub $sp, $sp, 4

	li $v0, 5
	syscall #scan a number
	move $t0, $v0
	sw $t0, num
	sw $t0, ($sp)	#store number (num) and change $sp
	sub $sp, $sp, 4

	jal gfn #call gfn()

	add $sp, $sp, 12 #pop args
	
	move $t0, $v0
	sw $t0, ans #store result

	li $v0, 1
	lw $a0, ans
	syscall #print result

	li $v0, 11
	li $a0, 10
	syscall #print newline

	li $v0, 10
	syscall #exit
			#prologue
gfn:	sub $sp, $sp, 16 #set $sp
	sw $ra, 16($sp) #save $ra
	sw $fp, 12($sp) #save $fp
	add $fp, $sp, 16 #set new $fp

	lw $t0, 12($fp) #get args
	lw $t1, 8($fp)
	lw $t2, 4($fp)

	li $t4, 1 #set local variable i to 1
	sw $t4, 8($sp)

	bgez $t2, else1 #if (n >= 0)

	li $t1, -1 #n1 = -1
	
	j endfunc
	
else1:	bnez $t2, else2 # if(n != 0) 

	move $t1, $t0 # n1 = n0

	j endfunc

else2:  lw $t4, 8($sp) 
	bge $t4, $t2, endfunc # if(i > n)

	sw $t0, 4($sp) #temp = n0
	move $t0, $t1 #n0 = n1
	lw $t4, 4($sp) 
	add $t1, $t1, $t4 # n1+=temp
	lw $t3, 8($sp)
	add $t3, $t3, 1 # i++
	sw $t3, 8($sp)	
	j else2 # loop it up
		# epilogue
endfunc: move $v0, $t1 # store result
	lw $ra, 16($sp) # restore $ra
	lw $fp, 12($sp) # restore $fp
	add $sp, $sp, 16 # reset $sp
	jr $ra #return to sender
	
	
	
	

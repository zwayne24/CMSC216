#Zachary Wayne ID:zwayne ID#:115649422 Sec#:0103
#Tests if the three given sides can make a valid triangle
	.data

side1:	.word 0
side2:	.word 0
side3:	.word 0
ans:	.word 0

	.text

main:	li $t0, 0 #ans = 0
	sw $t0, ans

	li $v0, 5
	syscall # scan int
	move $t1, $v0
	sw $t1, side1 #store at side1

	li $v0, 5
	syscall #scan int
	move $t2, $v0
	sw $t2, side2 #store at side2

	li $v0, 5
	syscall #scan int
	move $t3, $v0
	sw $t3, side3 #store at side3

	bltz $t1, else1 # if(side1 < 0)
	bltz $t2, else1 # if(side2 < 0)
	bltz $t3, else1 # if(side3 < 0)

	add $t4, $t1, $t2 # add sides 1 & 2
	add $t5, $t1, $t3 # add sides 1 & 3
	add $t6, $t2, $t3 # add sides 2 & 3

	ble $t4, $t3, end # if(1 & 2 <= 3)
	ble $t5, $t2, end # if(1 & 3 <= 2)
	ble $t6, $t1, end # if(2 & 3 <= 1)

	li $t0, 1 # ans = 1
	sw $t0, ans
	j end

else1:	li $t0, -1 # and = -1
	sw $t0, ans

end:	li $v0, 1 
	lw $a0, ans
	syscall  # print int

	li $v0, 11
	li $a0, 10
	syscall #print newline

	li $v0, 10
	syscall #exit

	
	

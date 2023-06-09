		MAIN: 
			MVI B 0x100H
			MVI C 0x2H
		L7:
			MOV A C
			CMP B
			JC L8
			HLT
		L8:
			MOV A B
			ADD C
			MOV D A
			MOV H D
		L5:
			MOV A B
			CMP C
			JC L6
			JMP L7
		L6:
			MOV A B
			SUB C
			MOV L A
			MOV B L
			MOV A C
			CMP B
			JC L1
			JMP L2
		L1:
			MVI C 0xaH
			JMP L5
		L2:
			MVI B 0x14H
		L3:
			MOV A C
			CMP B
			JC L4
			HLT
		L4:
			MOV A B
			ADD 0x1H
			MOV C A
			MOV B 0xH
			JMP L3

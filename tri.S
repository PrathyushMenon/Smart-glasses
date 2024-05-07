.text
.global lab5_act_1_1_add
.global lab5_act_1_1_flag
.global lab5_act_1_2
.global lab5_act_1_3
.global lab5_act_1_4

lab5_act_1_1_add:
    ADD r0, r0, r1
    BX lr

lab5_act_1_1_flag:
    MRS r0, APSR
    BX lr

lab5_act_1_2:
    CMP r0, r1
    BEQ equal
    MOV r0, #0
    BX lr

equal:
    MOV r0, #1
    BX lr

lab5_act_1_3:
    CMP r0, r1
    BHS higher_or_same
    MOV r0, #0
    BX lr

higher_or_same:
    MOV r0, #1
    BX lr

lab5_act_1_4:
    CMP r0, r1
    BLT less_than
    MOV r0, #0
    BX lr

less_than:
    MOV r0, #1
    BX lr

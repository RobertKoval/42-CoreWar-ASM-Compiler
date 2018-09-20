.name "Pope Francis"
.comment "God with us!"

        #Max 511 % 512
        #42
ld %57671936, r8
ld %100728832, r9
ld %68863, r10
ld %246, r11
ld %1, r5
ld %-1, r6

#03 70 01 00 | 06 01 00 00 |00 01 0c ff |f6
alive: st r1, 6
live %1
fork %:alive
#add r2, r3, r4
#st r1, 511
#zjmp %:alive
write:
st r8, 50 #+4
st r9, 49
st r10, 48
st r11, 47
st r8, 60 #+4
st r9, 59
st r10, 58
st r11, 57
#st r12, 36
#st r13, 35
st r8, 70 #+4
st r9, 69
st r10, 68
st r11, 67

st r8, 80 #+4
st r9, 77
add r5, r6, r16
zjmp %:alive
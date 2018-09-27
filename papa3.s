.name "Papa Jhon Paul II"
.comment "FROM POLAND"

ld %57671936, r8 #7
ld %100728832, r9 #7
ld %68863, r10 #7
ld %246, r11 #7

st r4, -9
st r4, -18
st r1, -27
st r4, -37
st r4, -46
st r4, -55

st r8, 90#+4 #5
st r9, 89 #5
st r10, 88 #5
st r11, 87 #5

st r4, -9
st r4, -18
st r4, -21
st r4, -27

start:
st r1, 6
live %1
st r4, -9

st r1, 6
live %1
st r4, -9

st r1, 6
live %1
st r4, -9

st r1, 6
live %1
st r4, -9

st r1, 6
live %1
st r4, -9

st r1, 6
live %1
st r4, -9

st r1, 6
live %1
st r4, -9

st r1, 6
live %1
st r4, -9

st r1, 6
live %1
st r4, -9

st r1, 6
live %1
st r4, -9

st r1, 6
live %1
st r4, -9

st r1, 6
live %1
st r4, -9

st r1, 6
live %1
st r4, -9

st r1, 6
live %1
st r4, -9

add r2, r3, r4
fork %:azaza
zjmp %:start



azaza:
st r1, 6
live %1
st r4, -9

ld %57671936, r8
ld %100728832, r9
ld %68863, r10
ld %246, r11
ld %1, r5
ld %-1, r6

#st r8, 240
#st r9, 239
#st r10, 238
#st r11, 237

#st r8, 440 #+4
st r4, 441
st r9, 439
st r1, 436
st r4, -9
#st r4, 440



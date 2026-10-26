
uint FUN_005ba430(void)

{
  uint in_EAX;
  uint uVar1;
  int *piVar2;
  
  piVar2 = *(int **)(in_EAX + 0x260);
  if ((((((((uint)piVar2[10] >> 8 & 1) == 0) &&
         (piVar2 = *(int **)(in_EAX + 0x264), ((uint)piVar2[10] >> 8 & 1) == 0)) &&
        (piVar2 = *(int **)(in_EAX + 0x268), ((uint)piVar2[10] >> 8 & 1) == 0)) &&
       ((piVar2 = *(int **)(in_EAX + 0x26c), ((uint)piVar2[10] >> 8 & 1) == 0 &&
        (piVar2 = *(int **)(in_EAX + 0x270), ((uint)piVar2[10] >> 8 & 1) == 0)))) &&
      ((piVar2 = *(int **)(in_EAX + 0x274), ((uint)piVar2[10] >> 8 & 1) == 0 &&
       ((piVar2 = *(int **)(in_EAX + 0x278), ((uint)piVar2[10] >> 8 & 1) == 0 &&
        (piVar2 = *(int **)(in_EAX + 0x290), ((uint)piVar2[10] >> 8 & 1) == 0)))))) &&
     ((piVar2 = *(int **)(in_EAX + 0x294), ((uint)piVar2[10] >> 8 & 1) == 0 &&
      ((piVar2 = *(int **)(in_EAX + 0x298), ((uint)piVar2[10] >> 8 & 1) == 0 &&
       (piVar2 = *(int **)(in_EAX + 600), ((uint)piVar2[10] >> 8 & 1) == 0)))))) {
    return in_EAX & 0xffffff00;
  }
  uVar1 = (**(code **)(*piVar2 + 0xec))(0xe);
  return uVar1;
}


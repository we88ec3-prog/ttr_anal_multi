
undefined4 FUN_00544730(int param_1,float *param_2,int param_3)

{
  float fVar1;
  float fVar2;
  bool bVar3;
  float *in_EAX;
  undefined4 *in_EDX;
  
  if (*(char *)(param_1 + 0x105) == '\0') {
    *in_EDX = 0;
    return 0;
  }
  fVar1 = *in_EAX;
  *in_EDX = 1;
  fVar1 = fVar1 - *(float *)(param_1 + 0xa0);
  fVar2 = in_EAX[1] - *(float *)(param_1 + 0xa4);
  fVar1 = fVar2 * fVar2 + fVar1 * fVar1;
  *param_2 = fVar1;
  bVar3 = *(float *)(param_1 + 0xfc) * *(float *)(param_1 + 0xfc) <= fVar1;
  if (*(int *)(param_1 + 0x100) == 0) {
    if ((param_3 == 0) || (bVar3)) {
LAB_005447e0:
      *(undefined1 *)(param_1 + 0x104) = 0;
      return 0;
    }
  }
  else if (bVar3) {
    if (*(char *)(param_1 + 0x104) == '\0') {
      *in_EDX = 0;
    }
    goto LAB_005447e0;
  }
  if (*(char *)(param_1 + 0x104) != '\0') {
    *in_EDX = 0;
  }
  *(undefined1 *)(param_1 + 0x104) = 1;
  return 1;
}


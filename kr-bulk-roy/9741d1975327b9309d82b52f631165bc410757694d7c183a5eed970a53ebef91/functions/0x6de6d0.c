
uint FUN_006de6d0(void)

{
  int *piVar1;
  int *in_EAX;
  byte *pbVar2;
  uint uVar3;
  
  if (*(int *)in_EAX[8] != 0) {
    if (1 < *(int *)in_EAX[0xc]) {
      *(int *)in_EAX[0xc] = *(int *)in_EAX[0xc] + -1;
      pbVar2 = (byte *)(*(int *)in_EAX[8] + 1);
      *(int *)in_EAX[8] = (int)pbVar2;
      return (uint)*pbVar2;
    }
    if ((*(int *)in_EAX[8] != 0) && (piVar1 = (int *)in_EAX[0xc], 0 < *piVar1)) {
      *piVar1 = *piVar1 + -1;
      pbVar2 = *(byte **)in_EAX[8];
      *(byte **)in_EAX[8] = pbVar2 + 1;
      uVar3 = (uint)*pbVar2;
      goto LAB_006de720;
    }
  }
  uVar3 = (**(code **)(*in_EAX + 0x1c))();
LAB_006de720:
  if (uVar3 == 0xffffffff) {
    return 0xffffffff;
  }
  if ((*(int *)in_EAX[8] != 0) && (0 < *(int *)in_EAX[0xc])) {
    return (uint)**(byte **)in_EAX[8];
  }
                    /* WARNING: Could not recover jumptable at 0x006de748. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar3 = (**(code **)(*in_EAX + 0x18))();
  return uVar3;
}



int * FUN_0071a570(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int *in_EAX;
  int *piVar4;
  int local_8;
  
  uVar1 = in_EAX[1] + 0x14;
  if (uVar1 < 0x8001) {
    local_8 = *in_EAX;
    piVar4 = (int *)(local_8 + 0x18 + in_EAX[1]);
    in_EAX[1] = uVar1;
  }
  else {
    piVar4 = (int *)FUN_0071a440(&local_8);
  }
  if (piVar4 != (int *)0x0) {
    *piVar4 = local_8;
    piVar4[1] = 0;
    piVar4[2] = 0;
    piVar4[3] = 0;
    piVar4[4] = 0;
    iVar2 = *(int *)(param_1 + 0x1c);
    if (iVar2 != 0) {
      iVar3 = *(int *)(iVar2 + 0xc);
      *(int **)(iVar3 + 0x10) = piVar4;
      piVar4[3] = iVar3;
      *(int **)(iVar2 + 0xc) = piVar4;
      return piVar4;
    }
    *(int **)(param_1 + 0x1c) = piVar4;
    piVar4[3] = (int)piVar4;
    return piVar4;
  }
  return (int *)0x0;
}


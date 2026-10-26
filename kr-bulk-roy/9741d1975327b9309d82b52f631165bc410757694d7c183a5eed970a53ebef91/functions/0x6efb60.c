
void FUN_006efb60(byte param_1)

{
  int *piVar1;
  int *piVar2;
  byte *pbVar3;
  uint uVar4;
  undefined1 *in_ECX;
  
  piVar1 = *(int **)(in_ECX + 4);
  if (piVar1 != (int *)0x0) {
    if ((*(int *)piVar1[9] == 0) || (piVar2 = (int *)piVar1[0xd], *piVar2 < 1)) {
      uVar4 = (**(code **)(*piVar1 + 0xc))(param_1);
    }
    else {
      *piVar2 = *piVar2 + -1;
      pbVar3 = *(byte **)piVar1[9];
      *(byte **)piVar1[9] = pbVar3 + 1;
      *pbVar3 = param_1;
      uVar4 = (uint)param_1;
    }
    if (uVar4 != 0xffffffff) {
      return;
    }
  }
  *in_ECX = 1;
  return;
}


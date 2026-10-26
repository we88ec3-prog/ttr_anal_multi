
void FUN_006fd7a0(uint param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int in_EDX;
  
  iVar3 = *(int *)(in_EDX + 0x10);
  iVar2 = *(int *)(in_EDX + 0x68);
  piVar4 = (int *)(in_EDX + 0x68);
  while (iVar2 != 0) {
    piVar5 = (int *)*piVar4;
    if ((uint)piVar5[2] < param_1) break;
    if (piVar5[2] == param_1) {
      if ((~*(byte *)(iVar3 + 0x14) & *(byte *)((int)piVar5 + 5) & 3) == 0) {
        return;
      }
      *(byte *)((int)piVar5 + 5) = *(byte *)((int)piVar5 + 5) ^ 3;
      return;
    }
    piVar4 = piVar5;
    iVar2 = *piVar5;
  }
  piVar5 = (int *)FUN_00700880();
  *(undefined1 *)(piVar5 + 1) = 10;
  bVar1 = *(byte *)(iVar3 + 0x14);
  piVar5[2] = param_1;
  *(byte *)((int)piVar5 + 5) = bVar1 & 3;
  *piVar5 = *piVar4;
  *piVar4 = (int)piVar5;
  piVar5[4] = iVar3 + 0x78;
  iVar2 = *(int *)(iVar3 + 0x8c);
  piVar5[5] = iVar2;
  *(int **)(iVar2 + 0x10) = piVar5;
  *(int **)(iVar3 + 0x8c) = piVar5;
  return;
}


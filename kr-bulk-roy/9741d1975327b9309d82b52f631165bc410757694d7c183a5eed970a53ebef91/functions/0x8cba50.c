
void FUN_008cba50(int param_1,short *param_2)

{
  short sVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x70);
  *(short *)(param_1 + 0x9c) = -(short)iVar2;
  sVar1 = *param_2;
  *(int *)(param_1 + 0x94) = -(sVar1 * iVar2);
  if (0 < iVar2) {
    *(int *)(param_1 + 0x94) = (*(int *)(param_1 + 0x68) + -1) * iVar2 + -(sVar1 * iVar2);
  }
  *(undefined4 *)(param_1 + 0x9e) = 0;
  return;
}


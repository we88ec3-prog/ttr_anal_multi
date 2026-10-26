
int FUN_008d5e50(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = param_2 - *(int *)(param_1 + 0x10);
  iVar1 = 0;
  if (uVar2 < *(uint *)(param_1 + 0x14)) {
    iVar1 = uVar2 + 1;
  }
  return iVar1;
}


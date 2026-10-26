
int FUN_008ec870(undefined4 param_1,int param_2,ushort param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_2 + 0xc);
  piVar1 = (int *)(iVar2 + 4 + (uint)param_3 * 8);
  *piVar1 = *piVar1 + param_4;
  return iVar2 + 4 + (uint)param_3 * 8;
}



void FUN_008ec7f0(undefined4 param_1,int param_2,ushort param_3,int param_4)

{
  int *piVar1;
  byte *pbVar2;
  
  piVar1 = (int *)(*(int *)(param_2 + 0x10) + (uint)param_3 * 8);
  *piVar1 = *piVar1 + param_4;
  pbVar2 = (byte *)((uint)param_3 + *(int *)(param_2 + 0x18));
  *pbVar2 = *pbVar2 | 8;
  return;
}


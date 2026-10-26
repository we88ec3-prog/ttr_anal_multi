
void FUN_008ec820(undefined4 param_1,int param_2,ushort param_3,int param_4)

{
  byte *pbVar1;
  int *piVar2;
  
  piVar2 = (int *)(*(int *)(param_2 + 0x10) + 4 + (uint)param_3 * 8);
  *piVar2 = *piVar2 + param_4;
  pbVar1 = (byte *)((uint)param_3 + *(int *)(param_2 + 0x18));
  *pbVar1 = *pbVar1 | 0x10;
  return;
}


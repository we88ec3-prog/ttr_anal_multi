
void FUN_008ec6f0(int param_1,int param_2,ushort param_3,undefined4 param_4)

{
  int *piVar1;
  byte *pbVar2;
  int iVar3;
  
  if (*(short *)(param_1 + 0x12a) != 0) {
    piVar1 = (int *)(*(int *)(param_2 + 0x10) + (uint)param_3 * 8);
    iVar3 = FUN_008b7dc0(param_4,(int)*(short *)(param_1 + 0x12a),*(undefined4 *)(param_1 + 0x234));
    *piVar1 = *piVar1 + iVar3;
    pbVar2 = (byte *)((uint)param_3 + *(int *)(param_2 + 0x18));
    *pbVar2 = *pbVar2 | 8;
  }
  if (*(short *)(param_1 + 300) != 0) {
    piVar1 = (int *)(*(int *)(param_2 + 0x10) + 4 + (uint)param_3 * 8);
    iVar3 = FUN_008b7dc0(param_4,(int)*(short *)(param_1 + 300),*(undefined4 *)(param_1 + 0x234));
    *piVar1 = *piVar1 + iVar3;
    pbVar2 = (byte *)((uint)param_3 + *(int *)(param_2 + 0x18));
    *pbVar2 = *pbVar2 | 0x10;
  }
  return;
}


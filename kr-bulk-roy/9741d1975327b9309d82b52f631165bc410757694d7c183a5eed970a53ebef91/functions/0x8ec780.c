
void FUN_008ec780(int param_1,int param_2,ushort param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  
  if (*(short *)(param_1 + 0x12a) != 0) {
    piVar1 = (int *)(*(int *)(param_2 + 0xc) + (uint)param_3 * 8);
    iVar2 = FUN_008b7dc0(param_4,(int)*(short *)(param_1 + 0x12a),*(undefined4 *)(param_1 + 0x234));
    *piVar1 = *piVar1 + iVar2;
  }
  if (*(short *)(param_1 + 300) != 0) {
    piVar1 = (int *)(*(int *)(param_2 + 0xc) + 4 + (uint)param_3 * 8);
    iVar2 = FUN_008b7dc0(param_4,(int)*(short *)(param_1 + 300),*(undefined4 *)(param_1 + 0x234));
    *piVar1 = *piVar1 + iVar2;
  }
  return;
}



bool FUN_0081b3f0(int param_1)

{
  byte *pbVar1;
  uint uVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090c12e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(int *)(param_1 + 0x10) != 0) {
    pbVar1 = *(byte **)(*(int *)(param_1 + 0x10) + 8);
    if ((DAT_00fe3430 & 1) == 0) {
      DAT_00fe3430 = DAT_00fe3430 | 1;
      local_8 = 0;
      FUN_00832a70(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
      _atexit((_func_4879 *)&LAB_00bd0cb0);
    }
    uVar2 = (uint)*pbVar1;
    if (((int)uVar2 < (int)(short)(DAT_00fe343c - DAT_00fe3438 >> 2)) &&
       (pbVar1 = *(byte **)(DAT_00fe3438 + uVar2 * 4), pbVar1 != (byte *)0x0)) {
      ExceptionList = local_10;
      return (1 << (*pbVar1 & 0x1f) & *(uint *)(in_ECX + 8)) != 0;
    }
  }
  ExceptionList = local_10;
  return false;
}


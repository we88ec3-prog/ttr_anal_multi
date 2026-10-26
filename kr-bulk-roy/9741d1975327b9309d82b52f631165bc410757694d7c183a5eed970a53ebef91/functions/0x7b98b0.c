
void FUN_007b98b0(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00935187;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x3c) == 1) {
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 0;
      FUN_00798de0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
      _atexit((_func_4879 *)&LAB_00bcd2e0);
    }
    local_8 = 0xffffffff;
    if (DAT_00fb76a8 != 0) {
      FUN_007e0b00();
      piVar1 = *(int **)(in_ECX + 0x68);
      if ((piVar1 != (int *)0x0) && (*piVar1 == 1)) {
        *piVar1 = 2;
      }
      if (*(int *)(in_ECX + 0x40) != 0) {
        FUN_007f7380();
      }
      if ((DAT_00fe3284 & 1) == 0) {
        DAT_00fe3284 = DAT_00fe3284 | 1;
        local_8 = 1;
        FUN_007df1e0();
        _atexit((_func_4879 *)&LAB_00bd0ad0);
        local_8 = 0xffffffff;
      }
      FUN_007df840();
      iVar2 = FUN_00891268(0x28);
      local_8 = 2;
      if (iVar2 == 0) {
        uVar3 = 0;
      }
      else {
        uVar3 = FUN_007e7f20(iVar2);
      }
      *(undefined4 *)(in_ECX + 0x8c) = uVar3;
      *(undefined4 *)(in_ECX + 0x3c) = 2;
    }
  }
  ExceptionList = local_10;
  return;
}


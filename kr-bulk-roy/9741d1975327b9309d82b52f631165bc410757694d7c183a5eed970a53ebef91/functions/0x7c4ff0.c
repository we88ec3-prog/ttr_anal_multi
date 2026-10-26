
void FUN_007c4ff0(void)

{
  int iVar1;
  uint uVar2;
  int in_ECX;
  int iVar3;
  uint uVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00938aae;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x58) == 1) {
    iVar3 = *(int *)(in_ECX + 200) - *(int *)(in_ECX + 0xc4);
    iVar1 = iVar3 >> 0x1f;
    uVar4 = 0;
    if (iVar3 / 0x38 + iVar1 != iVar1) {
      do {
        if ((DAT_00fe324c & 1) == 0) {
          DAT_00fe324c = DAT_00fe324c | 1;
          local_8 = 0;
          FUN_007cdeb0(uVar2);
          _atexit((_func_4879 *)&LAB_00bd09b0);
          local_8 = 0xffffffff;
        }
        FUN_007cf480();
        uVar4 = uVar4 + 1;
      } while (uVar4 < (uint)((*(int *)(in_ECX + 200) - *(int *)(in_ECX + 0xc4)) / 0x38));
    }
    FUN_007c42a0();
    FUN_007c3fc0();
    FUN_007c4100(in_ECX);
    FUN_007c4940();
    *(undefined4 *)(in_ECX + 0x58) = 0;
  }
  ExceptionList = local_10;
  return;
}


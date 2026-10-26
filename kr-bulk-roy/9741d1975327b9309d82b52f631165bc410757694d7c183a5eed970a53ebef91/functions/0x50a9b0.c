
undefined4 FUN_0050a9b0(int param_1,int param_2,uint param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  char *pcVar3;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0092419e;
  local_14 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffffd8;
  ExceptionList = &local_14;
  if (param_3 < 2) {
    local_1c = 0;
  }
  else {
    local_1c = (param_3 - 2) / 0x11;
  }
  if (local_1c != 0) {
    pcVar3 = (char *)(param_2 + 0xe);
    do {
      if (*pcVar3 == '\0') {
        if (*(ushort *)(pcVar3 + -0xc) - 1 < 0x1e0) {
          puVar1 = (undefined4 *)(param_1 + 0x23a0 + (uint)*(ushort *)(pcVar3 + -0xc) * 0x18);
          *puVar1 = 0;
          puVar1[1] = 0;
          puVar1[2] = 0;
          puVar1[3] = 0;
          puVar1[4] = 0;
          puVar1[5] = 0;
        }
        else {
          FUN_006edb60(&DAT_00c0ddc0,uVar2);
        }
      }
      else {
        FUN_00509260(param_1 + 0x23a0,*(undefined4 *)(pcVar3 + -10),*(undefined4 *)(pcVar3 + -6),
                     *pcVar3);
      }
      pcVar3 = pcVar3 + 0x11;
      local_1c = local_1c - 1;
    } while (local_1c != 0);
  }
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_c = 0;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_c = 0xffffffff;
  }
  FUN_0058aad0(0xf4364);
  ExceptionList = local_14;
  return 0;
}


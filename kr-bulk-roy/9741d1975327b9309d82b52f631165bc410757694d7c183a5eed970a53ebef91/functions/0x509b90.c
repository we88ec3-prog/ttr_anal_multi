
undefined4 FUN_00509b90(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint in_ECX;
  int in_EDX;
  char *pcVar4;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0092419e;
  local_14 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffffd8;
  ExceptionList = &local_14;
  if ((*(char *)(in_EDX + 2) == '\x01') && (iVar1 = param_1 + 0x16f8, iVar1 != 0)) {
    *(uint *)(param_1 + 0x2398) = (uint)*(byte *)(in_EDX + 3);
    if (in_ECX < 4) {
      local_1c = 0;
    }
    else {
      local_1c = in_ECX - 4 >> 4;
    }
    if (local_1c != 0) {
      pcVar4 = (char *)(in_EDX + 5);
      do {
        if (*pcVar4 == '\0') {
          if ((byte)pcVar4[-1] - 1 < 100) {
            puVar3 = (undefined4 *)((uint)(byte)pcVar4[-1] * 0x20 + iVar1);
            *puVar3 = 0;
            puVar3[1] = 0;
            puVar3[2] = 0;
            puVar3[3] = 0;
            puVar3[4] = 0;
            puVar3[5] = 0;
          }
          else {
            FUN_006edb60(&DAT_00c0ddc0,uVar2);
          }
        }
        else {
          FUN_00508cb0(iVar1,*(undefined4 *)(pcVar4 + 1),*(undefined4 *)(pcVar4 + 5),*pcVar4,0);
        }
        pcVar4 = pcVar4 + 0x10;
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
    FUN_0058aad0(0xf4365);
    ExceptionList = local_14;
    return 0;
  }
  FUN_006edb60("BagSt: Invalid Bag No %d",*(char *)(in_EDX + 2));
  ExceptionList = local_14;
  return 0x80004005;
}


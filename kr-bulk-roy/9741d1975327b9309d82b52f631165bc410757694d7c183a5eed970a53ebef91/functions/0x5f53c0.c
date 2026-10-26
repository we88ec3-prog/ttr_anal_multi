
void FUN_005f53c0(int param_1)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  int *in_ECX;
  undefined1 *puVar4;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0094713e;
  local_14 = ExceptionList;
  if (*(int *)(param_1 + 0x10) == 0x76c) {
    ExceptionList = &local_14;
    if (in_ECX[0x47] == 1) {
      iVar1 = FUN_00404ba0();
      iVar1 = *(int *)(iVar1 + 0x6920);
      if ((in_ECX[0x48] == 1) && (iVar1 != -0x16f8)) {
        if ((*(int *)(in_ECX[0x3e] + 0xcc) == 0) || (*(int *)(in_ECX[0x3e] + 0xd8) == 0)) {
          iVar2 = -1;
        }
        else {
          iVar2 = FUN_005f55a0();
        }
        in_ECX[0x48] = iVar2 + 1;
        if (1 < iVar2 + 1) {
          in_ECX[0x48] = 1;
        }
        iVar2 = 1;
        if (0 < *(int *)(iVar1 + 0x2398)) {
          puVar4 = (undefined1 *)(iVar1 + 0x1730);
          do {
            *puVar4 = 0;
            iVar2 = iVar2 + 1;
            puVar4 = puVar4 + 0x20;
          } while (iVar2 <= *(int *)(iVar1 + 0x2398));
        }
        if ((*(int *)(in_ECX[0x3e] + 0xcc) == 0) || (*(int *)(in_ECX[0x3e] + 0xd8) == 0)) {
          iVar1 = -1;
        }
        else {
          iVar1 = FUN_005f55a0();
        }
        if ((DAT_00f94390 & 1) == 0) {
          DAT_00f94390 = DAT_00f94390 | 1;
          local_c = 0;
          FUN_004e1590();
          _atexit((_func_4879 *)&LAB_00bccc80);
          local_c = 0xffffffff;
        }
        *(int *)(DAT_00f94300 + 0x50d8) = iVar1 + 1;
      }
    }
    pcVar3 = *(code **)(*in_ECX + 0x1b0);
    in_ECX[0x46] = *(int *)(param_1 + 0x14);
    (*pcVar3)();
    ExceptionList = local_14;
    return;
  }
  if (*(int *)(param_1 + 0x10) == 0x578) {
    if (*(int *)(param_1 + 8) == *(int *)(in_ECX[0x3f] + 0x20)) {
      pcVar3 = *(code **)(*in_ECX + 0x1b8);
    }
    else {
      if (*(int *)(param_1 + 8) != *(int *)(in_ECX[0x40] + 0x20)) {
        return;
      }
      pcVar3 = *(code **)(*in_ECX + 0x1bc);
    }
    ExceptionList = &local_14;
    (*pcVar3)(param_1,DAT_00d61f20 ^ (uint)&stack0xffffffd8);
  }
  ExceptionList = local_14;
  return;
}


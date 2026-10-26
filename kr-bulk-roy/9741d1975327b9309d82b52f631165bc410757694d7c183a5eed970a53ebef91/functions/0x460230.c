
void FUN_00460230(undefined4 param_1,int param_2)

{
  code *pcVar1;
  int iVar2;
  int in_ECX;
  uint uVar3;
  uint uVar4;
  int local_38;
  int local_34 [6];
  undefined1 local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093161a;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  uVar4 = 0;
  local_34[1] = 0;
  local_34[2] = 0;
  local_34[3] = 0;
  local_34[4] = 0;
  local_34[5] = 0;
  local_1c = 0;
  if ((DAT_00f8d9a4 & 1) == 0) {
    DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
    local_c = 0;
    FUN_0051c120(DAT_00d61f20 ^ (uint)&stack0xffffffb8);
    _atexit((_func_4879 *)&LAB_00bccc90);
  }
  local_c = 0xffffffff;
  local_38 = in_ECX;
  FUN_008438c0(&local_38);
  if ((local_34[0] == DAT_00f8d91c) || (iVar2 = *(int *)(local_34[0] + 0x10), iVar2 == 0)) {
    if (in_ECX != 0xf423e) {
      ExceptionList = local_14;
      return;
    }
    local_34[4] = param_2;
    local_34[3] = 0xf423e;
  }
  else {
    local_34[0] = *(int *)(iVar2 + 0x5c);
    if (local_34[0] != 0) {
      uVar3 = *(int *)(local_34[0] + 0xc) - *(int *)(local_34[0] + 8) >> 3;
      if (uVar3 != 0) {
        do {
          local_34[3] = *(undefined4 *)(*(int *)(local_34[0] + 8) + uVar4 * 8);
          local_34[4] = (int)*(byte *)(*(int *)(local_34[0] + 8) + uVar4 * 8 + 4);
          FUN_005f84f0();
          uVar4 = uVar4 + 1;
        } while (uVar4 < uVar3);
      }
      if (param_2 == 0) {
        if ((DAT_00fe5ae4 & 1) == 0) {
          DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
          local_c = 2;
          FUN_00584c40(&DAT_00fe5ac4);
          _atexit((_func_4879 *)&LAB_00bcf390);
          local_c = 0xffffffff;
        }
        local_34[0] = 0x2c4;
        FUN_005740f0(local_34);
        if (local_38 == DAT_00fe5ac8) {
          pcVar1 = (code *)swi(3);
          (*pcVar1)();
          return;
        }
      }
      else {
        if ((DAT_00fe5ae4 & 1) == 0) {
          DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
          local_c = 1;
          FUN_00584c40(&DAT_00fe5ac4);
          _atexit((_func_4879 *)&LAB_00bcf390);
          local_c = 0xffffffff;
        }
        local_34[0] = 0x2c3;
        FUN_005740f0(local_34);
        if (local_38 == DAT_00fe5ac8) {
          pcVar1 = (code *)swi(3);
          (*pcVar1)();
          return;
        }
      }
      FUN_00757710();
      ExceptionList = local_14;
      return;
    }
    local_34[3] = *(undefined4 *)(iVar2 + 0x1c);
    local_34[4] = param_2;
    local_34[0] = 0x2c4;
    iVar2 = FUN_00585620();
    FUN_005740f0(local_34);
    if (local_38 == *(int *)(iVar2 + 4)) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    FUN_00757710();
  }
  FUN_005f84f0();
  ExceptionList = local_14;
  return;
}


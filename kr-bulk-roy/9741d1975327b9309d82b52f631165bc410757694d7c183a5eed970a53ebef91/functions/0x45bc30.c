
void FUN_0045bc30(int param_1)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  undefined4 in_EDX;
  undefined4 uVar4;
  int local_80;
  int local_7c;
  undefined1 local_78 [16];
  int local_68;
  int local_64;
  undefined4 local_60;
  uint local_4c;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00945116;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_80;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffff78;
  ExceptionList = &local_14;
  if ((*(int *)(*(int *)(param_1 + 0x100) + 0x2b0) == -1) ||
     (*(int *)(*(int *)(param_1 + 0x100) + 0x2b4) == -1)) {
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_c = 0;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
    }
    local_c = 0xffffffff;
    local_7c = 0x31e;
    FUN_005740f0(&local_7c);
    if (local_80 == DAT_00fe5ac8) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    if (*(uint *)(local_80 + 0x24) < 8) {
      FUN_0045b330(uVar2);
    }
    else {
      FUN_0045b330(uVar2);
    }
  }
  else {
    FUN_0045b670(local_78,in_EDX);
    local_c = 1;
    if ((local_68 == -1) || (local_64 == -1)) {
      local_80 = 0x1b2;
      iVar3 = FUN_005854b0();
      FUN_005740f0(&local_80);
      if (local_7c == *(int *)(iVar3 + 4)) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
    }
    else {
      local_80 = local_64;
      iVar3 = FUN_00459c20();
      FUN_008438c0(&local_80);
      if ((local_7c != *(int *)(iVar3 + 0x18)) && (0 < *(int *)(local_7c + 0x10))) {
        if (7 < local_4c) {
          FUN_0089120c(local_60);
        }
        goto LAB_0045bde1;
      }
      uVar4 = 0x1b2;
      FUN_005854b0(0x1b2);
      FUN_00585330(uVar4);
    }
    FUN_0045b330();
    if (7 < local_4c) {
      FUN_0089120c(local_60);
    }
  }
LAB_0045bde1:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_80);
  return;
}



void FUN_0047c760(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined1 uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint local_40;
  int local_3c;
  undefined4 local_38;
  undefined4 *local_34;
  int local_28;
  int local_24;
  undefined4 local_20;
  void *pvStack_18;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00947f22;
  local_14 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xffffffb0;
  ExceptionList = &local_14;
  if ((DAT_00fc0f64 & 1) == 0) {
    DAT_00fc0f64 = DAT_00fc0f64 | 1;
    local_c = 0;
    FUN_0047dce0(uVar4);
    _atexit(FUN_00bcdaf0);
  }
  local_c = 0xffffffff;
  local_40 = 0;
  if (DAT_00fc0f70 != 0) {
    do {
      FUN_008438c0(&local_40);
      if (local_3c != DAT_00fc0f6c) {
        puVar1 = *(undefined4 **)(local_3c + 0x10);
        if ((DAT_00fab29c & 1) == 0) {
          DAT_00fab29c = DAT_00fab29c | 1;
          local_c = 1;
          FUN_004ffe60();
          _atexit((_func_4879 *)&LAB_00bccf00);
          local_c = 0xffffffff;
        }
        FUN_00503440(&DAT_00fab2a0,&local_28,puVar1 + 9);
        local_c = 2;
        if ((local_24 - local_28 & 0xfffffffcU) != 0) {
          local_38 = *puVar1;
          local_34 = puVar1;
          uVar5 = FUN_0057ef20();
          FUN_0057e850(param_1 + 0x10c,uVar5);
        }
        local_c = 0xffffffff;
        if (local_28 != 0) {
          FUN_0089120c(local_28);
        }
        local_28 = 0;
        local_24 = 0;
        local_20 = 0;
      }
      local_40 = local_40 + 1;
    } while (local_40 < DAT_00fc0f70);
  }
  if ((DAT_00fc0f64 & 1) == 0) {
    DAT_00fc0f64 = DAT_00fc0f64 | 1;
    local_c = 3;
    FUN_0047dce0(uVar4);
    _atexit(FUN_00bcdaf0);
    local_c = 0xffffffff;
  }
  *(undefined4 *)(param_1 + 0x11c) = DAT_00fc0f78;
  FUN_0047d290(param_1);
  iVar2 = *(int *)(*(int *)(param_1 + 0xf8) + 0xcc);
  if (*(uint *)(param_1 + 0x11c) < *(uint *)(param_1 + 0x114)) {
    if (iVar2 != 0) {
      FUN_0042c8e0(*(uint *)(param_1 + 0x11c));
    }
  }
  else {
    if (iVar2 != 0) {
      FUN_0042c8e0(0);
    }
    *(undefined4 *)(param_1 + 0x11c) = 0;
  }
  FUN_0047cb00(param_1,*(undefined4 *)(param_1 + 0x11c));
  iVar2 = **(int **)(param_1 + 0x100);
  uVar3 = FUN_0047d610();
  (**(code **)(iVar2 + 0x90))(uVar3);
  ExceptionList = pvStack_18;
  return;
}


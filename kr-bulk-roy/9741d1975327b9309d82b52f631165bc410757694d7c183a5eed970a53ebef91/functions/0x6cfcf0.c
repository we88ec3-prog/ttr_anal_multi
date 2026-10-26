
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006cfcf0(int *param_1)

{
  HWND pHVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  undefined *puVar5;
  HWND pHVar6;
  int iVar7;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092699c;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((_DAT_00fc1a6c & 1) == 0) {
    _DAT_00fc1a6c = _DAT_00fc1a6c | 1;
    _atexit((_func_4879 *)&DAT_00bce3b0);
  }
  if ((DAT_00fc1724 & 1) == 0) {
    DAT_00fc1724 = DAT_00fc1724 | 1;
    local_8 = 0;
    FUN_006ccd20(uVar4);
    _atexit((_func_4879 *)&LAB_00bce3c0);
    local_8 = 0xffffffff;
  }
  iVar7 = DAT_00fb1318;
  puVar5 = DAT_00fc1738;
  if (DAT_00fc1738 == (undefined *)0x0) {
    puVar5 = &DAT_00fc173c;
  }
  param_1[1] = *(int *)(puVar5 + 0x38);
  pHVar1 = *(HWND *)(iVar7 + 0x10);
  pHVar6 = GetForegroundWindow();
  if (pHVar6 == pHVar1) {
    if ((DAT_00fc1724 & 1) == 0) {
      DAT_00fc1724 = DAT_00fc1724 | 1;
      local_8 = 1;
      FUN_006ccd20(uVar4);
      _atexit((_func_4879 *)&LAB_00bce3c0);
      local_8 = 0xffffffff;
    }
    piVar3 = DAT_00fc1800;
    piVar2 = (int *)*DAT_00fc1800;
    while (piVar2 != piVar3) {
      if (piVar2[5] == 0x26) {
        if (piVar2[4] != 0) {
          uVar4 = piVar2[4] - 9;
          if (DAT_00fba80c == 0) {
            iVar7 = FUN_00891268(0x57c);
            if (iVar7 == 0) {
              DAT_00fba80c = 0;
            }
            else {
              DAT_00fba80c = FUN_006f1370();
            }
          }
          if (((*(int *)(DAT_00fba80c + 0x20) != 0) && (uVar4 < 0x80)) &&
             (*(char *)(DAT_00fba80c + 0x3f8 + uVar4) == '\x01')) {
            if (*param_1 == 0) {
              *param_1 = 1;
              goto LAB_006cfde9;
            }
            if (*param_1 == 1) {
              *param_1 = 0;
              ExceptionList = local_10;
              return;
            }
          }
        }
        break;
      }
      FUN_00406870();
    }
    if (*param_1 != 0) {
LAB_006cfde9:
      FUN_006cfe80(param_1);
    }
  }
  ExceptionList = local_10;
  return;
}


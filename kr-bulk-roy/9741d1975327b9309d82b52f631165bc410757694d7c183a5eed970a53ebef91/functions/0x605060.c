
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_00605060(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c [2];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00943378;
  local_14 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffffd0;
  ExceptionList = &local_14;
  iVar4 = 0;
  piVar3 = &DAT_00fc7b74;
  do {
    if ((DAT_00fc1cbc & 1) == 0) {
      DAT_00fc1cbc = DAT_00fc1cbc | 1;
      local_c = 0;
      FUN_004fdac0(uVar1);
      _atexit(FUN_00bce150);
    }
    if ((((iVar4 / 7 == 0) && (piVar3 != (int *)0x4)) && (piVar3[5] != 0)) &&
       ((*piVar3 == param_1 && (uVar2 = 0, piVar3[1] == param_2)))) goto LAB_006051e8;
    piVar3 = piVar3 + 0x10;
    iVar4 = iVar4 + 1;
  } while ((int)piVar3 < 0xfc7d34);
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 1;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  uVar2 = param_1 - 1;
  if ((uVar2 == 0) && (uVar2 = param_1 * 0xca8 + 0xa50 + DAT_00f94300, uVar2 != 0)) {
    if (param_2 - 1U < 100) {
      iVar4 = param_2 * 0x20 + uVar2;
      if (((*(int *)(iVar4 + 0xc) != 0) && (*(int *)(iVar4 + 8) != 0)) && (iVar4 != 0)) {
        if ((DAT_00f8d9a4 & 1) == 0) {
          DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
          local_c = 2;
          FUN_0051c120();
          _atexit((_func_4879 *)&LAB_00bccc90);
        }
        local_c = 0xffffffff;
        local_24 = *(undefined4 *)(iVar4 + 0xc);
        FUN_008438c0(&local_24);
        if ((DAT_00fab0d8 & 1) == 0) {
          DAT_00fab0d8 = DAT_00fab0d8 | 1;
          local_c = 3;
          FUN_004dd4a0();
          DAT_00fab0ec = 0;
          _DAT_00fab0f0 = 0;
          _DAT_00fab0f4 = 0;
          _atexit((_func_4879 *)&LAB_00bccdb0);
          local_c = 0xffffffff;
        }
        local_24 = *(undefined4 *)(iVar4 + 0x10);
        local_20 = *(undefined4 *)(iVar4 + 0x14);
        FUN_004dd400(&DAT_00fab0dc,local_1c,&local_24);
        if (local_1c[0] == DAT_00fab0e0) {
          iVar4 = 0;
        }
        else {
          iVar4 = *(int *)(local_1c[0] + 0x18);
        }
        uVar2 = FUN_0051bfc0();
        if ((uVar2 == 0) && ((iVar4 == 0 || (*(char *)(iVar4 + 0x15) == '\0')))) {
          ExceptionList = local_14;
          return 1;
        }
      }
    }
    else {
      uVar2 = FUN_006edb60(&DAT_00c0ddc0);
    }
  }
LAB_006051e8:
  ExceptionList = local_14;
  return uVar2 & 0xffffff00;
}



/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006c2680(int param_1)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009423f8;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  FUN_006c68c0(DAT_00d61f20 ^ (uint)&stack0xffffffd8);
  FUN_006c6af0();
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  if (((((DAT_00f9392c == 3) || (DAT_00f9392c == 7)) || (DAT_00f9392c == 0x17)) ||
      ((DAT_00f9392c == 0x18 || (DAT_00f9392c == 5)))) || (DAT_00f9392c == 8)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((DAT_00fbad10 & 1) == 0) {
    DAT_00fbad10 = DAT_00fbad10 | 1;
    local_c = 1;
    FUN_004e8010();
    _atexit((_func_4879 *)&LAB_00bcd6b0);
    local_c = 0xffffffff;
  }
  if ((DAT_00fc0bd8 != 0) && (bVar1)) {
    if ((DAT_00fbad10 & 1) == 0) {
      DAT_00fbad10 = DAT_00fbad10 | 1;
      local_c = 2;
      FUN_004e8010();
      _atexit((_func_4879 *)&LAB_00bcd6b0);
      local_c = 0xffffffff;
    }
    uVar5 = DAT_00fc0bc8 - DAT_00fc0bc4 >> 2;
    uVar2 = 0;
    if (uVar5 != 0) {
      do {
        iVar3 = *(int *)(DAT_00fc0bc4 + uVar2 * 4);
        if (*(int *)(iVar3 + 4) == *(int *)(param_1 + 0xb4)) {
          if (iVar3 != 0) {
            if ((((*(char *)(iVar3 + 0x12) == '\0') &&
                 (iVar3 = FUN_0044fd50(), *(int *)(iVar3 + 0x5ec0) != 0)) &&
                (iVar3 = *(int *)(iVar3 + 0x5ebc), iVar3 != 0)) &&
               ((*(char *)(iVar3 + 0x12) != '\0' || ((*(byte *)(iVar3 + 0x14) & 2) != 0)))) {
              FUN_006c6ec0(param_1);
            }
            goto LAB_006c2830;
          }
          break;
        }
        uVar2 = uVar2 + 1;
      } while (uVar2 < uVar5);
    }
    iVar3 = FUN_0044fd50();
    if (((*(int *)(iVar3 + 0x5ec0) != 0) && (iVar3 = *(int *)(iVar3 + 0x5ebc), iVar3 != 0)) &&
       ((*(char *)(iVar3 + 0x12) != '\0' || ((*(byte *)(iVar3 + 0x14) & 4) != 0)))) {
      FUN_006c6da0();
    }
  }
LAB_006c2830:
  if ((DAT_00fb1378 & 1) == 0) {
    DAT_00fb1378 = DAT_00fb1378 | 1;
    local_c = 3;
    FUN_00539c20();
    _atexit((_func_4879 *)&LAB_00bccfb0);
    local_c = 0xffffffff;
  }
  if ((DAT_00fb7258 != 0) && (bVar1)) {
    iVar3 = FUN_00539aa0(*(undefined4 *)(param_1 + 0xb4));
    iVar4 = FUN_00404ba0();
    iVar4 = FUN_00539aa0(*(undefined4 *)(iVar4 + 0x5f50));
    if ((iVar3 == 0) || ((iVar4 == 0 || (*(char *)(iVar4 + 6) == '\0')))) {
      FUN_006c7040();
    }
    else {
      FUN_006c7160(param_1);
      FUN_006c72e0();
    }
  }
  FUN_006c7760();
  FUN_006c7f40();
  if ((_DAT_00fd94dc & 1) == 0) {
    _DAT_00fd94dc = _DAT_00fd94dc | 1;
    FUN_004f10f0();
    _atexit((_func_4879 *)&LAB_00bce260);
  }
  if ((DAT_00fdf3ac == 0) ||
     (iVar3 = DAT_00fdf3ac, *(int *)(DAT_00fdf3ac + 8) != *(int *)(param_1 + 0xb4))) {
    uVar5 = DAT_00fdf3b4 - DAT_00fdf3b0 >> 2;
    uVar2 = 0;
    if (uVar5 != 0) {
      do {
        iVar3 = *(int *)(DAT_00fdf3b0 + uVar2 * 4);
        if (*(int *)(iVar3 + 8) == *(int *)(param_1 + 0xb4)) goto LAB_006c2926;
        uVar2 = uVar2 + 1;
      } while (uVar2 < uVar5);
    }
  }
  else {
LAB_006c2926:
    if (iVar3 != 0) {
      ExceptionList = local_14;
      return;
    }
  }
  FUN_006c79a0(param_1);
  ExceptionList = local_14;
  return;
}


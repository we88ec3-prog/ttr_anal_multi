
void FUN_006b4bb0(int param_1)

{
  int *piVar1;
  int *piVar2;
  bool bVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  uint uVar8;
  int iStack_64;
  uint uStack_60;
  int iStack_5c;
  int local_58;
  uint uStack_54;
  undefined4 uStack_44;
  uint uStack_40;
  undefined4 local_38;
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093c09a;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&iStack_64;
  ExceptionList = &local_14;
  iVar7 = *(int *)(*(int *)(param_1 + 0xf8) + 0xcc);
  local_58 = param_1;
  if (iVar7 == 0) {
    iVar7 = -1;
  }
  else {
    iVar7 = *(int *)(iVar7 + 0xdc);
    if (iVar7 == 0) {
      iVar7 = -1;
    }
    else {
      iVar7 = *(int *)(iVar7 + 0x20);
    }
  }
  uVar8 = iVar7 + 1;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffff90);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  if (((uVar8 < 10) && (iVar7 = uVar8 * 0x210 + DAT_00f94304, *(int *)(iVar7 + 0x5c) != 0)) &&
     (iVar7 != 0)) {
    uVar4 = FUN_00483f00((&PTR_DAT_00d6a1c4)[uVar8]);
    local_c = 1;
    FUN_00757800(uVar4);
    local_c = 0xffffffff;
    if (7 < local_24) {
      FUN_0089120c(local_38);
    }
  }
  else {
    FUN_00757710();
  }
  (**(code **)(**(int **)(param_1 + 0xf4) + 200))();
  uStack_60 = 1;
  iStack_64 = 0x210;
  piVar6 = (int *)(param_1 + 0x120);
  iStack_5c = 9;
  do {
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 2;
      FUN_004e1590();
      _atexit((_func_4879 *)&LAB_00bccc80);
      local_c = 0xffffffff;
    }
    if (((uStack_60 < 10) && (iVar7 = iStack_64 + DAT_00f94304, *(int *)(iVar7 + 0x5c) != 0)) &&
       ((iVar7 != 0 && (*(int *)(iVar7 + 0x5c) != 0)))) {
      iVar7 = *piVar6;
      if (((*(char *)(iVar7 + 0xa4) != '\0') && (*(int *)(iVar7 + 0x94) != 0)) &&
         (iVar7 = (**(code **)(**(int **)(iVar7 + 0x94) + 4))(), iVar7 == 0xbf6b)) {
        FUN_0077b200();
      }
      (**(code **)(*(int *)*piVar6 + 200))();
      if ((DAT_00f94390 & 1) == 0) {
        DAT_00f94390 = DAT_00f94390 | 1;
        local_c = 3;
        FUN_004e1590();
        _atexit((_func_4879 *)&LAB_00bccc80);
        local_c = 0xffffffff;
      }
      uVar4 = FUN_0040ef80();
      local_c = 4;
      FUN_00757800(uVar4);
      local_c = 0xffffffff;
      if (7 < uStack_40) {
        FUN_0089120c(uStack_54);
      }
      uStack_54 = uStack_54 & 0xffff0000;
      uStack_40 = 7;
      uStack_44 = 0;
      (**(code **)(*(int *)piVar6[9] + 200))();
      iVar7 = 0;
      do {
        if ((int)*(char *)(local_58 + 0x1d8 + iVar7) == uStack_60) {
          bVar3 = true;
          goto LAB_006b4e7a;
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < 9);
      bVar3 = false;
LAB_006b4e7a:
      (**(code **)(*(int *)piVar6[-9] + 0x90))(!bVar3);
      uVar8 = *(uint *)(piVar6[-9] + 0x28);
      if ((uVar8 & 4) != 0) {
        *(uint *)(piVar6[-9] + 0x28) = uVar8 ^ 4;
      }
    }
    else {
      iVar7 = *piVar6;
      if (((*(char *)(iVar7 + 0xa4) != '\0') && (*(int *)(iVar7 + 0x94) != 0)) &&
         (iVar5 = (**(code **)(**(int **)(iVar7 + 0x94) + 4))(), iVar5 == 0xbf6b)) {
        iVar7 = *(int *)(iVar7 + 0x94);
        iVar5 = *(int *)(iVar7 + 0x10);
        if (iVar5 != 0) {
          piVar2 = *(int **)(iVar5 + 8);
          if (piVar2 != (int *)0x0) {
            piVar1 = piVar2 + 0x27;
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
              (**(code **)(*piVar2 + 0x28))();
            }
          }
          *(undefined4 *)(iVar7 + 0x10) = 0;
        }
      }
      (**(code **)(*(int *)*piVar6 + 200))();
      FUN_00757710();
      (**(code **)(*(int *)piVar6[9] + 200))();
      *(uint *)(piVar6[-9] + 0x28) = *(uint *)(piVar6[-9] + 0x28) | 4;
    }
    iStack_64 = iStack_64 + 0x210;
    uStack_60 = uStack_60 + 1;
    piVar6 = piVar6 + 1;
    iStack_5c = iStack_5c + -1;
    if (iStack_5c == 0) {
      ExceptionList = local_14;
      __security_check_cookie(local_1c ^ (uint)&iStack_64);
      return;
    }
  } while( true );
}


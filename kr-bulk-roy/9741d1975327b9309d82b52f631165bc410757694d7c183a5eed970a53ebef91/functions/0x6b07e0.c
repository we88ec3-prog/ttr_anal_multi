
void FUN_006b07e0(int param_1)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int *piVar8;
  int local_44;
  uint local_40;
  int local_3c;
  uint uStack_38;
  undefined4 uStack_28;
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093c1e2;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_44;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xffffffb0;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(uVar4);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  local_40 = 1;
  local_44 = 0x210;
  piVar8 = (int *)(param_1 + 0x144);
  local_3c = 9;
  do {
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 1;
      FUN_004e1590(uVar4);
      _atexit((_func_4879 *)&LAB_00bccc80);
      local_c = 0xffffffff;
    }
    if ((((local_40 < 10) && (iVar5 = DAT_00f94304 + local_44, *(int *)(iVar5 + 0x5c) != 0)) &&
        (iVar5 != 0)) && (*(int *)(iVar5 + 0x5c) != 0)) {
      iVar5 = *piVar8;
      if ((*(char *)(iVar5 + 0xa4) != '\0') && (*(int *)(iVar5 + 0x94) != 0)) {
        iVar5 = (**(code **)(**(int **)(iVar5 + 0x94) + 4))();
        if (iVar5 == 0xbf6b) {
          FUN_0077b200();
        }
      }
      (**(code **)(*(int *)*piVar8 + 200))();
      if ((DAT_00f94390 & 1) == 0) {
        DAT_00f94390 = DAT_00f94390 | 1;
        local_c = 2;
        FUN_004e1590();
        _atexit((_func_4879 *)&LAB_00bccc80);
        local_c = 0xffffffff;
      }
      uVar6 = FUN_0040ef80();
      local_c = 3;
      FUN_00757800(uVar6);
      local_c = 0xffffffff;
      if (7 < uStack_24) {
        FUN_0089120c(uStack_38);
      }
      uStack_38 = uStack_38 & 0xffff0000;
      uStack_24 = 7;
      uStack_28 = 0;
      (**(code **)(*(int *)piVar8[9] + 200))();
      (**(code **)(*(int *)piVar8[-0x12] + 0x90))(1);
      uVar2 = *(uint *)(piVar8[-0x12] + 0x28);
      if ((uVar2 & 4) != 0) {
        *(uint *)(piVar8[-0x12] + 0x28) = uVar2 ^ 4;
      }
    }
    else {
      iVar5 = *piVar8;
      if ((*(char *)(iVar5 + 0xa4) != '\0') && (*(int *)(iVar5 + 0x94) != 0)) {
        iVar7 = (**(code **)(**(int **)(iVar5 + 0x94) + 4))();
        if (iVar7 == 0xbf6b) {
          iVar5 = *(int *)(iVar5 + 0x94);
          iVar7 = *(int *)(iVar5 + 0x10);
          if (iVar7 != 0) {
            piVar3 = *(int **)(iVar7 + 8);
            if (piVar3 != (int *)0x0) {
              piVar1 = piVar3 + 0x27;
              *piVar1 = *piVar1 + -1;
              if (*piVar1 == 0) {
                (**(code **)(*piVar3 + 0x28))();
              }
            }
            *(undefined4 *)(iVar5 + 0x10) = 0;
          }
        }
      }
      (**(code **)(*(int *)*piVar8 + 200))();
      FUN_00757710();
      (**(code **)(*(int *)piVar8[9] + 200))();
      (**(code **)(*(int *)piVar8[-0x12] + 0x90))(0);
      *(uint *)(piVar8[-0x12] + 0x28) = *(uint *)(piVar8[-0x12] + 0x28) | 4;
    }
    local_44 = local_44 + 0x210;
    local_40 = local_40 + 1;
    piVar8 = piVar8 + 1;
    local_3c = local_3c + -1;
  } while (local_3c != 0);
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_44);
  return;
}


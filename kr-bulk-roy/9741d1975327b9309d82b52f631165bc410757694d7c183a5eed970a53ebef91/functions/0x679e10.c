
void FUN_00679e10(int param_1)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int local_44;
  int local_40;
  int local_3c;
  undefined4 local_38;
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093cc94;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_44;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffffb0;
  ExceptionList = &local_14;
  local_3c = param_1;
  local_44 = 0;
  iVar7 = 1;
  iVar8 = 0xca8;
  do {
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 0;
      FUN_004e1590(uVar2);
      _atexit((_func_4879 *)&LAB_00bccc80);
    }
    local_c = 0xffffffff;
    if (iVar7 == 1) {
      iVar3 = iVar8 + 0xa50 + DAT_00f94300;
    }
    else {
      iVar3 = 0;
    }
    iVar5 = *(int *)(iVar3 + 0xca0);
    iVar6 = 0;
    if (0 < iVar5) {
      piVar4 = (int *)(iVar3 + 0x28);
      do {
        if ((piVar4[1] == 0) && (*piVar4 == 0)) {
          iVar6 = iVar6 + 1;
        }
        piVar4 = piVar4 + 8;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
    local_44 = local_44 + iVar6;
    if (4 < local_44) goto LAB_00679fe5;
    iVar8 = iVar8 + 0xca8;
    iVar7 = iVar7 + 1;
  } while (iVar8 < 0x1950);
  if ((DAT_00fe5b2c & 1) == 0) {
    DAT_00fe5b2c = DAT_00fe5b2c | 1;
    local_c = 1;
    FUN_00584c40(&DAT_00fe5b0c);
    _atexit(FUN_00bcf370);
  }
  local_c = 0xffffffff;
  local_44 = 0xc2;
  FUN_005740f0(&local_44);
  if (local_40 == DAT_00fe5b10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  FUN_004068f0();
  iVar7 = local_3c;
  local_c = 2;
  FUN_00757710();
  (**(code **)(**(int **)(iVar7 + 0x120) + 0xd8))(0x3f800000);
  (**(code **)(**(int **)(iVar7 + 0x120) + 0x94))(1);
  (**(code **)(**(int **)(iVar7 + 0x120) + 200))();
  if (7 < uStack_24) {
    FUN_0089120c(local_38);
  }
LAB_00679fe5:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_44);
  return;
}



void FUN_0067fca0(undefined4 param_1)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int unaff_EDI;
  int local_84;
  int local_80;
  undefined4 local_7c;
  undefined1 local_78 [8];
  int local_70;
  int local_6c;
  int local_68;
  undefined4 local_64;
  undefined4 uStack_60;
  uint uStack_4c;
  undefined4 local_44;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  int local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00942d46;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_84;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffff78;
  ExceptionList = &local_14;
  FUN_0067f930(local_78,param_1);
  local_c = 0;
  if ((local_70 != -1) && (local_6c != -1)) {
    switch(local_44) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 0x11:
    case 0x12:
    case 0x13:
    case 0x1b:
    case 0x20:
    case 0x24:
    case 0x25:
    case 0x28:
    case 0x29:
    case 0x2a:
    case 0x2b:
      local_80 = local_68;
      local_7c = local_64;
      iVar3 = FUN_00409560(uVar2);
      FUN_004dd400(iVar3,&local_84,&local_80);
      if (((local_84 != *(int *)(iVar3 + 4)) && (iVar3 = *(int *)(local_84 + 0x18), iVar3 != 0)) &&
         (iVar4 = FUN_004dc9a0(), *(int *)(iVar3 + 0x48) - *(int *)(iVar3 + 0x44) >> 3 != iVar4)) {
        FUN_0067dea0();
        goto LAB_0067fe42;
      }
    }
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_c._0_1_ = 1;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_c = (uint)local_c._1_3_ << 8;
  }
  local_84 = 0x311;
  FUN_005740f0(&local_84);
  if (local_80 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  FUN_00757710();
  (**(code **)(**(int **)(unaff_EDI + 0x278) + 0x94))(1);
  (**(code **)(**(int **)(unaff_EDI + 0x278) + 0xd8))(0x3f800000);
  (**(code **)(**(int **)(unaff_EDI + 0x278) + 200))();
  if (7 < uStack_4c) {
    FUN_0089120c(uStack_60);
  }
LAB_0067fe42:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_84);
  return;
}


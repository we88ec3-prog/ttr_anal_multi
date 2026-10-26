
void FUN_00457ba0(int param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  undefined1 auStack_b0 [12];
  undefined4 uStack_a4;
  uint *puStack_a0;
  int *piStack_9c;
  uint uStack_98;
  uint uStack_94;
  undefined1 auStack_84 [4];
  int local_80;
  int local_7c;
  int *piStack_78;
  undefined1 *puStack_74;
  uint uStack_70;
  undefined4 uStack_60;
  uint uStack_5c;
  uint auStack_54 [4];
  undefined4 uStack_44;
  uint uStack_40;
  undefined4 uStack_38;
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0093187e;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_84;
  uStack_94 = DAT_00d61f20 ^ (uint)&stack0xffffff70;
  ExceptionList = &local_14;
  local_80 = *(int *)(param_1 + 0x160 + (uint)*(byte *)(DAT_00fc0c68 + 0x4a) * 4);
  iVar5 = DAT_00fc0c68 + 8;
  local_7c = iVar5;
  if ((*(char *)(*(int *)(param_1 + 0xf8) + 0xa4) != '\0') &&
     (piVar6 = *(int **)(*(int *)(param_1 + 0xf8) + 0x94), piVar6 != (int *)0x0)) {
    uStack_98 = 0x457c19;
    iVar2 = (**(code **)(*piVar6 + 4))();
    if (iVar2 == 0xbf6b) {
      uStack_98 = 0x457c2f;
      FUN_0077b200();
      iVar5 = local_7c;
    }
  }
  uStack_98 = 0x457c43;
  (**(code **)(**(int **)(param_1 + 0xf8) + 200))();
  puStack_74 = auStack_b0;
  FUN_00453d70(auStack_b0,*(undefined4 *)(iVar5 + 0x3e));
  uStack_c = 0;
  puVar3 = (undefined4 *)FUN_00412df0();
  if (7 < (uint)puVar3[5]) {
    puVar3 = (undefined4 *)*puVar3;
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    uStack_c._0_1_ = 2;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
  }
  uStack_c._0_1_ = 1;
  local_80 = 0x19;
  FUN_005740f0(&local_80);
  if (piStack_78 == (int *)DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  uStack_c._0_1_ = 3;
  uStack_98 = FUN_004796c0(puVar3);
  uStack_c = CONCAT31(uStack_c._1_3_,4);
  piStack_9c = (int *)0x457d28;
  FUN_00757800();
  if (7 < uStack_5c) {
    uStack_98 = uStack_70;
    piStack_9c = (int *)0x457d3d;
    FUN_0089120c();
  }
  uStack_c = 0xffffffff;
  uStack_5c = 7;
  uStack_60 = 0;
  uStack_70 = uStack_70 & 0xffff0000;
  if (7 < uStack_24) {
    uStack_98 = uStack_38;
    piStack_9c = (int *)0x457d72;
    FUN_0089120c();
  }
  uStack_98 = 0x457d85;
  (**(code **)(**(int **)(param_1 + 0xfc) + 200))();
  iVar5 = local_7c;
  puStack_74 = (undefined1 *)(local_7c + 4);
  uStack_98 = 0x457da1;
  FUN_00757710();
  uStack_98 = 0x457db1;
  (**(code **)(**(int **)(param_1 + 0x100) + 200))();
  uStack_98 = *(undefined4 *)(iVar5 + 0x36);
  piStack_9c = *(int **)(iVar5 + 0x32);
  puStack_a0 = auStack_54;
  uStack_a4 = 0x457dc3;
  FUN_00433f80();
  uStack_c = 5;
  uStack_98 = 0x457df0;
  FUN_00757710();
  uStack_c = 0xffffffff;
  if (7 < uStack_40) {
    uStack_98 = auStack_54[0];
    piStack_9c = (int *)0x457e0b;
    FUN_0089120c();
  }
  auStack_54[0] = auStack_54[0] & 0xffff0000;
  iVar5 = 0;
  uStack_40 = 7;
  uStack_44 = 0;
  uStack_98 = 0x457e33;
  (**(code **)(**(int **)(param_1 + 0x104) + 200))();
  local_80 = 0;
  do {
    if (2 < iVar5) break;
    if ((1 << ((byte)local_80 & 0x1f) & (int)*(short *)(local_7c + 0x30)) != 0) {
      iVar2 = *(int *)(*(int *)(param_1 + 0x108) + 0xcc);
      if (((iVar2 == 0) || (iVar5 < 0)) ||
         (*(int *)(iVar2 + 0xac) - *(int *)(iVar2 + 0xa8) >> 2 <= iVar5)) {
        piVar6 = (int *)0x0;
      }
      else {
        piVar6 = *(int **)(*(int *)(iVar2 + 0xa8) + iVar5 * 4);
      }
      puStack_a0 = (uint *)0x457e94;
      piStack_9c = piVar6;
      uStack_98 = local_80;
      FUN_004527f0();
      uStack_98 = 0x457ea0;
      (**(code **)(*piVar6 + 200))();
      iVar5 = iVar5 + 1;
    }
    local_80 = local_80 + 1;
  } while (local_80 < 10);
  piVar6 = *(int **)(param_1 + 0x108);
  piVar4 = (int *)piVar6[0x19];
  piVar7 = (int *)*piVar4;
  piStack_78 = piVar4;
  if (piVar7 != piVar4) {
    do {
      uStack_98 = piVar7[2];
      if ((*(int *)(uStack_98 + 0x60) != 0) && ((*(int **)(uStack_98 + 0x1c))[2] != 6)) {
        piStack_9c = (int *)0x457edc;
        (**(code **)(**(int **)(uStack_98 + 0x1c) + 0x30))();
        piVar4 = piStack_78;
      }
      piVar7 = (int *)*piVar7;
    } while (piVar7 != piVar4);
  }
  uStack_98 = 0x457ef2;
  (**(code **)(*piVar6 + 0x128))();
  uStack_98 = 0x457f02;
  (**(code **)(**(int **)(param_1 + 0x108) + 200))();
  uStack_98 = 0;
  piStack_9c = (int *)0x457f19;
  FUN_00759ac0();
  uStack_98 = 0x457f2b;
  (**(code **)(**(int **)(param_1 + 0xf4) + 200))();
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_84);
  return;
}


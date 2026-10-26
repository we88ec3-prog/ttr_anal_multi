
void FUN_0064b240(int param_1)

{
  short sVar1;
  undefined4 uVar2;
  undefined1 uVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  short *psVar7;
  undefined4 in_ECX;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined4 local_e0;
  undefined4 local_d0;
  uint local_cc;
  short local_c0;
  undefined1 local_be [150];
  uint uStack_28;
  void *pvStack_20;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00941e27;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&uStack_f4;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xffffff00;
  ExceptionList = &local_14;
  uVar3 = FUN_004a7810(in_ECX);
  uStack_f0 = (undefined4 *)CONCAT13(uVar3,(undefined3)uStack_f0);
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(uVar4);
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  uVar4 = (uint)uStack_f0 >> 0x18;
  iVar5 = FUN_004d43d0();
  if (iVar5 < (int)uVar4) {
    puVar6 = (undefined4 *)FUN_004a78b0(in_ECX);
    if (7 < (uint)puVar6[5]) {
      puVar6 = (undefined4 *)*puVar6;
    }
    FUN_0041c010(L"<#FF0000>Lv.%02d</#> %s",uVar4,puVar6);
    if (7 < local_cc) {
      FUN_0089120c(local_e0);
    }
    *(undefined1 *)(param_1 + 0x260) = 0;
  }
  else {
    puVar6 = (undefined4 *)FUN_004a78b0(in_ECX);
    if (7 < (uint)puVar6[5]) {
      puVar6 = (undefined4 *)*puVar6;
    }
    FUN_0041c010(L"<#FFC000>Lv.%02d</#> %s",uVar4,puVar6);
    if (7 < local_cc) {
      FUN_0089120c(local_e0);
    }
    *(undefined1 *)(param_1 + 0x260) = 1;
  }
  psVar7 = &local_c0;
  local_e0 = (uint)local_e0._2_2_ << 0x10;
  local_cc = 7;
  local_d0 = 0;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(&local_c0,(int)psVar7 - (int)local_be >> 1);
  iVar5 = *(int *)(param_1 + 0x254);
  local_c = 1;
  FUN_007578f0();
  FUN_00759ed0(iVar5 + 0xe8,&local_e0,0x7b,0x7d);
  local_c = 0xffffffff;
  if (7 < local_cc) {
    FUN_0089120c(local_e0);
  }
  (**(code **)(**(int **)(param_1 + 0x254) + 200))();
  uStack_ec = CONCAT31(uStack_ec._1_3_,*(char *)(param_1 + 0x260) == '\0');
  uVar2 = uStack_ec;
  (**(code **)(**(int **)(param_1 + 0x250) + 0x94))(uStack_ec);
  (**(code **)(**(int **)(param_1 + 0x250) + 200))();
  (**(code **)(**(int **)(param_1 + 600) + 0x94))(uVar2);
  (**(code **)(**(int **)(param_1 + 600) + 200))();
  if ((DAT_00f94394 & 1) == 0) {
    DAT_00f94394 = DAT_00f94394 | 1;
    local_14 = (void *)0x2;
    FUN_005c3de0();
    _atexit((_func_4879 *)&LAB_00bccc30);
    local_14 = (void *)0xffffffff;
  }
  uStack_f4 = *uStack_f0;
  FUN_0082ef00(&uStack_f4);
  iVar5 = *(int *)(param_1 + 0x248);
  if (((*(char *)(iVar5 + 0xa4) != '\0') && (*(int *)(iVar5 + 0x94) != 0)) &&
     (iVar5 = (**(code **)(**(int **)(iVar5 + 0x94) + 4))(), iVar5 == 0xbf6b)) {
    FUN_0077b200();
  }
  (**(code **)(**(int **)(param_1 + 0x248) + 200))();
  puVar6 = uStack_f0;
  (**(code **)(**(int **)(param_1 + 0x24c) + 0x94))(*(undefined1 *)((int)uStack_f0 + 9));
  (**(code **)(**(int **)(param_1 + 0x24c) + 200))();
  *(undefined4 *)(param_1 + 0x25c) = *puVar6;
  ExceptionList = pvStack_20;
  __security_check_cookie(uStack_28 ^ (uint)&stack0xffffff00);
  return;
}


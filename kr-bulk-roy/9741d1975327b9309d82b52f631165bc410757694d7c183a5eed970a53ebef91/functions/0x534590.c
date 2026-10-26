
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_00534590(int param_1,int *param_2)

{
  short sVar1;
  code *pcVar2;
  undefined4 *puVar3;
  short *psVar4;
  int *piVar5;
  int *piVar6;
  short *psVar7;
  int iVar8;
  uint uVar9;
  int *piVar10;
  int local_1020;
  undefined2 local_101c;
  undefined1 local_101a;
  int local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092f4f7;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar9 = 0;
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 0;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
  }
  local_8 = 0xffffffff;
  puVar3 = (undefined4 *)FUN_00891268();
  if (puVar3 != (undefined4 *)0x0) {
    *puVar3 = FoxUI::FXUIEvent::vftable;
    puVar3[1] = 0xffffffff;
    puVar3[2] = 0xffffffff;
    puVar3[3] = 0;
    puVar3[4] = 0xf4443;
  }
  FUN_00402160();
  local_8 = 1;
  if ((DAT_00fe5b2c & 1) == 0) {
    DAT_00fe5b2c = DAT_00fe5b2c | 1;
    local_8._0_1_ = 2;
    local_8._1_3_ = 0;
    FUN_00584c40();
    _atexit(FUN_00bcf370);
    local_8 = CONCAT31(local_8._1_3_,1);
  }
  FUN_005740f0();
  if (local_1020 == DAT_00fe5b10) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  psVar7 = (short *)(local_1020 + 0x10);
  if (7 < *(uint *)(local_1020 + 0x24)) {
    psVar7 = *(short **)psVar7;
  }
  psVar4 = psVar7;
  do {
    sVar1 = *psVar4;
    psVar4 = psVar4 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar7,(int)psVar4 - (int)(psVar7 + 1) >> 1);
  local_8 = 0xffffffff;
  FUN_0058b270(199);
  piVar5 = *(int **)(param_1 + 0x30);
  piVar6 = (int *)*piVar5;
  piVar10 = (int *)(param_1 + 0x30);
  *piVar5 = (int)piVar5;
  *(int *)(*piVar10 + 4) = *piVar10;
  *(undefined4 *)(param_1 + 0x34) = 0;
  if (piVar6 != (int *)*piVar10) {
    do {
      piVar6 = (int *)*piVar6;
      FUN_0089120c();
    } while (piVar6 != (int *)*piVar10);
  }
  if (piVar10 != param_2) {
    FUN_00404d90();
  }
  local_101a = 1;
  if (*(uint *)(param_1 + 0x34) < 0x79) {
    local_101a = 3;
  }
  local_101c = 0xbd2;
  iVar8 = 3;
  local_1c = 3;
  piVar5 = *(int **)*piVar10;
  if (piVar5 != (int *)*piVar10) {
    do {
      if (0x78 < uVar9) break;
      if (iVar8 + 4U < 0x1001) {
        *(int *)((int)&local_101c + iVar8) = piVar5[2];
        iVar8 = local_1c + 4;
        local_1c = iVar8;
      }
      piVar6 = (int *)*piVar5;
      if (piVar5 != (int *)*piVar10) {
        *(int **)piVar5[1] = piVar6;
        *(int *)(*piVar5 + 4) = piVar5[1];
        FUN_0089120c();
        *(int *)(param_1 + 0x34) = *(int *)(param_1 + 0x34) + -1;
        iVar8 = local_1c;
      }
      uVar9 = uVar9 + 1;
      piVar5 = piVar6;
    } while (piVar6 != (int *)*piVar10);
  }
  (**(code **)(*DAT_00fba854 + 0x10))();
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


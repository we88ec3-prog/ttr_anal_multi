
/* WARNING: Removing unreachable block (ram,0x005774bf) */
/* WARNING: Removing unreachable block (ram,0x0057742e) */
/* WARNING: Removing unreachable block (ram,0x00577534) */
/* WARNING: Removing unreachable block (ram,0x00577537) */

void FUN_00577320(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int unaff_ESI;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091fe02;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar2 = *(int *)(unaff_ESI + 0x14 + param_1 * 0x1c);
  iVar1 = unaff_ESI + param_1 * 0x1c;
  *(undefined4 *)(iVar1 + 0x1c) = 0;
  *(float *)(iVar1 + 0x18) = (float)iVar2 * 64.0 + 49.0;
  if (*(int *)(unaff_ESI + 0x108) != 0) {
    *(undefined4 *)(unaff_ESI + 200) = *(undefined4 *)(**(int **)(unaff_ESI + 0x104) + 8);
    piVar4 = (int *)**(int **)(unaff_ESI + 0x104);
    if (piVar4 != *(int **)(unaff_ESI + 0x104)) {
      *(int *)piVar4[1] = *piVar4;
      *(int *)(*piVar4 + 4) = piVar4[1];
      FUN_0089120c(piVar4,uVar3);
      *(int *)(unaff_ESI + 0x108) = *(int *)(unaff_ESI + 0x108) + -1;
    }
    FUN_0040b310("LUCKYBOX_IMAGESTOP");
    local_8 = 0;
    if ((DAT_00fab0d4 & 1) == 0) {
      DAT_00fab0d4 = DAT_00fab0d4 | 1;
      local_8._0_1_ = 1;
      local_8._1_3_ = 0;
      FUN_0080a3a0();
      _atexit((_func_4879 *)&LAB_00bccdd0);
      local_8 = (uint)local_8._1_3_ << 8;
    }
    piVar4 = (int *)FUN_0080ab00(&DAT_00fab028);
    if (piVar4 != (int *)0x0) {
      (**(code **)(*piVar4 + 0x14))();
    }
    local_8 = 0xffffffff;
    if (*(int *)(unaff_ESI + 0x108) != 0) goto LAB_00577540;
  }
  local_8 = 0xffffffff;
  if (*(int *)(unaff_ESI + 0x74) == 0) {
    FUN_0040b310("LUCKYBOX_INCORRENT");
    local_8 = 4;
    if ((DAT_00fab0d4 & 1) == 0) {
      DAT_00fab0d4 = DAT_00fab0d4 | 1;
      local_8._0_1_ = 5;
      local_8._1_3_ = 0;
      FUN_0080a3a0();
      _atexit((_func_4879 *)&LAB_00bccdd0);
      local_8 = CONCAT31(local_8._1_3_,4);
    }
    piVar4 = (int *)FUN_0080ab00(&DAT_00fab028);
    if (piVar4 != (int *)0x0) {
      (**(code **)(*piVar4 + 0x14))();
    }
  }
  else {
    FUN_0040b310("LUCKYBOX_CORRENT");
    local_8 = 2;
    if ((DAT_00fab0d4 & 1) == 0) {
      DAT_00fab0d4 = DAT_00fab0d4 | 1;
      local_8._0_1_ = 3;
      local_8._1_3_ = 0;
      FUN_0080a3a0();
      _atexit((_func_4879 *)&LAB_00bccdd0);
      local_8 = CONCAT31(local_8._1_3_,2);
    }
    piVar4 = (int *)FUN_0080ab00(&DAT_00fab028);
    if (piVar4 != (int *)0x0) {
      (**(code **)(*piVar4 + 0x14))();
    }
  }
LAB_00577540:
  ExceptionList = local_10;
  __security_check_cookie(uVar3 ^ (uint)&stack0xfffffffc);
  return;
}



void FUN_007572f0(short *param_1)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  short *psVar4;
  undefined2 *unaff_ESI;
  undefined **local_70 [3];
  undefined **local_60 [3];
  char *local_54;
  char *local_50;
  undefined4 local_4c;
  undefined4 local_3c;
  uint local_38;
  undefined4 local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00928830;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(unaff_ESI + 10) = 7;
  *(undefined4 *)(unaff_ESI + 8) = 0;
  *unaff_ESI = 0;
  local_8 = 0;
  *(undefined4 *)(unaff_ESI + 0x10) = 0;
  local_14 = uVar2;
  iVar3 = FUN_00891268(0x10,uVar2);
  if (iVar3 == 0) {
    local_50 = (char *)0x0;
    std::exception::exception((exception *)local_70,&local_50);
    local_70[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_70,&DAT_00c857a8);
  }
  *(int *)(unaff_ESI + 0xe) = iVar3;
  *(int *)iVar3 = iVar3;
  *(int *)(*(int *)(unaff_ESI + 0xe) + 4) = *(int *)(unaff_ESI + 0xe);
  local_8._0_1_ = 1;
  *(undefined4 *)(unaff_ESI + 0x18) = 0;
  iVar3 = FUN_00891268(0x24,uVar2);
  if (iVar3 != 0) {
    *(int *)(unaff_ESI + 0x16) = iVar3;
    *(int *)iVar3 = iVar3;
    *(int *)(*(int *)(unaff_ESI + 0x16) + 4) = *(int *)(unaff_ESI + 0x16);
    *(int *)(*(int *)(unaff_ESI + 0x16) + 8) = *(int *)(unaff_ESI + 0x16);
    *(undefined1 *)(*(int *)(unaff_ESI + 0x16) + 0x20) = 1;
    *(undefined1 *)(*(int *)(unaff_ESI + 0x16) + 0x21) = 1;
    local_8._0_1_ = 2;
    psVar4 = param_1;
    do {
      sVar1 = *psVar4;
      psVar4 = psVar4 + 1;
    } while (sVar1 != 0);
    FUN_00402160(param_1,(int)psVar4 - (int)(param_1 + 1) >> 1);
    FUN_00757940(unaff_ESI,0x7b,0x7d);
    local_38 = 7;
    local_3c = 0;
    local_4c = (uint)local_4c._2_2_ << 0x10;
    FUN_00402160(&DAT_00bfb894,1);
    local_8._0_1_ = 3;
    local_30 = (uint)local_30._2_2_ << 0x10;
    local_1c = 7;
    local_20 = 0;
    FUN_00402160(&DAT_00c059b8,2);
    local_8 = CONCAT31(local_8._1_3_,4);
    FUN_00759330(unaff_ESI,&local_30,&local_4c);
    if (7 < local_1c) {
      FUN_0089120c(local_30);
    }
    local_1c = 7;
    local_20 = 0;
    local_30 = local_30 & 0xffff0000;
    if (7 < local_38) {
      FUN_0089120c(local_4c);
    }
    ExceptionList = local_10;
    __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
    return;
  }
  local_54 = (char *)0x0;
  std::exception::exception((exception *)local_60,&local_54);
  local_60[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_60,&DAT_00c857a8);
}


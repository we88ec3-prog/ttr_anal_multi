
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0063f9e0(void)

{
  short sVar1;
  undefined4 uVar2;
  code *pcVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  short *psVar7;
  short *psVar8;
  int in_ECX;
  uint uVar9;
  int iVar10;
  int iVar11;
  int local_38;
  uint local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093b7fc;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar5 = *(uint *)(*(int *)(in_ECX + 0x110) + 0x28);
  if (((uVar5 >> 8 & 1) == 0) || ((uVar5 >> 9 & 1) == 0)) {
    iVar10 = *(int *)(*(int *)(in_ECX + 0xfc) + 0xcc);
    if ((iVar10 != 0) &&
       ((iVar10 = *(int *)(iVar10 + 0xdc), iVar10 != 0 &&
        (iVar11 = -1, *(int *)(iVar10 + 0x20) != -1)))) {
      iVar10 = *(int *)(*(int *)(in_ECX + 0xfc) + 0xcc);
      if (iVar10 != 0) {
        iVar10 = *(int *)(iVar10 + 0xdc);
        if (iVar10 == 0) {
          iVar11 = -1;
        }
        else {
          iVar11 = *(int *)(iVar10 + 0x20);
        }
      }
      if ((_DAT_00fd94dc & 1) == 0) {
        _DAT_00fd94dc = _DAT_00fd94dc | 1;
        FUN_004f10f0();
        _atexit((_func_4879 *)&LAB_00bce260);
      }
      uVar9 = DAT_00fdf3b4 - DAT_00fdf3b0 >> 2;
      uVar5 = 0;
      if (uVar9 != 0) {
        do {
          iVar10 = *(int *)(DAT_00fdf3b0 + uVar5 * 4);
          if (*(int *)(iVar10 + 8) == iVar11) goto LAB_0063faf5;
          uVar5 = uVar5 + 1;
        } while (uVar5 < uVar9);
      }
    }
  }
  else {
    iVar10 = DAT_00fdf3ac;
    if ((_DAT_00fd94dc & 1) == 0) {
      _DAT_00fd94dc = _DAT_00fd94dc | 1;
      FUN_004f10f0();
      _atexit((_func_4879 *)&LAB_00bce260);
      iVar10 = DAT_00fdf3ac;
    }
LAB_0063faf5:
    if (iVar10 != 0) {
      if ((DAT_00faadd4 & 1) == 0) {
        DAT_00faadd4 = DAT_00faadd4 | 1;
        local_8 = 0;
        FUN_00587480();
        _atexit((_func_4879 *)&LAB_00bcccc0);
        local_8 = 0xffffffff;
      }
      puVar6 = (undefined4 *)FUN_00891268();
      if (puVar6 != (undefined4 *)0x0) {
        uVar2 = *(undefined4 *)(iVar10 + 8);
        puVar6[1] = 0xffffffff;
        puVar6[2] = 0xffffffff;
        puVar6[3] = 0;
        puVar6[4] = 0xf43c5;
        *puVar6 = FoxUI::FXUIEventI1::vftable;
        puVar6[5] = uVar2;
      }
      FUN_00402160();
      local_8._1_3_ = 0;
      if ((DAT_00fe5b2c & 1) == 0) {
        DAT_00fe5b2c = DAT_00fe5b2c | 1;
        local_8._0_1_ = 2;
        local_8._1_3_ = 0;
        FUN_00584c40();
        _atexit(FUN_00bcf370);
      }
      local_8._0_1_ = 1;
      FUN_005740f0();
      if (local_38 == DAT_00fe5b10) {
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      psVar7 = (short *)FUN_004ed610();
      local_8._0_1_ = 3;
      if (7 < *(uint *)(psVar7 + 10)) {
        psVar7 = *(short **)psVar7;
      }
      psVar8 = psVar7;
      do {
        sVar1 = *psVar8;
        psVar8 = psVar8 + 1;
      } while (sVar1 != 0);
      FUN_00402160(psVar7,(int)psVar8 - (int)(psVar7 + 1) >> 1);
      local_8 = CONCAT31(local_8._1_3_,4);
      FUN_0058b270(0xcf);
      if (7 < local_1c) {
        FUN_0089120c();
      }
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(uVar4 ^ (uint)&stack0xfffffffc);
  return;
}


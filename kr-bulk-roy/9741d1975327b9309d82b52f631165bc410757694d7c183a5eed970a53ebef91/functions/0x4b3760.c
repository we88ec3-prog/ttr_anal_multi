
void FUN_004b3760(int param_1)

{
  ushort uVar1;
  short sVar2;
  code *pcVar3;
  int iVar4;
  short *psVar5;
  short *psVar6;
  int *piVar7;
  undefined4 uVar8;
  undefined2 local_a4 [8];
  undefined4 local_94;
  short *local_90;
  undefined1 **ppuStack_8c;
  undefined2 local_88 [8];
  undefined4 local_78;
  undefined4 local_74;
  int *piStack_70;
  undefined4 uStack_6c;
  int local_58;
  undefined1 *local_54;
  undefined1 *local_50;
  uint local_4c;
  undefined4 local_3c;
  uint local_38;
  uint local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00930d24;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar1 = *(ushort *)(param_1 + 2);
  if ((uVar1 & 0x10) == 0) {
    if ((uVar1 & 8) == 0) goto LAB_004b3be9;
    if ((uVar1 & 1) != 0) {
      FUN_004054c0();
      uStack_6c = 0;
      piStack_70 = (int *)0x196;
      local_74 = 0x4b3a67;
      FUN_005854b0();
      local_74 = 0x4b3a6e;
      ppuStack_8c = (undefined1 **)FUN_00585330();
      local_54 = (undefined1 *)local_88;
      local_90 = (short *)0x4b3a7c;
      FUN_00402250();
      ppuStack_8c = (undefined1 **)0xe1;
      local_8 = 8;
      local_90 = (short *)0x4b3a8d;
      FUN_005854b0();
      local_90 = (short *)0x4b3a94;
      uVar8 = FUN_00585330();
      local_50 = (undefined1 *)local_a4;
      FUN_00402250(uVar8);
      local_8 = 0xffffffff;
      FUN_0058b270(0xca);
      local_38 = 0xf;
      local_3c = 0;
      local_4c = local_4c & 0xffffff00;
      uStack_6c = 0x4b3ad6;
      FUN_0040b310();
      local_8 = 9;
      FUN_0040b3f0();
      uStack_6c = 0x4b3aeb;
      piVar7 = (int *)FUN_0080ab00();
      if (piVar7 != (int *)0x0) {
        (**(code **)(*piVar7 + 0x14))();
      }
      if (0xf < local_38) {
        uStack_6c = 0x4b3b0b;
        FUN_0089120c();
      }
      goto LAB_004b3be9;
    }
    if ((uVar1 & 0x20) == 0) {
      if ((uVar1 & 0x40) == 0) {
        FUN_004054c0();
        uStack_6c = 0;
        piStack_70 = (int *)0x196;
        local_74 = 0x4b3b9a;
        FUN_005854b0();
        local_74 = 0x4b3ba1;
        ppuStack_8c = (undefined1 **)FUN_00585330();
        local_54 = (undefined1 *)local_88;
        local_90 = (short *)0x4b3baf;
        FUN_00402250();
        local_8 = 0xc;
        ppuStack_8c = (undefined1 **)0xe2;
      }
      else {
        FUN_004054c0();
        uStack_6c = 0;
        piStack_70 = (int *)0x196;
        local_74 = 0x4b3b64;
        FUN_005854b0();
        local_74 = 0x4b3b6b;
        ppuStack_8c = (undefined1 **)FUN_00585330();
        local_54 = (undefined1 *)local_88;
        local_90 = (short *)0x4b3b79;
        FUN_00402250();
        local_8 = 0xb;
        ppuStack_8c = (undefined1 **)0xe8;
      }
    }
    else {
      FUN_004054c0();
      uStack_6c = 0;
      piStack_70 = (int *)0x196;
      local_74 = 0x4b3b2a;
      FUN_005854b0();
      local_74 = 0x4b3b31;
      ppuStack_8c = (undefined1 **)FUN_00585330();
      local_54 = (undefined1 *)local_88;
      local_90 = (short *)0x4b3b3f;
      FUN_00402250();
      local_8 = 10;
      ppuStack_8c = (undefined1 **)0xe3;
    }
  }
  else {
    if ((uVar1 & 1) != 0) {
      if ((DAT_00faadd4 & 1) == 0) {
        DAT_00faadd4 = DAT_00faadd4 | 1;
        local_8 = 0;
        FUN_00587480();
        uStack_6c = 0x4b37c7;
        _atexit((_func_4879 *)&LAB_00bcccc0);
      }
      local_8 = 0xffffffff;
      uStack_6c = 0;
      local_58 = 0x196;
      piStack_70 = (int *)0x4b37e1;
      iVar4 = FUN_005854b0();
      piStack_70 = &local_58;
      local_74 = 0x4b37f1;
      FUN_005740f0();
      if (local_50 == *(undefined1 **)(iVar4 + 4)) {
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      local_90 = (short *)(local_50 + 0x10);
      if (7 < *(uint *)(local_50 + 0x24)) {
        local_90 = *(short **)local_90;
      }
      local_54 = (undefined1 *)local_88;
      local_74 = 7;
      local_78 = 0;
      local_88[0] = 0;
      psVar5 = local_90;
      do {
        sVar2 = *psVar5;
        psVar5 = psVar5 + 1;
      } while (sVar2 != 0);
      ppuStack_8c = (undefined1 **)((int)psVar5 - (int)(local_90 + 1) >> 1);
      local_94 = 0x4b3846;
      FUN_00402160();
      local_8 = 1;
      local_50 = (undefined1 *)0xdf;
      ppuStack_8c = (undefined1 **)0x4b3859;
      iVar4 = FUN_005854b0();
      ppuStack_8c = &local_50;
      local_90 = (short *)0x4b3869;
      FUN_005740f0();
      if (local_58 == *(int *)(iVar4 + 4)) {
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      psVar5 = (short *)(local_58 + 0x10);
      if (7 < *(uint *)(local_58 + 0x24)) {
        psVar5 = *(short **)psVar5;
      }
      local_50 = (undefined1 *)local_a4;
      local_90 = (short *)0x7;
      local_94 = 0;
      local_a4[0] = 0;
      psVar6 = psVar5;
      do {
        sVar2 = *psVar6;
        psVar6 = psVar6 + 1;
      } while (sVar2 != 0);
      FUN_00402160(psVar5,(int)psVar6 - (int)(psVar5 + 1) >> 1);
      local_8 = 0xffffffff;
      FUN_0058b270(0xca);
      local_1c = 0xf;
      local_20 = 0;
      local_30 = local_30 & 0xffffff00;
      uStack_6c = 0x4b38f4;
      FUN_0040b310();
      local_8 = 2;
      if ((DAT_00fab0d4 & 1) == 0) {
        DAT_00fab0d4 = DAT_00fab0d4 | 1;
        local_8._0_1_ = 3;
        local_8._1_3_ = 0;
        FUN_0080a3a0();
        uStack_6c = 0x4b391e;
        _atexit((_func_4879 *)&LAB_00bccdd0);
        local_8 = CONCAT31(local_8._1_3_,2);
      }
      uStack_6c = 0x4b3932;
      piVar7 = (int *)FUN_0080ab00();
      if (piVar7 != (int *)0x0) {
        (**(code **)(*piVar7 + 0x14))();
      }
      if (0xf < local_1c) {
        uStack_6c = 0x4b3952;
        FUN_0089120c();
      }
      goto LAB_004b3be9;
    }
    if ((uVar1 & 2) == 0) {
      if ((uVar1 & 4) == 0) {
        if ((uVar1 & 0x40) == 0) {
          FUN_004054c0();
          uStack_6c = 0;
          piStack_70 = (int *)0x196;
          local_74 = 0x4b3a1e;
          FUN_005854b0();
          local_74 = 0x4b3a25;
          ppuStack_8c = (undefined1 **)FUN_00585330();
          local_54 = (undefined1 *)local_88;
          local_90 = (short *)0x4b3a33;
          FUN_00402250();
          local_8 = 7;
          ppuStack_8c = (undefined1 **)0xe0;
        }
        else {
          FUN_004054c0();
          uStack_6c = 0;
          piStack_70 = (int *)0x196;
          local_74 = 0x4b39e5;
          FUN_005854b0();
          local_74 = 0x4b39ec;
          ppuStack_8c = (undefined1 **)FUN_00585330();
          local_54 = (undefined1 *)local_88;
          local_90 = (short *)0x4b39fa;
          FUN_00402250();
          local_8 = 6;
          ppuStack_8c = (undefined1 **)0xe8;
        }
      }
      else {
        FUN_004054c0();
        uStack_6c = 0;
        piStack_70 = (int *)0x196;
        local_74 = 0x4b39ab;
        FUN_005854b0();
        local_74 = 0x4b39b2;
        ppuStack_8c = (undefined1 **)FUN_00585330();
        local_54 = (undefined1 *)local_88;
        local_90 = (short *)0x4b39c0;
        FUN_00402250();
        local_8 = 5;
        ppuStack_8c = (undefined1 **)0x7;
      }
    }
    else {
      FUN_004054c0();
      uStack_6c = 0;
      piStack_70 = (int *)0x196;
      local_74 = 0x4b3971;
      FUN_005854b0();
      local_74 = 0x4b3978;
      ppuStack_8c = (undefined1 **)FUN_00585330();
      local_54 = (undefined1 *)local_88;
      local_90 = (short *)0x4b3986;
      FUN_00402250();
      local_8 = 4;
      ppuStack_8c = (undefined1 **)0xf;
    }
  }
  local_90 = (short *)0x4b3bc0;
  FUN_005854b0();
  local_90 = (short *)0x4b3bc7;
  uVar8 = FUN_00585330();
  local_50 = (undefined1 *)local_a4;
  FUN_00402250(uVar8);
  local_8 = 0xffffffff;
  FUN_0058b270(0xca);
LAB_004b3be9:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


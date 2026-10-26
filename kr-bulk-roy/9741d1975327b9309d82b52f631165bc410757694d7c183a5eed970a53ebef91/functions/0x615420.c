
void FUN_00615420(int param_1)

{
  int *piVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  int *in_ECX;
  int iVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined1 auStack_10c [20];
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  undefined1 auStack_f0 [12];
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined1 *puStack_dc;
  undefined1 *puStack_d8;
  undefined4 *puStack_d4;
  undefined1 auStack_bc [4];
  int local_b8;
  int *local_b4;
  undefined1 *local_b0;
  undefined1 *local_ac;
  undefined1 local_8c [56];
  undefined1 local_54 [56];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093e23b;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_bc;
  ExceptionList = &local_14;
  iVar6 = *(int *)(param_1 + 0x10);
  local_b4 = in_ECX;
  if (iVar6 != 0x578) {
    if (iVar6 == 0x57a) {
      piVar1 = in_ECX + 0x3f;
      local_b8 = 7;
      do {
        if ((((*(uint *)(piVar1[7] + 0x28) >> 7 & 1) != 0) &&
            (*(int *)(param_1 + 8) == *(int *)(*piVar1 + 0x20))) &&
           (*(int *)(param_1 + 8) != *(int *)(in_ECX[0x3f] + 0x20))) {
          iVar6 = FUN_00404ba0();
          if (((*(byte *)(in_ECX + 0x62) < 10) &&
              (iVar6 = (uint)*(byte *)(in_ECX + 0x62) * 0x210 + *(int *)(iVar6 + 0x6924),
              *(int *)(iVar6 + 0x5c) != 0)) && ((iVar6 != 0 && (iVar6 != -500)))) {
            local_b4 = (int *)CONCAT31(local_b4._1_3_,*(undefined1 *)(*piVar1 + 0x249));
            puStack_d4 = (undefined4 *)0x6155ac;
            iVar6 = FUN_0081a820();
            if (iVar6 == 0) {
              puStack_d4 = (undefined4 *)0x6155bb;
              iVar6 = FUN_00891268();
              if (iVar6 == 0) {
                uVar2 = 0;
              }
              else {
                puStack_d4 = (undefined4 *)0xf42ba;
                puStack_d8 = (undefined1 *)0x6155dd;
                uVar2 = FUN_00753e00();
              }
              FUN_00404aa0();
              puStack_d8 = (undefined1 *)0x197;
              puStack_dc = (undefined1 *)0x6155fa;
              puStack_d4 = (undefined4 *)uVar2;
              FUN_005854b0();
              puStack_dc = (undefined1 *)0x615601;
              uStack_f4 = FUN_00585330();
              local_ac = auStack_f0;
              uStack_f8 = 0x615610;
              FUN_00402250();
              uStack_f4 = 0x166;
              local_c = 3;
              uStack_f8 = 0x615625;
              FUN_005854b0();
              uStack_f8 = 0x61562c;
              uVar3 = FUN_00585330();
              local_b0 = auStack_10c;
              FUN_00402250(uVar3);
              local_c = 0xffffffff;
              FUN_0058b270(0xcf);
            }
          }
        }
        piVar1 = piVar1 + 1;
        local_b8 = local_b8 + -1;
      } while (local_b8 != 0);
      local_b8 = 0;
    }
    else if (iVar6 == 0x58c) {
      iVar6 = 0;
      piVar1 = in_ECX + 0x3f;
      do {
        if (*(int *)(param_1 + 8) == *(int *)(*piVar1 + 0x20)) {
          if ((DAT_00faadd4 & 1) == 0) {
            DAT_00faadd4 = DAT_00faadd4 | 1;
            local_c = 4;
            FUN_00587480();
            puStack_d4 = (undefined4 *)0x6154d5;
            _atexit((_func_4879 *)&LAB_00bcccc0);
          }
          local_c = 0xffffffff;
          puStack_d4 = (undefined4 *)(uint)*(byte *)(in_ECX + 0x62);
          puStack_d8 = (undefined1 *)0xf4330;
          puStack_dc = (undefined1 *)0x615504;
          FUN_0058ac30();
          break;
        }
        iVar6 = iVar6 + 1;
        piVar1 = piVar1 + 1;
      } while (iVar6 < 7);
    }
    goto LAB_00615882;
  }
  if (*(int *)(param_1 + 8) == *(int *)(in_ECX[0x3e] + 0x20)) {
    iVar6 = FUN_00404ba0();
    if (*(byte *)(in_ECX + 0x62) < 10) {
      iVar6 = (uint)*(byte *)(in_ECX + 0x62) * 0x210 + *(int *)(iVar6 + 0x6924);
      uVar2 = 0;
      if (((*(int *)(iVar6 + 0x5c) == 0) || (iVar6 == 0)) ||
         ((iVar6 == -500 || (*(int *)(iVar6 + 0x1fc) - *(int *)(iVar6 + 0x1f8) == 1))))
      goto LAB_00615830;
      local_b8 = 0;
      iVar6 = FUN_0040f7f0();
      uVar7 = *(int *)(iVar6 + 0x14) - *(int *)(iVar6 + 0x10) >> 3;
      if (uVar7 != 0) {
        do {
          iVar6 = FUN_0040f7f0();
          if ((uVar2 < (uint)(*(int *)(iVar6 + 0x14) - *(int *)(iVar6 + 0x10) >> 3)) &&
             (in_ECX = local_b4, *(int *)(iVar6 + 0x10) + uVar2 * 8 != 0)) {
            iVar6 = FUN_00404ba0();
            iVar4 = 0;
            if (*(int *)(iVar6 + 0x6920) != -0x16f8) {
              iVar4 = FUN_005090e0();
            }
            local_b8 = local_b8 + iVar4;
            in_ECX = local_b4;
          }
          uVar2 = uVar2 + 1;
        } while (uVar2 < uVar7);
        if (0 < local_b8) {
          puStack_d4 = (undefined4 *)0x61573a;
          puVar5 = (undefined4 *)FUN_00891268();
          puVar8 = (undefined4 *)0x0;
          if (puVar5 != (undefined4 *)0x0) {
            puVar5[3] = 0;
            *puVar5 = FoxUI::FXUIEvent::vftable;
            puVar5[1] = 0xffffffff;
            puVar5[2] = 0xffffffff;
            puVar5[4] = 0xf42bc;
            puVar8 = puVar5;
          }
          puStack_d4 = (undefined4 *)0x615768;
          FUN_005854b0();
          puStack_d4 = (undefined4 *)0x61576f;
          FUN_00585330();
          puStack_d4 = (undefined4 *)0x615779;
          FUN_007572f0();
          local_c = 0;
          puStack_d4 = (undefined4 *)0x61578e;
          FUN_005854b0();
          puStack_d4 = (undefined4 *)0x615795;
          FUN_00585330();
          FUN_004068f0();
          local_c._0_1_ = 1;
          puStack_d4 = (undefined4 *)0x6157b6;
          FUN_007574a0();
          local_c._0_1_ = 2;
          FUN_00404aa0();
          puStack_d8 = local_54;
          uStack_e0 = 0xcf;
          uStack_e4 = 0x6157e0;
          puStack_dc = local_8c;
          puStack_d4 = puVar8;
          FUN_00407330();
          local_c = CONCAT31(local_c._1_3_,1);
          puStack_d4 = (undefined4 *)0x6157f3;
          FUN_00757640();
          FUN_004fa440();
          local_c = 0xffffffff;
          puStack_d4 = (undefined4 *)0x615811;
          FUN_00757640();
          goto LAB_00615865;
        }
      }
      puStack_d4 = (undefined4 *)0x0;
      puStack_d8 = (undefined1 *)0x197;
      puStack_dc = (undefined1 *)0x615821;
      FUN_005854b0();
      puStack_dc = (undefined1 *)0x615828;
      puStack_d8 = (undefined1 *)FUN_00585330();
      puStack_dc = (undefined1 *)0x160;
    }
    else {
LAB_00615830:
      puStack_d4 = (undefined4 *)0x0;
      puStack_d8 = (undefined1 *)0x197;
      puStack_dc = (undefined1 *)0x61583e;
      FUN_005854b0();
      puStack_dc = (undefined1 *)0x615845;
      puStack_d8 = (undefined1 *)FUN_00585330();
      puStack_dc = (undefined1 *)0x16a;
    }
    uStack_e0 = 0x615850;
    FUN_005854b0();
    uStack_e0 = 0x615857;
    puStack_dc = (undefined1 *)FUN_00585330();
    uStack_e0 = 0xca;
    uStack_e4 = 0x615862;
    FUN_00404b10();
  }
LAB_00615865:
  if (*(int *)(param_1 + 8) == *(int *)(in_ECX[0x3d] + 0x20)) {
    (**(code **)(*in_ECX + 0xd4))();
  }
LAB_00615882:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_bc);
  return;
}


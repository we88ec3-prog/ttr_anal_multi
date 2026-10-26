
void FUN_0040fca0(int param_1)

{
  byte bVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int *in_ECX;
  uint uVar7;
  uint uVar8;
  undefined1 auStack_104 [20];
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined1 auStack_e8 [12];
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined1 *puStack_d4;
  int *piStack_d0;
  undefined4 *puStack_cc;
  int *piStack_c8;
  uint uStack_c4;
  undefined1 auStack_b4 [4];
  undefined1 *local_b0;
  undefined1 *local_ac;
  undefined1 local_8c [56];
  int local_54 [14];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00948498;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_b4;
  uStack_c4 = DAT_00d61f20 ^ (uint)&stack0xffffff40;
  ExceptionList = &local_14;
  uVar8 = *(uint *)(param_1 + 0x10);
  if (uVar8 < 0xf4412) {
    if (uVar8 == 0xf4411) {
      piStack_c8 = (int *)0x41012d;
      FUN_00410b50();
    }
    else if (uVar8 < 0x642) {
      if (uVar8 == 0x641) {
        piStack_c8 = (int *)0x41002c;
        FUN_0075cdb0();
        piStack_c8 = (int *)0x410033;
        iVar5 = FUN_004124b0();
        iVar4 = *(int *)(iVar5 + 0x20);
        if (in_ECX[0x57] == iVar4) goto LAB_00410155;
        piStack_c8 = (int *)in_ECX[0x3e];
        puStack_cc = (undefined4 *)0x410052;
        FUN_0075cd30();
        if (in_ECX[0x4f] != 0) {
          piStack_c8 = (int *)0x1c;
          puStack_cc = (undefined4 *)0x410067;
          iVar5 = FUN_00891268();
          if (iVar5 == 0) {
            puStack_cc = (undefined4 *)0x0;
          }
          else {
            puStack_cc = (undefined4 *)0xf4414;
            piStack_d0 = (int *)0x410082;
            piStack_c8 = (int *)iVar4;
            puStack_cc = (undefined4 *)FUN_00753e00();
          }
          piStack_d0 = (int *)0x197;
          puStack_d4 = (undefined1 *)0x410092;
          piStack_c8 = in_ECX;
          FUN_005854b0();
          puStack_d4 = (undefined1 *)0x410099;
          uStack_ec = FUN_00585330();
          local_ac = auStack_e8;
          uStack_f0 = 0x4100a8;
          FUN_00402250();
          uStack_ec = 0x15e;
          local_c = 4;
          uStack_f0 = 0x4100bd;
          FUN_005854b0();
          uStack_f0 = 0x4100c4;
          uVar2 = FUN_00585330();
          local_b0 = auStack_104;
          FUN_00402250(uVar2);
          local_c = 0xffffffff;
          FUN_0058b270(0xcf);
          goto LAB_00410155;
        }
        piStack_c8 = (int *)in_ECX[0x3e];
        puStack_cc = (undefined4 *)0x4100fb;
        FUN_0075cd30();
        in_ECX[0x57] = iVar4;
        *(undefined1 *)((int)in_ECX + 0x145) = *(undefined1 *)(iVar5 + 0x249);
      }
      else {
        if (uVar8 == 900) {
          piStack_c8 = (int *)0x41001c;
          FUN_00410fa0();
          goto LAB_00410155;
        }
        if (uVar8 != 0x578) goto LAB_00410155;
        iVar4 = *(int *)(param_1 + 8);
        if (iVar4 == *(int *)(in_ECX[0x40] + 0x20)) {
          if (in_ECX[0x4f] != 0) {
            piStack_c8 = (int *)0x14;
            puStack_cc = (undefined4 *)0x40fd4d;
            puStack_cc = (undefined4 *)FUN_00891268();
            if (puStack_cc == (undefined4 *)0x0) {
              puStack_cc = (undefined4 *)0x0;
            }
            else {
              *puStack_cc = FoxUI::FXUIEvent::vftable;
              puStack_cc[1] = 0xffffffff;
              puStack_cc[2] = 0xffffffff;
              puStack_cc[3] = 0;
              puStack_cc[4] = 0xf42b9;
            }
            piStack_d0 = (int *)0x197;
            puStack_d4 = (undefined1 *)0x40fd81;
            piStack_c8 = in_ECX;
            FUN_005854b0();
            puStack_d4 = (undefined1 *)0x40fd88;
            uStack_ec = FUN_00585330();
            local_ac = auStack_e8;
            uStack_f0 = 0x40fd97;
            FUN_00402250();
            uStack_ec = 0x165;
            local_c = 0;
            uStack_f0 = 0x40fdac;
            FUN_005854b0();
            uStack_f0 = 0x40fdb3;
            uVar2 = FUN_00585330();
            local_b0 = auStack_104;
            FUN_00402250(uVar2);
            local_c = 0xffffffff;
            FUN_0058b270(0xcf);
          }
          goto LAB_00410155;
        }
        if (iVar4 != *(int *)(in_ECX[0x41] + 0x20)) {
          if (iVar4 == *(int *)(in_ECX[0x42] + 0x20)) {
            piStack_c8 = (int *)0x40fe01;
            (**(code **)(*in_ECX + 0xd4))();
          }
          else if (iVar4 == *(int *)(in_ECX[0x43] + 0x20)) {
            piStack_c8 = (int *)0x40fe1a;
            FUN_00404ba0();
            piStack_c8 = (int *)0x40fe4e;
            piVar3 = (int *)FUN_004d4210();
            if (piVar3[1] - *piVar3 >> 3 == 0) {
              piStack_c8 = (int *)0x0;
              puStack_cc = (undefined4 *)0x0;
              piStack_d0 = (int *)0x197;
              puStack_d4 = (undefined1 *)0x40ffeb;
              FUN_005854b0();
              puStack_d4 = (undefined1 *)0x40fff2;
              piStack_d0 = (int *)FUN_00585330();
              puStack_d4 = (undefined1 *)0x169;
            }
            else {
              local_b0 = (undefined1 *)0x0;
              piStack_c8 = (int *)0x40fe69;
              iVar4 = FUN_0040f860();
              uVar8 = *(int *)(iVar4 + 0x14) - *(int *)(iVar4 + 0x10) >> 3;
              if (uVar8 != 0) {
                uVar7 = 0;
                do {
                  piStack_c8 = (int *)0x40fe85;
                  iVar4 = FUN_0040f860();
                  if ((uVar7 < (uint)(*(int *)(iVar4 + 0x14) - *(int *)(iVar4 + 0x10) >> 3)) &&
                     (local_ac = (undefined1 *)(*(int *)(iVar4 + 0x10) + uVar7 * 8),
                     local_ac != (undefined1 *)0x0)) {
                    piStack_c8 = (int *)0x40fea5;
                    iVar4 = FUN_00404ba0();
                    iVar5 = 0;
                    if (*(int *)(iVar4 + 0x6920) != -0x16f8) {
                      piStack_c8 = (int *)0x40fec0;
                      iVar5 = FUN_005090e0();
                    }
                    local_b0 = local_b0 + iVar5;
                  }
                  uVar7 = uVar7 + 1;
                } while (uVar7 < uVar8);
                if (0 < (int)local_b0) {
                  piStack_c8 = (int *)0x18;
                  puStack_cc = (undefined4 *)0x40fedb;
                  puVar6 = (undefined4 *)FUN_00891268();
                  if (puVar6 == (undefined4 *)0x0) {
                    puVar6 = (undefined4 *)0x0;
                  }
                  else {
                    bVar1 = *(byte *)((int)in_ECX + 0x145);
                    puVar6[1] = 0xffffffff;
                    puVar6[2] = 0xffffffff;
                    puVar6[3] = 0;
                    puVar6[4] = 0xf42bb;
                    *puVar6 = FoxUI::FXUIEventI1::vftable;
                    puVar6[5] = (uint)bVar1;
                  }
                  piStack_c8 = (int *)0x197;
                  puStack_cc = (undefined4 *)0x40ff19;
                  FUN_005854b0();
                  puStack_cc = (undefined4 *)0x40ff20;
                  piStack_c8 = (int *)FUN_00585330();
                  puStack_cc = (undefined4 *)0x40ff2a;
                  FUN_007572f0();
                  piStack_c8 = (int *)0x167;
                  local_c = 1;
                  puStack_cc = (undefined4 *)0x40ff3f;
                  FUN_005854b0();
                  puStack_cc = (undefined4 *)0x40ff46;
                  FUN_00585330();
                  piStack_c8 = (int *)0x40ff55;
                  piStack_c8 = (int *)FUN_004068f0();
                  local_c._0_1_ = 2;
                  puStack_cc = (undefined4 *)0x40ff67;
                  FUN_007574a0();
                  local_c._0_1_ = 3;
                  piStack_c8 = (int *)0x40ff74;
                  iVar4 = FUN_00404aa0();
                  piStack_c8 = *(int **)(iVar4 + 0x13c4);
                  piStack_d0 = local_54;
                  uStack_d8 = 0xcf;
                  uStack_dc = 0x40ff8e;
                  puStack_d4 = local_8c;
                  puStack_cc = puVar6;
                  FUN_00407330();
                  local_c = CONCAT31(local_c._1_3_,2);
                  puStack_cc = (undefined4 *)0x40ffa1;
                  piStack_c8 = (int *)local_8c;
                  FUN_00757640();
                  piStack_c8 = (int *)0x40ffaa;
                  FUN_004fa440();
                  piStack_c8 = local_54;
                  local_c = 0xffffffff;
                  puStack_cc = (undefined4 *)0x40ffbb;
                  FUN_00757640();
                  goto LAB_00410155;
                }
              }
              piStack_c8 = (int *)0x0;
              puStack_cc = (undefined4 *)0x0;
              piStack_d0 = (int *)0x197;
              puStack_d4 = (undefined1 *)0x40ffce;
              FUN_005854b0();
              puStack_d4 = (undefined1 *)0x40ffd5;
              piStack_d0 = (int *)FUN_00585330();
              puStack_d4 = (undefined1 *)0x162;
            }
            uStack_d8 = 0x40fffd;
            FUN_005854b0();
            uStack_d8 = 0x410004;
            puStack_d4 = (undefined1 *)FUN_00585330();
            uStack_d8 = 0xca;
            uStack_dc = 0x41000f;
            FUN_00404b10();
          }
          goto LAB_00410155;
        }
      }
      piStack_c8 = (int *)0x410114;
      FUN_00410af0();
    }
    else if (uVar8 == 0xf42b9) {
      puStack_cc = (undefined4 *)0x410124;
      piStack_c8 = in_ECX;
      FUN_00410fe0();
    }
  }
  else if (uVar8 == 0xf4412) {
    puStack_cc = (undefined4 *)0x410155;
    piStack_c8 = in_ECX;
    FUN_00410bc0();
  }
  else if (uVar8 == 0xf4413) {
    piStack_c8 = (int *)0x41014d;
    FUN_00410d50();
  }
  else if (uVar8 == 0xf4414) {
    piStack_c8 = (int *)0x410144;
    FUN_00410ec0();
  }
LAB_00410155:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_b4);
  return;
}


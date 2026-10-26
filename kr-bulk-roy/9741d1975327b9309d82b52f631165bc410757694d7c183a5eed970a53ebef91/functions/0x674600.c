
void FUN_00674600(undefined1 *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int *in_ECX;
  uint uVar4;
  int *piVar5;
  undefined4 uVar6;
  undefined1 auStack_e0 [4];
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  int *piStack_d4;
  undefined1 *puStack_d0;
  int *piStack_cc;
  int *piStack_c8;
  uint uStack_c4;
  undefined1 *local_b4;
  uint local_b0;
  int local_ac;
  int local_a8 [21];
  undefined1 local_54 [56];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0094877a;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_b4;
  uStack_c4 = DAT_00d61f20 ^ (uint)&stack0xffffff40;
  ExceptionList = &local_14;
  iVar2 = *(int *)(param_1 + 0x10);
  local_b4 = param_1;
  if (iVar2 == 0x578) {
    iVar2 = *(int *)(param_1 + 8);
    iVar1 = 0;
    piVar5 = in_ECX + 0x50;
    do {
      if (iVar2 == *(int *)(*piVar5 + 0x20)) {
        iVar2 = in_ECX[iVar1 + 0x55];
        goto LAB_00674695;
      }
      iVar1 = iVar1 + 1;
      piVar5 = piVar5 + 1;
    } while (iVar1 < 5);
    if (iVar2 == *(int *)(in_ECX[0x40] + 0x20)) {
      piStack_cc = (int *)0x674683;
      FUN_00674b00();
      piStack_cc = (int *)0x674689;
      piStack_c8 = in_ECX;
      FUN_00677e40();
      goto LAB_00674ada;
    }
    if ((iVar2 == *(int *)(in_ECX[0x46] + 0x20)) || (iVar2 == *(int *)(in_ECX[0x4e] + 0x20))) {
      piStack_cc = (int *)0x6747c7;
      FUN_00675b10();
      piStack_cc = (int *)0x6747cd;
      piStack_c8 = in_ECX;
      FUN_00677e40();
      goto LAB_00674ada;
    }
    if (iVar2 != *(int *)(in_ECX[0x49] + 0x20)) {
      if (iVar2 == *(int *)(in_ECX[0x5b] + 0x20)) {
        iVar2 = in_ECX[0x5f] + 1;
        if (iVar2 < in_ECX[0x5e]) {
LAB_00674695:
          in_ECX[0x5f] = iVar2;
        }
      }
      else {
        if (iVar2 != *(int *)(in_ECX[0x5a] + 0x20)) {
          if (iVar2 == *(int *)(in_ECX[0x5d] + 0x20)) {
            if (in_ECX[0x5f] + 5 < in_ECX[0x5e]) {
              in_ECX[0x5f] = in_ECX[0x5f] + 5;
              piStack_c8 = (int *)0x67475d;
              FUN_00675460();
              piStack_cc = (int *)0x674763;
              piStack_c8 = in_ECX;
              FUN_00677e40();
              goto LAB_00674ada;
            }
            uVar4 = in_ECX[0x5e] - 1;
          }
          else {
            if (iVar2 != *(int *)(in_ECX[0x5c] + 0x20)) {
              if (iVar2 == *(int *)(in_ECX[0x4c] + 0x20)) {
                piStack_c8 = (int *)0x6747bc;
                (**(code **)(*in_ECX + 0xd4))();
              }
              goto LAB_00674ada;
            }
            uVar4 = ((int)(in_ECX[0x5f] - 5U) < 1) - 1 & in_ECX[0x5f] - 5U;
          }
          in_ECX[0x5f] = uVar4;
          piStack_c8 = (int *)0x674796;
          FUN_00675460();
          piStack_cc = (int *)0x67479c;
          piStack_c8 = in_ECX;
          FUN_00677e40();
          goto LAB_00674ada;
        }
        if (in_ECX[0x5f] != 0) {
          iVar2 = in_ECX[0x5f] + -1;
          goto LAB_00674695;
        }
      }
      piStack_c8 = (int *)0x6746a2;
      FUN_00675460();
      piStack_cc = (int *)0x6746a8;
      piStack_c8 = in_ECX;
      FUN_00677e40();
      goto LAB_00674ada;
    }
    *(undefined1 *)((int)in_ECX + 0x1d5) = 1;
    if (in_ECX[0x73] == 1) {
      piStack_c8 = (int *)0x1;
      puStack_d0 = (undefined1 *)0x6746f2;
      piStack_cc = in_ECX;
      FUN_006777f0();
      goto LAB_00674ada;
    }
  }
  else {
    if (iVar2 == 0x3ea) {
      piStack_cc = (int *)0x6747df;
      piStack_c8 = in_ECX;
      FUN_00675b10();
      goto LAB_00674ada;
    }
    if (iVar2 == 0x641) {
      iVar2 = 0;
      piVar5 = in_ECX + 0x41;
      do {
        if (*(int *)(local_b4 + 8) == *(int *)(*piVar5 + 0x20)) {
          iVar1 = *(int *)(*piVar5 + 0x24c);
          if (iVar1 == 0) {
LAB_00674828:
            iVar1 = -1;
          }
          else {
            iVar1 = *(int *)(iVar1 + 0xcc);
            if (iVar1 == 0) {
              iVar1 = 0;
            }
            else {
              iVar1 = *(int *)(iVar1 + 0xdc);
            }
            if (iVar1 == 0) goto LAB_00674828;
            iVar1 = *(int *)(iVar1 + 0x20);
          }
          piVar5[0x2d] = iVar1;
          puStack_d0 = (undefined1 *)0x674838;
          piStack_c8 = (int *)iVar2;
          FUN_00674fb0();
        }
        iVar2 = iVar2 + 1;
        piVar5 = piVar5 + 1;
      } while (iVar2 < 3);
      piStack_cc = (int *)0x674847;
      piStack_c8 = in_ECX;
      FUN_00677e40();
      goto LAB_00674ada;
    }
    if (iVar2 == 0x70b) {
      if (*(int *)(param_1 + 8) == *(int *)(in_ECX[0x44] + 0x20)) {
        piStack_c8 = (int *)0x67486a;
        FUN_0041bb70();
        piStack_c8 = (int *)0x674871;
        iVar2 = FUN_005de120();
        if ((iVar2 != 0) && (*(int *)(iVar2 + 0x248) != 0)) {
          in_ECX[0x72] = *(int *)(*(int *)(iVar2 + 0x248) + 0x254);
          piStack_c8 = (int *)0x67489a;
          FUN_006767d0();
        }
      }
      goto LAB_00674ada;
    }
    if (iVar2 == 0xf43a4) {
      piStack_c8 = (int *)0x6748ab;
      iVar2 = FUN_00603e50();
      if (*(int *)(iVar2 + 0x14) == 0xf43a5) {
        piStack_c8 = *(int **)(iVar2 + 0x18);
        puStack_d0 = (undefined1 *)0x6748c2;
        piStack_cc = in_ECX;
        FUN_006777f0();
      }
      goto LAB_00674ada;
    }
    if (iVar2 == 0xf440c) {
      piStack_c8 = (int *)0x6748d7;
      iVar2 = FUN_004068c0();
      if (*(int *)(iVar2 + 0x14) == 0x6a7) {
        local_ac = *(int *)(iVar2 + 0x18);
        if ((char)in_ECX[0x7d] == '\0') {
          piStack_c8 = *(int **)(local_ac + 0x14);
          piStack_cc = (int *)0x674a97;
          FUN_00676630();
        }
        else {
          local_b4 = auStack_e0;
          FUN_00402110(in_ECX + 0x76);
          uVar6 = 0x1a8;
          local_c = 0;
          FUN_005854b0(0x1a8);
          uVar6 = FUN_00585330(uVar6);
          local_c = 0xffffffff;
          piStack_c8 = (int *)FUN_00424c80(uVar6);
          local_c = 1;
          piStack_cc = (int *)0x674955;
          FUN_007574a0();
          local_c = CONCAT31(local_c._1_3_,3);
          piStack_c8 = (int *)0x674966;
          FUN_004fa440();
          iVar2 = in_ECX[0x7f] - in_ECX[0x7e] >> 0x1f;
          local_b0 = 0;
          if ((in_ECX[0x7f] - in_ECX[0x7e]) / 0x1c + iVar2 != iVar2) {
            local_b4 = (undefined1 *)0x0;
            do {
              piStack_c8 = (int *)0x6749a3;
              FUN_00758d30();
              uVar4 = local_b0;
              piStack_c8 = (int *)local_b0;
              piStack_cc = (int *)0x6749c5;
              FUN_00759ac0();
              local_b4 = local_b4 + 0x1c;
              local_b0 = uVar4 + 1;
            } while (local_b0 < (uint)((in_ECX[0x7f] - in_ECX[0x7e]) / 0x1c));
          }
          piStack_c8 = (int *)0x18;
          piStack_cc = (int *)0x6749fe;
          puVar3 = (undefined4 *)FUN_00891268();
          if (puVar3 == (undefined4 *)0x0) {
            puVar3 = (undefined4 *)0x0;
          }
          else {
            uVar6 = *(undefined4 *)(local_ac + 0x14);
            puVar3[1] = 0xffffffff;
            puVar3[2] = 0xffffffff;
            puVar3[3] = 0;
            puVar3[4] = 0xf4426;
            *puVar3 = FoxUI::FXUIEventI1::vftable;
            puVar3[5] = uVar6;
          }
          piStack_c8 = (int *)0x196;
          piStack_cc = (int *)0x674a35;
          FUN_005854b0();
          piStack_cc = (int *)0x674a3c;
          piStack_c8 = (int *)FUN_00585330();
          piStack_cc = (int *)0x674a46;
          FUN_007572f0();
          piStack_d4 = local_a8;
          uStack_d8 = 0xd1;
          local_c._0_1_ = 4;
          uStack_dc = 0x674a62;
          puStack_d0 = local_54;
          piStack_cc = puVar3;
          FUN_00407330();
          local_c = CONCAT31(local_c._1_3_,3);
          piStack_cc = (int *)0x674a75;
          piStack_c8 = (int *)local_54;
          FUN_00757640();
          piStack_c8 = local_a8;
          local_c = 0xffffffff;
          piStack_cc = (int *)0x674a8a;
          FUN_00757640();
        }
      }
      goto LAB_00674ada;
    }
    if (iVar2 == 0xf4426) {
      piStack_c8 = (int *)0x674aa5;
      iVar2 = FUN_004068c0();
      if (*(int *)(iVar2 + 0x14) == 0x6a7) {
        piStack_c8 = *(int **)(*(int *)(iVar2 + 0x18) + 0x14);
        piStack_cc = (int *)0x674abc;
        FUN_00676630();
      }
      goto LAB_00674ada;
    }
    if (iVar2 != 0xf43af) goto LAB_00674ada;
    piStack_c8 = (int *)0x674aca;
    iVar2 = FUN_004068c0();
    if (*(int *)(iVar2 + 0x14) != 0x6a7) goto LAB_00674ada;
  }
  piStack_c8 = (int *)0x674ada;
  FUN_00676750();
LAB_00674ada:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_b4);
  return;
}


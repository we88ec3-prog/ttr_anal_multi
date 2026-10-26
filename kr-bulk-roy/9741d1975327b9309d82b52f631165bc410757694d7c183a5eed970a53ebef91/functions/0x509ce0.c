
void FUN_00509ce0(int param_1,uint param_2)

{
  short sVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  code *pcVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  int in_ECX;
  uint uVar8;
  byte *pbVar9;
  undefined4 uStack_d0;
  uint uStack_cc;
  uint uStack_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  char *pcStack_bc;
  int *local_a4;
  byte *local_a0;
  undefined1 *puStack_9c;
  uint local_98;
  int local_94;
  uint local_90;
  uint local_8c;
  int local_88;
  int iStack_84;
  int iStack_80;
  int iStack_7c;
  int iStack_78;
  int iStack_74;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0092f664;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_a4;
  ExceptionList = &local_14;
  local_94 = param_1;
  local_88 = in_ECX;
  FUN_00404ba0();
  uVar2 = *(undefined4 *)(in_ECX + 4);
  local_98 = local_98 & 0xffffff00;
  iVar5 = FUN_00404ba0();
  *(undefined4 *)(iVar5 + 0x6864) = uVar2;
  uVar2 = *(undefined4 *)(in_ECX + 8);
  iVar5 = FUN_00404ba0();
  *(undefined4 *)(iVar5 + 0x6870) = uVar2;
  local_a4 = (int *)0x0;
  switch(*(undefined2 *)(in_ECX + 2)) {
  case 1:
    goto LAB_00509d7c;
  case 2:
LAB_00509d7c:
    pcStack_bc = (char *)0x509d81;
    FUN_005855b0();
    pcStack_bc = (char *)0x509d88;
    local_a4 = (int *)FUN_00585330();
    local_98 = CONCAT31(local_98._1_3_,1);
    break;
  case 3:
    pcStack_bc = (char *)0x509da1;
    FUN_005855b0();
    pcStack_bc = (char *)0x509da8;
    local_a4 = (int *)FUN_00585330();
    break;
  case 4:
    pcStack_bc = (char *)0x509db8;
    FUN_005855b0();
    pcStack_bc = (char *)0x509dbf;
    local_a4 = (int *)FUN_00585330();
    break;
  case 5:
    pcStack_bc = (char *)0x509dcf;
    FUN_005855b0();
    pcStack_bc = (char *)0x509dd6;
    local_a4 = (int *)FUN_00585330();
    break;
  case 6:
    pcStack_bc = (char *)0x509de3;
    FUN_005855b0();
    pcStack_bc = (char *)0x509dea;
    local_a4 = (int *)FUN_00585330();
    break;
  case 7:
    pcStack_bc = (char *)0x509df7;
    FUN_005855b0();
    pcStack_bc = (char *)0x509dfe;
    local_a4 = (int *)FUN_00585330();
    FUN_004068f0();
    local_c = 0;
    pcStack_bc = (char *)0x509e20;
    FUN_0040f8c0();
    pcStack_bc = (char *)0x509e27;
    FUN_004d6b30();
    local_c = 0xffffffff;
    FUN_004fa440();
    pcStack_bc = (char *)0x509e4b;
    FUN_0045f3e0();
    in_ECX = local_88;
  }
  if (param_2 < 0xc) {
    uVar8 = 0;
  }
  else {
    uVar8 = (param_2 - 0xc) / 0x11;
  }
  if (uVar8 != 0) {
    pbVar9 = (byte *)(in_ECX + 0x1a);
    local_8c = uVar8;
    do {
      local_a0 = pbVar9;
      if ((pbVar9[-0xe] == 1) && (local_90 = local_94 + 0x16f8, local_90 != 0)) {
        if (pbVar9[-0xd] - 1 < 100) {
          iVar6 = (uint)pbVar9[-0xd] * 0x20;
          iVar5 = iVar6 + local_90;
          if ((*(int *)(iVar6 + 0xc + local_90) == 0) || (*(int *)(iVar5 + 8) == 0))
          goto LAB_00509ee2;
        }
        else {
          pcStack_bc = (char *)0x509edf;
          FUN_006edb60();
LAB_00509ee2:
          iVar5 = 0;
        }
        uVar8 = (uint)*pbVar9;
        if (*(int **)(local_94 + 0x50f0) != (int *)0x0) {
          if (iVar5 != 0) {
            uVar8 = uVar8 - *(int *)(iVar5 + 8);
          }
          if (0 < (int)uVar8) {
            pcStack_bc = *(char **)(pbVar9 + -4);
            uStack_c0 = *(undefined4 *)(pbVar9 + -8);
            uStack_c4 = *(undefined4 *)(pbVar9 + -0xc);
            uStack_c8 = (uint)pbVar9[-0xd];
            uStack_cc = (uint)pbVar9[-0xe];
            uStack_d0 = 0x509f1e;
            (**(code **)(**(int **)(local_94 + 0x50f0) + 4))();
          }
        }
        sVar1 = *(short *)(local_88 + 2);
        if (sVar1 == 1) {
          if (iVar5 != 0) {
            uVar8 = (uint)*pbVar9 - *(int *)(iVar5 + 8);
          }
          if ((local_a4 != (int *)0x0) && (uVar8 != 0)) {
            if ((int)uVar8 < 0) {
              local_a4 = (int *)0x2f;
              iVar5 = FUN_005855b0();
              pcStack_bc = (char *)0x509f6f;
              FUN_005740f0();
              if (iStack_84 == *(int *)(iVar5 + 4)) {
                pcVar4 = (code *)swi(3);
                (*pcVar4)();
                return;
              }
              if (*(uint *)(iStack_84 + 0x24) < 8) {
                local_a4 = (int *)(iStack_84 + 0x10);
              }
              else {
                local_a4 = *(int **)(iStack_84 + 0x10);
              }
            }
            else {
              local_a4 = (int *)0x2e;
              iVar5 = FUN_005855b0();
              pcStack_bc = (char *)0x509fac;
              FUN_005740f0();
              if (iStack_7c == *(int *)(iVar5 + 4)) {
                pcVar4 = (code *)swi(3);
                (*pcVar4)();
                return;
              }
              local_a4 = (int *)(iStack_7c + 0x10);
              if (7 < *(uint *)(iStack_7c + 0x24)) {
                local_a4 = (int *)*local_a4;
              }
            }
            if ((DAT_00f8d9a4 & 1) == 0) {
              DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
              local_c = 1;
              FUN_0051c120();
              pcStack_bc = (char *)0x50a000;
              _atexit((_func_4879 *)&LAB_00bccc90);
              local_c = 0xffffffff;
            }
            puStack_9c = *(undefined1 **)(local_a0 + -4);
            pcStack_bc = (char *)0x50a02c;
            FUN_008438c0();
            if (iStack_78 == DAT_00f8d91c) {
              puVar7 = (undefined4 *)0x0;
            }
            else {
              puVar7 = *(undefined4 **)(iStack_78 + 0x10);
            }
            if ((DAT_00fb131c & 1) == 0) {
              DAT_00fb131c = DAT_00fb131c | 1;
              local_c = 2;
              FUN_00570ec0();
              pcStack_bc = (char *)0x50a069;
              _atexit((_func_4879 *)&LAB_00bccf50);
              local_c = 0xffffffff;
            }
            if (DAT_00fb1330 == 0) {
              if (puVar7 == (undefined4 *)0x0) {
                pcStack_bc = (char *)0x50a11d;
                FUN_00483f00();
                local_c = 5;
              }
              else {
                pcStack_bc = (char *)0x50a0e5;
                FUN_00483f00();
                local_c = 4;
              }
              goto LAB_0050a0f3;
            }
            if (7 < (uint)puVar7[5]) {
              puVar7 = (undefined4 *)*puVar7;
            }
            puStack_9c = (undefined1 *)&uStack_d0;
            FUN_00483f00(puVar7);
            local_c = 3;
            FUN_00414720();
            local_c = 0xffffffff;
            FUN_00571460();
          }
        }
        else if (sVar1 == 2) {
          if (local_a4 != (int *)0x0) {
            if ((DAT_00f8d9a4 & 1) == 0) {
              DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
              local_c = 6;
              FUN_0051c120();
              pcStack_bc = (char *)0x50a175;
              _atexit((_func_4879 *)&LAB_00bccc90);
              local_c = 0xffffffff;
            }
            puStack_9c = *(undefined1 **)(local_a0 + -4);
            pcStack_bc = (char *)0x50a1a5;
            FUN_008438c0();
            if (iStack_74 == DAT_00f8d91c) {
              puVar7 = (undefined4 *)0x0;
            }
            else {
              puVar7 = *(undefined4 **)(iStack_74 + 0x10);
            }
            if ((DAT_00fb131c & 1) == 0) {
              DAT_00fb131c = DAT_00fb131c | 1;
              local_c = 7;
              FUN_00570ec0();
              pcStack_bc = (char *)0x50a1e2;
              _atexit((_func_4879 *)&LAB_00bccf50);
              local_c = 0xffffffff;
            }
            if (DAT_00fb1330 == 0) {
              if (puVar7 == (undefined4 *)0x0) {
                pcStack_bc = (char *)0x50a27f;
                FUN_00483f00();
                local_c = 10;
              }
              else {
                pcStack_bc = (char *)0x50a258;
                FUN_00483f00();
                local_c = 9;
              }
LAB_0050a0f3:
              pcStack_bc = (char *)0x50a0f9;
              FUN_0040f8c0();
              pcStack_bc = (char *)0x50a100;
              FUN_004d6b30();
              goto LAB_0050a358;
            }
            if (7 < (uint)puVar7[5]) {
              puVar7 = (undefined4 *)*puVar7;
            }
            puStack_9c = (undefined1 *)&uStack_d0;
            FUN_00483f00(puVar7);
            local_c = 8;
            FUN_00414720();
            local_c = 0xffffffff;
            FUN_00571460();
          }
        }
        else if (((iVar5 != 0) && ((((sVar1 == 3 || (sVar1 == 4)) || (sVar1 == 5)) || (sVar1 == 6)))
                 ) && (local_a4 != (int *)0x0)) {
          puVar3 = *(undefined1 **)(iVar5 + 0xc);
          iVar5 = FUN_00404c10();
          pcStack_bc = (char *)0x50a2e7;
          puStack_9c = puVar3;
          FUN_008438c0();
          if ((iStack_80 != *(int *)(iVar5 + 4)) && (*(int *)(iStack_80 + 0x10) != 0)) {
            pcStack_bc = (char *)0x50a311;
            FUN_00483f00();
            local_c = 0xb;
            goto LAB_0050a0f3;
          }
          pcStack_bc = (char *)0x50a33b;
          FUN_00483f00();
          local_c = 0xc;
          pcStack_bc = (char *)0x50a34f;
          FUN_0040f8c0();
          pcStack_bc = (char *)0x50a356;
          FUN_004d6b30();
LAB_0050a358:
          local_c = 0xffffffff;
          FUN_004fa440();
        }
        if (*local_a0 == 0) {
          if (local_a0[-0xd] - 1 < 100) {
            puVar7 = (undefined4 *)((uint)local_a0[-0xd] * 0x20 + local_90);
            *puVar7 = 0;
            puVar7[1] = 0;
            puVar7[2] = 0;
            puVar7[3] = 0;
            puVar7[4] = 0;
            puVar7[5] = 0;
          }
          else {
            pcStack_bc = (char *)0x50a3c8;
            FUN_006edb60();
          }
        }
        else {
          uStack_c0 = *(undefined4 *)(local_a0 + -8);
          pcStack_bc = (char *)(uint)*local_a0;
          uStack_c4 = *(undefined4 *)(local_a0 + -0xc);
          uStack_c8 = local_90;
          uStack_cc = 0x50a394;
          FUN_00508cb0();
        }
      }
      else {
        pcStack_bc = "InvUp: Invalid bag no %d";
        uStack_c0 = 0x509eac;
        FUN_006edb60();
        local_a0 = pbVar9;
      }
      pbVar9 = local_a0 + 0x11;
      local_8c = local_8c - 1;
      local_a0 = pbVar9;
    } while (local_8c != 0);
  }
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_c = 0xd;
    FUN_00587480();
    pcStack_bc = (char *)0x50a40a;
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_c = 0xffffffff;
  }
  pcStack_bc = (char *)0x50a422;
  FUN_0058aad0();
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_a4);
  return;
}


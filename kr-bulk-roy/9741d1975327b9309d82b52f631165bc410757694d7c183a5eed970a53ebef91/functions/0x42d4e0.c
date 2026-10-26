
/* WARNING: Removing unreachable block (ram,0x0042da78) */

void FUN_0042d4e0(int *param_1)

{
  bool bVar1;
  bool bVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  char extraout_CL;
  int *in_ECX;
  uint uVar8;
  int *piVar9;
  int local_fc;
  uint local_38;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009455b3;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  bVar2 = false;
  bVar1 = false;
  uVar8 = param_1[4];
  if (uVar8 < 0x642) {
    if (uVar8 == 0x641) {
      if (*(int *)(in_ECX[0x40] + 0x20) == param_1[2]) {
        iVar5 = FUN_0075cdd0();
        if (iVar5 == 2) {
          if (extraout_CL == '\0') {
            FUN_0042dbf0();
            goto LAB_0042db98;
          }
        }
        else if (extraout_CL == '\0') goto LAB_0042db98;
        FUN_0042dbf0();
      }
    }
    else if (uVar8 == 0x3e9) {
      if (*(int *)(in_ECX[0x3f] + 0x20) == param_1[2]) {
        iVar5 = FUN_00761500();
        if (*(int *)(iVar5 + 0x10) == 0) {
          FUN_00402250();
          uVar8 = 1;
        }
        else {
          FUN_00761500();
          FUN_00402110();
          uVar8 = 2;
        }
        local_8 = uVar8;
        FUN_00402880();
        local_8 = 3;
        if ((uVar8 & 2) != 0) {
          uVar8 = uVar8 & 0xfffffffd;
          FUN_004fa440();
        }
        local_8._0_1_ = 5;
        if ((uVar8 & 1) != 0) {
          FUN_004fa440();
        }
        FUN_00432b90();
        FUN_004068f0();
        local_8 = CONCAT31(local_8._1_3_,6);
        FUN_007613e0();
        FUN_004fa440();
        FUN_004fa440();
      }
      else {
        piVar9 = in_ECX + 0x47;
        local_fc = 0;
        do {
          local_8 = 0xffffffff;
          iVar5 = *piVar9;
          if (*(int *)(iVar5 + 0x20) == param_1[2]) {
            if (*(char *)(iVar5 + 0x141) != '\0') {
              FUN_006edb10();
            }
            if (*(int *)(iVar5 + 0x118) == 0) {
              FUN_00402250();
              local_8 = 7;
              bVar2 = true;
            }
            else {
              if (*(char *)(*piVar9 + 0x141) != '\0') {
                FUN_006edb10();
              }
              FUN_00402110();
              local_8 = 8;
              bVar1 = true;
            }
            FUN_00402800();
            local_8 = 9;
            if (bVar1) {
              bVar1 = false;
              FUN_004fa440();
            }
            local_8._0_1_ = 0xb;
            if (bVar2) {
              bVar2 = false;
              FUN_004fa440();
            }
            FUN_00432b90();
            FUN_004068f0();
            local_8 = CONCAT31(local_8._1_3_,0xc);
            iVar5 = *piVar9;
            if (*(char *)(iVar5 + 0x141) == '\0') {
              FUN_00757710();
            }
            else {
              FUN_006edb10();
            }
            *(undefined4 *)(iVar5 + 0x168) = 0;
            *(undefined4 *)(iVar5 + 0x160) = 0;
            *(undefined4 *)(iVar5 + 0x164) = 0;
            *(undefined4 *)(iVar5 + 0x14c) = 0;
            if (7 < local_38) {
              FUN_0089120c();
            }
            local_38 = 7;
          }
          local_8 = 0xffffffff;
          local_fc = local_fc + 1;
          piVar9 = piVar9 + 1;
        } while (local_fc < 3);
      }
    }
    else if (uVar8 == 0x578) {
      iVar5 = param_1[2];
      if (*(int *)(in_ECX[0x3c] + 0x20) == iVar5) {
        cVar3 = FUN_0042dc60();
        if (cVar3 != '\0') {
          FUN_0042e070();
          if (*(char *)((int)in_ECX + 0x159) == '\0') {
            if ((*(char *)((int)in_ECX + 0x15a) != '\0') &&
               (iVar5 = FUN_0041a4d0(), *(int *)(iVar5 + 0x5ed8) != 0)) {
              FUN_0053b990();
            }
          }
          else {
            iVar5 = FUN_0041a4d0();
            if (*(int *)(iVar5 + 0x5ed8) == 0) {
              if (*(char *)((int)in_ECX + 0x15a) != '\0') {
                iVar5 = FUN_0041a4d0();
                if (*(int *)(iVar5 + 0x5ed8) == 0) {
                  FUN_0053b900();
                }
                FUN_00414680();
                FUN_004a41d0();
              }
            }
            else {
              FUN_00404ba0();
              iVar5 = FUN_00539aa0();
              if (iVar5 == 0) {
                FUN_006edb60();
              }
              else {
                FUN_004054c0();
                puVar6 = (undefined4 *)FUN_00891268();
                if (puVar6 != (undefined4 *)0x0) {
                  puVar6[1] = 0xffffffff;
                  puVar6[2] = 0xffffffff;
                  puVar6[3] = 0;
                  puVar6[4] = 0xf4440;
                  *puVar6 = FoxUI::FXUIEventI1::vftable;
                  puVar6[5] = 0;
                }
                FUN_00402250();
                local_8 = 0;
                FUN_005854b0();
                uVar7 = FUN_00585330();
                FUN_00402250(uVar7);
                local_8 = 0xffffffff;
                FUN_0058b270(0xcf);
              }
            }
          }
          if ((*(uint *)(in_ECX[0x41] + 0x28) >> 9 & 1) == 0) {
            FUN_0041a4d0();
            FUN_0053bad0();
            (**(code **)(*in_ECX + 0xd4))();
          }
          else {
            FUN_0041a4d0();
            FUN_0053ba80();
            (**(code **)(*in_ECX + 0xd4))();
          }
          goto LAB_0042db98;
        }
      }
      else {
        if (*(int *)(in_ECX[0x3d] + 0x20) != iVar5) {
          if (((int *)in_ECX[0x41])[8] == iVar5) {
            (**(code **)(*(int *)in_ECX[0x41] + 0xa0))();
            (**(code **)(*(int *)in_ECX[0x42] + 0xa0))();
          }
          else if (*(int *)(in_ECX[0x42] + 0x20) == iVar5) {
            (**(code **)(*(int *)in_ECX[0x41] + 0xa0))();
            (**(code **)(*(int *)in_ECX[0x42] + 0xa0))();
          }
          goto LAB_0042db98;
        }
        FUN_0042e340();
      }
      (**(code **)(*in_ECX + 0xd4))();
    }
  }
  else if (uVar8 == 0xf4440) {
    iVar5 = (**(code **)(*param_1 + 4))();
    if (iVar5 != 0x105bd) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
      param_1 = (int *)0x0;
    }
    if (param_1[5] == 0x6a7) {
      FUN_00414680();
      FUN_004a3f80();
      FUN_00414680();
      FUN_004a41d0();
      iVar5 = FUN_0041a4d0();
      if (*(int *)(iVar5 + 0x5ed8) != 0) {
        FUN_0053b990();
      }
    }
  }
LAB_0042db98:
  ExceptionList = local_10;
  __security_check_cookie(uVar4 ^ (uint)&stack0xfffffffc);
  return;
}



void FUN_00606e60(int *param_1)

{
  code *pcVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  int in_ECX;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined1 auStack_e0 [4];
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined1 *local_b4;
  int local_b0;
  uint local_ac;
  undefined1 *local_7c;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00946c7a;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_b4;
  ExceptionList = &local_14;
  iVar3 = param_1[4];
  if (iVar3 == 0x578) {
    if (param_1[2] == *(int *)(*(int *)(in_ECX + 0x104) + 0x20)) {
      FUN_00607270();
    }
  }
  else if (iVar3 == 0xf43a4) {
    iVar3 = (**(code **)(*param_1 + 4))();
    if (iVar3 != 0x105c1) {
      uStack_d8 = 0x606ef8;
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
      param_1 = (int *)0x0;
    }
    if (param_1[5] == 0xf43a5) {
      FUN_006084b0();
    }
  }
  else if (iVar3 == 0xf440c) {
    iVar3 = FUN_004068c0();
    if (*(int *)(iVar3 + 0x14) == 0x6a7) {
      local_b0 = *(int *)(iVar3 + 0x18);
      if (*(char *)(in_ECX + 0x148) == '\0') {
        FUN_00607310();
      }
      else {
        local_b4 = auStack_e0;
        FUN_00402110(in_ECX + 300);
        uVar7 = 0x1a8;
        local_c = 0;
        FUN_005854b0(0x1a8);
        uVar7 = FUN_00585330(uVar7);
        local_c = 0xffffffff;
        FUN_00424c80(uVar7);
        local_c = 1;
        FUN_007574a0();
        local_c = CONCAT31(local_c._1_3_,3);
        FUN_004fa440();
        iVar5 = *(int *)(in_ECX + 0x150) - *(int *)(in_ECX + 0x14c);
        iVar3 = iVar5 >> 0x1f;
        uVar6 = 0;
        if (iVar5 / 0x1c + iVar3 != iVar3) {
          do {
            local_ac = uVar6;
            FUN_00848020();
            puVar2 = local_b4;
            if (local_b4 != local_7c) {
              *(undefined4 *)(local_b4 + 0x18) = 0xffff0000;
              puVar2[0x1c] = 1;
              FUN_007591a0();
            }
            FUN_00759ac0();
            uVar6 = uVar6 + 1;
          } while (uVar6 < (uint)((*(int *)(in_ECX + 0x150) - *(int *)(in_ECX + 0x14c)) / 0x1c));
        }
        puVar4 = (undefined4 *)FUN_00891268();
        if (puVar4 != (undefined4 *)0x0) {
          uVar7 = *(undefined4 *)(local_b0 + 0x14);
          puVar4[1] = 0xffffffff;
          puVar4[2] = 0xffffffff;
          puVar4[3] = 0;
          puVar4[4] = 0xf4426;
          *puVar4 = FoxUI::FXUIEventI1::vftable;
          puVar4[5] = uVar7;
        }
        local_b0 = 0x196;
        iVar3 = FUN_005854b0();
        FUN_005740f0();
        if (local_b4 == *(undefined1 **)(iVar3 + 4)) {
          pcVar1 = (code *)swi(3);
          (*pcVar1)();
          return;
        }
        FUN_007572f0();
        uStack_d8 = 0xd1;
        local_c._0_1_ = 4;
        uStack_dc = 0x60710c;
        FUN_00407330();
        local_c = CONCAT31(local_c._1_3_,3);
        FUN_00757640();
        local_c = 0xffffffff;
        FUN_00757640();
      }
    }
  }
  else if (iVar3 == 0xf4426) {
    iVar3 = FUN_004068c0();
    if (*(int *)(iVar3 + 0x14) == 0x6a7) {
      FUN_00607310();
    }
  }
  else if ((iVar3 == 0xf43af) && (iVar3 = FUN_004068c0(), *(int *)(iVar3 + 0x14) == 0x6a7)) {
    FUN_00607430();
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_b4);
  return;
}


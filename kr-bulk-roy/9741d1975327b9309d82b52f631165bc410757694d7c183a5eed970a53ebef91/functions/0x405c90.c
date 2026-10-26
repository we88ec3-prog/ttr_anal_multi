
void FUN_00405c90(int *param_1)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  int *in_ECX;
  int iVar7;
  int aiStack_124 [4];
  undefined4 uStack_114;
  undefined2 *puStack_110;
  undefined1 **ppuStack_10c;
  undefined2 local_108 [6];
  undefined4 uStack_fc;
  undefined4 local_f8;
  undefined1 *local_d4;
  int *local_d0;
  int *local_cc;
  undefined1 *local_c8;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00931fd3;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_d4;
  ExceptionList = &local_14;
  local_cc = param_1;
  local_d0 = in_ECX;
  if (param_1[4] == 0x578) {
    iVar4 = 0;
    do {
      iVar2 = iVar4 / 7;
      iVar7 = iVar4 % 7;
      if ((param_1[2] == *(int *)(in_ECX[(iVar2 + 9) * 7 + iVar7] + 0x20)) ||
         (param_1[2] == *(int *)(in_ECX[(iVar2 + 0xd) * 7 + iVar7] + 0x20))) {
        iVar1 = *(int *)(in_ECX[9] + 0x3d4);
        if ((iVar1 == 1) ||
           (((iVar1 == 2 || (iVar1 = *(int *)(in_ECX[9] + 0x404), iVar1 == 1)) || (iVar1 == 2))))
        break;
        iVar2 = in_ECX[(iVar2 + 0xd) * 7 + iVar7];
        if ((*(uint *)(*(int *)(iVar2 + 0x260) + 0x28) >> 8 & 1) == 0) {
          if ((*(uint *)(*(int *)(iVar2 + 0x264) + 0x28) >> 8 & 1) == 0) {
            if ((*(uint *)(*(int *)(iVar2 + 0x25c) + 0x28) >> 7 & 1) != 0) {
              in_ECX[0x9d] = iVar4 + 1;
              FUN_005854b0();
              FUN_00585330();
              FUN_004068f0();
              local_c = 0;
              FUN_00402250();
              local_c._0_1_ = 2;
              FUN_004fa440();
              puVar5 = (undefined4 *)FUN_00891268();
              if (puVar5 != (undefined4 *)0x0) {
                puVar5[3] = 0;
                *puVar5 = FoxUI::FXUIEvent::vftable;
                puVar5[1] = 0xffffffff;
                puVar5[2] = 0xffffffff;
                puVar5[4] = 0xf4434;
              }
              FUN_007572f0();
              local_c._0_1_ = 3;
              FUN_007574a0();
              local_f8 = 0xcf;
              local_c._0_1_ = 4;
              uStack_fc = 0x405ee8;
              FUN_00407330();
              local_c._0_1_ = 3;
              FUN_00757640();
              local_c = CONCAT31(local_c._1_3_,2);
              FUN_00757640();
              local_c = 0xffffffff;
              FUN_004fa440();
            }
            break;
          }
          FUN_004054c0();
          local_d4 = (undefined1 *)local_108;
          ppuStack_10c = (undefined1 **)&DAT_00bed1fc;
          puStack_110 = (undefined2 *)0x405f42;
          FUN_00402250();
          ppuStack_10c = (undefined1 **)0x1cd;
          local_c = 5;
          puStack_110 = (undefined2 *)0x405f57;
          FUN_005854b0();
          puStack_110 = (undefined2 *)0x405f5e;
          piVar6 = (int *)FUN_00585330();
          local_d0 = aiStack_124;
        }
        else {
          FUN_004054c0();
          local_c8 = (undefined1 *)local_108;
          ppuStack_10c = (undefined1 **)0x0;
          local_f8 = 0;
          puStack_110 = &DAT_00bed1fc;
          local_108[0] = 0;
          uStack_114 = 0x405f9a;
          FUN_00402160();
          local_c = 6;
          local_d4 = (undefined1 *)0x1ce;
          ppuStack_10c = (undefined1 **)0x405fb2;
          iVar4 = FUN_005854b0();
          ppuStack_10c = &local_d4;
          puStack_110 = (undefined2 *)0x405fc4;
          FUN_005740f0();
          if (local_d0 == *(int **)(iVar4 + 4)) {
            pcVar3 = (code *)swi(3);
            (*pcVar3)();
            return;
          }
          piVar6 = local_d0 + 4;
          if (7 < (uint)local_d0[9]) {
            piVar6 = (int *)*piVar6;
          }
          local_d4 = (undefined1 *)aiStack_124;
        }
        FUN_00402250(piVar6);
        local_c = 0xffffffff;
        FUN_0058b270(0xca);
        break;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0x1c);
    if (local_cc[2] == *(int *)(in_ECX[0x3e] + 0x20)) {
      (**(code **)(*in_ECX + 0xd4))();
    }
  }
  else if (param_1[4] == 0xf4434) {
    iVar4 = (**(code **)(*param_1 + 4))();
    if (iVar4 != 0x105bd) {
      local_f8 = 0x405d16;
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
      param_1 = (int *)0x0;
    }
    if (param_1[5] == 0x6a7) {
      FUN_00406460();
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_d4);
  return;
}


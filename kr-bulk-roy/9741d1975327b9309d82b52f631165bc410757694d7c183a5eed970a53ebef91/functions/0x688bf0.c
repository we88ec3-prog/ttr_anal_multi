
void FUN_00688bf0(int param_1)

{
  code *pcVar1;
  int iVar2;
  undefined2 *puVar3;
  int iVar4;
  int in_ECX;
  int *piVar5;
  int in_EDX;
  undefined4 unaff_EBX;
  undefined4 *unaff_ESI;
  undefined8 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined2 *puVar10;
  undefined2 *puVar11;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  undefined4 local_60;
  int local_5c;
  uint uStack_38;
  void *pvStack_30;
  undefined4 uStack_20;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0094854a;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_74;
  ExceptionList = &local_14;
  local_70 = param_1;
  local_6c = in_EDX;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590();
    uStack_8c = 0x688c5d;
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  if ((param_1 == 1) && (iVar2 = DAT_00f94300 + 0x16f8, iVar2 != 0)) {
    if (in_EDX - 1U < 100) {
      iVar4 = in_EDX * 0x20 + iVar2;
      if (((*(int *)(in_EDX * 0x20 + 0xc + iVar2) != 0) && (*(int *)(iVar4 + 8) != 0)) &&
         (iVar4 != 0)) {
        if ((DAT_00f8d9a4 & 1) == 0) {
          DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
          local_c = 2;
          FUN_0051c120();
          uStack_8c = 0x688d8b;
          _atexit((_func_4879 *)&LAB_00bccc90);
        }
        local_c = 0xffffffff;
        local_64 = *(int *)(iVar4 + 0xc);
        uStack_8c = 0x688db0;
        FUN_008438c0();
        if (((local_74 != DAT_00f8d91c) && (local_68 = *(int *)(local_74 + 0x10), local_68 != 0)) &&
           (local_74 = *(int *)(local_68 + 0x54), local_74 != 0)) {
          uVar6 = FUN_00520e10();
          if (((int)uVar6 != 0) && (*(int *)((int)((ulonglong)uVar6 >> 0x20) + 0x40) == 0)) {
            uStack_8c = *(undefined4 *)(iVar4 + 0x10);
            local_5c = 1;
            local_64 = 0;
            uStack_90 = 0x688e10;
            FUN_00409560();
            uStack_90 = 0x688e17;
            iVar2 = FUN_004dc700();
            if (iVar2 != 0) {
              local_64 = *(int *)(iVar2 + 0x30);
              local_5c = local_64 + 1;
              if (0x14 < local_5c) goto LAB_006891a6;
            }
            if (*(int *)(local_74 + 8) - 1U < 0x2b) {
              local_60 = FUN_00520f40();
            }
            else {
              local_60 = 0;
            }
            FUN_0067a460();
            iVar2 = FUN_00514ea0();
            if (iVar2 != 0) {
              puVar10 = (undefined2 *)0x0;
              uStack_8c = 0x688e88;
              (**(code **)(**(int **)(in_ECX + 0x140) + 0x94))();
              uStack_8c = *(undefined4 *)(iVar4 + 0x14);
              uStack_90 = *(undefined4 *)(iVar4 + 0x10);
              (**(code **)(**(int **)(in_ECX + 300) + 0x19c))
                        (*(undefined4 *)(iVar4 + 4),*(undefined4 *)(iVar4 + 0xc));
              (**(code **)(**(int **)(in_ECX + 300) + 200))();
              uVar9 = *(undefined4 *)(iVar4 + 0x14);
              uVar8 = *(undefined4 *)(iVar4 + 0x10);
              FUN_00409560(uVar8,uVar9);
              iVar2 = FUN_004dc700(uVar8,uVar9);
              if (iVar2 == 0) {
                uVar9 = 0;
              }
              else {
                uVar9 = *(undefined4 *)(iVar2 + 0x30);
              }
              if (7 < (uint)unaff_ESI[5]) {
                unaff_ESI = (undefined4 *)*unaff_ESI;
              }
              uVar8 = 0x18;
              FUN_00585620(0x18,unaff_ESI);
              FUN_00585330(uVar8);
              uVar8 = FUN_00483f00();
              uStack_20 = 3;
              FUN_00757800(uVar8);
              uStack_20 = 0xffffffff;
              FUN_004fa440();
              (**(code **)(**(int **)(in_ECX + 0x130) + 200))();
              FUN_0067a460();
              uVar8 = *(undefined4 *)(puVar10 + 0x2e);
              uVar7 = *(undefined4 *)(puVar10 + 4);
              puVar11 = puVar10;
              FUN_0067a460(uVar8,uVar7,uVar8,uVar9);
              local_6c = FUN_00515550(uVar7,uVar8,uVar9);
              iVar2 = FUN_0067a460();
              FUN_0062db10(&stack0xffffff84);
              if (puVar11 == *(undefined2 **)(iVar2 + 0x70)) {
                puVar3 = (undefined2 *)0x0;
              }
              else {
                puVar3 = puVar11 + 8;
              }
              iVar2 = *(int *)(puVar3 + 2);
              if (iVar2 != 0) {
                iVar4 = FUN_00404ba0();
                puVar11 = (undefined2 *)0x0;
                if (*(int *)(iVar4 + 0x6920) != -0x16f8) {
                  puVar11 = (undefined2 *)FUN_00508e40(iVar2);
                }
                iVar4 = iVar2;
                FUN_004034e0(iVar2);
                iVar4 = FUN_00523230(iVar4);
                if (iVar4 == 0) {
                  iVar2 = *(int *)(*(int *)(in_ECX + 0x164) + 0xcc);
                  if (iVar2 != 0) {
                    FUN_006438f0(iVar2);
                  }
                  FUN_00749920(*(undefined4 *)(in_ECX + 0x164));
                  (**(code **)(**(int **)(in_ECX + 0x164) + 200))();
                  uVar9 = 0x1a;
                  FUN_00585620(0x1a);
                  FUN_00585330(uVar9);
                  uVar9 = FUN_004068f0();
                  uStack_20 = 4;
                  FUN_00757800(uVar9);
                  uStack_20 = 0xffffffff;
                  FUN_004fa440();
                  piVar5 = *(int **)(in_ECX + 0x134);
                }
                else {
                  *(undefined4 *)(in_ECX + 0xfc) = *(undefined4 *)(puVar10 + 4);
                  *(undefined2 *)(in_ECX + 0x100) = *puVar10;
                  *(undefined4 *)(in_ECX + 0x104) = 0xffffffff;
                  *(undefined4 *)(in_ECX + 0x108) = *(undefined4 *)(puVar10 + 0x2e);
                  *(int *)(in_ECX + 0x110) = local_70;
                  *(undefined4 *)(in_ECX + 0x10c) = unaff_EBX;
                  *(undefined1 *)(in_ECX + 0x11c) = (undefined1)local_74;
                  *(int *)(in_ECX + 0x120) = iVar2;
                  *(undefined2 **)(in_ECX + 0x124) = puVar11;
                  *(int *)(in_ECX + 0x128) = local_6c;
                  FUN_00687f30(in_ECX,in_ECX + 0xfc);
                  FUN_00749920(*(undefined4 *)(in_ECX + 0x164));
                  piVar5 = *(int **)(in_ECX + 0x164);
                }
                (**(code **)(*piVar5 + 200))();
              }
              (**(code **)(**(int **)(in_ECX + 0x140) + 0x94))(1);
              (**(code **)(**(int **)(in_ECX + 0x140) + 200))();
              (**(code **)(**(int **)(in_ECX + 0x13c) + 0x90))(1);
              (**(code **)(**(int **)(in_ECX + 0x13c) + 200))();
              iVar2 = FUN_00891268(0x1c);
              if (iVar2 != 0) {
                FUN_00753e00(0xf4369,*(undefined4 *)(in_ECX + 0xf8));
              }
              FUN_004072a0();
              iVar2 = FUN_00891268(0x1c);
              if (iVar2 != 0) {
                FUN_00753e00(0xf4368,puVar11);
              }
              FUN_004072a0();
              *(undefined4 *)(in_ECX + 0xf4) = uStack_8c;
              *(undefined2 **)(in_ECX + 0xf8) = puVar11;
              FUN_00687de0();
              goto LAB_006891b9;
            }
          }
        }
LAB_006891a6:
        uStack_8c = 0x6891ab;
        FUN_00585620();
        uStack_8c = 0x6891b2;
        FUN_00585330();
        goto LAB_006891b2;
      }
    }
    else {
      uStack_8c = 0x688d5f;
      FUN_006edb60();
    }
    local_6c = 0x321;
    iVar2 = FUN_00585620();
    uStack_8c = 0x688d41;
    FUN_005740f0();
    if (local_70 == *(int *)(iVar2 + 4)) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
  }
  else {
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_c = 1;
      uStack_8c = 0x688ca8;
      FUN_00584c40();
      uStack_8c = 0x688cb2;
      _atexit((_func_4879 *)&LAB_00bcf390);
    }
    local_c = 0xffffffff;
    local_6c = 0x321;
    uStack_8c = 0x688cd8;
    FUN_005740f0();
    if (local_70 == DAT_00fe5ac8) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
  }
LAB_006891b2:
  FUN_00687e10();
LAB_006891b9:
  ExceptionList = pvStack_30;
  __security_check_cookie(uStack_38 ^ (uint)&uStack_90);
  return;
}



void FUN_0067ac10(int param_1)

{
  undefined4 *puVar1;
  code *pcVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  int in_ECX;
  int in_EDX;
  int unaff_EDI;
  uint uVar10;
  undefined4 uVar11;
  uint uStack_7c;
  int iVar12;
  uint local_6c;
  uint local_68;
  int local_64;
  int local_60;
  uint local_5c;
  undefined4 local_58;
  undefined4 uStack_2c;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00945e6c;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_6c;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xffffff88;
  ExceptionList = &local_14;
  local_64 = in_EDX;
  local_60 = in_ECX;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  if ((in_ECX == 1) && (iVar4 = DAT_00f94300 + 0x16f8, iVar4 != 0)) {
    if (in_EDX - 1U < 100) {
      puVar1 = (undefined4 *)(in_EDX * 0x20 + iVar4);
      if (((*(int *)(in_EDX * 0x20 + 0xc + iVar4) != 0) && (puVar1[2] != 0)) &&
         (puVar1 != (undefined4 *)0x0)) {
        switch(*puVar1) {
        case 2:
        case 0x28:
        case 0x29:
        case 0x2a:
        case 0x2b:
          local_5c = puVar1[4];
          local_58 = puVar1[5];
          local_68 = 0;
          iVar4 = FUN_00409560();
          FUN_004dd400(iVar4,&local_6c,&local_5c);
          if ((local_6c != *(uint *)(iVar4 + 4)) && (iVar4 = *(int *)(local_6c + 0x18), iVar4 != 0))
          {
            local_68 = *(int *)(iVar4 + 0x48) - *(int *)(iVar4 + 0x44) >> 3;
          }
          local_6c = puVar1[1];
          iVar4 = FUN_004034e0();
          FUN_008438c0(&local_6c);
          if (((local_5c != *(uint *)(iVar4 + 4)) &&
              (uVar10 = *(uint *)(local_5c + 0x10), local_5c = uVar10, uVar10 != 0)) &&
             (uVar5 = FUN_00520e70(), local_68 < uVar5)) {
            iVar4 = puVar1[3];
            local_6c = local_6c & 0xffffff00;
            (**(code **)(**(int **)(param_1 + 0xf4) + 0x19c))(puVar1[1],iVar4,puVar1[4],puVar1[5]);
            (**(code **)(**(int **)(param_1 + 0xf4) + 200))();
            FUN_00757710();
            (**(code **)(**(int **)(param_1 + 0xfc) + 200))();
            uVar11 = *(undefined4 *)(uVar10 + 8);
            iVar6 = FUN_0067a460();
            uStack_7c._1_3_ = (undefined3)(uVar3 >> 8);
            switch(uVar11) {
            case 0x11:
            case 0x12:
            case 0x13:
            case 0x20:
            case 0x24:
            case 0x25:
            case 0x28:
            case 0x29:
            case 0x2a:
              uVar10 = local_6c;
              if ((undefined4 *)(iVar6 + 0x40) == (undefined4 *)0x0) goto switchD_0067aebd_caseD_14;
              FUN_00404c10();
              iVar7 = FUN_0051d6d0();
              if (iVar7 == 0) goto LAB_0067b154;
              iVar8 = FUN_00404ba0();
              iVar12 = 0;
              if (*(int *)(iVar8 + 0x6920) != -0x16f8) {
                iVar12 = FUN_00508e40(*(undefined4 *)(iVar6 + 0x44));
              }
              (**(code **)(**(int **)(param_1 + 0xf8) + 0x19c))
                        (*(undefined4 *)(iVar6 + 0x44),*(undefined4 *)(iVar6 + 0x40),0,0);
              (**(code **)(**(int **)(param_1 + 0xf8) + 200))();
              FUN_00757800(iVar7);
              (**(code **)(**(int **)(param_1 + 0x100) + 200))();
              FUN_00757710();
              FUN_007597b0(0);
              FUN_007597b0(1);
              (**(code **)(**(int **)(param_1 + 0x104) + 200))();
              if (iVar4 < *(int *)(iVar6 + 0x48)) {
                uVar11 = 0xffff0000;
              }
              else {
                uVar11 = 0xffffffff;
              }
              *(undefined4 *)(*(int *)(param_1 + 0x100) + 0x154) = uVar11;
              (**(code **)(**(int **)(param_1 + 0x100) + 200))();
              *(undefined4 *)(*(int *)(param_1 + 0x104) + 0x154) = uVar11;
              (**(code **)(**(int **)(param_1 + 0x104) + 200))();
              (**(code **)(**(int **)(param_1 + 0xf8) + 0xd0))();
              (**(code **)(**(int **)(param_1 + 0x100) + 0xd0))();
              (**(code **)(**(int **)(param_1 + 0x104) + 0xd0))();
              uVar11 = 0x1a;
              FUN_00585620(0x1a);
              FUN_00585330(uVar11);
              uVar11 = FUN_004068f0();
              uStack_2c = 2;
              FUN_00757800(uVar11);
              uStack_2c = 0xffffffff;
              FUN_004fa440();
              (**(code **)(**(int **)(param_1 + 0x108) + 200))();
              if (iVar12 < *(int *)(iVar6 + 0x48)) goto LAB_0067b154;
              uStack_7c = CONCAT31(uStack_7c._1_3_,1);
              break;
            default:
switchD_0067aebd_caseD_14:
              iVar4 = FUN_00404ba0();
              uVar11 = *(undefined4 *)(uVar10 + 0x5c);
              iVar4 = *(int *)(iVar4 + 0x6864);
              iVar6 = unaff_EDI + 1;
              uVar9 = FUN_0067a460(uVar11,iVar6);
              iVar6 = FUN_005155b0(uVar9,uVar11,iVar6);
              if (iVar6 <= iVar4) {
                uStack_7c = CONCAT31(uStack_7c._1_3_,1);
                uVar3 = uStack_7c;
              }
              uStack_7c = uVar3;
              uVar11 = 0x1a;
              FUN_00585620(0x1a);
              FUN_00585330(uVar11);
              uVar11 = FUN_004068f0();
              local_1c = 3;
              FUN_00757800(uVar11);
              local_1c = 0xffffffff;
              FUN_004fa440();
              (**(code **)(**(int **)(param_1 + 0x108) + 200))();
              (**(code **)(**(int **)(param_1 + 0xf8) + 0xd4))();
              (**(code **)(**(int **)(param_1 + 0x100) + 0xd4))();
              (**(code **)(**(int **)(param_1 + 0x104) + 0xd4))();
              uVar3 = uStack_7c;
              if ((char)uStack_7c == '\0') {
LAB_0067b154:
                uStack_7c = uVar3;
                uVar11 = 0x29a;
                FUN_00585620(0x29a);
                FUN_00585330(uVar11);
                FUN_0067b560(param_1);
              }
            }
            (**(code **)(**(int **)(param_1 + 0x10c) + 0x90))(uStack_7c);
            (**(code **)(**(int **)(param_1 + 0x10c) + 200))();
            FUN_007597b0(0);
            (**(code **)(**(int **)(param_1 + 0x118) + 0x94))(1);
            (**(code **)(**(int **)(param_1 + 0x118) + 200))();
            iVar4 = FUN_00891268(0x1c);
            if (iVar4 != 0) {
              FUN_00753e00(0xf4369,*(undefined4 *)(param_1 + 0x114));
            }
            FUN_004072a0();
            iVar4 = FUN_00891268(0x1c);
            if (iVar4 != 0) {
              FUN_00753e00(0xf4368,local_64);
            }
            FUN_004072a0();
            *(int *)(param_1 + 0x110) = local_60;
            *(int *)(param_1 + 0x114) = local_64;
            goto LAB_0067b25e;
          }
        }
        uVar11 = 0x299;
        FUN_00585620(0x299);
        FUN_00585330(uVar11);
        goto LAB_0067b254;
      }
    }
    else {
      FUN_006edb60(&DAT_00c0ddc0);
    }
    local_64 = 0x321;
    iVar4 = FUN_00585620();
    FUN_005740f0(&local_64);
    if (local_60 == *(int *)(iVar4 + 4)) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
  }
  else {
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_c = 1;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
    }
    local_c = 0xffffffff;
    local_64 = 0x321;
    FUN_005740f0(&local_64);
    if (local_60 == DAT_00fe5ac8) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
  }
LAB_0067b254:
  FUN_0067b560(param_1);
LAB_0067b25e:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_6c);
  return;
}


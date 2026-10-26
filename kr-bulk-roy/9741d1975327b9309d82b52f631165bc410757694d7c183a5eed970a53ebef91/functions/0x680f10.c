
void FUN_00680f10(void)

{
  code *pcVar1;
  int iVar2;
  undefined4 *puVar3;
  int in_ECX;
  int unaff_ESI;
  int iVar4;
  int unaff_EDI;
  undefined4 uVar5;
  int iStack_74;
  int local_70 [2];
  int local_68;
  uint local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 uStack_54;
  uint uStack_50;
  undefined4 uStack_48;
  uint uStack_34;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093cb44;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&iStack_74;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffff80);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  if ((*(int *)(in_ECX + 0xf8) == 1) && (DAT_00f94300 + 0x16f8 != 0)) {
    if (*(int *)(in_ECX + 0xfc) - 1U < 100) {
      iVar4 = *(int *)(in_ECX + 0xfc) * 0x20 + DAT_00f94300 + 0x16f8;
      if (((*(int *)(iVar4 + 0xc) != 0) && (*(int *)(iVar4 + 8) != 0)) && (iVar4 != 0)) {
        local_70[0] = *(int *)(iVar4 + 4);
        iVar2 = FUN_004034e0();
        FUN_008438c0(local_70);
        if ((local_68 != *(int *)(iVar2 + 4)) &&
           (local_64 = *(uint *)(local_68 + 0x10), local_64 != 0)) {
          local_60 = *(undefined4 *)(iVar4 + 0x10);
          local_5c = *(undefined4 *)(iVar4 + 0x14);
          iVar2 = FUN_00409560();
          FUN_004dd400(iVar2,local_70,&local_60);
          if ((local_70[0] != *(int *)(iVar2 + 4)) &&
             (local_70[0] = *(int *)(local_70[0] + 0x18), local_70[0] != 0)) {
            iVar2 = *(int *)(local_70[0] + 0x30);
            (**(code **)(**(int **)(in_ECX + 0x104) + 0x19c))
                      (*(undefined4 *)(iVar4 + 4),*(undefined4 *)(iVar4 + 0xc),
                       *(undefined4 *)(iVar4 + 0x10),*(undefined4 *)(iVar4 + 0x14));
            (**(code **)(**(int **)(in_ECX + 0x104) + 200))();
            if (iVar2 < 2) {
              FUN_00757800(iStack_74 + 0x98);
            }
            else {
              puVar3 = (undefined4 *)(iStack_74 + 0x98);
              if (7 < *(uint *)(iStack_74 + 0xac)) {
                puVar3 = (undefined4 *)*puVar3;
              }
              uVar5 = 0x18;
              FUN_00585620(0x18,puVar3);
              FUN_00585330(uVar5);
              uVar5 = FUN_00483f00();
              local_1c = 1;
              FUN_00757800(uVar5);
              local_1c = 0xffffffff;
              FUN_004fa440();
            }
            (**(code **)(**(int **)(in_ECX + 0x108) + 200))();
            puVar3 = (undefined4 *)(in_ECX + 0x10c);
            local_68 = *(int *)(unaff_EDI + 0x48) - *(int *)(unaff_EDI + 0x44) >> 3;
            iVar4 = 0;
            do {
              if (iVar4 < local_68) {
                iVar2 = FUN_004dc9d0(iVar4);
                iVar2 = *(int *)(iVar2 + 4);
                local_70[0] = iVar2;
                if (iVar2 == 0) goto LAB_006811b9;
                FUN_004034e0(iVar2);
                iVar2 = FUN_00523230(iVar2);
                if (iVar2 == 0) goto LAB_006811b9;
                (**(code **)(*(int *)*puVar3 + 0x19c))(local_70[0],0xffffffff,0,0);
                FUN_00444090();
                (**(code **)(*(int *)*puVar3 + 200))();
                in_ECX = unaff_ESI;
              }
              else {
LAB_006811b9:
                (**(code **)(*(int *)*puVar3 + 0x19c))(0xffffffff,0xffffffff,0,0);
                FUN_00757710();
                (**(code **)(*(int *)*puVar3 + 200))();
              }
              iVar4 = iVar4 + 1;
              puVar3 = puVar3 + 1;
            } while (iVar4 < 3);
            if ((DAT_00fe3008 & 1) == 0) {
              DAT_00fe3008 = DAT_00fe3008 | 1;
              local_1c = 2;
              FUN_00513fa0();
              _atexit((_func_4879 *)&LAB_00bcff80);
              local_1c = 0xffffffff;
            }
            iVar4 = FUN_005156e0(&DAT_00fe3010,*(undefined4 *)(iStack_74 + 0x5c));
            iVar2 = FUN_00585620();
            if (iVar4 == 0) {
              FUN_005740f0(&stack0xffffff84);
              if (local_70[0] == *(int *)(iVar2 + 4)) {
                pcVar1 = (code *)swi(3);
                (*pcVar1)();
                return;
              }
              uVar5 = FUN_004068f0();
              local_1c = 4;
              FUN_00757800(uVar5);
              local_1c = 0xffffffff;
              if (7 < uStack_50) {
                FUN_0089120c(local_64);
              }
              local_64 = local_64 & 0xffff0000;
              uStack_50 = 7;
              uStack_54 = 0;
              (**(code **)(**(int **)(in_ECX + 0x11c) + 200))();
            }
            else {
              FUN_005740f0(&stack0xffffff84);
              if (local_70[0] == *(int *)(iVar2 + 4)) {
                pcVar1 = (code *)swi(3);
                (*pcVar1)();
                return;
              }
              uVar5 = FUN_004068f0();
              local_1c = 3;
              FUN_00757800(uVar5);
              local_1c = 0xffffffff;
              if (7 < uStack_34) {
                FUN_0089120c(uStack_48);
              }
              (**(code **)(**(int **)(in_ECX + 0x11c) + 200))();
            }
            if (((*(int *)(in_ECX + 0xf8) == -1) || (*(int *)(in_ECX + 0xfc) == -1)) ||
               (*(int *)(in_ECX + 0x100) == -1)) {
              uVar5 = 0;
            }
            else {
              uVar5 = 1;
            }
            (**(code **)(**(int **)(in_ECX + 0x120) + 0x90))(uVar5);
            (**(code **)(**(int **)(in_ECX + 0x120) + 200))();
            (**(code **)(**(int **)(in_ECX + 0x10c) + 0xa0))(0);
            (**(code **)(**(int **)(in_ECX + 0x110) + 0xa0))(0);
            (**(code **)(**(int **)(in_ECX + 0x114) + 0xa0))(0);
            *(undefined4 *)(in_ECX + 0x100) = 0xffffffff;
          }
        }
      }
    }
    else {
      FUN_006edb60(&DAT_00c0ddc0);
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&iStack_74);
  return;
}


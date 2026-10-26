
void FUN_00522b70(int param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  char *_Str1;
  int iVar8;
  int local_a4;
  int local_94;
  undefined **local_90 [17];
  char local_4c;
  uint local_44;
  undefined4 local_34;
  uint local_30;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092610b;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = uVar4;
  FUN_0072ed80(local_90);
  local_8 = 0;
  FUN_0072f110(0);
  if (local_4c == '\0') {
    iVar5 = FUN_0072e2e0("ITEM_USABLE_TABLE");
    if (iVar5 != 0) {
      iVar5 = FUN_0072e360(uVar4);
      while (iVar5 != 0) {
        iVar5 = FUN_007300a0(&DAT_00c0e550);
        if (iVar5 == 0) {
LAB_00522c87:
          local_94 = 0;
        }
        else {
          puVar6 = (undefined4 *)(iVar5 + 0x30);
          if (0xf < *(uint *)(iVar5 + 0x44)) {
            puVar6 = (undefined4 *)*puVar6;
          }
          if (puVar6 == (undefined4 *)0x0) goto LAB_00522c87;
          local_94 = FUN_008917b4(puVar6);
        }
        FUN_008438c0(&local_94);
        if ((local_a4 != *(int *)(param_1 + 4)) && (iVar5 = *(int *)(local_a4 + 0x10), iVar5 != 0))
        {
          iVar7 = FUN_0072e360();
          while (iVar7 != 0) {
            for (iVar1 = *(int *)(iVar7 + 0x94); iVar1 != iVar7 + 0x44;
                iVar1 = *(int *)(iVar1 + 0x50)) {
              _Str1 = (char *)(iVar1 + 0x14);
              if (0xf < *(uint *)(iVar1 + 0x28)) {
                _Str1 = *(char **)_Str1;
              }
              iVar8 = __stricmp(_Str1,"action");
              if (iVar8 == 0) {
                if (iVar1 != 0) {
                  puVar6 = (undefined4 *)(iVar1 + 0x30);
                  if (0xf < *(uint *)(iVar1 + 0x44)) {
                    puVar6 = (undefined4 *)*puVar6;
                  }
                  if (puVar6 != (undefined4 *)0x0) {
                    iVar7 = FUN_008917b4(puVar6);
                    goto LAB_00522d16;
                  }
                }
                break;
              }
            }
            iVar7 = 0;
LAB_00522d16:
            if (iVar7 - 1U < 0x1b) {
              iVar7 = FUN_00523260();
            }
            else {
              iVar7 = 0;
            }
            local_94 = iVar7;
            if (iVar7 != 0) {
              FUN_005205f0(iVar7);
              piVar2 = *(int **)(iVar5 + 0x14c);
              if (&local_94 < piVar2) {
                piVar3 = *(int **)(iVar5 + 0x148);
                if (&local_94 < piVar3) goto LAB_00522db8;
                if (piVar2 == *(int **)(iVar5 + 0x150)) {
                  FUN_004deab0();
                }
                if (*(undefined4 **)(iVar5 + 0x14c) != (undefined4 *)0x0) {
                  **(undefined4 **)(iVar5 + 0x14c) =
                       *(undefined4 *)
                        (*(int *)(iVar5 + 0x148) + ((int)&local_94 - (int)piVar3 >> 2) * 4);
                }
              }
              else {
LAB_00522db8:
                if (piVar2 == *(int **)(iVar5 + 0x150)) {
                  FUN_004deab0();
                }
                if (*(int **)(iVar5 + 0x14c) != (int *)0x0) {
                  **(int **)(iVar5 + 0x14c) = iVar7;
                }
              }
              *(int *)(iVar5 + 0x14c) = *(int *)(iVar5 + 0x14c) + 4;
            }
            iVar7 = FUN_0072e3c0();
          }
        }
        iVar5 = FUN_0072e3c0();
      }
    }
    local_8 = 0xffffffff;
    local_90[0] = TiXmlDocument::vftable;
    if (0xf < local_30) {
      FUN_0089120c(local_44);
    }
    local_30 = 0xf;
    local_34 = 0;
    local_44 = local_44 & 0xffffff00;
    FUN_0072e040();
  }
  else {
    local_8 = 0xffffffff;
    local_90[0] = TiXmlDocument::vftable;
    if (0xf < local_30) {
      FUN_0089120c(local_44);
    }
    local_30 = 0xf;
    local_34 = 0;
    local_44 = local_44 & 0xffffff00;
    FUN_0072e040();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



void FUN_00505570(int param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined1 auStack_ac [4];
  int local_a8;
  int local_a4;
  int local_a0;
  undefined4 local_9c;
  undefined **local_98 [17];
  char local_54;
  uint local_4c;
  undefined4 local_3c;
  uint local_38;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0092287b;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_ac;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xffffff48;
  ExceptionList = &local_14;
  local_a4 = param_1;
  FUN_0072ee30(local_98);
  local_c = 0;
  FUN_0072f110(0);
  if (local_54 == '\0') {
    iVar4 = FUN_0072e2e0("QuestTalk");
    if (iVar4 == 0) {
      FUN_006edb60(&DAT_00c0dc50);
      local_c = 0xffffffff;
      local_98[0] = TiXmlDocument::vftable;
      if (0xf < local_38) {
        FUN_0089120c(local_4c);
      }
      local_38 = 0xf;
      local_3c = 0;
      local_4c = local_4c & 0xffffff00;
      FUN_0072e040();
    }
    else {
      local_a8 = FUN_00506a30(uVar3);
      if (local_a8 != 0) {
        do {
          iVar4 = FUN_007300a0(&DAT_00bed1d0);
          if (iVar4 == 0) {
LAB_005056f1:
            local_9c = 0;
          }
          else {
            puVar5 = (undefined4 *)(iVar4 + 0x30);
            if (0xf < *(uint *)(iVar4 + 0x44)) {
              puVar5 = (undefined4 *)*puVar5;
            }
            if (puVar5 == (undefined4 *)0x0) goto LAB_005056f1;
            local_9c = FUN_008917b4(puVar5);
          }
          iVar4 = local_a4;
          FUN_00503d20(&local_9c);
          iVar2 = local_a0;
          if ((local_a0 != *(int *)(iVar4 + 4)) && (local_a0 != -0x10)) {
            iVar4 = FUN_007300a0("givertalk");
            if (iVar4 == 0) {
LAB_0050574b:
              uVar6 = 0;
            }
            else {
              puVar5 = (undefined4 *)(iVar4 + 0x30);
              if (0xf < *(uint *)(iVar4 + 0x44)) {
                puVar5 = (undefined4 *)*puVar5;
              }
              if (puVar5 == (undefined4 *)0x0) goto LAB_0050574b;
              uVar6 = FUN_008917b4(puVar5);
            }
            *(undefined4 *)(iVar2 + 0x40) = uVar6;
            iVar4 = FUN_007300a0("givertotalk");
            if (iVar4 == 0) {
LAB_00505778:
              uVar6 = 0;
            }
            else {
              puVar5 = (undefined4 *)(iVar4 + 0x30);
              if (0xf < *(uint *)(iVar4 + 0x44)) {
                puVar5 = (undefined4 *)*puVar5;
              }
              if (puVar5 == (undefined4 *)0x0) goto LAB_00505778;
              uVar6 = FUN_008917b4(puVar5);
            }
            *(undefined4 *)(iVar2 + 0x44) = uVar6;
            iVar4 = FUN_007300a0("finishertalk");
            if (iVar4 == 0) {
LAB_005057a5:
              uVar6 = 0;
            }
            else {
              puVar5 = (undefined4 *)(iVar4 + 0x30);
              if (0xf < *(uint *)(iVar4 + 0x44)) {
                puVar5 = (undefined4 *)*puVar5;
              }
              if (puVar5 == (undefined4 *)0x0) goto LAB_005057a5;
              uVar6 = FUN_008917b4(puVar5);
            }
            *(undefined4 *)(iVar2 + 0x48) = uVar6;
          }
          for (piVar1 = *(int **)(local_a8 + 0x40); piVar1 != (int *)0x0;
              piVar1 = (int *)piVar1[0x10]) {
            iVar4 = (**(code **)(*piVar1 + 0x18))();
            if (iVar4 != 0) {
              local_a8 = (**(code **)(*piVar1 + 0x18))();
              goto LAB_005057cf;
            }
          }
          local_a8 = 0;
LAB_005057cf:
        } while (local_a8 != 0);
        local_a8 = 0;
      }
      local_c = 0xffffffff;
      local_98[0] = TiXmlDocument::vftable;
      if (0xf < local_38) {
        FUN_0089120c(local_4c);
      }
      local_38 = 0xf;
      local_3c = 0;
      local_4c = local_4c & 0xffffff00;
      FUN_0072e040();
    }
  }
  else {
    local_c = 0xffffffff;
    local_98[0] = TiXmlDocument::vftable;
    if (0xf < local_38) {
      FUN_0089120c(local_4c);
    }
    local_38 = 0xf;
    local_3c = 0;
    local_4c = local_4c & 0xffffff00;
    FUN_0072e040();
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_ac);
  return;
}


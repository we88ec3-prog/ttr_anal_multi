
void FUN_00745c80(int param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  int in_ECX;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_1c;
  
  if (*(int **)(in_ECX + 0x1c) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x1c) + 0x1c))(1);
    *(undefined4 *)(in_ECX + 0x1c) = 0;
  }
  if (param_1 - 0xc9U < 0x62) {
    if (*(int *)(in_ECX + 0x60) != 0) {
      if (param_1 == 0xd5) {
        FUN_008fed10();
        FUN_008fed10();
      }
      else if ((param_1 == 0xd3) || (param_1 == 0xd4)) {
        FUN_008fed10();
      }
      else if ((param_1 == 0xd2) || (param_1 == 0xd1)) {
        FUN_008fed10();
      }
    }
    pvVar1 = _malloc(0x1c);
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_0076e490(param_1);
      *(undefined4 *)(in_ECX + 0x1c) = uVar2;
      return;
    }
  }
  else if (param_1 - 0x12dU < 0x62) {
    puVar3 = _malloc(0xc);
    if (puVar3 != (undefined4 *)0x0) {
      DAT_00fba828 = DAT_00fba828 + 1;
      puVar3[1] = DAT_00fba828;
      puVar3[2] = param_1;
      *puVar3 = FoxUI::FXUIDockInfoOutter::vftable;
      *(undefined4 **)(in_ECX + 0x1c) = puVar3;
      return;
    }
  }
  else if (param_1 - 0x191U < 0x62) {
    iVar4 = *(int *)(in_ECX + 0x60);
    local_1c = 6;
    if ((iVar4 != 0) && (param_1 == 0x191)) {
      iVar5 = (*(int *)(in_ECX + 0x10) - *(int *)(in_ECX + 8)) / 2 + *(int *)(in_ECX + 8);
      iVar7 = (*(int *)(in_ECX + 0x14) - *(int *)(in_ECX + 0xc)) / 2 + *(int *)(in_ECX + 0xc);
      iVar6 = (*(int *)(iVar4 + 0x10) - *(int *)(iVar4 + 8)) / 2;
      iVar4 = (*(int *)(*(int *)(in_ECX + 0x60) + 0x14) - *(int *)(*(int *)(in_ECX + 0x60) + 0xc)) /
              2;
      if (iVar5 == iVar6) {
        local_1c = (uint)(iVar4 < iVar7) * 2 + 0xc9;
      }
      else if (iVar7 == iVar4) {
        local_1c = (iVar6 < iVar5) + 0xc9;
      }
      else if ((iVar5 < iVar6) && (iVar7 < iVar4)) {
        local_1c = 0xc9;
      }
      else if ((iVar6 < iVar5) && (iVar7 < iVar4)) {
        local_1c = 0xca;
      }
      else if ((iVar5 < iVar6) && (iVar4 < iVar7)) {
        local_1c = 0xcb;
      }
      else if ((iVar6 < iVar5) && (iVar4 < iVar7)) {
        local_1c = 0xcc;
      }
    }
    pvVar1 = _malloc(0x20);
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_0076eb50(param_1,local_1c);
      *(undefined4 *)(in_ECX + 0x1c) = uVar2;
      return;
    }
  }
  else {
    puVar3 = _malloc(0xc);
    if (puVar3 != (undefined4 *)0x0) {
      DAT_00fba828 = DAT_00fba828 + 1;
      puVar3[1] = DAT_00fba828;
      *puVar3 = FoxUI::FXUIDockInfo::vftable;
      puVar3[2] = param_1;
      *(undefined4 **)(in_ECX + 0x1c) = puVar3;
      return;
    }
  }
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  return;
}


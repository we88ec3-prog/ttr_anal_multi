
void FUN_00658fe0(int param_1)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  int in_ECX;
  int iVar5;
  int iVar6;
  int local_1c;
  
  if (0x61 < param_1 - 0x191U) {
    FUN_00745c80(param_1);
    return;
  }
  if (*(int **)(in_ECX + 0x1c) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x1c) + 0x1c))(1);
    *(undefined4 *)(in_ECX + 0x1c) = 0;
  }
  iVar2 = *(int *)(in_ECX + 0x60);
  local_1c = 6;
  if ((iVar2 != 0) && (param_1 == 0x191)) {
    iVar5 = (*(int *)(in_ECX + 0x10) - *(int *)(in_ECX + 8)) / 2 + *(int *)(in_ECX + 8);
    iVar6 = (*(int *)(iVar2 + 0x10) - *(int *)(iVar2 + 8)) / 2;
    iVar2 = (*(int *)(iVar2 + 0x14) - *(int *)(iVar2 + 0xc)) / 2;
    if (iVar5 == iVar6) {
      local_1c = (uint)(iVar2 < *(int *)(in_ECX + 0xc)) * 2 + 0xc9;
    }
    else {
      iVar1 = *(int *)(in_ECX + 0xc);
      if (iVar1 == iVar2) {
        local_1c = (iVar6 < iVar5) + 0xc9;
      }
      else if ((iVar5 < iVar6) && (iVar1 < iVar2)) {
        local_1c = 0xc9;
      }
      else if ((iVar6 < iVar5) && (iVar1 < iVar2)) {
        local_1c = 0xca;
      }
      else if ((iVar5 < iVar6) && (iVar2 < iVar1)) {
        local_1c = 0xcb;
      }
      else if ((iVar6 < iVar5) && (iVar2 < iVar1)) {
        local_1c = 0xcc;
      }
    }
  }
  pvVar3 = _malloc(0x20);
  if (pvVar3 == (void *)0x0) {
    *(undefined4 *)(in_ECX + 0x1c) = 0;
    return;
  }
  uVar4 = FUN_0076eb50(param_1,local_1c);
  *(undefined4 *)(in_ECX + 0x1c) = uVar4;
  return;
}


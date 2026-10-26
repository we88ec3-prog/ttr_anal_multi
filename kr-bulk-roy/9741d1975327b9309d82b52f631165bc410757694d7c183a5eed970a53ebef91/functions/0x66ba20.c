
void FUN_0066ba20(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 local_8;
  
  iVar4 = param_1;
  iVar1 = *(int *)(param_1 + 0xf0);
  if (iVar1 != 0) {
    if (*(int *)(iVar1 + 0xcc) == 0) {
      local_8 = -1;
    }
    else {
      iVar2 = *(int *)(*(int *)(iVar1 + 0xcc) + 0xdc);
      if (iVar2 == 0) {
        local_8 = -1;
      }
      else {
        local_8 = *(int *)(iVar2 + 0x20);
      }
    }
    uVar3 = (*(int *)(param_1 + 0x100) - *(int *)(param_1 + 0xfc)) / 0x50;
    if (DAT_00d63dcc != -1) {
      local_8 = DAT_00d63dcc;
    }
    if (*(int *)(iVar1 + 0xcc) != 0) {
      FUN_00408920(*(int *)(iVar1 + 0xcc),uVar3);
    }
    uVar7 = 0;
    if (uVar3 != 0) {
      param_1 = 0;
      do {
        iVar1 = *(int *)(param_1 + *(int *)(iVar4 + 0xfc));
        iVar2 = *(int *)(*(int *)(iVar4 + 0xf0) + 0xcc);
        if ((((iVar2 == 0) || ((int)uVar7 < 0)) ||
            (*(int *)(iVar2 + 0xac) - *(int *)(iVar2 + 0xa8) >> 2 <= (int)uVar7)) ||
           (iVar5 = *(int *)(*(int *)(iVar2 + 0xa8) + uVar7 * 4), iVar5 == 0)) {
          iVar5 = 0;
        }
        else {
          *(int *)(iVar5 + 0x20) = iVar1;
          uVar6 = iVar1 + 1;
          if (uVar6 <= *(uint *)(iVar2 + 0xe4)) {
            uVar6 = *(uint *)(iVar2 + 0xe4);
          }
          *(uint *)(iVar2 + 0xe4) = uVar6;
        }
        if (iVar5 != 0) {
          FUN_00757710();
        }
        param_1 = param_1 + 0x50;
        uVar7 = uVar7 + 1;
      } while (uVar7 < uVar3);
    }
    if (*(int *)(*(int *)(iVar4 + 0xf0) + 0xcc) != 0) {
      FUN_0042c8e0(local_8);
    }
    FUN_00749920(*(undefined4 *)(iVar4 + 0xf0));
    (**(code **)(**(int **)(iVar4 + 0xf0) + 200))();
  }
  return;
}


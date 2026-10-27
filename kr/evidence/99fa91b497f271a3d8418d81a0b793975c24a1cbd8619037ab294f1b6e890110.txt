
void FUN_00648e60(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  int in_ECX;
  uint uVar5;
  uint uVar6;
  int *piVar7;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009463ce;
  local_14 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffffc8;
  iVar4 = *(int *)(param_1 + 0x10);
  if (iVar4 == 0x57a) {
    uVar5 = 0;
    uVar6 = *(int *)(in_ECX + 0xe4) - *(int *)(in_ECX + 0xe0) >> 2;
    if (uVar6 != 0) {
      piVar7 = *(int **)(in_ECX + 0xe0);
      while ((*piVar7 == 0 || (*(int *)(param_1 + 8) != *(int *)(*piVar7 + 0x20)))) {
        uVar5 = uVar5 + 1;
        piVar7 = piVar7 + 1;
        if (uVar6 <= uVar5) {
          return;
        }
      }
      uVar6 = DAT_00fb725c & 1;
      ExceptionList = &local_14;
      *(undefined4 *)(in_ECX + 0xd8) =
           *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0xe0) + uVar5 * 4) + 0x24c);
      if (uVar6 == 0) {
        DAT_00fb725c = DAT_00fb725c | 1;
        local_c = 0;
        FUN_004a79a0(uVar2);
        _atexit((_func_4879 *)&DAT_00bccf80);
      }
      local_c = 0xffffffff;
      uVar5 = DAT_00fb7264 - DAT_00fb7260 >> 2;
      uVar2 = 0;
      if (uVar5 != 0) {
        do {
          piVar7 = *(int **)(DAT_00fb7260 + uVar2 * 4);
          if (*piVar7 == *(int *)(in_ECX + 0xd8)) {
            if (piVar7 != (int *)0x0) {
              FUN_00404ba0();
              uVar2 = FUN_004a7810(piVar7);
              iVar4 = FUN_004d43d0();
              FUN_0041ce80((int)(uVar2 & 0xff) <= iVar4);
            }
            break;
          }
          uVar2 = uVar2 + 1;
        } while (uVar2 < uVar5);
      }
      FUN_00690fa0(*(undefined4 *)(in_ECX + 0xd8));
    }
  }
  else if (iVar4 == 0x57b) {
    uVar2 = 0;
    uVar5 = *(int *)(in_ECX + 0xe4) - *(int *)(in_ECX + 0xe0) >> 2;
    if (uVar5 != 0) {
      piVar7 = *(int **)(in_ECX + 0xe0);
      while ((*piVar7 == 0 || (*(int *)(param_1 + 8) != *(int *)(*piVar7 + 0x20)))) {
        uVar2 = uVar2 + 1;
        piVar7 = piVar7 + 1;
        if (uVar5 <= uVar2) {
          return;
        }
      }
      iVar4 = *(int *)(in_ECX + 0xa8);
      ExceptionList = &local_14;
      puVar3 = (undefined4 *)FUN_00649120(in_ECX);
      FUN_0064ba50(*(undefined4 *)(iVar4 + 8),*(undefined4 *)(iVar4 + 0xc),
                   *(undefined4 *)(iVar4 + 0x10),*(undefined4 *)(iVar4 + 0x14),*puVar3,puVar3[1],
                   puVar3[2],puVar3[3]);
      FUN_0064ab00(*(undefined4 *)(in_ECX + 0xa8),
                   *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0xe0) + uVar2 * 4) + 0x24c));
      ExceptionList = local_14;
      return;
    }
  }
  else if ((iVar4 == 0xf4391) && (*(int *)(param_1 + 0x14) == 0x6a7)) {
    ExceptionList = &local_14;
    puVar3 = (undefined4 *)FUN_00891268(0x18);
    if (puVar3 != (undefined4 *)0x0) {
      uVar1 = *(undefined4 *)(in_ECX + 0xd8);
      puVar3[3] = 0;
      puVar3[1] = 0xffffffff;
      puVar3[2] = 0xffffffff;
      puVar3[4] = 0xf4390;
      *puVar3 = FoxUI::FXUIEventI1::vftable;
      puVar3[5] = uVar1;
    }
    FUN_00404aa0();
    FUN_00750020();
    (**(code **)(**(int **)(in_ECX + 0xa8) + 0xd4))();
    ExceptionList = local_14;
    return;
  }
  ExceptionList = local_14;
  return;
}


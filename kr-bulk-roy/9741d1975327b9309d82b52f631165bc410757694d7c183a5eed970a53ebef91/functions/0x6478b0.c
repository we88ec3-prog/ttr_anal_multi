
void FUN_006478b0(int param_1)

{
  ushort uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int in_ECX;
  int iVar4;
  int iVar5;
  ushort *puVar6;
  
  if (*(int *)(param_1 + 0x10) == 0x578) {
    if (*(int *)(param_1 + 8) != *(int *)(*(int *)(in_ECX + 0x100) + 0x20)) {
      return;
    }
    puVar3 = (undefined4 *)FUN_00891268(0x18);
    if (puVar3 != (undefined4 *)0x0) {
      puVar3[1] = 0xffffffff;
      puVar3[2] = 0xffffffff;
      puVar3[3] = 0;
      puVar3[4] = 0xf4328;
      *puVar3 = FoxUI::FXUIEventB1::vftable;
      *(undefined1 *)(puVar3 + 5) = 0;
      FUN_004072a0();
      return;
    }
  }
  else {
    if (*(int *)(param_1 + 0x10) != 0x641) {
      return;
    }
    if (*(int *)(param_1 + 8) != *(int *)(*(int *)(in_ECX + 0xfc) + 0x20)) {
      return;
    }
    FUN_0040afc0();
    iVar4 = *(int *)(*(int *)(in_ECX + 0xfc) + 0x24c);
    if ((iVar4 == 0) || (iVar4 = *(int *)(iVar4 + 0xcc), iVar4 == 0)) {
      iVar4 = 0;
    }
    else {
      iVar4 = *(int *)(iVar4 + 0xdc);
    }
    puVar6 = (ushort *)(iVar4 + 0xe8);
    if (7 < *(uint *)(iVar4 + 0xfc)) {
      puVar6 = *(ushort **)puVar6;
    }
    iVar4 = 0;
    iVar5 = 0;
    do {
      uVar1 = *puVar6;
      puVar6 = puVar6 + 1;
      if (9 < uVar1 - 0x30) {
        iVar4 = -1;
        break;
      }
      iVar5 = iVar5 + 1;
      iVar4 = (uVar1 - 0x30) + iVar4 * 10;
    } while (iVar5 < 2);
    *(int *)(in_ECX + 0x104) = iVar4;
    puVar3 = (undefined4 *)FUN_00891268(0x18);
    if (puVar3 != (undefined4 *)0x0) {
      uVar2 = *(undefined4 *)(in_ECX + 0x104);
      puVar3[1] = 0xffffffff;
      puVar3[2] = 0xffffffff;
      puVar3[3] = 0;
      puVar3[4] = 0xf43e6;
      *puVar3 = FoxUI::FXUIEventI1::vftable;
      puVar3[5] = uVar2;
      FUN_004072a0();
      return;
    }
  }
  FUN_004072a0();
  return;
}



void FUN_00472fc0(int param_1)

{
  char cVar1;
  char cVar2;
  byte bVar3;
  char cVar4;
  int iVar5;
  undefined4 *puVar6;
  int in_ECX;
  undefined1 uVar7;
  byte bVar8;
  undefined4 uVar9;
  
  if (*(int *)(param_1 + 8) != 0x35f48) {
    return;
  }
  iVar5 = *(int *)(param_1 + 0x10);
  if (iVar5 == 0x578) {
    iVar5 = FUN_00443dc0();
    if ((*(int *)(iVar5 + 0x20) == 0) || (*(char *)(iVar5 + 0x17d) != '\x02')) {
      uVar9 = 0x9d;
      FUN_00443dc0(0x9d);
      iVar5 = FUN_006f1b90(uVar9);
      if (iVar5 != 2) goto LAB_00473198;
    }
    cVar1 = *(char *)(*(int *)(in_ECX + 0x250) + 6);
    cVar2 = *(char *)(*(int *)(in_ECX + 0x250) + 4);
    cVar4 = FUN_00473390();
    FUN_004054c0();
    iVar5 = FUN_00891268(0x20);
    if (iVar5 == 0) {
      uVar9 = 0;
    }
    else {
      uVar9 = FUN_00753e30(0xf4412,*(undefined4 *)(in_ECX + 600),cVar4 - (cVar1 + cVar2 + -1));
    }
    FUN_0058b1a0(0xdb,uVar9);
    *(undefined1 *)(*(int *)(in_ECX + 0x24c) + 600) = 1;
LAB_00473198:
    FUN_004054c0();
    puVar6 = (undefined4 *)FUN_00891268(0x18);
    if (puVar6 == (undefined4 *)0x0) {
      FUN_0058b1a0(0xdb,0);
      return;
    }
    uVar9 = *(undefined4 *)(in_ECX + 0x250);
    puVar6[1] = 0xffffffff;
    puVar6[2] = 0xffffffff;
    puVar6[3] = 0;
    puVar6[4] = 0xf4411;
    *puVar6 = FoxUI::FXUIEventP1::vftable;
    puVar6[5] = uVar9;
    FUN_0058b1a0(0xdb,puVar6);
    return;
  }
  if (iVar5 == 0x57a) {
    if (*(char *)(in_ECX + 0x255) != '\0') {
      return;
    }
    iVar5 = *(int *)(in_ECX + 0x250);
    bVar8 = (*(char *)(iVar5 + 6) + *(char *)(iVar5 + 4)) - 1;
    if (*(byte *)(iVar5 + 5) <= bVar8) {
      return;
    }
    bVar3 = FUN_00473390();
    if (bVar3 <= bVar8) {
      return;
    }
    FUN_004054c0();
    iVar5 = FUN_00891268(0x20);
    if (iVar5 != 0) {
      uVar9 = FUN_00753e30(0xf4412,*(undefined4 *)(in_ECX + 600),1);
      goto LAB_0047307d;
    }
  }
  else {
    if (iVar5 != 0x58c) {
      return;
    }
    if (*(char *)(in_ECX + 0x255) != '\0') {
      return;
    }
    uVar9 = 0x1d;
    FUN_00443dc0(0x1d);
    iVar5 = FUN_006f1b90(uVar9);
    if (iVar5 == 2) {
LAB_00473030:
      uVar7 = *(undefined1 *)(*(int *)(in_ECX + 0x250) + 6);
    }
    else {
      uVar9 = 0x9d;
      FUN_00443dc0(0x9d);
      iVar5 = FUN_006f1b90(uVar9);
      if (iVar5 == 2) goto LAB_00473030;
      uVar7 = 1;
    }
    if (*(char *)(*(int *)(in_ECX + 0x250) + 6) == '\0') {
      return;
    }
    FUN_004054c0();
    iVar5 = FUN_00891268(0x20);
    if (iVar5 != 0) {
      uVar9 = FUN_00753e30(0xf4413,*(undefined4 *)(in_ECX + 600),uVar7);
      goto LAB_0047307d;
    }
  }
  uVar9 = 0;
LAB_0047307d:
  FUN_0058b1a0(0xdb,uVar9);
  *(undefined1 *)(*(int *)(in_ECX + 0x24c) + 600) = 1;
  return;
}



undefined4 FUN_004bc2d0(undefined4 *param_1)

{
  char cVar1;
  byte bVar2;
  undefined4 *puVar3;
  int in_ECX;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 uStack_c;
  
  uStack_c = in_ECX;
  if (*(char *)((int)param_1 + 2) != '\x02') {
    FUN_006edb60(&DAT_00c06fe0);
    uStack_c = CONCAT22(0x19,(undefined2)uStack_c);
    if (DAT_00fba798 == 0) {
      (**(code **)(*DAT_00fba854 + 0x10))(0,(int)&uStack_c + 2,2);
    }
    return 0x80004005;
  }
  puVar5 = (undefined4 *)(in_ECX + 0xbfa8);
  puVar3 = param_1;
  for (iVar4 = 6; puVar3 = puVar3 + 1, iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = *puVar3;
    puVar5 = puVar5 + 1;
  }
  *(undefined2 *)puVar5 = *(undefined2 *)puVar3;
  puVar3 = (undefined4 *)(in_ECX + 0xbfa8);
  puVar5 = (undefined4 *)(DAT_00fe1aa4 + 8);
  for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar5 = puVar5 + 1;
  }
  *(undefined2 *)puVar5 = *(undefined2 *)puVar3;
  cVar1 = *(char *)(in_ECX + 0xbfbc);
  if (cVar1 == '\0') {
    uVar6 = FUN_0040f060();
    FUN_004dfe90(uVar6);
    uStack_c = CONCAT22(0x19,(undefined2)uStack_c);
    if (DAT_00fba798 == 0) {
      (**(code **)(*DAT_00fba854 + 0x10))(0,(int)&uStack_c + 2,2);
    }
    return 0;
  }
  if (cVar1 == '\x01') {
    puVar3 = (undefined4 *)FUN_0040f060();
    FUN_004ddad0(*puVar3,*(undefined1 *)(in_ECX + 0xbfbd));
    FUN_004054c0();
    puVar3 = (undefined4 *)FUN_00891268(0x20);
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      bVar2 = *(byte *)(in_ECX + 0xbfbd);
      cVar1 = *(char *)((int)param_1 + 3);
      puVar3[1] = 0xffffffff;
      puVar3[2] = 0xffffffff;
      puVar3[3] = 0;
      puVar3[4] = 0xf426b;
      *puVar3 = FoxUI::FXUIEventI3::vftable;
      puVar3[5] = 1;
      puVar3[6] = (uint)bVar2;
      puVar3[7] = (int)cVar1;
    }
    FUN_0058aa50(puVar3);
    uVar6 = 1;
  }
  else {
    if (cVar1 != '\x02') {
      return 0;
    }
    FUN_004054c0();
    FUN_0058acf0(0xf426b,0,0,(int)*(char *)((int)param_1 + 3));
    uVar6 = 0;
  }
  FUN_004ba8c0(uVar6);
  *(undefined4 *)(in_ECX + 0x5eb4) = 1;
  FUN_006df020();
  return 0;
}



undefined4 FUN_0054aed0(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  char *_Str1;
  int in_ECX;
  
  (**(code **)(*param_1 + 0x14))();
  iVar1 = FUN_007300a0(&DAT_00c0f030);
  if (iVar1 == 0) {
LAB_0054af0c:
    uVar3 = 0;
  }
  else {
    puVar2 = (undefined4 *)(iVar1 + 0x30);
    if (0xf < *(uint *)(iVar1 + 0x44)) {
      puVar2 = (undefined4 *)*puVar2;
    }
    if (puVar2 == (undefined4 *)0x0) goto LAB_0054af0c;
    uVar3 = FUN_008917b4(puVar2);
  }
  *(undefined4 *)(in_ECX + 4) = uVar3;
  iVar1 = FUN_007300a0(&DAT_00c0f038);
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)(iVar1 + 0x30);
    if (0xf < *(uint *)(iVar1 + 0x44)) {
      puVar2 = (undefined4 *)*puVar2;
    }
    if (puVar2 != (undefined4 *)0x0) {
      uVar3 = FUN_008917b4(puVar2);
      goto LAB_0054af3b;
    }
  }
  uVar3 = 0;
LAB_0054af3b:
  *(undefined4 *)(in_ECX + 8) = uVar3;
  iVar1 = FUN_007300a0("tiercheck");
  if (iVar1 != 0) {
    _Str1 = (char *)(iVar1 + 0x30);
    if (0xf < *(uint *)(iVar1 + 0x44)) {
      _Str1 = *(char **)_Str1;
    }
    if (_Str1 != (char *)0x0) {
      iVar1 = __stricmp(_Str1,"true");
      *(uint *)(in_ECX + 0xc) = (uint)(iVar1 == 0);
      return 1;
    }
  }
  *(undefined4 *)(in_ECX + 0xc) = 0;
  return 1;
}


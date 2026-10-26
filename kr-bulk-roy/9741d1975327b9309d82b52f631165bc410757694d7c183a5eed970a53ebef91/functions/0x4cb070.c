
void FUN_004cb070(undefined1 param_1)

{
  undefined4 uVar1;
  byte bVar2;
  int iVar3;
  int in_ECX;
  uint uVar4;
  
  *(undefined1 *)(in_ECX + 0xb0) = param_1;
  if ((*(int *)(in_ECX + 0xf0) != 0) && (*(int *)(*(int *)(in_ECX + 0xf0) + 0x24) != 0)) {
    uVar4 = DAT_00fb7c18;
    if ((DAT_00fb7c18 & 1) == 0) {
      uVar4 = DAT_00fb7c18 | 1;
      DAT_00fb7c18 = uVar4;
      FUN_004449d0();
    }
    bVar2 = *(byte *)(in_ECX + 0xb0);
    if ((uVar4 & 1) == 0) {
      DAT_00fb7c18 = uVar4 | 1;
      FUN_004449d0();
    }
    FUN_004bb450((&DAT_00fb7c20)[bVar2]);
    bVar2 = *(byte *)(in_ECX + 0xb0);
    if ((DAT_00fb7c18 & 1) == 0) {
      DAT_00fb7c18 = DAT_00fb7c18 | 1;
      FUN_004449d0();
    }
    iVar3 = *(int *)(*(int *)(in_ECX + 0xf0) + 0x24);
    uVar1 = (&DAT_00fb7c20)[bVar2];
    *(undefined4 *)(iVar3 + 0x70) = 1;
    *(undefined4 *)(iVar3 + 0x3c) = uVar1;
  }
  return;
}



/* WARNING: Removing unreachable block (ram,0x004d08c7) */
/* WARNING: Removing unreachable block (ram,0x004d08da) */

void FUN_004d0890(undefined1 param_1)

{
  undefined4 uVar1;
  byte bVar2;
  int iVar3;
  int in_ECX;
  uint uVar4;
  
  *(undefined1 *)(in_ECX + 0xb0) = param_1;
  if (*(int *)(in_ECX + 0xf0) != 0) {
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
    iVar3 = *(int *)(in_ECX + 0xf0);
    uVar1 = (&DAT_00fb7c20)[bVar2];
    *(undefined4 *)(iVar3 + 0x70) = 1;
    *(undefined4 *)(iVar3 + 0x3c) = uVar1;
  }
  return;
}



void FUN_0074ec80(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x13d4) = 0;
  *(undefined4 *)(in_ECX + 0x13e8) = 0;
  *(undefined4 *)(in_ECX + 0x13cc) = 0;
  FUN_0074eb80((undefined4 *)(in_ECX + 0x13d4));
  iVar2 = *(int *)(in_ECX + 0xfc);
  if ((iVar2 == 3) || ((iVar2 != 1 && (*(int *)(in_ECX + 0x100) != 1)))) {
    if (*(char *)(in_ECX + 0x13d9) != '\0') {
      *(undefined4 *)(in_ECX + 0x13d0) = *(undefined4 *)(in_ECX + 0x13dc);
    }
    goto LAB_0074ed66;
  }
  *(bool *)(in_ECX + 0x13d8) = iVar2 == 1;
  if (*(int *)(in_ECX + 0x13d0) != *(int *)(in_ECX + 0x13cc)) {
    *(undefined4 *)(in_ECX + 0x108) = 0;
    *(undefined4 *)(in_ECX + 0x10c) = 0;
    *(undefined4 *)(in_ECX + 0x110) = 0;
  }
  iVar2 = *(int *)(in_ECX + 0x13cc);
  if (iVar2 != 0) {
    if ((*(byte *)(iVar2 + 0x28) & 0x10) == 0) {
      if (*(int *)(iVar2 + 0x60) == 0) goto LAB_0074ed43;
      iVar2 = FUN_00745c20();
    }
    if (((iVar2 != 0) && ((*(uint *)(iVar2 + 0x28) >> 0xc & 1) == 0)) &&
       (*(int *)(iVar2 + 0x60) != 0)) {
      FUN_0074a010(iVar2);
    }
  }
LAB_0074ed43:
  *(undefined4 *)(in_ECX + 0x13d0) = *(undefined4 *)(in_ECX + 0x13cc);
LAB_0074ed66:
  if (((*(int *)(in_ECX + 0x13c4) != 0) && (iVar2 = FUN_00761010(), iVar2 != 0)) &&
     (*(int *)(in_ECX + 0x1408) != iVar2)) {
    FUN_00753020(*(undefined4 *)(in_ECX + 0x13f8),*(undefined4 *)(in_ECX + 0x13fc),
                 *(undefined4 *)(in_ECX + 0x1400),*(undefined4 *)(in_ECX + 0x1404));
    puVar3 = (undefined4 *)FUN_00443da0();
    *(undefined4 *)(in_ECX + 0x13f8) = *puVar3;
    *(undefined4 *)(in_ECX + 0x13fc) = puVar3[1];
    *(undefined4 *)(in_ECX + 0x1400) = puVar3[2];
    *(undefined4 *)(in_ECX + 0x1404) = puVar3[3];
    *(int *)(in_ECX + 0x1408) = iVar2;
  }
  iVar2 = *(int *)(in_ECX + 0x13d0);
  *(undefined1 *)(in_ECX + 0x13d9) = 0;
  *(undefined4 *)(in_ECX + 0x13dc) = 0;
  if ((iVar2 != 0) && (*(char *)(in_ECX + 0x13d8) != '\0')) {
    iVar1 = *(int *)(in_ECX + 0xfc);
    if (iVar1 == 1) {
      *(undefined4 *)(in_ECX + 0xd0) = *(undefined4 *)(in_ECX + 0xa8);
      *(undefined4 *)(in_ECX + 0xd4) = *(undefined4 *)(in_ECX + 0xac);
      FUN_00443da0();
      FUN_00443da0();
      uVar4 = FUN_008fed10();
      *(undefined4 *)(in_ECX + 0xd8) = uVar4;
      uVar4 = FUN_008fed10();
      *(undefined4 *)(in_ECX + 0xdc) = uVar4;
      if (*(int *)(iVar2 + 0x60) == 0) {
        return;
      }
      FUN_007488b0(*(undefined4 *)(iVar2 + 0x60));
      uVar4 = FUN_008fed10();
      *(undefined4 *)(in_ECX + 0xe0) = uVar4;
      uVar4 = FUN_008fed10();
      *(undefined4 *)(in_ECX + 0xe4) = uVar4;
      return;
    }
    if (iVar1 == 3) {
      if ((*(uint *)(iVar2 + 0x28) >> 3 & 1) == 0) {
        return;
      }
      *(int *)(in_ECX + 0x13c8) = iVar2;
      return;
    }
    if (iVar1 == 6) {
      return;
    }
  }
  *(undefined4 *)(in_ECX + 0x13c8) = 0;
  return;
}


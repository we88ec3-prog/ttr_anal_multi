
void FUN_0078fdf0(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int in_ECX;
  int unaff_ESI;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  puVar1 = (undefined4 *)(unaff_ESI + 4);
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0x3f800000;
  if (&local_1c != puVar1) {
    local_10 = *(undefined4 *)(unaff_ESI + 0x10);
    local_1c = *puVar1;
    local_18 = *(undefined4 *)(unaff_ESI + 8);
    local_14 = *(undefined4 *)(unaff_ESI + 0xc);
  }
  uVar3 = *(undefined4 *)(unaff_ESI + 0x18);
  puVar2 = (undefined4 *)(in_ECX + 4);
  uVar4 = *(undefined4 *)(unaff_ESI + 0x14);
  if (puVar1 != puVar2) {
    *(undefined4 *)(unaff_ESI + 0x10) = *(undefined4 *)(in_ECX + 0x10);
    *puVar1 = *puVar2;
    *(undefined4 *)(unaff_ESI + 8) = *(undefined4 *)(in_ECX + 8);
    *(undefined4 *)(unaff_ESI + 0xc) = *(undefined4 *)(in_ECX + 0xc);
  }
  *(undefined4 *)(unaff_ESI + 0x14) = *(undefined4 *)(in_ECX + 0x14);
  *(undefined4 *)(unaff_ESI + 0x18) = *(undefined4 *)(in_ECX + 0x18);
  if (puVar2 != &local_1c) {
    *(undefined4 *)(in_ECX + 0x10) = local_10;
    *puVar2 = local_1c;
    *(undefined4 *)(in_ECX + 8) = local_18;
    *(undefined4 *)(in_ECX + 0xc) = local_14;
  }
  *(undefined4 *)(in_ECX + 0x14) = uVar4;
  *(undefined4 *)(in_ECX + 0x18) = uVar3;
  return;
}


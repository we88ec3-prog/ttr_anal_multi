
void FUN_00779bf0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xfc) = param_1;
  *(undefined4 *)(in_ECX + 0x100) = param_2;
  *(undefined4 *)(in_ECX + 0x104) = param_3;
  *(undefined4 *)(in_ECX + 0x108) = param_4;
  if (*(int *)(in_ECX + 8) != 0) {
    *(undefined4 *)(in_ECX + 0xd0) = 0;
    iVar1 = *(int *)(*(int *)(in_ECX + 8) + 0x14);
    iVar2 = *(int *)(*(int *)(in_ECX + 8) + 0xc);
    *(undefined4 *)(in_ECX + 0xcc) = 0;
    *(int *)(in_ECX + 0xd8) = iVar1 - iVar2;
    *(undefined4 *)(in_ECX + 0xd4) = *(undefined4 *)(in_ECX + 0xfc);
    *(undefined4 *)(in_ECX + 0xe0) = 0;
    *(int *)(in_ECX + 0xe8) =
         *(int *)(*(int *)(in_ECX + 8) + 0x14) - *(int *)(*(int *)(in_ECX + 8) + 0xc);
    *(undefined4 *)(in_ECX + 0xdc) = *(undefined4 *)(in_ECX + 0xfc);
    iVar1 = *(int *)(*(int *)(in_ECX + 8) + 0x10);
    iVar2 = *(int *)(*(int *)(in_ECX + 8) + 8);
    *(undefined4 *)(in_ECX + 0xf0) = 0;
    *(int *)(in_ECX + 0xe4) = (iVar1 - iVar2) - *(int *)(in_ECX + 0x104);
    *(int *)(in_ECX + 0xf8) =
         *(int *)(*(int *)(in_ECX + 8) + 0x14) - *(int *)(*(int *)(in_ECX + 8) + 0xc);
    *(int *)(in_ECX + 0xec) =
         (*(int *)(*(int *)(in_ECX + 8) + 0x10) - *(int *)(*(int *)(in_ECX + 8) + 8)) -
         *(int *)(in_ECX + 0x104);
    *(int *)(in_ECX + 0xf4) =
         *(int *)(*(int *)(in_ECX + 8) + 0x10) - *(int *)(*(int *)(in_ECX + 8) + 8);
  }
  return;
}


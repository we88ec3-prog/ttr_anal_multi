
void FUN_007a7080(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  *(undefined4 *)(in_ECX + 0xf8) = param_1;
  *(undefined4 *)(in_ECX + 0xfc) = 1;
  if (*(int *)(in_ECX + 0x18) != 0) {
    local_10 = 0;
    local_c = 0;
    local_8 = param_1;
    FUN_007d3030(&local_10);
  }
  iVar1 = *(int *)(in_ECX + 0x104);
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x3c) = param_1;
    *(undefined4 *)(iVar1 + 0x70) = 1;
    return;
  }
  return;
}


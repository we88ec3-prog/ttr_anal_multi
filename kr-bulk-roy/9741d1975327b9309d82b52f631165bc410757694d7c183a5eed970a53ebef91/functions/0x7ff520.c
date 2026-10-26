
void FUN_007ff520(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int in_ECX;
  
  uVar1 = param_1[1];
  uVar2 = param_1[2];
  puVar3 = *(undefined4 **)(in_ECX + 0x24);
  *puVar3 = *param_1;
  puVar3[1] = uVar1;
  puVar3[2] = uVar2;
  return;
}


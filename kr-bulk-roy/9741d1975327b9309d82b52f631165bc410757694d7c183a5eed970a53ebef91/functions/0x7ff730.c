
void FUN_007ff730(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int in_ECX;
  
  puVar1 = *(undefined4 **)(in_ECX + 0x24);
  uVar2 = puVar1[1];
  uVar3 = puVar1[2];
  *param_1 = *puVar1;
  param_1[1] = uVar2;
  param_1[2] = uVar3;
  *param_2 = 0x41200000;
  return;
}


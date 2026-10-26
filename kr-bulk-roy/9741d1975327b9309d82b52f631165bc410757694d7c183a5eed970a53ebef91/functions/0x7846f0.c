
undefined4 * FUN_007846f0(undefined4 *param_1)

{
  int in_EAX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  FUN_0077fed0(param_1);
  *param_1 = gbObject3d::vftable;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x15] = 0;
  param_1[0x1b] = 3;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x1c] = *(undefined4 *)(in_EAX + 0x70);
  puVar2 = (undefined4 *)(in_EAX + 0x54);
  puVar3 = param_1 + 0x15;
  for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return param_1;
}



void FUN_00842710(undefined4 *param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_54 [11];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  puVar2 = param_1;
  puVar3 = local_54;
  for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  FUN_0077ea00();
  param_1[0xb] = *(undefined4 *)(param_2 + 0x2c);
  param_1[0xc] = *(undefined4 *)(param_2 + 0x30);
  param_1[0xd] = *(undefined4 *)(param_2 + 0x34);
  param_1[0xe] = *(undefined4 *)(param_2 + 0x38);
  param_1[0xf] = *(undefined4 *)(param_2 + 0x3c);
  param_1[0x10] = *(undefined4 *)(param_2 + 0x40);
  param_1[0x11] = *(undefined4 *)(param_2 + 0x44);
  param_1[0x12] = *(undefined4 *)(param_2 + 0x48);
  param_1[0x13] = *(undefined4 *)(param_2 + 0x4c);
  FUN_0077ea00();
  *(undefined4 *)(param_2 + 0x3c) = local_18;
  *(undefined4 *)(param_2 + 0x2c) = local_28;
  *(undefined4 *)(param_2 + 0x30) = local_24;
  *(undefined4 *)(param_2 + 0x34) = local_20;
  *(undefined4 *)(param_2 + 0x38) = local_1c;
  *(undefined4 *)(param_2 + 0x40) = local_14;
  *(undefined4 *)(param_2 + 0x44) = local_10;
  *(undefined4 *)(param_2 + 0x48) = local_c;
  *(undefined4 *)(param_2 + 0x4c) = local_8;
  return;
}


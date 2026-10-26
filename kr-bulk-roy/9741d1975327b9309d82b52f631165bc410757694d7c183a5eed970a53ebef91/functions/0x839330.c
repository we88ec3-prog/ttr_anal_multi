
undefined4 * FUN_00839330(undefined4 *param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *_Dst;
  
  _Dst = param_1 + 1;
  param_1[0xd] = 7;
  _memset(_Dst,0,0x34);
  param_1[9] = 0x3f800000;
  param_1[5] = 0x3f800000;
  *_Dst = 0x3f800000;
  param_1[0x13] = param_2[0x13];
  puVar3 = param_2;
  for (iVar2 = 0xd; puVar3 = puVar3 + 1, iVar2 != 0; iVar2 = iVar2 + -1) {
    *_Dst = *puVar3;
    _Dst = _Dst + 1;
  }
  param_1[0xe] = param_2[0xe];
  *param_1 = *param_2;
  param_1[0xf] = param_2[0xf];
  *(undefined8 *)(param_1 + 0x10) = *(undefined8 *)(param_2 + 0x10);
  param_1[0x12] = param_2[0x12];
  piVar1 = (int *)param_2[0x14];
  param_1[0x14] = piVar1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  piVar1 = (int *)param_2[0x15];
  param_1[0x15] = piVar1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  piVar1 = (int *)param_2[0x16];
  param_1[0x16] = piVar1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  param_1[0x17] = param_2[0x17];
  param_1[0x18] = param_2[0x18];
  param_1[0x19] = param_2[0x19];
  param_1[0x1a] = param_2[0x1a];
  param_1[0x1c] = param_2[0x1c];
  param_1[0x1b] = param_2[0x1b];
  param_1[0xe] = param_2[0xe];
  return param_1;
}


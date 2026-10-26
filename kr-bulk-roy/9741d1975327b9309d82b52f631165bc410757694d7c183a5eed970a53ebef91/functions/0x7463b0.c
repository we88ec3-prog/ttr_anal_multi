
void FUN_007463b0(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  int *in_ECX;
  
  uVar3 = in_ECX[10];
  if (((byte)(uVar3 >> 10) & 1) == (byte)param_1) goto LAB_007463f0;
  if ((byte)param_1 == 0) {
    if ((uVar3 & 0x400) != 0) {
      uVar3 = uVar3 ^ 0x400;
      goto LAB_007463e1;
    }
  }
  else {
    uVar3 = uVar3 | 0x400;
LAB_007463e1:
    in_ECX[10] = uVar3;
  }
  (**(code **)(*in_ECX + 0xcc))();
LAB_007463f0:
  puVar1 = (undefined4 *)in_ECX[0x19];
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    (**(code **)(*(int *)puVar2[2] + 0xac))(param_1);
  }
  return;
}


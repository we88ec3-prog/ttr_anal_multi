
void FUN_007462e0(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  int *in_ECX;
  
  uVar3 = in_ECX[10];
  if (((byte)(uVar3 >> 9) & 1) == (byte)param_1) goto LAB_00746320;
  if ((byte)param_1 == 0) {
    if ((uVar3 & 0x200) != 0) {
      uVar3 = uVar3 ^ 0x200;
      goto LAB_00746311;
    }
  }
  else {
    uVar3 = uVar3 | 0x200;
LAB_00746311:
    in_ECX[10] = uVar3;
  }
  (**(code **)(*in_ECX + 0xcc))();
LAB_00746320:
  puVar1 = (undefined4 *)in_ECX[0x19];
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    (**(code **)(*(int *)puVar2[2] + 0xa4))(param_1);
  }
  return;
}


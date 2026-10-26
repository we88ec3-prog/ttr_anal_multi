
void FUN_007461f0(undefined4 param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  int *in_ECX;
  undefined4 *extraout_EDX;
  undefined4 *puVar3;
  
  uVar2 = in_ECX[10];
  if (((byte)(uVar2 >> 0xb) & 1) == (byte)param_1) goto LAB_00746258;
  if ((byte)param_1 == 0) {
    if ((uVar2 & 0x800) != 0) {
      uVar2 = uVar2 ^ 0x800;
      goto LAB_00746221;
    }
  }
  else {
    uVar2 = uVar2 | 0x800;
LAB_00746221:
    in_ECX[10] = uVar2;
  }
  puVar1 = (undefined4 *)in_ECX[0x19];
  for (puVar3 = (undefined4 *)*puVar1; puVar3 != puVar1; puVar3 = (undefined4 *)*puVar3) {
    if ((*(byte *)(puVar3[2] + 0x28) & 0x30) == 0) {
      FUN_00746450(0x800,param_1,1);
      puVar3 = extraout_EDX;
    }
  }
  (**(code **)(*in_ECX + 0xcc))();
LAB_00746258:
  puVar1 = (undefined4 *)in_ECX[0x19];
  for (puVar3 = (undefined4 *)*puVar1; puVar3 != puVar1; puVar3 = (undefined4 *)*puVar3) {
    (**(code **)(*(int *)puVar3[2] + 0x9c))(param_1);
  }
  return;
}


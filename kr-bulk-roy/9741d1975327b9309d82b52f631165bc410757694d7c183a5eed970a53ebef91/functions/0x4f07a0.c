
void FUN_004f07a0(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *in_ECX;
  
  puVar2 = in_ECX;
  if (7 < (uint)in_ECX[5]) {
    puVar2 = (undefined4 *)*in_ECX;
  }
  iVar1 = (int)puVar2 + in_ECX[4] * 2;
  if (7 < (uint)in_ECX[5]) {
    in_ECX = (undefined4 *)*in_ECX;
  }
  if (iVar1 != 0) {
    FUN_004f0b60(iVar1 - (int)in_ECX >> 1,1,param_1);
    return;
  }
  FUN_004f0b60(0,1,param_1);
  return;
}


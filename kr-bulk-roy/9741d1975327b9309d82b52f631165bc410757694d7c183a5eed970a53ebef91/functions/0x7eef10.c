
void FUN_007eef10(byte param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *in_ECX;
  
  *in_ECX = IS3D::CMaterial::vftable;
  puVar2 = (undefined4 *)in_ECX[2];
  if (puVar2 != (undefined4 *)0x0) {
    piVar1 = puVar2 + 1;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      (**(code **)*puVar2)(1);
    }
  }
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}


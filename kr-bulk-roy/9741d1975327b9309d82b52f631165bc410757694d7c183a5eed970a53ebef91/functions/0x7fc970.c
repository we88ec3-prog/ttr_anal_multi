
void FUN_007fc970(float param_1)

{
  float fVar1;
  int iVar2;
  int in_ECX;
  
  if ((*(float *)(in_ECX + 0x34) < 0.0) || (iVar2 = *(int *)(in_ECX + 0x30), iVar2 == 0)) {
    *(undefined4 *)(in_ECX + 0x3c) = 0;
  }
  else {
    fVar1 = *(float *)(iVar2 + 0x74);
    *(undefined4 *)(in_ECX + 0x3c) = 1;
    *(float *)(in_ECX + 0x34) = *(float *)(in_ECX + 0x34) + param_1 * fVar1;
    FUN_007d89b0(iVar2,param_1);
    iVar2 = *(int *)(in_ECX + 0x30);
    if ((*(float *)(in_ECX + 0x34) < *(float *)(iVar2 + 0x74) * *(float *)(in_ECX + 0x38)) &&
       (*(float *)(iVar2 + 0x70) < *(float *)(iVar2 + 0x6c))) {
      FUN_007d8bf0();
      return;
    }
  }
  return;
}


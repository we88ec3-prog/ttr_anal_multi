
void FUN_004a8830(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  int *piVar4;
  
  piVar4 = (int *)(in_ECX + 0x48);
  piVar2 = piVar4;
  if (0xf < *(uint *)(in_ECX + 0x5c)) {
    piVar2 = (int *)*piVar4;
  }
  iVar3 = FUN_00734330(piVar2,0);
  *(int *)(in_ECX + 0x44) = iVar3;
  if (iVar3 == 0) {
    if (0xf < *(uint *)(in_ECX + 0x5c)) {
      piVar4 = (int *)*piVar4;
    }
    FUN_006edb60("CSimpleObject::Load(): Can\'t load texture file \'%s\'",piVar4);
  }
  iVar3 = *(int *)(in_ECX + 0x44);
  if (iVar3 != 0) {
    iVar1 = *(int *)(iVar3 + 0xc);
    iVar3 = *(int *)(iVar3 + 0x10);
    if ((*(int *)(in_ECX + 100) == 0) && (*(int *)(in_ECX + 0x68) == 0)) {
      *(int *)(in_ECX + 100) = iVar1;
      *(int *)(in_ECX + 0x68) = iVar3;
    }
    *(float *)(in_ECX + 0x6c) = (float)*(int *)(in_ECX + 100) / (float)iVar1;
    *(float *)(in_ECX + 0x70) = (float)*(int *)(in_ECX + 0x68) / (float)iVar3;
  }
  return;
}



void FUN_00553da0(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  int *piVar3;
  
  piVar3 = (int *)(in_ECX + 0x48);
  piVar1 = piVar3;
  if (0xf < *(uint *)(in_ECX + 0x5c)) {
    piVar1 = (int *)*piVar3;
  }
  iVar2 = FUN_00734330(piVar1,0);
  *(int *)(in_ECX + 0x44) = iVar2;
  if (iVar2 == 0) {
    if (0xf < *(uint *)(in_ECX + 0x5c)) {
      piVar3 = (int *)*piVar3;
    }
    FUN_006edb60("CSimpleObject::Load(): Can\'t load texture file \'%s\'",piVar3);
  }
  return;
}


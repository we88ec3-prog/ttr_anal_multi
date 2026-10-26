
void FUN_004d4940(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  int *piVar3;
  
  *(undefined4 *)(in_ECX + 0x34) = 1;
  if (*(int **)(in_ECX + 0x44) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x44) + 8))();
    *(undefined4 *)(in_ECX + 0x44) = 0;
  }
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
    FUN_006edb60("CFadeObject::Load(): Can\'t load texture file \'%s\'",piVar3);
  }
  return;
}


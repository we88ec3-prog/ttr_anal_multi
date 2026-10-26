
void FUN_004cb4b0(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  
  piVar1 = *(int **)(in_ECX + 4);
  iVar2 = piVar1[0xe3];
  if ((piVar1[0x57] == 0) || (piVar1[0xdc] == 0)) {
    iVar3 = 0;
  }
  else {
    iVar3 = *(int *)(piVar1[0x57] + 0x11c);
  }
  if ((iVar2 == 4) || (iVar2 == 5)) {
    if ((iVar2 != 6) && (piVar1[0x34] < 100)) {
      (**(code **)(*piVar1 + 0x68))(6,0x3f800000);
    }
  }
  else if (iVar2 != 6) {
    if ((iVar2 == 0x10) && (iVar3 == 0)) {
      return;
    }
    (**(code **)(*piVar1 + 0x68))(4,piVar1[0xe6]);
    return;
  }
  if ((iVar2 != 5) && (100 < (*(int **)(in_ECX + 4))[0x34])) {
    (**(code **)(**(int **)(in_ECX + 4) + 0x68))(5,0x3f800000);
  }
  if ((iVar2 != 4) && (piVar1 = *(int **)(in_ECX + 4), piVar1[0x34] == 100)) {
    (**(code **)(*piVar1 + 0x68))(4,piVar1[0xe6]);
  }
  return;
}


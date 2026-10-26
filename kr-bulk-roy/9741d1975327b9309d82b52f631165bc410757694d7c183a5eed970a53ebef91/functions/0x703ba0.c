
int FUN_00703ba0(int *param_1)

{
  uint uVar1;
  int in_EAX;
  int iVar2;
  int in_ECX;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  
  iVar2 = in_EAX + -0x31;
  if (((iVar2 < 0) || (*(int *)(in_ECX + 0xc) <= iVar2)) ||
     (*(int *)(in_ECX + 0x14 + iVar2 * 8) == -1)) {
    iVar2 = FUN_006f5f30(*(undefined4 *)(in_ECX + 8),"invalid capture index");
  }
  uVar1 = *(uint *)(in_ECX + 0x14 + iVar2 * 8);
  if (uVar1 <= (uint)(*(int *)(in_ECX + 4) - (int)param_1)) {
    piVar5 = *(int **)(in_ECX + 0x10 + iVar2 * 8);
    piVar4 = param_1;
    for (uVar3 = uVar1; 3 < uVar3; uVar3 = uVar3 - 4) {
      if (*piVar5 != *piVar4) {
        return 0;
      }
      piVar4 = piVar4 + 1;
      piVar5 = piVar5 + 1;
    }
    if ((uVar3 == 0) ||
       (((char)*piVar4 == (char)*piVar5 &&
        ((uVar3 < 2 ||
         ((*(char *)((int)piVar4 + 1) == *(char *)((int)piVar5 + 1) &&
          ((uVar3 < 3 || (*(char *)((int)piVar4 + 2) == *(char *)((int)piVar5 + 2))))))))))) {
      return uVar1 + (int)param_1;
    }
  }
  return 0;
}



/* WARNING: Type propagation algorithm not settling */

int FUN_00762cc0(void)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  int *piVar3;
  int local_10;
  int local_c [2];
  
  iVar1 = *(int *)(in_ECX + 0xa4) + *(int *)(in_ECX + 0x2c);
  if (*(int *)(in_ECX + 0x168) <= *(int *)(in_ECX + 0x14c)) {
    piVar3 = (int *)(in_ECX + 0x108);
    local_c[0] = 0;
    local_10 = 0;
    local_c[1] = 0;
    piVar2 = piVar3;
    if (7 < *(uint *)(in_ECX + 0x11c)) {
      piVar2 = (int *)*piVar3;
    }
    (**(code **)(**(int **)(in_ECX + 0xf4) + 0x30))
              (local_c,local_c + 1,piVar2,*(int *)(in_ECX + 0x14c));
    if (7 < *(uint *)(in_ECX + 0x11c)) {
      piVar3 = (int *)*piVar3;
    }
    (**(code **)(**(int **)(in_ECX + 0xf4) + 0x30))
              (&local_10,local_c + 1,piVar3,*(undefined4 *)(in_ECX + 0x168));
    iVar1 = (local_c[0] - local_10) + iVar1;
  }
  return iVar1;
}


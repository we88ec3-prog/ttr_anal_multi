
int FUN_00768e30(void)

{
  uint uVar1;
  int in_ECX;
  int *piVar2;
  int iVar3;
  undefined4 local_c;
  int local_8;
  
  uVar1 = *(uint *)(in_ECX + 0x13c);
  iVar3 = *(int *)(in_ECX + 0xa4) + *(int *)(in_ECX + 0x2c);
  if ((*(int *)(in_ECX + 0x134) <= (int)uVar1) &&
     ((int)uVar1 < *(int *)(in_ECX + 0x138) + *(int *)(in_ECX + 0x134))) {
    local_8 = 0;
    local_c = 0;
    if (uVar1 < (uint)(*(int *)(in_ECX + 0x114) - *(int *)(in_ECX + 0x110) >> 2)) {
      piVar2 = *(int **)(*(int *)(in_ECX + 0x110) + uVar1 * 4);
      if (7 < (uint)piVar2[5]) {
        piVar2 = (int *)*piVar2;
      }
      (**(code **)(**(int **)(in_ECX + 0xf4) + 0x30))
                (&local_8,&local_c,piVar2,*(undefined4 *)(in_ECX + 0x140));
    }
    return local_8 + iVar3;
  }
  return iVar3;
}


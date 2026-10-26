
uint FUN_007830e0(uint param_1)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  
  uVar1 = **(uint **)(in_ECX + 0x20);
  if (((uVar1 != 0) && (**(uint **)(in_ECX + 0x10) < uVar1)) &&
     ((param_1 == 0xffffffff || (*(byte *)(uVar1 - 1) == param_1)))) {
    **(int **)(in_ECX + 0x30) = **(int **)(in_ECX + 0x30) + 1;
    **(int **)(in_ECX + 0x20) = **(int **)(in_ECX + 0x20) + -1;
    return -(uint)(param_1 != 0xffffffff) & param_1;
  }
  if ((*(FILE **)(in_ECX + 0x54) != (FILE *)0x0) && (param_1 != 0xffffffff)) {
    if ((*(int *)(in_ECX + 0x44) == 0) &&
       (iVar2 = _ungetc(param_1 & 0xff,*(FILE **)(in_ECX + 0x54)), iVar2 != -1)) {
      return param_1;
    }
    if ((undefined1 *)**(int **)(in_ECX + 0x20) != (undefined1 *)(in_ECX + 0x48)) {
      *(undefined1 *)(in_ECX + 0x48) = (char)param_1;
      FUN_00783c30();
      return param_1;
    }
  }
  return 0xffffffff;
}


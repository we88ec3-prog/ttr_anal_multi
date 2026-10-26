
void FUN_00765de0(void)

{
  int in_ECX;
  int iVar1;
  
  FUN_00754430();
  iVar1 = (*(int *)(in_ECX + 0x10) - *(int *)(in_ECX + 0x128)) - *(int *)(in_ECX + 8);
  if (-1 < iVar1) {
    (**(code **)(**(int **)(in_ECX + 0x10c) + 0xbc))
              (iVar1,0,*(int *)(in_ECX + 0x128) + iVar1,
               *(int *)(in_ECX + 0x14) - *(int *)(in_ECX + 0xc));
  }
  if ((*(int *)(in_ECX + 0xf4) == 0) || (iVar1 = FUN_008fed10(), iVar1 == 0)) {
    *(undefined4 *)(in_ECX + 0x138) = 0;
  }
  else {
    *(int *)(in_ECX + 0x138) = (*(int *)(in_ECX + 0xb0) - *(int *)(in_ECX + 0xa8)) / iVar1;
  }
  FUN_00766390(0,1,1);
  FUN_00767ba0();
  FUN_00767ec0();
  FUN_00767b30();
  FUN_00767fa0();
  return;
}


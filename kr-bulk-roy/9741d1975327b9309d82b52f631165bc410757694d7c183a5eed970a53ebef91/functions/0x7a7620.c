
void FUN_007a7620(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 local_c;
  undefined4 local_8;
  
  FUN_007aa0c0(&local_c,&param_2);
  FUN_006d7120(local_c,local_8);
  iVar2 = param_2 + 0x10;
  param_2 = iVar2;
  piVar1 = (int *)FUN_007a0c00(&param_2);
  if (*(int *)(param_1 + 0x60) != *piVar1) {
    param_2 = iVar2;
    FUN_007aa0c0(&local_c,&param_2);
    FUN_006d7120(local_c,local_8);
  }
  *(undefined1 *)(param_1 + 0x28) = 1;
  return;
}


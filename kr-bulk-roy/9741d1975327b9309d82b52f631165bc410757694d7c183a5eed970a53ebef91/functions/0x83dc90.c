
undefined4 FUN_0083dc90(int *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  undefined1 local_c [4];
  undefined4 local_8;
  
  piVar1 = param_1;
  local_8 = 0x1b;
  iVar2 = (**(code **)(*param_1 + 0x4c))(&local_8,local_c,&param_1);
  if (iVar2 != 0) {
    return 2;
  }
  uVar3 = (**(code **)(*in_ECX + 0xe0))(piVar1[0x59]);
  return uVar3;
}


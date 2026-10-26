
undefined4 FUN_00709450(int param_1)

{
  undefined4 *puVar1;
  double *pdVar2;
  char *_Command;
  int iVar3;
  
  puVar1 = *(undefined4 **)(param_1 + 0xc);
  if (((puVar1 < *(undefined4 **)(param_1 + 8)) && (puVar1 != &DAT_00c0bfc8)) &&
     (0 < (int)puVar1[2])) {
    _Command = (char *)FUN_006f6210(param_1);
  }
  else {
    _Command = (char *)0x0;
  }
  iVar3 = _system(_Command);
  pdVar2 = *(double **)(param_1 + 8);
  *(undefined4 *)(pdVar2 + 1) = 3;
  *pdVar2 = (double)iVar3;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  return 1;
}


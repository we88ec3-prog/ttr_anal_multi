
intptr_t FUN_008b0092(int param_1,char *param_2,char **param_3,char **param_4)

{
  int *piVar1;
  int iVar2;
  intptr_t iVar3;
  char *local_c;
  char *local_8;
  
  if ((param_2 == (char *)0x0) || (param_3 == (char **)0x0)) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_00893343();
  }
  else {
    iVar2 = __cenvarg(param_3,param_4,&local_8,&local_c,param_2);
    if (iVar2 != -1) {
      iVar3 = __dospawn(param_1,param_2,local_8,local_c);
      _free(local_8);
      _free(local_c);
      return iVar3;
    }
  }
  return -1;
}


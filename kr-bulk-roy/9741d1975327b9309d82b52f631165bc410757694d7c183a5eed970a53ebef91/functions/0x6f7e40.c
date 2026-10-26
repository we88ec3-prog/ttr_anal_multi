
char * FUN_006f7e40(int param_1,int param_2)

{
  char *pcVar1;
  int iVar2;
  int *unaff_EDI;
  
  if (((((int *)unaff_EDI[1])[2] == 6) &&
      (iVar2 = *(int *)unaff_EDI[1], *(char *)(iVar2 + 6) == '\0')) && (*(int *)(iVar2 + 0x10) != 0)
     ) {
    if (unaff_EDI == *(int **)(param_1 + 0x14)) {
      unaff_EDI[3] = *(int *)(param_1 + 0x18);
    }
    pcVar1 = (char *)FUN_006fda20(param_2);
    if (pcVar1 != (char *)0x0) {
      return pcVar1;
    }
  }
  if (unaff_EDI == *(int **)(param_1 + 0x14)) {
    iVar2 = *(int *)(param_1 + 8);
  }
  else {
    iVar2 = unaff_EDI[7];
  }
  if ((param_2 <= iVar2 - *unaff_EDI >> 4) && (0 < param_2)) {
    return "(*temporary)";
  }
  return (char *)0x0;
}


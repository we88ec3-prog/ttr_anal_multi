
char * FUN_00732d00(undefined4 param_1,int *param_2,undefined4 param_3)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  char *pcVar4;
  int *in_ECX;
  int local_8;
  
  for (piVar2 = in_ECX; piVar2 != (int *)0x0; piVar2 = (int *)piVar2[4]) {
    iVar3 = (**(code **)(*piVar2 + 0x10))();
    if (iVar3 != 0) {
      local_8 = (**(code **)(*piVar2 + 0x10))();
      goto LAB_00732d2f;
    }
  }
  local_8 = 0;
LAB_00732d2f:
  pcVar4 = (char *)FUN_00731170(param_3);
  if (param_2 != (int *)0x0) {
    FUN_00730f80(pcVar4,param_3);
    in_ECX[1] = *param_2;
    in_ECX[2] = param_2[1];
  }
  if (((pcVar4 == (char *)0x0) || (*pcVar4 == '\0')) || (*pcVar4 != '<')) {
    if (local_8 != 0) {
      FUN_00732010(10,pcVar4,param_2,param_3);
    }
    return (char *)0x0;
  }
  FUN_00402a70(&DAT_00bf2375,0);
  while (pcVar4 = pcVar4 + 1, pcVar4 != (char *)0x0) {
    cVar1 = *pcVar4;
    if (cVar1 == '\0') goto LAB_00732daf;
    if (cVar1 == '>') goto LAB_00732db4;
    FUN_00429630(1,cVar1);
  }
  if (local_8 != 0) {
    FUN_00732010(10,0,0,param_3);
  }
LAB_00732daf:
  if (*pcVar4 != '>') {
    return pcVar4;
  }
LAB_00732db4:
  return pcVar4 + 1;
}


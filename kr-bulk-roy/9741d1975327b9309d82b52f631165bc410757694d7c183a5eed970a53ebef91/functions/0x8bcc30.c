
int FUN_008bcc30(undefined4 *param_1,undefined4 param_2,int *param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int local_8;
  
  local_8 = 0;
  if (((param_1 == (undefined4 *)0x0) || (param_3 == (int *)0x0)) || (iVar1 = *param_3, iVar1 == 0))
  {
    return 6;
  }
  uVar2 = *(undefined4 *)(iVar1 + 100);
  piVar3 = (int *)FUN_008baee0(uVar2,*param_1,&local_8);
  if (local_8 != 0) goto LAB_008bcce5;
  *piVar3 = *param_3;
  piVar3[1] = param_3[1];
  piVar3[2] = param_3[2];
  piVar3[3] = (int)param_1;
  if ((code *)param_1[1] == (code *)0x0) {
LAB_008bccac:
    iVar4 = FUN_008bc7d0(uVar2,4,*(int *)(iVar1 + 0x24),*(int *)(iVar1 + 0x24) + 1,
                         *(undefined4 *)(iVar1 + 0x28),&local_8);
    *(int *)(iVar1 + 0x28) = iVar4;
    if (local_8 == 0) {
      *(int **)(iVar4 + *(int *)(iVar1 + 0x24) * 4) = piVar3;
      *(int *)(iVar1 + 0x24) = *(int *)(iVar1 + 0x24) + 1;
      goto LAB_008bcce5;
    }
  }
  else {
    local_8 = (*(code *)param_1[1])(piVar3,param_2);
    if (local_8 == 0) goto LAB_008bccac;
  }
  FUN_008ba7b0();
  piVar3 = (int *)0x0;
LAB_008bcce5:
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = piVar3;
  }
  return local_8;
}


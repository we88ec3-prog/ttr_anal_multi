
int FUN_008bbed0(int param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  code *pcVar3;
  int iVar4;
  int *piVar5;
  int local_8;
  
  iVar4 = param_1;
  local_8 = 0;
  if (param_1 == 0) {
    return 0x23;
  }
  if (param_2 == (int *)0x0) {
    return 0x24;
  }
  if (*(int *)(param_1 + 0x60) == 0) {
    return 0x22;
  }
  *param_2 = 0;
  iVar1 = *(int *)(*(int *)(param_1 + 0x60) + 0xc);
  uVar2 = *(undefined4 *)(param_1 + 100);
  piVar5 = (int *)FUN_008baee0(uVar2,*(undefined4 *)(iVar1 + 0x28),&param_1);
  if ((param_1 == 0) && (local_8 = FUN_008baee0(uVar2,0xc,&param_1), param_1 == 0)) {
    *piVar5 = iVar4;
    piVar5[10] = 0;
    pcVar3 = *(code **)(iVar1 + 0x38);
    if (pcVar3 != (code *)0x0) {
      param_1 = (*pcVar3)(piVar5);
      if (param_1 != 0) goto LAB_008bbf98;
      param_1 = 0;
    }
    *param_2 = (int)piVar5;
    *(int **)(local_8 + 8) = piVar5;
    FUN_008ba090(iVar4 + 0x6c,local_8);
    return param_1;
  }
LAB_008bbf98:
  FUN_008b9f80(uVar2,local_8);
  FUN_008b9f80(uVar2,piVar5);
  return param_1;
}


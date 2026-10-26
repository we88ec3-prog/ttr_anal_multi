
int FUN_008bbd40(undefined4 *param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  char *pcVar6;
  int in_EDX;
  
  uVar1 = *param_1;
  if (in_EAX == -1) {
    in_EAX = 0;
  }
  if (in_EAX < param_3) {
    iVar4 = *(int *)(in_EDX + in_EAX * 4);
    param_3 = FUN_008b97e0(param_2,iVar4);
    iVar3 = param_3;
    if ((param_3 == 0) && (iVar2 = FUN_008b9c00(param_2,&param_3), iVar3 = param_3, param_3 == 0)) {
      if (iVar2 == -1) {
        return 1;
      }
      iVar3 = FUN_008bb9e0(param_1,param_2,in_EAX,param_4);
      if ((((iVar3 != 0) && (param_3 = iVar3, iVar4 = FUN_008b97e0(param_2,iVar4 + 4), iVar4 == 0))
          && (piVar5 = (int *)FUN_008baee0(uVar1,iVar2,&param_3), iVar3 = param_3, param_3 == 0)) &&
         (iVar3 = FUN_008bab70(param_2,piVar5,iVar2), iVar3 == 0)) {
        if ((iVar2 < 5) || (pcVar6 = "cff", *piVar5 != 0x4f54544f)) {
          pcVar6 = "truetype";
        }
        iVar3 = FUN_008bb920(0,pcVar6,param_4);
      }
    }
    return iVar3;
  }
  return 1;
}



int FUN_008bb9e0(undefined4 *param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  undefined4 extraout_ECX;
  undefined4 local_18;
  int local_14;
  int local_c;
  char local_5;
  
  uVar4 = *param_1;
  iVar1 = FUN_008b9850(param_2);
  iVar2 = FUN_008ba520(extraout_ECX,param_3,&local_5);
  local_c = iVar2;
  if ((((iVar2 == 0) && (iVar3 = FUN_008b97e0(param_2,local_14 + iVar1), iVar3 == 0)) &&
      (uVar4 = FUN_008baee0(uVar4,local_18,&local_c), iVar2 = local_c, local_c == 0)) &&
     (iVar2 = FUN_008bab70(param_2,uVar4,local_18), iVar2 == 0)) {
    pcVar5 = "cid";
    if (local_5 == '\0') {
      pcVar5 = "type1";
    }
    iVar2 = FUN_008bb920((-1 < (int)param_3) - 1 & param_3,pcVar5,param_4);
  }
  if (((char)iVar2 == '\x02') && (iVar1 = FUN_008b97e0(param_2,iVar1), iVar1 != 0)) {
    return iVar1;
  }
  return iVar2;
}


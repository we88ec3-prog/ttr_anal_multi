
void FUN_006f4dd0(char *param_1,int param_2)

{
  char cVar1;
  int *in_EAX;
  char *pcVar2;
  int iVar3;
  int iVar4;
  int local_18;
  int local_14;
  undefined4 local_10;
  
  iVar4 = *in_EAX;
  pcVar2 = param_1;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  local_18 = FUN_006fec70(iVar4,param_1,(int)pcVar2 - (int)(param_1 + 1));
  local_10 = 4;
  FUN_006fb850(iVar4,iVar4 + 0x48,&local_18,*(undefined4 *)(iVar4 + 8));
  *(int *)(iVar4 + 8) = *(int *)(iVar4 + 8) + 0x10;
  if ((*(undefined **)(*in_EAX + 8) == &DAT_00c0bfd8) ||
     (*(int *)(*(undefined **)(*in_EAX + 8) + -8) != 6)) {
    FID_conflict__wprintf
              ("Error running function \'%s\' : Attempt to call non-function object\n",param_1);
    iVar4 = *in_EAX;
    if (*(uint *)(iVar4 + 8) < *(uint *)(iVar4 + 0xc)) {
      do {
        *(undefined4 *)(*(int *)(iVar4 + 8) + 8) = 0;
        *(int *)(iVar4 + 8) = *(int *)(iVar4 + 8) + 0x10;
      } while (*(uint *)(iVar4 + 8) < *(uint *)(iVar4 + 0xc));
    }
    *(undefined4 *)(iVar4 + 8) = *(undefined4 *)(iVar4 + 0xc);
    return;
  }
  iVar3 = FUN_006f4cd0(in_EAX,&stack0x00000010);
  iVar4 = *in_EAX;
  local_18 = *(int *)(iVar4 + 8) + (iVar3 + 1) * -0x10;
  local_14 = param_2;
  iVar3 = FUN_006fe770(FUN_006f5a50,&local_18,local_18 - *(int *)(iVar4 + 0x20));
  if (param_2 == -1) {
    if (*(uint *)(*(int *)(iVar4 + 0x14) + 8) <= *(uint *)(iVar4 + 8)) {
      *(uint *)(*(int *)(iVar4 + 0x14) + 8) = *(uint *)(iVar4 + 8);
    }
  }
  if (iVar3 == 0) {
    return;
  }
  iVar4 = *in_EAX;
  iVar3 = *(int *)(iVar4 + 8);
  if (*(int *)(iVar3 + -8) != 4) {
    iVar3 = FUN_006fb5d0();
    if (iVar3 == 0) {
      iVar4 = 0;
      goto LAB_006f4edc;
    }
    if (*(uint *)(*(int *)(iVar4 + 0x10) + 0x40) <= *(uint *)(*(int *)(iVar4 + 0x10) + 0x44)) {
      FUN_006fb3a0();
    }
    iVar3 = *(int *)(iVar4 + 8);
  }
  iVar4 = *(int *)(iVar3 + -0x10) + 0x10;
LAB_006f4edc:
  FID_conflict__wprintf("Error running function \'%s\' : %s\n",param_1,iVar4);
  return;
}


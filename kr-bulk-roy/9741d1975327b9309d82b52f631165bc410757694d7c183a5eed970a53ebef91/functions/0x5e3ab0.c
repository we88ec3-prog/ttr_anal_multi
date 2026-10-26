
void FUN_005e3ab0(void)

{
  short sVar1;
  code *pcVar2;
  int in_EAX;
  int iVar3;
  short *psVar4;
  short *psVar5;
  int local_c;
  undefined4 local_8;
  
  if ((*(int *)(in_EAX + 0x180) != 0) && (*(int *)(*(int *)(in_EAX + 0x180) + 0x40) != 0)) {
    local_8 = 0x196;
    iVar3 = FUN_00585620();
    FUN_005740f0(&local_8);
    if (local_c == *(int *)(iVar3 + 4)) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    psVar5 = (short *)(local_c + 0x10);
    if (7 < *(uint *)(local_c + 0x24)) {
      psVar5 = *(short **)psVar5;
    }
    psVar4 = psVar5;
    do {
      sVar1 = *psVar4;
      psVar4 = psVar4 + 1;
    } while (sVar1 != 0);
    FUN_00404300(psVar5,(int)psVar4 - (int)(psVar5 + 1) >> 1);
  }
  return;
}


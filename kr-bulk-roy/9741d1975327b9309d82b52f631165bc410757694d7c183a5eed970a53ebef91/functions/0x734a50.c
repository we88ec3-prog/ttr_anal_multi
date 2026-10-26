
void FUN_00734a50(int param_1,int param_2,int param_3)

{
  int iVar1;
  int in_EAX;
  char cVar2;
  int iVar3;
  int in_EDX;
  int iVar4;
  int *piVar5;
  
  if (in_EAX < param_3 + in_EAX) {
    iVar3 = (param_3 + in_EAX) - in_EAX;
    piVar5 = (int *)(in_EDX + 0x18 + in_EAX * 4);
    iVar4 = in_EAX * 0x20 + 0x118 + in_EDX;
    do {
      cVar2 = '\x01';
      iVar1 = param_1;
      while ((iVar1 = iVar1 + -1, -1 < iVar1 && (-1 < *(char *)(iVar4 + iVar1)))) {
        *(char *)(iVar4 + iVar1) = cVar2;
        cVar2 = cVar2 + '\x01';
      }
      *piVar5 = *piVar5 - param_2;
      if (*piVar5 < 0) {
        FID_conflict__wprintf("Err#7\n");
        *piVar5 = 0;
      }
      piVar5 = piVar5 + 1;
      iVar4 = iVar4 + 0x20;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return;
}


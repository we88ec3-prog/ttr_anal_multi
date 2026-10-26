
undefined4 FUN_004ad850(int *param_1,int *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  char *in_EDX;
  int iVar3;
  char *pcVar4;
  char *local_8;
  
  iVar1 = param_3 - (int)in_EDX;
  iVar2 = 0;
  pcVar4 = in_EDX;
  if (0 < iVar1) {
    do {
      if (*pcVar4 == '=') {
        iVar1 = ((int)pcVar4 - (int)in_EDX) + -1;
        if ((int)pcVar4 - (int)in_EDX == 1) goto LAB_004ad8d7;
        iVar2 = 0;
        iVar3 = 0;
        if (iVar1 < 1) goto LAB_004ad8da;
        goto LAB_004ad8b2;
      }
      iVar2 = iVar2 + 1;
      pcVar4 = pcVar4 + 1;
    } while (iVar2 < iVar1);
  }
  if (iVar1 == 1) {
LAB_004ad8f3:
    iVar2 = -1;
  }
  else {
    iVar2 = 0;
    iVar3 = 0;
    if (0 < iVar1 + -1) {
      do {
        in_EDX = in_EDX + 1;
        if (9 < (int)*in_EDX - 0x30U) goto LAB_004ad8f3;
        iVar3 = iVar3 + 1;
        iVar2 = *in_EDX + -0x30 + iVar2 * 10;
      } while (iVar3 < iVar1 + -1);
    }
  }
  *param_1 = iVar2;
  *param_2 = 0;
  return 0;
LAB_004ad8d7:
  iVar2 = -1;
  goto LAB_004ad8da;
  while( true ) {
    iVar3 = iVar3 + 1;
    iVar2 = *local_8 + -0x30 + iVar2 * 10;
    in_EDX = local_8;
    if (iVar1 <= iVar3) break;
LAB_004ad8b2:
    local_8 = in_EDX + 1;
    if (9 < (int)*local_8 - 0x30U) goto LAB_004ad8d7;
  }
LAB_004ad8da:
  *param_1 = iVar2;
  *param_2 = (param_3 - (int)pcVar4) + -1;
  return 1;
}

